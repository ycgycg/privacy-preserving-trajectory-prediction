import os
from matplotlib.image import imread
import matplotlib.pyplot as plt
import numpy as np
import requests
import cv2
from timeit import default_timer as timer
from send_shares_mpcservers import send_shares_mpc

#MPC parties
hosts = ['LAP-BE-NIKOVIO1', 'LAP-BE-NIKOVIO1', 'LAP-BE-NIKOVIO1']
ports = [5000, 5001, 5002]

#clear data
for j in np.arange(len(hosts)):
    print(f'clearing datapart test on server {hosts[j]}:{ports[j]}')
    r = requests.get(f'http://{hosts[j]}:{ports[j]}/clear_all?datapart=test')

#send image as flattened ndarray
image = imread(os.path.join('data_faces', '1.pgm'))
image = cv2.resize(image, dsize=(100, 100))

flattened_image = image.flatten()

print(f'sending shares of input {flattened_image} to servers')
send_shares_mpc(flattened_image, ['Face'], 'test', hosts, ports, combined=True)

#compute
url = f'http://{hosts[0]}:{ports[0]}/mpyc_launch?api=image_sharpening_server'
print(f'Sending request: {url}')
response = requests.get(url)
print(f'Response status code: {response.status_code}')
output = response.text
print(type(output))
print(output)
output = output.replace("[", "")
output = output.replace("]", "")
#ERROR i cant cast floats to uint before clipping because numbers will wrap
#output = np.fromstring(output, dtype=float, sep=',').astype(np.uint8)
output = np.fromstring(output, dtype=float, sep=',')
output = np.clip(output, 0, 255)
print(output)
output = np.reshape(output, (-1, 98)).astype(np.uint8)
cv2.imshow("original", image)
cv2.imshow("sharpened", output)
cv2.waitKey(0)
cv2.imwrite('secure_out.png', output)

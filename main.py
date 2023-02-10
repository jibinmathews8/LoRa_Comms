from matplotlib import image
from matplotlib import pyplot as plt

# to read the image stored in the working directory
data = image.imread('Map/Lab3Mapinv.png')
val_x = input("Enter X Coordinate (Meters):")
val_y = input("Enter Y Coordinate (Meters):")
val_x = int(val_x)
val_y = int(val_y)
x=(val_x/1.33) + 1010
y=(val_y/1.33) + 307
plt.ylim([0, 850])
plt.xlim([200, 1200])
plt.plot(x, y, marker='X', color="red", markersize=8)
plt.imshow(data)
plt.show()
import cv2
import numpy as np

image = cv2.imread('test.jpg')

# Print error message if image is null
if image is None:
    print('Could not read image')

# Apply identity kernel
kernel1 = np.array([[0, 0, 0],
                   [0, 1, 0],
                   [0, 0, 0]])

identity = cv2.filter2D(src=image, ddepth=-1, kernel=kernel1)

cv2.imshow('Original', image)
cv2.imshow('Identity', identity)
    
cv2.waitKey()
cv2.imwrite('identity.jpg', identity)
cv2.destroyAllWindows()

# Apply blurring kernel
kernel2 = np.ones((5, 5), np.float32) / 25
img = cv2.filter2D(src=image, ddepth=-1, kernel=kernel2)

cv2.imshow('Original', image)
cv2.imshow('Kernel Blur', img)
    
cv2.waitKey()
cv2.imwrite('blur_kernel.jpg', img)
cv2.destroyAllWindows()

# Apply blur using `blur()` function
img_blur = cv2.blur(src=image, ksize=(5,5)) 
cv2.imshow('Original', image)
cv2.imshow('Blurred', img_blur)
    
cv2.waitKey()
cv2.imwrite('blur.jpg', img_blur)
cv2.destroyAllWindows()

# Apply Gaussian blur
gaussian_blur = cv2.GaussianBlur(src=image, ksize=(5,5), sigmaX=0)

cv2.imshow('Original', image)
cv2.imshow('Gaussian Blurred', gaussian_blur)
    
cv2.waitKey()
cv2.imwrite('gaussian_blur.jpg', gaussian_blur)
cv2.destroyAllWindows()

# Apply Median blur
median_blurred = cv2.medianBlur(src=image, ksize=5)

cv2.imshow('Original', image)
cv2.imshow('Median Blurred', median_blurred)
cv2.imwrite('median_blur.jpg', median_blurred)
cv2.waitKey()
cv2.destroyAllWindows()

# Apply sharpening using kernel
kernel3 = np.array([[0, -1, 0],
                   [-1, 5, -1],
                   [0, -1, 0]])
sharp_img = cv2.filter2D(src=image, ddepth=-1, kernel=kernel3)

cv2.imshow('Original', image)
cv2.imshow('Sharpened', sharp_img)
    
cv2.waitKey()
cv2.imwrite('sharp_image.jpg', sharp_img)
cv2.destroyAllWindows()

# Apply Bilateral Filtering
bilateral_filter = cv2.bilateralFilter(src=image, d=9, sigmaColor=75, sigmaSpace=75)

cv2.imshow('Original', image)
cv2.imshow('Bilateral Filtering', bilateral_filter)
cv2.imwrite('bilateral_filtering.jpg', bilateral_filter)
cv2.waitKey(0)

cv2.destroyAllWindows()
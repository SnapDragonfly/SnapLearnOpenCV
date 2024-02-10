# let's import the necessary libraries
import cv2

# let's read the image using imread() function from OpenCV
img = cv2.imread('sample.jpg')
#let's see the sample image
cv2.imshow('Original Image',img)
cv2.waitKey(0)

# Print error message if image is null
if img is None:
	print('Could not read image')

# Draw line on image
imageLine = img.copy()
# Draw the image from point  A to B
pointA = (200,80)
pointB = (450,80)
cv2.line(imageLine, pointA, pointB, (255, 255, 0), thickness=3, lineType=cv2.LINE_AA)
cv2.imshow('Image Line', imageLine)
cv2.waitKey(0)

# Draw Circle on image
imageCircle = img.copy()
circle_center = (415,190)
radius =100
cv2.circle(imageCircle, circle_center, radius, (0, 0, 255), thickness=3, lineType=cv2.LINE_AA)
cv2.imshow("Image Circle",imageCircle)
cv2.waitKey(0)

# Draw Filled Circle
Filled_circle_image = img.copy()
cv2.circle(Filled_circle_image, circle_center, radius, (255, 0, 0), thickness=-1, lineType=cv2.LINE_AA)
cv2.imshow('Image with Filled Circle',Filled_circle_image)
cv2.waitKey(0)

# Draw Rectangle
imageRectangle = img.copy()
start_point = (300,115)
end_point = (475,225)
cv2.rectangle(imageRectangle, start_point, end_point, (0, 0, 255), thickness= 3, lineType=cv2.LINE_8)   
cv2.imshow('imageRectangle', imageRectangle)
cv2.waitKey(0)

# Draw Ellipse
imageEllipse = img.copy()
ellipse_center = (415,190)
axis1 = (100,50)
axis2 = (125,50)
cv2.ellipse(imageEllipse, ellipse_center, axis1, 0, 0, 360, (255, 0, 0), thickness=3, lineType=cv2.LINE_AA)
cv2.ellipse(imageEllipse, ellipse_center, axis2, 90, 0, 360, (0, 0, 255), thickness=3, lineType=cv2.LINE_AA)
cv2.imshow('ellipse Image',imageEllipse)
cv2.waitKey(0)


halfEllipse = img.copy()
# Half Ellipse
cv2.ellipse(halfEllipse, ellipse_center, axis1, 0, 180, 360, (255, 0, 0), thickness=3, lineType=cv2.LINE_AA)
# Filled ellipse
cv2.ellipse(halfEllipse, ellipse_center, axis1, 0, 0, 180, (0, 0, 255), thickness=-2, lineType=cv2.LINE_AA)
cv2.imshow('HalfEllipse',halfEllipse)
cv2.waitKey(0)

# Put Text on Image
imageText = img.copy()
text = 'I am a Happy dog!'
# org: Where you want to put the text
org = (50,350)
cv2.putText(imageText, text, org, fontFace = cv2.FONT_HERSHEY_COMPLEX, fontScale = 1.5,
            color = (250,225,100),thickness =  3, lineType=cv2.LINE_AA)
cv2.imshow("Image Text",imageText)
cv2.waitKey(0)

cv2.destroyAllWindows()

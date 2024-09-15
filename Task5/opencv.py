import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

video_path = 'Task5/vid (4).mp4'
cap = cv.VideoCapture(video_path)

output_path = 'Task5/output.avi'
out = cv.VideoWriter(output_path, cv.VideoWriter_fourcc(*'XVID'), 25.0, (640, 480))

lower_color = np.array([7, 180, 180])
upper_color = np.array([11, 255, 255])

path_points = []

def rescaleFrame(frame, scale = 0.75):
    
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimensions = (width, height)
    
    return cv.resize(frame, dimensions, interpolation = cv.INTER_CUBIC)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    hsv_frame = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
    mask = cv.inRange(hsv_frame, lower_color, upper_color)

    contours, _ = cv.findContours(mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

    if contours:
        largest_contour = max(contours, key=cv.contourArea)
        x, y, w, h = cv.boundingRect(largest_contour)

        cv.rectangle(frame, (x, y), (x + 50, y + 50), (0, 255, 0), 2)
        out.write(frame)

        center = (int(x + w / 2), int(y + h / 2))
        path_points.append(center)
    
    frame = rescaleFrame(frame)

    cv.imshow('Basketball Tracking', frame)

    if cv.waitKey(50) & 0xFF == ord('q'):
        break

cap.release()
out.release()
cv.destroyAllWindows()

# Plot the path only if there are detected points
if len(path_points) > 0:
    path_points = np.array(path_points)
    plt.plot(path_points[:, 0], path_points[:, 1], marker='o', linestyle='-', color='b')
    plt.title('Basketball Path Tracking')
    plt.xlabel('X-coordinate')
    plt.ylabel('Y-coordinate')
    plt.show(block=True)
else:
    print("No object detected for path plotting.")

main: main.cpp
	g++ main.cpp -o main -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs


clean:
	rm -rf main
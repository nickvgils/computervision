#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{

	// Controle of er een argument aan het programma is meegegeven.
	if (argc != 2)
	{
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}

		// Lees de afbeelding in en sla deze op in image. 
		// De filenaam is het eerste argument dat meegegeven is bij aanroep van het programma.
		Mat image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

		// Controleer of alles goed is gegaan
		if (!image.data)
		{
			cout << "Could not open or find the image" << std::endl;
			return -1;
		}

		cvtColor(image, image, CV_BGR2GRAY);
		threshold(image, image, 50, 1, CV_THRESH_BINARY);

		imwrite("newchangedImage.jpg", image);

		namedWindow("window", CV_WINDOW_AUTOSIZE);
		imshow("window", image);
		waitKey(0);

		// Gebruikersinformatie
		cout << "Imagefile: " << argv[1] << " met succes getoond op het scherm." << endl;
		cout << "Druk op ENTER voor vervolg ==> " << endl;
		string dummy;
		getline(cin, dummy);

		
	return 0;
}

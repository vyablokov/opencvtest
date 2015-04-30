#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if( argc < 2 )
    { 
        std::cout << " Usage: ./contours <img1>" << std::endl;
        return -1; 
    }

    IplImage *img = cvLoadImage(argv[1]);
    IplImage *bin_img = cvCreateImage(cvGetSize(img), 8, 1);
    cvCvtColor(img, bin_img, CV_RGB2GRAY);
    cvSmooth(bin_img, bin_img, CV_GAUSSIAN);
    cvCanny(bin_img, bin_img, 50, 150, 3);

    CvMemStorage *storage = cvCreateMemStorage(0);
    CvContourScanner traverse = cvStartFindContours(bin_img, storage, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    
    CvSeq *mContour = 0;
    for (CvSeq *contour = cvFindNextContour(traverse); contour; contour = cvFindNextContour(traverse))
    {
        CvRect rect = cvContourBoundingRect(contour);
        if ((rect.width < 20) && (rect.height < 20))
            cvRectangle(img, cvPoint(rect.x, rect.y), cvPoint(rect.x + rect.width, rect.y + rect.height), CV_RGB(255, 0, 0));
    }

    cvEndFindContours(&traverse);
    cvReleaseMemStorage(&storage);

    cvSaveImage("res.jpg", img);
    cvSaveImage("contours.png", bin_img);

    cvReleaseImage(&bin_img);
    cvReleaseImage(&img);

    return 0;
}
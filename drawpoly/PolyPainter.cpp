#include "PolyPainter.h"
#include <opencv2/highgui.hpp>

PolyPainter::PolyPainter()
{
	m_image = cv::Mat::zeros(400, 400, CV_8UC3);
}

PolyPainter::PolyPainter(cv::Mat image, std::vector<std::pair<cv::Point, cv::Point>> lines)
{
	m_image = image;
	m_lines = lines;
}

void PolyPainter::setBackground(cv::Mat image)
{
	m_image = image;
}

void PolyPainter::setLines(std::vector<std::pair<cv::Point, cv::Point>> lines)
{
	m_lines = lines;
}

void PolyPainter::show()
{
	int thickness = 2;
	int lineType =cv::LINE_8;

	for (std::pair<cv::Point, cv::Point> pnt : m_lines)
	{

		cv::line(m_image,
			pnt.first,
			pnt.second,
			cv::Scalar(255, 255, 255),
			thickness,
			lineType);

	}
	cv::imshow("Art", m_image);
	cv::waitKey(0);
}

PolyPainter::~PolyPainter()
{

}
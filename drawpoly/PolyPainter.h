#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
class PolyPainter
{
public:
	PolyPainter();
	PolyPainter(cv::Mat image, std::vector<std::pair<cv::Point, cv::Point>> lines);

	void show();
	void setBackground(cv::Mat image);
	void setLines(std::vector<std::pair<cv::Point, cv::Point>> lines);

	~PolyPainter();

protected:
	
	cv::Mat m_image;
	std::vector<std::pair<cv::Point, cv::Point>> m_lines;

};


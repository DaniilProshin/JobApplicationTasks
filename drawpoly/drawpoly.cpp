#include <iostream>
#include "PolyPainter.h"
#include <opencv2/highgui.hpp>
#define PI 3.14159265358979323846

using namespace std;

class RegPolyPainter : public PolyPainter
{
public:
	
	RegPolyPainter( unsigned int n, unsigned int len) : m_n(n), m_len(len)
	{
		
		std::vector<std::pair<cv::Point, cv::Point>> lines;
		float step = (2*PI)/ n;

		
		int x = 0;
		int y = 0;
		int x1 = 0;
		int y1 = 0;
		for (int i = 0; i < n; ++i) 
		{
			cv::Point prev(0, 0);
			cv::Point next(0, 0);

			if (i == 0)
			{
				x = 200;
				y = 200 - (int)(((float)m_len) / (2 * sin(PI / (2 * n)))); // radius of outerbound circle = len/(2*sin(360/2n));
				prev = cv::Point(x,y);

				x1 = x + len * cos((i+1)*step);
				y1 = y + len * sin((i + 1) * step);
				next = cv::Point(x1, y1);

				lines.push_back(std::pair<cv::Point, cv::Point>(prev,next));
			}
			else
			{
				prev = cv::Point(x1, y1);

				x1 = x1 + len * cos((i + 1) * step);
				y1 = y1 + len * sin((i + 1) * step);
				next = cv::Point(x1, y1);

				lines.push_back(std::pair<cv::Point, cv::Point>(prev, next));
			}

		}
		m_lines = lines;

	}
private:
							//center is at (200,200)
	unsigned int m_n = 0;	// number of verticies
	unsigned int m_len = 0;	// length of edge	
};


class EllipsePainter : public PolyPainter
{
public:
	EllipsePainter(int xsize, int ysize): m_xsize(xsize), m_ysize(ysize)
	{
	
	
	}
	void show() const
	{
		int thickness = 2;
		int lineType = 8;
		cv::ellipse(m_image,
			cv::Point(200, 200),
			cv::Size(m_xsize, m_ysize),
			0,
			0,
			360,
			cv::Scalar(255, 0, 0),
			thickness,
			lineType);
		cv::imshow("Art", m_image);
		cv::waitKey(0);
	
	}
protected:
	int m_xsize, m_ysize;
};

int main()
{
	PolyPainter randomfigure;
	randomfigure.setLines({ { {200,200},{300,300} } });
	randomfigure.show();
	RegPolyPainter regularpoly(5, 70);
	regularpoly.show();
	EllipsePainter ellipse(50,100);
	ellipse.show();
	return 0;
}
#include "TorrentProgressWidget.h"
#include <QPainter>
#include <QtDebug>

TorrentProgressWidget::TorrentProgressWidget(QWidget* parent) : QWidget(parent)
{
	m_data = new quint32[1000];
}

TorrentProgressWidget::~TorrentProgressWidget()
{
	delete [] m_data;
}

void TorrentProgressWidget::generate(const std::vector<bool>& data)
{
	m_image = generate(data, 1000, m_data);
	update();
}

void TorrentProgressWidget::generate(const std::vector<int>& data)
{
	m_image = generate(data, 1000, m_data);
	update();
}

QImage TorrentProgressWidget::generate(const std::vector<bool>& data, int width, quint32* buf, float sstart, float send)
{
	double fact = (data.size()-send-sstart)/float(width);
	double step = qMin<double>(255.0, 255.0/fact);
	
	for(int i=0;i<width;i++)
	{
		int from = i*fact+sstart;
		int to = (i+1)*fact+sstart;
		
		if(to >= (int) data.size())
			to = data.size()-1;
		
		double color = 0;
		do
		{
			color += data[from] ? step : 0;
			from++;
		}
		while(from <= to);
		
		quint32 rcolor = 255 - qMin(quint32(color), 255U);
		buf[i] = 0xff0000ff | (rcolor << 8) | (rcolor << 16);
	}
	
	return QImage((uchar*) buf, width, 1, QImage::Format_RGB32);
}

QImage TorrentProgressWidget::generate(const std::vector<int>& data, int width, quint32* buf, float sstart, float send)
{
	if(send < 0)
		send = data.size();
	
	const int maximum = (data.empty()) ? 0 : *std::max_element(data.begin(), data.end());
	const float step = (send-sstart)/width;
	
	if(maximum > 0)
	{
		for(int i=0;i<width;i++)
		{
			int from = i*step+sstart;
			int to = (i+1)*step+sstart;
			int total = 0;
			
			if(to >= (int) data.size())
				to = data.size()-1;
			
			for(int j=from;j<=to;j++)
				total += data[j];
			
			int rcolor = 255 - qMin(255.0 * total / ((to-from+1)*maximum), 255.0);
			buf[i] = 0xff000000 | (rcolor) | (rcolor << 8) | (rcolor << 16);
		}
	}
	else
		memset(buf, 0xff, 4*width);
	
	return QImage((uchar*) buf, width, 1, QImage::Format_RGB32);
}

void TorrentProgressWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setClipRegion(event->region());
	
	QImage bdraw = m_image.scaled(size());
	painter.drawImage(0, 0, bdraw);
	
	painter.end();
}

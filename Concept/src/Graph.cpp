#include "Graph.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent) {}

void GraphWidget::setData(const QVector<double> &data) {
    dataPoints = data;
    update(); // Request a repaint after updating the data
}

void GraphWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Define pens for drawing
    QPen linePen(Qt::black, 2);
    QPen dataPen(Qt::blue, 3);

    // Draw axes
    painter.setPen(linePen);
    painter.drawLine(40, height() - 40, width() - 10, height() - 40); // X-axis
    painter.drawLine(40, height() - 40, 40, 10); // Y-axis

    // Check if there is data to draw
    if (dataPoints.isEmpty()) return;

    // Calculate scaling factors
    double maxDataValue = *std::max_element(dataPoints.begin(), dataPoints.end());
    double xScale = double(width() - 50) / dataPoints.size();
    double yScale = (height() - 50) / maxDataValue;

    // Draw data points
    painter.setPen(dataPen);
    for (int i = 0; i < dataPoints.size(); ++i) {
        if (i > 0) {
            // Draw line between points
            painter.drawLine(QPointF(40 + (i - 1) * xScale, height() - 40 - dataPoints[i - 1] * yScale),
                             QPointF(40 + i * xScale, height() - 40 - dataPoints[i] * yScale));
        }
        // Draw the point
        painter.drawEllipse(QPointF(40 + i * xScale, height() - 40 - dataPoints[i] * yScale), 4, 4);
    }
}

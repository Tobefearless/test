#include "qwchartview.h"
//QT_CHARTS_USE_NAMESPACE     //必须这么设置

#include    <QChartView>


//bool QWChartView::viewportEvent(QEvent *event)
//{
////    if (event->type() == QEvent::TouchBegin) {
////        // By default touch events are converted to mouse events. So
////        // after this event we will get a mouse event also but we want
////        // to handle touch events as gestures only. So we need this safeguard
////        // to block mouse events that are actually generated from touch.
////        m_isTouching = true;

////        // Turn off animations when handling gestures they
////        // will only slow us down.
////        chart()->setAnimationOptions(QChart::NoAnimation);
////    }
//    return QChartView::viewportEvent(event);

//}

//void QWChartView::mousePressEvent(QMouseEvent *event)
//{//鼠标左键按下，记录beginPoint
////    QChartView::mousePressEvent(event);
//    if (event->button()==Qt::LeftButton)
//        beginPoint=event->pos();
//    QChartView::mousePressEvent(event);
//}

//void QWChartView::mouseMoveEvent(QMouseEvent *event)
//{//鼠标移动事件
//    QPoint  point;
//    point=event->pos();

//    emit mouseMovePoint(point);
//    QChartView::mouseMoveEvent(event);
//}

//void QWChartView::mouseReleaseEvent(QMouseEvent *event)
//{
////    QChartView::mouseReleaseEvent(event);
//    if (event->button()==Qt::LeftButton)
//    { //鼠标左键释放，获取矩形框的endPoint,进行缩放
//        endPoint=event->pos();
//        QRectF  rectF;
//        rectF.setTopLeft(this->beginPoint);
//        rectF.setBottomRight(this->endPoint);

////        rectF.setTop(this->chart()->rect().top());
////        rectF.setBottom(this->chart()->rect().bottom());

////        rectF.setLeft(this->beginPoint.rx());
////        rectF.setRight(this->endPoint.rx());

//        this->chart()->zoomIn(rectF);
//    }
//    else if (event->button()==Qt::RightButton)
//        this->chart()->zoomReset(); //鼠标右键释放，resetZoom
//    QChartView::mouseReleaseEvent(event);
//}

void QWChartView::keyPressEvent(QKeyEvent *event)
{//按键控制
    switch (event->key()) {
    case Qt::Key_Plus:  //+
        chart()->zoom(1.2);
        break;
    case Qt::Key_Minus:
        chart()->zoom(0.8);
        break;
    case Qt::Key_Left:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, -10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_PageUp:
        chart()->scroll(0, 50);
        break;
    case Qt::Key_PageDown:
        chart()->scroll(0, -50);
        break;
    case Qt::Key_Home:
        chart()->zoomReset();

//        chart()->resetTransform();//没用
//        chart()->zoomIn(chart()->plotArea()); //没用
        break;
    default:
        QGraphicsView::keyPressEvent(event);
//        break;
    }
//    QGraphicsView::keyPressEvent(event);
}

QWChartView::QWChartView(QWidget *parent):QChartView(parent)
{
    this->setDragMode(QGraphicsView::RubberBandDrag);
//    this->setRubberBand(QChartView::RectangleRubberBand);//设置为矩形选择方式
//    this->setRubberBand(QChartView::VerticalRubberBand);
//    this->setRubberBand(QChartView::HorizontalRubberBand);

    this->setMouseTracking(true);//必须开启此功能
}

QWChartView::~QWChartView()
{

}

//QWChartView::QWChartView(QChart *chart, QWidget *parent)
//    :QChartView(chart, parent)
//{
//    this->setMouseTracking(true);
//}

void QWChartView::wheelEvent(QWheelEvent * event)
{
    const QPoint curpos = event->pos();
    QPointF curChartPos = this->chart()->mapToValue(QPointF(curpos));

    if (!m_alreadySaveRange)
    {
        this->saveAxisRange();
        m_alreadySaveRange = true;
    }

    const double factor = 1.1;//缩放比例

    QValueAxis *axisY = dynamic_cast<QValueAxis*>(this->chart()->axisY());
    const double yMin = axisY->min();
    const double yMax = axisY->max();
    const double yCentral = curChartPos.y();

    QDateTimeAxis *axisX = dynamic_cast<QDateTimeAxis*>(this->chart()->axisX());

    const double xMin = axisX->min().toTime_t();
    const double xMax = axisX->max().toTime_t();
    const double xCentral = curChartPos.x();

    double bottomOffset, topOffset, leftOffset, rightOffset;
    if (event->delta() > 0)//放大
    {
        bottomOffset = 1.0 / factor * (yCentral - yMin);
        topOffset = 1.0 / factor * (yMax - yCentral);

        leftOffset = 1.0 / factor * (xCentral - xMin);
        rightOffset = 1.0 / factor * (xMax - xCentral);
        this->chart()->zoomIn();
    }
    else//缩小
    {
        bottomOffset = 1.0 * factor * (yCentral - yMin);
        topOffset = 1.0 * factor * (yMax - yCentral);

        leftOffset = 1.0 * factor * (xCentral - xMin);
        rightOffset = 1.0 * factor * (xMax - xCentral);

        this->chart()->zoomOut();
    }
    qDebug()<<leftOffset<<rightOffset;
    chart()->axisY()->setRange(yCentral - bottomOffset, yCentral + topOffset);
    //chart()->axisX()->setRange( xCentral - leftOffset, xCentral + rightOffset);

}

void QWChartView::saveAxisRange()
{
    QDateTimeAxis *axisX = dynamic_cast<QDateTimeAxis*>(this->chart()->axisX());
    m_xMin = axisX->min().toTime_t();
    m_xMax = axisX->max().toTime_t();
    QValueAxis *axisY = dynamic_cast<QValueAxis*>(this->chart()->axisY());
    m_yMin = axisY->min();
    m_yMax = axisY->max();
}

void QWChartView::mouseReleaseEvent(QMouseEvent * event)
{
    m_isPress = false;

    //鼠标右键恢复初始化状态
    if (event->button() == Qt::RightButton)
    {
        if (m_alreadySaveRange)
        {
              this->chart()->zoomReset();
//            this->chart()->axisX()->setRange(m_xMin, m_xMax);
//            this->chart()->axisY()->setRange(m_yMin, m_yMax);
        }
    }
}

void QWChartView::mousePressEvent(QMouseEvent * event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_lastPoint = event->pos();
        m_isPress = true;
    }
}

void QWChartView::mouseMoveEvent(QMouseEvent * event)
{
    //显示当前鼠标所在位置的坐标
    //显示当前鼠标所在位置的坐标
        const QPoint curpos = event->pos();
//        QPointF curChartPos = this->chart()->mapToValue(QPointF(curpos));
//        QString coordStr = QString("(X = %1, Y = %2)").arg(curChartPos.x()).arg(curChartPos.y());
//        coordStr += "\n";
//            double x = curChartPos.x();
//            double y =  curChartPos.y();
//            coordStr += QString::number(x);
//            coordStr += " , ";
//            coordStr += QString::number(y);

//       m_coordItem->setText(coordStr);
    //平移
    if (m_isPress)
    {
        QPoint offset = curpos - m_lastPoint;
        m_lastPoint = curpos;
        if (!m_alreadySaveRange)
        {
            this->saveAxisRange();
            m_alreadySaveRange = true;
        }
        this->chart()->scroll(-offset.x(), offset.y());
    }

    //QChartView::mouseMoveEvent(event);
}

#ifndef QWCHARTVIEW_H
#define QWCHARTVIEW_H


#include    <QtCharts>
QT_CHARTS_USE_NAMESPACE

class QWChartView : public QChartView
{
    Q_OBJECT

private:
    QPoint  beginPoint; //选择矩形区的起点
    QPoint  endPoint;  //选择矩形区的终点;
        int channelNum;

        QPoint m_lastPoint;
        bool m_isPress = false;
        bool m_alreadySaveRange = false;
        double m_xMin, m_xMax, m_yMin, m_yMax;
        QGraphicsSimpleTextItem *m_coordItem = nullptr;
protected:
//    bool viewportEvent(QEvent *event);
//    void mousePressEvent(QMouseEvent *event); //鼠标左键按下
    void mouseMoveEvent(QMouseEvent *event); //鼠标移动
//    void mouseReleaseEvent(QMouseEvent *event); //鼠标释放左键
    void keyPressEvent(QKeyEvent *event); //按键事件
    void wheelEvent(QWheelEvent * event);
    void saveAxisRange();
    void mouseReleaseEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
public:
    explicit QWChartView(QWidget *parent = 0);
    ~QWChartView();

signals:
    void mouseMovePoint(QPoint point); //鼠标移动信号，在mouseMoveEvent()事件中触发
};

#endif // QWCHARTVIEW_H

#include "controldelegate.h"
#include "QLineEdit"
#include <QDebug>
#include <QDateTimeEdit>
#include "QTimeEdit"
//spinbox控件部分
SpinboxDelegate::SpinboxDelegate(int column)
{
        mColumn = column;
}

//返回修改数据的组件，为指定的列或者行创建部件
QWidget *SpinboxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const
{
    if(index.column() == 3)
    {
        QSpinBox *editor = new QSpinBox(parent);
        editor->setRange(0 , 1000);
        connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else if( index.column() == 4)
    {
        QSpinBox *editor = new QSpinBox(parent);
        editor->setRange(0,1000);
        connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else
    {
        return QItemDelegate::createEditor(parent,option,index);
    }
}

//根据editor 的数据更新model的数据
void SpinboxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

//显示格式控制
void SpinboxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 3) {
        int warehouseAmount = index.model()->data(index,Qt::DisplayRole).toInt();
        QString text = QString("%1").arg(warehouseAmount, 3, 10, QChar(' '));

        QStyleOptionViewItem myOption = option;
        //设置显示在item的中间
        myOption.displayAlignment = Qt::AlignHCenter | Qt::AlignVCenter;

        drawDisplay(painter, myOption, myOption.rect, text);
        drawFocus(painter, myOption, myOption.rect);
    }
    else if(index.column() == 4) {
        int amount = index.model()->data(index,Qt::DisplayRole).toInt();
        QString text = QString("%1").arg(amount, 3, 10, QChar(' '));

        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignHCenter | Qt::AlignVCenter;

        drawDisplay(painter, myOption, myOption.rect, text);
        drawFocus(painter, myOption, myOption.rect);
    }
}

void SpinboxDelegate::commitAndCloseEditor()
{
    QSpinBox *editor = qobject_cast<QSpinBox*>(sender());
    emit commitData(editor);                    //当编辑器小部件完成数据编辑并希望将其写入模型时，必须发出此信号
    emit closeEditor(editor);                   //当用户使用指定的编辑器完成对项目的编辑时，将发出此信号
}

//checkbox部分
static QRect CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions)/*const*/
{
    //绘制按钮所需要的参数
    QStyleOptionButton checkBoxStyleOption;
    //按照给定的风格参数 返回元素子区域
    QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
    //返回QCheckBox坐标
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x() + viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                         viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    //返回QCheckBox几何形状
    return QRect(checkBoxPoint, checkBoxRect.size());
}

CheckBoxDelegate::CheckBoxDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

void CheckBoxDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,const QModelIndex& index)const
{
    bool checked = index.model()->data(index, Qt::DisplayRole).toBool();

    if(index.column() == 5) {
        //按钮的风格选项
        QStyleOptionButton checkBoxStyleOption;
        //|=为复合赋值语句，a|=b等价于a=a|b，对a和b进行位或运算
        checkBoxStyleOption.state |= QStyle::State_Enabled;

        //根据值判断是否选中
        checkBoxStyleOption.state |= checked? QStyle::State_On : QStyle::State_Off;

        //返回QCheckBox几何形状
        checkBoxStyleOption.rect = CheckBoxRect(option);
        //绘制QCheckBox
        QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkBoxStyleOption, painter);
    }
    else {
        //否则调用默认委托
        QStyledItemDelegate::paint(painter, option, index);
    }
}

bool CheckBoxDelegate::editorEvent(QEvent *event,
                                QAbstractItemModel *model,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index) {
    if(index.column() == 5){
    if((event->type() == QEvent::MouseButtonRelease) ||
            (event->type() == QEvent::MouseButtonDblClick)){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->button() != Qt::LeftButton ||
                !CheckBoxRect(option).contains(mouseEvent->pos())){
            return true;
        }
        if(event->type() == QEvent::MouseButtonDblClick){
            return true;
        }
    }else if(event->type() == QEvent::KeyPress){
        if(static_cast<QKeyEvent*>(event)->key() != Qt::Key_Space &&
                static_cast<QKeyEvent*>(event)->key() != Qt::Key_Select){
            return false;
        }
    }else{
        return false;
    }

    bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
    return model->setData(index, !checked, Qt::EditRole);
    }else{
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }
}

//combobox控件部分
ComboboxDelegate::ComboboxDelegate(QStringList list)
{
    mList = list;
}

QWidget *ComboboxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    if(index.column()  > 0){
//        editor->addItem(QString::fromLocal8Bit("boy"));
//        editor->addItem(QString::fromLocal8Bit("girl"));
        editor->addItems(mList);
//        editor->setCurrentIndex(0);

        //connect(editor,SIGNAL(editingFinished()),SLOT(commitAndCloseEditor()));
        connect(editor,SIGNAL(editTextChanged(QString)),SLOT(commitAndCloseEditor()));
        return editor;
    }
    else
    {
        QItemDelegate::createEditor(parent,option,index);
    }
    return nullptr;
}

void ComboboxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 2)
    {
        QString text = index.model()->data(index , Qt::DisplayRole).toString();

        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignHCenter | Qt::AlignVCenter;

        drawDisplay(painter,myOption,myOption.rect,text);
        drawFocus(painter,myOption,myOption.rect);
    }
    else
    {
        QItemDelegate::paint(painter,option,index);
    }
}

void ComboboxDelegate::commitAndCloseEditor()
{
    QComboBox *editor = qobject_cast<QComboBox*>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}

//QlineEdit
LindeEditDelegate::LindeEditDelegate(QString  format )
{
    mFormat = format;
    //qDebug()<<"da";
}

QWidget *LindeEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/*option*/,
    const QModelIndex &/*index*/) const
{
    QLineEdit *editor = new QLineEdit(parent);
    QRegExp regExp(mFormat);
    editor->setValidator(new QRegExpValidator(regExp, parent));
    return editor;
}

void LindeEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

    QString text = index.model()->data(index, Qt::EditRole).toString();
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    lineEdit->setText(text);

}

void LindeEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
    const QModelIndex &index) const
{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    QString text = lineEdit->text();
    model->setData(index, text, Qt::EditRole);
}

void LindeEditDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    editor->setGeometry(option.rect);
}


//日期控件
DateDelegate::DateDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *DateDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QDateTimeEdit *editor = new QDateTimeEdit(parent);
    editor->setDisplayFormat("MM/dd");
    editor->setCalendarPopup(true);

    editor->setStyleSheet("QCalendarWidget QTableView {background-color: #ffffff;}\n"
                          "QAbstractItemView {color: black;selection-color: white;selection-background-color: rgb(255, 174, 0);font: 15px;}");

    editor->installEventFilter(const_cast<DateDelegate*>(this));

    return editor;
}

void DateDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    QString year = QDate::currentDate().toString("yyyy/");
    QString dateStr =   year + index.model()->data(index).toString();

    //QDate date = QDate::fromString(dateStr,Qt::ISODate);
    //QDate date = QDate::fromString(dateStr,"MM/dd");
    QDateTime date = QDateTime::fromString(dateStr,"yyyy/MM/dd");
    QDateTimeEdit *edit = static_cast<QDateTimeEdit*>(editor);
    //edit->setDate(date);
    edit->setDateTime(date);
}

void DateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QDateTimeEdit *edit = static_cast<QDateTimeEdit*>(editor);
    QDate date = edit->date();


    //odel->setData(index, QVariant(date.toString(Qt::ISODate)));
    model->setData(index, QVariant(date.toString("MM/dd")));
}

void DateDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

TimeDelegate::TimeDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}


//时间控件
QWidget *TimeDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QTimeEdit *editor = new QTimeEdit(parent);
    editor->setDisplayFormat("hh:mm");
    //editor->setCalendarPopup(true);
    editor->installEventFilter(const_cast<TimeDelegate*>(this));
    editor->setButtonSymbols(QAbstractSpinBox::NoButtons);
    return editor;
}

void TimeDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    QString dateStr = index.model()->data(index).toString();
    //QDate date = QDate::fromString(dateStr,Qt::ISODate);
    QTime time = QTime::fromString(dateStr,"hh:mm");
    QTimeEdit *edit = static_cast<QTimeEdit*>(editor);
    edit->setTime(time);
}

void TimeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QTimeEdit *edit = static_cast<QTimeEdit*>(editor);
    QTime time = edit->time();

    //model->setData(index, QVariant(date.toString(Qt::ISODate)));
    model->setData(index, QVariant(time.toString("hh:mm")));
}

void TimeDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

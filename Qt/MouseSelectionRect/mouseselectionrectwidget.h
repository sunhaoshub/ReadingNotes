#ifndef MOUSESELECTIONRECTWIDGET_H
#define MOUSESELECTIONRECTWIDGET_H

#include <QMouseEvent>
#include <QWidget>

namespace Ui {
class MouseSelectionRectWidget;
}

class MouseSelectionRectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MouseSelectionRectWidget(QWidget *parent = 0);
    ~MouseSelectionRectWidget();

private:
    Ui::MouseSelectionRectWidget *ui;
    bool modifyMode = false;
    QRect rect;
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // MOUSESELECTIONRECTWIDGET_H

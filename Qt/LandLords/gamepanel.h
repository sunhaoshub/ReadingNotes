#ifndef GAMEPANE_H
#define GAMEPANE_H

#include <QMainWindow>

namespace Ui {
class GamePane;
}

class GamePane : public QMainWindow
{
    Q_OBJECT

public:
    explicit GamePane(QWidget *parent = 0);
    ~GamePane();

private:
    Ui::GamePane *ui;
};

#endif // GAMEPANE_H

#ifndef LAUNCHERWINDOW_H
#define LAUNCHERWINDOW_H

#include <QMainWindow>

namespace Ui {
class LauncherWindow;
}

class LauncherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LauncherWindow(QWidget *parent = 0);
    ~LauncherWindow();

private slots:
    void on_buttonLogin_clicked();

private:
    Ui::LauncherWindow *ui;

    void setLoginEnabled(bool enable);
    void wait(long ms);
};

#endif // LAUNCHERWINDOW_H

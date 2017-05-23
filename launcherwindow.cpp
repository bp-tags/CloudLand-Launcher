#include "launcherwindow.h"
#include "ui_launcherwindow.h"

#include <QProcess>

#include <QTime>
#include <QCoreApplication>
#include <QUrl>
#include <QDesktopServices>

#include "clhelper.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <stdio.h>

LauncherWindow::LauncherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LauncherWindow)
{
    ui->setupUi(this);
}

LauncherWindow::~LauncherWindow()
{
    delete ui;
}

void LauncherWindow::on_buttonLogin_clicked()
{
  setLoginEnabled(false);
  ui->labelStatus->setText("Logging in with your info... ");

  wait(2000L);

  if(ui->textEmail->text() == "test" && ui->textPassword->text() == "test") {
    ui->labelStatus->setText("Starting game... ");
    QCoreApplication::processEvents();

    QStringList args;
    args.append("1");
    args.append("test_token");
    QProcess p;
    p.startDetached("client.exe", args);

    QCoreApplication::processEvents();
    wait(1000L);
    QCoreApplication::exit();
  } else {
    ui->labelStatus->setText("Wrong username or password! ");
    setLoginEnabled(true);
  }
}

void LauncherWindow::setLoginEnabled(bool enable) {
  ui->frameLogin->setEnabled(enable);
}

void LauncherWindow::wait(long ms) {
    QTime t;
    t.start();
    while(t.elapsed() < ms) QCoreApplication::processEvents();
}

void LauncherWindow::on_buttonRegister_clicked()
{
    QJsonDocument* doc = parse(&QString("{\"test\": \"value\"}"));
    printf("NULL? %s\n", (doc == NULL ? "YES" : "NO"));
    ui->labelStatus->setText(doc->object().isEmpty() ? "YES" : "NO");
    // QDesktopServices::openUrl(QUrl("http://dragonet.org/register"));
}

// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "complex.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_subtract_clicked();
    void on_pushButton_multiply_clicked();
    void on_pushButton_divide_clicked();

private:
    Ui::MainWindow *ui;
    Complex parseComplex(const QString& realStr, const QString& imagStr);
};

#endif // MAINWINDOW_H

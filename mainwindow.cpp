#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_add_clicked()
{
    Complex c1 = parseComplex(ui->lineEdit_real1->text(), ui->lineEdit_imag1->text());
    Complex c2 = parseComplex(ui->lineEdit_real2->text(), ui->lineEdit_imag2->text());
    Complex result = c1 + c2;
    ui->label_result->setText(QString::fromStdString(result.toString()));
}

void MainWindow::on_pushButton_subtract_clicked()
{
    Complex c1 = parseComplex(ui->lineEdit_real1->text(), ui->lineEdit_imag1->text());
    Complex c2 = parseComplex(ui->lineEdit_real2->text(), ui->lineEdit_imag2->text());
    Complex result = c1 - c2;
    ui->label_result->setText(QString::fromStdString(result.toString()));
}

void MainWindow::on_pushButton_multiply_clicked()
{
    Complex c1 = parseComplex(ui->lineEdit_real1->text(), ui->lineEdit_imag1->text());
    Complex c2 = parseComplex(ui->lineEdit_real2->text(), ui->lineEdit_imag2->text());
    Complex result = c1 * c2;
    ui->label_result->setText(QString::fromStdString(result.toString()));
}

void MainWindow::on_pushButton_divide_clicked()
{
    Complex c1 = parseComplex(ui->lineEdit_real1->text(), ui->lineEdit_imag1->text());
    Complex c2 = parseComplex(ui->lineEdit_real2->text(), ui->lineEdit_imag2->text());
    if (c2.real() == 0 && c2.imag() == 0) {
        QMessageBox::warning(this, "Error", "Division by zero is not allowed.");
        return;
    }
    Complex result = c1 / c2;
    ui->label_result->setText(QString::fromStdString(result.toString()));
}

Complex MainWindow::parseComplex(const QString& realStr, const QString& imagStr)
{
    double real = realStr.toDouble();
    double imag = imagStr.toDouble();
    return Complex(real, imag);
}

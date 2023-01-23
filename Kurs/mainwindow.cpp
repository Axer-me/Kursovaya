#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Способ применения", "Для применения калькулятора сожжёных при беге калорий вам необходимо:"
                                                        " Заполнить графы Вес, Рост, Дистанция, то есть расстояние, что вы пробежали, а также то время, "
                                                        "за которое вы её пробежали, после чего достаточно лишь нажать кнопку Результат. Внимение, если в поле подсчитаных калорий пишется <nan>,"
                                                        "значит вы ввели недопустимые символы, то есть цифры, знаки препинания и так далее. В полях для ввода должны быть только цифры.");
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setValidator( new QIntValidator);
    ui->lineEdit_2->setValidator( new QIntValidator);
    ui->lineEdit_3->setValidator( new QIntValidator);
    ui->lineEdit_4->setValidator( new QIntValidator);
    QString a = ("Всего сожжено(кал): ");
    ui -> label_5 -> setText(a);
    int height = ui ->lineEdit -> text().toInt(0,10);
    int weight = ui ->lineEdit_2 -> text().toInt(0,10) ;
    int time = ui -> lineEdit_3 -> text().toInt(0,10);
    int distance = ui ->lineEdit_4 -> text().toInt(0,10);
    double speed = (distance)/(time * 60);
    double calories = ((0.035 * weight) + (((speed*speed)/(height/100)) * (0.029 * weight))) * time;

            QString C = QString::number(calories);
        ui -> label_5 -> setText(ui-> label_5 ->text() + C);
}


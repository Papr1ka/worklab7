#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorts.h"
#include "tools.h"


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

void MainWindow::clear_counters()
{
    ui->label_avg->clear();
    ui->label_max->clear();
    ui->label_min->clear();
}

void MainWindow::setTable(int size)
{
    if ((size > 0) && (size <= 200))
    {
        int last_size = this->size;
        this->size = size;

        ui->tableWidget->setRowCount(1);
        ui->tableWidget->setColumnCount(size);

        QTableWidgetItem *table_item;

        if (size > last_size)
        {
            for (int i = last_size; i < size; i++)
            {

                table_item = new QTableWidgetItem();
                table_item->setBackground(Qt::red);
                ui->tableWidget->setItem(0, i, table_item);

            }
        }

    }
    else
    {
        QMessageBox::information(this, "Ошибка", "Извините, но мы размер должен быть в промежутке [1, 200]");
        ui->tableWidget->clear();
        ui->tableWidget->setColumnCount(0);
        ui->tableWidget->setRowCount(0);
        this->size = 0;
    }
    ui->label_iterations->clear();
    ui->label_swipes->clear();
    this->clear_counters();
}

void MainWindow::on_lineEdit_size_editingFinished()
{
    bool is_int;
    int number;
    if (ui->lineEdit_size->text() != "")
    {
        number = ui->lineEdit_size->text().toInt(&is_int);
        this->setTable(number);
    }
}

void MainWindow::on_pushButton_set_size_10_clicked()
{
    this->setTable(10);
    ui->lineEdit_size->setText("10");
}

void MainWindow::on_pushButton_set_size_200_clicked()
{
    this->setTable(200);
    ui->lineEdit_size->setText("200");
}

bool MainWindow::check()
{
    if (this->size <= 0)
    {
        QMessageBox::information(this, "Ошибка", "Программе не с чем работать");
        return false;
    }
    return true;
}

void MainWindow::on_pushButton_set_size_random_clicked()
{
    if (this->check())
    {
        int value;
        QTableWidgetItem *table_item;
        srand(clock());


        for (int i = 0; i < this->size; i++)
        {
            value = rand() % 201 - 100;
            this->array[i] = value;
            table_item = ui->tableWidget->item(0, i);
            if (table_item != nullptr)
            {
                ui->tableWidget->item(0, i)->setText(QString::number(value));
                ui->tableWidget->item(0, i)->setBackground(Qt::white);
                ui->tableWidget->repaint();
                ui->tableWidget->scrollToItem(table_item);
            }
        }

        ui->tableWidget->scrollToItem(ui->tableWidget->item(0, 0));
    }
    ui->label_iterations->clear();
    ui->label_swipes->clear();
    this->clear_counters();
}

bool MainWindow::check_numbers()
{
    bool flag = true;
    for (int i = 0; i < this->size; i++)
    {
        ui->tableWidget->item(0, i)->text().toInt(&flag);
        if (flag == false)
        {
            ui->tableWidget->item(0, i)->setBackground(Qt::red);
            ui->tableWidget->scrollToItem(ui->tableWidget->item(0, i));
            QMessageBox::information(this, "Ошибка", "Ячейка содержит невалидные данные");
            return flag;
        }
    }
    return true;
}

void quick_sort_container(int size, int *array_ptr, int *iterations, int *swipes)
{
    quick_sort(array_ptr, 0, size - 1, iterations, swipes);
}

void MainWindow::table_function( void (*func)(int size, int *array_ptr, int *iterations, int *swipes) )
{
    if (this->check() && this->check_numbers())
    {
        this->swipes = 0;
        this->iterations = 0;
        func(this->size, this->array, &this->iterations, &this->swipes);
        for (int i = 0; i < this->size; i++)
        {
            ui->tableWidget->item(0, i)->setText(QString::number(this->array[i]));
        }
        ui->label_swipes->setText(QString::number(this->iterations));
        ui->label_iterations->setText(QString::number(this->swipes));
        if (func == &makaka_sort)
        {
            if (this->swipes >= 1000)
            {
                QMessageBox::information(this, "Ошибка", "Обезьянки не справились за 1000 попыток");
            }
        }
    }
}

QString MainWindow::table_function(int (*func)(int, int *))
{
    if (this->check() && this->check_numbers())
    {
        int value = func(this->size, this->array);
        return QString::number(value);
    }
    return "";
}

void MainWindow::on_pushButton_bubble_clicked()
{
    this->table_function(bubble_sort);
}

void MainWindow::on_pushButton_gnome_clicked()
{
    this->table_function(gnome_sort);
}

void MainWindow::on_pushButton_quick_clicked()
{
    this->table_function(quick_sort_container);
}

void MainWindow::on_pushButton_hair_clicked()
{
    this->table_function(hair_sort);
}

void MainWindow::on_pushButton_makaka_clicked()
{
    if (this->size > 5)
    {
        QMessageBox::information(this, "Ошибка", "Обезьянки не сортируют массив с размерностью более 5");
    }
    else
    {
        this->table_function(makaka_sort);
    }
}


void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    bool is_int;
    int number;
    number = item->text().toInt(&is_int);
    if (not is_int)
    {
        item->setBackground(Qt::red);
    }
    else
    {
        item->setBackground(Qt::white);
        this->array[item->column()] = number;
    }
    ui->label_iterations->clear();
    ui->label_swipes->clear();
    this->clear_counters();
}


void MainWindow::on_pushButton_min_clicked()
{
    ui->label_min->setText(this->table_function(min));
}


void MainWindow::on_pushButton_max_clicked()
{
    ui->label_max->setText(this->table_function(max));
}


void MainWindow::on_pushButton_avg_clicked()
{
    ui->label_avg->setText(this->table_function(avg));
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    setWindowTitle("Jumppad");

}

MainWindow::~MainWindow()
{
    delete ui;
}
QString filename ;
void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->clear();
}


void MainWindow::on_actionopen_triggered()
{
    QString fileContent;

    filename= QFileDialog::getOpenFileName(this, "Choose File");
    if(filename.isEmpty())
        return;
    QFile file(filename);
    setWindowTitle(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream in(&file);

    fileContent= in.readAll();

    file.close();

    ui->textEdit->clear();
    ui->textEdit->setPlainText(fileContent);

}


void MainWindow::on_actionsave_triggered()
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
}


void MainWindow::on_actionsave_as_triggered()
{
    QString fileContent;
    filename= QFileDialog::getOpenFileName(this, "Choose File");
    if(filename.isEmpty())
        return;
    QFile file(filename);
    setWindowTitle(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QTextStream in(&file);
    fileContent= in.readAll();
    file.close();
    ui->textEdit->clear();
    ui->textEdit->setPlainText(fileContent);
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionUndo_triggered()
{
     ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionTerminal_triggered()
{
#ifdef _WIN32
    system("start cmd");
// program.exe is app you have built to get input.
#endif

#ifdef _WIN64
    system("start cmd");
#endif

#ifdef __APPLE__
    system("open terminal");
#endif

#ifdef __linux__
    system("gnome-terminal &");
#endif
}


void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionDark_triggered()
{
    ui->textEdit->setStyleSheet("background-color: #2f2f2f;color: white");
    ui->toolBar->setStyleSheet("background-color: #2f2f2f;color: white");
    ui->menubar->setStyleSheet("background-color: #2f2f2f;color: white");
}


void MainWindow::on_actionNight_triggered()
{
    ui->textEdit->setStyleSheet("background-color: white;color: black");
    ui->toolBar->setStyleSheet("background-color: white;color: black");
    ui->menubar->setStyleSheet("background-color: white;color: black");
}


void MainWindow::on_actionContents_triggered()
{
    QString link = "http://github.com/nimacpp";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_actionAbout_triggered()
{
    Dialog* dlg = new Dialog(this);
    dlg->show();
}


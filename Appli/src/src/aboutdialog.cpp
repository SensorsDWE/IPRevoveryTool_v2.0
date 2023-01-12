#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QString text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->textBrowser_about->setText(text);
    ui->textBrowser_about->setStyleSheet("QTextBrowser { background-color: white;}");
    setWindowTitle(tr("About", "About window title"));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_pushButton_ok_clicked()
{
    close();
}

#include "imageedit.h"
#include "ui_imageedit.h"

ImageEdit::ImageEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageEdit)
{
    ui->setupUi(this);
}

ImageEdit::~ImageEdit()
{
    delete ui;
}

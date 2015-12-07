#ifndef IMAGEEDIT_H
#define IMAGEEDIT_H

#include <QWidget>

namespace Ui {
class ImageEdit;
}

class ImageEdit : public QWidget
{
    Q_OBJECT

public:
    explicit ImageEdit(QWidget *parent = 0);
    ~ImageEdit();

private:
    Ui::ImageEdit *ui;
};

#endif // IMAGEEDIT_H

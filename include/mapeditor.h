#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include "mapviewmodel.h"
#include "blockviewmodel.h"
#include "blockdelegate.h"

namespace Ui {
class MapEditor;
}

class MapEditor : public QMainWindow
{
    Q_OBJECT
public:
    explicit MapEditor(QWidget *parent = 0);
    ~MapEditor();

public slots:
    void EditMap(QModelIndex index);
    void EditBlock();
    void LoadImages();
    void ImageChanged(QModelIndex index);
    void ChangeBackgroundColor();
private:
    Ui::MapEditor *ui;
    MapViewModel *MapModel;
    BlockViewModel *BlockModel;
    BlockDelegate *BlockDlg;
    int ActiveBlock = 0;
};

#endif // MAPEDITOR_H

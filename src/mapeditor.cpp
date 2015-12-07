#include "mapeditor.h"
#include "ui_mapeditor.h"
#include <QDebug>

MapEditor::MapEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapEditor)
{
    ui->setupUi(this);

    BlockDlg = new BlockDelegate(this);

    MapModel = new MapViewModel();
    ui->Map->setModel(MapModel);
    ui->Map->setMouseTracking(true);
    connect(ui->Map, SIGNAL(clicked(QModelIndex)), this, SLOT(Edit(QModelIndex)));
    ui->Map->setFocusPolicy(Qt::NoFocus);
    ui->Map->setItemDelegate(BlockDlg);

    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,0);
    QList<int> list = ui->splitter->sizes();
    list[1]=194;
    ui->splitter->setSizes(list);
    ui->splitter->handle(1)->setEnabled(false);

    BlockModel = new BlockViewModel();
    ui->BlockList->setModel(BlockModel);
    ui->BlockList->setItemDelegate(BlockDlg);
    connect(ui->BlockList, SIGNAL(clicked(QModelIndex)), this, SLOT(ImageChanged(QModelIndex)));

    ui->CurrentBlock->setIcon(QIcon((QPixmap().fromImage(BlockDlg->GetImage(0)))));

    connect(ui->ButtonAdd, SIGNAL(clicked(bool)), this, SLOT(LoadImages()));

}

MapEditor::~MapEditor()
{
    delete ui;
}

void MapEditor::Edit(QModelIndex index){
    MapModel->ChangeBlock(index, ActiveBlock);
}

void MapEditor::LoadImages(){
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Select texturaz plz"), "", tr("PNG images (*.png)"));
    while(!files.empty()){
        QString file = files.back();
        BlockDlg->AddBlock(QImage(file));
        BlockModel->BlockAdded();
        files.pop_back();
    }
}

void MapEditor::ImageChanged(QModelIndex index){
    int block = index.column() + index.row()*4;
    if(block < BlockDlg->GetBlocksCount()) ActiveBlock = block;
    qDebug()<<index.column()<<":"<<index.row()<<"="<<index.column() + index.row()*4;
    ui->CurrentBlock->setIcon(QIcon(QPixmap().fromImage(BlockDlg->GetImage(index.model()->data(index).toInt()))));
}

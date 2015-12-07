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
    connect(ui->Map, SIGNAL(clicked(QModelIndex)), this, SLOT(EditMap(QModelIndex)));
    ui->Map->setFocusPolicy(Qt::NoFocus);
    ui->Map->setItemDelegate(BlockDlg);
    ui->Map->setStyleSheet("QTableView{ background-color: #ffffff; }");

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
    connect(ui->ButtonEdit, SIGNAL(clicked(bool)), this, SLOT(EditBlock()));

    //BlockModel->BlockNames.push_back(tr("Sky"));
    //BlockTypes.push_back(tr("background"));
}

MapEditor::~MapEditor()
{
    delete ui;
}

void MapEditor::EditMap(QModelIndex index){
    MapModel->ChangeBlock(index, ActiveBlock);
}

void MapEditor::LoadImages(){
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Select texturaz plz"), "", tr("PNG images (*.png)"));
    while(!files.empty()){
        QString file = files.back();
        QString name = QFileInfo(file).fileName();
        name = name.left(name.lastIndexOf("."));
        name.replace('_',' ');
        qDebug()<<name;
        BlockDlg->AddBlock(QImage(file));
        BlockModel->AddBlock(name, tr("Solid"));
        files.pop_back();
    }
}

void MapEditor::ImageChanged(QModelIndex index){
    int block = index.column() + index.row()*4;
    if(block < BlockDlg->GetBlocksCount()) ActiveBlock = block;
    qDebug()<<index.column()<<":"<<index.row()<<"="<<index.column() + index.row()*4;
    ui->CurrentBlock->setIcon(QIcon(QPixmap().fromImage(BlockDlg->GetImage(index.model()->data(index).toInt()))));
    ui->CurrentBlockName->setText(BlockModel->GetNameOf(ActiveBlock));
    ui->CurrentBlockType->setText(BlockModel->GetTypeOf(ActiveBlock));
}

void MapEditor::EditBlock(){
    if(ActiveBlock == 0) ChangeBackgroundColor();
}

void MapEditor::ChangeBackgroundColor(){
    QColor color = QColorDialog::getColor(BlockDlg->GetBackgroundColor(),this,tr("Select new background color"));
    BlockDlg->SetBackgroundColor(color);
    QString R,G,B;
    R = QString::number(color.red());
    G = QString::number(color.green());
    B = QString::number(color.blue());
    ui->Map->setStyleSheet("QTableView{ background-color: rgb("+ R +","+ G +","+ B +"); }");
    BlockModel->dataChanged(BlockModel->index(0,0), BlockModel->index(0,0));
}

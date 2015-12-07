#ifndef BLOCKDELEGATE_H
#define BLOCKDELEGATE_H

#include <QItemDelegate>
#include <QPainter>
#include <QVector>
#include <QImage>

class BlockDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    BlockDelegate(QWidget *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void AddBlock(QImage block);
    QImage GetImage(int block);
    int GetBlocksCount();
    QColor GetBackgroundColor();
    void SetBackgroundColor(QColor color);
private:
    QVector<QImage> Blocks;
    QColor BackgroundColor;
signals:

public slots:

};

#endif // BLOCKDELEGATE_H

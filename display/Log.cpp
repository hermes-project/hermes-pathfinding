//
// Created by rem on 26/04/18.
//

#include "Log.h"

Log::Log(QWidget *parent, int size_Y) : QFrame(parent) {

    this->setFixedSize(300, size_Y);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(40, 50, 60));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    Line* emptyLine = new Line(this, "");
    Line* title = new Line(this, "Hermès Pathfinding - Log");
    emptyLine->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    title->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    title->setFont(QFont("Cursive", 16, QFont::Medium));
    nbLine = size_Y/TEXT_SIZE;

    layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(emptyLine);
    layout->addWidget(title);
    layout->addWidget(emptyLine->clone());
    this->setLayout(layout);
}
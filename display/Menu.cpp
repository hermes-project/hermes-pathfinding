//
// Created by rem on 20/03/18.
//

#include <QtWidgets/QGridLayout>
#include "Menu.h"
Menu::Menu(QWidget *parent): QWidget(parent) {
    buttonGenerate = new QPushButton("Générer", this);
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(buttonGenerate,0,0);
    setLayout(grid);
}

void Menu::paintEvent(QPaintEvent *event) {
}
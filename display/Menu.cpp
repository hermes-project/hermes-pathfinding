//
// Created by rem on 26/04/18.
//

#include "Menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent)
{
    // Les boutons à lier avec les bonnes méthodes
    quit = new QPushButton("Quit");
    regenerate = new QPushButton("Regenerate");
    add = new QPushButton("Add");
    empty = new QPushButton("Nani button (not binded)");

    // On configure le look des boutons
    quit->setFont(QFont("Cursive", 11, QFont::Bold));
    regenerate->setFont(QFont("Cursive", 11, QFont::Bold));;
    add->setFont(QFont("Cursive", 11, QFont::Bold));
    empty->setFont(QFont("Cursive", 11, QFont::Bold));

    // Gestion des layouts
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(regenerate, 0, 0);
    layout->addWidget(quit, 0, 1);
    layout->addWidget(add, 1, 0);
    layout->addWidget(empty, 1, 1);
    this->setLayout(layout);
}

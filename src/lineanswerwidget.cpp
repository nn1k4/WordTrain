/******************************************************************************
** WordTrain 0.9.3 -- Foreign words trainer
** Copyright (C) 2010  Valery Kharitonov <kharvd@gmail.com>
**
** This file is part of WordTrain.
**
** $QT_BEGIN_LICENSE:GPL$
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
** $QT_END_LICENSE$
**
** If you have questions regarding the use of this file, please contact me at
** kharvd@gmail.com.
**
******************************************************************************/

#include "lineanswerwidget.h"

#include <QLayout>
#include <QLineEdit>
#include <QLabel>

LineAnswerWidget::LineAnswerWidget(QWidget *parent) :
    AnswerWidget(parent)
{
    txtAnswer = new QLineEdit();
    imgCorrect = new QLabel();

    QHBoxLayout *lt = new QHBoxLayout();
    lt->addWidget(txtAnswer);
    lt->addWidget(imgCorrect);

    lt->setMargin(0);

    setFocusPolicy(Qt::StrongFocus);
    setLayout(lt);
}

QString LineAnswerWidget::answer()
{
    return txtAnswer->text();
}

void LineAnswerWidget::setFocus()
{
    txtAnswer->setFocus(Qt::MouseFocusReason);
}

void LineAnswerWidget::setFocus(Qt::FocusReason reason)
{
    txtAnswer->setFocus(reason);
}

void LineAnswerWidget::clear()
{
    txtAnswer->clear();
    imgCorrect->clear();
}

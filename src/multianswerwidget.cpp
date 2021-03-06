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

#include "multianswerwidget.h"

#include <QRadioButton>
#include <QLayout>
#include <QButtonGroup>
#include <QLabel>
#include <QDebug>

MultiAnswerWidget::MultiAnswerWidget(QWidget *parent) :
    AnswerWidget(parent)
{
    ltRadios = new QVBoxLayout();
    grpAnswers = new QButtonGroup(this);

    QHBoxLayout *lt = new QHBoxLayout();
    lt->addLayout(ltRadios);
    lt->addWidget(imgCorrect);

    lt->setMargin(0);

    setLayout(lt);
}

void MultiAnswerWidget::setAnswers(const QStringList & answers)
{
    m_Answers = answers;
    createRadios();
}

void MultiAnswerWidget::createRadios()
{
    for (int i = 0; i < m_Answers.size(); i++) {
        QRadioButton *tmp = new QRadioButton(m_Answers[i]);
        connect(tmp, SIGNAL(toggled(bool)), SIGNAL(answered()));
        grpAnswers->addButton(tmp, i);
        ltRadios->addWidget(tmp);
    }
}

QString MultiAnswerWidget::answer()
{
    if (grpAnswers->checkedId() != -1)
        return m_Answers.at(grpAnswers->checkedId());

    return "";
}

void MultiAnswerWidget::clear()
{
    QLayoutItem *child;
    QRadioButton *btn;

    // We take first 'child' and remove it from the layout
    while ((child = ltRadios->takeAt(0))) {
        btn = qobject_cast<QRadioButton *>(child->widget());
        Q_ASSERT(btn);
        grpAnswers->removeButton(btn);

        delete btn;
    }

    m_Answers.clear();
    imgCorrect->clear();
}

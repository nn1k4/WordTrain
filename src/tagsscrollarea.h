/******************************************************************************
** WordTrain 0.9.2 -- Foreign words trainer
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

#ifndef TAGSSCROLLAREA_H
#define TAGSSCROLLAREA_H

#include <QScrollArea>
#include "wordscard.h"

class QVBoxLayout;
class QCheckBox;

// Displays checkboxes in scrollarea for tags. Used in QuizWordChooserDialog
class TagsScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit TagsScrollArea(const Tags &tags, QWidget *parent = 0);

    Tags selectedTags();

signals:
    // Emitted when one of the checkboxes has been clicked
    void stateChanged();

private:
    QString chckBoxTextAt(int index);
    bool chckBoxClickedAt(int index);

    void fillTags();

    Tags m_Tags;

    QScrollArea *scrlArea;
    QVBoxLayout *ltTags;
};

#endif // TAGSSCROLLAREA_H

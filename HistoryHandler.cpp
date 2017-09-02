#include "HistoryHandler.h"
#include "Utility.h"
HistoryHandler::HistoryHandler()
{
doing = false;
};
void HistoryHandler::undo()
{
    if(HistoryHandler::doing)return;
    doing = true;
    QUndoStack::undo();
    doing = false;
}
void HistoryHandler::redo()
{
    if(doing)return;
    doing = true;
    QUndoStack::redo();
    doing = false;
}
void HistoryHandler::push(QUndoCommand *cmd)
{
    qDebug("crownign");
    if(doing)return;
    qDebug("it's a girl");
    doing = true;
    QUndoStack::push(cmd);
    doing = false;
}

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

class ProgramInfo;
class QSqlDatabase;

#include <qmap.h> 
#include <list>
#include <vector>
using namespace std;

class Scheduler
{
  public:
      Scheduler(QSqlDatabase *ldb);
     ~Scheduler();

      bool CheckForChanges(void);
      bool FillRecordLists(bool doautoconflicts = true);

      void RemoveFirstRecording(void ); 
      ProgramInfo *GetNextRecording(void);

      list<ProgramInfo *> *getAllPending(void) { return &recordingList; }

      list<ProgramInfo *> *getConflicting(ProgramInfo *pginfo,
                                          bool removenonplaying = true,
                                          list<ProgramInfo *> *uselist = NULL);

  private:
      void setupCards(void);

      void MarkKnownInputs(void);

      void MarkConflicts(list<ProgramInfo *> *uselist = NULL);
      void PruneList(void);

      void MarkConflictsToRemove(void);
      void MarkSingleConflict(ProgramInfo *info,
                              list<ProgramInfo *> *conflictList);
      void CheckOverride(ProgramInfo *info, list<ProgramInfo *> *conflictList);
      void RemoveConflicts(void);

      void GuessSingle(ProgramInfo *info, list<ProgramInfo *> *conflictList);
      void GuessConflicts(void);

      bool Conflict(ProgramInfo *a, ProgramInfo *b);

      bool FindInOldRecordings(ProgramInfo *pginfo);      

      void PrintList(void);

      ProgramInfo *GetBest(ProgramInfo *info, 
                           list<ProgramInfo *> *conflictList);

      void DoMultiCard();

      list<ProgramInfo *> *CopyList(list<ProgramInfo *> *sourcelist);

      QSqlDatabase *db;

      list<ProgramInfo *> recordingList;

      bool hasconflicts;

      int numcards;
      int numsources;
      int numinputs;

      QMap<int, int> numInputsPerSource;
      QMap<int, vector<int> > sourceToInput;
      QMap<int, int> inputToCard;
};

#endif

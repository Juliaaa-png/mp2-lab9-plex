#include "Plex.h"

void TChart::Show(Graphics^ gr, Pen^ pen)
{
	TLine CurrLine;
	TRoot* pR;
	TPoint* pP;
	CurrLine.pChart = this;
	CurrLine.pFp = NULL;
	CurrLine.pLp = NULL;
	St.Clear();
	St.Push(CurrLine);
	while (!St.Empty())
	{
		CurrLine = St.Pop();
		while (CurrLine.pFp == NULL)
		{
			pR = CurrLine.pChart->GetFirst();
			pP = dynamic_cast<TPoint*>(pR);
			if (pP != NULL)
				CurrLine.pFp = pP;
			else
			{
				St.Push(CurrLine);
				CurrLine.pChart = dynamic_cast<TChart*>(pR);
			}
		}
		if (CurrLine.pLp == NULL)
		{
			pR = CurrLine.pChart->GetLast();
			pP = dynamic_cast<TPoint*>(pR);
			if (pP != NULL)
				CurrLine.pLp = pP;
			else
			{
				St.Push(CurrLine);
				CurrLine.pChart = dynamic_cast<TChart*>(pR);
				CurrLine.pFp = NULL;
				St.Push(CurrLine);
			}
		}
		CurrLine.pChart->SetVisible(true);
		if (CurrLine.pFp != NULL && CurrLine.pLp != NULL)
		{
			if (CurrLine.pChart->GetVisible())
			{
				gr->DrawLine(pen, CurrLine.pFp->GetX(), CurrLine.pFp->GetY(), CurrLine.pLp->GetX(), CurrLine.pLp->GetY());
				CurrLine.pFp->Show(gr, pen);
				CurrLine.pLp->Show(gr, pen);
			}
			pP = CurrLine.pLp;
			if (!St.Empty())
			{
				CurrLine = St.Pop();
				if (CurrLine.pFp == NULL)
					CurrLine.pFp = pP;
				else
					CurrLine.pLp = pP;
				St.Push(CurrLine);
			}
		}
	}
}
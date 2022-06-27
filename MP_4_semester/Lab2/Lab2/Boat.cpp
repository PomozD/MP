#include "pch.h"
#include "Boat.h"
#include "Combi.h"
namespace boatfnc
{
	int calcv(combi::accomodation s, const int v[])		// подсчет веса
	{
		int rc = 0;
		for (int i = 0; i < s.m; i++) rc += v[s.ntx(i)];
		return rc;
	};
	int calcc(combi::accomodation s, const int c[])		// подсчет дохода от перевозки
	{
		int rc = 0;
		for (int i = 0; i < s.m; i++) rc += c[s.ntx(i)];
		return rc;
	};
	void copycomb(short m, short *r1, const short *r2)  //копировать
	{
		for (int i = 0; i < m; i++)  r1[i] = r2[i];
	};
}
int boat_с(      // функция возвращает доход от перевозки контейнеров
	int V,      // [in]  максимальный вес груза
	short m,   // [in]  количество мест для контейнеров
	short n,      // [in]  всего контейнеров  
	const int v[],// [in]  вес каждого контейнера  
	const int c[],// [in]  доход от перевозки каждого контейнера   
	short r[]     // [out] номера  выбранных контейнеров  
)
{
	combi::accomodation xc(n, m);	// размещения
	int rc = 0, i = xc.getfirst(), cc = 0;
	while (i > 0)
	{
		if (boatfnc::calcv(xc, v) <= V)	// если загрузка уд.условию
			if ((cc = boatfnc::calcc(xc, c)) > rc)	// если цена выше предыдущей
			{
				rc = cc; 
				boatfnc::copycomb(m, r, xc.sset);
			}
		i = xc.getnext();
	};
	return rc;
};

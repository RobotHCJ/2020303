#include "stdafx.h"
#include "CBezierCurve.h"
#include <math.h>  
 


CBezierCurve::CBezierCurve()
{
}


CBezierCurve::~CBezierCurve()
{
}

void CBezierCurve::SetCtrlPoint(POINT& stPt)
{
	m_vecCtrlPt.push_back(stPt);
}

void CBezierCurve::CreateCurve()
{
	// ȷ���Ƕ������ߣ�2������һ�����Ƶ�  
	assert(m_vecCtrlPt.size() == 3);

	// t�������� ����ͨ��setp��Сȷ����Ҫ����������ϵ�ĸ���  
	float step = 0.5;
	for (float t = 0.0; t <= 1.0; t += step)
	{
		POINT stPt;
		CalCurvePoint(t, stPt);
		m_vecCurvePt.push_back(stPt);
	}
}

void CBezierCurve::Draw(CDC* pDC)
{
	// ���������ϸ��㣬��������������ֱ�����Ӹ���  
	int nCount = m_vecCurvePt.size();

	//CPoint  pp = pDC->GetCurrentPosition();
	pDC->MoveTo(pDC->GetCurrentPosition());
	
	for (int i = 0; i < nCount; i++)
	{
		pDC->LineTo(m_vecCurvePt[i]);
	}
	pDC->LineTo(m_vecCtrlPt[2]);
}

void CBezierCurve::CalCurvePoint(float t, POINT& stPt)
{
	// ȷ���Ƕ������ߣ�2������һ�����Ƶ�  
	assert(m_vecCtrlPt.size() == 3);

	// �������ߵ����꣬��Ϊ2���㷨���ı�˴�����ʵ�ֶ������  
	float x = (float)m_vecCtrlPt[0].x * pow(1 - t, 2) +
		(float)m_vecCtrlPt[1].x * t * (1 - t) * 2 +
		(float)m_vecCtrlPt[2].x * pow(t, 2);
	float y = (float)m_vecCtrlPt[0].y * pow(1 - t, 2) +
		(float)m_vecCtrlPt[1].y * t * (1 - t) * 2 +
		(float)m_vecCtrlPt[2].y * pow(t, 2);
	stPt.x = x;
	stPt.y = y;
}

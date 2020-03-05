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
	// 确保是二次曲线，2个顶点一个控制点  
	assert(m_vecCtrlPt.size() == 3);

	// t的增量， 可以通过setp大小确定需要保存的曲线上点的个数  
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
	// 画出曲线上个点，若不连续可以用直线连接各点  
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
	// 确保是二次曲线，2个顶点一个控制点  
	assert(m_vecCtrlPt.size() == 3);

	// 计算曲线点坐标，此为2次算法，改变此处可以实现多次曲线  
	float x = (float)m_vecCtrlPt[0].x * pow(1 - t, 2) +
		(float)m_vecCtrlPt[1].x * t * (1 - t) * 2 +
		(float)m_vecCtrlPt[2].x * pow(t, 2);
	float y = (float)m_vecCtrlPt[0].y * pow(1 - t, 2) +
		(float)m_vecCtrlPt[1].y * t * (1 - t) * 2 +
		(float)m_vecCtrlPt[2].y * pow(t, 2);
	stPt.x = x;
	stPt.y = y;
}

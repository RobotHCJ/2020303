#pragma once
#include <vector>
class CBezierCurve
{
public:
	CBezierCurve();
	~CBezierCurve();

	void SetCtrlPoint(POINT& stPt);

	void CreateCurve();

	void Draw(CDC* pDC);

private:
	// 主要算法，计算曲线各个点坐标  
	void CalCurvePoint(float t, POINT& stPt);

private:

public:
	// 曲线上各点坐标数组  
	std::vector<POINT> m_vecCurvePt;
	// 顶点和控制点数组  
	std::vector<POINT> m_vecCtrlPt;
};


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
	// ��Ҫ�㷨���������߸���������  
	void CalCurvePoint(float t, POINT& stPt);

private:

public:
	// �����ϸ�����������  
	std::vector<POINT> m_vecCurvePt;
	// ����Ϳ��Ƶ�����  
	std::vector<POINT> m_vecCtrlPt;
};


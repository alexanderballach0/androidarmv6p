#include "..\eactions.h"


e2d::EActionOpacityTo::EActionOpacityTo(float duration, float opacity) :
	EActionOpacityBy(duration, 0)
{
	m_nEndVal = opacity;
}

e2d::EActionOpacityTo * e2d::EActionOpacityTo::clone() const
{
	return new EActionOpacityTo(m_fDuration, m_nEndVal);
}

void e2d::EActionOpacityTo::_init()
{
	EActionOpacityBy::_init();
	m_nVariation = m_nEndVal - m_nBeginVal;
}

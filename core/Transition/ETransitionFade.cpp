#include "..\etransitions.h"
#include "..\enodes.h"

e2d::ETransitionFade::ETransitionFade(float fadeOutDuration, float fadeInDuration)
	: ETransition(0)
	, m_fFadeOutDuration(fadeOutDuration)
	, m_fFadeInDuration(fadeInDuration)
	, m_bFadeOutTransioning(true)
{
	m_fDuration = max(m_fFadeOutDuration, 0);
}

void e2d::ETransitionFade::_update()
{
	this->_calcRateOfProgress();

	if (m_bFadeOutTransioning)
	{
		m_pPrevScene->getRoot()->setOpacity(1 - m_fRateOfProgress);
		if (m_fRateOfProgress >= 1)
		{
			m_bFadeOutTransioning = false;
			m_fDuration = max(m_fFadeInDuration, 0);
			m_fLast = ETime::getTotalTime();
		}
	}
	else
	{
		m_pNextScene->getRoot()->setOpacity(m_fRateOfProgress);
		if (m_fRateOfProgress >= 1)
		{
			this->_stop();
		}
	}
}

void e2d::ETransitionFade::_init()
{
	if (m_pPrevScene)
	{
		m_bFadeOutTransioning = true;
		m_pPrevScene->getRoot()->setOpacity(1);
	}
	else
	{
		m_bFadeOutTransioning = false;
		m_fDuration = m_fFadeInDuration;
	}
	m_pNextScene->getRoot()->setOpacity(0);
}

void e2d::ETransitionFade::_reset()
{
	if (m_pPrevScene) m_pPrevScene->getRoot()->setOpacity(1);
	m_pNextScene->getRoot()->setOpacity(1);
}

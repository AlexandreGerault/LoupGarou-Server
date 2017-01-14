#include "includes/locator.h"

Logger * Locator::m_service = &Locator::nullService();

Logger & Locator::nullService(){
    static NullLogger instance;
    return instance;
}

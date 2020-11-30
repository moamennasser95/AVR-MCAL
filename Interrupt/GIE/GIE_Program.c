#include "../../../LIBERARY/STD_Types.h"

#include "../../../LIBERARY/AVR32_REG.h"
#include "../../../LIBERARY/BIT_MATH.h"
#include "../../../LIBERARY/ERROR_STATE.h"


void GIE_VidEnable(void)
{
	SET_BIT(SREG,7);
}

void GIE_VidDisable(void)
{
	CLR_BIT(SREG,7);
}

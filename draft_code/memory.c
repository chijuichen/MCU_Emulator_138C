
#include "memory.h"
#include "sfr.h"

void memory_init(memory_t *pMem)
{
	pMem->pRom = calloc(IROM_SIZE, sizeof(IROM));
	pMem->pIbrom = pMem->pRom + IBROM_START_ADDR;
	pMem->pXram = calloc(XRAM_SIZE, sizeof(XRAM));
	pMem->pIram = calloc(IRAM_SIZE, sizeof(IRAM));
	pMem->pSfr  = calloc(SFR_SIZE,  sizeof(SFR));
}

void memory_deinit(memory_t *pMem)
{
	free(pMem->pRom);
	free(pMem->pXram);
	free(pMem->pIram);
	free(pMem);
}







#ifndef MEMORY_H
#define MEMORY_H

#define IROM             unsigned char
#define XRAM             unsigned char
#define IRAM             unsigned char

#define IROM_SIZE        (0x4800)
#define IROM_START_ADDR  (0x0000)
#define IROM_END_ADDR    (0x47FF)

#define IBROM_SIZE       (0x0080)
#define IBROM_START_ADDR (0x6180)
#define IBROM_END_ADDR   (0x61FF)

#define XRAM_SIZE        (0x0300)
#define XRAM_START_ADDR  (0x0000)
#define XRAM_END_ADDR    (0x02FF)

#define IRAM_SIZE        (0x0100)
#define IRAM_START_ADDR  (0x00)
#define IRAM_END_ADDR    (0xFF)

typedef IROM irom_region_t;
typedef IROM *ibrom_region_t;
typedef XRAM xram_region_t;
typedef IRAM iram_region_t;

typedef struct MEMORY_DEF {
	irom_region_t  *pRom;
	ibrom_region_t *pIbrom;
	xram_region_t  *pXram;
	iram_region_t  *pIram;
}memory_t;

#endif /* MEMORY_H */
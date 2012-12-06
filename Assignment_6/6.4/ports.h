#ifndef PORTS_H
#define PORTS_H

typedef	unsigned char port8;
typedef	unsigned short port16;

#define	PARALLELL_OUT_ADR	0x0500
#define	PARALLELL_OUT 		*((port8*) PARALLELL_OUT_ADR)

#define ML15IN			0x09c0
#define KEYOUT		*((port8*) ML15IN)

#define ML15DSP_MODE_ADR 	0x09c2
#define ML15DSP_DATA_ADR 	0x09c3

#define ML15DSP_MODE 		*((port8*) ML15DSP_MODE_ADR)
#define ML15DSP_DATA 		*((port8*) ML15DSP_DATA_ADR)

#define DRILL_CONTROL_ADR	0x0400
#ifdef	SIMULATOR
   #define DRILL_STATUS_ADR	0x0401
#else
   #define DRILL_STATUS_ADR	0x0600
#endif

#define DrillStatus		*((port8*) DRILL_STATUS_ADR)
#define DrillControl		*((port8*) DRILL_CONTROL_ADR)

#endif

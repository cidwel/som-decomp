#include "som_c.h"

/* C23766 finish_boss_airborne_motion_when_landed   [class A, 20 bytes, 10 instructions]
 * Source: src/rom/finish_boss_airborne_motion_when_landed.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void finish_boss_airborne_motion_when_landed(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0066 + x);
    if (value == 0) {
        RAM16_SET(0x0064 + x, 0);
        RAM16_SET(0x0066 + x, 0);
        RAM16_SET(0x0090 + x, 0);
        r->a = value;
        r->c = 1;
        r->z = value == 0;
        r->n = value & 0x8000;
        RETURN_RTS(c);
    }
    if (!(value & 0x8000)) {
        r->a = value;
        r->c = 0;
        r->z = value == 0;
        r->n = value & 0x8000;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0064 + x, 0);
    RAM16_SET(0x0066 + x, 0);
    RAM16_SET(0x0090 + x, 0);
    r->a = value;
    r->c = 1;
    r->z = value == 0;
    r->n = value & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23766, SOM_RTS, "gen", finish_boss_airborne_motion_when_landed, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 20, 10)

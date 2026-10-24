#include "som_c.h"

/* C186C6 load_queued_native_motion_presentation_graphics   [class A, 11 bytes, 4 instructions]
 * Source: src/rom/load_queued_native_motion_presentation_graphics.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BCV.
 */
static void load_queued_native_motion_presentation_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    BUS16_SET(c, (uint16_t)(dp + 0x14), y);
    uint16_t value = BUS16(c, 0xD04158 + x);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    TAIL_CALL(c, 0xC18686, SOM_RTS); /* external */
}
SOM_REGISTER(0xC186C6, SOM_RTS, "gen", load_queued_native_motion_presentation_graphics, 0, L_B | L_C | L_V, 1, -1, 0, 11, 4)

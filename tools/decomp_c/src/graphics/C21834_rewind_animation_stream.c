#include "som_c.h"

/* C21834 rewind_animation_stream   [class A, 6 bytes, 3 instructions]
 * Source: src/rom/rewind_animation_stream.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void rewind_animation_stream(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->x = RAM16(0x0287);
    r->y = 0;
    r->z = 1;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21834, SOM_RTS, "gen", rewind_animation_stream, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 6, 3)

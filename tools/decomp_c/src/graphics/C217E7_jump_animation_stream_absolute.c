#include "som_c.h"

/* C217E7 jump_animation_stream_absolute   [class A, 9 bytes, 5 instructions]
 * Source: src/rom/jump_animation_stream_absolute.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void jump_animation_stream_absolute(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2;
    BUS16_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y, value2);
    RAM16_SET(0x009C + value, value2);
    r->a = value2;
    r->x = value;
    r->y = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC217E7, SOM_RTS, "hand", jump_animation_stream_absolute, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 9, 5)

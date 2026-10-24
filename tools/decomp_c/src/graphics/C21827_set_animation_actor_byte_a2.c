#include "som_c.h"

/* C21827 set_animation_actor_byte_a2   [class A, 13 bytes, 7 instructions]
 * Source: src/rom/set_animation_actor_byte_a2.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void set_animation_actor_byte_a2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2;
    BUS16_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y, value2);
    RAM8(0x00A2 + value) = (uint8_t)value2;
    r->a = value2;
    r->x = value;
    r->y = (uint16_t)(y + 1);
    r->z = (uint16_t)(y + 1) == 0;
    r->n = (uint16_t)(y + 1) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21827, SOM_RTS, "hand", set_animation_actor_byte_a2, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 13, 7)

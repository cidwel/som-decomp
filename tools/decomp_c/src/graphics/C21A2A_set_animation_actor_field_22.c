#include "som_c.h"

/* C21A2A set_animation_actor_field_22   [class A, 10 bytes, 6 instructions]
 * Source: src/rom/set_animation_actor_field_22.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void set_animation_actor_field_22(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value;
    BUS16_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y, value);
    uint16_t value2 = RAM16(0x0287);
    RAM16_SET(0x0022 + value2, value);
    r->a = value;
    r->x = value2;
    r->y = (uint16_t)(y + 2);
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21A2A, SOM_RTS, "hand", set_animation_actor_field_22, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 6)

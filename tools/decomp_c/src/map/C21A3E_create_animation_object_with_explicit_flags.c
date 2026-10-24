#include "som_c.h"

/* C21A3E create_animation_object_with_explicit_flags   [class B, 67 bytes, 32 instructions]
 * Source: src/rom/create_animation_object_with_explicit_flags.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void create_animation_object_with_explicit_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM16_SET(0x029A, 0);
    RAM16_SET(0x029C, 0);
    uint16_t value;
    BUS16_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y, value);
    RAM16_SET(0x0297, value);
    uint16_t value2;
    BUS16_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + (uint16_t)(y + 2), value2);
    RAM16_SET(0x02A5, value2);
    r->y = (uint16_t)(y + 4);
    JSR(c, 0x1A50, 0xC21978); /* prepare_animation_object_mirrored_position */
    uint16_t y_ret = r->y;
    uint16_t value3 = RAM16(0x02A5);
    r->x = 0x31D4;
    r->y = value3;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x1A59, 0xC20D53); /* allocate_boss_object_pool_slot */
    r->sp += 2;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x009A + x_ret2, RAM16(0x0297));
    RAM16_SET(0x002B + x_ret2, RAM16(0x029F));
    RAM16_SET(0x0032 + x_ret2, RAM16(0x02A1));
    RAM16_SET(0x0066 + x_ret2, RAM16(0x029D));
    RAM16_SET(0x00B0 + x_ret2, RAM16(0x02A3));
    RAM16_SET(0x00B2 + x_ret2, RAM16(0x0299));
    uint16_t value10 = RAM16(0x029B);
    RAM16_SET(0x00B4 + x_ret2, value10);
    uint16_t value11 = RAM16(0x0287);
    r->a = value10;
    r->x = value11;
    r->y = y_ret;
    r->z = y_ret == 0;
    r->n = y_ret & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21A3E, SOM_RTS, "hand", create_animation_object_with_explicit_flags, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 67, 32)

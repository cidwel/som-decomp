#include "som_c.h"

/* C21933 create_animation_object_inheriting_orientation   [class B, 69 bytes, 31 instructions]
 * Source: src/rom/create_animation_object_inheriting_orientation.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void create_animation_object_inheriting_orientation(SomCtx *c)
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
    r->y = (uint16_t)(y + 2);
    JSR(c, 0x193F, 0xC21978); /* prepare_animation_object_mirrored_position */
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    uint16_t value2 = RAM16(0x0098 + x_ret);
    r->a = (value2 & 0x88E7) | 0x0220;
    r->x = 0x31D4;
    r->y = (value2 & 0x88E7) | 0x0220;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x1950, 0xC20D53); /* allocate_boss_object_pool_slot */
    r->sp += 2;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x009A + x_ret2, RAM16(0x0297));
    RAM16_SET(0x002B + x_ret2, RAM16(0x029F));
    RAM16_SET(0x0032 + x_ret2, RAM16(0x02A1));
    RAM16_SET(0x0066 + x_ret2, RAM16(0x029D));
    RAM16_SET(0x00B0 + x_ret2, RAM16(0x02A3));
    RAM16_SET(0x00B2 + x_ret2, RAM16(0x0299));
    uint16_t value9 = RAM16(0x029B);
    RAM16_SET(0x00B4 + x_ret2, value9);
    uint16_t value10 = RAM16(0x0287);
    r->a = value9;
    r->x = value10;
    r->y = y_ret;
    r->z = y_ret == 0;
    r->n = y_ret & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21933, SOM_RTS, "hand", create_animation_object_inheriting_orientation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 69, 31)

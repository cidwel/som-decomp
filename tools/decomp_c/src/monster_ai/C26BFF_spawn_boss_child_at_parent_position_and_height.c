#include "som_c.h"

/* C26BFF spawn_boss_child_at_parent_position_and_height   [class B, 54 bytes, 22 instructions]
 * Source: src/rom/spawn_boss_child_at_parent_position_and_height.s
 * Documented in docs/boss-native-child-capture.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void spawn_boss_child_at_parent_position_and_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0295, RAM16(0x002B + x));
    RAM16_SET(0x0297, RAM16(0x0032 + x));
    RAM16_SET(0x0299, RAM16(0x0066 + x));
    RAM16_SET(0x029B, x);
    uint16_t value4 = RAM16(0x0098 + x);
    r->a = (value4 & 3) | 0xA920;
    r->x = 0x6C9F;
    r->y = (value4 & 3) | 0xA920;
    JSR(c, 0x6C1F, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    RAM16_SET(0x002B + x_ret, RAM16(0x0295));
    RAM16_SET(0x0032 + x_ret, RAM16(0x0297));
    RAM16_SET(0x0066 + x_ret, RAM16(0x0299));
    uint16_t value8 = RAM16(0x029B);
    RAM16_SET(0x00B0 + x_ret, value8);
    r->a = value8;
    r->z = value8 == 0;
    r->n = value8 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26BFF, SOM_RTS, "gen", spawn_boss_child_at_parent_position_and_height, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 54, 22)

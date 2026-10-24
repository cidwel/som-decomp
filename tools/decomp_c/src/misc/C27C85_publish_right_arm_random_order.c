#include "som_c.h"

/* C27C85 publish_right_arm_random_order   [class A, 24 bytes, 9 instructions]
 * Source: src/rom/publish_right_arm_random_order.s
 * Documented in docs/boss-native58-action-helpers.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void publish_right_arm_random_order(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 1;
    JSR(c, 0x7C8A, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all = r->a;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x00B4 + value, a_all | 0x4000);
    r->a = 0x012F;
    r->x = value;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7C98, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B2 + value, 0);
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27C85, SOM_RTS, "gen", publish_right_arm_random_order, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 24, 9)

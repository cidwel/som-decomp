#include "som_c.h"

/* C27003 refresh_descriptor_eight_child_parent_state_animation   [class A, 23 bytes, 10 instructions]
 * Source: src/rom/refresh_descriptor_eight_child_parent_state_animation.s
 * Documented in docs/boss-descriptor-eight-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void refresh_descriptor_eight_child_parent_state_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    uint16_t value2 = BUS16(c, 0xDCE4A9 + (uint16_t)(RAM16(0x007A + y) << 1));
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x00B4 + value3);
    uint8_t a_hi1;
    if (value2 == value4) {
        a_hi1 = value2 >> 8;
    } else {
        RAM16_SET(0x00B4 + value3, value2);
        r->a = value2;
        r->x = value3;
        r->c = value2 >= value4;
        JSR(c, 0x7018, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all = r->a;
        a_hi1 = a_all >> 8;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = value3;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27003, SOM_RTS, "gen", refresh_descriptor_eight_child_parent_state_animation, 0, L_B | L_X | L_Y, 1, 0, 0, 23, 10)

#include "som_c.h"

/* C23A9A create_boss_terminal_visual_effect_pair   [class B, 65 bytes, 25 instructions]
 * Source: src/rom/create_boss_terminal_visual_effect_pair.s
 * Documented in docs/boss-native-linked-death-phases.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void create_boss_terminal_visual_effect_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0098 + x);
    uint8_t a_hi1;
    if ((value & 8) != 0) {
        r->a = 0x0133;
        JSR(c, 0x3AAF, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all = r->a;
        a_hi1 = a_all >> 8;
    } else {
        r->a = 0;
        JSR(c, 0x3AA7, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all2 = r->a;
        a_hi1 = a_all2 >> 8;
    }
    RAM16_SET(0x0295, RAM16(0x002B + x));
    uint16_t value3 = RAM16(0x0032 + x);
    uint16_t value4 = RAM16(0x0062 + x);
    RAM16_SET(0x0297, (uint16_t)(value3 + value4));
    r->a = (uint16_t)(value3 + value4);
    r->x = 0x3ADB;
    r->y = 0x2A21;
    r->v = ((value3 ^ (uint16_t)(value3 + value4)) & (value4 ^ (uint16_t)(value3 + value4)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3AC6, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    RAM16_SET(0x002B + x_ret, RAM16(0x0295));
    uint16_t value6 = RAM16(0x0297);
    RAM16_SET(0x0032 + x_ret, value6);
    r->a = value6;
    r->x = 0x3C78;
    r->y = 0x2100;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3AD9, 0xC20D53); /* allocate_boss_object_pool_slot */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23A9A, SOM_RTS, "gen", create_boss_terminal_visual_effect_pair, 0, L_B | L_Y | L_V, 1, 0, 0, 65, 25)

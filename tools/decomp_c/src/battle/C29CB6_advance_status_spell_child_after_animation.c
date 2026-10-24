#include "som_c.h"

/* C29CB6 advance_status_spell_child_after_animation   [class A, 24 bytes, 10 instructions]
 * Source: src/rom/advance_status_spell_child_after_animation.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_status_spell_child_after_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x009E + value);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    if (value2 != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = value;
        y1 = y;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        RAM16_SET(OBJECT_AGE + value, 0);
        r->a = 0;
        r->x = value;
        JSR(c, 0x9CC8, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x9CCB, 0xC29CCE); /* mark_single_or_three_spell_targets_control19 */
        uint16_t a_all2 = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret;
        y1 = y_ret;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29CB6, SOM_RTS, "gen", advance_status_spell_child_after_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 24, 10)

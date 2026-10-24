#include "som_c.h"

/* C23129 initialize_parent_linked_boss_effect_animation_and_following   [class B, 73 bytes, 31 instructions]
 * Source: src/rom/initialize_parent_linked_boss_effect_animation_and_following.s
 * Documented in docs/boss-descriptor-zero-child-follow.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_parent_linked_boss_effect_animation_and_following(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0029 + value, 0);
    RAM16_SET(0x0030 + value, 0);
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(0x008C + value, 1);
    uint16_t value3 = RAM16(0x00A7 + value);
    uint16_t value4 = BUS16(c, 0xC23172 + (uint16_t)(value3 << 1));
    uint16_t value5 = RAM16(0x0287);
    r->a = value4;
    r->x = value5;
    r->c = value3 & 0x8000;
    JSR(c, 0x314A, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0090 + value5, 0x3182);
    uint16_t value6 = RAM16(0x0287);
    uint16_t value7 = RAM16(0x00B0 + value6);
    uint16_t value8 = RAM16(0x00A7 + value7);
    if (value8 == 0) {
        r->a = value8;
        r->x = value6;
        r->y = value7;
        r->c = 1;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value9 = RAM16(0x00A7 + value6);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    bool zero1;
    bool negative1;
    if (value8 == value9) {
        a1 = (uint8_t)value8;
        a_hi1 = value8 >> 8;
        x1 = value6;
        zero1 = value8 == value9;
        negative1 = (uint16_t)(value8 - value9) & 0x8000;
    } else {
        RAM16_SET(0x00A7 + value6, value8);
        uint16_t value10 = BUS16(c, 0xC23172 + (uint16_t)(value8 << 1));
        uint16_t value11 = RAM16(0x0287);
        r->a = value10;
        r->x = value11;
        r->y = value7;
        r->c = value8 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x316D, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all2 = r->a;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = value11;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = value7;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23129, SOM_RTS, "gen", initialize_parent_linked_boss_effect_animation_and_following, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 73, 31)

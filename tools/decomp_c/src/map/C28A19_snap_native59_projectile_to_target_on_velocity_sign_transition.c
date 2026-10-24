#include "som_c.h"

/* C28A19 snap_native59_projectile_to_target_on_velocity_sign_transition   [class B, 58 bytes, 22 instructions]
 * Source: src/rom/snap_native59_projectile_to_target_on_velocity_sign_transition.s
 * Documented in docs/boss-native59-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void snap_native59_projectile_to_target_on_velocity_sign_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00C6 + value);
    uint8_t a_hi2;
    uint16_t y2;
    if (!(value2 & 0x8000)) {
        a_hi2 = value2 >> 8;
        y2 = y;
    } else {
        uint16_t value3 = RAM16(0x00B4 + value);
        uint8_t a_hi1;
        uint16_t y1;
        if (value3 & 0x8000) {
            a_hi1 = value3 >> 8;
            y1 = y;
        } else {
            uint16_t value4 = RAM16(0x00B2 + value);
            RAM16_SET(0x002B + value, RAM16(0x0002 + value4));
            uint16_t value6 = RAM16(0x0004 + value4);
            RAM16_SET(0x0032 + value, value6);
            a_hi1 = value6 >> 8;
            y1 = value4;
        }
        a_hi2 = a_hi1;
        y2 = y1;
    }
    RAM16_SET(0x00B4 + value, RAM16(0x00C6 + value));
    uint16_t value8 = RAM16(0x0066 + value);
    uint8_t a1;
    uint8_t a_hi3;
    bool zero1;
    bool negative1;
    if (value8 != 0) {
        a1 = (uint8_t)value8;
        a_hi3 = value8 >> 8;
        zero1 = value8 == 0;
        negative1 = value8 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        r->a = 0x010E;
        r->x = value;
        r->y = y2;
        JSR(c, 0x8A47, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all = r->a;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        RAM16_SET(0x0066 + value, 0);
        RAM16_SET(0x0090 + value, 0);
        RAM16_SET(0x00B4 + value, 0);
        a1 = (uint8_t)a_all;
        a_hi3 = a_all >> 8;
        zero1 = zero_ret;
        negative1 = negative_ret;
    }
    r->a = (a_hi3 << 8) | a1;
    r->x = value;
    r->y = y2;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28A19, SOM_RTS, "gen", snap_native59_projectile_to_target_on_velocity_sign_transition, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 58, 22)

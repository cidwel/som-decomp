#include "som_c.h"

/* C2454E choose_native54_spawn_or_attack_state_after_twelve_ticks   [class B, 72 bytes, 29 instructions]
 * Source: src/rom/choose_native54_spawn_or_attack_state_after_twelve_ticks.s
 * Documented in docs/boss-native54-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_native54_spawn_or_attack_state_after_twelve_ticks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if (value2 < 0x0C) {
        a2 = (uint8_t)value2;
        a_hi2 = value2 >> 8;
        x2 = value;
        y2 = y;
        zero2 = value2 == 0x0C;
        negative2 = (uint16_t)(value2 - 0x0C) & 0x8000;
        overflow2 = overflow;
    } else {
        uint16_t value3 = RAM16(0x00B2 + value);
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (value3 == 0) {
            RAM16_SET(OBJECT_PHASE + value, 3);
            RAM16_SET(0x00BA + value, 0);
            a1 = 3;
            a_hi1 = 0;
            x1 = value;
            y1 = y;
            zero1 = 0;
            negative1 = 0;
            overflow1 = overflow;
        } else {
            JSR(c, 0x455F, 0xC23224); /* select_nearest_active_living_party_actor */
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            RAM16_SET(0x00A9 + RAM16(0x0287), a_all);
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x4567, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
            uint16_t a_all2 = r->a;
            bool overflow_ret2 = r->v;
            uint16_t value5 = BUS16(c, 0xDCE5FB + (uint16_t)(a_all2 << 1));
            RAM16_SET(0x0295, value5);
            uint16_t value6 = RAM16(0x0287);
            RAM16_SET(0x0098 + value6, (RAM16(0x0098 + value6) & 0xFF3F) | RAM16(0x0295));
            RAM16_SET(OBJECT_PHASE + value6, 4);
            r->a = 0x72;
            r->x = value6;
            r->c = a_all2 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x4588, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
            uint16_t a_all3 = r->a;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            a1 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            x1 = value6;
            y1 = y_ret;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow1 = overflow_ret2;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->y = y2;
    r->c = 0;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2454E, SOM_RTS, "gen", choose_native54_spawn_or_attack_state_after_twelve_ticks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 72, 29)

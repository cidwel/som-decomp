#include "som_c.h"

/* C24D20 recover_body_target_after_thirty_two_ticks   [class B, 44 bytes, 19 instructions]
 * Source: src/rom/recover_body_target_after_thirty_two_ticks.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void recover_body_target_after_thirty_two_ticks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value2 = RAM16(0x00B0 + RAM16(0x0287));
    RAM16_SET(0x00BC + value2, (uint16_t)(RAM16(0x00BC + value2) + 1));
    r->a = value2;
    r->x = value2;
    JSR(c, 0x4D2B, 0xC24DB9); /* consume_body_damage_or_parent_phase15_and_enter_hurt */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if (carry_ret) {
        a2 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y;
        zero2 = zero_ret;
        negative2 = negative_ret;
        overflow2 = overflow;
    } else {
        RAM16_SET(0x0295, 0x20);
        uint16_t value4 = RAM16(0x0287);
        uint16_t value5 = RAM16(OBJECT_AGE + value4);
        uint16_t value6 = RAM16(0x0295);
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (value5 < value6) {
            a1 = (uint8_t)value5;
            a_hi1 = value5 >> 8;
            x1 = value4;
            y1 = y;
            zero1 = value5 == value6;
            negative1 = (uint16_t)(value5 - value6) & 0x8000;
            overflow1 = overflow;
        } else {
            r->a = value5;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x4D3E, 0xC24BEC); /* select_native54_body_nearest_party_target */
            uint16_t a_all2 = r->a;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            uint16_t value7 = RAM16(0x0287);
            RAM16_SET(0x00A9 + value7, a_all2);
            RAM16_SET(OBJECT_PHASE + value7, 1);
            a1 = 1;
            a_hi1 = 0;
            x1 = value7;
            y1 = y_ret;
            zero1 = 0;
            negative1 = 0;
            overflow1 = overflow_ret;
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
SOM_REGISTER(0xC24D20, SOM_RTS, "gen", recover_body_target_after_thirty_two_ticks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 44, 19)

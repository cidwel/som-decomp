#include "som_c.h"

/* C24C43 enter_body_retraction_after_six_ticks   [class B, 49 bytes, 22 instructions]
 * Source: src/rom/enter_body_retraction_after_six_ticks.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void enter_body_retraction_after_six_ticks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint16_t value2 = RAM16(0x00B0 + RAM16(0x0287));
    RAM16_SET(0x00BC + value2, (uint16_t)(RAM16(0x00BC + value2) + 1));
    uint16_t value3 = RAM16(0x0287);
    r->a = value2;
    r->x = value3;
    JSR(c, 0x4C50, 0xC24DB9); /* consume_body_damage_or_parent_phase15_and_enter_hurt */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    uint8_t a2;
    uint8_t a_hi2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if (carry_ret) {
        a2 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        zero2 = zero_ret;
        negative2 = negative_ret;
        overflow2 = overflow;
    } else {
        uint16_t value4 = RAM16(OBJECT_AGE + x_ret);
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (value4 != 6) {
            a1 = (uint8_t)value4;
            a_hi1 = value4 >> 8;
            zero1 = value4 == 6;
            negative1 = (uint16_t)(value4 - 6) & 0x8000;
            overflow1 = overflow;
        } else {
            RAM16_SET(OBJECT_AGE + x_ret, 0);
            RAM16_SET(OBJECT_PHASE + x_ret, 6);
            uint16_t value5 = RAM16(0x00B2 + x_ret);
            uint16_t value6 = RAM16(0x0289);
            RAM16_SET(0x00B8 + x_ret, (uint16_t)((uint16_t)((uint16_t)(value5 << 2) + 3) + value6 + ((uint16_t)(value5 << 2) + 3 > 0xFFFF)));
            a1 = (uint8_t)((uint16_t)((uint16_t)(value5 << 2) + 3) + value6 + ((uint16_t)(value5 << 2) + 3 > 0xFFFF));
            a_hi1 = (uint16_t)((uint16_t)((uint16_t)(value5 << 2) + 3) + value6 + ((uint16_t)(value5 << 2) + 3 > 0xFFFF)) >> 8;
            zero1 = (uint16_t)((uint16_t)((uint16_t)(value5 << 2) + 3) + value6 + ((uint16_t)(value5 << 2) + 3 > 0xFFFF)) == 0;
            negative1 = (uint16_t)((uint16_t)((uint16_t)(value5 << 2) + 3) + value6 + ((uint16_t)(value5 << 2) + 3 > 0xFFFF)) & 0x8000;
            overflow1 = (((uint16_t)((uint16_t)(value5 << 2) + 3) ^ (uint16_t)((uint16_t)((uint16_t)(value5 << 2) + 3) + value6 + ((uint16_t)(value5 << 2) + 3 > 0xFFFF))) & (value6 ^ (uint16_t)((uint16_t)((uint16_t)(value5 << 2) + 3) + value6 + ((uint16_t)(value5 << 2) + 3 > 0xFFFF))) & 0x8000) != 0;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->c = 0;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24C43, SOM_RTS, "gen", enter_body_retraction_after_six_ticks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 49, 22)

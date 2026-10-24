#include "som_c.h"

/* C2C64E test_charge_effect_homing_target_distance_threshold   [class B, 51 bytes, 24 instructions]
 * Source: src/rom/test_charge_effect_homing_target_distance_threshold.s
 * Documented in docs/actor-charge-effect-update.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void test_charge_effect_homing_target_distance_threshold(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xE020 + x);
    uint16_t value2 = RAM16(0x0004);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value - value2) & 0x8000)) {
        a1 = (uint8_t)(value - value2);
        a_hi1 = (uint16_t)(value - value2) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
    }
    uint8_t a_hi3;
    bool carry1;
    bool overflow1;
    if (((a_hi1 << 8) | a1) >= 8) {
        a_hi3 = a_hi1;
        carry1 = ((a_hi1 << 8) | a1) >= 8;
        overflow1 = ((value ^ value2) & (value ^ (uint16_t)(value - value2)) & 0x8000) != 0;
    } else {
        uint16_t value3 = RAM16(0xE074 + x);
        uint16_t value4 = RAM16(0xE045 + x);
        uint16_t value5 = RAM16(0xE022 + x);
        uint16_t value6 = RAM16(0x0006);
        uint8_t a2;
        uint8_t a_hi2;
        if (!((uint16_t)((uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5) - value6) & 0x8000)) {
            a2 = (uint8_t)((uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5) - value6);
            a_hi2 = (uint16_t)((uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5) - value6) >> 8;
        } else {
            a2 = (uint8_t)(((uint16_t)((uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5) - value6) ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)(((uint16_t)((uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5) - value6) ^ 0xFFFF) + 1) >> 8;
        }
        a_hi3 = a_hi2;
        carry1 = ((a_hi2 << 8) | a2) >= 8;
        overflow1 = (((uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5) ^ value6) & ((uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5) ^ (uint16_t)((uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5) - value6)) & 0x8000) != 0;
    }
    r->a = (r->a & 0x00FF) | (a_hi3 << 8);
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C64E, SOM_RTS, "gen", test_charge_effect_homing_target_distance_threshold, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 51, 24)

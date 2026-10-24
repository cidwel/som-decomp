#include "som_c.h"

/* C20989 query_party_half_maximum_over_current_hp_ratio_capped_four   [class B, 43 bytes, 21 instructions]
 * Source: src/rom/query_party_half_maximum_over_current_hp_ratio_capped_four.s
 * Documented in docs/boss-party-hp-query.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void query_party_half_maximum_over_current_hp_ratio_capped_four(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if (!(RAM16(0x0190 + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & 0x8000)) {
        RAM16_SET(0x034E, RAM16(0x0182 + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)));
        uint16_t value3 = RAM16(0x0184 + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000));
        RAM16_SET(0x0346, value3);
        r->a = value3;
        r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
        r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
        r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x09A7, 0xC22CBF); GUARD_JSR(c, sp_call, 0x09A7); } /* divide_unsigned_word_by_word_in_software */
        uint16_t value4 = RAM16(0x0356);
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        if (value4 >> 1 < 4) {
            a1 = (uint8_t)(value4 >> 1);
            a_hi1 = value4 >> 1 >> 8;
            zero1 = value4 >> 1 == 4;
            negative1 = (uint16_t)((value4 >> 1) - 4) & 0x8000;
        } else {
            a1 = 4;
            a_hi1 = 0;
            zero1 = 0;
            negative1 = 0;
        }
        r->a = (a_hi1 << 8) | a1;
        r->c = value4 >> 1 >= 4;
        r->z = zero1;
        r->n = negative1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x03C5);
    r->a = value5;
    r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
    r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
    r->z = value5 == 0;
    r->n = value5 & 0x8000;
    r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20989, SOM_RTS, "gen", query_party_half_maximum_over_current_hp_ratio_capped_four, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 43, 21)

#include "som_c.h"

/* C14708 make_accumulator_low_nibble_one_hot_index   [class B, 24 bytes, 15 instructions]
 * Source: src/rom/make_accumulator_low_nibble_one_hot_index.s
 * Documented in docs/actor-entity-index-bits.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void make_accumulator_low_nibble_one_hot_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a2;
    uint8_t a_hi2;
    if ((((a_hi << 8) | a) & 0x0F) == 0) {
        a2 = 1;
        a_hi2 = 0;
    } else {
        uint8_t a1 = 1;
        uint8_t a_hi1 = 0;
        uint16_t x1 = ((a_hi << 8) | a) & 0x0F;
        for (;;) {
            uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) << 1);
            uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) << 1) >> 8;
            uint16_t x1_next = (uint16_t)(x1 - 1);
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            if (!(x1 != 0)) break;
        }
        a2 = a1;
        a_hi2 = a_hi1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = (a_hi2 << 8) | a2;
    r->y = y;
    r->c = carry;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14708, SOM_RTS, "gen", make_accumulator_low_nibble_one_hot_index, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 24, 15)

#include "som_c.h"

/* C12710 highest_set_bit_index   [class B, 24 bytes, 16 instructions]
 * Source: src/rom/highest_set_bit_index.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=any X=16 bit DB=$7E D=$01DF.  Callers read: AB.
 */
static void highest_set_bit_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x01DF) { c->fail = 3; return; }
    const uint8_t m_entry = r->mf;
    const uint16_t x = r->x;
    uint8_t a1 = (uint8_t)x;
    uint8_t a_hi1 = x >> 8;
    uint16_t x1 = 0x10;
    for (;;) {
        uint8_t a2;
        uint8_t a_hi2;
        if (((a_hi1 << 8) | a1) & 0x8000) {
            a2 = (uint8_t)(x1 - 1);
            a_hi2 = (uint16_t)(x1 - 1) >> 8;
        } else {
            if ((uint16_t)(x1 - 1) != 0) {
                uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) << 1);
                uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) << 1) >> 8;
                uint16_t x1_next = (uint16_t)(x1 - 1);
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                continue;
            }
            a2 = 0xFF;
            a_hi2 = 0;
        }
        a1 = a2;
        a_hi1 = a_hi2;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->mf = m_entry;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12710, SOM_RTS, "gen", highest_set_bit_index, 0, L_A | L_B, 3, -1, 0, 24, 16)

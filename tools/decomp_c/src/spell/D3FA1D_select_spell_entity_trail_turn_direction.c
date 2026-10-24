#include "som_c.h"

/* D3FA1D select_spell_entity_trail_turn_direction   [class B, 82 bytes, 40 instructions]
 * Source: src/rom/select_spell_entity_trail_turn_direction.s
 * Documented in docs/actor-cast-entity-trail-direction.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XCV.
 */
static void select_spell_entity_trail_turn_direction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint16_t value = RAM16(0x014C + x);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), value & 3);
    uint8_t a7;
    if ((value & 1) == 0) {
        uint16_t value2 = RAM16(0x0140 + x);
        uint16_t value3 = RAM16(0x0144 + x);
        uint8_t a3;
        if ((uint16_t)(value2 - value3) & 0x8000) {
            uint8_t a1;
            if (!overflow) {
                a1 = 3;
            } else {
                a1 = 1;
            }
            a3 = a1;
        } else {
            uint8_t a2;
            if (overflow) {
                a2 = 3;
            } else {
                a2 = 1;
            }
            a3 = a2;
        }
        a7 = a3;
    } else {
        uint16_t value4 = RAM16(0x0142 + x);
        uint16_t value5 = RAM16(0x0146 + x);
        uint8_t a6;
        if ((uint16_t)(value4 - value5) & 0x8000) {
            uint8_t a4;
            if (!overflow) {
                a4 = 2;
            } else {
                a4 = 0;
            }
            a6 = a4;
        } else {
            uint8_t a5;
            if (overflow) {
                a5 = 2;
            } else {
                a5 = 0;
            }
            a6 = a5;
        }
        a7 = a6;
    }
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 5)) << 1));
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 5)) << 1));
    RAM16_SET(0x014C + x, a7 | RAM16(0x0001 + (uint16_t)(sp0 - 5)));
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FA1D, SOM_RTS, "gen", select_spell_entity_trail_turn_direction, 0, L_X | L_C | L_V, 5, 1, 0, 82, 40)

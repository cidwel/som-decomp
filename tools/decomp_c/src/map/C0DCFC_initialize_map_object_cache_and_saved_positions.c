#include "som_c.h"

/* C0DCFC initialize_map_object_cache_and_saved_positions   [class B, 89 bytes, 46 instructions]
 * Source: src/rom/initialize_map_object_cache_and_saved_positions.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void initialize_map_object_cache_and_saved_positions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x00BD) = 0;
    uint8_t value = RAM8(0x00BC);
    RAM8(0x0004) = value;
    if (value != 0) {
        uint8_t a_hi1 = a >> 8;
        uint16_t x1 = 0;
        uint16_t y1 = y;
        bool carry1 = carry;
        bool overflow1 = overflow;
        do {
            r->x = x1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            JSR(c, 0xDD12, 0xC0DD55); /* copy_map_object_record_to_cache */
            uint16_t y_ret = r->y;
            RAM16_SET(0x000D, (uint16_t)(RAM16(0x000D) + 8));
            RAM8(0x0004)--;
            uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + 0x10);
            uint16_t y1_next = y_ret;
            bool carry1_next = x1 + 0x10 > 0xFFFF;
            bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            overflow1 = overflow1_next;
        } while (RAM8(0x0004) != 0);
        uint8_t value3 = RAM8(0x00E8);
        RAM8(0x00E8) &= 0x7F;
        if ((value3 & 0x80) != 0) {
            uint8_t a1 = 0x80;
            uint8_t a_hi2 = a_hi1;
            uint16_t x2 = 0;
            uint16_t y2 = 0;
            bool carry2 = carry1;
            bool overflow2 = overflow1;
            for (;;) {
                RAM16_SET(0xC80A + x2, RAM16(0xCD70 + y2));
                RAM8(0xC80C + x2) = RAM8(0xCD72 + y2);
                uint8_t a1_next = (uint8_t)(x2 + 0x10);
                uint8_t a_hi2_next = (uint16_t)(x2 + 0x10) >> 8;
                uint16_t x2_next = (uint16_t)(x2 + 0x10);
                uint16_t y2_next = (uint16_t)(y2 + 3);
                bool carry2_next = (uint16_t)(y2 + 3) >= 0x90;
                bool overflow2_next = ((x2 ^ (uint16_t)(x2 + 0x10)) & ((uint16_t)(x2 + 0x10) ^ 0x10) & 0x8000) != 0;
                a1 = a1_next;
                a_hi2 = a_hi2_next;
                x2 = x2_next;
                y2 = y2_next;
                carry2 = carry2_next;
                overflow2 = overflow2_next;
                if (!(y2 < 0x90)) break;
            }
            r->a = (a_hi2 << 8) | a1;
            r->x = x2;
            r->y = y2;
            r->c = carry2;
            r->v = overflow2;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        r->a = (a_hi1 << 8) | 0x80;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    RAM8(0x00E8) &= 0x7F;
    SET_A8(r, 0x80);
    r->x = 0;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DCFC, SOM_RTS, "gen", initialize_map_object_cache_and_saved_positions, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 89, 46)

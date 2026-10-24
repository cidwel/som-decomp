#include "som_c.h"

/* D3F6C9 refresh_spell_frame_random_velocity_groups   [class B, 126 bytes, 69 instructions]
 * Source: src/rom/refresh_spell_frame_random_velocity_groups.s
 * Documented in docs/map-oam-spell-frames.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01E4.  Callers read: Y.
 */
static void refresh_spell_frame_random_velocity_groups(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01E4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xE4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0110 + x)--;
    uint16_t y3;
    if (RAM8(0x0110 + x) != 0) {
        y3 = y;
    } else {
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), x);
        r->a = ((uint16_t)(sp0 - 7) >> 8 << 8) | 0x10;
        r->c = (uint16_t)(sp0 - 3) >= 4;
        r->z = false;
        r->n = false;
        r->v = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
        r->mf = true;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 7;
        JSL(c, 0xF6E2, 0xC12ED1); /* draw_spell_entity_bounded_random_long */
        r->sp += 7;
        uint16_t a_all = r->a;
        RAM8(0x0110 + RAM16(0x0003 + (uint16_t)(sp0 - 7))) = (uint8_t)((uint8_t)a_all + 1);
        r->a = (a_all >> 8 << 8) | 0;
        r->z = true;
        r->n = false;
        r->mf = true;
        r->xf = false;
        r->sp -= 7;
        JSL(c, 0xF6EE, 0xC12ED1); /* draw_spell_entity_bounded_random_long */
        r->sp += 7;
        uint16_t a_all2 = r->a;
        RAM8(0x0105 + RAM16(0x0003 + (uint16_t)(sp0 - 7))) = (uint8_t)a_all2;
        r->a = (a_all2 >> 8 << 8) | 0;
        r->z = true;
        r->n = false;
        r->mf = true;
        r->xf = false;
        r->sp -= 7;
        JSL(c, 0xF6F9, 0xC12ED1); /* draw_spell_entity_bounded_random_long */
        r->sp += 7;
        uint16_t a_all3 = r->a;
        uint16_t value4 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        RAM8(0x0102 + value4) = (uint8_t)a_all3;
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 3);
        uint8_t a_hi1 = 0;
        uint16_t x1 = (uint16_t)(value4 + 0xF0);
        uint16_t y1 = (uint16_t)(value4 + 0x0102);
        bool carry1 = value4 + 0xF0 > 0xFFFF;
        bool zero1 = 0;
        bool negative1 = 0;
        bool overflow1 = ((value4 ^ (uint16_t)(value4 + 0xF0)) & ((uint16_t)(value4 + 0xF0) ^ 0xF0) & 0x8000) != 0;
        do {
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = false;
            r->xf = false;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 7;
            JSR(c, 0xF715, 0xD3F567); /* advance_spell_frame_signed_velocity */
            r->sp += 7;
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 7)) - 1));
            uint8_t a_hi1_next = (uint16_t)(x1 + 6) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + 6);
            bool carry1_next = x1 + 6 > 0xFFFF;
            bool zero1_next = RAM16(0x0001 + (uint16_t)(sp0 - 7)) == 0;
            bool negative1_next = RAM16(0x0001 + (uint16_t)(sp0 - 7)) & 0x8000;
            bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 6)) & ((uint16_t)(x1 + 6) ^ 6) & 0x8000) != 0;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            carry1 = carry1_next;
            zero1 = zero1_next;
            negative1 = negative1_next;
            overflow1 = overflow1_next;
        } while (RAM16(0x0001 + (uint16_t)(sp0 - 7)) != 0);
        uint16_t value5 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 3);
        uint8_t a_hi2 = 0;
        uint16_t x2 = (uint16_t)(value5 + 0xF0);
        uint16_t y2 = y1;
        bool carry2 = value5 + 0xF0 > 0xFFFF;
        bool overflow2 = ((value5 ^ (uint16_t)(value5 + 0xF0)) & ((uint16_t)(value5 + 0xF0) ^ 0xF0) & 0x8000) != 0;
        do {
            uint16_t value6 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
            r->a = (uint16_t)(value6 + 2);
            r->x = x2;
            r->y = y2;
            r->c = carry2;
            r->z = (uint16_t)(value6 + 2) == 0;
            r->n = (uint16_t)(value6 + 2) & 0x8000;
            r->v = overflow2;
            r->mf = false;
            r->xf = false;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 7;
            JSR(c, 0xF733, 0xD3F5B8); /* damp_spell_frame_velocity_with_mode7_product */
            r->sp += 7;
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 7)) - 1));
            uint8_t a_hi2_next = (uint16_t)(x2 + 6) >> 8;
            uint16_t x2_next = (uint16_t)(x2 + 6);
            bool carry2_next = x2 + 6 > 0xFFFF;
            bool overflow2_next = ((x2 ^ (uint16_t)(x2 + 6)) & ((uint16_t)(x2 + 6) ^ 6) & 0x8000) != 0;
            a_hi2 = a_hi2_next;
            x2 = x2_next;
            carry2 = carry2_next;
            overflow2 = overflow2_next;
        } while (RAM16(0x0001 + (uint16_t)(sp0 - 7)) != 0);
        y3 = y2;
    }
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->y = y3;
    r->mf = false;
    r->xf = false;
    r->db = 0x7E;
    r->dp = (value12 << 8) | value11;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F6C9, SOM_RTS, "hand", refresh_spell_frame_random_velocity_groups, 0, L_Y, 7, 0, 0, 126, 69)

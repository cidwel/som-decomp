#include "som_c.h"

/* 7E9D1E convert_components_to_planar_tile   [class B, 152 bytes, 88 instructions]
 * Source: src/boot/convert_components_to_planar_tile.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$05CF.  Callers read: XY.
 */
static void convert_components_to_planar_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x05CF) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0E) + 0x3 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xCF;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0E), x);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0E)) = 0x40;
    uint8_t a1 = 0x40;
    uint8_t a_hi1 = (uint16_t)(sp0 - 0x0E) >> 8;
    uint16_t x1 = x;
    uint16_t y1 = x;
    bool carry1 = (uint16_t)(sp0 - 3) >= 0x0B;
    bool zero1 = 0;
    bool negative1 = 0;
    bool overflow1 = (((uint16_t)(sp0 - 3) ^ 0x0B) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0E)) & 0x8000) != 0;
    uint16_t direct_page = (uint16_t)(sp0 - 0x0E);
    for (;;) {
        RAM8(0x0000 + sp0 - 0x0E) = x1 >> 8;
        RAM8(0x0000 + sp0 - 0x0F) = (uint8_t)x1;
        RAM8(0x0000 + sp0 - 0x10) = y1 >> 8;
        RAM8(0x0000 + sp0 - 0x11) = (uint8_t)y1;
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = direct_page;
        r->sp -= 18;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9D36, 0x7E87C9); GUARD_JSR(c, sp_call, 0x9D36); } /* lookup_cached_colour_sample */
        r->sp += 18;
        uint16_t dp_ret = r->dp;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint8_t value = RAM8(0x0000 + sp0 - 0x11);
        uint8_t value2 = RAM8(0x0000 + sp0 - 0x10);
        uint8_t value3 = RAM8(0x0000 + sp0 - 0x0F);
        uint8_t value4 = RAM8(0x0000 + sp0 - 0x0E);
        BUS8_SET(c, 0x000000 + ((value2 << 8) | value), (uint8_t)a_all);
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value5 - 1));
        a1 = (uint8_t)(((value4 << 8) | value3) + 4);
        a_hi1 = (uint16_t)(((value4 << 8) | value3) + 4) >> 8;
        x1 = (uint16_t)(((value4 << 8) | value3) + 4);
        y1 = (uint16_t)(((value2 << 8) | value) + 1);
        carry1 = ((value4 << 8) | value3) + 4 > 0xFFFF;
        zero1 = (uint8_t)(value5 - 1) == 0;
        negative1 = (uint8_t)(value5 - 1) & 0x80;
        overflow1 = ((((value4 << 8) | value3) ^ (uint16_t)(((value4 << 8) | value3) + 4)) & ((uint16_t)(((value4 << 8) | value3) + 4) ^ 4) & 0x8000) != 0;
        direct_page = dp_ret;
        if (!((uint8_t)(value5 - 1) != 0)) break;
    }
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(direct_page + 2));
    BUS8_SET(c, (uint16_t)(direct_page + 9), 8);
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = value6;
    uint16_t y2 = value6;
    for (;;) {
        BUS16_SET(c, (uint16_t)(direct_page + 4), x2);
        BUS16_SET(c, (uint16_t)(direct_page + 6), y2);
        BUS8_SET(c, (uint16_t)(direct_page + 8), 4);
        uint8_t a_hi3 = a_hi2;
        uint16_t y3 = y2;
        for (;;) {
            uint16_t value7 = BUS16_RDP(c, (uint16_t)(direct_page + 4));
            BUS8_SET(c, (uint16_t)(direct_page + 0x0A), 8);
            uint8_t a2 = 8;
            uint8_t a_hi4 = a_hi3;
            uint16_t x3 = value7;
            for (;;) {
                uint8_t value8 = BUS8(c, 0x000000 + x3);
                BUS8_SET(c, 0x000000 + x3, BUS8(c, 0x000000 + x3) >> 1);
                uint8_t value9 = BUS8_RDP(c, (uint16_t)(direct_page + 0x0A));
                BUS8_SET(c, (uint16_t)(direct_page + 0x0A), (uint8_t)(value9 - 1));
                a2 = (uint8_t)(a2 << 1 | (value8 & 1));
                x3 = (uint16_t)(x3 + 1);
                if (!((uint8_t)(value9 - 1) != 0)) break;
            }
            BUS8_SET(c, 0x0000C0 + y3, a2);
            uint16_t value10 = BUS16_RDP(c, (uint16_t)(direct_page + 4));
            BUS8_SET(c, (uint16_t)(direct_page + 0x0A), 8);
            uint8_t a3 = 8;
            uint8_t a_hi5 = a_hi4;
            uint16_t x4 = value10;
            for (;;) {
                uint8_t value11 = BUS8(c, 0x000000 + x4);
                BUS8_SET(c, 0x000000 + x4, BUS8(c, 0x000000 + x4) >> 1);
                uint8_t value12 = BUS8_RDP(c, (uint16_t)(direct_page + 0x0A));
                BUS8_SET(c, (uint16_t)(direct_page + 0x0A), (uint8_t)(value12 - 1));
                a3 = (uint8_t)(a3 << 1 | (value11 & 1));
                x4 = (uint16_t)(x4 + 1);
                if (!((uint8_t)(value12 - 1) != 0)) break;
            }
            BUS8_SET(c, 0x0000C0 + (uint16_t)(y3 + 1), a3);
            uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page + 8));
            BUS8_SET(c, (uint16_t)(direct_page + 8), (uint8_t)(value13 - 1));
            uint8_t a_hi3_next = (uint16_t)(y3 + 0x10) >> 8;
            uint16_t y3_next = (uint16_t)(y3 + 0x10);
            a_hi3 = a_hi3_next;
            y3 = y3_next;
            if (!((uint8_t)(value13 - 1) != 0)) break;
        }
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(direct_page + 4));
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page + 6));
        uint8_t value16 = BUS8_RDP(c, (uint16_t)(direct_page + 9));
        BUS8_SET(c, (uint16_t)(direct_page + 9), (uint8_t)(value16 - 1));
        a_hi2 = (uint16_t)(value14 + 8) >> 8;
        x2 = (uint16_t)(value14 + 8);
        y2 = (uint16_t)(value15 + 2);
        if (!((uint8_t)(value16 - 1) != 0)) break;
    }
    uint8_t value17 = BUS8_RDP(c, (uint16_t)(direct_page + 2));
    r->a = (a_hi2 << 8) | 0;
    r->x = (a_hi2 << 8) | (uint8_t)(value17 + 0xC0);
    r->y = y2;
    r->c = value17 + 0xC0 > 0xFF;
    r->z = 1;
    r->n = 0;
    r->v = ((value17 ^ (uint8_t)(value17 + 0xC0)) & ((uint8_t)(value17 + 0xC0) ^ 0xC0) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    r->dp = direct_page;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DAA, 0x7EBF2A); GUARD_JSR(c, sp_call, 0x9DAA); } /* copy_and_submit_colour_tile */
    r->sp += 14;
    uint8_t value18 = RAM8(0x0000 + sp0 - 2);
    uint8_t value19 = RAM8(0x0000 + sp0 - 1);
    uint8_t value20 = RAM8(0x0000 + sp0);
    r->mf = value18 & 0x20;
    r->xf = value18 & 0x10;
    r->dp = (value20 << 8) | value19;
    r->i = value18 & 0x04;
    r->d = value18 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9D1E, SOM_RTS, "gen", convert_components_to_planar_tile, 0, L_X | L_Y, 18, 1, 0, 152, 88)

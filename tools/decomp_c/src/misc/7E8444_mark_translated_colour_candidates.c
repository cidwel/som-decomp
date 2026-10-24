#include "som_c.h"

/* 7E8444 mark_translated_colour_candidates   [class B, 106 bytes, 56 instructions]
 * Source: src/boot/mark_translated_colour_candidates.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABY.
 */
static void mark_translated_colour_candidates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0C) + 0x9 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0C), x);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0C), RAM16(0x0018));
    uint16_t value2 = RAM16(0x001A);
    RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x0C), value2);
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0C), 0);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0C)) = 0xE8;
    uint8_t a_hi1 = value2 >> 8;
    uint16_t y1 = y;
    uint16_t direct_page = (uint16_t)(sp0 - 0x0C);
    for (;;) {
        uint8_t a_hi2 = a_hi1;
        uint16_t x1 = 3;
        uint16_t y2 = 0;
        uint16_t direct_page2 = direct_page;
        for (;;) {
            uint8_t value3 = BUS8_RDP(c, BUS16_RDP(c, (uint16_t)(direct_page2 + 8)) + 0x7E0000 + y2);
            uint8_t value4 = BUS8_RDP(c, BUS16_RDP(c, (uint16_t)(direct_page2 + 6)) + 0x7E0000 + y2);
            uint8_t a_hi3;
            uint16_t y3;
            uint16_t direct_page3;
            if (((uint8_t)(value3 + value4) & 0xE0) != 0) {
                a_hi3 = a_hi2;
                y3 = y2;
                direct_page3 = direct_page2;
            } else {
                BUS8_SET(c, BUS16_RDP(c, (uint16_t)(direct_page2 + 4)) + 0x7E0000 + y2, (uint8_t)(value3 + value4));
                if ((uint16_t)(x1 - 1) != 0) {
                    x1 = (uint16_t)(x1 - 1);
                    y2 = (uint16_t)(y2 + 1);
                    continue;
                }
                uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page2 + 4));
                r->a = (a_hi2 << 8) | (uint8_t)(value3 + value4);
                r->x = value5;
                r->y = (uint16_t)(y2 + 1);
                r->c = value3 + value4 > 0xFF;
                r->z = value5 == 0;
                r->n = value5 & 0x8000;
                r->v = ((value3 ^ (uint8_t)(value3 + value4)) & (value4 ^ (uint8_t)(value3 + value4)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = direct_page2;
                r->sp -= 12;
                { const uint16_t sp_call = r->sp; JSR(c, 0x847C, 0x7E83E2); GUARD_JSR(c, sp_call, 0x847C); } /* quantize_component_cube_index */
                r->sp += 12;
                uint16_t dp_ret = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all = r->a;
                uint16_t x_ret = r->x;
                uint8_t value6 = BUS8(c, 0x7F8000 + x_ret);
                if (value6 == 0) {
                    uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS8_SET(c, 0x7F8000 + x_ret, (uint8_t)(0xF7 - value7));
                    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                    BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)(value8 + 1));
                }
                a_hi3 = a_all >> 8;
                y3 = (uint16_t)(y2 + 1);
                direct_page3 = dp_ret;
            }
            a_hi2 = a_hi3;
            y2 = y3;
            direct_page2 = direct_page3;
            break;
        }
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(direct_page2 + 8));
        BUS16_SET(c, (uint16_t)(direct_page2 + 8), (uint16_t)(value9 + 4));
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(direct_page2 + 1));
        BUS8_SET(c, (uint16_t)(direct_page2 + 1), (uint8_t)(value10 - 1));
        a_hi1 = (uint16_t)(value9 + 4) >> 8;
        y1 = y2;
        direct_page = direct_page2;
        if (!((uint8_t)(value10 - 1) != 0)) break;
    }
    uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page + 2));
    RAM16_SET(0x0000 + sp0 - 4, value11);
    uint8_t value12 = RAM8(0x0000 + sp0 - 4);
    uint8_t value13 = RAM8(0x0000 + sp0 - 3);
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->a = (value13 << 8) | value12;
    r->y = y1;
    r->mf = value14 & 0x20;
    r->xf = value14 & 0x10;
    r->db = 0x7E;
    r->dp = (value16 << 8) | value15;
    r->i = value14 & 0x04;
    r->d = value14 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8444, SOM_RTS, "gen", mark_translated_colour_candidates, 0, L_A | L_B | L_Y, 12, 1, 0, 106, 56)

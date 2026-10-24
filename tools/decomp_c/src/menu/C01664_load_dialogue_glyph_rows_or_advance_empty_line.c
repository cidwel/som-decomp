#include "som_c.h"

/* C01664 load_dialogue_glyph_rows_or_advance_empty_line   [class B, 84 bytes, 42 instructions]
 * Source: src/rom/load_dialogue_glyph_rows_or_advance_empty_line.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void load_dialogue_glyph_rows_or_advance_empty_line(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA1CE);
    bool x_flag2;
    uint8_t a6;
    uint8_t a_hi6;
    uint16_t x6;
    uint16_t y6;
    bool carry4;
    bool zero4;
    bool overflow4;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if ((value & 0x7F) != 0) {
        RAM8(0xA176) = 0x20;
        uint8_t a1 = 0x20;
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = 0;
        uint16_t y1 = 0;
        bool carry1 = carry;
        bool zero1 = 1;
        bool overflow1 = overflow;
        do {
            uint8_t value2 = RAM8(0xA1A4 + x1);
            RAM8(0x0000 + sp0) = (uint16_t)(x1 + 1) >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(x1 + 1);
            RAM16_SET(0xA1C7, (uint16_t)((uint16_t)((((a_hi1 << 8) | value2) & 0xFF) - 0x80) << 2));
            uint16_t value3 = RAM16(0xA1C7);
            uint8_t a2 = 0x0C;
            uint8_t a_hi2 = (uint16_t)((uint16_t)((uint16_t)((((a_hi1 << 8) | value2) & 0xFF) - 0x80) << 3) + value3) >> 8;
            uint16_t x2 = (uint16_t)((uint16_t)((uint16_t)((((a_hi1 << 8) | value2) & 0xFF) - 0x80) << 3) + value3);
            uint16_t y2 = y1;
            for (;;) {
                uint8_t value4 = BUS8(c, 0xD2DC00 + x2);
                RAM8(0x9000 + y2) = value4;
                a2 = (uint8_t)(a2 - 1);
                a_hi2 = value4;
                x2 = (uint16_t)(x2 + 1);
                y2 = (uint16_t)(y2 + 1);
                if (!(a2 != 0)) break;
            }
            uint8_t value5 = RAM8(0x0000 + sp0 - 1);
            uint8_t value6 = RAM8(0x0000 + sp0);
            RAM8(0xA176)--;
            uint8_t a1_next = a2;
            uint8_t a_hi1_next = a_hi2;
            uint16_t x1_next = (value6 << 8) | value5;
            uint16_t y1_next = y2;
            bool carry1_next = (uint16_t)((uint16_t)((((a_hi1 << 8) | value2) & 0xFF) - 0x80) << 3) + value3 > 0xFFFF;
            bool zero1_next = RAM8(0xA176) == 0;
            bool overflow1_next = (((uint16_t)((uint16_t)((((a_hi1 << 8) | value2) & 0xFF) - 0x80) << 3) ^ (uint16_t)((uint16_t)((uint16_t)((((a_hi1 << 8) | value2) & 0xFF) - 0x80) << 3) + value3)) & (value3 ^ (uint16_t)((uint16_t)((uint16_t)((((a_hi1 << 8) | value2) & 0xFF) - 0x80) << 3) + value3)) & 0x8000) != 0;
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            zero1 = zero1_next;
            overflow1 = overflow1_next;
        } while (RAM8(0xA176) != 0);
        x_flag2 = 0;
        a6 = a1;
        a_hi6 = a_hi1;
        x6 = x1;
        y6 = y1;
        carry4 = carry1;
        zero4 = zero1;
        overflow4 = overflow1;
        data_bank2 = 0x7E;
        direct_page2 = 0;
    } else {
        uint8_t value7 = RAM8(0x1D05);
        bool x_flag;
        uint8_t a5;
        uint8_t a_hi5;
        uint16_t x5;
        uint16_t y5;
        bool carry3;
        bool zero3;
        bool overflow3;
        uint8_t data_bank;
        uint16_t direct_page;
        if (value7 == 5) {
            RAM8(0xA176) = 0x20;
            uint8_t a3 = 0x20;
            uint8_t a_hi3 = a_hi;
            uint16_t x3 = 0;
            uint16_t y3 = 0;
            bool carry2 = value7 >= 5;
            bool zero2 = 1;
            bool overflow2 = overflow;
            do {
                uint8_t value8 = RAM8(0xA1A4 + x3);
                RAM8(0x0000 + sp0) = (uint16_t)(x3 + 1) >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)(x3 + 1);
                RAM16_SET(0xA1C7, (uint16_t)((uint16_t)((((a_hi3 << 8) | value8) & 0xFF) - 0x80) << 2));
                uint16_t value9 = RAM16(0xA1C7);
                uint8_t a4 = 0x0C;
                uint8_t a_hi4 = (uint16_t)((uint16_t)((uint16_t)((((a_hi3 << 8) | value8) & 0xFF) - 0x80) << 3) + value9) >> 8;
                uint16_t x4 = (uint16_t)((uint16_t)((uint16_t)((((a_hi3 << 8) | value8) & 0xFF) - 0x80) << 3) + value9);
                uint16_t y4 = y3;
                for (;;) {
                    uint8_t value10 = BUS8(c, 0xD2DC00 + x4);
                    RAM8(0x9000 + y4) = value10;
                    a4 = (uint8_t)(a4 - 1);
                    a_hi4 = value10;
                    x4 = (uint16_t)(x4 + 1);
                    y4 = (uint16_t)(y4 + 1);
                    if (!(a4 != 0)) break;
                }
                uint8_t value11 = RAM8(0x0000 + sp0 - 1);
                uint8_t value12 = RAM8(0x0000 + sp0);
                RAM8(0xA176)--;
                uint8_t a3_next = a4;
                uint8_t a_hi3_next = a_hi4;
                uint16_t x3_next = (value12 << 8) | value11;
                uint16_t y3_next = y4;
                bool carry2_next = (uint16_t)((uint16_t)((((a_hi3 << 8) | value8) & 0xFF) - 0x80) << 3) + value9 > 0xFFFF;
                bool zero2_next = RAM8(0xA176) == 0;
                bool overflow2_next = (((uint16_t)((uint16_t)((((a_hi3 << 8) | value8) & 0xFF) - 0x80) << 3) ^ (uint16_t)((uint16_t)((uint16_t)((((a_hi3 << 8) | value8) & 0xFF) - 0x80) << 3) + value9)) & (value9 ^ (uint16_t)((uint16_t)((uint16_t)((((a_hi3 << 8) | value8) & 0xFF) - 0x80) << 3) + value9)) & 0x8000) != 0;
                a3 = a3_next;
                a_hi3 = a_hi3_next;
                x3 = x3_next;
                y3 = y3_next;
                carry2 = carry2_next;
                zero2 = zero2_next;
                overflow2 = overflow2_next;
            } while (RAM8(0xA176) != 0);
            x_flag = 0;
            a5 = a3;
            a_hi5 = a_hi3;
            x5 = x3;
            y5 = y3;
            carry3 = carry2;
            zero3 = zero2;
            overflow3 = overflow2;
            data_bank = 0x7E;
            direct_page = 0;
        } else {
            r->a = (a_hi << 8) | value7;
            r->c = value7 >= 5;
            r->z = value7 == 5;
            r->n = (uint8_t)(value7 - 5) & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1675, 0xC013CD); GUARD_JSR(c, sp_call, 0x1675); } /* advance_empty_dialogue_line_and_reset_render_origin */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            BUS8_SET(c, (db_ret << 0x10) + 0xA15D, 7);
            x_flag = x_ret;
            a5 = 7;
            a_hi5 = a_all >> 8;
            x5 = x_ret2;
            y5 = y_ret;
            carry3 = carry_ret;
            zero3 = 0;
            overflow3 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        x_flag2 = x_flag;
        a6 = a5;
        a_hi6 = a_hi5;
        x6 = x5;
        y6 = y5;
        carry4 = carry3;
        zero4 = zero3;
        overflow4 = overflow3;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->a = (a_hi6 << 8) | a6;
    r->x = x6;
    r->y = y6;
    r->c = carry4;
    r->z = zero4;
    r->v = overflow4;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01664, SOM_RTS, "gen", load_dialogue_glyph_rows_or_advance_empty_line, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 84, 42)

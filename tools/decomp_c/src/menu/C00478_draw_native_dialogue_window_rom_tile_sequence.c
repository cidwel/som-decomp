#include "som_c.h"

/* C00478 draw_native_dialogue_window_rom_tile_sequence   [class B, 88 bytes, 46 instructions]
 * Source: src/rom/draw_native_dialogue_window_rom_tile_sequence.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void draw_native_dialogue_window_rom_tile_sequence(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    uint8_t a_hi_04a6 = 0;
    uint16_t x_04a6 = 0;
    uint16_t y_04a6 = 0;
    uint16_t direct_page_04a6 = 0;
    uint8_t data_bank_04a6 = 0;
    uint8_t a_hi_04a62 = 0;
    uint8_t x_04a62 = 0;
    uint8_t y_04a62 = 0;
    uint16_t direct_page_04a62 = 0;
    uint8_t data_bank_04a62 = 0;
    RAM8(0xA16D) = RAM8(0xA186);
    uint16_t value2 = RAM16(0xA1A0);
    uint8_t value3 = BUS8(c, 0xC7716A + value2);
    RAM8(0xA16D) = ((uint8_t)(((uint8_t)(((uint8_t)(value3 << 1) << 1) | (value3 >> 7)) << 1) | ((uint8_t)(value3 << 1) >> 7)) & 3) ^ RAM8(0xA16D);
    uint8_t value5 = BUS8(c, 0xC77169 + value2);
    RAM8(0x0000 + sp0) = value5;
    if (RAM8(0xA15C) >= 5) {
        a_hi_04a6 = 0;
        x_04a6 = (uint16_t)(value2 - 2);
        y_04a6 = y;
        direct_page_04a6 = 0;
        data_bank_04a6 = 0x7E;
        goto shared_04A6;
    }
    a_hi_04a6 = 0;
    x_04a6 = (uint16_t)(value2 + 2);
    y_04a6 = y;
    direct_page_04a6 = 0;
    data_bank_04a6 = 0x7E;
    shared_04A6:;
    BUS16_SET(c, (data_bank_04a6 << 0x10) + 0xA1A0, x_04a6);
    BUS16_SET(c, (data_bank_04a6 << 0x10) + 0xA173, (uint16_t)(((a_hi_04a6 << 8) | RAM8(0x0000 + sp0)) - 0x10));
    uint16_t value8 = BUS16_RDP(c, (data_bank_04a6 << 0x10) + 0xA24E);
    uint16_t value9 = BUS16_RDP(c, (data_bank_04a6 << 0x10) + 0xA173);
    r->a = (uint16_t)((uint16_t)(((value8 & 0xFF) << 1 << 1 << 1) + value9) << 4);
    r->x = (uint16_t)((uint16_t)(((value8 & 0xFF) << 1 << 1 << 1) + value9) << 4);
    r->y = y_04a6;
    r->c = (uint16_t)((uint16_t)(((value8 & 0xFF) << 1 << 1 << 1) + value9) << 3) & 0x8000;
    r->z = (uint16_t)((uint16_t)(((value8 & 0xFF) << 1 << 1 << 1) + value9) << 4) == 0;
    r->n = (uint16_t)((uint16_t)(((value8 & 0xFF) << 1 << 1 << 1) + value9) << 4) & 0x8000;
    r->v = ((((value8 & 0xFF) << 1 << 1 << 1) ^ (uint16_t)(((value8 & 0xFF) << 1 << 1 << 1) + value9)) & (value9 ^ (uint16_t)(((value8 & 0xFF) << 1 << 1 << 1) + value9)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_04a6;
    r->dp = direct_page_04a6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x04C9, 0xC004D0); GUARD_JSR(c, sp_call, 0x04C9); } /* dispatch_dialogue_window_tile_orientation */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (m_ret) {
        uint8_t value10 = BUS8_RDP(c, (db_ret << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret << 0x10) + 0xA164, (uint8_t)(value10 - 1));
        if ((uint8_t)(value10 - 1) != 0) {
            uint8_t value11 = BUS8_RDP(c, (db_ret << 0x10) + 0xA186);
            BUS8_SET(c, (db_ret << 0x10) + 0xA16D, value11);
            if (x_ret) {
                uint8_t value12 = BUS8_RDP(c, (db_ret << 0x10) + 0xA1A0);
                uint8_t value13 = BUS8(c, 0xC7716A + value12);
                uint8_t value14 = BUS8_RDP(c, (db_ret << 0x10) + 0xA16D);
                BUS8_SET(c, (db_ret << 0x10) + 0xA16D, ((uint8_t)(((uint8_t)(((uint8_t)(value13 << 1) << 1) | (value13 >> 7)) << 1) | ((uint8_t)(value13 << 1) >> 7)) & 3) ^ value14);
                uint8_t value15 = BUS8(c, 0xC77169 + value12);
                RAM8(0x0000 + sp0) = value15;
                uint8_t value16 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
                if (value16 >= 5) {
                    a_hi_04a62 = 0;
                    x_04a62 = (uint8_t)(value12 - 2);
                    y_04a62 = (uint8_t)y_ret;
                    direct_page_04a62 = dp_ret;
                    data_bank_04a62 = db_ret;
                    goto shared_04A6_1;
                }
                a_hi_04a62 = 0;
                x_04a62 = (uint8_t)(value12 + 2);
                y_04a62 = (uint8_t)y_ret;
                direct_page_04a62 = dp_ret;
                data_bank_04a62 = db_ret;
                goto shared_04A6_1;
            } else {
                uint16_t value17 = BUS16_RDP(c, (db_ret << 0x10) + 0xA1A0);
                uint8_t value18 = BUS8(c, 0xC7716A + value17);
                uint8_t value19 = BUS8_RDP(c, (db_ret << 0x10) + 0xA16D);
                BUS8_SET(c, (db_ret << 0x10) + 0xA16D, ((uint8_t)(((uint8_t)(((uint8_t)(value18 << 1) << 1) | (value18 >> 7)) << 1) | ((uint8_t)(value18 << 1) >> 7)) & 3) ^ value19);
                uint8_t value20 = BUS8(c, 0xC77169 + value17);
                RAM8(0x0000 + sp0) = value20;
                uint8_t value21 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15C);
                if (value21 >= 5) {
                    a_hi_04a6 = 0;
                    x_04a6 = (uint16_t)(value17 - 2);
                    y_04a6 = y_ret;
                    direct_page_04a6 = dp_ret;
                    data_bank_04a6 = db_ret;
                    goto shared_04A6;
                }
                a_hi_04a6 = 0;
                x_04a6 = (uint16_t)(value17 + 2);
                y_04a6 = y_ret;
                direct_page_04a6 = dp_ret;
                data_bank_04a6 = db_ret;
                goto shared_04A6;
            }
        }
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value22 = BUS16_RDP(c, (db_ret << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret << 0x10) + 0xA164, (uint16_t)(value22 - 1));
        if ((uint16_t)(value22 - 1) != 0) {
            uint16_t value23 = BUS16_RDP(c, (db_ret << 0x10) + 0xA186);
            BUS16_SET(c, (db_ret << 0x10) + 0xA16D, value23);
            if (x_ret) {
                uint8_t value24 = BUS8_RDP(c, (db_ret << 0x10) + 0xA1A0);
                uint16_t value25 = BUS16(c, 0xC7716A + value24);
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                uint16_t value26 = BUS16_RDP(c, (db_ret << 0x10) + 0xA1A0);
                uint16_t value27 = BUS16(c, 0xC7716A + value26);
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        }
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    shared_04A6_1:;
    BUS8_SET(c, (data_bank_04a62 << 0x10) + 0xA1A0, x_04a62);
    BUS16_SET(c, (data_bank_04a62 << 0x10) + 0xA173, (uint16_t)(((a_hi_04a62 << 8) | RAM8(0x0000 + sp0)) - 0x10));
    uint16_t value29 = BUS16_RDP(c, (data_bank_04a62 << 0x10) + 0xA24E);
    uint16_t value30 = BUS16_RDP(c, (data_bank_04a62 << 0x10) + 0xA173);
    r->a = (uint16_t)((uint16_t)(((value29 & 0xFF) << 1 << 1 << 1) + value30) << 4);
    r->x = (uint8_t)((uint16_t)(((value29 & 0xFF) << 1 << 1 << 1) + value30) << 4);
    r->y = y_04a62;
    r->c = (uint16_t)((uint16_t)(((value29 & 0xFF) << 1 << 1 << 1) + value30) << 3) & 0x8000;
    r->z = (uint8_t)((uint16_t)(((value29 & 0xFF) << 1 << 1 << 1) + value30) << 4) == 0;
    r->n = (uint8_t)((uint16_t)(((value29 & 0xFF) << 1 << 1 << 1) + value30) << 4) & 0x80;
    r->v = ((((value29 & 0xFF) << 1 << 1 << 1) ^ (uint16_t)(((value29 & 0xFF) << 1 << 1 << 1) + value30)) & (value30 ^ (uint16_t)(((value29 & 0xFF) << 1 << 1 << 1) + value30)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_04a62;
    r->dp = direct_page_04a62;
    { const uint16_t sp_call = r->sp; JSR(c, 0x04C9, 0xC004D0); GUARD_JSR(c, sp_call, 0x04C9); } /* dispatch_dialogue_window_tile_orientation */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t y_ret2 = r->y;
    if (m_ret2) {
        uint8_t value31 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA164);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA164, (uint8_t)(value31 - 1));
        if ((uint8_t)(value31 - 1) != 0) {
            uint8_t value32 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA186);
            BUS8_SET(c, (db_ret2 << 0x10) + 0xA16D, value32);
            if (x_ret3) {
                uint8_t value33 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA1A0);
                uint8_t value34 = BUS8(c, 0xC7716A + value33);
                uint8_t value35 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA16D);
                BUS8_SET(c, (db_ret2 << 0x10) + 0xA16D, ((uint8_t)(((uint8_t)(((uint8_t)(value34 << 1) << 1) | (value34 >> 7)) << 1) | ((uint8_t)(value34 << 1) >> 7)) & 3) ^ value35);
                uint8_t value36 = BUS8(c, 0xC77169 + value33);
                RAM8(0x0000 + sp0) = value36;
                uint8_t value37 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA15C);
                if (value37 >= 5) {
                    a_hi_04a62 = 0;
                    x_04a62 = (uint8_t)(value33 - 2);
                    y_04a62 = (uint8_t)y_ret2;
                    direct_page_04a62 = dp_ret2;
                    data_bank_04a62 = db_ret2;
                    goto shared_04A6_1;
                }
                a_hi_04a62 = 0;
                x_04a62 = (uint8_t)(value33 + 2);
                y_04a62 = (uint8_t)y_ret2;
                direct_page_04a62 = dp_ret2;
                data_bank_04a62 = db_ret2;
                goto shared_04A6_1;
            } else {
                uint16_t value38 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA1A0);
                uint8_t value39 = BUS8(c, 0xC7716A + value38);
                uint8_t value40 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA16D);
                BUS8_SET(c, (db_ret2 << 0x10) + 0xA16D, ((uint8_t)(((uint8_t)(((uint8_t)(value39 << 1) << 1) | (value39 >> 7)) << 1) | ((uint8_t)(value39 << 1) >> 7)) & 3) ^ value40);
                uint8_t value41 = BUS8(c, 0xC77169 + value38);
                RAM8(0x0000 + sp0) = value41;
                uint8_t value42 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA15C);
                if (value42 >= 5) {
                    a_hi_04a6 = 0;
                    x_04a6 = (uint16_t)(value38 - 2);
                    y_04a6 = y_ret2;
                    direct_page_04a6 = dp_ret2;
                    data_bank_04a6 = db_ret2;
                    goto shared_04A6;
                }
                a_hi_04a6 = 0;
                x_04a6 = (uint16_t)(value38 + 2);
                y_04a6 = y_ret2;
                direct_page_04a6 = dp_ret2;
                data_bank_04a6 = db_ret2;
                goto shared_04A6;
            }
        }
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value43 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA164);
        BUS16_RMW_SET(c, (db_ret2 << 0x10) + 0xA164, (uint16_t)(value43 - 1));
        if ((uint16_t)(value43 - 1) != 0) {
            uint16_t value44 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA186);
            BUS16_SET(c, (db_ret2 << 0x10) + 0xA16D, value44);
            if (x_ret3) {
                uint8_t value45 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA1A0);
                uint16_t value46 = BUS16(c, 0xC7716A + value45);
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                uint16_t value47 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA1A0);
                uint16_t value48 = BUS16(c, 0xC7716A + value47);
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        }
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC00478, SOM_RTS, "gen", draw_native_dialogue_window_rom_tile_sequence, 0, L_B | L_Y | L_V, 1, 1, 0, 88, 46)

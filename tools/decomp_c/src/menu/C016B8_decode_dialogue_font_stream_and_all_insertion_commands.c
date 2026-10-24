#include "som_c.h"

static void sub_C017C7(SomCtx *c);
static void sub_C017C7_v2(SomCtx *c);
static void sub_C017C7_v3(SomCtx *c);
static void sub_C017C7_v4(SomCtx *c);

/* C016B8 decode_dialogue_font_stream_and_all_insertion_commands   [class C, 638 bytes, 292 instructions]
 * Source: src/rom/decode_dialogue_font_stream_and_all_insertion_commands.s
 * Documented in docs/event-dialogue-font-parser.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCZV.
 */
static void decode_dialogue_font_stream_and_all_insertion_commands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint16_t x1 = 0;
    for (;;) {
        BUS8_SET(c, (db << 0x10) + 0xA1A4 + x1, 0x80);
        x1 = (uint16_t)(x1 + 1);
        if (!(x1 != 0x21)) break;
    }
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xA16A);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xA181);
    BUS8_SET(c, (db << 0x10) + 0xA1CA, (uint8_t)(value - value2));
    BUS8_SET(c, (db << 0x10) + 0xA1CE, 0);
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x1D03);
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x1D01);
    RAM8(0x0000 + sp0) = db;
    RAM8(0x0000 + sp0 - 1) = value3;
    uint8_t a_hi1 = a_hi;
    uint16_t x2 = 0;
    uint16_t y1 = value4;
    bool carry1 = value >= value2;
    bool overflow1 = ((value ^ value2) & (value ^ (uint8_t)(value - value2)) & 0x80) != 0;
    uint8_t data_bank = value3;
    uint16_t direct_page = 0;
    uint8_t width_pass = 0;
    for (;;) {
        if (width_pass == 0) {
            if ((RAM8(0x1D00) & 0x80) == 0) {
                uint8_t value6 = BUS8_RDP(c, (data_bank << 0x10) + y1);
                if (value6 != 0x7F) {
                    if (value6 >= 0xD3) {
                        RAM8(0x0000 + sp0 - 1) = x2 >> 8;
                        RAM8(0x0000 + sp0 - 2) = (uint8_t)x2;
                        uint16_t value7 = BUS16(c, 0xC77299 + (uint16_t)((uint16_t)((((a_hi1 << 8) | value6) & 0xFF) - 0xC3) << 1));
                        RAM16_SET(0xA173, value7);
                        r->a = value7;
                        r->x = x2;
                        r->y = (uint16_t)(y1 + 1);
                        r->c = (uint16_t)((((a_hi1 << 8) | value6) & 0xFF) - 0xC3) & 0x8000;
                        r->v = (((((a_hi1 << 8) | value6) & 0xFF) ^ 0xC3) & ((((a_hi1 << 8) | value6) & 0xFF) ^ (uint16_t)((((a_hi1 << 8) | value6) & 0xFF) - 0xC3)) & 0x8000) != 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = data_bank;
                        r->dp = 0;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x1726, sub_C017C7, sp_in, 2); GUARD_JSR(c, sp_call, 0x1726); }
                        r->sp += 1;
                        uint16_t a_all = r->a;
                        r->a = (a_all >> 8 << 8) | RAM8(0xA174);
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                        r->sp += 1;
                        uint16_t dp_ret2 = r->dp;
                        uint8_t db_ret2 = r->db;
                        uint16_t a_all2 = r->a;
                        uint16_t x_ret2 = r->x;
                        uint16_t y_ret2 = r->y;
                        bool carry_ret2 = r->c;
                        bool overflow_ret2 = r->v;
                        a_hi1 = a_all2 >> 8;
                        x2 = x_ret2;
                        y1 = y_ret2;
                        carry1 = carry_ret2;
                        overflow1 = overflow_ret2;
                        data_bank = db_ret2;
                        direct_page = dp_ret2;
                        continue;
                    }
                    if (value6 >= 0x80) {
                        r->a = (a_hi1 << 8) | value6;
                        r->x = x2;
                        r->y = (uint16_t)(y1 + 1);
                        r->c = value6 >= 0x80;
                        r->v = overflow1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = data_bank;
                        r->dp = 0;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                        r->sp += 1;
                        uint16_t dp_ret3 = r->dp;
                        uint8_t db_ret3 = r->db;
                        uint16_t a_all3 = r->a;
                        uint16_t x_ret3 = r->x;
                        uint16_t y_ret3 = r->y;
                        bool carry_ret3 = r->c;
                        bool overflow_ret3 = r->v;
                        a_hi1 = a_all3 >> 8;
                        x2 = x_ret3;
                        y1 = y_ret3;
                        carry1 = carry_ret3;
                        overflow1 = overflow_ret3;
                        data_bank = db_ret3;
                        direct_page = dp_ret3;
                        continue;
                    }
                    if (value6 < 0x5F) {
                        RAM8(0x0000 + sp0 - 1) = value6;
                        RAM8(0xA212) |= 1;
                        if (value6 < 0x53) {
                            uint8_t value10 = RAM8(0x1D00);
                            if ((value10 & 8) == 0) {
                                uint8_t value11 = RAM8(0x0000 + sp0);
                                BUS16_SET(c, (value11 << 0x10) + 0x1D01, (uint16_t)(y1 + 0));
                                BUS8_SET(c, (value11 << 0x10) + 0xA1D0, 0);
                                r->a = (uint16_t)(y1 + 0);
                                r->x = x2;
                                r->y = (uint16_t)(y1 + 0);
                                r->c = value6 >= 0x53;
                                r->z = (uint16_t)(y1 + 0) == 0;
                                r->v = ((value6 ^ 0x53) & (value6 ^ (uint8_t)(value6 - 0x53)) & 0x80) != 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = value11;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            RAM8(0x1D00) = value10 & 0xF7;
                            uint8_t value12 = RAM8(0xA1D3);
                            RAM8(0x1D03) = value12;
                            RAM8(0x0000 + sp0 - 1) = value12;
                            uint16_t value13 = RAM16(0xA1D1);
                            RAM16_SET(0x1D01, (uint16_t)(value13 + 1));
                            a_hi1 = (uint16_t)(value13 + 1) >> 8;
                            y1 = (uint16_t)(value13 + 1);
                            carry1 = value6 >= 0x53;
                            overflow1 = ((value6 ^ 0x53) & (value6 ^ (uint8_t)(value6 - 0x53)) & 0x80) != 0;
                            data_bank = value12;
                            direct_page = 0;
                            continue;
                        }
                        if ((uint8_t)(value6 - 0x53) >= 0x0A) {
                            uint8_t value14 = RAM8(0x1D00);
                            if ((value14 & 8) == 0) {
                                uint8_t value15 = RAM8(0x0000 + sp0);
                                BUS16_SET(c, (value15 << 0x10) + 0x1D01, (uint16_t)(y1 + 0));
                                BUS8_SET(c, (value15 << 0x10) + 0xA1D0, 0);
                                r->a = (uint16_t)(y1 + 0);
                                r->x = x2;
                                r->y = (uint16_t)(y1 + 0);
                                r->c = (uint8_t)(value6 - 0x53) >= 0x0A;
                                r->z = (uint16_t)(y1 + 0) == 0;
                                r->v = ((value6 ^ 0x53) & (value6 ^ (uint8_t)(value6 - 0x53)) & 0x80) != 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = value15;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            RAM8(0x1D00) = value14 & 0xF7;
                            uint8_t value16 = RAM8(0xA1D3);
                            RAM8(0x1D03) = value16;
                            RAM8(0x0000 + sp0 - 1) = value16;
                            uint16_t value17 = RAM16(0xA1D1);
                            RAM16_SET(0x1D01, (uint16_t)(value17 + 1));
                            a_hi1 = (uint16_t)(value17 + 1) >> 8;
                            y1 = (uint16_t)(value17 + 1);
                            carry1 = (uint8_t)(value6 - 0x53) >= 0x0A;
                            overflow1 = ((value6 ^ 0x53) & (value6 ^ (uint8_t)(value6 - 0x53)) & 0x80) != 0;
                            data_bank = value16;
                            direct_page = 0;
                            continue;
                        }
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)(value6 - 0x53);
                        if ((uint8_t)(value6 - 0x53) >= 5) {
                            RAM8(0x0000 + sp0 - 1) = a_hi1;
                            RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi1 << 8) | (uint8_t)(value6 - 0x53));
                            RAM16_SET(0xA173, x2);
                            r->a = (((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1;
                            r->x = (((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1;
                            r->y = (uint16_t)(y1 + 1);
                            r->c = ((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF & 0x8000;
                            r->z = (((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1 == 0;
                            r->n = (((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1 & 0x8000;
                            r->v = ((value6 ^ 0x53) & (value6 ^ (uint8_t)(value6 - 0x53)) & 0x80) != 0;
                            r->mf = 0;
                            r->xf = 0;
                            r->db = data_bank;
                            r->dp = 0;
                            r->sp -= 1;
                            { const uint16_t sp_call = r->sp;
                            JSR(c, 0x1765, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A22 + ((((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1)))); GUARD_JSR(c, sp_call, 0x1765);
                            }
                            r->sp += 1;
                            uint16_t dp_ret4 = r->dp;
                            uint8_t db_ret4 = r->db;
                            bool x_ret4 = r->xf;
                            uint16_t y_ret4 = r->y;
                            bool carry_ret4 = r->c;
                            bool overflow_ret4 = r->v;
                            uint16_t value18 = RAM16(0xA173);
                            if (x_ret4) {
                                a_hi1 = value18 >> 8;
                                x2 = (uint8_t)value18;
                                y1 = (uint8_t)y_ret4;
                                carry1 = carry_ret4;
                                overflow1 = overflow_ret4;
                                data_bank = db_ret4;
                                direct_page = dp_ret4;
                                width_pass = 2;
                                continue;
                            } else {
                                a_hi1 = value18 >> 8;
                                x2 = value18;
                                y1 = y_ret4;
                                carry1 = carry_ret4;
                                overflow1 = overflow_ret4;
                                data_bank = db_ret4;
                                direct_page = dp_ret4;
                                continue;
                            }
                        }
                        RAM8(0x1D00) |= 8;
                        RAM8(0x0000 + sp0 - 1) = a_hi1;
                        RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi1 << 8) | (uint8_t)(value6 - 0x53));
                        RAM16_SET(0xA173, x2);
                        r->a = (((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1;
                        r->x = (((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1;
                        r->y = (uint16_t)(y1 + 1);
                        r->c = ((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF & 0x8000;
                        r->z = (((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1 == 0;
                        r->n = (((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1 & 0x8000;
                        r->v = ((value6 ^ 0x53) & (value6 ^ (uint8_t)(value6 - 0x53)) & 0x80) != 0;
                        r->mf = 0;
                        r->xf = 0;
                        r->db = data_bank;
                        r->dp = 0;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp;
                        JSR(c, 0x1765, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A22 + ((((a_hi1 << 8) | (uint8_t)(value6 - 0x53)) & 0xFF) << 1)))); GUARD_JSR(c, sp_call, 0x1765);
                        }
                        r->sp += 1;
                        uint16_t dp_ret5 = r->dp;
                        uint8_t db_ret5 = r->db;
                        bool x_ret6 = r->xf;
                        uint16_t y_ret5 = r->y;
                        bool carry_ret5 = r->c;
                        bool overflow_ret5 = r->v;
                        uint16_t value20 = RAM16(0xA173);
                        if (x_ret6) {
                            a_hi1 = value20 >> 8;
                            x2 = (uint8_t)value20;
                            y1 = (uint8_t)y_ret5;
                            carry1 = carry_ret5;
                            overflow1 = overflow_ret5;
                            data_bank = db_ret5;
                            direct_page = dp_ret5;
                            width_pass = 2;
                            continue;
                        } else {
                            a_hi1 = value20 >> 8;
                            x2 = value20;
                            y1 = y_ret5;
                            carry1 = carry_ret5;
                            overflow1 = overflow_ret5;
                            data_bank = db_ret5;
                            direct_page = dp_ret5;
                            continue;
                        }
                    }
                    RAM8(0x0000 + sp0 - 1) = x2 >> 8;
                    RAM8(0x0000 + sp0 - 2) = (uint8_t)x2;
                    uint16_t value21 = BUS16(c, 0xC77299 + (uint16_t)((uint16_t)((((a_hi1 << 8) | value6) & 0xFF) - 0x60) << 1));
                    RAM16_SET(0xA173, value21);
                    r->a = value21;
                    r->x = x2;
                    r->y = (uint16_t)(y1 + 1);
                    r->c = (uint16_t)((((a_hi1 << 8) | value6) & 0xFF) - 0x60) & 0x8000;
                    r->v = (((((a_hi1 << 8) | value6) & 0xFF) ^ 0x60) & ((((a_hi1 << 8) | value6) & 0xFF) ^ (uint16_t)((((a_hi1 << 8) | value6) & 0xFF) - 0x60)) & 0x8000) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = data_bank;
                    r->dp = 0;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x1726, sub_C017C7, sp_in, 2); GUARD_JSR(c, sp_call, 0x1726); }
                    r->sp += 1;
                    uint16_t a_all6 = r->a;
                    r->a = (a_all6 >> 8 << 8) | RAM8(0xA174);
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                    r->sp += 1;
                    uint16_t dp_ret7 = r->dp;
                    uint8_t db_ret7 = r->db;
                    uint16_t a_all7 = r->a;
                    uint16_t x_ret9 = r->x;
                    uint16_t y_ret7 = r->y;
                    bool carry_ret7 = r->c;
                    bool overflow_ret7 = r->v;
                    a_hi1 = a_all7 >> 8;
                    x2 = x_ret9;
                    y1 = y_ret7;
                    carry1 = carry_ret7;
                    overflow1 = overflow_ret7;
                    data_bank = db_ret7;
                    direct_page = dp_ret7;
                    continue;
                }
                RAM8(0xA1CE) |= 0x80;
                uint8_t value24 = RAM8(0x0000 + sp0);
                BUS16_SET(c, (value24 << 0x10) + 0x1D01, (uint16_t)(y1 + 1));
                BUS8_SET(c, (value24 << 0x10) + 0xA1D0, 0);
                r->a = (uint16_t)(y1 + 1);
                r->x = x2;
                r->y = (uint16_t)(y1 + 1);
                r->c = value6 >= 0x7F;
                r->z = (uint16_t)(y1 + 1) == 0;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = value24;
                r->dp = 0;
                RETURN_RTS(c);
            }
            RAM8(0xA1CE) |= 0x80;
            uint8_t value26 = RAM8(0x0000 + sp0);
            BUS16_SET(c, (value26 << 0x10) + 0x1D01, y1);
            BUS8_SET(c, (value26 << 0x10) + 0xA1D0, 0);
            r->a = y1;
            r->x = x2;
            r->y = y1;
            r->c = carry1;
            r->z = y1 == 0;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = value26;
            r->dp = 0;
            RETURN_RTS(c);
        } else if (width_pass == 1) {
            if ((RAM8(0x1D00) & 0x80) == 0) {
                uint8_t value28 = BUS8_RDP(c, (data_bank << 0x10) + (uint8_t)y1);
                if (value28 != 0x7F) {
                    if (value28 >= 0xD3) {
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)x2;
                        uint16_t value29 = BUS16(c, 0xC77299 + (uint8_t)((uint16_t)((((a_hi1 << 8) | value28) & 0xFF) - 0xC3) << 1));
                        RAM16_SET(0xA173, value29);
                        r->a = value29;
                        r->x = (uint8_t)x2;
                        r->y = (uint8_t)((uint8_t)y1 + 1);
                        r->c = (uint16_t)((((a_hi1 << 8) | value28) & 0xFF) - 0xC3) & 0x8000;
                        r->v = (((((a_hi1 << 8) | value28) & 0xFF) ^ 0xC3) & ((((a_hi1 << 8) | value28) & 0xFF) ^ (uint16_t)((((a_hi1 << 8) | value28) & 0xFF) - 0xC3)) & 0x8000) != 0;
                        r->mf = 1;
                        r->xf = 1;
                        r->db = data_bank;
                        r->dp = direct_page;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x1726, sub_C017C7_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0x1726); }
                        r->sp += 1;
                        uint16_t a_all8 = r->a;
                        r->a = (a_all8 >> 8 << 8) | RAM8(0xA174);
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                        r->sp += 1;
                        uint16_t dp_ret9 = r->dp;
                        uint8_t db_ret9 = r->db;
                        uint16_t a_all9 = r->a;
                        uint8_t x_ret11 = r->x;
                        uint8_t y_ret9 = r->y;
                        bool carry_ret9 = r->c;
                        bool overflow_ret9 = r->v;
                        a_hi1 = a_all9 >> 8;
                        x2 = x_ret11;
                        y1 = y_ret9;
                        carry1 = carry_ret9;
                        overflow1 = overflow_ret9;
                        data_bank = db_ret9;
                        direct_page = dp_ret9;
                        continue;
                    }
                    if (value28 >= 0x80) {
                        r->a = (a_hi1 << 8) | value28;
                        r->x = (uint8_t)x2;
                        r->y = (uint8_t)((uint8_t)y1 + 1);
                        r->c = value28 >= 0x80;
                        r->v = overflow1;
                        r->mf = 1;
                        r->xf = 1;
                        r->db = data_bank;
                        r->dp = direct_page;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                        r->sp += 1;
                        uint16_t dp_ret10 = r->dp;
                        uint8_t db_ret10 = r->db;
                        uint16_t a_all10 = r->a;
                        uint8_t x_ret12 = r->x;
                        uint8_t y_ret10 = r->y;
                        bool carry_ret10 = r->c;
                        bool overflow_ret10 = r->v;
                        a_hi1 = a_all10 >> 8;
                        x2 = x_ret12;
                        y1 = y_ret10;
                        carry1 = carry_ret10;
                        overflow1 = overflow_ret10;
                        data_bank = db_ret10;
                        direct_page = dp_ret10;
                        continue;
                    }
                    if (value28 < 0x5F) {
                        RAM8(0x0000 + sp0 - 1) = value28;
                        RAM8(0xA212) |= 1;
                        if (value28 < 0x53) {
                            uint8_t value32 = RAM8(0x1D00);
                            if ((value32 & 8) == 0) {
                                uint8_t value33 = RAM8(0x0000 + sp0);
                                BUS16_SET(c, (value33 << 0x10) + 0x1D01, (uint8_t)((uint8_t)y1 + 0));
                                BUS8_SET(c, (value33 << 0x10) + 0xA1D0, 0);
                                r->a = (uint8_t)((uint8_t)y1 + 0);
                                r->x = (uint8_t)x2;
                                r->y = (uint8_t)((uint8_t)y1 + 0);
                                r->c = value28 >= 0x53;
                                r->z = (uint8_t)((uint8_t)y1 + 0) == 0;
                                r->v = ((value28 ^ 0x53) & (value28 ^ (uint8_t)(value28 - 0x53)) & 0x80) != 0;
                                r->mf = 1;
                                r->xf = 1;
                                r->db = value33;
                                r->dp = direct_page;
                                RETURN_RTS(c);
                            }
                            RAM8(0x1D00) = value32 & 0xF7;
                            uint8_t value34 = RAM8(0xA1D3);
                            RAM8(0x1D03) = value34;
                            RAM8(0x0000 + sp0 - 1) = value34;
                            uint16_t value35 = RAM16(0xA1D1);
                            RAM16_SET(0x1D01, (uint16_t)(value35 + 1));
                            a_hi1 = (uint16_t)(value35 + 1) >> 8;
                            x2 = (uint8_t)x2;
                            y1 = (uint8_t)(value35 + 1);
                            carry1 = value28 >= 0x53;
                            overflow1 = ((value28 ^ 0x53) & (value28 ^ (uint8_t)(value28 - 0x53)) & 0x80) != 0;
                            data_bank = value34;
                            continue;
                        }
                        if ((uint8_t)(value28 - 0x53) >= 0x0A) {
                            uint8_t value36 = RAM8(0x1D00);
                            if ((value36 & 8) == 0) {
                                uint8_t value37 = RAM8(0x0000 + sp0);
                                BUS16_SET(c, (value37 << 0x10) + 0x1D01, (uint8_t)((uint8_t)y1 + 0));
                                BUS8_SET(c, (value37 << 0x10) + 0xA1D0, 0);
                                r->a = (uint8_t)((uint8_t)y1 + 0);
                                r->x = (uint8_t)x2;
                                r->y = (uint8_t)((uint8_t)y1 + 0);
                                r->c = (uint8_t)(value28 - 0x53) >= 0x0A;
                                r->z = (uint8_t)((uint8_t)y1 + 0) == 0;
                                r->v = ((value28 ^ 0x53) & (value28 ^ (uint8_t)(value28 - 0x53)) & 0x80) != 0;
                                r->mf = 1;
                                r->xf = 1;
                                r->db = value37;
                                r->dp = direct_page;
                                RETURN_RTS(c);
                            }
                            RAM8(0x1D00) = value36 & 0xF7;
                            uint8_t value38 = RAM8(0xA1D3);
                            RAM8(0x1D03) = value38;
                            RAM8(0x0000 + sp0 - 1) = value38;
                            uint16_t value39 = RAM16(0xA1D1);
                            RAM16_SET(0x1D01, (uint16_t)(value39 + 1));
                            a_hi1 = (uint16_t)(value39 + 1) >> 8;
                            x2 = (uint8_t)x2;
                            y1 = (uint8_t)(value39 + 1);
                            carry1 = (uint8_t)(value28 - 0x53) >= 0x0A;
                            overflow1 = ((value28 ^ 0x53) & (value28 ^ (uint8_t)(value28 - 0x53)) & 0x80) != 0;
                            data_bank = value38;
                            continue;
                        }
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)(value28 - 0x53);
                        if ((uint8_t)(value28 - 0x53) >= 5) {
                            RAM8(0x0000 + sp0 - 1) = a_hi1;
                            RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi1 << 8) | (uint8_t)(value28 - 0x53));
                            RAM16_SET(0xA173, (uint8_t)x2);
                            r->a = (((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1;
                            r->x = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1);
                            r->y = (uint8_t)((uint8_t)y1 + 1);
                            r->c = ((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF & 0x8000;
                            r->z = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1) == 0;
                            r->n = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1) & 0x80;
                            r->v = ((value28 ^ 0x53) & (value28 ^ (uint8_t)(value28 - 0x53)) & 0x80) != 0;
                            r->mf = 0;
                            r->xf = 1;
                            r->db = data_bank;
                            r->dp = direct_page;
                            r->sp -= 1;
                            { const uint16_t sp_call = r->sp;
                            JSR(c, 0x1765, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A22 + ((uint8_t)((((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1))))); GUARD_JSR(c, sp_call, 0x1765);
                            }
                            r->sp += 1;
                            uint16_t dp_ret11 = r->dp;
                            uint8_t db_ret11 = r->db;
                            bool x_ret13 = r->xf;
                            uint16_t y_ret11 = r->y;
                            bool carry_ret11 = r->c;
                            bool overflow_ret11 = r->v;
                            uint16_t value40 = RAM16(0xA173);
                            if (x_ret13) {
                                a_hi1 = value40 >> 8;
                                x2 = (uint8_t)value40;
                                y1 = (uint8_t)y_ret11;
                                carry1 = carry_ret11;
                                overflow1 = overflow_ret11;
                                data_bank = db_ret11;
                                direct_page = dp_ret11;
                                continue;
                            } else {
                                a_hi1 = value40 >> 8;
                                x2 = value40;
                                y1 = y_ret11;
                                carry1 = carry_ret11;
                                overflow1 = overflow_ret11;
                                data_bank = db_ret11;
                                direct_page = dp_ret11;
                                width_pass = 3;
                                continue;
                            }
                        }
                        RAM8(0x1D00) |= 8;
                        RAM8(0x0000 + sp0 - 1) = a_hi1;
                        RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi1 << 8) | (uint8_t)(value28 - 0x53));
                        RAM16_SET(0xA173, (uint8_t)x2);
                        r->a = (((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1;
                        r->x = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1);
                        r->y = (uint8_t)((uint8_t)y1 + 1);
                        r->c = ((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF & 0x8000;
                        r->z = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1) == 0;
                        r->n = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1) & 0x80;
                        r->v = ((value28 ^ 0x53) & (value28 ^ (uint8_t)(value28 - 0x53)) & 0x80) != 0;
                        r->mf = 0;
                        r->xf = 1;
                        r->db = data_bank;
                        r->dp = direct_page;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp;
                        JSR(c, 0x1765, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A22 + ((uint8_t)((((a_hi1 << 8) | (uint8_t)(value28 - 0x53)) & 0xFF) << 1))))); GUARD_JSR(c, sp_call, 0x1765);
                        }
                        r->sp += 1;
                        uint16_t dp_ret12 = r->dp;
                        uint8_t db_ret12 = r->db;
                        bool x_ret15 = r->xf;
                        uint16_t y_ret12 = r->y;
                        bool carry_ret12 = r->c;
                        bool overflow_ret12 = r->v;
                        uint16_t value42 = RAM16(0xA173);
                        if (x_ret15) {
                            a_hi1 = value42 >> 8;
                            x2 = (uint8_t)value42;
                            y1 = (uint8_t)y_ret12;
                            carry1 = carry_ret12;
                            overflow1 = overflow_ret12;
                            data_bank = db_ret12;
                            direct_page = dp_ret12;
                            continue;
                        } else {
                            a_hi1 = value42 >> 8;
                            x2 = value42;
                            y1 = y_ret12;
                            carry1 = carry_ret12;
                            overflow1 = overflow_ret12;
                            data_bank = db_ret12;
                            direct_page = dp_ret12;
                            width_pass = 3;
                            continue;
                        }
                    }
                    RAM8(0x0000 + sp0 - 1) = (uint8_t)x2;
                    uint16_t value43 = BUS16(c, 0xC77299 + (uint8_t)((uint16_t)((((a_hi1 << 8) | value28) & 0xFF) - 0x60) << 1));
                    RAM16_SET(0xA173, value43);
                    r->a = value43;
                    r->x = (uint8_t)x2;
                    r->y = (uint8_t)((uint8_t)y1 + 1);
                    r->c = (uint16_t)((((a_hi1 << 8) | value28) & 0xFF) - 0x60) & 0x8000;
                    r->v = (((((a_hi1 << 8) | value28) & 0xFF) ^ 0x60) & ((((a_hi1 << 8) | value28) & 0xFF) ^ (uint16_t)((((a_hi1 << 8) | value28) & 0xFF) - 0x60)) & 0x8000) != 0;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = data_bank;
                    r->dp = direct_page;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x1726, sub_C017C7_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0x1726); }
                    r->sp += 1;
                    uint16_t a_all13 = r->a;
                    r->a = (a_all13 >> 8 << 8) | RAM8(0xA174);
                    r->mf = 1;
                    r->xf = 1;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                    r->sp += 1;
                    uint16_t dp_ret14 = r->dp;
                    uint8_t db_ret14 = r->db;
                    uint16_t a_all14 = r->a;
                    uint8_t x_ret18 = r->x;
                    uint8_t y_ret14 = r->y;
                    bool carry_ret14 = r->c;
                    bool overflow_ret14 = r->v;
                    a_hi1 = a_all14 >> 8;
                    x2 = x_ret18;
                    y1 = y_ret14;
                    carry1 = carry_ret14;
                    overflow1 = overflow_ret14;
                    data_bank = db_ret14;
                    direct_page = dp_ret14;
                    continue;
                }
                RAM8(0xA1CE) |= 0x80;
                uint8_t value46 = RAM8(0x0000 + sp0);
                BUS16_SET(c, (value46 << 0x10) + 0x1D01, (uint8_t)((uint8_t)y1 + 1));
                BUS8_SET(c, (value46 << 0x10) + 0xA1D0, 0);
                r->a = (uint8_t)((uint8_t)y1 + 1);
                r->x = (uint8_t)x2;
                r->y = (uint8_t)((uint8_t)y1 + 1);
                r->c = value28 >= 0x7F;
                r->z = (uint8_t)((uint8_t)y1 + 1) == 0;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 1;
                r->db = value46;
                r->dp = direct_page;
                RETURN_RTS(c);
            }
            RAM8(0xA1CE) |= 0x80;
            uint8_t value48 = RAM8(0x0000 + sp0);
            BUS16_SET(c, (value48 << 0x10) + 0x1D01, (uint8_t)y1);
            BUS8_SET(c, (value48 << 0x10) + 0xA1D0, 0);
            r->a = (uint8_t)y1;
            r->x = (uint8_t)x2;
            r->y = (uint8_t)y1;
            r->c = carry1;
            r->z = (uint8_t)y1 == 0;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 1;
            r->db = value48;
            r->dp = direct_page;
            RETURN_RTS(c);
        } else if (width_pass == 2) {
            if ((RAM8(0x1D00) & 0x80) == 0) {
                uint8_t value50 = BUS8_RDP(c, (data_bank << 0x10) + (uint8_t)y1);
                if (value50 != 0x7F) {
                    if (value50 >= 0xD3) {
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)x2;
                        uint16_t value51 = BUS16(c, 0xC77299 + (uint8_t)((uint16_t)((((a_hi1 << 8) | value50) & 0xFF) - 0xC3) << 1));
                        RAM16_SET(0xA173, value51);
                        r->a = value51;
                        r->x = (uint8_t)x2;
                        r->y = (uint8_t)((uint8_t)y1 + 1);
                        r->c = (uint16_t)((((a_hi1 << 8) | value50) & 0xFF) - 0xC3) & 0x8000;
                        r->v = (((((a_hi1 << 8) | value50) & 0xFF) ^ 0xC3) & ((((a_hi1 << 8) | value50) & 0xFF) ^ (uint16_t)((((a_hi1 << 8) | value50) & 0xFF) - 0xC3)) & 0x8000) != 0;
                        r->mf = 1;
                        r->xf = 1;
                        r->db = data_bank;
                        r->dp = 0;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x1726, sub_C017C7_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0x1726); }
                        r->sp += 1;
                        uint16_t a_all15 = r->a;
                        r->a = (a_all15 >> 8 << 8) | RAM8(0xA174);
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                        r->sp += 1;
                        uint16_t dp_ret16 = r->dp;
                        uint8_t db_ret16 = r->db;
                        uint16_t a_all16 = r->a;
                        uint8_t x_ret20 = r->x;
                        uint8_t y_ret16 = r->y;
                        bool carry_ret16 = r->c;
                        bool overflow_ret16 = r->v;
                        a_hi1 = a_all16 >> 8;
                        x2 = x_ret20;
                        y1 = y_ret16;
                        carry1 = carry_ret16;
                        overflow1 = overflow_ret16;
                        data_bank = db_ret16;
                        direct_page = dp_ret16;
                        continue;
                    }
                    if (value50 >= 0x80) {
                        r->a = (a_hi1 << 8) | value50;
                        r->x = (uint8_t)x2;
                        r->y = (uint8_t)((uint8_t)y1 + 1);
                        r->c = value50 >= 0x80;
                        r->v = overflow1;
                        r->mf = 1;
                        r->xf = 1;
                        r->db = data_bank;
                        r->dp = 0;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                        r->sp += 1;
                        uint16_t dp_ret17 = r->dp;
                        uint8_t db_ret17 = r->db;
                        uint16_t a_all17 = r->a;
                        uint8_t x_ret21 = r->x;
                        uint8_t y_ret17 = r->y;
                        bool carry_ret17 = r->c;
                        bool overflow_ret17 = r->v;
                        a_hi1 = a_all17 >> 8;
                        x2 = x_ret21;
                        y1 = y_ret17;
                        carry1 = carry_ret17;
                        overflow1 = overflow_ret17;
                        data_bank = db_ret17;
                        direct_page = dp_ret17;
                        continue;
                    }
                    if (value50 < 0x5F) {
                        RAM8(0x0000 + sp0 - 1) = value50;
                        RAM8(0xA212) |= 1;
                        if (value50 < 0x53) {
                            uint8_t value54 = RAM8(0x1D00);
                            if ((value54 & 8) == 0) {
                                uint8_t value55 = RAM8(0x0000 + sp0);
                                BUS16_SET(c, (value55 << 0x10) + 0x1D01, (uint8_t)((uint8_t)y1 + 0));
                                BUS8_SET(c, (value55 << 0x10) + 0xA1D0, 0);
                                r->a = (uint8_t)((uint8_t)y1 + 0);
                                r->x = (uint8_t)x2;
                                r->y = (uint8_t)((uint8_t)y1 + 0);
                                r->c = value50 >= 0x53;
                                r->z = (uint8_t)((uint8_t)y1 + 0) == 0;
                                r->v = ((value50 ^ 0x53) & (value50 ^ (uint8_t)(value50 - 0x53)) & 0x80) != 0;
                                r->mf = 1;
                                r->xf = 1;
                                r->db = value55;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            RAM8(0x1D00) = value54 & 0xF7;
                            uint8_t value56 = RAM8(0xA1D3);
                            RAM8(0x1D03) = value56;
                            RAM8(0x0000 + sp0 - 1) = value56;
                            uint16_t value57 = RAM16(0xA1D1);
                            RAM16_SET(0x1D01, (uint16_t)(value57 + 1));
                            a_hi1 = (uint16_t)(value57 + 1) >> 8;
                            x2 = (uint8_t)x2;
                            y1 = (uint8_t)(value57 + 1);
                            carry1 = value50 >= 0x53;
                            overflow1 = ((value50 ^ 0x53) & (value50 ^ (uint8_t)(value50 - 0x53)) & 0x80) != 0;
                            data_bank = value56;
                            direct_page = 0;
                            continue;
                        }
                        if ((uint8_t)(value50 - 0x53) >= 0x0A) {
                            uint8_t value58 = RAM8(0x1D00);
                            if ((value58 & 8) == 0) {
                                uint8_t value59 = RAM8(0x0000 + sp0);
                                BUS16_SET(c, (value59 << 0x10) + 0x1D01, (uint8_t)((uint8_t)y1 + 0));
                                BUS8_SET(c, (value59 << 0x10) + 0xA1D0, 0);
                                r->a = (uint8_t)((uint8_t)y1 + 0);
                                r->x = (uint8_t)x2;
                                r->y = (uint8_t)((uint8_t)y1 + 0);
                                r->c = (uint8_t)(value50 - 0x53) >= 0x0A;
                                r->z = (uint8_t)((uint8_t)y1 + 0) == 0;
                                r->v = ((value50 ^ 0x53) & (value50 ^ (uint8_t)(value50 - 0x53)) & 0x80) != 0;
                                r->mf = 1;
                                r->xf = 1;
                                r->db = value59;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            RAM8(0x1D00) = value58 & 0xF7;
                            uint8_t value60 = RAM8(0xA1D3);
                            RAM8(0x1D03) = value60;
                            RAM8(0x0000 + sp0 - 1) = value60;
                            uint16_t value61 = RAM16(0xA1D1);
                            RAM16_SET(0x1D01, (uint16_t)(value61 + 1));
                            a_hi1 = (uint16_t)(value61 + 1) >> 8;
                            x2 = (uint8_t)x2;
                            y1 = (uint8_t)(value61 + 1);
                            carry1 = (uint8_t)(value50 - 0x53) >= 0x0A;
                            overflow1 = ((value50 ^ 0x53) & (value50 ^ (uint8_t)(value50 - 0x53)) & 0x80) != 0;
                            data_bank = value60;
                            direct_page = 0;
                            continue;
                        }
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)(value50 - 0x53);
                        if ((uint8_t)(value50 - 0x53) >= 5) {
                            RAM8(0x0000 + sp0 - 1) = a_hi1;
                            RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi1 << 8) | (uint8_t)(value50 - 0x53));
                            RAM16_SET(0xA173, (uint8_t)x2);
                            r->a = (((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1;
                            r->x = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1);
                            r->y = (uint8_t)((uint8_t)y1 + 1);
                            r->c = ((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF & 0x8000;
                            r->z = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1) == 0;
                            r->n = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1) & 0x80;
                            r->v = ((value50 ^ 0x53) & (value50 ^ (uint8_t)(value50 - 0x53)) & 0x80) != 0;
                            r->mf = 0;
                            r->xf = 1;
                            r->db = data_bank;
                            r->dp = 0;
                            r->sp -= 1;
                            { const uint16_t sp_call = r->sp;
                            JSR(c, 0x1765, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A22 + ((uint8_t)((((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1))))); GUARD_JSR(c, sp_call, 0x1765);
                            }
                            r->sp += 1;
                            uint16_t dp_ret18 = r->dp;
                            uint8_t db_ret18 = r->db;
                            bool x_ret22 = r->xf;
                            uint16_t y_ret18 = r->y;
                            bool carry_ret18 = r->c;
                            bool overflow_ret18 = r->v;
                            uint16_t value62 = RAM16(0xA173);
                            if (x_ret22) {
                                a_hi1 = value62 >> 8;
                                x2 = (uint8_t)value62;
                                y1 = (uint8_t)y_ret18;
                                carry1 = carry_ret18;
                                overflow1 = overflow_ret18;
                                data_bank = db_ret18;
                                direct_page = dp_ret18;
                                continue;
                            } else {
                                a_hi1 = value62 >> 8;
                                x2 = value62;
                                y1 = y_ret18;
                                carry1 = carry_ret18;
                                overflow1 = overflow_ret18;
                                data_bank = db_ret18;
                                direct_page = dp_ret18;
                                width_pass = 0;
                                continue;
                            }
                        }
                        RAM8(0x1D00) |= 8;
                        RAM8(0x0000 + sp0 - 1) = a_hi1;
                        RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi1 << 8) | (uint8_t)(value50 - 0x53));
                        RAM16_SET(0xA173, (uint8_t)x2);
                        r->a = (((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1;
                        r->x = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1);
                        r->y = (uint8_t)((uint8_t)y1 + 1);
                        r->c = ((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF & 0x8000;
                        r->z = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1) == 0;
                        r->n = (uint8_t)((((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1) & 0x80;
                        r->v = ((value50 ^ 0x53) & (value50 ^ (uint8_t)(value50 - 0x53)) & 0x80) != 0;
                        r->mf = 0;
                        r->xf = 1;
                        r->db = data_bank;
                        r->dp = 0;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp;
                        JSR(c, 0x1765, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A22 + ((uint8_t)((((a_hi1 << 8) | (uint8_t)(value50 - 0x53)) & 0xFF) << 1))))); GUARD_JSR(c, sp_call, 0x1765);
                        }
                        r->sp += 1;
                        uint16_t dp_ret19 = r->dp;
                        uint8_t db_ret19 = r->db;
                        bool x_ret24 = r->xf;
                        uint16_t y_ret19 = r->y;
                        bool carry_ret19 = r->c;
                        bool overflow_ret19 = r->v;
                        uint16_t value64 = RAM16(0xA173);
                        if (x_ret24) {
                            a_hi1 = value64 >> 8;
                            x2 = (uint8_t)value64;
                            y1 = (uint8_t)y_ret19;
                            carry1 = carry_ret19;
                            overflow1 = overflow_ret19;
                            data_bank = db_ret19;
                            direct_page = dp_ret19;
                            continue;
                        } else {
                            a_hi1 = value64 >> 8;
                            x2 = value64;
                            y1 = y_ret19;
                            carry1 = carry_ret19;
                            overflow1 = overflow_ret19;
                            data_bank = db_ret19;
                            direct_page = dp_ret19;
                            width_pass = 0;
                            continue;
                        }
                    }
                    RAM8(0x0000 + sp0 - 1) = (uint8_t)x2;
                    uint16_t value65 = BUS16(c, 0xC77299 + (uint8_t)((uint16_t)((((a_hi1 << 8) | value50) & 0xFF) - 0x60) << 1));
                    RAM16_SET(0xA173, value65);
                    r->a = value65;
                    r->x = (uint8_t)x2;
                    r->y = (uint8_t)((uint8_t)y1 + 1);
                    r->c = (uint16_t)((((a_hi1 << 8) | value50) & 0xFF) - 0x60) & 0x8000;
                    r->v = (((((a_hi1 << 8) | value50) & 0xFF) ^ 0x60) & ((((a_hi1 << 8) | value50) & 0xFF) ^ (uint16_t)((((a_hi1 << 8) | value50) & 0xFF) - 0x60)) & 0x8000) != 0;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = data_bank;
                    r->dp = 0;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x1726, sub_C017C7_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0x1726); }
                    r->sp += 1;
                    uint16_t a_all20 = r->a;
                    r->a = (a_all20 >> 8 << 8) | RAM8(0xA174);
                    r->mf = 1;
                    r->xf = 1;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                    r->sp += 1;
                    uint16_t dp_ret21 = r->dp;
                    uint8_t db_ret21 = r->db;
                    uint16_t a_all21 = r->a;
                    uint8_t x_ret27 = r->x;
                    uint8_t y_ret21 = r->y;
                    bool carry_ret21 = r->c;
                    bool overflow_ret21 = r->v;
                    a_hi1 = a_all21 >> 8;
                    x2 = x_ret27;
                    y1 = y_ret21;
                    carry1 = carry_ret21;
                    overflow1 = overflow_ret21;
                    data_bank = db_ret21;
                    direct_page = dp_ret21;
                    continue;
                }
                RAM8(0xA1CE) |= 0x80;
                uint8_t value68 = RAM8(0x0000 + sp0);
                BUS16_SET(c, (value68 << 0x10) + 0x1D01, (uint8_t)((uint8_t)y1 + 1));
                BUS8_SET(c, (value68 << 0x10) + 0xA1D0, 0);
                r->a = (uint8_t)((uint8_t)y1 + 1);
                r->x = (uint8_t)x2;
                r->y = (uint8_t)((uint8_t)y1 + 1);
                r->c = value50 >= 0x7F;
                r->z = (uint8_t)((uint8_t)y1 + 1) == 0;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 1;
                r->db = value68;
                r->dp = 0;
                RETURN_RTS(c);
            }
            RAM8(0xA1CE) |= 0x80;
            uint8_t value70 = RAM8(0x0000 + sp0);
            BUS16_SET(c, (value70 << 0x10) + 0x1D01, (uint8_t)y1);
            BUS8_SET(c, (value70 << 0x10) + 0xA1D0, 0);
            r->a = (uint8_t)y1;
            r->x = (uint8_t)x2;
            r->y = (uint8_t)y1;
            r->c = carry1;
            r->z = (uint8_t)y1 == 0;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 1;
            r->db = value70;
            r->dp = 0;
            RETURN_RTS(c);
        } else {
            if ((RAM8(0x1D00) & 0x80) == 0) {
                uint8_t value72 = BUS8_RDP(c, (data_bank << 0x10) + y1);
                if (value72 != 0x7F) {
                    if (value72 >= 0xD3) {
                        RAM8(0x0000 + sp0 - 1) = x2 >> 8;
                        RAM8(0x0000 + sp0 - 2) = (uint8_t)x2;
                        uint16_t value73 = BUS16(c, 0xC77299 + (uint16_t)((uint16_t)((((a_hi1 << 8) | value72) & 0xFF) - 0xC3) << 1));
                        RAM16_SET(0xA173, value73);
                        r->a = value73;
                        r->x = x2;
                        r->y = (uint16_t)(y1 + 1);
                        r->c = (uint16_t)((((a_hi1 << 8) | value72) & 0xFF) - 0xC3) & 0x8000;
                        r->v = (((((a_hi1 << 8) | value72) & 0xFF) ^ 0xC3) & ((((a_hi1 << 8) | value72) & 0xFF) ^ (uint16_t)((((a_hi1 << 8) | value72) & 0xFF) - 0xC3)) & 0x8000) != 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = data_bank;
                        r->dp = direct_page;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x1726, sub_C017C7_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x1726); }
                        r->sp += 1;
                        uint16_t a_all22 = r->a;
                        r->a = (a_all22 >> 8 << 8) | RAM8(0xA174);
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                        r->sp += 1;
                        uint16_t dp_ret23 = r->dp;
                        uint8_t db_ret23 = r->db;
                        uint16_t a_all23 = r->a;
                        uint16_t x_ret29 = r->x;
                        uint16_t y_ret23 = r->y;
                        bool carry_ret23 = r->c;
                        bool overflow_ret23 = r->v;
                        a_hi1 = a_all23 >> 8;
                        x2 = x_ret29;
                        y1 = y_ret23;
                        carry1 = carry_ret23;
                        overflow1 = overflow_ret23;
                        data_bank = db_ret23;
                        direct_page = dp_ret23;
                        continue;
                    }
                    if (value72 >= 0x80) {
                        r->a = (a_hi1 << 8) | value72;
                        r->x = x2;
                        r->y = (uint16_t)(y1 + 1);
                        r->c = value72 >= 0x80;
                        r->v = overflow1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = data_bank;
                        r->dp = direct_page;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                        r->sp += 1;
                        uint16_t dp_ret24 = r->dp;
                        uint8_t db_ret24 = r->db;
                        uint16_t a_all24 = r->a;
                        uint16_t x_ret30 = r->x;
                        uint16_t y_ret24 = r->y;
                        bool carry_ret24 = r->c;
                        bool overflow_ret24 = r->v;
                        a_hi1 = a_all24 >> 8;
                        x2 = x_ret30;
                        y1 = y_ret24;
                        carry1 = carry_ret24;
                        overflow1 = overflow_ret24;
                        data_bank = db_ret24;
                        direct_page = dp_ret24;
                        continue;
                    }
                    if (value72 < 0x5F) {
                        RAM8(0x0000 + sp0 - 1) = value72;
                        RAM8(0xA212) |= 1;
                        if (value72 < 0x53) {
                            uint8_t value76 = RAM8(0x1D00);
                            if ((value76 & 8) == 0) {
                                uint8_t value77 = RAM8(0x0000 + sp0);
                                BUS16_SET(c, (value77 << 0x10) + 0x1D01, (uint16_t)(y1 + 0));
                                BUS8_SET(c, (value77 << 0x10) + 0xA1D0, 0);
                                r->a = (uint16_t)(y1 + 0);
                                r->x = x2;
                                r->y = (uint16_t)(y1 + 0);
                                r->c = value72 >= 0x53;
                                r->z = (uint16_t)(y1 + 0) == 0;
                                r->v = ((value72 ^ 0x53) & (value72 ^ (uint8_t)(value72 - 0x53)) & 0x80) != 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = value77;
                                r->dp = direct_page;
                                RETURN_RTS(c);
                            }
                            RAM8(0x1D00) = value76 & 0xF7;
                            uint8_t value78 = RAM8(0xA1D3);
                            RAM8(0x1D03) = value78;
                            RAM8(0x0000 + sp0 - 1) = value78;
                            uint16_t value79 = RAM16(0xA1D1);
                            RAM16_SET(0x1D01, (uint16_t)(value79 + 1));
                            a_hi1 = (uint16_t)(value79 + 1) >> 8;
                            y1 = (uint16_t)(value79 + 1);
                            carry1 = value72 >= 0x53;
                            overflow1 = ((value72 ^ 0x53) & (value72 ^ (uint8_t)(value72 - 0x53)) & 0x80) != 0;
                            data_bank = value78;
                            continue;
                        }
                        if ((uint8_t)(value72 - 0x53) >= 0x0A) {
                            uint8_t value80 = RAM8(0x1D00);
                            if ((value80 & 8) == 0) {
                                uint8_t value81 = RAM8(0x0000 + sp0);
                                BUS16_SET(c, (value81 << 0x10) + 0x1D01, (uint16_t)(y1 + 0));
                                BUS8_SET(c, (value81 << 0x10) + 0xA1D0, 0);
                                r->a = (uint16_t)(y1 + 0);
                                r->x = x2;
                                r->y = (uint16_t)(y1 + 0);
                                r->c = (uint8_t)(value72 - 0x53) >= 0x0A;
                                r->z = (uint16_t)(y1 + 0) == 0;
                                r->v = ((value72 ^ 0x53) & (value72 ^ (uint8_t)(value72 - 0x53)) & 0x80) != 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = value81;
                                r->dp = direct_page;
                                RETURN_RTS(c);
                            }
                            RAM8(0x1D00) = value80 & 0xF7;
                            uint8_t value82 = RAM8(0xA1D3);
                            RAM8(0x1D03) = value82;
                            RAM8(0x0000 + sp0 - 1) = value82;
                            uint16_t value83 = RAM16(0xA1D1);
                            RAM16_SET(0x1D01, (uint16_t)(value83 + 1));
                            a_hi1 = (uint16_t)(value83 + 1) >> 8;
                            y1 = (uint16_t)(value83 + 1);
                            carry1 = (uint8_t)(value72 - 0x53) >= 0x0A;
                            overflow1 = ((value72 ^ 0x53) & (value72 ^ (uint8_t)(value72 - 0x53)) & 0x80) != 0;
                            data_bank = value82;
                            continue;
                        }
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)(value72 - 0x53);
                        if ((uint8_t)(value72 - 0x53) >= 5) {
                            RAM8(0x0000 + sp0 - 1) = a_hi1;
                            RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi1 << 8) | (uint8_t)(value72 - 0x53));
                            RAM16_SET(0xA173, x2);
                            r->a = (((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1;
                            r->x = (((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1;
                            r->y = (uint16_t)(y1 + 1);
                            r->c = ((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF & 0x8000;
                            r->z = (((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1 == 0;
                            r->n = (((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1 & 0x8000;
                            r->v = ((value72 ^ 0x53) & (value72 ^ (uint8_t)(value72 - 0x53)) & 0x80) != 0;
                            r->mf = 0;
                            r->xf = 0;
                            r->db = data_bank;
                            r->dp = direct_page;
                            r->sp -= 1;
                            { const uint16_t sp_call = r->sp;
                            JSR(c, 0x1765, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A22 + ((((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1)))); GUARD_JSR(c, sp_call, 0x1765);
                            }
                            r->sp += 1;
                            uint16_t dp_ret25 = r->dp;
                            uint8_t db_ret25 = r->db;
                            bool x_ret31 = r->xf;
                            uint16_t y_ret25 = r->y;
                            bool carry_ret25 = r->c;
                            bool overflow_ret25 = r->v;
                            uint16_t value84 = RAM16(0xA173);
                            if (x_ret31) {
                                a_hi1 = value84 >> 8;
                                x2 = (uint8_t)value84;
                                y1 = (uint8_t)y_ret25;
                                carry1 = carry_ret25;
                                overflow1 = overflow_ret25;
                                data_bank = db_ret25;
                                direct_page = dp_ret25;
                                width_pass = 1;
                                continue;
                            } else {
                                a_hi1 = value84 >> 8;
                                x2 = value84;
                                y1 = y_ret25;
                                carry1 = carry_ret25;
                                overflow1 = overflow_ret25;
                                data_bank = db_ret25;
                                direct_page = dp_ret25;
                                continue;
                            }
                        }
                        RAM8(0x1D00) |= 8;
                        RAM8(0x0000 + sp0 - 1) = a_hi1;
                        RAM8(0x0000 + sp0 - 2) = (uint8_t)((a_hi1 << 8) | (uint8_t)(value72 - 0x53));
                        RAM16_SET(0xA173, x2);
                        r->a = (((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1;
                        r->x = (((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1;
                        r->y = (uint16_t)(y1 + 1);
                        r->c = ((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF & 0x8000;
                        r->z = (((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1 == 0;
                        r->n = (((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1 & 0x8000;
                        r->v = ((value72 ^ 0x53) & (value72 ^ (uint8_t)(value72 - 0x53)) & 0x80) != 0;
                        r->mf = 0;
                        r->xf = 0;
                        r->db = data_bank;
                        r->dp = direct_page;
                        r->sp -= 1;
                        { const uint16_t sp_call = r->sp;
                        JSR(c, 0x1765, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1A22 + ((((a_hi1 << 8) | (uint8_t)(value72 - 0x53)) & 0xFF) << 1)))); GUARD_JSR(c, sp_call, 0x1765);
                        }
                        r->sp += 1;
                        uint16_t dp_ret26 = r->dp;
                        uint8_t db_ret26 = r->db;
                        bool x_ret33 = r->xf;
                        uint16_t y_ret26 = r->y;
                        bool carry_ret26 = r->c;
                        bool overflow_ret26 = r->v;
                        uint16_t value86 = RAM16(0xA173);
                        if (x_ret33) {
                            a_hi1 = value86 >> 8;
                            x2 = (uint8_t)value86;
                            y1 = (uint8_t)y_ret26;
                            carry1 = carry_ret26;
                            overflow1 = overflow_ret26;
                            data_bank = db_ret26;
                            direct_page = dp_ret26;
                            width_pass = 1;
                            continue;
                        } else {
                            a_hi1 = value86 >> 8;
                            x2 = value86;
                            y1 = y_ret26;
                            carry1 = carry_ret26;
                            overflow1 = overflow_ret26;
                            data_bank = db_ret26;
                            direct_page = dp_ret26;
                            continue;
                        }
                    }
                    RAM8(0x0000 + sp0 - 1) = x2 >> 8;
                    RAM8(0x0000 + sp0 - 2) = (uint8_t)x2;
                    uint16_t value87 = BUS16(c, 0xC77299 + (uint16_t)((uint16_t)((((a_hi1 << 8) | value72) & 0xFF) - 0x60) << 1));
                    RAM16_SET(0xA173, value87);
                    r->a = value87;
                    r->x = x2;
                    r->y = (uint16_t)(y1 + 1);
                    r->c = (uint16_t)((((a_hi1 << 8) | value72) & 0xFF) - 0x60) & 0x8000;
                    r->v = (((((a_hi1 << 8) | value72) & 0xFF) ^ 0x60) & ((((a_hi1 << 8) | value72) & 0xFF) ^ (uint16_t)((((a_hi1 << 8) | value72) & 0xFF) - 0x60)) & 0x8000) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = data_bank;
                    r->dp = direct_page;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x1726, sub_C017C7_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x1726); }
                    r->sp += 1;
                    uint16_t a_all27 = r->a;
                    r->a = (a_all27 >> 8 << 8) | RAM8(0xA174);
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x172D, sub_C017C7_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x172D); }
                    r->sp += 1;
                    uint16_t dp_ret28 = r->dp;
                    uint8_t db_ret28 = r->db;
                    uint16_t a_all28 = r->a;
                    uint16_t x_ret36 = r->x;
                    uint16_t y_ret28 = r->y;
                    bool carry_ret28 = r->c;
                    bool overflow_ret28 = r->v;
                    a_hi1 = a_all28 >> 8;
                    x2 = x_ret36;
                    y1 = y_ret28;
                    carry1 = carry_ret28;
                    overflow1 = overflow_ret28;
                    data_bank = db_ret28;
                    direct_page = dp_ret28;
                    continue;
                }
                RAM8(0xA1CE) |= 0x80;
                uint8_t value90 = RAM8(0x0000 + sp0);
                BUS16_SET(c, (value90 << 0x10) + 0x1D01, (uint16_t)(y1 + 1));
                BUS8_SET(c, (value90 << 0x10) + 0xA1D0, 0);
                r->a = (uint16_t)(y1 + 1);
                r->x = x2;
                r->y = (uint16_t)(y1 + 1);
                r->c = value72 >= 0x7F;
                r->z = (uint16_t)(y1 + 1) == 0;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = value90;
                r->dp = direct_page;
                RETURN_RTS(c);
            }
            RAM8(0xA1CE) |= 0x80;
            uint8_t value92 = RAM8(0x0000 + sp0);
            BUS16_SET(c, (value92 << 0x10) + 0x1D01, y1);
            BUS8_SET(c, (value92 << 0x10) + 0xA1D0, 0);
            r->a = y1;
            r->x = x2;
            r->y = y1;
            r->c = carry1;
            r->z = y1 == 0;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = value92;
            r->dp = direct_page;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC016B8, SOM_RTS, "gen", decode_dialogue_font_stream_and_all_insertion_commands, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 37, 1, 0, 638, 292)

/* C017C7 sub_C017C7   [class A, 102 bytes, 46 instructions]
 * Source: src/rom/decode_dialogue_font_stream_and_all_insertion_commands.s
 * Subroutine of decode_dialogue_font_stream_and_all_insertion_commands, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void sub_C017C7(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 3;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0xA1A4 + x) = a;
    RAM8(0xA1CE)++;
    uint8_t value = RAM8(0xA1CA);
    RAM8(0xA1CA)--;
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    if ((uint8_t)(value - 1) != 0) {
        SET_A8(r, (uint8_t)(value - 1));
        r->x = (uint16_t)(x + 1);
        r->z = (uint8_t)(value - 1) == 0;
        r->n = (uint8_t)(value - 1) & 0x80;
        r->db = value2;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x1D00);
    uint8_t a_hi1;
    uint16_t y1;
    if ((value3 & 8) == 0) {
        a_hi1 = a_hi;
        y1 = y;
    } else {
        RAM8(0x1D00) = (value3 | 1) & 0xF7;
        uint16_t value4 = RAM16(0xA1D1);
        RAM8(0x1D03) = RAM8(0xA1D3);
        a_hi1 = (uint16_t)(value4 + 1) >> 8;
        y1 = (uint16_t)(value4 + 1);
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    if (RAM8(0xA1C6) == 0) {
        RAM8(0xA1C5) = 0;
        RAM8(0xA1C6) = 1;
        RAM8(0xA1CE) |= 0x80;
    }
    uint8_t value10 = RAM8(0x0000 + sp0);
    BUS16_SET(c, (value10 << 0x10) + 0x1D01, y1);
    BUS8_SET(c, (value10 << 0x10) + 0xA1D0, 0);
    r->a = y1;
    r->x = (value7 << 8) | value6;
    r->y = y1;
    r->z = y1 == 0;
    r->n = y1 & 0x8000;
    r->db = value10;
    r->sp += 3;
    c->unwound = 1;   /* the subroutine returns from its caller */
    RETURN_RTS(c);
}

/* C017C7 sub_C017C7_v2   [class A, 102 bytes, 46 instructions]
 * Source: src/rom/decode_dialogue_font_stream_and_all_insertion_commands.s
 * Subroutine of decode_dialogue_font_stream_and_all_insertion_commands, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void sub_C017C7_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp + 3;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0xA1A4 + x) = a;
    RAM8(0xA1CE)++;
    uint8_t value = RAM8(0xA1CA);
    RAM8(0xA1CA)--;
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    if ((uint8_t)(value - 1) != 0) {
        SET_A8(r, (uint8_t)(value - 1));
        r->x = (uint16_t)(x + 1);
        r->z = (uint8_t)(value - 1) == 0;
        r->n = (uint8_t)(value - 1) & 0x80;
        r->db = value2;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x1D00);
    uint8_t a_hi1;
    uint16_t y1;
    if ((value3 & 8) == 0) {
        a_hi1 = a_hi;
        y1 = y;
    } else {
        RAM8(0x1D00) = (value3 | 1) & 0xF7;
        uint16_t value4 = RAM16(0xA1D1);
        RAM8(0x1D03) = RAM8(0xA1D3);
        a_hi1 = (uint16_t)(value4 + 1) >> 8;
        y1 = (uint16_t)(value4 + 1);
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    if (RAM8(0xA1C6) == 0) {
        RAM8(0xA1C5) = 0;
        RAM8(0xA1C6) = 1;
        RAM8(0xA1CE) |= 0x80;
    }
    uint8_t value10 = RAM8(0x0000 + sp0);
    BUS16_SET(c, (value10 << 0x10) + 0x1D01, y1);
    BUS8_SET(c, (value10 << 0x10) + 0xA1D0, 0);
    r->a = y1;
    r->x = (value7 << 8) | value6;
    r->y = y1;
    r->z = y1 == 0;
    r->n = y1 & 0x8000;
    r->db = value10;
    r->sp += 3;
    c->unwound = 1;   /* the subroutine returns from its caller */
    RETURN_RTS(c);
}

/* C017C7 sub_C017C7_v3   [class A, 102 bytes, 46 instructions]
 * Source: src/rom/decode_dialogue_font_stream_and_all_insertion_commands.s
 * Subroutine of decode_dialogue_font_stream_and_all_insertion_commands, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void sub_C017C7_v3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t sp0 = r->sp + 2;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0 - 2) = db;
    RAM8(0x0000 + sp0 - 3) = a;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM8(0xA1A4 + x) = a;
    RAM8(0xA1CE)++;
    uint8_t value = RAM8(0xA1CA);
    RAM8(0xA1CA)--;
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    if ((uint8_t)(value - 1) != 0) {
        SET_A8(r, (uint8_t)(value - 1));
        r->x = (uint8_t)(x + 1);
        r->z = (uint8_t)(value - 1) == 0;
        r->n = (uint8_t)(value - 1) & 0x80;
        r->db = value2;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x1D00);
    uint8_t a_hi1;
    uint8_t y1;
    if ((value3 & 8) == 0) {
        a_hi1 = a_hi;
        y1 = y;
    } else {
        RAM8(0x1D00) = (value3 | 1) & 0xF7;
        uint16_t value4 = RAM16(0xA1D1);
        RAM8(0x1D03) = RAM8(0xA1D3);
        a_hi1 = (uint16_t)(value4 + 1) >> 8;
        y1 = (uint8_t)(value4 + 1);
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    if (RAM8(0xA1C6) == 0) {
        RAM8(0xA1C5) = 0;
        RAM8(0xA1C6) = 1;
        RAM8(0xA1CE) |= 0x80;
    }
    uint8_t value9 = RAM8(0x0000 + sp0);
    BUS16_SET(c, (value9 << 0x10) + 0x1D01, y1);
    BUS8_SET(c, (value9 << 0x10) + 0xA1D0, 0);
    r->a = y1;
    r->x = value6;
    r->y = y1;
    r->z = y1 == 0;
    r->n = y1 & 0x8000;
    r->db = value9;
    r->sp += 2;
    c->unwound = 1;   /* the subroutine returns from its caller */
    RETURN_RTS(c);
}

/* C017C7 sub_C017C7_v4   [class A, 102 bytes, 46 instructions]
 * Source: src/rom/decode_dialogue_font_stream_and_all_insertion_commands.s
 * Subroutine of decode_dialogue_font_stream_and_all_insertion_commands, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void sub_C017C7_v4(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0 - 2) = db;
    RAM8(0x0000 + sp0 - 3) = a;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM8(0xA1A4 + x) = a;
    RAM8(0xA1CE)++;
    uint8_t value = RAM8(0xA1CA);
    RAM8(0xA1CA)--;
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    if ((uint8_t)(value - 1) != 0) {
        SET_A8(r, (uint8_t)(value - 1));
        r->x = (uint8_t)(x + 1);
        r->z = (uint8_t)(value - 1) == 0;
        r->n = (uint8_t)(value - 1) & 0x80;
        r->db = value2;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x1D00);
    uint8_t a_hi1;
    uint8_t y1;
    if ((value3 & 8) == 0) {
        a_hi1 = a_hi;
        y1 = y;
    } else {
        RAM8(0x1D00) = (value3 | 1) & 0xF7;
        uint16_t value4 = RAM16(0xA1D1);
        RAM8(0x1D03) = RAM8(0xA1D3);
        a_hi1 = (uint16_t)(value4 + 1) >> 8;
        y1 = (uint8_t)(value4 + 1);
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    if (RAM8(0xA1C6) == 0) {
        RAM8(0xA1C5) = 0;
        RAM8(0xA1C6) = 1;
        RAM8(0xA1CE) |= 0x80;
    }
    uint8_t value9 = RAM8(0x0000 + sp0);
    BUS16_SET(c, (value9 << 0x10) + 0x1D01, y1);
    BUS8_SET(c, (value9 << 0x10) + 0xA1D0, 0);
    r->a = y1;
    r->x = value6;
    r->y = y1;
    r->z = y1 == 0;
    r->n = y1 & 0x8000;
    r->db = value9;
    r->sp += 2;
    c->unwound = 1;   /* the subroutine returns from its caller */
    RETURN_RTS(c);
}

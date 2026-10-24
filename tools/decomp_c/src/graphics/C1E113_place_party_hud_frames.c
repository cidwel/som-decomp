#include "som_c.h"

static void write_one_party_hud_frame(SomCtx *c);
static void write_one_party_hud_frame_v2(SomCtx *c);

/* C1E113 place_party_hud_frames   [class C, 425 bytes, 167 instructions]
 * Source: src/rom/place_party_hud_frames.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void place_party_hud_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_e126 = 0;
    uint16_t x_e126 = 0;
    uint16_t y_e126 = 0;
    bool carry_e126 = 0;
    bool overflow_e126 = 0;
    uint8_t a_hi_e12e = 0;
    uint16_t x_e12e = 0;
    uint16_t y_e12e = 0;
    bool carry_e12e = 0;
    bool overflow_e12e = 0;
    uint8_t event_flag_bytes = RAM8(EVENT_FLAG_BYTES);
    if (event_flag_bytes != 0) {
        uint8_t value = RAM8(0xE000);
        if (value & 0x80) {
            a_hi_e126 = a >> 8;
            x_e126 = x;
            y_e126 = y;
            carry_e126 = carry;
            overflow_e126 = overflow;
            goto shared_E126;
        }
        if (value != 0) {
            uint8_t value2 = RAM8(0xE200);
            uint8_t a14;
            uint8_t a_hi14;
            uint16_t x14;
            uint16_t y14;
            uint8_t data_bank14;
            uint16_t direct_page14;
            if (value2 & 0x80) {
                uint8_t value3 = RAM8(0xE400);
                uint8_t a5;
                uint8_t a_hi5;
                uint16_t x5;
                uint16_t y5;
                uint8_t data_bank5;
                uint16_t direct_page5;
                if (value3 & 0x80) {
                    RAM8(0x0A55) = 0x4D;
                    a5 = RAM8(0xE02C);
                    a_hi5 = a >> 8;
                    x5 = 0x5B2B;
                    y5 = 0x24;
                    data_bank5 = 0;
                    direct_page5 = 0;
                } else {
                    uint8_t a4;
                    uint8_t a_hi4;
                    uint16_t x4;
                    uint16_t y4;
                    uint8_t data_bank4;
                    uint16_t direct_page4;
                    if (value3 != 0) {
                        RAM8(0x0A55) = 0x48;
                        RAM8(0x0A75) = 0x52;
                        r->a = (a >> 8 << 8) | RAM8(0xE02C);
                        r->x = 0x5B26;
                        r->y = 0x24;
                        r->mf = 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1C5, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1C5); }
                        uint16_t dp_ret = r->dp;
                        uint8_t db_ret = r->db;
                        uint16_t a_all = r->a;
                        a4 = RAM8(0xE42C);
                        a_hi4 = a_all >> 8;
                        x4 = 0x5B30;
                        y4 = 0x2C;
                        data_bank4 = db_ret;
                        direct_page4 = dp_ret;
                    } else {
                        uint8_t a3;
                        uint8_t a_hi3;
                        uint16_t x3;
                        uint16_t y3;
                        uint8_t data_bank3;
                        uint16_t direct_page3;
                        if (value3 == 0) {
                            RAM8(0x0A55) = 0x4D;
                            a3 = RAM8(0xE02C);
                            a_hi3 = a >> 8;
                            x3 = 0x5B2B;
                            y3 = 0x24;
                            data_bank3 = 0;
                            direct_page3 = 0;
                        } else {
                            uint8_t a2;
                            uint8_t a_hi2;
                            uint16_t x2;
                            uint16_t y2;
                            uint8_t data_bank2;
                            uint16_t direct_page2;
                            if (value3 & 0x80) {
                                RAM8(0x0A55) = 0x48;
                                RAM8(0x0A65) = 0x52;
                                r->a = (a >> 8 << 8) | RAM8(0xE02C);
                                r->x = 0x5B26;
                                r->y = 0x24;
                                r->mf = 1;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1A2, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1A2); }
                                uint16_t dp_ret2 = r->dp;
                                uint8_t db_ret2 = r->db;
                                uint16_t a_all2 = r->a;
                                a2 = RAM8(0xE22C);
                                a_hi2 = a_all2 >> 8;
                                x2 = 0x5B30;
                                y2 = 0x28;
                                data_bank2 = db_ret2;
                                direct_page2 = dp_ret2;
                            } else {
                                uint8_t a1;
                                uint8_t a_hi1;
                                uint16_t x1;
                                uint16_t y1;
                                uint8_t data_bank;
                                uint16_t direct_page;
                                if (value3 == 0) {
                                    RAM8(0x0A55) = 0x48;
                                    RAM8(0x0A65) = 0x52;
                                    r->a = (a >> 8 << 8) | RAM8(0xE02C);
                                    r->x = 0x5B26;
                                    r->y = 0x24;
                                    r->mf = 1;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1A2, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1A2); }
                                    uint16_t dp_ret3 = r->dp;
                                    uint8_t db_ret3 = r->db;
                                    uint16_t a_all3 = r->a;
                                    a1 = RAM8(0xE22C);
                                    a_hi1 = a_all3 >> 8;
                                    x1 = 0x5B30;
                                    y1 = 0x28;
                                    data_bank = db_ret3;
                                    direct_page = dp_ret3;
                                } else {
                                    RAM8(0x0A55) = 0x43;
                                    RAM8(0x0A65) = 0x4D;
                                    RAM8(0x0A75) = 0x57;
                                    r->a = (a >> 8 << 8) | RAM8(0xE02C);
                                    r->x = 0x5B21;
                                    r->y = 0x24;
                                    r->mf = 1;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE210, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE210); }
                                    uint16_t a_all4 = r->a;
                                    r->a = (a_all4 >> 8 << 8) | RAM8(0xE22C);
                                    r->x = 0x5B2B;
                                    r->y = 0x28;
                                    r->mf = 1;
                                    r->xf = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE21D, write_one_party_hud_frame_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE21D); }
                                    uint16_t dp_ret5 = r->dp;
                                    uint8_t db_ret5 = r->db;
                                    uint16_t a_all5 = r->a;
                                    a1 = RAM8(0xE42C);
                                    a_hi1 = a_all5 >> 8;
                                    x1 = 0x5B35;
                                    y1 = 0x2C;
                                    data_bank = db_ret5;
                                    direct_page = dp_ret5;
                                }
                                a2 = a1;
                                a_hi2 = a_hi1;
                                x2 = x1;
                                y2 = y1;
                                data_bank2 = data_bank;
                                direct_page2 = direct_page;
                            }
                            a3 = a2;
                            a_hi3 = a_hi2;
                            x3 = x2;
                            y3 = y2;
                            data_bank3 = data_bank2;
                            direct_page3 = direct_page2;
                        }
                        a4 = a3;
                        a_hi4 = a_hi3;
                        x4 = x3;
                        y4 = y3;
                        data_bank4 = data_bank3;
                        direct_page4 = direct_page3;
                    }
                    a5 = a4;
                    a_hi5 = a_hi4;
                    x5 = x4;
                    y5 = y4;
                    data_bank5 = data_bank4;
                    direct_page5 = direct_page4;
                }
                a14 = a5;
                a_hi14 = a_hi5;
                x14 = x5;
                y14 = y5;
                data_bank14 = data_bank5;
                direct_page14 = direct_page5;
            } else {
                uint8_t a13;
                uint8_t a_hi13;
                uint16_t x13;
                uint16_t y13;
                uint8_t data_bank13;
                uint16_t direct_page13;
                if (value2 != 0) {
                    uint8_t value15 = RAM8(0xE400);
                    uint8_t a7;
                    uint8_t a_hi7;
                    uint16_t x7;
                    uint16_t y7;
                    uint8_t data_bank7;
                    uint16_t direct_page7;
                    if (value15 & 0x80) {
                        RAM8(0x0A55) = 0x48;
                        RAM8(0x0A65) = 0x52;
                        r->a = (a >> 8 << 8) | RAM8(0xE02C);
                        r->x = 0x5B26;
                        r->y = 0x24;
                        r->mf = 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1A2, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1A2); }
                        uint16_t dp_ret6 = r->dp;
                        uint8_t db_ret6 = r->db;
                        uint16_t a_all6 = r->a;
                        a7 = RAM8(0xE22C);
                        a_hi7 = a_all6 >> 8;
                        x7 = 0x5B30;
                        y7 = 0x28;
                        data_bank7 = db_ret6;
                        direct_page7 = dp_ret6;
                    } else {
                        uint8_t a6;
                        uint8_t a_hi6;
                        uint16_t x6;
                        uint16_t y6;
                        uint8_t data_bank6;
                        uint16_t direct_page6;
                        if (value15 == 0) {
                            RAM8(0x0A55) = 0x48;
                            RAM8(0x0A65) = 0x52;
                            r->a = (a >> 8 << 8) | RAM8(0xE02C);
                            r->x = 0x5B26;
                            r->y = 0x24;
                            r->mf = 1;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1A2, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1A2); }
                            uint16_t dp_ret7 = r->dp;
                            uint8_t db_ret7 = r->db;
                            uint16_t a_all7 = r->a;
                            a6 = RAM8(0xE22C);
                            a_hi6 = a_all7 >> 8;
                            x6 = 0x5B30;
                            y6 = 0x28;
                            data_bank6 = db_ret7;
                            direct_page6 = dp_ret7;
                        } else {
                            RAM8(0x0A55) = 0x43;
                            RAM8(0x0A65) = 0x4D;
                            RAM8(0x0A75) = 0x57;
                            r->a = (a >> 8 << 8) | RAM8(0xE02C);
                            r->x = 0x5B21;
                            r->y = 0x24;
                            r->mf = 1;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE210, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE210); }
                            uint16_t a_all8 = r->a;
                            r->a = (a_all8 >> 8 << 8) | RAM8(0xE22C);
                            r->x = 0x5B2B;
                            r->y = 0x28;
                            r->mf = 1;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE21D, write_one_party_hud_frame_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE21D); }
                            uint16_t dp_ret9 = r->dp;
                            uint8_t db_ret9 = r->db;
                            uint16_t a_all9 = r->a;
                            a6 = RAM8(0xE42C);
                            a_hi6 = a_all9 >> 8;
                            x6 = 0x5B35;
                            y6 = 0x2C;
                            data_bank6 = db_ret9;
                            direct_page6 = dp_ret9;
                        }
                        a7 = a6;
                        a_hi7 = a_hi6;
                        x7 = x6;
                        y7 = y6;
                        data_bank7 = data_bank6;
                        direct_page7 = direct_page6;
                    }
                    a13 = a7;
                    a_hi13 = a_hi7;
                    x13 = x7;
                    y13 = y7;
                    data_bank13 = data_bank7;
                    direct_page13 = direct_page7;
                } else {
                    uint8_t value23 = RAM8(0xE400);
                    uint8_t a12;
                    uint8_t a_hi12;
                    uint16_t x12;
                    uint16_t y12;
                    uint8_t data_bank12;
                    uint16_t direct_page12;
                    if (value23 & 0x80) {
                        RAM8(0x0A55) = 0x4D;
                        a12 = RAM8(0xE02C);
                        a_hi12 = a >> 8;
                        x12 = 0x5B2B;
                        y12 = 0x24;
                        data_bank12 = 0;
                        direct_page12 = 0;
                    } else {
                        uint8_t a11;
                        uint8_t a_hi11;
                        uint16_t x11;
                        uint16_t y11;
                        uint8_t data_bank11;
                        uint16_t direct_page11;
                        if (value23 != 0) {
                            RAM8(0x0A55) = 0x48;
                            RAM8(0x0A75) = 0x52;
                            r->a = (a >> 8 << 8) | RAM8(0xE02C);
                            r->x = 0x5B26;
                            r->y = 0x24;
                            r->mf = 1;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1C5, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1C5); }
                            uint16_t dp_ret10 = r->dp;
                            uint8_t db_ret10 = r->db;
                            uint16_t a_all10 = r->a;
                            a11 = RAM8(0xE42C);
                            a_hi11 = a_all10 >> 8;
                            x11 = 0x5B30;
                            y11 = 0x2C;
                            data_bank11 = db_ret10;
                            direct_page11 = dp_ret10;
                        } else {
                            uint8_t a10;
                            uint8_t a_hi10;
                            uint16_t x10;
                            uint16_t y10;
                            uint8_t data_bank10;
                            uint16_t direct_page10;
                            if (value23 == 0) {
                                RAM8(0x0A55) = 0x4D;
                                a10 = RAM8(0xE02C);
                                a_hi10 = a >> 8;
                                x10 = 0x5B2B;
                                y10 = 0x24;
                                data_bank10 = 0;
                                direct_page10 = 0;
                            } else {
                                uint8_t a9;
                                uint8_t a_hi9;
                                uint16_t x9;
                                uint16_t y9;
                                uint8_t data_bank9;
                                uint16_t direct_page9;
                                if (value23 & 0x80) {
                                    RAM8(0x0A55) = 0x48;
                                    RAM8(0x0A65) = 0x52;
                                    r->a = (a >> 8 << 8) | RAM8(0xE02C);
                                    r->x = 0x5B26;
                                    r->y = 0x24;
                                    r->mf = 1;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1A2, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1A2); }
                                    uint16_t dp_ret11 = r->dp;
                                    uint8_t db_ret11 = r->db;
                                    uint16_t a_all11 = r->a;
                                    a9 = RAM8(0xE22C);
                                    a_hi9 = a_all11 >> 8;
                                    x9 = 0x5B30;
                                    y9 = 0x28;
                                    data_bank9 = db_ret11;
                                    direct_page9 = dp_ret11;
                                } else {
                                    uint8_t a8;
                                    uint8_t a_hi8;
                                    uint16_t x8;
                                    uint16_t y8;
                                    uint8_t data_bank8;
                                    uint16_t direct_page8;
                                    if (value23 == 0) {
                                        RAM8(0x0A55) = 0x48;
                                        RAM8(0x0A65) = 0x52;
                                        r->a = (a >> 8 << 8) | RAM8(0xE02C);
                                        r->x = 0x5B26;
                                        r->y = 0x24;
                                        r->mf = 1;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1A2, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1A2); }
                                        uint16_t dp_ret12 = r->dp;
                                        uint8_t db_ret12 = r->db;
                                        uint16_t a_all12 = r->a;
                                        a8 = RAM8(0xE22C);
                                        a_hi8 = a_all12 >> 8;
                                        x8 = 0x5B30;
                                        y8 = 0x28;
                                        data_bank8 = db_ret12;
                                        direct_page8 = dp_ret12;
                                    } else {
                                        RAM8(0x0A55) = 0x43;
                                        RAM8(0x0A65) = 0x4D;
                                        RAM8(0x0A75) = 0x57;
                                        r->a = (a >> 8 << 8) | RAM8(0xE02C);
                                        r->x = 0x5B21;
                                        r->y = 0x24;
                                        r->mf = 1;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE210, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE210); }
                                        uint16_t a_all13 = r->a;
                                        r->a = (a_all13 >> 8 << 8) | RAM8(0xE22C);
                                        r->x = 0x5B2B;
                                        r->y = 0x28;
                                        r->mf = 1;
                                        r->xf = 0;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE21D, write_one_party_hud_frame_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE21D); }
                                        uint16_t dp_ret14 = r->dp;
                                        uint8_t db_ret14 = r->db;
                                        uint16_t a_all14 = r->a;
                                        a8 = RAM8(0xE42C);
                                        a_hi8 = a_all14 >> 8;
                                        x8 = 0x5B35;
                                        y8 = 0x2C;
                                        data_bank8 = db_ret14;
                                        direct_page8 = dp_ret14;
                                    }
                                    a9 = a8;
                                    a_hi9 = a_hi8;
                                    x9 = x8;
                                    y9 = y8;
                                    data_bank9 = data_bank8;
                                    direct_page9 = direct_page8;
                                }
                                a10 = a9;
                                a_hi10 = a_hi9;
                                x10 = x9;
                                y10 = y9;
                                data_bank10 = data_bank9;
                                direct_page10 = direct_page9;
                            }
                            a11 = a10;
                            a_hi11 = a_hi10;
                            x11 = x10;
                            y11 = y10;
                            data_bank11 = data_bank10;
                            direct_page11 = direct_page10;
                        }
                        a12 = a11;
                        a_hi12 = a_hi11;
                        x12 = x11;
                        y12 = y11;
                        data_bank12 = data_bank11;
                        direct_page12 = direct_page11;
                    }
                    a13 = a12;
                    a_hi13 = a_hi12;
                    x13 = x12;
                    y13 = y12;
                    data_bank13 = data_bank12;
                    direct_page13 = direct_page12;
                }
                a14 = a13;
                a_hi14 = a_hi13;
                x14 = x13;
                y14 = y13;
                data_bank14 = data_bank13;
                direct_page14 = direct_page13;
            }
            RAM16_SET(0x0000 + direct_page14, x14);
            BUS16_SET(c, (data_bank14 << 0x10) + 0x2116, x14);
            BUS8_SET(c, (data_bank14 << 0x10) + 0x2115, 0x80);
            uint8_t a_hi15 = a_hi14;
            uint16_t x15 = 0;
            for (;;) {
                uint16_t value35 = BUS16(c, 0xD27E30 + x15);
                BUS16_SET(c, (data_bank14 << 0x10) + 0x2118, value35);
                a_hi15 = value35 >> 8;
                x15 = (uint16_t)(x15 + 2);
                if (!(x15 < 0x14)) break;
            }
            uint16_t value36 = RAM16(0x0000 + direct_page14);
            BUS16_SET(c, (data_bank14 << 0x10) + 0x2116, (uint16_t)(value36 + 0x20));
            uint8_t a_hi16 = (uint16_t)(value36 + 0x20) >> 8;
            uint16_t x16 = x15;
            for (;;) {
                uint16_t value37 = BUS16(c, 0xD27E30 + x16);
                BUS16_SET(c, (data_bank14 << 0x10) + 0x2118, value37);
                a_hi16 = value37 >> 8;
                x16 = (uint16_t)(x16 + 2);
                if (!(x16 < 0x28)) break;
            }
            uint16_t value38 = RAM16(0x0000 + direct_page14);
            BUS16_SET(c, (data_bank14 << 0x10) + 0x2116, (uint16_t)(value38 + 0x40));
            uint8_t a_hi17 = (uint16_t)(value38 + 0x40) >> 8;
            uint16_t x17 = x16;
            for (;;) {
                uint16_t value39 = BUS16(c, 0xD27E30 + x17);
                BUS16_SET(c, (data_bank14 << 0x10) + 0x2118, value39);
                a_hi17 = value39 >> 8;
                x17 = (uint16_t)(x17 + 2);
                if (!(x17 < 0x3C)) break;
            }
            uint16_t value40 = RAM16(0x0000 + direct_page14);
            BUS16_SET(c, (data_bank14 << 0x10) + 0x2116, (uint16_t)(value40 + 1));
            uint8_t a17;
            if (a14 == 0) {
                a17 = 0x16;
            } else {
                uint8_t a16;
                if (a14 & 0x01) {
                    a16 = 0x21;
                } else {
                    uint8_t a15;
                    if (a14 >> 1 & 0x01) {
                        a15 = 0x22;
                    } else {
                        a15 = 0x23;
                    }
                    a16 = a15;
                }
                a17 = a16;
            }
            BUS8_SET(c, (data_bank14 << 0x10) + 0x2118, a17);
            uint16_t value41 = RAM16(0x0000 + direct_page14);
            BUS16_SET(c, (data_bank14 << 0x10) + 0x2116, (uint16_t)(value41 + 0x24));
            uint8_t value42 = RAM8(0x00B8 + direct_page14);
            uint8_t a19;
            bool zero2;
            bool negative2;
            if (value42 & 0x80) {
                a19 = 0x24;
                zero2 = 0;
                negative2 = 0;
            } else {
                uint8_t a18;
                bool zero1;
                bool negative1;
                if (!(value42 & 0x40)) {
                    a18 = (uint8_t)y14;
                    zero1 = ((uint8_t)y14 & value42) == 0;
                    negative1 = value42 & 0x80;
                } else {
                    a18 = 0x24;
                    zero1 = 0;
                    negative1 = 0;
                }
                a19 = a18;
                zero2 = zero1;
                negative2 = negative1;
            }
            BUS8_SET(c, (data_bank14 << 0x10) + 0x2119, a19);
            BUS8_SET(c, (data_bank14 << 0x10) + 0x2119, a19);
            BUS8_SET(c, (data_bank14 << 0x10) + 0x2119, a19);
            BUS8_SET(c, (data_bank14 << 0x10) + 0x2119, a19);
            BUS8_SET(c, (data_bank14 << 0x10) + 0x2119, a19);
            r->a = (y14 >> 8 << 8) | a19;
            r->x = (uint16_t)(value40 + 1);
            r->y = y14;
            r->c = value41 + 0x24 > 0xFFFF;
            r->z = zero2;
            r->n = negative2;
            r->v = value42 & 0x40;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank14;
            r->dp = direct_page14;
            RETURN_RTS(c);
        }
        a_hi_e126 = a >> 8;
        x_e126 = x;
        y_e126 = y;
        carry_e126 = carry;
        overflow_e126 = overflow;
        goto shared_E126;
    }
    SET_A8(r, event_flag_bytes);
    r->z = event_flag_bytes == 0;
    r->n = event_flag_bytes & 0x80;
    r->mf = 1;
    RETURN_RTS(c);
    shared_E126:;
    uint8_t value43 = RAM8(0xE200);
    if (value43 & 0x80) {
        a_hi_e12e = a_hi_e126;
        x_e12e = x_e126;
        y_e12e = y_e126;
        carry_e12e = carry_e126;
        overflow_e12e = overflow_e126;
        goto shared_E12E;
    }
    if (value43 != 0) {
        uint8_t value44 = RAM8(0xE400);
        uint8_t a22;
        uint8_t a_hi19;
        uint16_t x19;
        uint16_t y17;
        uint8_t data_bank16;
        uint16_t direct_page16;
        if (value44 & 0x80) {
            RAM8(0x0A65) = 0x4D;
            a22 = RAM8(0xE22C);
            a_hi19 = a_hi_e126;
            x19 = 0x5B2B;
            y17 = 0x28;
            data_bank16 = 0;
            direct_page16 = 0;
        } else {
            uint8_t a21;
            uint8_t a_hi18;
            uint16_t x18;
            uint16_t y16;
            uint8_t data_bank15;
            uint16_t direct_page15;
            if (value44 != 0) {
                RAM8(0x0A65) = 0x48;
                RAM8(0x0A75) = 0x52;
                r->a = (a_hi_e126 << 8) | RAM8(0xE22C);
                r->x = 0x5B26;
                r->y = 0x28;
                r->mf = 1;
                r->xf = 0;
                r->db = 0;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE1E8, write_one_party_hud_frame, sp_in, 2); GUARD_JSR(c, sp_call, 0xE1E8); }
                uint16_t dp_ret15 = r->dp;
                uint8_t db_ret15 = r->db;
                uint16_t a_all15 = r->a;
                a21 = RAM8(0xE42C);
                a_hi18 = a_all15 >> 8;
                x18 = 0x5B30;
                y16 = 0x2C;
                data_bank15 = db_ret15;
                direct_page15 = dp_ret15;
            } else {
                uint8_t a20;
                uint16_t y15;
                if (value44 == 0) {
                    RAM8(0x0A65) = 0x4D;
                    a20 = RAM8(0xE22C);
                    y15 = 0x28;
                } else {
                    RAM8(0x0A55) = 0x4D;
                    a20 = RAM8(0xE02C);
                    y15 = 0x24;
                }
                a21 = a20;
                a_hi18 = a_hi_e126;
                x18 = 0x5B2B;
                y16 = y15;
                data_bank15 = 0;
                direct_page15 = 0;
            }
            a22 = a21;
            a_hi19 = a_hi18;
            x19 = x18;
            y17 = y16;
            data_bank16 = data_bank15;
            direct_page16 = direct_page15;
        }
        RAM16_SET(0x0000 + direct_page16, x19);
        BUS16_SET(c, (data_bank16 << 0x10) + 0x2116, x19);
        BUS8_SET(c, (data_bank16 << 0x10) + 0x2115, 0x80);
        uint8_t a_hi20 = a_hi19;
        uint16_t x20 = 0;
        for (;;) {
            uint16_t value50 = BUS16(c, 0xD27E30 + x20);
            BUS16_SET(c, (data_bank16 << 0x10) + 0x2118, value50);
            a_hi20 = value50 >> 8;
            x20 = (uint16_t)(x20 + 2);
            if (!(x20 < 0x14)) break;
        }
        uint16_t value51 = RAM16(0x0000 + direct_page16);
        BUS16_SET(c, (data_bank16 << 0x10) + 0x2116, (uint16_t)(value51 + 0x20));
        uint8_t a_hi21 = (uint16_t)(value51 + 0x20) >> 8;
        uint16_t x21 = x20;
        for (;;) {
            uint16_t value52 = BUS16(c, 0xD27E30 + x21);
            BUS16_SET(c, (data_bank16 << 0x10) + 0x2118, value52);
            a_hi21 = value52 >> 8;
            x21 = (uint16_t)(x21 + 2);
            if (!(x21 < 0x28)) break;
        }
        uint16_t value53 = RAM16(0x0000 + direct_page16);
        BUS16_SET(c, (data_bank16 << 0x10) + 0x2116, (uint16_t)(value53 + 0x40));
        uint8_t a_hi22 = (uint16_t)(value53 + 0x40) >> 8;
        uint16_t x22 = x21;
        for (;;) {
            uint16_t value54 = BUS16(c, 0xD27E30 + x22);
            BUS16_SET(c, (data_bank16 << 0x10) + 0x2118, value54);
            a_hi22 = value54 >> 8;
            x22 = (uint16_t)(x22 + 2);
            if (!(x22 < 0x3C)) break;
        }
        uint16_t value55 = RAM16(0x0000 + direct_page16);
        BUS16_SET(c, (data_bank16 << 0x10) + 0x2116, (uint16_t)(value55 + 1));
        uint8_t a25;
        if (a22 == 0) {
            a25 = 0x16;
        } else {
            uint8_t a24;
            if (a22 & 0x01) {
                a24 = 0x21;
            } else {
                uint8_t a23;
                if (a22 >> 1 & 0x01) {
                    a23 = 0x22;
                } else {
                    a23 = 0x23;
                }
                a24 = a23;
            }
            a25 = a24;
        }
        BUS8_SET(c, (data_bank16 << 0x10) + 0x2118, a25);
        uint16_t value56 = RAM16(0x0000 + direct_page16);
        BUS16_SET(c, (data_bank16 << 0x10) + 0x2116, (uint16_t)(value56 + 0x24));
        uint8_t value57 = RAM8(0x00B8 + direct_page16);
        uint8_t a27;
        bool zero4;
        bool negative4;
        if (value57 & 0x80) {
            a27 = 0x24;
            zero4 = 0;
            negative4 = 0;
        } else {
            uint8_t a26;
            bool zero3;
            bool negative3;
            if (!(value57 & 0x40)) {
                a26 = (uint8_t)y17;
                zero3 = ((uint8_t)y17 & value57) == 0;
                negative3 = value57 & 0x80;
            } else {
                a26 = 0x24;
                zero3 = 0;
                negative3 = 0;
            }
            a27 = a26;
            zero4 = zero3;
            negative4 = negative3;
        }
        BUS8_SET(c, (data_bank16 << 0x10) + 0x2119, a27);
        BUS8_SET(c, (data_bank16 << 0x10) + 0x2119, a27);
        BUS8_SET(c, (data_bank16 << 0x10) + 0x2119, a27);
        BUS8_SET(c, (data_bank16 << 0x10) + 0x2119, a27);
        BUS8_SET(c, (data_bank16 << 0x10) + 0x2119, a27);
        r->a = (y17 >> 8 << 8) | a27;
        r->x = (uint16_t)(value55 + 1);
        r->y = y17;
        r->c = value56 + 0x24 > 0xFFFF;
        r->z = zero4;
        r->n = negative4;
        r->v = value57 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank16;
        r->dp = direct_page16;
        RETURN_RTS(c);
    }
    a_hi_e12e = a_hi_e126;
    x_e12e = x_e126;
    y_e12e = y_e126;
    carry_e12e = carry_e126;
    overflow_e12e = overflow_e126;
    goto shared_E12E;
    shared_E12E:;
    uint8_t value58 = RAM8(0xE400);
    if (value58 & 0x80) {
        r->a = (a_hi_e12e << 8) | value58;
        r->x = x_e12e;
        r->y = y_e12e;
        r->c = carry_e12e;
        r->z = value58 == 0;
        r->n = value58 & 0x80;
        r->v = overflow_e12e;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if (value58 != 0) {
        RAM8(0x0A75) = 0x4D;
        uint8_t value59 = RAM8(0xE42C);
        RAM16_SET(0x0000, 0x5B2B);
        BUS16_SET(c, 0x002116, 0x5B2B);
        BUS8_SET(c, 0x002115, 0x80);
        uint8_t a_hi23 = a_hi_e12e;
        uint16_t x23 = 0;
        for (;;) {
            uint16_t value60 = BUS16(c, 0xD27E30 + x23);
            BUS16_SET(c, 0x002118, value60);
            a_hi23 = value60 >> 8;
            x23 = (uint16_t)(x23 + 2);
            if (!(x23 < 0x14)) break;
        }
        uint16_t value61 = RAM16(0x0000);
        BUS16_SET(c, 0x002116, (uint16_t)(value61 + 0x20));
        uint8_t a_hi24 = (uint16_t)(value61 + 0x20) >> 8;
        uint16_t x24 = x23;
        for (;;) {
            uint16_t value62 = BUS16(c, 0xD27E30 + x24);
            BUS16_SET(c, 0x002118, value62);
            a_hi24 = value62 >> 8;
            x24 = (uint16_t)(x24 + 2);
            if (!(x24 < 0x28)) break;
        }
        uint16_t value63 = RAM16(0x0000);
        BUS16_SET(c, 0x002116, (uint16_t)(value63 + 0x40));
        uint8_t a_hi25 = (uint16_t)(value63 + 0x40) >> 8;
        uint16_t x25 = x24;
        for (;;) {
            uint16_t value64 = BUS16(c, 0xD27E30 + x25);
            BUS16_SET(c, 0x002118, value64);
            a_hi25 = value64 >> 8;
            x25 = (uint16_t)(x25 + 2);
            if (!(x25 < 0x3C)) break;
        }
        uint16_t value65 = RAM16(0x0000);
        BUS16_SET(c, 0x002116, (uint16_t)(value65 + 1));
        uint8_t a30;
        if (value59 == 0) {
            a30 = 0x16;
        } else {
            uint8_t a29;
            if (value59 & 0x01) {
                a29 = 0x21;
            } else {
                uint8_t a28;
                if (value59 >> 1 & 0x01) {
                    a28 = 0x22;
                } else {
                    a28 = 0x23;
                }
                a29 = a28;
            }
            a30 = a29;
        }
        BUS8_SET(c, 0x002118, a30);
        BUS16_SET(c, 0x002116, (uint16_t)(value65 + 0x24));
        uint8_t value66 = RAM8(0x00B8);
        uint8_t a32;
        bool zero6;
        bool negative6;
        if (value66 & 0x80) {
            a32 = 0x24;
            zero6 = 0;
            negative6 = 0;
        } else {
            uint8_t a31;
            bool zero5;
            bool negative5;
            if (!(value66 & 0x40)) {
                a31 = 0x2C;
                zero5 = (value66 & 0x2C) == 0;
                negative5 = value66 & 0x80;
            } else {
                a31 = 0x24;
                zero5 = 0;
                negative5 = 0;
            }
            a32 = a31;
            zero6 = zero5;
            negative6 = negative5;
        }
        BUS8_SET(c, 0x002119, a32);
        BUS8_SET(c, 0x002119, a32);
        BUS8_SET(c, 0x002119, a32);
        BUS8_SET(c, 0x002119, a32);
        BUS8_SET(c, 0x002119, a32);
        r->a = a32;
        r->x = (uint16_t)(value65 + 1);
        r->y = 0x2C;
        r->c = value65 + 0x24 > 0xFFFF;
        r->z = zero6;
        r->n = negative6;
        r->v = value66 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi_e12e << 8) | value58;
    r->x = x_e12e;
    r->y = y_e12e;
    r->c = carry_e12e;
    r->z = value58 == 0;
    r->n = value58 & 0x80;
    r->v = overflow_e12e;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E113, SOM_RTS, "gen", place_party_hud_frames, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 0, 0, 425, 167)

/* C1E228 write_one_party_hud_frame   [class A, 148 bytes, 68 instructions]
 * Source: src/rom/place_party_hud_frames.s
 * Subroutine of place_party_hud_frames, translated in place.
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void write_one_party_hud_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0000, x);
    BUS16_SET(c, 0x002116, x);
    BUS8_SET(c, 0x002115, 0x80);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    for (;;) {
        uint16_t value = BUS16(c, 0xD27E30 + x1);
        BUS16_SET(c, 0x002118, value);
        a_hi1 = value >> 8;
        x1 = (uint16_t)(x1 + 2);
        if (!(x1 < 0x14)) break;
    }
    uint16_t value2 = RAM16(0x0000);
    BUS16_SET(c, 0x002116, (uint16_t)(value2 + 0x20));
    uint8_t a_hi2 = (uint16_t)(value2 + 0x20) >> 8;
    uint16_t x2 = x1;
    for (;;) {
        uint16_t value3 = BUS16(c, 0xD27E30 + x2);
        BUS16_SET(c, 0x002118, value3);
        a_hi2 = value3 >> 8;
        x2 = (uint16_t)(x2 + 2);
        if (!(x2 < 0x28)) break;
    }
    uint16_t value4 = RAM16(0x0000);
    BUS16_SET(c, 0x002116, (uint16_t)(value4 + 0x40));
    uint8_t a_hi3 = (uint16_t)(value4 + 0x40) >> 8;
    uint16_t x3 = x2;
    for (;;) {
        uint16_t value5 = BUS16(c, 0xD27E30 + x3);
        BUS16_SET(c, 0x002118, value5);
        a_hi3 = value5 >> 8;
        x3 = (uint16_t)(x3 + 2);
        if (!(x3 < 0x3C)) break;
    }
    uint16_t value6 = RAM16(0x0000);
    BUS16_SET(c, 0x002116, (uint16_t)(value6 + 1));
    uint8_t a3;
    if (a == 0) {
        a3 = 0x16;
    } else {
        uint8_t a2;
        if (a & 0x01) {
            a2 = 0x21;
        } else {
            uint8_t a1;
            if (a >> 1 & 0x01) {
                a1 = 0x22;
            } else {
                a1 = 0x23;
            }
            a2 = a1;
        }
        a3 = a2;
    }
    BUS8_SET(c, 0x002118, a3);
    BUS16_SET(c, 0x002116, (uint16_t)(value6 + 0x24));
    uint8_t value7 = RAM8(0x00B8);
    uint8_t a5;
    bool zero2;
    bool negative2;
    if (value7 & 0x80) {
        a5 = 0x24;
        zero2 = 0;
        negative2 = 0;
    } else {
        uint8_t a4;
        bool zero1;
        bool negative1;
        if (!(value7 & 0x40)) {
            a4 = (uint8_t)y;
            zero1 = ((uint8_t)y & value7) == 0;
            negative1 = value7 & 0x80;
        } else {
            a4 = 0x24;
            zero1 = 0;
            negative1 = 0;
        }
        a5 = a4;
        zero2 = zero1;
        negative2 = negative1;
    }
    BUS8_SET(c, 0x002119, a5);
    BUS8_SET(c, 0x002119, a5);
    BUS8_SET(c, 0x002119, a5);
    BUS8_SET(c, 0x002119, a5);
    BUS8_SET(c, 0x002119, a5);
    r->a = (y >> 8 << 8) | a5;
    r->x = (uint16_t)(value6 + 1);
    r->y = y;
    r->c = value6 + 0x24 > 0xFFFF;
    r->z = zero2;
    r->n = negative2;
    r->v = value7 & 0x40;
    RETURN_RTS(c);
}

/* C1E228 write_one_party_hud_frame_v2   [class A, 148 bytes, 68 instructions]
 * Source: src/rom/place_party_hud_frames.s
 * Subroutine of place_party_hud_frames, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void write_one_party_hud_frame_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    RAM16_SET(0x0000 + dp, x);
    BUS16_SET(c, (db << 0x10) + 0x2116, x);
    BUS8_SET(c, (db << 0x10) + 0x2115, 0x80);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    for (;;) {
        uint16_t value = BUS16(c, 0xD27E30 + x1);
        BUS16_SET(c, (db << 0x10) + 0x2118, value);
        a_hi1 = value >> 8;
        x1 = (uint16_t)(x1 + 2);
        if (!(x1 < 0x14)) break;
    }
    uint16_t value2 = RAM16(0x0000 + dp);
    BUS16_SET(c, (db << 0x10) + 0x2116, (uint16_t)(value2 + 0x20));
    uint8_t a_hi2 = (uint16_t)(value2 + 0x20) >> 8;
    uint16_t x2 = x1;
    for (;;) {
        uint16_t value3 = BUS16(c, 0xD27E30 + x2);
        BUS16_SET(c, (db << 0x10) + 0x2118, value3);
        a_hi2 = value3 >> 8;
        x2 = (uint16_t)(x2 + 2);
        if (!(x2 < 0x28)) break;
    }
    uint16_t value4 = RAM16(0x0000 + dp);
    BUS16_SET(c, (db << 0x10) + 0x2116, (uint16_t)(value4 + 0x40));
    uint8_t a_hi3 = (uint16_t)(value4 + 0x40) >> 8;
    uint16_t x3 = x2;
    for (;;) {
        uint16_t value5 = BUS16(c, 0xD27E30 + x3);
        BUS16_SET(c, (db << 0x10) + 0x2118, value5);
        a_hi3 = value5 >> 8;
        x3 = (uint16_t)(x3 + 2);
        if (!(x3 < 0x3C)) break;
    }
    uint16_t value6 = RAM16(0x0000 + dp);
    BUS16_SET(c, (db << 0x10) + 0x2116, (uint16_t)(value6 + 1));
    uint8_t a3;
    if (a == 0) {
        a3 = 0x16;
    } else {
        uint8_t a2;
        if (a & 0x01) {
            a2 = 0x21;
        } else {
            uint8_t a1;
            if (a >> 1 & 0x01) {
                a1 = 0x22;
            } else {
                a1 = 0x23;
            }
            a2 = a1;
        }
        a3 = a2;
    }
    BUS8_SET(c, (db << 0x10) + 0x2118, a3);
    uint16_t value7 = RAM16(0x0000 + dp);
    BUS16_SET(c, (db << 0x10) + 0x2116, (uint16_t)(value7 + 0x24));
    uint8_t value8 = RAM8(0x00B8 + dp);
    uint8_t a5;
    bool zero2;
    bool negative2;
    if (value8 & 0x80) {
        a5 = 0x24;
        zero2 = 0;
        negative2 = 0;
    } else {
        uint8_t a4;
        bool zero1;
        bool negative1;
        if (!(value8 & 0x40)) {
            a4 = (uint8_t)y;
            zero1 = ((uint8_t)y & value8) == 0;
            negative1 = value8 & 0x80;
        } else {
            a4 = 0x24;
            zero1 = 0;
            negative1 = 0;
        }
        a5 = a4;
        zero2 = zero1;
        negative2 = negative1;
    }
    BUS8_SET(c, (db << 0x10) + 0x2119, a5);
    BUS8_SET(c, (db << 0x10) + 0x2119, a5);
    BUS8_SET(c, (db << 0x10) + 0x2119, a5);
    BUS8_SET(c, (db << 0x10) + 0x2119, a5);
    BUS8_SET(c, (db << 0x10) + 0x2119, a5);
    r->a = (y >> 8 << 8) | a5;
    r->x = (uint16_t)(value6 + 1);
    r->y = y;
    r->c = value7 + 0x24 > 0xFFFF;
    r->z = zero2;
    r->n = negative2;
    r->v = value8 & 0x40;
    RETURN_RTS(c);
}

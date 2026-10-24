#include "som_c.h"

/* 7E91B8 program_dma_descriptor_pass   [class D, 305 bytes, 153 instructions]
 * Source: src/boot/program_dma_descriptor_pass.s
 * Documented in docs/boot-dma-descriptor-pass.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: ABXYCZNV.
 */
static void program_dma_descriptor_pass(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = a_hi;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x1006E);
    if (value == 0) {
        r->a = value;
        r->x = (a_hi << 8) | a;
        r->z = 0;
        r->n = 0;
        RETURN_RTS(c);
    }
    BUS8_SET(c, 0x00420C, 0);
    uint16_t value2 = RAM16(0x0000 + sp0 - 5);
    RAM16_SET(0x0000 + sp0 - 5, (uint16_t)(0x0106 - value2));
    RAM8(0x0000 + sp0 - 6) = 0x42;
    RAM8(0x0000 + sp0 - 7) = 0;
    uint16_t value3 = RAM16(0x1006E);
    uint16_t value4 = RAM16(0x10066);
    uint8_t a1 = (uint8_t)value3;
    uint8_t a_hi1 = value3 >> 8;
    uint16_t y1 = value4;
    bool carry1 = value2 <= 0x0106;
    bool overflow1 = ((value2 ^ 0x0106) & ((uint16_t)(0x0106 - value2) ^ 0x0106) & 0x8000) != 0;
    uint16_t direct_page = 0x4300;
    for (;;) {
        RAM8(0x0000 + sp0 - 8) = a_hi1;
        RAM8(0x0000 + sp0 - 9) = (uint8_t)((a_hi1 << 8) | a1);
        RAM8(0x0000 + sp0 - 0x0A) = y1 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)y1;
        uint16_t value5 = BUS16(c, 0x7F0000 + y1);
        uint8_t value6 = BUS8(c, 0x002137);
        uint8_t value7 = BUS8(c, 0x00213D);
        uint8_t value8 = BUS8(c, 0x00213D);
        uint16_t value9 = BUS16(c, 0x7F0005 + value5);
        uint16_t value10 = RAM16(0x0000 + sp0 - 5);
        uint8_t a_hi7;
        uint16_t y2;
        bool carry4;
        bool overflow4;
        uint16_t direct_page4;
        if ((uint16_t)((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) + value9) >> 7 < value10) {
            RAM8(0x0000 + sp0 - 0x0C) = value5 >> 8;
            RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)value5;
            BUS8_SET(c, 0x00420B, 0);
            BUS8_SET(c, 0x004300, RAM8(0x10000 + value5));
            uint16_t value12 = BUS16(c, 0x7F0001 + value5);
            BUS16_SET(c, 0x004301, value12);
            uint16_t value13 = BUS16(c, 0x7F0003 + value5);
            BUS16_SET(c, 0x004303, value13);
            uint16_t value14 = BUS16(c, 0x7F0005 + value5);
            BUS16_SET(c, 0x004305, value14);
            uint8_t value15 = RAM8(0x0000 + sp0 - 0x0D);
            uint8_t value16 = RAM8(0x0000 + sp0 - 0x0C);
            uint8_t value17 = BUS8(c, 0x7F0009 + ((value16 << 8) | value15));
            BUS8_SET(c, 0x002115, value17);
            uint8_t value18 = BUS8(c, 0x7F000F + ((value16 << 8) | value15));
            uint8_t a_hi4;
            if ((uint8_t)((value18 & 7) - 1) == 0) {
                uint16_t value19 = BUS16(c, 0x7F000A + ((value16 << 8) | value15));
                BUS16_SET(c, 0x002116, value19);
                a_hi4 = value19 >> 8;
            } else {
                uint8_t a_hi3;
                if ((uint8_t)((value18 & 7) - 2) == 0) {
                    uint8_t value20 = BUS8(c, 0x7F000A + ((value16 << 8) | value15));
                    BUS8_SET(c, 0x002121, value20);
                    a_hi3 = 0x21;
                } else {
                    uint8_t a_hi2;
                    if ((uint8_t)((value18 & 7) - 3) == 0) {
                        uint8_t value21 = BUS8(c, 0x7F000A + ((value16 << 8) | value15));
                        BUS8_SET(c, 0x002181, value21);
                        uint8_t value22 = BUS8(c, 0x7F000B + ((value16 << 8) | value15));
                        BUS8_SET(c, 0x002182, value22);
                        uint8_t value23 = BUS8(c, 0x7F000C + ((value16 << 8) | value15));
                        BUS8_SET(c, 0x002183, value23);
                        a_hi2 = 0x21;
                    } else {
                        uint16_t value24 = BUS16(c, 0x7F000A + ((value16 << 8) | value15));
                        BUS16_SET(c, 0x002102, value24);
                        a_hi2 = value24 >> 8;
                    }
                    a_hi3 = a_hi2;
                }
                a_hi4 = a_hi3;
            }
            BUS8_SET(c, 0x00420B, 1);
            uint8_t value25 = RAM8(0x0000 + sp0 - 0x0B);
            uint8_t value26 = RAM8(0x0000 + sp0 - 0x0A);
            uint16_t value27 = BUS16(c, 0x004212);
            uint8_t a_hi6;
            bool carry3;
            bool overflow3;
            uint16_t direct_page3;
            if ((value27 & 0x80) == 0) {
                BUS16_SET(c, 0x004305, 0);
                uint8_t value28 = RAM8(0x0000 + sp0 - 9);
                uint8_t value29 = RAM8(0x0000 + sp0 - 8);
                uint16_t value30 = RAM16(0x1006E);
                RAM16_SET(0x1006E, (uint16_t)(((uint16_t)(((value29 << 8) | value28) - value30) ^ 0xFFFF) + 1));
                uint8_t value31 = RAM8(0x0000 + sp0 - 7);
                uint8_t value32 = RAM8(0x0000 + sp0 - 6);
                a_hi6 = (uint16_t)(((uint16_t)(((value29 << 8) | value28) - value30) ^ 0xFFFF) + 1) >> 8;
                carry3 = ((value29 << 8) | value28) >= value30;
                overflow3 = ((((value29 << 8) | value28) ^ value30) & (((value29 << 8) | value28) ^ (uint16_t)(((value29 << 8) | value28) - value30)) & 0x8000) != 0;
                direct_page3 = (value32 << 8) | value31;
            } else {
                uint16_t value33 = BUS16(c, 0x004305);
                uint8_t a_hi5;
                bool carry2;
                bool overflow2;
                uint16_t direct_page2;
                if (value33 != 0) {
                    BUS16_SET(c, 0x004305, 0);
                    uint8_t value34 = RAM8(0x0000 + sp0 - 9);
                    uint8_t value35 = RAM8(0x0000 + sp0 - 8);
                    uint16_t value36 = RAM16(0x1006E);
                    RAM16_SET(0x1006E, (uint16_t)(((uint16_t)(((value35 << 8) | value34) - value36) ^ 0xFFFF) + 1));
                    uint8_t value37 = RAM8(0x0000 + sp0 - 7);
                    uint8_t value38 = RAM8(0x0000 + sp0 - 6);
                    a_hi5 = (uint16_t)(((uint16_t)(((value35 << 8) | value34) - value36) ^ 0xFFFF) + 1) >> 8;
                    carry2 = ((value35 << 8) | value34) >= value36;
                    overflow2 = ((((value35 << 8) | value34) ^ value36) & (((value35 << 8) | value34) ^ (uint16_t)(((value35 << 8) | value34) - value36)) & 0x8000) != 0;
                    direct_page2 = (value38 << 8) | value37;
                } else {
                    uint8_t value39 = RAM8(0x0000 + sp0 - 9);
                    uint8_t value40 = RAM8(0x0000 + sp0 - 8);
                    if ((uint16_t)(((value40 << 8) | value39) - 1) != 0) {
                        a1 = (uint8_t)(((value40 << 8) | value39) - 1);
                        a_hi1 = (uint16_t)(((value40 << 8) | value39) - 1) >> 8;
                        y1 = (uint16_t)(((value26 << 8) | value25) + 2);
                        carry1 = (uint16_t)((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) + value9) >> 7 >= value10;
                        overflow1 = (((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) ^ (uint16_t)((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) + value9)) & (value9 ^ (uint16_t)((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) + value9)) & 0x8000) != 0;
                        direct_page = 0x4300;
                        continue;
                    }
                    uint8_t value41 = RAM8(0x0000 + sp0 - 7);
                    uint8_t value42 = RAM8(0x0000 + sp0 - 6);
                    uint8_t value43 = BUS8(c, 0x004212);
                    if ((value43 & 0x80) == 0) {
                        if (RAM8(0x10010) == 0) {
                            RAM8(0x1006E)--;
                            BUS8_SET(c, 0x00420B, 0);
                        }
                    }
                    a_hi5 = (uint16_t)(((value40 << 8) | value39) - 1) >> 8;
                    carry2 = (uint16_t)((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) + value9) >> 7 >= value10;
                    overflow2 = (((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) ^ (uint16_t)((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) + value9)) & (value9 ^ (uint16_t)((((value7 >> 1) | ((value8 & 1) << 7)) << 8 | (((value8 >> 2) | ((value7 & 1) << 7)) & 0x80)) + value9)) & 0x8000) != 0;
                    direct_page2 = (value42 << 8) | value41;
                }
                a_hi6 = a_hi5;
                carry3 = carry2;
                overflow3 = overflow2;
                direct_page3 = direct_page2;
            }
            a_hi7 = a_hi6;
            y2 = (uint16_t)(((value26 << 8) | value25) + 2);
            carry4 = carry3;
            overflow4 = overflow3;
            direct_page4 = direct_page3;
        } else {
            BUS16_SET(c, 0x004305, 0);
            uint16_t value45 = RAM16(0x1006E);
            RAM16_SET(0x1006E, (uint16_t)(((uint16_t)(((a_hi1 << 8) | a1) - value45) ^ 0xFFFF) + 1));
            uint8_t value46 = RAM8(0x0000 + sp0 - 7);
            uint8_t value47 = RAM8(0x0000 + sp0 - 6);
            a_hi7 = (uint16_t)(((uint16_t)(((a_hi1 << 8) | a1) - value45) ^ 0xFFFF) + 1) >> 8;
            y2 = y1;
            carry4 = ((a_hi1 << 8) | a1) >= value45;
            overflow4 = ((((a_hi1 << 8) | a1) ^ value45) & (((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) - value45)) & 0x8000) != 0;
            direct_page4 = (value47 << 8) | value46;
        }
        a_hi1 = a_hi7;
        y1 = y2;
        carry1 = carry4;
        overflow1 = overflow4;
        direct_page = direct_page4;
        break;
    }
    uint16_t value48 = RAM16(0x1007A);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi8;
    uint16_t y3;
    uint8_t data_bank;
    uint16_t direct_page5;
    if (value48 == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi8 = a_hi1;
        y3 = y1;
        data_bank = 0x7F;
        direct_page5 = direct_page;
    } else {
        r->a = (a_hi1 << 8) | a1;
        r->x = value48;
        r->y = y1;
        r->c = carry1;
        r->z = value48 == 0;
        r->n = value48 & 0x8000;
        r->v = overflow1;
        r->dp = direct_page;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x92DC, 0x7E90DA); GUARD_JSR(c, sp_call, 0x92DC); } /* submit_transfer_or_program_hdma */
        r->sp += 6;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        m_flag = m_ret;
        x_flag = x_ret;
        a_hi8 = a_all >> 8;
        y3 = y_ret;
        data_bank = db_ret;
        direct_page5 = dp_ret;
    }
    if (m_flag) {
        uint8_t value49 = BUS8_RDP(c, (data_bank << 0x10) + 0x70);
        BUS8_SET(c, 0x00420C, value49);
        if (x_flag) {
            c->fail = 3;
            return;
        } else {
            uint8_t value55 = RAM8(0x0000 + sp0 - 5);
            uint8_t value56 = RAM8(0x0000 + sp0 - 4);
            uint8_t value57 = RAM8(0x0000 + sp0 - 3);
            uint8_t value58 = RAM8(0x0000 + sp0 - 2);
            uint8_t value59 = RAM8(0x0000 + sp0 - 1);
            uint8_t value60 = RAM8(0x0000 + sp0);
            r->a = (a_hi8 << 8) | value49;
            r->x = (value56 << 8) | value55;
            r->y = y3;
            r->c = value58 & 0x01;
            r->z = ((value60 << 8) | value59) == 0;
            r->n = ((value60 << 8) | value59) & 0x8000;
            r->v = value58 & 0x40;
            r->mf = value58 & 0x20;
            r->xf = value58 & 0x10;
            r->db = value57;
            r->dp = (value60 << 8) | value59;
            r->i = value58 & 0x04;
            r->d = value58 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value61 = BUS16_RDP(c, (data_bank << 0x10) + 0x70);
        BUS16_SET(c, 0x00420C, value61);
        if (x_flag) {
            c->fail = 3;
            return;
        } else {
            uint8_t value67 = RAM8(0x0000 + sp0 - 5);
            uint8_t value68 = RAM8(0x0000 + sp0 - 4);
            uint8_t value69 = RAM8(0x0000 + sp0 - 3);
            uint8_t value70 = RAM8(0x0000 + sp0 - 2);
            uint8_t value71 = RAM8(0x0000 + sp0 - 1);
            uint8_t value72 = RAM8(0x0000 + sp0);
            r->a = value61;
            r->x = (value68 << 8) | value67;
            r->y = y3;
            r->c = value70 & 0x01;
            r->z = ((value72 << 8) | value71) == 0;
            r->n = ((value72 << 8) | value71) & 0x8000;
            r->v = value70 & 0x40;
            r->mf = value70 & 0x20;
            r->xf = value70 & 0x10;
            r->db = value69;
            r->dp = (value72 << 8) | value71;
            r->i = value70 & 0x04;
            r->d = value70 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7E91B8, SOM_RTS, "gen", program_dma_descriptor_pass, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 14, 1, 0, 305, 153)

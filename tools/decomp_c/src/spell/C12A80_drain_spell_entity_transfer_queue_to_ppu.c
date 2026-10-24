#include "som_c.h"

/* C12A80 drain_spell_entity_transfer_queue_to_ppu   [class D, 256 bytes, 127 instructions]
 * Source: src/rom/drain_spell_entity_transfer_queue_to_ppu.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCZNV.
 */
static void drain_spell_entity_transfer_queue_to_ppu(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 6) = 0x7E;
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    uint16_t value = RAM16(0x821C);
    uint8_t a_hi8;
    uint16_t x2;
    uint16_t y2;
    uint16_t direct_page5;
    if (value != 0) {
        RAM8(0x0000 + sp0 - 7) = (uint16_t)(sp0 - 6) >> 8;
        RAM8(0x0000 + sp0 - 8) = (uint8_t)(sp0 - 6);
        uint16_t value2 = RAM16(0x821C);
        uint16_t value3 = RAM16(0x8214);
        uint8_t a1 = (uint8_t)value2;
        uint8_t a_hi1 = value2 >> 8;
        uint16_t x1 = x;
        uint16_t y1 = value3;
        uint16_t direct_page = 0x4300;
        for (;;) {
            RAM8(0x0000 + sp0 - 9) = a_hi1;
            RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)((a_hi1 << 8) | a1);
            RAM8(0x0000 + sp0 - 0x0B) = y1 >> 8;
            RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)y1;
            uint16_t value4 = RAM16(0x0000 + y1);
            RAM8(0x0000 + sp0 - 0x0D) = value4 >> 8;
            RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)value4;
            BUS8_SET(c, 0x00420B, 0);
            BUS8_SET(c, 0x004370, RAM8(0x0000 + value4));
            BUS16_SET(c, 0x004371, RAM16(0x0001 + value4));
            BUS16_SET(c, 0x004373, RAM16(0x0003 + value4));
            BUS16_SET(c, 0x004375, RAM16(0x0005 + value4));
            uint8_t value9 = RAM8(0x0000 + sp0 - 0x0E);
            uint8_t value10 = RAM8(0x0000 + sp0 - 0x0D);
            BUS8_SET(c, 0x002115, RAM8(0x0009 + ((value10 << 8) | value9)));
            uint8_t value12 = RAM8(0x000F + ((value10 << 8) | value9));
            uint8_t a_hi4;
            if ((uint8_t)((value12 & 7) - 1) == 0) {
                uint16_t value13 = RAM16(0x000A + ((value10 << 8) | value9));
                BUS16_SET(c, 0x002116, value13);
                a_hi4 = value13 >> 8;
            } else {
                uint8_t a_hi3;
                if ((uint8_t)((value12 & 7) - 2) == 0) {
                    BUS8_SET(c, 0x002121, RAM8(0x000A + ((value10 << 8) | value9)));
                    a_hi3 = 0x21;
                } else {
                    uint8_t a_hi2;
                    if ((uint8_t)((value12 & 7) - 3) == 0) {
                        BUS8_SET(c, 0x002181, RAM8(0x000A + ((value10 << 8) | value9)));
                        BUS8_SET(c, 0x002182, RAM8(0x000B + ((value10 << 8) | value9)));
                        BUS8_SET(c, 0x002183, RAM8(0x000C + ((value10 << 8) | value9)));
                        a_hi2 = 0x21;
                    } else {
                        uint16_t value18 = RAM16(0x000A + ((value10 << 8) | value9));
                        BUS16_SET(c, 0x002102, value18);
                        a_hi2 = value18 >> 8;
                    }
                    a_hi3 = a_hi2;
                }
                a_hi4 = a_hi3;
            }
            BUS8_SET(c, 0x00420B, 0x80);
            uint8_t value19 = RAM8(0x0000 + sp0 - 0x0C);
            uint8_t value20 = RAM8(0x0000 + sp0 - 0x0B);
            uint8_t value21 = BUS8(c, 0x002137);
            uint8_t value22 = BUS8(c, 0x00213D);
            uint8_t value23 = BUS8(c, 0x00213D);
            bool m_flag3;
            uint8_t a_hi7;
            uint16_t direct_page4;
            if (((value22 << 8) | value23) < 0xE000) {
                BUS16_SET(c, 0x004375, 0);
                uint8_t value24 = RAM8(0x0000 + sp0 - 0x0A);
                uint8_t value25 = RAM8(0x0000 + sp0 - 9);
                uint16_t value26 = RAM16(0x821C);
                RAM16_SET(0x821C, (uint16_t)(((uint16_t)(((value25 << 8) | value24) - value26) ^ 0xFFFF) + 1));
                uint8_t value27 = RAM8(0x0000 + sp0 - 8);
                uint8_t value28 = RAM8(0x0000 + sp0 - 7);
                m_flag3 = 0;
                a_hi7 = (uint16_t)(((uint16_t)(((value25 << 8) | value24) - value26) ^ 0xFFFF) + 1) >> 8;
                direct_page4 = (value28 << 8) | value27;
            } else {
                uint16_t value29 = BUS16(c, 0x004212);
                bool m_flag2;
                uint8_t a_hi6;
                uint16_t direct_page3;
                if ((value29 & 0x80) == 0) {
                    BUS16_SET(c, 0x004375, 0);
                    uint8_t value30 = RAM8(0x0000 + sp0 - 0x0A);
                    uint8_t value31 = RAM8(0x0000 + sp0 - 9);
                    uint16_t value32 = RAM16(0x821C);
                    RAM16_SET(0x821C, (uint16_t)(((uint16_t)(((value31 << 8) | value30) - value32) ^ 0xFFFF) + 1));
                    uint8_t value33 = RAM8(0x0000 + sp0 - 8);
                    uint8_t value34 = RAM8(0x0000 + sp0 - 7);
                    m_flag2 = 0;
                    a_hi6 = (uint16_t)(((uint16_t)(((value31 << 8) | value30) - value32) ^ 0xFFFF) + 1) >> 8;
                    direct_page3 = (value34 << 8) | value33;
                } else {
                    uint16_t value35 = BUS16(c, 0x004375);
                    bool m_flag;
                    uint8_t a_hi5;
                    uint16_t direct_page2;
                    if (value35 != 0) {
                        BUS16_SET(c, 0x004375, 0);
                        uint8_t value36 = RAM8(0x0000 + sp0 - 0x0A);
                        uint8_t value37 = RAM8(0x0000 + sp0 - 9);
                        uint16_t value38 = RAM16(0x821C);
                        RAM16_SET(0x821C, (uint16_t)(((uint16_t)(((value37 << 8) | value36) - value38) ^ 0xFFFF) + 1));
                        uint8_t value39 = RAM8(0x0000 + sp0 - 8);
                        uint8_t value40 = RAM8(0x0000 + sp0 - 7);
                        m_flag = 0;
                        a_hi5 = (uint16_t)(((uint16_t)(((value37 << 8) | value36) - value38) ^ 0xFFFF) + 1) >> 8;
                        direct_page2 = (value40 << 8) | value39;
                    } else {
                        uint8_t value41 = RAM8(0x0000 + sp0 - 0x0A);
                        uint8_t value42 = RAM8(0x0000 + sp0 - 9);
                        if ((uint16_t)(((value42 << 8) | value41) - 1) != 0) {
                            a1 = (uint8_t)(((value42 << 8) | value41) - 1);
                            a_hi1 = (uint16_t)(((value42 << 8) | value41) - 1) >> 8;
                            x1 = (value10 << 8) | value9;
                            y1 = (uint16_t)(((value20 << 8) | value19) + 2);
                            direct_page = 0x4300;
                            continue;
                        }
                        uint8_t value43 = RAM8(0x0000 + sp0 - 8);
                        uint8_t value44 = RAM8(0x0000 + sp0 - 7);
                        uint8_t value45 = BUS8(c, 0x004212);
                        if ((value45 & 0x80) == 0) {
                            if (RAM8(0x8210) == 0) {
                                RAM8(0x821C)--;
                                BUS8_SET(c, 0x00420B, 0);
                            }
                        }
                        m_flag = 1;
                        a_hi5 = (uint16_t)(((value42 << 8) | value41) - 1) >> 8;
                        direct_page2 = (value44 << 8) | value43;
                    }
                    m_flag2 = m_flag;
                    a_hi6 = a_hi5;
                    direct_page3 = direct_page2;
                }
                m_flag3 = m_flag2;
                a_hi7 = a_hi6;
                direct_page4 = direct_page3;
            }
            a_hi1 = a_hi7;
            x1 = (value10 << 8) | value9;
            y1 = (uint16_t)(((value20 << 8) | value19) + 2);
            direct_page = direct_page4;
            break;
        }
        a_hi8 = a_hi1;
        x2 = x1;
        y2 = y1;
        direct_page5 = direct_page;
    } else {
        a_hi8 = value >> 8;
        x2 = x;
        y2 = y;
        direct_page5 = (uint16_t)(sp0 - 6);
    }
    uint8_t value47 = RAM8(0x0000 + sp0 - 6);
    uint8_t value50 = RAM8(0x0000 + sp0 - 3);
    uint8_t value51 = RAM8(0x0000 + sp0 - 2);
    uint8_t value52 = RAM8(0x0000 + sp0 - 1);
    uint8_t value53 = RAM8(0x0000 + sp0);
    r->a = (a_hi8 << 8) | value50;
    r->x = x2;
    r->y = y2;
    r->c = value51 & 0x01;
    r->z = ((value53 << 8) | value52) == 0;
    r->n = ((value53 << 8) | value52) & 0x8000;
    r->v = value51 & 0x40;
    r->mf = value51 & 0x20;
    r->xf = value51 & 0x10;
    r->db = value47;
    r->dp = (value53 << 8) | value52;
    r->i = value51 & 0x04;
    r->d = value51 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12A80, SOM_RTS, "gen", drain_spell_entity_transfer_queue_to_ppu, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 15, 1, 0, 256, 127)

#include "som_c.h"

/* C20040 initialize_boss_resources_from_cache   [class B, 174 bytes, 84 instructions]
 * Source: src/rom/initialize_boss_resources_from_cache.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYV.
 */
static void initialize_boss_resources_from_cache(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = dp >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    r->a = 0x61BA;
    r->z = 0;
    r->n = 0;
    r->dp = 0x0200;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0054, 0xC221B7); GUARD_JSR(c, sp_call, 0x0054); } /* interpret_boss_loader_commands */
    r->sp += 4;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t x_ret = r->x;
    BUS16_SET(c, (db_ret << 0x10) + 0x0FAE, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x0352, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x0351, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x0360, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x0362, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x02CD, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x02CF, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x02D1, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x02D3, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x02D5, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x02D7, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x0FA4, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x0364, 0);
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC5));
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC5));
    uint16_t y1 = value;
    for (;;) {
        BUS16_SET(c, (db_ret << 0x10) + 0x033F + y1, value2);
        y1 = (uint16_t)(y1 + 2);
        if (!(y1 != 0x10)) break;
    }
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC5));
    uint8_t a1 = (uint8_t)value2;
    uint8_t a_hi1 = value2 >> 8;
    uint16_t x1 = x_ret;
    uint16_t y2 = value3;
    uint8_t data_bank = db_ret;
    uint16_t direct_page = dp_ret;
    for (;;) {
        BUS16_SET(c, (data_bank << 0x10) + 0x0FA6, y2);
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(direct_page + 0xC5));
        uint8_t value5 = BUS8_RDP(c, (data_bank << 0x10) + 0xC80D + y2);
        if (value5 != 0) {
            bool m_flag4;
            uint8_t a_hi5;
            uint16_t x5;
            uint16_t y6;
            uint8_t data_bank5;
            uint16_t direct_page5;
            if (value5 < 0x57) {
                m_flag4 = 1;
                a_hi5 = value4 >> 8;
                x5 = x1;
                y6 = y2;
                data_bank5 = data_bank;
                direct_page5 = direct_page;
            } else {
                bool m_flag3;
                uint8_t a_hi4;
                uint16_t x4;
                uint16_t y5;
                uint8_t data_bank4;
                uint16_t direct_page4;
                if (value5 >= 0x80) {
                    m_flag3 = 1;
                    a_hi4 = value4 >> 8;
                    x4 = x1;
                    y5 = y2;
                    data_bank4 = data_bank;
                    direct_page4 = direct_page;
                } else {
                    BUS8_SET(c, (uint16_t)(direct_page + 0x1E), value5);
                    uint8_t value6 = BUS8_RDP(c, (data_bank << 0x10) + 0xC808 + y2);
                    uint8_t value7 = BUS8_RDP(c, (data_bank << 0x10) + 0xCF00 + ((value4 >> 8 << 8) | value6));
                    BUS8_SET(c, (uint16_t)(direct_page + 0x1A), value7 & 0x0F);
                    uint8_t value8 = BUS8_RDP(c, (data_bank << 0x10) + 0xC809 + y2);
                    BUS8_SET(c, (uint16_t)(direct_page + 0x1C), (value8 & 0xF0) >> 4);
                    uint8_t value9 = BUS8_RDP(c, (uint16_t)(direct_page + 0x1A));
                    uint8_t value10 = BUS8_RDP(c, (uint16_t)(direct_page + 0x1C));
                    bool m_flag2;
                    uint8_t a_hi3;
                    uint16_t x3;
                    uint16_t y4;
                    uint8_t data_bank3;
                    uint16_t direct_page3;
                    if (value9 < value10) {
                        m_flag2 = 1;
                        a_hi3 = value4 >> 8;
                        x3 = (value4 >> 8 << 8) | value6;
                        y4 = y2;
                        data_bank3 = data_bank;
                        direct_page3 = direct_page;
                    } else {
                        uint8_t value11 = BUS8_RDP(c, (data_bank << 0x10) + 0xC809 + y2);
                        uint8_t value12 = BUS8_RDP(c, (uint16_t)(direct_page + 0x1A));
                        bool m_flag;
                        uint8_t a_hi2;
                        uint16_t x2;
                        uint16_t y3;
                        uint8_t data_bank2;
                        uint16_t direct_page2;
                        if ((value11 & 0x0F) < value12) {
                            m_flag = 1;
                            a_hi2 = value4 >> 8;
                            x2 = (value4 >> 8 << 8) | value6;
                            y3 = y2;
                            data_bank2 = data_bank;
                            direct_page2 = direct_page;
                        } else {
                            uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page + 0x1E));
                            BUS16_SET(c, (data_bank << 0x10) + 0x0FA2, (value4 >> 8 << 8) | value13);
                            uint16_t value14 = BUS16(c, 0xC200EE + (uint16_t)((uint16_t)(((value4 >> 8 << 8) | value13) - 0x54) << 1));
                            RAM8(0x0000 + sp0 - 4) = y2 >> 8;
                            RAM8(0x0000 + sp0 - 5) = (uint8_t)y2;
                            r->a = value14;
                            r->x = (uint16_t)((uint16_t)(((value4 >> 8 << 8) | value13) - 0x54) << 1);
                            r->y = y2;
                            r->c = (uint16_t)(((value4 >> 8 << 8) | value13) - 0x54) & 0x8000;
                            r->z = value14 == 0;
                            r->n = value14 & 0x8000;
                            r->v = ((((value4 >> 8 << 8) | value13) ^ 0x54) & (((value4 >> 8 << 8) | value13) ^ (uint16_t)(((value4 >> 8 << 8) | value13) - 0x54)) & 0x8000) != 0;
                            r->mf = 0;
                            r->xf = 0;
                            r->db = data_bank;
                            r->dp = direct_page;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x00DB, 0xC221B7); GUARD_JSR(c, sp_call, 0x00DB); } /* interpret_boss_loader_commands */
                            r->sp += 6;
                            uint16_t dp_ret2 = r->dp;
                            uint8_t db_ret2 = r->db;
                            uint16_t a_all2 = r->a;
                            uint16_t x_ret2 = r->x;
                            uint8_t value15 = RAM8(0x0000 + sp0 - 5);
                            uint8_t value16 = RAM8(0x0000 + sp0 - 4);
                            uint16_t value17 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0FA4);
                            BUS16_RMW_SET(c, (db_ret2 << 0x10) + 0x0FA4, (uint16_t)(value17 + 1));
                            m_flag = 0;
                            a_hi2 = a_all2 >> 8;
                            x2 = x_ret2;
                            y3 = (value16 << 8) | value15;
                            data_bank2 = db_ret2;
                            direct_page2 = dp_ret2;
                        }
                        m_flag2 = m_flag;
                        a_hi3 = a_hi2;
                        x3 = x2;
                        y4 = y3;
                        data_bank3 = data_bank2;
                        direct_page3 = direct_page2;
                    }
                    m_flag3 = m_flag2;
                    a_hi4 = a_hi3;
                    x4 = x3;
                    y5 = y4;
                    data_bank4 = data_bank3;
                    direct_page4 = direct_page3;
                }
                m_flag4 = m_flag3;
                a_hi5 = a_hi4;
                x5 = x4;
                y6 = y5;
                data_bank5 = data_bank4;
                direct_page5 = direct_page4;
            }
            a1 = (uint8_t)(y6 + 0x10);
            a_hi1 = (uint16_t)(y6 + 0x10) >> 8;
            x1 = x5;
            y2 = (uint16_t)(y6 + 0x10);
            data_bank = data_bank5;
            direct_page = direct_page5;
            continue;
        }
        a1 = value5;
        a_hi1 = value4 >> 8;
        break;
    }
    uint8_t value18 = RAM8(0x0000 + sp0 - 3);
    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
    uint8_t value21 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y2;
    r->v = value21 & 0x40;
    r->mf = value21 & 0x20;
    r->xf = value21 & 0x10;
    r->db = value18;
    r->dp = (value20 << 8) | value19;
    r->i = value21 & 0x04;
    r->d = value21 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC20040, SOM_RTL, "gen", initialize_boss_resources_from_cache, 0, L_A | L_B | L_X | L_Y | L_V, 6, 0, 0, 174, 84)

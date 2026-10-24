#include "som_c.h"

/* D3FB3F launch_spell_entity_trail_child   [class B, 119 bytes, 63 instructions]
 * Source: src/rom/launch_spell_entity_trail_child.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void launch_spell_entity_trail_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_fb60 = 0;
    uint8_t a_hi_fb60 = 0;
    uint16_t x_fb60 = 0;
    uint16_t direct_page_fb60 = 0;
    uint8_t a_hi_fb90 = 0;
    uint16_t direct_page_fb90 = 0;
    uint8_t data_bank_fb90 = 0;
    uint8_t a_hi_fb902 = 0;
    uint16_t direct_page_fb902 = 0;
    uint8_t data_bank_fb902 = 0;
    uint8_t a_hi_fb903 = 0;
    uint16_t direct_page_fb903 = 0;
    uint8_t data_bank_fb903 = 0;
    uint8_t a_hi_fb904 = 0;
    uint16_t direct_page_fb904 = 0;
    uint8_t data_bank_fb904 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), x);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), RAM16(0x014C + x) & 3);
    uint16_t value2 = RAM16(0x0150 + x);
    if ((uint16_t)(value2 + 1) < 0x14) {
        a_fb60 = (uint8_t)(value2 + 1);
        a_hi_fb60 = (uint16_t)(value2 + 1) >> 8;
        x_fb60 = x;
        direct_page_fb60 = (uint16_t)(sp0 - 9);
        goto shared_FB60;
    }
    a_fb60 = 0;
    a_hi_fb60 = 0;
    x_fb60 = x;
    direct_page_fb60 = (uint16_t)(sp0 - 9);
    shared_FB60:;
    RAM16_SET(0x0150 + x_fb60, (a_hi_fb60 << 8) | a_fb60);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(direct_page_fb60 + 1));
    BUS16_SET(c, (uint16_t)(direct_page_fb60 + 5), (uint16_t)((uint16_t)(((a_hi_fb60 << 8) | a_fb60) << 4) + value3));
    RAM16_SET(0x014E + x_fb60, (uint16_t)(RAM16(0x014E + x_fb60) - 1));
    if (RAM16(0x014E + x_fb60) != 0) {
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(direct_page_fb60 + 3));
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page_fb60 + 3));
        BUS16_SET(c, (uint16_t)(direct_page_fb60 + 3), (uint16_t)(value4 << 2) | value5);
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(direct_page_fb60 + 5));
        RAM16_SET(0x000A + value6, (uint16_t)(value4 << 2) | value5);
        a_hi_fb90 = ((uint16_t)(value4 << 2) | value5) >> 8;
        direct_page_fb90 = direct_page_fb60;
        data_bank_fb90 = 0x7E;
        goto shared_FB90;
    }
    uint16_t value7 = RAM16(0x014E + x_fb60);
    r->a = (uint16_t)((uint16_t)(((a_hi_fb60 << 8) | a_fb60) << 4) + value3);
    r->x = x_fb60;
    r->c = (uint16_t)(((a_hi_fb60 << 8) | a_fb60) << 4) + value3 > 0xFFFF;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->v = (((uint16_t)(((a_hi_fb60 << 8) | a_fb60) << 4) ^ (uint16_t)((uint16_t)(((a_hi_fb60 << 8) | a_fb60) << 4) + value3)) & (value3 ^ (uint16_t)((uint16_t)(((a_hi_fb60 << 8) | a_fb60) << 4) + value3)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_fb60;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFB73, 0xD3FA1D); GUARD_JSR(c, sp_call, 0xFB73); } /* select_spell_entity_trail_turn_direction */
    r->sp += 9;
    uint16_t dp_ret = r->dp;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (m_ret) {
        uint8_t value8 = RAM8(0x014C + x_fb60);
        if (x_ret) {
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
            RAM8(0x000A + value9) = value8;
            BUS8_SET(c, (uint16_t)(dp_ret + 3), value8);
            r->a = (a_all >> 8 << 8) | value8;
            r->x = (uint8_t)x_fb60;
            r->y = value9;
            r->z = value9 == 0;
            r->n = value9 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFB80, 0xD3FA6F); GUARD_JSR(c, sp_call, 0xFB80); } /* adjust_spell_entity_trail_velocity */
            r->sp += 9;
            uint8_t db_ret = r->db;
            bool m_ret2 = r->mf;
            bool x_ret2 = r->xf;
            uint16_t a_all2 = r->a;
            if (m_ret2) {
                if (x_ret2) {
                    a_hi_fb902 = a_all2 >> 8;
                    direct_page_fb902 = dp_ret;
                    data_bank_fb902 = db_ret;
                    goto shared_FB90_1;
                } else {
                    a_hi_fb903 = a_all2 >> 8;
                    direct_page_fb903 = dp_ret;
                    data_bank_fb903 = db_ret;
                    goto shared_FB90_2;
                }
            } else {
                if (x_ret2) {
                    a_hi_fb904 = a_all2 >> 8;
                    direct_page_fb904 = dp_ret;
                    data_bank_fb904 = db_ret;
                    goto shared_FB90_3;
                } else {
                    a_hi_fb90 = a_all2 >> 8;
                    direct_page_fb90 = dp_ret;
                    data_bank_fb90 = db_ret;
                    goto shared_FB90;
                }
            }
        } else {
            uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
            RAM8(0x000A + value10) = value8;
            BUS8_SET(c, (uint16_t)(dp_ret + 3), value8);
            r->a = (a_all >> 8 << 8) | value8;
            r->y = value10;
            r->z = value10 == 0;
            r->n = value10 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFB80, 0xD3FA6F); GUARD_JSR(c, sp_call, 0xFB80); } /* adjust_spell_entity_trail_velocity */
            r->sp += 9;
            uint8_t db_ret2 = r->db;
            bool m_ret3 = r->mf;
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            if (m_ret3) {
                if (x_ret4) {
                    a_hi_fb902 = a_all3 >> 8;
                    direct_page_fb902 = dp_ret;
                    data_bank_fb902 = db_ret2;
                    goto shared_FB90_1;
                } else {
                    a_hi_fb903 = a_all3 >> 8;
                    direct_page_fb903 = dp_ret;
                    data_bank_fb903 = db_ret2;
                    goto shared_FB90_2;
                }
            } else {
                if (x_ret4) {
                    a_hi_fb904 = a_all3 >> 8;
                    direct_page_fb904 = dp_ret;
                    data_bank_fb904 = db_ret2;
                    goto shared_FB90_3;
                } else {
                    a_hi_fb90 = a_all3 >> 8;
                    direct_page_fb90 = dp_ret;
                    data_bank_fb90 = db_ret2;
                    goto shared_FB90;
                }
            }
        }
    } else {
        uint16_t value11 = RAM16(0x014C + x_fb60);
        if (x_ret) {
            uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
            RAM16_SET(0x000A + value12, value11);
            BUS16_SET(c, (uint16_t)(dp_ret + 3), value11);
            r->a = value11;
            r->x = (uint8_t)x_fb60;
            r->y = value12;
            r->z = value12 == 0;
            r->n = value12 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFB80, 0xD3FA6F); GUARD_JSR(c, sp_call, 0xFB80); } /* adjust_spell_entity_trail_velocity */
            r->sp += 9;
            uint8_t db_ret3 = r->db;
            bool m_ret4 = r->mf;
            bool x_ret6 = r->xf;
            uint16_t a_all4 = r->a;
            if (m_ret4) {
                if (x_ret6) {
                    a_hi_fb902 = a_all4 >> 8;
                    direct_page_fb902 = dp_ret;
                    data_bank_fb902 = db_ret3;
                    goto shared_FB90_1;
                } else {
                    a_hi_fb903 = a_all4 >> 8;
                    direct_page_fb903 = dp_ret;
                    data_bank_fb903 = db_ret3;
                    goto shared_FB90_2;
                }
            } else {
                if (x_ret6) {
                    a_hi_fb904 = a_all4 >> 8;
                    direct_page_fb904 = dp_ret;
                    data_bank_fb904 = db_ret3;
                    goto shared_FB90_3;
                } else {
                    a_hi_fb90 = a_all4 >> 8;
                    direct_page_fb90 = dp_ret;
                    data_bank_fb90 = db_ret3;
                    goto shared_FB90;
                }
            }
        } else {
            uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
            RAM16_SET(0x000A + value13, value11);
            BUS16_SET(c, (uint16_t)(dp_ret + 3), value11);
            r->a = value11;
            r->y = value13;
            r->z = value13 == 0;
            r->n = value13 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFB80, 0xD3FA6F); GUARD_JSR(c, sp_call, 0xFB80); } /* adjust_spell_entity_trail_velocity */
            r->sp += 9;
            uint8_t db_ret4 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret8 = r->xf;
            uint16_t a_all5 = r->a;
            if (m_ret5) {
                if (x_ret8) {
                    a_hi_fb902 = a_all5 >> 8;
                    direct_page_fb902 = dp_ret;
                    data_bank_fb902 = db_ret4;
                    goto shared_FB90_1;
                } else {
                    a_hi_fb903 = a_all5 >> 8;
                    direct_page_fb903 = dp_ret;
                    data_bank_fb903 = db_ret4;
                    goto shared_FB90_2;
                }
            } else {
                if (x_ret8) {
                    a_hi_fb904 = a_all5 >> 8;
                    direct_page_fb904 = dp_ret;
                    data_bank_fb904 = db_ret4;
                    goto shared_FB90_3;
                } else {
                    a_hi_fb90 = a_all5 >> 8;
                    direct_page_fb90 = dp_ret;
                    data_bank_fb90 = db_ret4;
                    goto shared_FB90;
                }
            }
        }
    }
    shared_FB90:;
    uint16_t value14 = BUS16_RDP(c, (uint16_t)(direct_page_fb90 + 3));
    uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page_fb90 + 3));
    uint16_t value16 = BUS16_RDP(c, (uint16_t)(direct_page_fb90 + 5));
    BUS16_SET(c, (data_bank_fb90 << 0x10) + 6 + value16, (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value14 << 1) + value15) << 2) + 0x055A));
    BUS16_SET(c, (data_bank_fb90 << 0x10) + 0x0C + value16, 6);
    uint16_t value17 = BUS16_RDP(c, (uint16_t)(direct_page_fb90 + 1));
    uint8_t value18 = RAM8(0x0000 + sp0 - 2);
    uint8_t value19 = RAM8(0x0000 + sp0 - 1);
    uint8_t value20 = RAM8(0x0000 + sp0);
    r->x = value17;
    r->y = value16;
    r->mf = value18 & 0x20;
    r->xf = value18 & 0x10;
    r->db = data_bank_fb90;
    r->dp = (value20 << 8) | value19;
    r->i = value18 & 0x04;
    r->d = value18 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_FB90_1:;
    uint8_t value21 = BUS8_RDP(c, (uint16_t)(direct_page_fb902 + 3));
    uint8_t value22 = BUS8_RDP(c, (uint16_t)(direct_page_fb902 + 3));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_FB90_2:;
    uint8_t value23 = BUS8_RDP(c, (uint16_t)(direct_page_fb903 + 3));
    uint8_t value24 = BUS8_RDP(c, (uint16_t)(direct_page_fb903 + 3));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_FB90_3:;
    uint16_t value25 = BUS16_RDP(c, (uint16_t)(direct_page_fb904 + 3));
    uint16_t value26 = BUS16_RDP(c, (uint16_t)(direct_page_fb904 + 3));
    uint8_t value27 = BUS8_RDP(c, (uint16_t)(direct_page_fb904 + 5));
    BUS16_SET(c, (data_bank_fb904 << 0x10) + 6 + value27, (uint16_t)((uint16_t)((uint16_t)((uint16_t)(value25 << 1) + value26) << 2) + 0x055A));
    BUS16_SET(c, (data_bank_fb904 << 0x10) + 0x0C + value27, 6);
    uint8_t value28 = BUS8_RDP(c, (uint16_t)(direct_page_fb904 + 1));
    uint8_t value29 = RAM8(0x0000 + sp0 - 2);
    uint8_t value30 = RAM8(0x0000 + sp0 - 1);
    uint8_t value31 = RAM8(0x0000 + sp0);
    r->x = value28;
    r->y = value27;
    r->mf = value29 & 0x20;
    r->xf = value29 & 0x10;
    r->db = data_bank_fb904;
    r->dp = (value31 << 8) | value30;
    r->i = value29 & 0x04;
    r->d = value29 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FB3F, SOM_RTS, "gen", launch_spell_entity_trail_child, 0, L_X | L_Y, 9, 1, 0, 119, 63)

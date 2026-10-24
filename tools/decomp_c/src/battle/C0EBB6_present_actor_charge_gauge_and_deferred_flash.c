#include "som_c.h"

/* C0EBB6 present_actor_charge_gauge_and_deferred_flash   [class B, 251 bytes, 113 instructions]
 * Source: src/rom/present_actor_charge_gauge_and_deferred_flash.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void present_actor_charge_gauge_and_deferred_flash(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = a;
    RAM16_SET(0x0A56 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0x2817);
    uint8_t value = RAM8(0x0000 + sp0);
    if (value != 0) {
        BUS8_SET(c, 0x004202, value);
        BUS8_SET(c, 0x004203, 0x64);
        RAM8(0x0000) = x >> 9;
        uint8_t value2 = RAM8(0x00F4);
        uint8_t value3 = RAM8(0x0000);
        if ((value2 & 3) == value3) {
            uint8_t value4 = RAM8(ACTOR_AGILITY + x);
            RAM8(0x0000) = ((uint8_t)(0x64 - value4) >> 1) + 0x32;
            uint16_t value5 = BUS16(c, 0x004216);
            BUS16_SET(c, 0x004204, value5);
            BUS8_SET(c, 0x004206, RAM8(0x0000));
            RAM8(0x0A50 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = 0x14;
            RAM8(0x0A54 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = 0x15;
            r->a = (value5 >> 8 << 8) | 0x15;
            r->y = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3);
            r->c = ((uint8_t)(0x64 - value4) >> 1) + 0x32 > 0xFF;
            r->z = 0;
            r->n = 0;
            r->v = ((((uint8_t)(0x64 - value4) >> 1) ^ ((uint8_t)(0x64 - value4) >> 1) + 0x32) & (((uint8_t)(0x64 - value4) >> 1) + 0x32 ^ 0x32) & 0x80) != 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEC4C, 0xC0ECB1); GUARD_JSR(c, sp_call, 0xEC4C); } /* convert_hardware_charge_percentage_to_native_three_glyphs */
            RAM8(0x0A51 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = (uint8_t)(RAM8(0x0002) + 8);
            RAM8(0x0A52 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = (uint8_t)(RAM8(0x0001) + 8);
            uint8_t value9 = RAM8(0x0000);
            RAM8(0x0A53 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = (uint8_t)(value9 + 8);
            uint16_t value10 = RAM16(0x1D04);
            uint8_t a_hi1;
            if ((value10 & 0x20) != 0) {
                uint16_t value11 = BUS16(c, 0xD27E00);
                RAM16_SET(0xDE0C + ((uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1), value11);
                uint16_t value12 = BUS16(c, 0xD27E02);
                RAM16_SET(0xDE0E + ((uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1), value12);
                a_hi1 = value12 >> 8;
            } else {
                uint16_t value13 = BUS16(c, 0xD27E00);
                RAM16_SET(0x060C + ((uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1), value13);
                uint16_t value14 = BUS16(c, 0xD27E02);
                RAM16_SET(0x060E + ((uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1), value14);
                a_hi1 = value14 >> 8;
            }
            bool m_flag4;
            bool x_flag4;
            uint8_t a_hi5;
            uint16_t y4;
            bool carry4;
            bool overflow4;
            uint8_t data_bank4;
            uint16_t direct_page4;
            if (x >= 0x0600) {
                m_flag4 = 1;
                x_flag4 = 0;
                a_hi5 = a_hi1;
                y4 = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1;
                carry4 = x >= 0x0600;
                overflow4 = ((value9 ^ (uint8_t)(value9 + 8)) & ((uint8_t)(value9 + 8) ^ 8) & 0x80) != 0;
                data_bank4 = 0x7E;
                direct_page4 = 0;
            } else {
                uint8_t value15 = RAM8(0xE02C + x);
                bool m_flag3;
                bool x_flag3;
                uint8_t a_hi4;
                uint16_t y3;
                bool carry3;
                bool overflow3;
                uint8_t data_bank3;
                uint16_t direct_page3;
                if (value15 == 0) {
                    m_flag3 = 1;
                    x_flag3 = 0;
                    a_hi4 = a_hi1;
                    y3 = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1;
                    carry3 = x >= 0x0600;
                    overflow3 = ((value9 ^ (uint8_t)(value9 + 8)) & ((uint8_t)(value9 + 8) ^ 8) & 0x80) != 0;
                    data_bank3 = 0x7E;
                    direct_page3 = 0;
                } else {
                    uint8_t value16 = RAM8(ACTOR_WEAPON_GAUGE + x);
                    bool m_flag2;
                    bool x_flag2;
                    uint8_t a_hi3;
                    uint16_t y2;
                    bool carry2;
                    bool overflow2;
                    uint8_t data_bank2;
                    uint16_t direct_page2;
                    if (value16 < 2) {
                        m_flag2 = 1;
                        x_flag2 = 0;
                        a_hi3 = a_hi1;
                        y2 = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1;
                        carry2 = value16 >= 2;
                        overflow2 = ((value9 ^ (uint8_t)(value9 + 8)) & ((uint8_t)(value9 + 8) ^ 8) & 0x80) != 0;
                        data_bank2 = 0x7E;
                        direct_page2 = 0;
                    } else {
                        uint8_t value17 = RAM8(0xE100 + x);
                        bool m_flag;
                        bool x_flag;
                        uint8_t a_hi2;
                        uint16_t y1;
                        bool carry1;
                        bool overflow1;
                        uint8_t data_bank;
                        uint16_t direct_page;
                        if (value17 & 0x80) {
                            m_flag = 1;
                            x_flag = 0;
                            a_hi2 = a_hi1;
                            y1 = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1;
                            carry1 = value16 >= 2;
                            overflow1 = ((value9 ^ (uint8_t)(value9 + 8)) & ((uint8_t)(value9 + 8) ^ 8) & 0x80) != 0;
                            data_bank = 0x7E;
                            direct_page = 0;
                        } else {
                            r->a = (a_hi1 << 8) | value17;
                            r->y = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 1;
                            r->c = 0;
                            r->z = value17 == 0;
                            r->n = value17 & 0x80;
                            r->v = ((value9 ^ (uint8_t)(value9 + 8)) & ((uint8_t)(value9 + 8) ^ 8) & 0x80) != 0;
                            r->mf = 1;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSL(c, 0xECAF, 0x01CA04); GUARD_JSL(c, sp_call, 0xECAF); } /* prepare_or_restore_actor_attack_palette */
                            uint16_t dp_ret = r->dp;
                            uint8_t db_ret = r->db;
                            bool m_ret = r->mf;
                            bool x_ret = r->xf;
                            uint16_t a_all2 = r->a;
                            uint16_t y_ret = r->y;
                            bool carry_ret2 = r->c;
                            bool overflow_ret2 = r->v;
                            m_flag = m_ret;
                            x_flag = x_ret;
                            a_hi2 = a_all2 >> 8;
                            y1 = y_ret;
                            carry1 = carry_ret2;
                            overflow1 = overflow_ret2;
                            data_bank = db_ret;
                            direct_page = dp_ret;
                        }
                        m_flag2 = m_flag;
                        x_flag2 = x_flag;
                        a_hi3 = a_hi2;
                        y2 = y1;
                        carry2 = carry1;
                        overflow2 = overflow1;
                        data_bank2 = data_bank;
                        direct_page2 = direct_page;
                    }
                    m_flag3 = m_flag2;
                    x_flag3 = x_flag2;
                    a_hi4 = a_hi3;
                    y3 = y2;
                    carry3 = carry2;
                    overflow3 = overflow2;
                    data_bank3 = data_bank2;
                    direct_page3 = direct_page2;
                }
                m_flag4 = m_flag3;
                x_flag4 = x_flag3;
                a_hi5 = a_hi4;
                y4 = y3;
                carry4 = carry3;
                overflow4 = overflow3;
                data_bank4 = data_bank3;
                direct_page4 = direct_page3;
            }
            r->a = (a_hi5 << 8) | a;
            r->y = y4;
            r->c = carry4;
            r->v = overflow4;
            r->mf = m_flag4;
            r->xf = x_flag4;
            r->db = data_bank4;
            r->dp = direct_page4;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = (r->a & 0x00FF) | ((uint8_t)x << 8);
        r->y = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3);
        r->c = (value2 & 3) >= value3;
        RETURN_RTS(c);
    }
    uint8_t value18 = RAM8(0xE063 + x);
    RAM8(0xE063 + x) = (uint8_t)(value18 + 0x10);
    if (((uint8_t)(value18 + 0x10) & 0xF0) == 0) {
        RAM8(0x0A50 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = (uint8_t)(value18 + 0x10) & 0xF0;
        RAM8(0x0A51 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = (uint8_t)(value18 + 0x10) & 0xF0;
        RAM8(0x0A52 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = (uint8_t)(value18 + 0x10) & 0xF0;
        RAM8(0x0A53 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = (uint8_t)(value18 + 0x10) & 0xF0;
        RAM8(0x0A54 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3)) = (uint8_t)(value18 + 0x10) & 0xF0;
        r->a = 0x28 << 8 | ((uint8_t)(value18 + 0x10) & 0xF0);
        r->y = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3);
        r->c = 1;
        r->z = ((uint8_t)(value18 + 0x10) & 0xF0) == 0;
        r->n = (uint8_t)(value18 + 0x10) & 0xF0 & 0x80;
        r->v = ((value18 ^ (uint8_t)(value18 + 0x10)) & ((uint8_t)(value18 + 0x10) ^ 0x10) & 0x80) != 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEBFB, 0x01CA04); GUARD_JSL(c, sp_call, 0xEBFB); } /* prepare_or_restore_actor_attack_palette */
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        uint16_t a_all3 = r->a;
        if (m_ret2) {
            uint8_t value19 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE02C + x);
            if (value19 != 0) {
                r->a = (a_all3 >> 8 << 8) | 0xA6;
                r->z = 0;
                r->n = 1;
                r->mf = 1;
                TAIL_CALL(c, 0xC0BB11, SOM_RTS); /* external */
            }
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value20 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xE02C + x);
            if (value20 != 0) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
            r->a = value20;
            r->mf = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    RAM8(ACTOR_WEAPON_GAUGE + x)++;
    uint8_t a_hi6;
    uint16_t y5;
    bool overflow5;
    if (((uint8_t)(value18 + 0x10) & 0xF0) != 0x40) {
        a_hi6 = 0x28;
        y5 = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3);
        overflow5 = ((value18 ^ (uint8_t)(value18 + 0x10)) & ((uint8_t)(value18 + 0x10) ^ 0x10) & 0x80) != 0;
    } else {
        RAM8(0x0000 + sp0) = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3) >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((((uint8_t)x << 8) | (x >> 8)) << 3);
        r->a = 0x28 << 8 | ((uint8_t)(value18 + 0x10) & 0xF0);
        r->y = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3);
        r->c = ((uint8_t)(value18 + 0x10) & 0xF0) >= 0x40;
        r->z = ((uint8_t)(value18 + 0x10) & 0xF0) == 0x40;
        r->n = (uint8_t)(((uint8_t)(value18 + 0x10) & 0xF0) - 0x40) & 0x80;
        r->v = ((value18 ^ (uint8_t)(value18 + 0x10)) & ((uint8_t)(value18 + 0x10) ^ 0x10) & 0x80) != 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEBE2, 0x01C9F1); GUARD_JSL(c, sp_call, 0xEBE2); } /* seed_native_charge_flash_palette_if_status_bit_eight */
        r->sp += 2;
        uint16_t a_all4 = r->a;
        bool overflow_ret4 = r->v;
        uint8_t value21 = RAM8(0x0000 + sp0 - 1);
        uint8_t value22 = RAM8(0x0000 + sp0);
        a_hi6 = a_all4 >> 8;
        y5 = (value22 << 8) | value21;
        overflow5 = overflow_ret4;
    }
    BUS8_SET(c, 0x004202, 0);
    BUS8_SET(c, 0x004203, 0x64);
    RAM8(0x0000) = x >> 9;
    uint8_t value23 = RAM8(0x00F4);
    uint8_t value24 = RAM8(0x0000);
    if ((value23 & 3) == value24) {
        uint8_t value25 = RAM8(ACTOR_AGILITY + x);
        RAM8(0x0000) = ((uint8_t)(0x64 - value25) >> 1) + 0x32;
        uint16_t value26 = BUS16(c, 0x004216);
        BUS16_SET(c, 0x004204, value26);
        BUS8_SET(c, 0x004206, RAM8(0x0000));
        RAM8(0x0A50 + y5) = 0x14;
        RAM8(0x0A54 + y5) = 0x15;
        r->a = (value26 >> 8 << 8) | 0x15;
        r->y = y5;
        r->c = ((uint8_t)(0x64 - value25) >> 1) + 0x32 > 0xFF;
        r->z = 0;
        r->n = 0;
        r->v = ((((uint8_t)(0x64 - value25) >> 1) ^ ((uint8_t)(0x64 - value25) >> 1) + 0x32) & (((uint8_t)(0x64 - value25) >> 1) + 0x32 ^ 0x32) & 0x80) != 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEC4C, 0xC0ECB1); GUARD_JSR(c, sp_call, 0xEC4C); } /* convert_hardware_charge_percentage_to_native_three_glyphs */
        RAM8(0x0A51 + y5) = (uint8_t)(RAM8(0x0002) + 8);
        RAM8(0x0A52 + y5) = (uint8_t)(RAM8(0x0001) + 8);
        uint8_t value30 = RAM8(0x0000);
        RAM8(0x0A53 + y5) = (uint8_t)(value30 + 8);
        uint16_t value31 = RAM16(0x1D04);
        uint8_t a_hi7;
        if ((value31 & 0x20) != 0) {
            uint16_t value32 = BUS16(c, 0xD27E00);
            RAM16_SET(0xDE0C + (y5 >> 1), value32);
            uint16_t value33 = BUS16(c, 0xD27E02);
            RAM16_SET(0xDE0E + (y5 >> 1), value33);
            a_hi7 = value33 >> 8;
        } else {
            uint16_t value34 = BUS16(c, 0xD27E00);
            RAM16_SET(0x060C + (y5 >> 1), value34);
            uint16_t value35 = BUS16(c, 0xD27E02);
            RAM16_SET(0x060E + (y5 >> 1), value35);
            a_hi7 = value35 >> 8;
        }
        bool m_flag8;
        bool x_flag8;
        uint8_t a_hi11;
        uint16_t y9;
        bool carry8;
        bool overflow9;
        uint8_t data_bank8;
        uint16_t direct_page8;
        if (x >= 0x0600) {
            m_flag8 = 1;
            x_flag8 = 0;
            a_hi11 = a_hi7;
            y9 = y5 >> 1;
            carry8 = x >= 0x0600;
            overflow9 = ((value30 ^ (uint8_t)(value30 + 8)) & ((uint8_t)(value30 + 8) ^ 8) & 0x80) != 0;
            data_bank8 = 0x7E;
            direct_page8 = 0;
        } else {
            uint8_t value36 = RAM8(0xE02C + x);
            bool m_flag7;
            bool x_flag7;
            uint8_t a_hi10;
            uint16_t y8;
            bool carry7;
            bool overflow8;
            uint8_t data_bank7;
            uint16_t direct_page7;
            if (value36 == 0) {
                m_flag7 = 1;
                x_flag7 = 0;
                a_hi10 = a_hi7;
                y8 = y5 >> 1;
                carry7 = x >= 0x0600;
                overflow8 = ((value30 ^ (uint8_t)(value30 + 8)) & ((uint8_t)(value30 + 8) ^ 8) & 0x80) != 0;
                data_bank7 = 0x7E;
                direct_page7 = 0;
            } else {
                uint8_t value37 = RAM8(ACTOR_WEAPON_GAUGE + x);
                bool m_flag6;
                bool x_flag6;
                uint8_t a_hi9;
                uint16_t y7;
                bool carry6;
                bool overflow7;
                uint8_t data_bank6;
                uint16_t direct_page6;
                if (value37 < 2) {
                    m_flag6 = 1;
                    x_flag6 = 0;
                    a_hi9 = a_hi7;
                    y7 = y5 >> 1;
                    carry6 = value37 >= 2;
                    overflow7 = ((value30 ^ (uint8_t)(value30 + 8)) & ((uint8_t)(value30 + 8) ^ 8) & 0x80) != 0;
                    data_bank6 = 0x7E;
                    direct_page6 = 0;
                } else {
                    uint8_t value38 = RAM8(0xE100 + x);
                    bool m_flag5;
                    bool x_flag5;
                    uint8_t a_hi8;
                    uint16_t y6;
                    bool carry5;
                    bool overflow6;
                    uint8_t data_bank5;
                    uint16_t direct_page5;
                    if (value38 & 0x80) {
                        m_flag5 = 1;
                        x_flag5 = 0;
                        a_hi8 = a_hi7;
                        y6 = y5 >> 1;
                        carry5 = value37 >= 2;
                        overflow6 = ((value30 ^ (uint8_t)(value30 + 8)) & ((uint8_t)(value30 + 8) ^ 8) & 0x80) != 0;
                        data_bank5 = 0x7E;
                        direct_page5 = 0;
                    } else {
                        r->a = (a_hi7 << 8) | value38;
                        r->y = y5 >> 1;
                        r->c = 0;
                        r->z = value38 == 0;
                        r->n = value38 & 0x80;
                        r->v = ((value30 ^ (uint8_t)(value30 + 8)) & ((uint8_t)(value30 + 8) ^ 8) & 0x80) != 0;
                        r->mf = 1;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSL(c, 0xECAF, 0x01CA04); GUARD_JSL(c, sp_call, 0xECAF); } /* prepare_or_restore_actor_attack_palette */
                        uint16_t dp_ret3 = r->dp;
                        uint8_t db_ret3 = r->db;
                        bool m_ret3 = r->mf;
                        bool x_ret3 = r->xf;
                        uint16_t a_all6 = r->a;
                        uint16_t y_ret4 = r->y;
                        bool carry_ret6 = r->c;
                        bool overflow_ret6 = r->v;
                        m_flag5 = m_ret3;
                        x_flag5 = x_ret3;
                        a_hi8 = a_all6 >> 8;
                        y6 = y_ret4;
                        carry5 = carry_ret6;
                        overflow6 = overflow_ret6;
                        data_bank5 = db_ret3;
                        direct_page5 = dp_ret3;
                    }
                    m_flag6 = m_flag5;
                    x_flag6 = x_flag5;
                    a_hi9 = a_hi8;
                    y7 = y6;
                    carry6 = carry5;
                    overflow7 = overflow6;
                    data_bank6 = data_bank5;
                    direct_page6 = direct_page5;
                }
                m_flag7 = m_flag6;
                x_flag7 = x_flag6;
                a_hi10 = a_hi9;
                y8 = y7;
                carry7 = carry6;
                overflow8 = overflow7;
                data_bank7 = data_bank6;
                direct_page7 = direct_page6;
            }
            m_flag8 = m_flag7;
            x_flag8 = x_flag7;
            a_hi11 = a_hi10;
            y9 = y8;
            carry8 = carry7;
            overflow9 = overflow8;
            data_bank8 = data_bank7;
            direct_page8 = direct_page7;
        }
        r->a = (a_hi11 << 8) | a;
        r->y = y9;
        r->c = carry8;
        r->v = overflow9;
        r->mf = m_flag8;
        r->xf = x_flag8;
        r->db = data_bank8;
        r->dp = direct_page8;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->a = (uint8_t)x << 8 | (value23 & 3);
    r->y = y5;
    r->c = (value23 & 3) >= value24;
    r->v = overflow5;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0EBB6, SOM_RTS, "gen", present_actor_charge_gauge_and_deferred_flash, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 251, 113)

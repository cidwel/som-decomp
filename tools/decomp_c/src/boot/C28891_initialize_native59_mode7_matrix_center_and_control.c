#include "som_c.h"

/* C28891 initialize_native59_mode7_matrix_center_and_control   [class D, 262 bytes, 106 instructions]
 * Source: src/rom/initialize_native59_mode7_matrix_center_and_control.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_native59_mode7_matrix_center_and_control(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    if (r->d) { c->fail = 3; return; } /* binary ADC/SBC: entered with the decimal flag clear */
    uint64_t loop_guard = 0;
    uint8_t a_8918 = 0;
    uint8_t a_hi_8918 = 0;
    uint8_t x_8918 = 0;
    uint8_t y_8918 = 0;
    bool carry_8918 = 0;
    bool overflow_8918 = 0;
    uint16_t direct_page_8918 = 0;
    uint8_t data_bank_8918 = 0;
    bool decimal_8918 = 0;
    uint8_t a_89182 = 0;
    uint8_t a_hi_89182 = 0;
    uint16_t x_89182 = 0;
    uint16_t y_89182 = 0;
    bool carry_89182 = 0;
    bool overflow_89182 = 0;
    uint16_t direct_page_89182 = 0;
    uint8_t data_bank_89182 = 0;
    bool decimal_89182 = 0;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->a = 0x010F;
    r->x = value;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x88A1, 0xC21394); GUARD_JSR(c, sp_call, 0x88A1); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B0 + value, 0);
    RAM16_SET(0x00B2 + value, 0);
    RAM16_SET(0x00B4 + value, RAM16(0x00B8 + value));
    RAM16_SET(0x02D5, 0x30);
    RAM16_SET(0x02D7, 0x20);
    RAM16_SET(0x02D5, 0x30);
    RAM16_SET(0x02D7, 0x20);
    BUS8_SET(c, 0x00211A, 0xC0);
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x00B6 + value3);
    RAM16_SET(0x002B + value3, RAM16(0x002B + value4));
    uint16_t value6 = RAM16(0x0032 + value4);
    RAM16_SET(0x0032 + value3, (uint16_t)(value6 - 0x10));
    r->a = (uint16_t)(value6 - 0x10);
    r->x = value3;
    r->y = value4;
    r->c = value6 >= 0x10;
    r->z = (uint16_t)(value6 - 0x10) == 0;
    r->n = (uint16_t)(value6 - 0x10) & 0x8000;
    r->v = ((value6 ^ 0x10) & (value6 ^ (uint16_t)(value6 - 0x10)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x88E7, 0xC28999); GUARD_JSR(c, sp_call, 0x88E7); } /* dispatch_native59_child_radius_convergence */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret = r->y;
    bool decimal_ret = r->d;
    if (x_ret) {
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        if (m_ret) {
            uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0xB0 + value7);
            r->a = (a_all2 >> 8 << 8) | value8;
            r->x = value7;
            r->y = (uint8_t)y_ret;
            r->z = value8 == 0;
            r->n = value8 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x88EF, 0xC22A60); GUARD_JSR(c, sp_call, 0x88EF); } /* mask_angle_and_derive_native_sine */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret3 = r->xf;
            uint16_t a_all3 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret2 + 0x46), a_all3);
            if (x_ret3) {
                uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x87));
                uint8_t value10 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xB6 + value9);
                uint16_t value11 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB2 + value10);
                uint8_t a1;
                bool carry1;
                bool overflow1;
                if (value11 != 0) {
                    uint16_t value12 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB0 + value9);
                    bool carry_bcd, overflow_bcd;
                    uint16_t sum_bcd = SOM_ADC16_AUTO(decimal_ret, value12, 0x0100, 0, &carry_bcd, &overflow_bcd);
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xB0 + value9, sum_bcd);
                    a1 = 0x0F;
                    carry1 = carry_bcd;
                    overflow1 = overflow_bcd;
                } else {
                    uint16_t value13 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB0 + value9);
                    bool carry_bcd2, overflow_bcd2;
                    uint16_t sum_bcd2 = SOM_ADC16_AUTO(decimal_ret, value13, 0x40, 0, &carry_bcd2, &overflow_bcd2);
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xB0 + value9, sum_bcd2);
                    a1 = 0x1E;
                    carry1 = carry_bcd2;
                    overflow1 = overflow_bcd2;
                }
                a_8918 = a1;
                a_hi_8918 = 0;
                x_8918 = value9;
                y_8918 = value10;
                carry_8918 = carry1;
                overflow_8918 = overflow1;
                direct_page_8918 = dp_ret2;
                data_bank_8918 = db_ret2;
                decimal_8918 = decimal_ret;
                goto shared_8918;
            } else {
                uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x87));
                uint16_t value15 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB6 + value14);
                uint16_t value16 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB2 + value15);
                uint8_t a2;
                bool carry2;
                bool overflow2;
                if (value16 != 0) {
                    uint16_t value17 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB0 + value14);
                    bool carry_bcd3, overflow_bcd3;
                    uint16_t sum_bcd3 = SOM_ADC16_AUTO(decimal_ret, value17, 0x0100, 0, &carry_bcd3, &overflow_bcd3);
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xB0 + value14, sum_bcd3);
                    a2 = 0x0F;
                    carry2 = carry_bcd3;
                    overflow2 = overflow_bcd3;
                } else {
                    uint16_t value18 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xB0 + value14);
                    bool carry_bcd4, overflow_bcd4;
                    uint16_t sum_bcd4 = SOM_ADC16_AUTO(decimal_ret, value18, 0x40, 0, &carry_bcd4, &overflow_bcd4);
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xB0 + value14, sum_bcd4);
                    a2 = 0x1E;
                    carry2 = carry_bcd4;
                    overflow2 = overflow_bcd4;
                }
                a_89182 = a2;
                a_hi_89182 = 0;
                x_89182 = value14;
                y_89182 = value15;
                carry_89182 = carry2;
                overflow_89182 = overflow2;
                direct_page_89182 = dp_ret2;
                data_bank_89182 = db_ret2;
                decimal_89182 = decimal_ret;
                goto shared_8918_1;
            }
        } else {
            uint16_t value19 = BUS16_RDP(c, (db_ret << 0x10) + 0xB0 + value7);
            r->a = value19;
            r->x = value7;
            r->y = (uint8_t)y_ret;
            r->z = value19 == 0;
            r->n = value19 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x88EF, 0xC22A60); GUARD_JSR(c, sp_call, 0x88EF); } /* mask_angle_and_derive_native_sine */
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret5 = r->xf;
            uint16_t a_all4 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x46), a_all4);
            if (x_ret5) {
                uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x87));
                uint8_t value21 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xB6 + value20);
                uint16_t value22 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB2 + value21);
                uint8_t a3;
                bool carry3;
                bool overflow3;
                if (value22 != 0) {
                    uint16_t value23 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB0 + value20);
                    bool carry_bcd5, overflow_bcd5;
                    uint16_t sum_bcd5 = SOM_ADC16_AUTO(decimal_ret, value23, 0x0100, 0, &carry_bcd5, &overflow_bcd5);
                    BUS16_SET(c, (db_ret3 << 0x10) + 0xB0 + value20, sum_bcd5);
                    a3 = 0x0F;
                    carry3 = carry_bcd5;
                    overflow3 = overflow_bcd5;
                } else {
                    uint16_t value24 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB0 + value20);
                    bool carry_bcd6, overflow_bcd6;
                    uint16_t sum_bcd6 = SOM_ADC16_AUTO(decimal_ret, value24, 0x40, 0, &carry_bcd6, &overflow_bcd6);
                    BUS16_SET(c, (db_ret3 << 0x10) + 0xB0 + value20, sum_bcd6);
                    a3 = 0x1E;
                    carry3 = carry_bcd6;
                    overflow3 = overflow_bcd6;
                }
                a_8918 = a3;
                a_hi_8918 = 0;
                x_8918 = value20;
                y_8918 = value21;
                carry_8918 = carry3;
                overflow_8918 = overflow3;
                direct_page_8918 = dp_ret3;
                data_bank_8918 = db_ret3;
                decimal_8918 = decimal_ret;
                goto shared_8918;
            } else {
                uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x87));
                uint16_t value26 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB6 + value25);
                uint16_t value27 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB2 + value26);
                uint8_t a4;
                bool carry4;
                bool overflow4;
                if (value27 != 0) {
                    uint16_t value28 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB0 + value25);
                    bool carry_bcd7, overflow_bcd7;
                    uint16_t sum_bcd7 = SOM_ADC16_AUTO(decimal_ret, value28, 0x0100, 0, &carry_bcd7, &overflow_bcd7);
                    BUS16_SET(c, (db_ret3 << 0x10) + 0xB0 + value25, sum_bcd7);
                    a4 = 0x0F;
                    carry4 = carry_bcd7;
                    overflow4 = overflow_bcd7;
                } else {
                    uint16_t value29 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xB0 + value25);
                    bool carry_bcd8, overflow_bcd8;
                    uint16_t sum_bcd8 = SOM_ADC16_AUTO(decimal_ret, value29, 0x40, 0, &carry_bcd8, &overflow_bcd8);
                    BUS16_SET(c, (db_ret3 << 0x10) + 0xB0 + value25, sum_bcd8);
                    a4 = 0x1E;
                    carry4 = carry_bcd8;
                    overflow4 = overflow_bcd8;
                }
                a_89182 = a4;
                a_hi_89182 = 0;
                x_89182 = value25;
                y_89182 = value26;
                carry_89182 = carry4;
                overflow_89182 = overflow4;
                direct_page_89182 = dp_ret3;
                data_bank_89182 = db_ret3;
                decimal_89182 = decimal_ret;
                goto shared_8918_1;
            }
        }
    } else {
        uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        if (m_ret) {
            uint8_t value31 = BUS8_RDP(c, (db_ret << 0x10) + 0xB0 + value30);
            r->a = (a_all2 >> 8 << 8) | value31;
            r->x = value30;
            r->z = value31 == 0;
            r->n = value31 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x88EF, 0xC22A60); GUARD_JSR(c, sp_call, 0x88EF); } /* mask_angle_and_derive_native_sine */
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret7 = r->xf;
            uint16_t a_all5 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret4 + 0x46), a_all5);
            if (x_ret7) {
                uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 0x87));
                uint8_t value33 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xB6 + value32);
                uint16_t value34 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xB2 + value33);
                uint8_t a5;
                bool carry5;
                bool overflow5;
                if (value34 != 0) {
                    uint16_t value35 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xB0 + value32);
                    bool carry_bcd9, overflow_bcd9;
                    uint16_t sum_bcd9 = SOM_ADC16_AUTO(decimal_ret, value35, 0x0100, 0, &carry_bcd9, &overflow_bcd9);
                    BUS16_SET(c, (db_ret4 << 0x10) + 0xB0 + value32, sum_bcd9);
                    a5 = 0x0F;
                    carry5 = carry_bcd9;
                    overflow5 = overflow_bcd9;
                } else {
                    uint16_t value36 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xB0 + value32);
                    bool carry_bcd10, overflow_bcd10;
                    uint16_t sum_bcd10 = SOM_ADC16_AUTO(decimal_ret, value36, 0x40, 0, &carry_bcd10, &overflow_bcd10);
                    BUS16_SET(c, (db_ret4 << 0x10) + 0xB0 + value32, sum_bcd10);
                    a5 = 0x1E;
                    carry5 = carry_bcd10;
                    overflow5 = overflow_bcd10;
                }
                a_8918 = a5;
                a_hi_8918 = 0;
                x_8918 = value32;
                y_8918 = value33;
                carry_8918 = carry5;
                overflow_8918 = overflow5;
                direct_page_8918 = dp_ret4;
                data_bank_8918 = db_ret4;
                decimal_8918 = decimal_ret;
                goto shared_8918;
            } else {
                uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 0x87));
                uint16_t value38 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xB6 + value37);
                uint16_t value39 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xB2 + value38);
                uint8_t a6;
                bool carry6;
                bool overflow6;
                if (value39 != 0) {
                    uint16_t value40 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xB0 + value37);
                    bool carry_bcd11, overflow_bcd11;
                    uint16_t sum_bcd11 = SOM_ADC16_AUTO(decimal_ret, value40, 0x0100, 0, &carry_bcd11, &overflow_bcd11);
                    BUS16_SET(c, (db_ret4 << 0x10) + 0xB0 + value37, sum_bcd11);
                    a6 = 0x0F;
                    carry6 = carry_bcd11;
                    overflow6 = overflow_bcd11;
                } else {
                    uint16_t value41 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xB0 + value37);
                    bool carry_bcd12, overflow_bcd12;
                    uint16_t sum_bcd12 = SOM_ADC16_AUTO(decimal_ret, value41, 0x40, 0, &carry_bcd12, &overflow_bcd12);
                    BUS16_SET(c, (db_ret4 << 0x10) + 0xB0 + value37, sum_bcd12);
                    a6 = 0x1E;
                    carry6 = carry_bcd12;
                    overflow6 = overflow_bcd12;
                }
                a_89182 = a6;
                a_hi_89182 = 0;
                x_89182 = value37;
                y_89182 = value38;
                carry_89182 = carry6;
                overflow_89182 = overflow6;
                direct_page_89182 = dp_ret4;
                data_bank_89182 = db_ret4;
                decimal_89182 = decimal_ret;
                goto shared_8918_1;
            }
        } else {
            uint16_t value42 = BUS16_RDP(c, (db_ret << 0x10) + 0xB0 + value30);
            r->a = value42;
            r->x = value30;
            r->z = value42 == 0;
            r->n = value42 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x88EF, 0xC22A60); GUARD_JSR(c, sp_call, 0x88EF); } /* mask_angle_and_derive_native_sine */
            uint16_t dp_ret5 = r->dp;
            uint8_t db_ret5 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret9 = r->xf;
            uint16_t a_all6 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret5 + 0x46), a_all6);
            if (x_ret9) {
                uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 0x87));
                uint8_t value44 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xB6 + value43);
                uint16_t value45 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xB2 + value44);
                uint8_t a7;
                bool carry7;
                bool overflow7;
                if (value45 != 0) {
                    uint16_t value46 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xB0 + value43);
                    bool carry_bcd13, overflow_bcd13;
                    uint16_t sum_bcd13 = SOM_ADC16_AUTO(decimal_ret, value46, 0x0100, 0, &carry_bcd13, &overflow_bcd13);
                    BUS16_SET(c, (db_ret5 << 0x10) + 0xB0 + value43, sum_bcd13);
                    a7 = 0x0F;
                    carry7 = carry_bcd13;
                    overflow7 = overflow_bcd13;
                } else {
                    uint16_t value47 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xB0 + value43);
                    bool carry_bcd14, overflow_bcd14;
                    uint16_t sum_bcd14 = SOM_ADC16_AUTO(decimal_ret, value47, 0x40, 0, &carry_bcd14, &overflow_bcd14);
                    BUS16_SET(c, (db_ret5 << 0x10) + 0xB0 + value43, sum_bcd14);
                    a7 = 0x1E;
                    carry7 = carry_bcd14;
                    overflow7 = overflow_bcd14;
                }
                a_8918 = a7;
                a_hi_8918 = 0;
                x_8918 = value43;
                y_8918 = value44;
                carry_8918 = carry7;
                overflow_8918 = overflow7;
                direct_page_8918 = dp_ret5;
                data_bank_8918 = db_ret5;
                decimal_8918 = decimal_ret;
                goto shared_8918;
            } else {
                uint16_t value48 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 0x87));
                uint16_t value49 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xB6 + value48);
                uint16_t value50 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xB2 + value49);
                uint8_t a8;
                bool carry8;
                bool overflow8;
                if (value50 != 0) {
                    uint16_t value51 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xB0 + value48);
                    bool carry_bcd15, overflow_bcd15;
                    uint16_t sum_bcd15 = SOM_ADC16_AUTO(decimal_ret, value51, 0x0100, 0, &carry_bcd15, &overflow_bcd15);
                    BUS16_SET(c, (db_ret5 << 0x10) + 0xB0 + value48, sum_bcd15);
                    a8 = 0x0F;
                    carry8 = carry_bcd15;
                    overflow8 = overflow_bcd15;
                } else {
                    uint16_t value52 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xB0 + value48);
                    bool carry_bcd16, overflow_bcd16;
                    uint16_t sum_bcd16 = SOM_ADC16_AUTO(decimal_ret, value52, 0x40, 0, &carry_bcd16, &overflow_bcd16);
                    BUS16_SET(c, (db_ret5 << 0x10) + 0xB0 + value48, sum_bcd16);
                    a8 = 0x1E;
                    carry8 = carry_bcd16;
                    overflow8 = overflow_bcd16;
                }
                a_89182 = a8;
                a_hi_89182 = 0;
                x_89182 = value48;
                y_89182 = value49;
                carry_89182 = carry8;
                overflow_89182 = overflow8;
                direct_page_89182 = dp_ret5;
                data_bank_89182 = db_ret5;
                decimal_89182 = decimal_ret;
                goto shared_8918_1;
            }
        }
    }
    shared_8918:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(direct_page_8918 + 0x4E), (a_hi_8918 << 8) | a_8918);
    r->a = (a_hi_8918 << 8) | a_8918;
    r->x = x_8918;
    r->y = y_8918;
    r->c = carry_8918;
    r->v = overflow_8918;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_8918;
    r->dp = direct_page_8918;
    r->d = decimal_8918;
    { const uint16_t sp_call = r->sp; JSR(c, 0x891C, 0xC22D69); GUARD_JSR(c, sp_call, 0x891C); } /* divide_signed_word_by_word_with_remainder */
    uint8_t value53 = BUS8_RDP(c, (uint16_t)(direct_page_8918 + 0x87));
    uint16_t value54 = BUS16_RDP(c, (uint16_t)(direct_page_8918 + 0x56));
    uint16_t value55 = BUS16_RDP(c, (data_bank_8918 << 0x10) + 0xB4 + value53);
    bool carry_bcd17, overflow_bcd17;
    uint16_t sum_bcd17 = SOM_ADC16_AUTO(decimal_8918, value54, value55, 0, &carry_bcd17, &overflow_bcd17);
    BUS16_SET(c, (uint16_t)(direct_page_8918 + 0x95), sum_bcd17);
    uint8_t value56 = BUS8_RDP(c, (uint16_t)(direct_page_8918 + 0x87));
    uint16_t value57 = BUS16_RDP(c, (data_bank_8918 << 0x10) + 0xB2 + value56);
    r->a = value57;
    r->x = value56;
    r->c = carry_bcd17;
    r->z = value57 == 0;
    r->n = value57 & 0x8000;
    r->v = overflow_bcd17;
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x892E, 0xC22A60); GUARD_JSR(c, sp_call, 0x892E); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret12 = r->xf;
    uint16_t a_all8 = r->a;
    if (m_ret2) {
        BUS8_SET(c, (uint16_t)(dp_ret6 + 0x97), (uint8_t)a_all8);
        if (x_ret12) {
            uint8_t value58 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x87));
            uint8_t value59 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xB2 + value58);
            r->a = (a_all8 >> 8 << 8) | value59;
            r->x = value58;
            r->z = value59 == 0;
            r->n = value59 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8938, 0xC22A59); GUARD_JSR(c, sp_call, 0x8938); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all9 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x99), a_all9);
            uint16_t value60 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), value60);
            uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value61);
            r->a = value61;
            r->z = value61 == 0;
            r->n = value61 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8945, 0xC22B94); GUARD_JSR(c, sp_call, 0x8945); } /* multiply_signed_words_to_double_word */
            uint16_t value62 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9B), value62);
            uint16_t value63 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), value63);
            uint16_t value64 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value64);
            r->a = value64;
            r->z = value64 == 0;
            r->n = value64 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8954, 0xC22B94); GUARD_JSR(c, sp_call, 0x8954); } /* multiply_signed_words_to_double_word */
            uint16_t value65 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9D), value65);
            uint16_t value66 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x97));
            uint16_t value67 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), (uint16_t)((value66 ^ value67) + 1));
            uint16_t value68 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value68);
            r->a = value68;
            r->z = value68 == 0;
            r->n = value68 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8966, 0xC22B94); GUARD_JSR(c, sp_call, 0x8966); } /* multiply_signed_words_to_double_word */
            uint16_t value69 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9F), value69);
            uint16_t value70 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9B));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02CD, value70);
            uint16_t value71 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9D));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02CF, value71);
            uint16_t value72 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9F));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02D1, value72);
            uint16_t value73 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9B));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02D3, value73);
            uint8_t value74 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x87));
            uint8_t value75 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xB6 + value74);
            uint16_t value76 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x94 + value75);
            uint8_t a9;
            uint8_t a_hi1;
            bool zero1;
            bool negative1;
            if (value76 != 6) {
                a9 = (uint8_t)value76;
                a_hi1 = value76 >> 8;
                zero1 = value76 == 6;
                negative1 = (uint16_t)(value76 - 6) & 0x8000;
            } else {
                uint16_t value77 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x94 + value74);
                BUS16_RMW_SET(c, (db_ret6 << 0x10) + 0x94 + value74, (uint16_t)(value77 + 1));
                r->a = 0x017B;
                r->x = value74;
                r->y = value75;
                r->c = value76 >= 6;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8994, 0xC21394); GUARD_JSR(c, sp_call, 0x8994); } /* select_boss_animation_and_reset_frame_cursor */
                uint16_t a_all13 = r->a;
                bool zero_ret13 = r->z;
                bool negative_ret13 = r->n;
                a9 = (uint8_t)a_all13;
                a_hi1 = a_all13 >> 8;
                zero1 = zero_ret13;
                negative1 = negative_ret13;
            }
            r->a = (a_hi1 << 8) | a9;
            r->x = value74;
            r->y = value75;
            r->c = 0;
            r->z = zero1;
            r->n = negative1;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value78 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x87));
            uint8_t value79 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xB2 + value78);
            r->a = (a_all8 >> 8 << 8) | value79;
            r->x = value78;
            r->z = value79 == 0;
            r->n = value79 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8938, 0xC22A59); GUARD_JSR(c, sp_call, 0x8938); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all14 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x99), a_all14);
            uint16_t value80 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), value80);
            uint16_t value81 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value81);
            r->a = value81;
            r->z = value81 == 0;
            r->n = value81 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8945, 0xC22B94); GUARD_JSR(c, sp_call, 0x8945); } /* multiply_signed_words_to_double_word */
            uint16_t value82 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9B), value82);
            uint16_t value83 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), value83);
            uint16_t value84 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value84);
            r->a = value84;
            r->z = value84 == 0;
            r->n = value84 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8954, 0xC22B94); GUARD_JSR(c, sp_call, 0x8954); } /* multiply_signed_words_to_double_word */
            uint16_t value85 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9D), value85);
            uint16_t value86 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x97));
            uint16_t value87 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), (uint16_t)((value86 ^ value87) + 1));
            uint16_t value88 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value88);
            r->a = value88;
            r->z = value88 == 0;
            r->n = value88 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8966, 0xC22B94); GUARD_JSR(c, sp_call, 0x8966); } /* multiply_signed_words_to_double_word */
            uint16_t value89 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9F), value89);
            uint16_t value90 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9B));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02CD, value90);
            uint16_t value91 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9D));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02CF, value91);
            uint16_t value92 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9F));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02D1, value92);
            uint16_t value93 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9B));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02D3, value93);
            uint16_t value94 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x87));
            uint16_t value95 = BUS16_RDP(c, (db_ret6 << 0x10) + 0xB6 + value94);
            uint16_t value96 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x94 + value95);
            uint8_t a10;
            uint8_t a_hi2;
            bool zero2;
            bool negative2;
            if (value96 != 6) {
                a10 = (uint8_t)value96;
                a_hi2 = value96 >> 8;
                zero2 = value96 == 6;
                negative2 = (uint16_t)(value96 - 6) & 0x8000;
            } else {
                uint16_t value97 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x94 + value94);
                BUS16_RMW_SET(c, (db_ret6 << 0x10) + 0x94 + value94, (uint16_t)(value97 + 1));
                r->a = 0x017B;
                r->x = value94;
                r->y = value95;
                r->c = value96 >= 6;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8994, 0xC21394); GUARD_JSR(c, sp_call, 0x8994); } /* select_boss_animation_and_reset_frame_cursor */
                uint16_t a_all18 = r->a;
                bool zero_ret18 = r->z;
                bool negative_ret18 = r->n;
                a10 = (uint8_t)a_all18;
                a_hi2 = a_all18 >> 8;
                zero2 = zero_ret18;
                negative2 = negative_ret18;
            }
            r->a = (a_hi2 << 8) | a10;
            r->x = value94;
            r->y = value95;
            r->c = 0;
            r->z = zero2;
            r->n = negative2;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret6 + 0x97), a_all8);
        if (x_ret12) {
            uint8_t value98 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x87));
            uint16_t value99 = BUS16_RDP(c, (db_ret6 << 0x10) + 0xB2 + value98);
            r->a = value99;
            r->x = value98;
            r->z = value99 == 0;
            r->n = value99 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8938, 0xC22A59); GUARD_JSR(c, sp_call, 0x8938); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all19 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x99), a_all19);
            uint16_t value100 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), value100);
            uint16_t value101 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value101);
            r->a = value101;
            r->z = value101 == 0;
            r->n = value101 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8945, 0xC22B94); GUARD_JSR(c, sp_call, 0x8945); } /* multiply_signed_words_to_double_word */
            uint16_t value102 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9B), value102);
            uint16_t value103 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), value103);
            uint16_t value104 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value104);
            r->a = value104;
            r->z = value104 == 0;
            r->n = value104 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8954, 0xC22B94); GUARD_JSR(c, sp_call, 0x8954); } /* multiply_signed_words_to_double_word */
            uint16_t value105 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9D), value105);
            uint16_t value106 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x97));
            uint16_t value107 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), (uint16_t)((value106 ^ value107) + 1));
            uint16_t value108 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value108);
            r->a = value108;
            r->z = value108 == 0;
            r->n = value108 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8966, 0xC22B94); GUARD_JSR(c, sp_call, 0x8966); } /* multiply_signed_words_to_double_word */
            uint16_t value109 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9F), value109);
            uint16_t value110 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9B));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02CD, value110);
            uint16_t value111 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9D));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02CF, value111);
            uint16_t value112 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9F));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02D1, value112);
            uint16_t value113 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9B));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02D3, value113);
            uint8_t value114 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x87));
            uint8_t value115 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xB6 + value114);
            uint16_t value116 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x94 + value115);
            uint8_t a11;
            uint8_t a_hi3;
            bool zero3;
            bool negative3;
            if (value116 != 6) {
                a11 = (uint8_t)value116;
                a_hi3 = value116 >> 8;
                zero3 = value116 == 6;
                negative3 = (uint16_t)(value116 - 6) & 0x8000;
            } else {
                uint16_t value117 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x94 + value114);
                BUS16_RMW_SET(c, (db_ret6 << 0x10) + 0x94 + value114, (uint16_t)(value117 + 1));
                r->a = 0x017B;
                r->x = value114;
                r->y = value115;
                r->c = value116 >= 6;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8994, 0xC21394); GUARD_JSR(c, sp_call, 0x8994); } /* select_boss_animation_and_reset_frame_cursor */
                uint16_t a_all23 = r->a;
                bool zero_ret23 = r->z;
                bool negative_ret23 = r->n;
                a11 = (uint8_t)a_all23;
                a_hi3 = a_all23 >> 8;
                zero3 = zero_ret23;
                negative3 = negative_ret23;
            }
            r->a = (a_hi3 << 8) | a11;
            r->x = value114;
            r->y = value115;
            r->c = 0;
            r->z = zero3;
            r->n = negative3;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value118 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x87));
            uint16_t value119 = BUS16_RDP(c, (db_ret6 << 0x10) + 0xB2 + value118);
            r->a = value119;
            r->x = value118;
            r->z = value119 == 0;
            r->n = value119 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8938, 0xC22A59); GUARD_JSR(c, sp_call, 0x8938); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all24 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x99), a_all24);
            uint16_t value120 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), value120);
            uint16_t value121 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value121);
            r->a = value121;
            r->z = value121 == 0;
            r->n = value121 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8945, 0xC22B94); GUARD_JSR(c, sp_call, 0x8945); } /* multiply_signed_words_to_double_word */
            uint16_t value122 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9B), value122);
            uint16_t value123 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), value123);
            uint16_t value124 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value124);
            r->a = value124;
            r->z = value124 == 0;
            r->n = value124 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8954, 0xC22B94); GUARD_JSR(c, sp_call, 0x8954); } /* multiply_signed_words_to_double_word */
            uint16_t value125 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9D), value125);
            uint16_t value126 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x97));
            uint16_t value127 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x46), (uint16_t)((value126 ^ value127) + 1));
            uint16_t value128 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x4E), value128);
            r->a = value128;
            r->z = value128 == 0;
            r->n = value128 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8966, 0xC22B94); GUARD_JSR(c, sp_call, 0x8966); } /* multiply_signed_words_to_double_word */
            uint16_t value129 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret6 + 0x9F), value129);
            uint16_t value130 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9B));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02CD, value130);
            uint16_t value131 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9D));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02CF, value131);
            uint16_t value132 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9F));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02D1, value132);
            uint16_t value133 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9B));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x02D3, value133);
            uint16_t value134 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x87));
            uint16_t value135 = BUS16_RDP(c, (db_ret6 << 0x10) + 0xB6 + value134);
            uint16_t value136 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x94 + value135);
            uint8_t a12;
            uint8_t a_hi4;
            bool zero4;
            bool negative4;
            if (value136 != 6) {
                a12 = (uint8_t)value136;
                a_hi4 = value136 >> 8;
                zero4 = value136 == 6;
                negative4 = (uint16_t)(value136 - 6) & 0x8000;
            } else {
                uint16_t value137 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x94 + value134);
                BUS16_RMW_SET(c, (db_ret6 << 0x10) + 0x94 + value134, (uint16_t)(value137 + 1));
                r->a = 0x017B;
                r->x = value134;
                r->y = value135;
                r->c = value136 >= 6;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8994, 0xC21394); GUARD_JSR(c, sp_call, 0x8994); } /* select_boss_animation_and_reset_frame_cursor */
                uint16_t a_all28 = r->a;
                bool zero_ret28 = r->z;
                bool negative_ret28 = r->n;
                a12 = (uint8_t)a_all28;
                a_hi4 = a_all28 >> 8;
                zero4 = zero_ret28;
                negative4 = negative_ret28;
            }
            r->a = (a_hi4 << 8) | a12;
            r->x = value134;
            r->y = value135;
            r->c = 0;
            r->z = zero4;
            r->n = negative4;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    shared_8918_1:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(direct_page_89182 + 0x4E), (a_hi_89182 << 8) | a_89182);
    r->a = (a_hi_89182 << 8) | a_89182;
    r->x = x_89182;
    r->y = y_89182;
    r->c = carry_89182;
    r->v = overflow_89182;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_89182;
    r->dp = direct_page_89182;
    r->d = decimal_89182;
    { const uint16_t sp_call = r->sp; JSR(c, 0x891C, 0xC22D69); GUARD_JSR(c, sp_call, 0x891C); } /* divide_signed_word_by_word_with_remainder */
    uint16_t y_ret3 = r->y;
    uint16_t value138 = BUS16_RDP(c, (uint16_t)(direct_page_89182 + 0x87));
    uint16_t value139 = BUS16_RDP(c, (uint16_t)(direct_page_89182 + 0x56));
    uint16_t value140 = BUS16_RDP(c, (data_bank_89182 << 0x10) + 0xB4 + value138);
    bool carry_bcd18, overflow_bcd18;
    uint16_t sum_bcd18 = SOM_ADC16_AUTO(decimal_89182, value139, value140, 0, &carry_bcd18, &overflow_bcd18);
    BUS16_SET(c, (uint16_t)(direct_page_89182 + 0x95), sum_bcd18);
    uint16_t value141 = BUS16_RDP(c, (uint16_t)(direct_page_89182 + 0x87));
    uint16_t value142 = BUS16_RDP(c, (data_bank_89182 << 0x10) + 0xB2 + value141);
    r->a = value142;
    r->x = value141;
    r->c = carry_bcd18;
    r->z = value142 == 0;
    r->n = value142 & 0x8000;
    r->v = overflow_bcd18;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x892E, 0xC22A60); GUARD_JSR(c, sp_call, 0x892E); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret19 = r->xf;
    uint16_t a_all30 = r->a;
    if (m_ret3) {
        BUS8_SET(c, (uint16_t)(dp_ret7 + 0x97), (uint8_t)a_all30);
        if (x_ret19) {
            uint8_t value143 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 0x87));
            uint8_t value144 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xB2 + value143);
            r->a = (a_all30 >> 8 << 8) | value144;
            r->x = value143;
            r->y = (uint8_t)y_ret3;
            r->z = value144 == 0;
            r->n = value144 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8938, 0xC22A59); GUARD_JSR(c, sp_call, 0x8938); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all31 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x99), a_all31);
            uint16_t value145 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), value145);
            uint16_t value146 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value146);
            r->a = value146;
            r->z = value146 == 0;
            r->n = value146 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8945, 0xC22B94); GUARD_JSR(c, sp_call, 0x8945); } /* multiply_signed_words_to_double_word */
            uint16_t value147 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9B), value147);
            uint16_t value148 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), value148);
            uint16_t value149 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value149);
            r->a = value149;
            r->z = value149 == 0;
            r->n = value149 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8954, 0xC22B94); GUARD_JSR(c, sp_call, 0x8954); } /* multiply_signed_words_to_double_word */
            uint16_t value150 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9D), value150);
            uint16_t value151 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x97));
            uint16_t value152 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), (uint16_t)((value151 ^ value152) + 1));
            uint16_t value153 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value153);
            r->a = value153;
            r->z = value153 == 0;
            r->n = value153 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8966, 0xC22B94); GUARD_JSR(c, sp_call, 0x8966); } /* multiply_signed_words_to_double_word */
            uint16_t value154 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9F), value154);
            uint16_t value155 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9B));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02CD, value155);
            uint16_t value156 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9D));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02CF, value156);
            uint16_t value157 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9F));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02D1, value157);
            uint16_t value158 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9B));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02D3, value158);
            uint8_t value159 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 0x87));
            uint8_t value160 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xB6 + value159);
            uint16_t value161 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value160);
            uint8_t a13;
            uint8_t a_hi5;
            bool zero5;
            bool negative5;
            if (value161 != 6) {
                a13 = (uint8_t)value161;
                a_hi5 = value161 >> 8;
                zero5 = value161 == 6;
                negative5 = (uint16_t)(value161 - 6) & 0x8000;
            } else {
                uint16_t value162 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value159);
                BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x94 + value159, (uint16_t)(value162 + 1));
                r->a = 0x017B;
                r->x = value159;
                r->y = value160;
                r->c = value161 >= 6;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8994, 0xC21394); GUARD_JSR(c, sp_call, 0x8994); } /* select_boss_animation_and_reset_frame_cursor */
                uint16_t a_all35 = r->a;
                bool zero_ret35 = r->z;
                bool negative_ret35 = r->n;
                a13 = (uint8_t)a_all35;
                a_hi5 = a_all35 >> 8;
                zero5 = zero_ret35;
                negative5 = negative_ret35;
            }
            r->a = (a_hi5 << 8) | a13;
            r->x = value159;
            r->y = value160;
            r->c = 0;
            r->z = zero5;
            r->n = negative5;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value163 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x87));
            uint8_t value164 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xB2 + value163);
            r->a = (a_all30 >> 8 << 8) | value164;
            r->x = value163;
            r->z = value164 == 0;
            r->n = value164 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8938, 0xC22A59); GUARD_JSR(c, sp_call, 0x8938); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all36 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x99), a_all36);
            uint16_t value165 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), value165);
            uint16_t value166 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value166);
            r->a = value166;
            r->z = value166 == 0;
            r->n = value166 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8945, 0xC22B94); GUARD_JSR(c, sp_call, 0x8945); } /* multiply_signed_words_to_double_word */
            uint16_t value167 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9B), value167);
            uint16_t value168 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), value168);
            uint16_t value169 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value169);
            r->a = value169;
            r->z = value169 == 0;
            r->n = value169 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8954, 0xC22B94); GUARD_JSR(c, sp_call, 0x8954); } /* multiply_signed_words_to_double_word */
            uint16_t value170 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9D), value170);
            uint16_t value171 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x97));
            uint16_t value172 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), (uint16_t)((value171 ^ value172) + 1));
            uint16_t value173 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value173);
            r->a = value173;
            r->z = value173 == 0;
            r->n = value173 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8966, 0xC22B94); GUARD_JSR(c, sp_call, 0x8966); } /* multiply_signed_words_to_double_word */
            uint16_t value174 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9F), value174);
            uint16_t value175 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9B));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02CD, value175);
            uint16_t value176 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9D));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02CF, value176);
            uint16_t value177 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9F));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02D1, value177);
            uint16_t value178 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9B));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02D3, value178);
            uint16_t value179 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x87));
            uint16_t value180 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xB6 + value179);
            uint16_t value181 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value180);
            uint8_t a14;
            uint8_t a_hi6;
            bool zero6;
            bool negative6;
            if (value181 != 6) {
                a14 = (uint8_t)value181;
                a_hi6 = value181 >> 8;
                zero6 = value181 == 6;
                negative6 = (uint16_t)(value181 - 6) & 0x8000;
            } else {
                uint16_t value182 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value179);
                BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x94 + value179, (uint16_t)(value182 + 1));
                r->a = 0x017B;
                r->x = value179;
                r->y = value180;
                r->c = value181 >= 6;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8994, 0xC21394); GUARD_JSR(c, sp_call, 0x8994); } /* select_boss_animation_and_reset_frame_cursor */
                uint16_t a_all40 = r->a;
                bool zero_ret40 = r->z;
                bool negative_ret40 = r->n;
                a14 = (uint8_t)a_all40;
                a_hi6 = a_all40 >> 8;
                zero6 = zero_ret40;
                negative6 = negative_ret40;
            }
            r->a = (a_hi6 << 8) | a14;
            r->x = value179;
            r->y = value180;
            r->c = 0;
            r->z = zero6;
            r->n = negative6;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret7 + 0x97), a_all30);
        if (x_ret19) {
            uint8_t value183 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 0x87));
            uint16_t value184 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xB2 + value183);
            r->a = value184;
            r->x = value183;
            r->y = (uint8_t)y_ret3;
            r->z = value184 == 0;
            r->n = value184 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8938, 0xC22A59); GUARD_JSR(c, sp_call, 0x8938); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all41 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x99), a_all41);
            uint16_t value185 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), value185);
            uint16_t value186 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value186);
            r->a = value186;
            r->z = value186 == 0;
            r->n = value186 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8945, 0xC22B94); GUARD_JSR(c, sp_call, 0x8945); } /* multiply_signed_words_to_double_word */
            uint16_t value187 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9B), value187);
            uint16_t value188 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), value188);
            uint16_t value189 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value189);
            r->a = value189;
            r->z = value189 == 0;
            r->n = value189 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8954, 0xC22B94); GUARD_JSR(c, sp_call, 0x8954); } /* multiply_signed_words_to_double_word */
            uint16_t value190 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9D), value190);
            uint16_t value191 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x97));
            uint16_t value192 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), (uint16_t)((value191 ^ value192) + 1));
            uint16_t value193 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value193);
            r->a = value193;
            r->z = value193 == 0;
            r->n = value193 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8966, 0xC22B94); GUARD_JSR(c, sp_call, 0x8966); } /* multiply_signed_words_to_double_word */
            uint16_t value194 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9F), value194);
            uint16_t value195 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9B));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02CD, value195);
            uint16_t value196 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9D));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02CF, value196);
            uint16_t value197 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9F));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02D1, value197);
            uint16_t value198 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9B));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02D3, value198);
            uint8_t value199 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 0x87));
            uint8_t value200 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xB6 + value199);
            uint16_t value201 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value200);
            uint8_t a15;
            uint8_t a_hi7;
            bool zero7;
            bool negative7;
            if (value201 != 6) {
                a15 = (uint8_t)value201;
                a_hi7 = value201 >> 8;
                zero7 = value201 == 6;
                negative7 = (uint16_t)(value201 - 6) & 0x8000;
            } else {
                uint16_t value202 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value199);
                BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x94 + value199, (uint16_t)(value202 + 1));
                r->a = 0x017B;
                r->x = value199;
                r->y = value200;
                r->c = value201 >= 6;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8994, 0xC21394); GUARD_JSR(c, sp_call, 0x8994); } /* select_boss_animation_and_reset_frame_cursor */
                uint16_t a_all45 = r->a;
                bool zero_ret45 = r->z;
                bool negative_ret45 = r->n;
                a15 = (uint8_t)a_all45;
                a_hi7 = a_all45 >> 8;
                zero7 = zero_ret45;
                negative7 = negative_ret45;
            }
            r->a = (a_hi7 << 8) | a15;
            r->x = value199;
            r->y = value200;
            r->c = 0;
            r->z = zero7;
            r->n = negative7;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value203 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x87));
            uint16_t value204 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xB2 + value203);
            r->a = value204;
            r->x = value203;
            r->z = value204 == 0;
            r->n = value204 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8938, 0xC22A59); GUARD_JSR(c, sp_call, 0x8938); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all46 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x99), a_all46);
            uint16_t value205 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), value205);
            uint16_t value206 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value206);
            r->a = value206;
            r->z = value206 == 0;
            r->n = value206 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8945, 0xC22B94); GUARD_JSR(c, sp_call, 0x8945); } /* multiply_signed_words_to_double_word */
            uint16_t value207 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9B), value207);
            uint16_t value208 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), value208);
            uint16_t value209 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value209);
            r->a = value209;
            r->z = value209 == 0;
            r->n = value209 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8954, 0xC22B94); GUARD_JSR(c, sp_call, 0x8954); } /* multiply_signed_words_to_double_word */
            uint16_t value210 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9D), value210);
            uint16_t value211 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x97));
            uint16_t value212 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x46), (uint16_t)((value211 ^ value212) + 1));
            uint16_t value213 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x4E), value213);
            r->a = value213;
            r->z = value213 == 0;
            r->n = value213 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8966, 0xC22B94); GUARD_JSR(c, sp_call, 0x8966); } /* multiply_signed_words_to_double_word */
            uint16_t value214 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret7 + 0x9F), value214);
            uint16_t value215 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9B));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02CD, value215);
            uint16_t value216 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9D));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02CF, value216);
            uint16_t value217 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9F));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02D1, value217);
            uint16_t value218 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9B));
            BUS16_SET(c, (db_ret7 << 0x10) + 0x02D3, value218);
            uint16_t value219 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x87));
            uint16_t value220 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xB6 + value219);
            uint16_t value221 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value220);
            uint8_t a16;
            uint8_t a_hi8;
            bool zero8;
            bool negative8;
            if (value221 != 6) {
                a16 = (uint8_t)value221;
                a_hi8 = value221 >> 8;
                zero8 = value221 == 6;
                negative8 = (uint16_t)(value221 - 6) & 0x8000;
            } else {
                uint16_t value222 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value219);
                BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x94 + value219, (uint16_t)(value222 + 1));
                r->a = 0x017B;
                r->x = value219;
                r->y = value220;
                r->c = value221 >= 6;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8994, 0xC21394); GUARD_JSR(c, sp_call, 0x8994); } /* select_boss_animation_and_reset_frame_cursor */
                uint16_t a_all50 = r->a;
                bool zero_ret50 = r->z;
                bool negative_ret50 = r->n;
                a16 = (uint8_t)a_all50;
                a_hi8 = a_all50 >> 8;
                zero8 = zero_ret50;
                negative8 = negative_ret50;
            }
            r->a = (a_hi8 << 8) | a16;
            r->x = value219;
            r->y = value220;
            r->c = 0;
            r->z = zero8;
            r->n = negative8;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC28891, SOM_RTS, "gen", initialize_native59_mode7_matrix_center_and_control, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 262, 106)

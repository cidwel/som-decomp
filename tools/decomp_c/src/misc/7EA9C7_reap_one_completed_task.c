#include "som_c.h"

/* 7EA9C7 reap_one_completed_task   [class B, 91 bytes, 44 instructions]
 * Source: src/boot/reap_one_completed_task.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: BXYCV.
 */
static void reap_one_completed_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_aa0c = 0;
    uint8_t y_aa0c = 0;
    bool carry_aa0c = 0;
    bool overflow_aa0c = 0;
    uint16_t direct_page_aa0c = 0;
    uint8_t data_bank_aa0c = 0;
    uint8_t a_hi_aa0c2 = 0;
    uint8_t y_aa0c2 = 0;
    bool carry_aa0c2 = 0;
    bool overflow_aa0c2 = 0;
    uint16_t direct_page_aa0c2 = 0;
    uint8_t data_bank_aa0c2 = 0;
    uint8_t a_hi_aa0c3 = 0;
    uint16_t y_aa0c3 = 0;
    bool carry_aa0c3 = 0;
    bool overflow_aa0c3 = 0;
    uint16_t direct_page_aa0c3 = 0;
    uint8_t data_bank_aa0c3 = 0;
    uint8_t a_hi_aa0c4 = 0;
    uint16_t y_aa0c4 = 0;
    bool carry_aa0c4 = 0;
    bool overflow_aa0c4 = 0;
    uint16_t direct_page_aa0c4 = 0;
    uint8_t data_bank_aa0c4 = 0;
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    uint16_t value = RAM16(0x100A4);
    if (value == 0) {
        r->a = (r->a & 0x00FF) | (((uint16_t)(sp0 - 5) >> 8) << 8);
        r->x = value;
        RETURN_RTS(c);
    }
    uint16_t value2 = BUS16(c, 0x7F0000 + value);
    RAM16_SET(0x100A4, value2);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), value);
    uint16_t value3 = BUS16(c, 0x7F0004 + value);
    r->a = value3;
    r->x = value;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA9E9, 0x7EB0E8); GUARD_JSR(c, sp_call, 0xA9E9); } /* clear_heap_units_by_task */
    r->sp += 6;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        if (m_ret) {
            uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 4 + value4);
            r->a = (a_all >> 8 << 8) | value5;
            r->x = value4;
            r->y = (uint8_t)y_ret;
            r->z = value5 == 0;
            r->n = value5 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA9F1, 0x7ECBDC); GUARD_JSR(c, sp_call, 0xA9F1); } /* clear_registrations_by_task */
            r->sp += 6;
            uint8_t db_ret2 = r->db;
            bool x_ret3 = r->xf;
            if (x_ret3) {
                uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                uint8_t value7 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0A + value6);
                r->x = value7;
                r->y = value6;
                r->z = value7 == 0;
                r->n = value7 & 0x80;
                r->xf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA9F9, 0x7EB23A); GUARD_JSR(c, sp_call, 0xA9F9); } /* release_record_chain */
                r->sp += 6;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret3 = r->db;
                bool m_ret3 = r->mf;
                bool x_ret5 = r->xf;
                uint16_t a_all3 = r->a;
                if (x_ret5) {
                    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    if (m_ret3) {
                        uint8_t value9 = BUS8_RDP(c, (db_ret3 << 0x10) + 4 + value8);
                        r->a = (a_all3 >> 8 << 8) | value9;
                        r->x = value8;
                        r->z = value9 == 0;
                        r->n = value9 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret3 = r->dp;
                        uint8_t db_ret4 = r->db;
                        bool m_ret4 = r->mf;
                        bool x_ret7 = r->xf;
                        uint16_t a_all4 = r->a;
                        bool carry_ret4 = r->c;
                        bool overflow_ret4 = r->v;
                        if (x_ret7) {
                            uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                            uint8_t value11 = BUS8_RDP(c, (db_ret4 << 0x10) + 8 + value10);
                            if (value11 == 0) {
                                if (m_ret4) {
                                    a_hi_aa0c = a_all4 >> 8;
                                    y_aa0c = value10;
                                    carry_aa0c = carry_ret4;
                                    overflow_aa0c = overflow_ret4;
                                    direct_page_aa0c = dp_ret3;
                                    data_bank_aa0c = db_ret4;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all4 >> 8;
                                    y_aa0c2 = value10;
                                    carry_aa0c2 = carry_ret4;
                                    overflow_aa0c2 = overflow_ret4;
                                    direct_page_aa0c2 = dp_ret3;
                                    data_bank_aa0c2 = db_ret4;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value11;
                            r->y = value10;
                            r->z = value11 == 0;
                            r->n = value11 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret4 = r->dp;
                            uint8_t db_ret5 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret9 = r->xf;
                            uint16_t a_all5 = r->a;
                            bool carry_ret5 = r->c;
                            bool overflow_ret5 = r->v;
                            if (x_ret9) {
                                a_hi_aa0c2 = a_all5 >> 8;
                                y_aa0c2 = value10;
                                carry_aa0c2 = carry_ret5;
                                overflow_aa0c2 = overflow_ret5;
                                direct_page_aa0c2 = dp_ret4;
                                data_bank_aa0c2 = db_ret5;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all5 >> 8;
                                y_aa0c3 = value10;
                                carry_aa0c3 = carry_ret5;
                                overflow_aa0c3 = overflow_ret5;
                                direct_page_aa0c3 = dp_ret4;
                                data_bank_aa0c3 = db_ret5;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
                            uint16_t value13 = BUS16_RDP(c, (db_ret4 << 0x10) + 8 + value12);
                            if (value13 == 0) {
                                if (m_ret4) {
                                    a_hi_aa0c4 = a_all4 >> 8;
                                    y_aa0c4 = value12;
                                    carry_aa0c4 = carry_ret4;
                                    overflow_aa0c4 = overflow_ret4;
                                    direct_page_aa0c4 = dp_ret3;
                                    data_bank_aa0c4 = db_ret4;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all4 >> 8;
                                    y_aa0c3 = value12;
                                    carry_aa0c3 = carry_ret4;
                                    overflow_aa0c3 = overflow_ret4;
                                    direct_page_aa0c3 = dp_ret3;
                                    data_bank_aa0c3 = db_ret4;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value13;
                            r->y = value12;
                            r->z = value13 == 0;
                            r->n = value13 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret5 = r->dp;
                            uint8_t db_ret6 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret11 = r->xf;
                            uint16_t a_all6 = r->a;
                            bool carry_ret6 = r->c;
                            bool overflow_ret6 = r->v;
                            if (x_ret11) {
                                a_hi_aa0c2 = a_all6 >> 8;
                                y_aa0c2 = (uint8_t)value12;
                                carry_aa0c2 = carry_ret6;
                                overflow_aa0c2 = overflow_ret6;
                                direct_page_aa0c2 = dp_ret5;
                                data_bank_aa0c2 = db_ret6;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all6 >> 8;
                                y_aa0c3 = value12;
                                carry_aa0c3 = carry_ret6;
                                overflow_aa0c3 = overflow_ret6;
                                direct_page_aa0c3 = dp_ret5;
                                data_bank_aa0c3 = db_ret6;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value14 = BUS16_RDP(c, (db_ret3 << 0x10) + 4 + value8);
                        r->a = value14;
                        r->x = value8;
                        r->z = value14 == 0;
                        r->n = value14 & 0x8000;
                        r->mf = 0;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret6 = r->dp;
                        uint8_t db_ret7 = r->db;
                        bool m_ret5 = r->mf;
                        bool x_ret13 = r->xf;
                        uint16_t a_all7 = r->a;
                        bool carry_ret7 = r->c;
                        bool overflow_ret7 = r->v;
                        if (x_ret13) {
                            uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 1));
                            uint8_t value16 = BUS8_RDP(c, (db_ret7 << 0x10) + 8 + value15);
                            if (value16 == 0) {
                                if (m_ret5) {
                                    a_hi_aa0c = a_all7 >> 8;
                                    y_aa0c = value15;
                                    carry_aa0c = carry_ret7;
                                    overflow_aa0c = overflow_ret7;
                                    direct_page_aa0c = dp_ret6;
                                    data_bank_aa0c = db_ret7;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all7 >> 8;
                                    y_aa0c2 = value15;
                                    carry_aa0c2 = carry_ret7;
                                    overflow_aa0c2 = overflow_ret7;
                                    direct_page_aa0c2 = dp_ret6;
                                    data_bank_aa0c2 = db_ret7;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value16;
                            r->y = value15;
                            r->z = value16 == 0;
                            r->n = value16 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret7 = r->dp;
                            uint8_t db_ret8 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret15 = r->xf;
                            uint16_t a_all8 = r->a;
                            bool carry_ret8 = r->c;
                            bool overflow_ret8 = r->v;
                            if (x_ret15) {
                                a_hi_aa0c2 = a_all8 >> 8;
                                y_aa0c2 = value15;
                                carry_aa0c2 = carry_ret8;
                                overflow_aa0c2 = overflow_ret8;
                                direct_page_aa0c2 = dp_ret7;
                                data_bank_aa0c2 = db_ret8;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all8 >> 8;
                                y_aa0c3 = value15;
                                carry_aa0c3 = carry_ret8;
                                overflow_aa0c3 = overflow_ret8;
                                direct_page_aa0c3 = dp_ret7;
                                data_bank_aa0c3 = db_ret8;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 1));
                            uint16_t value18 = BUS16_RDP(c, (db_ret7 << 0x10) + 8 + value17);
                            if (value18 == 0) {
                                if (m_ret5) {
                                    a_hi_aa0c4 = a_all7 >> 8;
                                    y_aa0c4 = value17;
                                    carry_aa0c4 = carry_ret7;
                                    overflow_aa0c4 = overflow_ret7;
                                    direct_page_aa0c4 = dp_ret6;
                                    data_bank_aa0c4 = db_ret7;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all7 >> 8;
                                    y_aa0c3 = value17;
                                    carry_aa0c3 = carry_ret7;
                                    overflow_aa0c3 = overflow_ret7;
                                    direct_page_aa0c3 = dp_ret6;
                                    data_bank_aa0c3 = db_ret7;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value18;
                            r->y = value17;
                            r->z = value18 == 0;
                            r->n = value18 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret8 = r->dp;
                            uint8_t db_ret9 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret17 = r->xf;
                            uint16_t a_all9 = r->a;
                            bool carry_ret9 = r->c;
                            bool overflow_ret9 = r->v;
                            if (x_ret17) {
                                a_hi_aa0c2 = a_all9 >> 8;
                                y_aa0c2 = (uint8_t)value17;
                                carry_aa0c2 = carry_ret9;
                                overflow_aa0c2 = overflow_ret9;
                                direct_page_aa0c2 = dp_ret8;
                                data_bank_aa0c2 = db_ret9;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all9 >> 8;
                                y_aa0c3 = value17;
                                carry_aa0c3 = carry_ret9;
                                overflow_aa0c3 = overflow_ret9;
                                direct_page_aa0c3 = dp_ret8;
                                data_bank_aa0c3 = db_ret9;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                } else {
                    uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                    if (m_ret3) {
                        uint8_t value20 = BUS8_RDP(c, (db_ret3 << 0x10) + 4 + value19);
                        r->a = (a_all3 >> 8 << 8) | value20;
                        r->x = value19;
                        r->z = value20 == 0;
                        r->n = value20 & 0x80;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret9 = r->dp;
                        uint8_t db_ret10 = r->db;
                        bool m_ret6 = r->mf;
                        bool x_ret19 = r->xf;
                        uint16_t a_all10 = r->a;
                        bool carry_ret10 = r->c;
                        bool overflow_ret10 = r->v;
                        if (x_ret19) {
                            uint8_t value21 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 1));
                            uint8_t value22 = BUS8_RDP(c, (db_ret10 << 0x10) + 8 + value21);
                            if (value22 == 0) {
                                if (m_ret6) {
                                    a_hi_aa0c = a_all10 >> 8;
                                    y_aa0c = value21;
                                    carry_aa0c = carry_ret10;
                                    overflow_aa0c = overflow_ret10;
                                    direct_page_aa0c = dp_ret9;
                                    data_bank_aa0c = db_ret10;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all10 >> 8;
                                    y_aa0c2 = value21;
                                    carry_aa0c2 = carry_ret10;
                                    overflow_aa0c2 = overflow_ret10;
                                    direct_page_aa0c2 = dp_ret9;
                                    data_bank_aa0c2 = db_ret10;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value22;
                            r->y = value21;
                            r->z = value22 == 0;
                            r->n = value22 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret10 = r->dp;
                            uint8_t db_ret11 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret21 = r->xf;
                            uint16_t a_all11 = r->a;
                            bool carry_ret11 = r->c;
                            bool overflow_ret11 = r->v;
                            if (x_ret21) {
                                a_hi_aa0c2 = a_all11 >> 8;
                                y_aa0c2 = value21;
                                carry_aa0c2 = carry_ret11;
                                overflow_aa0c2 = overflow_ret11;
                                direct_page_aa0c2 = dp_ret10;
                                data_bank_aa0c2 = db_ret11;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all11 >> 8;
                                y_aa0c3 = value21;
                                carry_aa0c3 = carry_ret11;
                                overflow_aa0c3 = overflow_ret11;
                                direct_page_aa0c3 = dp_ret10;
                                data_bank_aa0c3 = db_ret11;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret9 + 1));
                            uint16_t value24 = BUS16_RDP(c, (db_ret10 << 0x10) + 8 + value23);
                            if (value24 == 0) {
                                if (m_ret6) {
                                    a_hi_aa0c4 = a_all10 >> 8;
                                    y_aa0c4 = value23;
                                    carry_aa0c4 = carry_ret10;
                                    overflow_aa0c4 = overflow_ret10;
                                    direct_page_aa0c4 = dp_ret9;
                                    data_bank_aa0c4 = db_ret10;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all10 >> 8;
                                    y_aa0c3 = value23;
                                    carry_aa0c3 = carry_ret10;
                                    overflow_aa0c3 = overflow_ret10;
                                    direct_page_aa0c3 = dp_ret9;
                                    data_bank_aa0c3 = db_ret10;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value24;
                            r->y = value23;
                            r->z = value24 == 0;
                            r->n = value24 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret11 = r->dp;
                            uint8_t db_ret12 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret23 = r->xf;
                            uint16_t a_all12 = r->a;
                            bool carry_ret12 = r->c;
                            bool overflow_ret12 = r->v;
                            if (x_ret23) {
                                a_hi_aa0c2 = a_all12 >> 8;
                                y_aa0c2 = (uint8_t)value23;
                                carry_aa0c2 = carry_ret12;
                                overflow_aa0c2 = overflow_ret12;
                                direct_page_aa0c2 = dp_ret11;
                                data_bank_aa0c2 = db_ret12;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all12 >> 8;
                                y_aa0c3 = value23;
                                carry_aa0c3 = carry_ret12;
                                overflow_aa0c3 = overflow_ret12;
                                direct_page_aa0c3 = dp_ret11;
                                data_bank_aa0c3 = db_ret12;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value25 = BUS16_RDP(c, (db_ret3 << 0x10) + 4 + value19);
                        r->a = value25;
                        r->x = value19;
                        r->z = value25 == 0;
                        r->n = value25 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret12 = r->dp;
                        uint8_t db_ret13 = r->db;
                        bool m_ret7 = r->mf;
                        bool x_ret25 = r->xf;
                        uint16_t a_all13 = r->a;
                        bool carry_ret13 = r->c;
                        bool overflow_ret13 = r->v;
                        if (x_ret25) {
                            uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 1));
                            uint8_t value27 = BUS8_RDP(c, (db_ret13 << 0x10) + 8 + value26);
                            if (value27 == 0) {
                                if (m_ret7) {
                                    a_hi_aa0c = a_all13 >> 8;
                                    y_aa0c = value26;
                                    carry_aa0c = carry_ret13;
                                    overflow_aa0c = overflow_ret13;
                                    direct_page_aa0c = dp_ret12;
                                    data_bank_aa0c = db_ret13;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all13 >> 8;
                                    y_aa0c2 = value26;
                                    carry_aa0c2 = carry_ret13;
                                    overflow_aa0c2 = overflow_ret13;
                                    direct_page_aa0c2 = dp_ret12;
                                    data_bank_aa0c2 = db_ret13;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value27;
                            r->y = value26;
                            r->z = value27 == 0;
                            r->n = value27 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret13 = r->dp;
                            uint8_t db_ret14 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret27 = r->xf;
                            uint16_t a_all14 = r->a;
                            bool carry_ret14 = r->c;
                            bool overflow_ret14 = r->v;
                            if (x_ret27) {
                                a_hi_aa0c2 = a_all14 >> 8;
                                y_aa0c2 = value26;
                                carry_aa0c2 = carry_ret14;
                                overflow_aa0c2 = overflow_ret14;
                                direct_page_aa0c2 = dp_ret13;
                                data_bank_aa0c2 = db_ret14;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all14 >> 8;
                                y_aa0c3 = value26;
                                carry_aa0c3 = carry_ret14;
                                overflow_aa0c3 = overflow_ret14;
                                direct_page_aa0c3 = dp_ret13;
                                data_bank_aa0c3 = db_ret14;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret12 + 1));
                            uint16_t value29 = BUS16_RDP(c, (db_ret13 << 0x10) + 8 + value28);
                            if (value29 == 0) {
                                if (m_ret7) {
                                    a_hi_aa0c4 = a_all13 >> 8;
                                    y_aa0c4 = value28;
                                    carry_aa0c4 = carry_ret13;
                                    overflow_aa0c4 = overflow_ret13;
                                    direct_page_aa0c4 = dp_ret12;
                                    data_bank_aa0c4 = db_ret13;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all13 >> 8;
                                    y_aa0c3 = value28;
                                    carry_aa0c3 = carry_ret13;
                                    overflow_aa0c3 = overflow_ret13;
                                    direct_page_aa0c3 = dp_ret12;
                                    data_bank_aa0c3 = db_ret13;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value29;
                            r->y = value28;
                            r->z = value29 == 0;
                            r->n = value29 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret14 = r->dp;
                            uint8_t db_ret15 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret29 = r->xf;
                            uint16_t a_all15 = r->a;
                            bool carry_ret15 = r->c;
                            bool overflow_ret15 = r->v;
                            if (x_ret29) {
                                a_hi_aa0c2 = a_all15 >> 8;
                                y_aa0c2 = (uint8_t)value28;
                                carry_aa0c2 = carry_ret15;
                                overflow_aa0c2 = overflow_ret15;
                                direct_page_aa0c2 = dp_ret14;
                                data_bank_aa0c2 = db_ret15;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all15 >> 8;
                                y_aa0c3 = value28;
                                carry_aa0c3 = carry_ret15;
                                overflow_aa0c3 = overflow_ret15;
                                direct_page_aa0c3 = dp_ret14;
                                data_bank_aa0c3 = db_ret15;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                }
            } else {
                uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                uint16_t value31 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0A + value30);
                r->x = value31;
                r->y = value30;
                r->z = value31 == 0;
                r->n = value31 & 0x8000;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA9F9, 0x7EB23A); GUARD_JSR(c, sp_call, 0xA9F9); } /* release_record_chain */
                r->sp += 6;
                uint16_t dp_ret15 = r->dp;
                uint8_t db_ret16 = r->db;
                bool m_ret8 = r->mf;
                bool x_ret31 = r->xf;
                uint16_t a_all16 = r->a;
                if (x_ret31) {
                    uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp_ret15 + 1));
                    if (m_ret8) {
                        uint8_t value33 = BUS8_RDP(c, (db_ret16 << 0x10) + 4 + value32);
                        r->a = (a_all16 >> 8 << 8) | value33;
                        r->x = value32;
                        r->y = (uint8_t)value30;
                        r->z = value33 == 0;
                        r->n = value33 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret16 = r->dp;
                        uint8_t db_ret17 = r->db;
                        bool m_ret9 = r->mf;
                        bool x_ret33 = r->xf;
                        uint16_t a_all17 = r->a;
                        bool carry_ret17 = r->c;
                        bool overflow_ret17 = r->v;
                        if (x_ret33) {
                            uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp_ret16 + 1));
                            uint8_t value35 = BUS8_RDP(c, (db_ret17 << 0x10) + 8 + value34);
                            if (value35 == 0) {
                                if (m_ret9) {
                                    a_hi_aa0c = a_all17 >> 8;
                                    y_aa0c = value34;
                                    carry_aa0c = carry_ret17;
                                    overflow_aa0c = overflow_ret17;
                                    direct_page_aa0c = dp_ret16;
                                    data_bank_aa0c = db_ret17;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all17 >> 8;
                                    y_aa0c2 = value34;
                                    carry_aa0c2 = carry_ret17;
                                    overflow_aa0c2 = overflow_ret17;
                                    direct_page_aa0c2 = dp_ret16;
                                    data_bank_aa0c2 = db_ret17;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value35;
                            r->y = value34;
                            r->z = value35 == 0;
                            r->n = value35 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret17 = r->dp;
                            uint8_t db_ret18 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret35 = r->xf;
                            uint16_t a_all18 = r->a;
                            bool carry_ret18 = r->c;
                            bool overflow_ret18 = r->v;
                            if (x_ret35) {
                                a_hi_aa0c2 = a_all18 >> 8;
                                y_aa0c2 = value34;
                                carry_aa0c2 = carry_ret18;
                                overflow_aa0c2 = overflow_ret18;
                                direct_page_aa0c2 = dp_ret17;
                                data_bank_aa0c2 = db_ret18;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all18 >> 8;
                                y_aa0c3 = value34;
                                carry_aa0c3 = carry_ret18;
                                overflow_aa0c3 = overflow_ret18;
                                direct_page_aa0c3 = dp_ret17;
                                data_bank_aa0c3 = db_ret18;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp_ret16 + 1));
                            uint16_t value37 = BUS16_RDP(c, (db_ret17 << 0x10) + 8 + value36);
                            if (value37 == 0) {
                                if (m_ret9) {
                                    a_hi_aa0c4 = a_all17 >> 8;
                                    y_aa0c4 = value36;
                                    carry_aa0c4 = carry_ret17;
                                    overflow_aa0c4 = overflow_ret17;
                                    direct_page_aa0c4 = dp_ret16;
                                    data_bank_aa0c4 = db_ret17;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all17 >> 8;
                                    y_aa0c3 = value36;
                                    carry_aa0c3 = carry_ret17;
                                    overflow_aa0c3 = overflow_ret17;
                                    direct_page_aa0c3 = dp_ret16;
                                    data_bank_aa0c3 = db_ret17;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value37;
                            r->y = value36;
                            r->z = value37 == 0;
                            r->n = value37 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret18 = r->dp;
                            uint8_t db_ret19 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret37 = r->xf;
                            uint16_t a_all19 = r->a;
                            bool carry_ret19 = r->c;
                            bool overflow_ret19 = r->v;
                            if (x_ret37) {
                                a_hi_aa0c2 = a_all19 >> 8;
                                y_aa0c2 = (uint8_t)value36;
                                carry_aa0c2 = carry_ret19;
                                overflow_aa0c2 = overflow_ret19;
                                direct_page_aa0c2 = dp_ret18;
                                data_bank_aa0c2 = db_ret19;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all19 >> 8;
                                y_aa0c3 = value36;
                                carry_aa0c3 = carry_ret19;
                                overflow_aa0c3 = overflow_ret19;
                                direct_page_aa0c3 = dp_ret18;
                                data_bank_aa0c3 = db_ret19;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value38 = BUS16_RDP(c, (db_ret16 << 0x10) + 4 + value32);
                        r->a = value38;
                        r->x = value32;
                        r->y = (uint8_t)value30;
                        r->z = value38 == 0;
                        r->n = value38 & 0x8000;
                        r->mf = 0;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret19 = r->dp;
                        uint8_t db_ret20 = r->db;
                        bool m_ret10 = r->mf;
                        bool x_ret39 = r->xf;
                        uint16_t a_all20 = r->a;
                        bool carry_ret20 = r->c;
                        bool overflow_ret20 = r->v;
                        if (x_ret39) {
                            uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp_ret19 + 1));
                            uint8_t value40 = BUS8_RDP(c, (db_ret20 << 0x10) + 8 + value39);
                            if (value40 == 0) {
                                if (m_ret10) {
                                    a_hi_aa0c = a_all20 >> 8;
                                    y_aa0c = value39;
                                    carry_aa0c = carry_ret20;
                                    overflow_aa0c = overflow_ret20;
                                    direct_page_aa0c = dp_ret19;
                                    data_bank_aa0c = db_ret20;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all20 >> 8;
                                    y_aa0c2 = value39;
                                    carry_aa0c2 = carry_ret20;
                                    overflow_aa0c2 = overflow_ret20;
                                    direct_page_aa0c2 = dp_ret19;
                                    data_bank_aa0c2 = db_ret20;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value40;
                            r->y = value39;
                            r->z = value40 == 0;
                            r->n = value40 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret20 = r->dp;
                            uint8_t db_ret21 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret41 = r->xf;
                            uint16_t a_all21 = r->a;
                            bool carry_ret21 = r->c;
                            bool overflow_ret21 = r->v;
                            if (x_ret41) {
                                a_hi_aa0c2 = a_all21 >> 8;
                                y_aa0c2 = value39;
                                carry_aa0c2 = carry_ret21;
                                overflow_aa0c2 = overflow_ret21;
                                direct_page_aa0c2 = dp_ret20;
                                data_bank_aa0c2 = db_ret21;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all21 >> 8;
                                y_aa0c3 = value39;
                                carry_aa0c3 = carry_ret21;
                                overflow_aa0c3 = overflow_ret21;
                                direct_page_aa0c3 = dp_ret20;
                                data_bank_aa0c3 = db_ret21;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret19 + 1));
                            uint16_t value42 = BUS16_RDP(c, (db_ret20 << 0x10) + 8 + value41);
                            if (value42 == 0) {
                                if (m_ret10) {
                                    a_hi_aa0c4 = a_all20 >> 8;
                                    y_aa0c4 = value41;
                                    carry_aa0c4 = carry_ret20;
                                    overflow_aa0c4 = overflow_ret20;
                                    direct_page_aa0c4 = dp_ret19;
                                    data_bank_aa0c4 = db_ret20;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all20 >> 8;
                                    y_aa0c3 = value41;
                                    carry_aa0c3 = carry_ret20;
                                    overflow_aa0c3 = overflow_ret20;
                                    direct_page_aa0c3 = dp_ret19;
                                    data_bank_aa0c3 = db_ret20;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value42;
                            r->y = value41;
                            r->z = value42 == 0;
                            r->n = value42 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret21 = r->dp;
                            uint8_t db_ret22 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret43 = r->xf;
                            uint16_t a_all22 = r->a;
                            bool carry_ret22 = r->c;
                            bool overflow_ret22 = r->v;
                            if (x_ret43) {
                                a_hi_aa0c2 = a_all22 >> 8;
                                y_aa0c2 = (uint8_t)value41;
                                carry_aa0c2 = carry_ret22;
                                overflow_aa0c2 = overflow_ret22;
                                direct_page_aa0c2 = dp_ret21;
                                data_bank_aa0c2 = db_ret22;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all22 >> 8;
                                y_aa0c3 = value41;
                                carry_aa0c3 = carry_ret22;
                                overflow_aa0c3 = overflow_ret22;
                                direct_page_aa0c3 = dp_ret21;
                                data_bank_aa0c3 = db_ret22;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                } else {
                    uint16_t value43 = BUS16_RDP(c, (uint16_t)(dp_ret15 + 1));
                    if (m_ret8) {
                        uint8_t value44 = BUS8_RDP(c, (db_ret16 << 0x10) + 4 + value43);
                        r->a = (a_all16 >> 8 << 8) | value44;
                        r->x = value43;
                        r->z = value44 == 0;
                        r->n = value44 & 0x80;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret22 = r->dp;
                        uint8_t db_ret23 = r->db;
                        bool m_ret11 = r->mf;
                        bool x_ret45 = r->xf;
                        uint16_t a_all23 = r->a;
                        bool carry_ret23 = r->c;
                        bool overflow_ret23 = r->v;
                        if (x_ret45) {
                            uint8_t value45 = BUS8_RDP(c, (uint16_t)(dp_ret22 + 1));
                            uint8_t value46 = BUS8_RDP(c, (db_ret23 << 0x10) + 8 + value45);
                            if (value46 == 0) {
                                if (m_ret11) {
                                    a_hi_aa0c = a_all23 >> 8;
                                    y_aa0c = value45;
                                    carry_aa0c = carry_ret23;
                                    overflow_aa0c = overflow_ret23;
                                    direct_page_aa0c = dp_ret22;
                                    data_bank_aa0c = db_ret23;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all23 >> 8;
                                    y_aa0c2 = value45;
                                    carry_aa0c2 = carry_ret23;
                                    overflow_aa0c2 = overflow_ret23;
                                    direct_page_aa0c2 = dp_ret22;
                                    data_bank_aa0c2 = db_ret23;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value46;
                            r->y = value45;
                            r->z = value46 == 0;
                            r->n = value46 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret23 = r->dp;
                            uint8_t db_ret24 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret47 = r->xf;
                            uint16_t a_all24 = r->a;
                            bool carry_ret24 = r->c;
                            bool overflow_ret24 = r->v;
                            if (x_ret47) {
                                a_hi_aa0c2 = a_all24 >> 8;
                                y_aa0c2 = value45;
                                carry_aa0c2 = carry_ret24;
                                overflow_aa0c2 = overflow_ret24;
                                direct_page_aa0c2 = dp_ret23;
                                data_bank_aa0c2 = db_ret24;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all24 >> 8;
                                y_aa0c3 = value45;
                                carry_aa0c3 = carry_ret24;
                                overflow_aa0c3 = overflow_ret24;
                                direct_page_aa0c3 = dp_ret23;
                                data_bank_aa0c3 = db_ret24;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret22 + 1));
                            uint16_t value48 = BUS16_RDP(c, (db_ret23 << 0x10) + 8 + value47);
                            if (value48 == 0) {
                                if (m_ret11) {
                                    a_hi_aa0c4 = a_all23 >> 8;
                                    y_aa0c4 = value47;
                                    carry_aa0c4 = carry_ret23;
                                    overflow_aa0c4 = overflow_ret23;
                                    direct_page_aa0c4 = dp_ret22;
                                    data_bank_aa0c4 = db_ret23;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all23 >> 8;
                                    y_aa0c3 = value47;
                                    carry_aa0c3 = carry_ret23;
                                    overflow_aa0c3 = overflow_ret23;
                                    direct_page_aa0c3 = dp_ret22;
                                    data_bank_aa0c3 = db_ret23;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value48;
                            r->y = value47;
                            r->z = value48 == 0;
                            r->n = value48 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret24 = r->dp;
                            uint8_t db_ret25 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret49 = r->xf;
                            uint16_t a_all25 = r->a;
                            bool carry_ret25 = r->c;
                            bool overflow_ret25 = r->v;
                            if (x_ret49) {
                                a_hi_aa0c2 = a_all25 >> 8;
                                y_aa0c2 = (uint8_t)value47;
                                carry_aa0c2 = carry_ret25;
                                overflow_aa0c2 = overflow_ret25;
                                direct_page_aa0c2 = dp_ret24;
                                data_bank_aa0c2 = db_ret25;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all25 >> 8;
                                y_aa0c3 = value47;
                                carry_aa0c3 = carry_ret25;
                                overflow_aa0c3 = overflow_ret25;
                                direct_page_aa0c3 = dp_ret24;
                                data_bank_aa0c3 = db_ret25;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value49 = BUS16_RDP(c, (db_ret16 << 0x10) + 4 + value43);
                        r->a = value49;
                        r->x = value43;
                        r->z = value49 == 0;
                        r->n = value49 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret25 = r->dp;
                        uint8_t db_ret26 = r->db;
                        bool m_ret12 = r->mf;
                        bool x_ret51 = r->xf;
                        uint16_t a_all26 = r->a;
                        bool carry_ret26 = r->c;
                        bool overflow_ret26 = r->v;
                        if (x_ret51) {
                            uint8_t value50 = BUS8_RDP(c, (uint16_t)(dp_ret25 + 1));
                            uint8_t value51 = BUS8_RDP(c, (db_ret26 << 0x10) + 8 + value50);
                            if (value51 == 0) {
                                if (m_ret12) {
                                    a_hi_aa0c = a_all26 >> 8;
                                    y_aa0c = value50;
                                    carry_aa0c = carry_ret26;
                                    overflow_aa0c = overflow_ret26;
                                    direct_page_aa0c = dp_ret25;
                                    data_bank_aa0c = db_ret26;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all26 >> 8;
                                    y_aa0c2 = value50;
                                    carry_aa0c2 = carry_ret26;
                                    overflow_aa0c2 = overflow_ret26;
                                    direct_page_aa0c2 = dp_ret25;
                                    data_bank_aa0c2 = db_ret26;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value51;
                            r->y = value50;
                            r->z = value51 == 0;
                            r->n = value51 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret26 = r->dp;
                            uint8_t db_ret27 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret53 = r->xf;
                            uint16_t a_all27 = r->a;
                            bool carry_ret27 = r->c;
                            bool overflow_ret27 = r->v;
                            if (x_ret53) {
                                a_hi_aa0c2 = a_all27 >> 8;
                                y_aa0c2 = value50;
                                carry_aa0c2 = carry_ret27;
                                overflow_aa0c2 = overflow_ret27;
                                direct_page_aa0c2 = dp_ret26;
                                data_bank_aa0c2 = db_ret27;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all27 >> 8;
                                y_aa0c3 = value50;
                                carry_aa0c3 = carry_ret27;
                                overflow_aa0c3 = overflow_ret27;
                                direct_page_aa0c3 = dp_ret26;
                                data_bank_aa0c3 = db_ret27;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value52 = BUS16_RDP(c, (uint16_t)(dp_ret25 + 1));
                            uint16_t value53 = BUS16_RDP(c, (db_ret26 << 0x10) + 8 + value52);
                            if (value53 == 0) {
                                if (m_ret12) {
                                    a_hi_aa0c4 = a_all26 >> 8;
                                    y_aa0c4 = value52;
                                    carry_aa0c4 = carry_ret26;
                                    overflow_aa0c4 = overflow_ret26;
                                    direct_page_aa0c4 = dp_ret25;
                                    data_bank_aa0c4 = db_ret26;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all26 >> 8;
                                    y_aa0c3 = value52;
                                    carry_aa0c3 = carry_ret26;
                                    overflow_aa0c3 = overflow_ret26;
                                    direct_page_aa0c3 = dp_ret25;
                                    data_bank_aa0c3 = db_ret26;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value53;
                            r->y = value52;
                            r->z = value53 == 0;
                            r->n = value53 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret27 = r->dp;
                            uint8_t db_ret28 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret55 = r->xf;
                            uint16_t a_all28 = r->a;
                            bool carry_ret28 = r->c;
                            bool overflow_ret28 = r->v;
                            if (x_ret55) {
                                a_hi_aa0c2 = a_all28 >> 8;
                                y_aa0c2 = (uint8_t)value52;
                                carry_aa0c2 = carry_ret28;
                                overflow_aa0c2 = overflow_ret28;
                                direct_page_aa0c2 = dp_ret27;
                                data_bank_aa0c2 = db_ret28;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all28 >> 8;
                                y_aa0c3 = value52;
                                carry_aa0c3 = carry_ret28;
                                overflow_aa0c3 = overflow_ret28;
                                direct_page_aa0c3 = dp_ret27;
                                data_bank_aa0c3 = db_ret28;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                }
            }
        } else {
            uint16_t value54 = BUS16_RDP(c, (db_ret << 0x10) + 4 + value4);
            r->a = value54;
            r->x = value4;
            r->y = (uint8_t)y_ret;
            r->z = value54 == 0;
            r->n = value54 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA9F1, 0x7ECBDC); GUARD_JSR(c, sp_call, 0xA9F1); } /* clear_registrations_by_task */
            r->sp += 6;
            uint8_t db_ret29 = r->db;
            bool x_ret57 = r->xf;
            if (x_ret57) {
                uint8_t value55 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                uint8_t value56 = BUS8_RDP(c, (db_ret29 << 0x10) + 0x0A + value55);
                r->x = value56;
                r->y = value55;
                r->z = value56 == 0;
                r->n = value56 & 0x80;
                r->xf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA9F9, 0x7EB23A); GUARD_JSR(c, sp_call, 0xA9F9); } /* release_record_chain */
                r->sp += 6;
                uint16_t dp_ret28 = r->dp;
                uint8_t db_ret30 = r->db;
                bool m_ret14 = r->mf;
                bool x_ret59 = r->xf;
                uint16_t a_all30 = r->a;
                if (x_ret59) {
                    uint8_t value57 = BUS8_RDP(c, (uint16_t)(dp_ret28 + 1));
                    if (m_ret14) {
                        uint8_t value58 = BUS8_RDP(c, (db_ret30 << 0x10) + 4 + value57);
                        r->a = (a_all30 >> 8 << 8) | value58;
                        r->x = value57;
                        r->z = value58 == 0;
                        r->n = value58 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret29 = r->dp;
                        uint8_t db_ret31 = r->db;
                        bool m_ret15 = r->mf;
                        bool x_ret61 = r->xf;
                        uint16_t a_all31 = r->a;
                        bool carry_ret31 = r->c;
                        bool overflow_ret31 = r->v;
                        if (x_ret61) {
                            uint8_t value59 = BUS8_RDP(c, (uint16_t)(dp_ret29 + 1));
                            uint8_t value60 = BUS8_RDP(c, (db_ret31 << 0x10) + 8 + value59);
                            if (value60 == 0) {
                                if (m_ret15) {
                                    a_hi_aa0c = a_all31 >> 8;
                                    y_aa0c = value59;
                                    carry_aa0c = carry_ret31;
                                    overflow_aa0c = overflow_ret31;
                                    direct_page_aa0c = dp_ret29;
                                    data_bank_aa0c = db_ret31;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all31 >> 8;
                                    y_aa0c2 = value59;
                                    carry_aa0c2 = carry_ret31;
                                    overflow_aa0c2 = overflow_ret31;
                                    direct_page_aa0c2 = dp_ret29;
                                    data_bank_aa0c2 = db_ret31;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value60;
                            r->y = value59;
                            r->z = value60 == 0;
                            r->n = value60 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret30 = r->dp;
                            uint8_t db_ret32 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret63 = r->xf;
                            uint16_t a_all32 = r->a;
                            bool carry_ret32 = r->c;
                            bool overflow_ret32 = r->v;
                            if (x_ret63) {
                                a_hi_aa0c2 = a_all32 >> 8;
                                y_aa0c2 = value59;
                                carry_aa0c2 = carry_ret32;
                                overflow_aa0c2 = overflow_ret32;
                                direct_page_aa0c2 = dp_ret30;
                                data_bank_aa0c2 = db_ret32;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all32 >> 8;
                                y_aa0c3 = value59;
                                carry_aa0c3 = carry_ret32;
                                overflow_aa0c3 = overflow_ret32;
                                direct_page_aa0c3 = dp_ret30;
                                data_bank_aa0c3 = db_ret32;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret29 + 1));
                            uint16_t value62 = BUS16_RDP(c, (db_ret31 << 0x10) + 8 + value61);
                            if (value62 == 0) {
                                if (m_ret15) {
                                    a_hi_aa0c4 = a_all31 >> 8;
                                    y_aa0c4 = value61;
                                    carry_aa0c4 = carry_ret31;
                                    overflow_aa0c4 = overflow_ret31;
                                    direct_page_aa0c4 = dp_ret29;
                                    data_bank_aa0c4 = db_ret31;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all31 >> 8;
                                    y_aa0c3 = value61;
                                    carry_aa0c3 = carry_ret31;
                                    overflow_aa0c3 = overflow_ret31;
                                    direct_page_aa0c3 = dp_ret29;
                                    data_bank_aa0c3 = db_ret31;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value62;
                            r->y = value61;
                            r->z = value62 == 0;
                            r->n = value62 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret31 = r->dp;
                            uint8_t db_ret33 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret65 = r->xf;
                            uint16_t a_all33 = r->a;
                            bool carry_ret33 = r->c;
                            bool overflow_ret33 = r->v;
                            if (x_ret65) {
                                a_hi_aa0c2 = a_all33 >> 8;
                                y_aa0c2 = (uint8_t)value61;
                                carry_aa0c2 = carry_ret33;
                                overflow_aa0c2 = overflow_ret33;
                                direct_page_aa0c2 = dp_ret31;
                                data_bank_aa0c2 = db_ret33;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all33 >> 8;
                                y_aa0c3 = value61;
                                carry_aa0c3 = carry_ret33;
                                overflow_aa0c3 = overflow_ret33;
                                direct_page_aa0c3 = dp_ret31;
                                data_bank_aa0c3 = db_ret33;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value63 = BUS16_RDP(c, (db_ret30 << 0x10) + 4 + value57);
                        r->a = value63;
                        r->x = value57;
                        r->z = value63 == 0;
                        r->n = value63 & 0x8000;
                        r->mf = 0;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret32 = r->dp;
                        uint8_t db_ret34 = r->db;
                        bool m_ret16 = r->mf;
                        bool x_ret67 = r->xf;
                        uint16_t a_all34 = r->a;
                        bool carry_ret34 = r->c;
                        bool overflow_ret34 = r->v;
                        if (x_ret67) {
                            uint8_t value64 = BUS8_RDP(c, (uint16_t)(dp_ret32 + 1));
                            uint8_t value65 = BUS8_RDP(c, (db_ret34 << 0x10) + 8 + value64);
                            if (value65 == 0) {
                                if (m_ret16) {
                                    a_hi_aa0c = a_all34 >> 8;
                                    y_aa0c = value64;
                                    carry_aa0c = carry_ret34;
                                    overflow_aa0c = overflow_ret34;
                                    direct_page_aa0c = dp_ret32;
                                    data_bank_aa0c = db_ret34;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all34 >> 8;
                                    y_aa0c2 = value64;
                                    carry_aa0c2 = carry_ret34;
                                    overflow_aa0c2 = overflow_ret34;
                                    direct_page_aa0c2 = dp_ret32;
                                    data_bank_aa0c2 = db_ret34;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value65;
                            r->y = value64;
                            r->z = value65 == 0;
                            r->n = value65 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret33 = r->dp;
                            uint8_t db_ret35 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret69 = r->xf;
                            uint16_t a_all35 = r->a;
                            bool carry_ret35 = r->c;
                            bool overflow_ret35 = r->v;
                            if (x_ret69) {
                                a_hi_aa0c2 = a_all35 >> 8;
                                y_aa0c2 = value64;
                                carry_aa0c2 = carry_ret35;
                                overflow_aa0c2 = overflow_ret35;
                                direct_page_aa0c2 = dp_ret33;
                                data_bank_aa0c2 = db_ret35;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all35 >> 8;
                                y_aa0c3 = value64;
                                carry_aa0c3 = carry_ret35;
                                overflow_aa0c3 = overflow_ret35;
                                direct_page_aa0c3 = dp_ret33;
                                data_bank_aa0c3 = db_ret35;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value66 = BUS16_RDP(c, (uint16_t)(dp_ret32 + 1));
                            uint16_t value67 = BUS16_RDP(c, (db_ret34 << 0x10) + 8 + value66);
                            if (value67 == 0) {
                                if (m_ret16) {
                                    a_hi_aa0c4 = a_all34 >> 8;
                                    y_aa0c4 = value66;
                                    carry_aa0c4 = carry_ret34;
                                    overflow_aa0c4 = overflow_ret34;
                                    direct_page_aa0c4 = dp_ret32;
                                    data_bank_aa0c4 = db_ret34;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all34 >> 8;
                                    y_aa0c3 = value66;
                                    carry_aa0c3 = carry_ret34;
                                    overflow_aa0c3 = overflow_ret34;
                                    direct_page_aa0c3 = dp_ret32;
                                    data_bank_aa0c3 = db_ret34;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value67;
                            r->y = value66;
                            r->z = value67 == 0;
                            r->n = value67 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret34 = r->dp;
                            uint8_t db_ret36 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret71 = r->xf;
                            uint16_t a_all36 = r->a;
                            bool carry_ret36 = r->c;
                            bool overflow_ret36 = r->v;
                            if (x_ret71) {
                                a_hi_aa0c2 = a_all36 >> 8;
                                y_aa0c2 = (uint8_t)value66;
                                carry_aa0c2 = carry_ret36;
                                overflow_aa0c2 = overflow_ret36;
                                direct_page_aa0c2 = dp_ret34;
                                data_bank_aa0c2 = db_ret36;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all36 >> 8;
                                y_aa0c3 = value66;
                                carry_aa0c3 = carry_ret36;
                                overflow_aa0c3 = overflow_ret36;
                                direct_page_aa0c3 = dp_ret34;
                                data_bank_aa0c3 = db_ret36;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                } else {
                    uint16_t value68 = BUS16_RDP(c, (uint16_t)(dp_ret28 + 1));
                    if (m_ret14) {
                        uint8_t value69 = BUS8_RDP(c, (db_ret30 << 0x10) + 4 + value68);
                        r->a = (a_all30 >> 8 << 8) | value69;
                        r->x = value68;
                        r->z = value69 == 0;
                        r->n = value69 & 0x80;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret35 = r->dp;
                        uint8_t db_ret37 = r->db;
                        bool m_ret17 = r->mf;
                        bool x_ret73 = r->xf;
                        uint16_t a_all37 = r->a;
                        bool carry_ret37 = r->c;
                        bool overflow_ret37 = r->v;
                        if (x_ret73) {
                            uint8_t value70 = BUS8_RDP(c, (uint16_t)(dp_ret35 + 1));
                            uint8_t value71 = BUS8_RDP(c, (db_ret37 << 0x10) + 8 + value70);
                            if (value71 == 0) {
                                if (m_ret17) {
                                    a_hi_aa0c = a_all37 >> 8;
                                    y_aa0c = value70;
                                    carry_aa0c = carry_ret37;
                                    overflow_aa0c = overflow_ret37;
                                    direct_page_aa0c = dp_ret35;
                                    data_bank_aa0c = db_ret37;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all37 >> 8;
                                    y_aa0c2 = value70;
                                    carry_aa0c2 = carry_ret37;
                                    overflow_aa0c2 = overflow_ret37;
                                    direct_page_aa0c2 = dp_ret35;
                                    data_bank_aa0c2 = db_ret37;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value71;
                            r->y = value70;
                            r->z = value71 == 0;
                            r->n = value71 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret36 = r->dp;
                            uint8_t db_ret38 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret75 = r->xf;
                            uint16_t a_all38 = r->a;
                            bool carry_ret38 = r->c;
                            bool overflow_ret38 = r->v;
                            if (x_ret75) {
                                a_hi_aa0c2 = a_all38 >> 8;
                                y_aa0c2 = value70;
                                carry_aa0c2 = carry_ret38;
                                overflow_aa0c2 = overflow_ret38;
                                direct_page_aa0c2 = dp_ret36;
                                data_bank_aa0c2 = db_ret38;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all38 >> 8;
                                y_aa0c3 = value70;
                                carry_aa0c3 = carry_ret38;
                                overflow_aa0c3 = overflow_ret38;
                                direct_page_aa0c3 = dp_ret36;
                                data_bank_aa0c3 = db_ret38;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value72 = BUS16_RDP(c, (uint16_t)(dp_ret35 + 1));
                            uint16_t value73 = BUS16_RDP(c, (db_ret37 << 0x10) + 8 + value72);
                            if (value73 == 0) {
                                if (m_ret17) {
                                    a_hi_aa0c4 = a_all37 >> 8;
                                    y_aa0c4 = value72;
                                    carry_aa0c4 = carry_ret37;
                                    overflow_aa0c4 = overflow_ret37;
                                    direct_page_aa0c4 = dp_ret35;
                                    data_bank_aa0c4 = db_ret37;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all37 >> 8;
                                    y_aa0c3 = value72;
                                    carry_aa0c3 = carry_ret37;
                                    overflow_aa0c3 = overflow_ret37;
                                    direct_page_aa0c3 = dp_ret35;
                                    data_bank_aa0c3 = db_ret37;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value73;
                            r->y = value72;
                            r->z = value73 == 0;
                            r->n = value73 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret37 = r->dp;
                            uint8_t db_ret39 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret77 = r->xf;
                            uint16_t a_all39 = r->a;
                            bool carry_ret39 = r->c;
                            bool overflow_ret39 = r->v;
                            if (x_ret77) {
                                a_hi_aa0c2 = a_all39 >> 8;
                                y_aa0c2 = (uint8_t)value72;
                                carry_aa0c2 = carry_ret39;
                                overflow_aa0c2 = overflow_ret39;
                                direct_page_aa0c2 = dp_ret37;
                                data_bank_aa0c2 = db_ret39;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all39 >> 8;
                                y_aa0c3 = value72;
                                carry_aa0c3 = carry_ret39;
                                overflow_aa0c3 = overflow_ret39;
                                direct_page_aa0c3 = dp_ret37;
                                data_bank_aa0c3 = db_ret39;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value74 = BUS16_RDP(c, (db_ret30 << 0x10) + 4 + value68);
                        r->a = value74;
                        r->x = value68;
                        r->z = value74 == 0;
                        r->n = value74 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret38 = r->dp;
                        uint8_t db_ret40 = r->db;
                        bool m_ret18 = r->mf;
                        bool x_ret79 = r->xf;
                        uint16_t a_all40 = r->a;
                        bool carry_ret40 = r->c;
                        bool overflow_ret40 = r->v;
                        if (x_ret79) {
                            uint8_t value75 = BUS8_RDP(c, (uint16_t)(dp_ret38 + 1));
                            uint8_t value76 = BUS8_RDP(c, (db_ret40 << 0x10) + 8 + value75);
                            if (value76 == 0) {
                                if (m_ret18) {
                                    a_hi_aa0c = a_all40 >> 8;
                                    y_aa0c = value75;
                                    carry_aa0c = carry_ret40;
                                    overflow_aa0c = overflow_ret40;
                                    direct_page_aa0c = dp_ret38;
                                    data_bank_aa0c = db_ret40;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all40 >> 8;
                                    y_aa0c2 = value75;
                                    carry_aa0c2 = carry_ret40;
                                    overflow_aa0c2 = overflow_ret40;
                                    direct_page_aa0c2 = dp_ret38;
                                    data_bank_aa0c2 = db_ret40;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value76;
                            r->y = value75;
                            r->z = value76 == 0;
                            r->n = value76 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret39 = r->dp;
                            uint8_t db_ret41 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret81 = r->xf;
                            uint16_t a_all41 = r->a;
                            bool carry_ret41 = r->c;
                            bool overflow_ret41 = r->v;
                            if (x_ret81) {
                                a_hi_aa0c2 = a_all41 >> 8;
                                y_aa0c2 = value75;
                                carry_aa0c2 = carry_ret41;
                                overflow_aa0c2 = overflow_ret41;
                                direct_page_aa0c2 = dp_ret39;
                                data_bank_aa0c2 = db_ret41;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all41 >> 8;
                                y_aa0c3 = value75;
                                carry_aa0c3 = carry_ret41;
                                overflow_aa0c3 = overflow_ret41;
                                direct_page_aa0c3 = dp_ret39;
                                data_bank_aa0c3 = db_ret41;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value77 = BUS16_RDP(c, (uint16_t)(dp_ret38 + 1));
                            uint16_t value78 = BUS16_RDP(c, (db_ret40 << 0x10) + 8 + value77);
                            if (value78 == 0) {
                                if (m_ret18) {
                                    a_hi_aa0c4 = a_all40 >> 8;
                                    y_aa0c4 = value77;
                                    carry_aa0c4 = carry_ret40;
                                    overflow_aa0c4 = overflow_ret40;
                                    direct_page_aa0c4 = dp_ret38;
                                    data_bank_aa0c4 = db_ret40;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all40 >> 8;
                                    y_aa0c3 = value77;
                                    carry_aa0c3 = carry_ret40;
                                    overflow_aa0c3 = overflow_ret40;
                                    direct_page_aa0c3 = dp_ret38;
                                    data_bank_aa0c3 = db_ret40;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value78;
                            r->y = value77;
                            r->z = value78 == 0;
                            r->n = value78 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret40 = r->dp;
                            uint8_t db_ret42 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret83 = r->xf;
                            uint16_t a_all42 = r->a;
                            bool carry_ret42 = r->c;
                            bool overflow_ret42 = r->v;
                            if (x_ret83) {
                                a_hi_aa0c2 = a_all42 >> 8;
                                y_aa0c2 = (uint8_t)value77;
                                carry_aa0c2 = carry_ret42;
                                overflow_aa0c2 = overflow_ret42;
                                direct_page_aa0c2 = dp_ret40;
                                data_bank_aa0c2 = db_ret42;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all42 >> 8;
                                y_aa0c3 = value77;
                                carry_aa0c3 = carry_ret42;
                                overflow_aa0c3 = overflow_ret42;
                                direct_page_aa0c3 = dp_ret40;
                                data_bank_aa0c3 = db_ret42;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                }
            } else {
                uint16_t value79 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                uint16_t value80 = BUS16_RDP(c, (db_ret29 << 0x10) + 0x0A + value79);
                r->x = value80;
                r->y = value79;
                r->z = value80 == 0;
                r->n = value80 & 0x8000;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA9F9, 0x7EB23A); GUARD_JSR(c, sp_call, 0xA9F9); } /* release_record_chain */
                r->sp += 6;
                uint16_t dp_ret41 = r->dp;
                uint8_t db_ret43 = r->db;
                bool m_ret19 = r->mf;
                bool x_ret85 = r->xf;
                uint16_t a_all43 = r->a;
                if (x_ret85) {
                    uint8_t value81 = BUS8_RDP(c, (uint16_t)(dp_ret41 + 1));
                    if (m_ret19) {
                        uint8_t value82 = BUS8_RDP(c, (db_ret43 << 0x10) + 4 + value81);
                        r->a = (a_all43 >> 8 << 8) | value82;
                        r->x = value81;
                        r->y = (uint8_t)value79;
                        r->z = value82 == 0;
                        r->n = value82 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret42 = r->dp;
                        uint8_t db_ret44 = r->db;
                        bool m_ret20 = r->mf;
                        bool x_ret87 = r->xf;
                        uint16_t a_all44 = r->a;
                        bool carry_ret44 = r->c;
                        bool overflow_ret44 = r->v;
                        if (x_ret87) {
                            uint8_t value83 = BUS8_RDP(c, (uint16_t)(dp_ret42 + 1));
                            uint8_t value84 = BUS8_RDP(c, (db_ret44 << 0x10) + 8 + value83);
                            if (value84 == 0) {
                                if (m_ret20) {
                                    a_hi_aa0c = a_all44 >> 8;
                                    y_aa0c = value83;
                                    carry_aa0c = carry_ret44;
                                    overflow_aa0c = overflow_ret44;
                                    direct_page_aa0c = dp_ret42;
                                    data_bank_aa0c = db_ret44;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all44 >> 8;
                                    y_aa0c2 = value83;
                                    carry_aa0c2 = carry_ret44;
                                    overflow_aa0c2 = overflow_ret44;
                                    direct_page_aa0c2 = dp_ret42;
                                    data_bank_aa0c2 = db_ret44;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value84;
                            r->y = value83;
                            r->z = value84 == 0;
                            r->n = value84 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret43 = r->dp;
                            uint8_t db_ret45 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret89 = r->xf;
                            uint16_t a_all45 = r->a;
                            bool carry_ret45 = r->c;
                            bool overflow_ret45 = r->v;
                            if (x_ret89) {
                                a_hi_aa0c2 = a_all45 >> 8;
                                y_aa0c2 = value83;
                                carry_aa0c2 = carry_ret45;
                                overflow_aa0c2 = overflow_ret45;
                                direct_page_aa0c2 = dp_ret43;
                                data_bank_aa0c2 = db_ret45;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all45 >> 8;
                                y_aa0c3 = value83;
                                carry_aa0c3 = carry_ret45;
                                overflow_aa0c3 = overflow_ret45;
                                direct_page_aa0c3 = dp_ret43;
                                data_bank_aa0c3 = db_ret45;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value85 = BUS16_RDP(c, (uint16_t)(dp_ret42 + 1));
                            uint16_t value86 = BUS16_RDP(c, (db_ret44 << 0x10) + 8 + value85);
                            if (value86 == 0) {
                                if (m_ret20) {
                                    a_hi_aa0c4 = a_all44 >> 8;
                                    y_aa0c4 = value85;
                                    carry_aa0c4 = carry_ret44;
                                    overflow_aa0c4 = overflow_ret44;
                                    direct_page_aa0c4 = dp_ret42;
                                    data_bank_aa0c4 = db_ret44;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all44 >> 8;
                                    y_aa0c3 = value85;
                                    carry_aa0c3 = carry_ret44;
                                    overflow_aa0c3 = overflow_ret44;
                                    direct_page_aa0c3 = dp_ret42;
                                    data_bank_aa0c3 = db_ret44;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value86;
                            r->y = value85;
                            r->z = value86 == 0;
                            r->n = value86 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret44 = r->dp;
                            uint8_t db_ret46 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret91 = r->xf;
                            uint16_t a_all46 = r->a;
                            bool carry_ret46 = r->c;
                            bool overflow_ret46 = r->v;
                            if (x_ret91) {
                                a_hi_aa0c2 = a_all46 >> 8;
                                y_aa0c2 = (uint8_t)value85;
                                carry_aa0c2 = carry_ret46;
                                overflow_aa0c2 = overflow_ret46;
                                direct_page_aa0c2 = dp_ret44;
                                data_bank_aa0c2 = db_ret46;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all46 >> 8;
                                y_aa0c3 = value85;
                                carry_aa0c3 = carry_ret46;
                                overflow_aa0c3 = overflow_ret46;
                                direct_page_aa0c3 = dp_ret44;
                                data_bank_aa0c3 = db_ret46;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value87 = BUS16_RDP(c, (db_ret43 << 0x10) + 4 + value81);
                        r->a = value87;
                        r->x = value81;
                        r->y = (uint8_t)value79;
                        r->z = value87 == 0;
                        r->n = value87 & 0x8000;
                        r->mf = 0;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret45 = r->dp;
                        uint8_t db_ret47 = r->db;
                        bool m_ret21 = r->mf;
                        bool x_ret93 = r->xf;
                        uint16_t a_all47 = r->a;
                        bool carry_ret47 = r->c;
                        bool overflow_ret47 = r->v;
                        if (x_ret93) {
                            uint8_t value88 = BUS8_RDP(c, (uint16_t)(dp_ret45 + 1));
                            uint8_t value89 = BUS8_RDP(c, (db_ret47 << 0x10) + 8 + value88);
                            if (value89 == 0) {
                                if (m_ret21) {
                                    a_hi_aa0c = a_all47 >> 8;
                                    y_aa0c = value88;
                                    carry_aa0c = carry_ret47;
                                    overflow_aa0c = overflow_ret47;
                                    direct_page_aa0c = dp_ret45;
                                    data_bank_aa0c = db_ret47;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all47 >> 8;
                                    y_aa0c2 = value88;
                                    carry_aa0c2 = carry_ret47;
                                    overflow_aa0c2 = overflow_ret47;
                                    direct_page_aa0c2 = dp_ret45;
                                    data_bank_aa0c2 = db_ret47;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value89;
                            r->y = value88;
                            r->z = value89 == 0;
                            r->n = value89 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret46 = r->dp;
                            uint8_t db_ret48 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret95 = r->xf;
                            uint16_t a_all48 = r->a;
                            bool carry_ret48 = r->c;
                            bool overflow_ret48 = r->v;
                            if (x_ret95) {
                                a_hi_aa0c2 = a_all48 >> 8;
                                y_aa0c2 = value88;
                                carry_aa0c2 = carry_ret48;
                                overflow_aa0c2 = overflow_ret48;
                                direct_page_aa0c2 = dp_ret46;
                                data_bank_aa0c2 = db_ret48;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all48 >> 8;
                                y_aa0c3 = value88;
                                carry_aa0c3 = carry_ret48;
                                overflow_aa0c3 = overflow_ret48;
                                direct_page_aa0c3 = dp_ret46;
                                data_bank_aa0c3 = db_ret48;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value90 = BUS16_RDP(c, (uint16_t)(dp_ret45 + 1));
                            uint16_t value91 = BUS16_RDP(c, (db_ret47 << 0x10) + 8 + value90);
                            if (value91 == 0) {
                                if (m_ret21) {
                                    a_hi_aa0c4 = a_all47 >> 8;
                                    y_aa0c4 = value90;
                                    carry_aa0c4 = carry_ret47;
                                    overflow_aa0c4 = overflow_ret47;
                                    direct_page_aa0c4 = dp_ret45;
                                    data_bank_aa0c4 = db_ret47;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all47 >> 8;
                                    y_aa0c3 = value90;
                                    carry_aa0c3 = carry_ret47;
                                    overflow_aa0c3 = overflow_ret47;
                                    direct_page_aa0c3 = dp_ret45;
                                    data_bank_aa0c3 = db_ret47;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value91;
                            r->y = value90;
                            r->z = value91 == 0;
                            r->n = value91 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret47 = r->dp;
                            uint8_t db_ret49 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret97 = r->xf;
                            uint16_t a_all49 = r->a;
                            bool carry_ret49 = r->c;
                            bool overflow_ret49 = r->v;
                            if (x_ret97) {
                                a_hi_aa0c2 = a_all49 >> 8;
                                y_aa0c2 = (uint8_t)value90;
                                carry_aa0c2 = carry_ret49;
                                overflow_aa0c2 = overflow_ret49;
                                direct_page_aa0c2 = dp_ret47;
                                data_bank_aa0c2 = db_ret49;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all49 >> 8;
                                y_aa0c3 = value90;
                                carry_aa0c3 = carry_ret49;
                                overflow_aa0c3 = overflow_ret49;
                                direct_page_aa0c3 = dp_ret47;
                                data_bank_aa0c3 = db_ret49;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                } else {
                    uint16_t value92 = BUS16_RDP(c, (uint16_t)(dp_ret41 + 1));
                    if (m_ret19) {
                        uint8_t value93 = BUS8_RDP(c, (db_ret43 << 0x10) + 4 + value92);
                        r->a = (a_all43 >> 8 << 8) | value93;
                        r->x = value92;
                        r->z = value93 == 0;
                        r->n = value93 & 0x80;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret48 = r->dp;
                        uint8_t db_ret50 = r->db;
                        bool m_ret22 = r->mf;
                        bool x_ret99 = r->xf;
                        uint16_t a_all50 = r->a;
                        bool carry_ret50 = r->c;
                        bool overflow_ret50 = r->v;
                        if (x_ret99) {
                            uint8_t value94 = BUS8_RDP(c, (uint16_t)(dp_ret48 + 1));
                            uint8_t value95 = BUS8_RDP(c, (db_ret50 << 0x10) + 8 + value94);
                            if (value95 == 0) {
                                if (m_ret22) {
                                    a_hi_aa0c = a_all50 >> 8;
                                    y_aa0c = value94;
                                    carry_aa0c = carry_ret50;
                                    overflow_aa0c = overflow_ret50;
                                    direct_page_aa0c = dp_ret48;
                                    data_bank_aa0c = db_ret50;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all50 >> 8;
                                    y_aa0c2 = value94;
                                    carry_aa0c2 = carry_ret50;
                                    overflow_aa0c2 = overflow_ret50;
                                    direct_page_aa0c2 = dp_ret48;
                                    data_bank_aa0c2 = db_ret50;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value95;
                            r->y = value94;
                            r->z = value95 == 0;
                            r->n = value95 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret49 = r->dp;
                            uint8_t db_ret51 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret101 = r->xf;
                            uint16_t a_all51 = r->a;
                            bool carry_ret51 = r->c;
                            bool overflow_ret51 = r->v;
                            if (x_ret101) {
                                a_hi_aa0c2 = a_all51 >> 8;
                                y_aa0c2 = value94;
                                carry_aa0c2 = carry_ret51;
                                overflow_aa0c2 = overflow_ret51;
                                direct_page_aa0c2 = dp_ret49;
                                data_bank_aa0c2 = db_ret51;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all51 >> 8;
                                y_aa0c3 = value94;
                                carry_aa0c3 = carry_ret51;
                                overflow_aa0c3 = overflow_ret51;
                                direct_page_aa0c3 = dp_ret49;
                                data_bank_aa0c3 = db_ret51;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value96 = BUS16_RDP(c, (uint16_t)(dp_ret48 + 1));
                            uint16_t value97 = BUS16_RDP(c, (db_ret50 << 0x10) + 8 + value96);
                            if (value97 == 0) {
                                if (m_ret22) {
                                    a_hi_aa0c4 = a_all50 >> 8;
                                    y_aa0c4 = value96;
                                    carry_aa0c4 = carry_ret50;
                                    overflow_aa0c4 = overflow_ret50;
                                    direct_page_aa0c4 = dp_ret48;
                                    data_bank_aa0c4 = db_ret50;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all50 >> 8;
                                    y_aa0c3 = value96;
                                    carry_aa0c3 = carry_ret50;
                                    overflow_aa0c3 = overflow_ret50;
                                    direct_page_aa0c3 = dp_ret48;
                                    data_bank_aa0c3 = db_ret50;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value97;
                            r->y = value96;
                            r->z = value97 == 0;
                            r->n = value97 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret50 = r->dp;
                            uint8_t db_ret52 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret103 = r->xf;
                            uint16_t a_all52 = r->a;
                            bool carry_ret52 = r->c;
                            bool overflow_ret52 = r->v;
                            if (x_ret103) {
                                a_hi_aa0c2 = a_all52 >> 8;
                                y_aa0c2 = (uint8_t)value96;
                                carry_aa0c2 = carry_ret52;
                                overflow_aa0c2 = overflow_ret52;
                                direct_page_aa0c2 = dp_ret50;
                                data_bank_aa0c2 = db_ret52;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all52 >> 8;
                                y_aa0c3 = value96;
                                carry_aa0c3 = carry_ret52;
                                overflow_aa0c3 = overflow_ret52;
                                direct_page_aa0c3 = dp_ret50;
                                data_bank_aa0c3 = db_ret52;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value98 = BUS16_RDP(c, (db_ret43 << 0x10) + 4 + value92);
                        r->a = value98;
                        r->x = value92;
                        r->z = value98 == 0;
                        r->n = value98 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret51 = r->dp;
                        uint8_t db_ret53 = r->db;
                        bool m_ret23 = r->mf;
                        bool x_ret105 = r->xf;
                        uint16_t a_all53 = r->a;
                        bool carry_ret53 = r->c;
                        bool overflow_ret53 = r->v;
                        if (x_ret105) {
                            uint8_t value99 = BUS8_RDP(c, (uint16_t)(dp_ret51 + 1));
                            uint8_t value100 = BUS8_RDP(c, (db_ret53 << 0x10) + 8 + value99);
                            if (value100 == 0) {
                                if (m_ret23) {
                                    a_hi_aa0c = a_all53 >> 8;
                                    y_aa0c = value99;
                                    carry_aa0c = carry_ret53;
                                    overflow_aa0c = overflow_ret53;
                                    direct_page_aa0c = dp_ret51;
                                    data_bank_aa0c = db_ret53;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all53 >> 8;
                                    y_aa0c2 = value99;
                                    carry_aa0c2 = carry_ret53;
                                    overflow_aa0c2 = overflow_ret53;
                                    direct_page_aa0c2 = dp_ret51;
                                    data_bank_aa0c2 = db_ret53;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value100;
                            r->y = value99;
                            r->z = value100 == 0;
                            r->n = value100 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret52 = r->dp;
                            uint8_t db_ret54 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret107 = r->xf;
                            uint16_t a_all54 = r->a;
                            bool carry_ret54 = r->c;
                            bool overflow_ret54 = r->v;
                            if (x_ret107) {
                                a_hi_aa0c2 = a_all54 >> 8;
                                y_aa0c2 = value99;
                                carry_aa0c2 = carry_ret54;
                                overflow_aa0c2 = overflow_ret54;
                                direct_page_aa0c2 = dp_ret52;
                                data_bank_aa0c2 = db_ret54;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all54 >> 8;
                                y_aa0c3 = value99;
                                carry_aa0c3 = carry_ret54;
                                overflow_aa0c3 = overflow_ret54;
                                direct_page_aa0c3 = dp_ret52;
                                data_bank_aa0c3 = db_ret54;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value101 = BUS16_RDP(c, (uint16_t)(dp_ret51 + 1));
                            uint16_t value102 = BUS16_RDP(c, (db_ret53 << 0x10) + 8 + value101);
                            if (value102 == 0) {
                                if (m_ret23) {
                                    a_hi_aa0c4 = a_all53 >> 8;
                                    y_aa0c4 = value101;
                                    carry_aa0c4 = carry_ret53;
                                    overflow_aa0c4 = overflow_ret53;
                                    direct_page_aa0c4 = dp_ret51;
                                    data_bank_aa0c4 = db_ret53;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all53 >> 8;
                                    y_aa0c3 = value101;
                                    carry_aa0c3 = carry_ret53;
                                    overflow_aa0c3 = overflow_ret53;
                                    direct_page_aa0c3 = dp_ret51;
                                    data_bank_aa0c3 = db_ret53;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value102;
                            r->y = value101;
                            r->z = value102 == 0;
                            r->n = value102 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret53 = r->dp;
                            uint8_t db_ret55 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret109 = r->xf;
                            uint16_t a_all55 = r->a;
                            bool carry_ret55 = r->c;
                            bool overflow_ret55 = r->v;
                            if (x_ret109) {
                                a_hi_aa0c2 = a_all55 >> 8;
                                y_aa0c2 = (uint8_t)value101;
                                carry_aa0c2 = carry_ret55;
                                overflow_aa0c2 = overflow_ret55;
                                direct_page_aa0c2 = dp_ret53;
                                data_bank_aa0c2 = db_ret55;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all55 >> 8;
                                y_aa0c3 = value101;
                                carry_aa0c3 = carry_ret55;
                                overflow_aa0c3 = overflow_ret55;
                                direct_page_aa0c3 = dp_ret53;
                                data_bank_aa0c3 = db_ret55;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                }
            }
        }
    } else {
        uint16_t value103 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        if (m_ret) {
            uint8_t value104 = BUS8_RDP(c, (db_ret << 0x10) + 4 + value103);
            r->a = (a_all >> 8 << 8) | value104;
            r->x = value103;
            r->z = value104 == 0;
            r->n = value104 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA9F1, 0x7ECBDC); GUARD_JSR(c, sp_call, 0xA9F1); } /* clear_registrations_by_task */
            r->sp += 6;
            uint8_t db_ret56 = r->db;
            bool x_ret111 = r->xf;
            if (x_ret111) {
                uint8_t value105 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                uint8_t value106 = BUS8_RDP(c, (db_ret56 << 0x10) + 0x0A + value105);
                r->x = value106;
                r->y = value105;
                r->z = value106 == 0;
                r->n = value106 & 0x80;
                r->xf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA9F9, 0x7EB23A); GUARD_JSR(c, sp_call, 0xA9F9); } /* release_record_chain */
                r->sp += 6;
                uint16_t dp_ret54 = r->dp;
                uint8_t db_ret57 = r->db;
                bool m_ret25 = r->mf;
                bool x_ret113 = r->xf;
                uint16_t a_all57 = r->a;
                if (x_ret113) {
                    uint8_t value107 = BUS8_RDP(c, (uint16_t)(dp_ret54 + 1));
                    if (m_ret25) {
                        uint8_t value108 = BUS8_RDP(c, (db_ret57 << 0x10) + 4 + value107);
                        r->a = (a_all57 >> 8 << 8) | value108;
                        r->x = value107;
                        r->z = value108 == 0;
                        r->n = value108 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret55 = r->dp;
                        uint8_t db_ret58 = r->db;
                        bool m_ret26 = r->mf;
                        bool x_ret115 = r->xf;
                        uint16_t a_all58 = r->a;
                        bool carry_ret58 = r->c;
                        bool overflow_ret58 = r->v;
                        if (x_ret115) {
                            uint8_t value109 = BUS8_RDP(c, (uint16_t)(dp_ret55 + 1));
                            uint8_t value110 = BUS8_RDP(c, (db_ret58 << 0x10) + 8 + value109);
                            if (value110 == 0) {
                                if (m_ret26) {
                                    a_hi_aa0c = a_all58 >> 8;
                                    y_aa0c = value109;
                                    carry_aa0c = carry_ret58;
                                    overflow_aa0c = overflow_ret58;
                                    direct_page_aa0c = dp_ret55;
                                    data_bank_aa0c = db_ret58;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all58 >> 8;
                                    y_aa0c2 = value109;
                                    carry_aa0c2 = carry_ret58;
                                    overflow_aa0c2 = overflow_ret58;
                                    direct_page_aa0c2 = dp_ret55;
                                    data_bank_aa0c2 = db_ret58;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value110;
                            r->y = value109;
                            r->z = value110 == 0;
                            r->n = value110 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret56 = r->dp;
                            uint8_t db_ret59 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret117 = r->xf;
                            uint16_t a_all59 = r->a;
                            bool carry_ret59 = r->c;
                            bool overflow_ret59 = r->v;
                            if (x_ret117) {
                                a_hi_aa0c2 = a_all59 >> 8;
                                y_aa0c2 = value109;
                                carry_aa0c2 = carry_ret59;
                                overflow_aa0c2 = overflow_ret59;
                                direct_page_aa0c2 = dp_ret56;
                                data_bank_aa0c2 = db_ret59;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all59 >> 8;
                                y_aa0c3 = value109;
                                carry_aa0c3 = carry_ret59;
                                overflow_aa0c3 = overflow_ret59;
                                direct_page_aa0c3 = dp_ret56;
                                data_bank_aa0c3 = db_ret59;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value111 = BUS16_RDP(c, (uint16_t)(dp_ret55 + 1));
                            uint16_t value112 = BUS16_RDP(c, (db_ret58 << 0x10) + 8 + value111);
                            if (value112 == 0) {
                                if (m_ret26) {
                                    a_hi_aa0c4 = a_all58 >> 8;
                                    y_aa0c4 = value111;
                                    carry_aa0c4 = carry_ret58;
                                    overflow_aa0c4 = overflow_ret58;
                                    direct_page_aa0c4 = dp_ret55;
                                    data_bank_aa0c4 = db_ret58;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all58 >> 8;
                                    y_aa0c3 = value111;
                                    carry_aa0c3 = carry_ret58;
                                    overflow_aa0c3 = overflow_ret58;
                                    direct_page_aa0c3 = dp_ret55;
                                    data_bank_aa0c3 = db_ret58;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value112;
                            r->y = value111;
                            r->z = value112 == 0;
                            r->n = value112 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret57 = r->dp;
                            uint8_t db_ret60 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret119 = r->xf;
                            uint16_t a_all60 = r->a;
                            bool carry_ret60 = r->c;
                            bool overflow_ret60 = r->v;
                            if (x_ret119) {
                                a_hi_aa0c2 = a_all60 >> 8;
                                y_aa0c2 = (uint8_t)value111;
                                carry_aa0c2 = carry_ret60;
                                overflow_aa0c2 = overflow_ret60;
                                direct_page_aa0c2 = dp_ret57;
                                data_bank_aa0c2 = db_ret60;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all60 >> 8;
                                y_aa0c3 = value111;
                                carry_aa0c3 = carry_ret60;
                                overflow_aa0c3 = overflow_ret60;
                                direct_page_aa0c3 = dp_ret57;
                                data_bank_aa0c3 = db_ret60;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value113 = BUS16_RDP(c, (db_ret57 << 0x10) + 4 + value107);
                        r->a = value113;
                        r->x = value107;
                        r->z = value113 == 0;
                        r->n = value113 & 0x8000;
                        r->mf = 0;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret58 = r->dp;
                        uint8_t db_ret61 = r->db;
                        bool m_ret27 = r->mf;
                        bool x_ret121 = r->xf;
                        uint16_t a_all61 = r->a;
                        bool carry_ret61 = r->c;
                        bool overflow_ret61 = r->v;
                        if (x_ret121) {
                            uint8_t value114 = BUS8_RDP(c, (uint16_t)(dp_ret58 + 1));
                            uint8_t value115 = BUS8_RDP(c, (db_ret61 << 0x10) + 8 + value114);
                            if (value115 == 0) {
                                if (m_ret27) {
                                    a_hi_aa0c = a_all61 >> 8;
                                    y_aa0c = value114;
                                    carry_aa0c = carry_ret61;
                                    overflow_aa0c = overflow_ret61;
                                    direct_page_aa0c = dp_ret58;
                                    data_bank_aa0c = db_ret61;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all61 >> 8;
                                    y_aa0c2 = value114;
                                    carry_aa0c2 = carry_ret61;
                                    overflow_aa0c2 = overflow_ret61;
                                    direct_page_aa0c2 = dp_ret58;
                                    data_bank_aa0c2 = db_ret61;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value115;
                            r->y = value114;
                            r->z = value115 == 0;
                            r->n = value115 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret59 = r->dp;
                            uint8_t db_ret62 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret123 = r->xf;
                            uint16_t a_all62 = r->a;
                            bool carry_ret62 = r->c;
                            bool overflow_ret62 = r->v;
                            if (x_ret123) {
                                a_hi_aa0c2 = a_all62 >> 8;
                                y_aa0c2 = value114;
                                carry_aa0c2 = carry_ret62;
                                overflow_aa0c2 = overflow_ret62;
                                direct_page_aa0c2 = dp_ret59;
                                data_bank_aa0c2 = db_ret62;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all62 >> 8;
                                y_aa0c3 = value114;
                                carry_aa0c3 = carry_ret62;
                                overflow_aa0c3 = overflow_ret62;
                                direct_page_aa0c3 = dp_ret59;
                                data_bank_aa0c3 = db_ret62;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value116 = BUS16_RDP(c, (uint16_t)(dp_ret58 + 1));
                            uint16_t value117 = BUS16_RDP(c, (db_ret61 << 0x10) + 8 + value116);
                            if (value117 == 0) {
                                if (m_ret27) {
                                    a_hi_aa0c4 = a_all61 >> 8;
                                    y_aa0c4 = value116;
                                    carry_aa0c4 = carry_ret61;
                                    overflow_aa0c4 = overflow_ret61;
                                    direct_page_aa0c4 = dp_ret58;
                                    data_bank_aa0c4 = db_ret61;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all61 >> 8;
                                    y_aa0c3 = value116;
                                    carry_aa0c3 = carry_ret61;
                                    overflow_aa0c3 = overflow_ret61;
                                    direct_page_aa0c3 = dp_ret58;
                                    data_bank_aa0c3 = db_ret61;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value117;
                            r->y = value116;
                            r->z = value117 == 0;
                            r->n = value117 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret60 = r->dp;
                            uint8_t db_ret63 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret125 = r->xf;
                            uint16_t a_all63 = r->a;
                            bool carry_ret63 = r->c;
                            bool overflow_ret63 = r->v;
                            if (x_ret125) {
                                a_hi_aa0c2 = a_all63 >> 8;
                                y_aa0c2 = (uint8_t)value116;
                                carry_aa0c2 = carry_ret63;
                                overflow_aa0c2 = overflow_ret63;
                                direct_page_aa0c2 = dp_ret60;
                                data_bank_aa0c2 = db_ret63;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all63 >> 8;
                                y_aa0c3 = value116;
                                carry_aa0c3 = carry_ret63;
                                overflow_aa0c3 = overflow_ret63;
                                direct_page_aa0c3 = dp_ret60;
                                data_bank_aa0c3 = db_ret63;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                } else {
                    uint16_t value118 = BUS16_RDP(c, (uint16_t)(dp_ret54 + 1));
                    if (m_ret25) {
                        uint8_t value119 = BUS8_RDP(c, (db_ret57 << 0x10) + 4 + value118);
                        r->a = (a_all57 >> 8 << 8) | value119;
                        r->x = value118;
                        r->z = value119 == 0;
                        r->n = value119 & 0x80;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret61 = r->dp;
                        uint8_t db_ret64 = r->db;
                        bool m_ret28 = r->mf;
                        bool x_ret127 = r->xf;
                        uint16_t a_all64 = r->a;
                        bool carry_ret64 = r->c;
                        bool overflow_ret64 = r->v;
                        if (x_ret127) {
                            uint8_t value120 = BUS8_RDP(c, (uint16_t)(dp_ret61 + 1));
                            uint8_t value121 = BUS8_RDP(c, (db_ret64 << 0x10) + 8 + value120);
                            if (value121 == 0) {
                                if (m_ret28) {
                                    a_hi_aa0c = a_all64 >> 8;
                                    y_aa0c = value120;
                                    carry_aa0c = carry_ret64;
                                    overflow_aa0c = overflow_ret64;
                                    direct_page_aa0c = dp_ret61;
                                    data_bank_aa0c = db_ret64;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all64 >> 8;
                                    y_aa0c2 = value120;
                                    carry_aa0c2 = carry_ret64;
                                    overflow_aa0c2 = overflow_ret64;
                                    direct_page_aa0c2 = dp_ret61;
                                    data_bank_aa0c2 = db_ret64;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value121;
                            r->y = value120;
                            r->z = value121 == 0;
                            r->n = value121 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret62 = r->dp;
                            uint8_t db_ret65 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret129 = r->xf;
                            uint16_t a_all65 = r->a;
                            bool carry_ret65 = r->c;
                            bool overflow_ret65 = r->v;
                            if (x_ret129) {
                                a_hi_aa0c2 = a_all65 >> 8;
                                y_aa0c2 = value120;
                                carry_aa0c2 = carry_ret65;
                                overflow_aa0c2 = overflow_ret65;
                                direct_page_aa0c2 = dp_ret62;
                                data_bank_aa0c2 = db_ret65;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all65 >> 8;
                                y_aa0c3 = value120;
                                carry_aa0c3 = carry_ret65;
                                overflow_aa0c3 = overflow_ret65;
                                direct_page_aa0c3 = dp_ret62;
                                data_bank_aa0c3 = db_ret65;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value122 = BUS16_RDP(c, (uint16_t)(dp_ret61 + 1));
                            uint16_t value123 = BUS16_RDP(c, (db_ret64 << 0x10) + 8 + value122);
                            if (value123 == 0) {
                                if (m_ret28) {
                                    a_hi_aa0c4 = a_all64 >> 8;
                                    y_aa0c4 = value122;
                                    carry_aa0c4 = carry_ret64;
                                    overflow_aa0c4 = overflow_ret64;
                                    direct_page_aa0c4 = dp_ret61;
                                    data_bank_aa0c4 = db_ret64;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all64 >> 8;
                                    y_aa0c3 = value122;
                                    carry_aa0c3 = carry_ret64;
                                    overflow_aa0c3 = overflow_ret64;
                                    direct_page_aa0c3 = dp_ret61;
                                    data_bank_aa0c3 = db_ret64;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value123;
                            r->y = value122;
                            r->z = value123 == 0;
                            r->n = value123 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret63 = r->dp;
                            uint8_t db_ret66 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret131 = r->xf;
                            uint16_t a_all66 = r->a;
                            bool carry_ret66 = r->c;
                            bool overflow_ret66 = r->v;
                            if (x_ret131) {
                                a_hi_aa0c2 = a_all66 >> 8;
                                y_aa0c2 = (uint8_t)value122;
                                carry_aa0c2 = carry_ret66;
                                overflow_aa0c2 = overflow_ret66;
                                direct_page_aa0c2 = dp_ret63;
                                data_bank_aa0c2 = db_ret66;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all66 >> 8;
                                y_aa0c3 = value122;
                                carry_aa0c3 = carry_ret66;
                                overflow_aa0c3 = overflow_ret66;
                                direct_page_aa0c3 = dp_ret63;
                                data_bank_aa0c3 = db_ret66;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value124 = BUS16_RDP(c, (db_ret57 << 0x10) + 4 + value118);
                        r->a = value124;
                        r->x = value118;
                        r->z = value124 == 0;
                        r->n = value124 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret64 = r->dp;
                        uint8_t db_ret67 = r->db;
                        bool m_ret29 = r->mf;
                        bool x_ret133 = r->xf;
                        uint16_t a_all67 = r->a;
                        bool carry_ret67 = r->c;
                        bool overflow_ret67 = r->v;
                        if (x_ret133) {
                            uint8_t value125 = BUS8_RDP(c, (uint16_t)(dp_ret64 + 1));
                            uint8_t value126 = BUS8_RDP(c, (db_ret67 << 0x10) + 8 + value125);
                            if (value126 == 0) {
                                if (m_ret29) {
                                    a_hi_aa0c = a_all67 >> 8;
                                    y_aa0c = value125;
                                    carry_aa0c = carry_ret67;
                                    overflow_aa0c = overflow_ret67;
                                    direct_page_aa0c = dp_ret64;
                                    data_bank_aa0c = db_ret67;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all67 >> 8;
                                    y_aa0c2 = value125;
                                    carry_aa0c2 = carry_ret67;
                                    overflow_aa0c2 = overflow_ret67;
                                    direct_page_aa0c2 = dp_ret64;
                                    data_bank_aa0c2 = db_ret67;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value126;
                            r->y = value125;
                            r->z = value126 == 0;
                            r->n = value126 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret65 = r->dp;
                            uint8_t db_ret68 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret135 = r->xf;
                            uint16_t a_all68 = r->a;
                            bool carry_ret68 = r->c;
                            bool overflow_ret68 = r->v;
                            if (x_ret135) {
                                a_hi_aa0c2 = a_all68 >> 8;
                                y_aa0c2 = value125;
                                carry_aa0c2 = carry_ret68;
                                overflow_aa0c2 = overflow_ret68;
                                direct_page_aa0c2 = dp_ret65;
                                data_bank_aa0c2 = db_ret68;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all68 >> 8;
                                y_aa0c3 = value125;
                                carry_aa0c3 = carry_ret68;
                                overflow_aa0c3 = overflow_ret68;
                                direct_page_aa0c3 = dp_ret65;
                                data_bank_aa0c3 = db_ret68;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value127 = BUS16_RDP(c, (uint16_t)(dp_ret64 + 1));
                            uint16_t value128 = BUS16_RDP(c, (db_ret67 << 0x10) + 8 + value127);
                            if (value128 == 0) {
                                if (m_ret29) {
                                    a_hi_aa0c4 = a_all67 >> 8;
                                    y_aa0c4 = value127;
                                    carry_aa0c4 = carry_ret67;
                                    overflow_aa0c4 = overflow_ret67;
                                    direct_page_aa0c4 = dp_ret64;
                                    data_bank_aa0c4 = db_ret67;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all67 >> 8;
                                    y_aa0c3 = value127;
                                    carry_aa0c3 = carry_ret67;
                                    overflow_aa0c3 = overflow_ret67;
                                    direct_page_aa0c3 = dp_ret64;
                                    data_bank_aa0c3 = db_ret67;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value128;
                            r->y = value127;
                            r->z = value128 == 0;
                            r->n = value128 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret66 = r->dp;
                            uint8_t db_ret69 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret137 = r->xf;
                            uint16_t a_all69 = r->a;
                            bool carry_ret69 = r->c;
                            bool overflow_ret69 = r->v;
                            if (x_ret137) {
                                a_hi_aa0c2 = a_all69 >> 8;
                                y_aa0c2 = (uint8_t)value127;
                                carry_aa0c2 = carry_ret69;
                                overflow_aa0c2 = overflow_ret69;
                                direct_page_aa0c2 = dp_ret66;
                                data_bank_aa0c2 = db_ret69;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all69 >> 8;
                                y_aa0c3 = value127;
                                carry_aa0c3 = carry_ret69;
                                overflow_aa0c3 = overflow_ret69;
                                direct_page_aa0c3 = dp_ret66;
                                data_bank_aa0c3 = db_ret69;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                }
            } else {
                uint16_t value129 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                uint16_t value130 = BUS16_RDP(c, (db_ret56 << 0x10) + 0x0A + value129);
                r->x = value130;
                r->y = value129;
                r->z = value130 == 0;
                r->n = value130 & 0x8000;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA9F9, 0x7EB23A); GUARD_JSR(c, sp_call, 0xA9F9); } /* release_record_chain */
                r->sp += 6;
                uint16_t dp_ret67 = r->dp;
                uint8_t db_ret70 = r->db;
                bool m_ret30 = r->mf;
                bool x_ret139 = r->xf;
                uint16_t a_all70 = r->a;
                if (x_ret139) {
                    uint8_t value131 = BUS8_RDP(c, (uint16_t)(dp_ret67 + 1));
                    if (m_ret30) {
                        uint8_t value132 = BUS8_RDP(c, (db_ret70 << 0x10) + 4 + value131);
                        r->a = (a_all70 >> 8 << 8) | value132;
                        r->x = value131;
                        r->y = (uint8_t)value129;
                        r->z = value132 == 0;
                        r->n = value132 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret68 = r->dp;
                        uint8_t db_ret71 = r->db;
                        bool m_ret31 = r->mf;
                        bool x_ret141 = r->xf;
                        uint16_t a_all71 = r->a;
                        bool carry_ret71 = r->c;
                        bool overflow_ret71 = r->v;
                        if (x_ret141) {
                            uint8_t value133 = BUS8_RDP(c, (uint16_t)(dp_ret68 + 1));
                            uint8_t value134 = BUS8_RDP(c, (db_ret71 << 0x10) + 8 + value133);
                            if (value134 == 0) {
                                if (m_ret31) {
                                    a_hi_aa0c = a_all71 >> 8;
                                    y_aa0c = value133;
                                    carry_aa0c = carry_ret71;
                                    overflow_aa0c = overflow_ret71;
                                    direct_page_aa0c = dp_ret68;
                                    data_bank_aa0c = db_ret71;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all71 >> 8;
                                    y_aa0c2 = value133;
                                    carry_aa0c2 = carry_ret71;
                                    overflow_aa0c2 = overflow_ret71;
                                    direct_page_aa0c2 = dp_ret68;
                                    data_bank_aa0c2 = db_ret71;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value134;
                            r->y = value133;
                            r->z = value134 == 0;
                            r->n = value134 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret69 = r->dp;
                            uint8_t db_ret72 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret143 = r->xf;
                            uint16_t a_all72 = r->a;
                            bool carry_ret72 = r->c;
                            bool overflow_ret72 = r->v;
                            if (x_ret143) {
                                a_hi_aa0c2 = a_all72 >> 8;
                                y_aa0c2 = value133;
                                carry_aa0c2 = carry_ret72;
                                overflow_aa0c2 = overflow_ret72;
                                direct_page_aa0c2 = dp_ret69;
                                data_bank_aa0c2 = db_ret72;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all72 >> 8;
                                y_aa0c3 = value133;
                                carry_aa0c3 = carry_ret72;
                                overflow_aa0c3 = overflow_ret72;
                                direct_page_aa0c3 = dp_ret69;
                                data_bank_aa0c3 = db_ret72;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value135 = BUS16_RDP(c, (uint16_t)(dp_ret68 + 1));
                            uint16_t value136 = BUS16_RDP(c, (db_ret71 << 0x10) + 8 + value135);
                            if (value136 == 0) {
                                if (m_ret31) {
                                    a_hi_aa0c4 = a_all71 >> 8;
                                    y_aa0c4 = value135;
                                    carry_aa0c4 = carry_ret71;
                                    overflow_aa0c4 = overflow_ret71;
                                    direct_page_aa0c4 = dp_ret68;
                                    data_bank_aa0c4 = db_ret71;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all71 >> 8;
                                    y_aa0c3 = value135;
                                    carry_aa0c3 = carry_ret71;
                                    overflow_aa0c3 = overflow_ret71;
                                    direct_page_aa0c3 = dp_ret68;
                                    data_bank_aa0c3 = db_ret71;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value136;
                            r->y = value135;
                            r->z = value136 == 0;
                            r->n = value136 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret70 = r->dp;
                            uint8_t db_ret73 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret145 = r->xf;
                            uint16_t a_all73 = r->a;
                            bool carry_ret73 = r->c;
                            bool overflow_ret73 = r->v;
                            if (x_ret145) {
                                a_hi_aa0c2 = a_all73 >> 8;
                                y_aa0c2 = (uint8_t)value135;
                                carry_aa0c2 = carry_ret73;
                                overflow_aa0c2 = overflow_ret73;
                                direct_page_aa0c2 = dp_ret70;
                                data_bank_aa0c2 = db_ret73;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all73 >> 8;
                                y_aa0c3 = value135;
                                carry_aa0c3 = carry_ret73;
                                overflow_aa0c3 = overflow_ret73;
                                direct_page_aa0c3 = dp_ret70;
                                data_bank_aa0c3 = db_ret73;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value137 = BUS16_RDP(c, (db_ret70 << 0x10) + 4 + value131);
                        r->a = value137;
                        r->x = value131;
                        r->y = (uint8_t)value129;
                        r->z = value137 == 0;
                        r->n = value137 & 0x8000;
                        r->mf = 0;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret71 = r->dp;
                        uint8_t db_ret74 = r->db;
                        bool m_ret32 = r->mf;
                        bool x_ret147 = r->xf;
                        uint16_t a_all74 = r->a;
                        bool carry_ret74 = r->c;
                        bool overflow_ret74 = r->v;
                        if (x_ret147) {
                            uint8_t value138 = BUS8_RDP(c, (uint16_t)(dp_ret71 + 1));
                            uint8_t value139 = BUS8_RDP(c, (db_ret74 << 0x10) + 8 + value138);
                            if (value139 == 0) {
                                if (m_ret32) {
                                    a_hi_aa0c = a_all74 >> 8;
                                    y_aa0c = value138;
                                    carry_aa0c = carry_ret74;
                                    overflow_aa0c = overflow_ret74;
                                    direct_page_aa0c = dp_ret71;
                                    data_bank_aa0c = db_ret74;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all74 >> 8;
                                    y_aa0c2 = value138;
                                    carry_aa0c2 = carry_ret74;
                                    overflow_aa0c2 = overflow_ret74;
                                    direct_page_aa0c2 = dp_ret71;
                                    data_bank_aa0c2 = db_ret74;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value139;
                            r->y = value138;
                            r->z = value139 == 0;
                            r->n = value139 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret72 = r->dp;
                            uint8_t db_ret75 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret149 = r->xf;
                            uint16_t a_all75 = r->a;
                            bool carry_ret75 = r->c;
                            bool overflow_ret75 = r->v;
                            if (x_ret149) {
                                a_hi_aa0c2 = a_all75 >> 8;
                                y_aa0c2 = value138;
                                carry_aa0c2 = carry_ret75;
                                overflow_aa0c2 = overflow_ret75;
                                direct_page_aa0c2 = dp_ret72;
                                data_bank_aa0c2 = db_ret75;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all75 >> 8;
                                y_aa0c3 = value138;
                                carry_aa0c3 = carry_ret75;
                                overflow_aa0c3 = overflow_ret75;
                                direct_page_aa0c3 = dp_ret72;
                                data_bank_aa0c3 = db_ret75;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value140 = BUS16_RDP(c, (uint16_t)(dp_ret71 + 1));
                            uint16_t value141 = BUS16_RDP(c, (db_ret74 << 0x10) + 8 + value140);
                            if (value141 == 0) {
                                if (m_ret32) {
                                    a_hi_aa0c4 = a_all74 >> 8;
                                    y_aa0c4 = value140;
                                    carry_aa0c4 = carry_ret74;
                                    overflow_aa0c4 = overflow_ret74;
                                    direct_page_aa0c4 = dp_ret71;
                                    data_bank_aa0c4 = db_ret74;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all74 >> 8;
                                    y_aa0c3 = value140;
                                    carry_aa0c3 = carry_ret74;
                                    overflow_aa0c3 = overflow_ret74;
                                    direct_page_aa0c3 = dp_ret71;
                                    data_bank_aa0c3 = db_ret74;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value141;
                            r->y = value140;
                            r->z = value141 == 0;
                            r->n = value141 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret73 = r->dp;
                            uint8_t db_ret76 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret151 = r->xf;
                            uint16_t a_all76 = r->a;
                            bool carry_ret76 = r->c;
                            bool overflow_ret76 = r->v;
                            if (x_ret151) {
                                a_hi_aa0c2 = a_all76 >> 8;
                                y_aa0c2 = (uint8_t)value140;
                                carry_aa0c2 = carry_ret76;
                                overflow_aa0c2 = overflow_ret76;
                                direct_page_aa0c2 = dp_ret73;
                                data_bank_aa0c2 = db_ret76;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all76 >> 8;
                                y_aa0c3 = value140;
                                carry_aa0c3 = carry_ret76;
                                overflow_aa0c3 = overflow_ret76;
                                direct_page_aa0c3 = dp_ret73;
                                data_bank_aa0c3 = db_ret76;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                } else {
                    uint16_t value142 = BUS16_RDP(c, (uint16_t)(dp_ret67 + 1));
                    if (m_ret30) {
                        uint8_t value143 = BUS8_RDP(c, (db_ret70 << 0x10) + 4 + value142);
                        r->a = (a_all70 >> 8 << 8) | value143;
                        r->x = value142;
                        r->z = value143 == 0;
                        r->n = value143 & 0x80;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret74 = r->dp;
                        uint8_t db_ret77 = r->db;
                        bool m_ret33 = r->mf;
                        bool x_ret153 = r->xf;
                        uint16_t a_all77 = r->a;
                        bool carry_ret77 = r->c;
                        bool overflow_ret77 = r->v;
                        if (x_ret153) {
                            uint8_t value144 = BUS8_RDP(c, (uint16_t)(dp_ret74 + 1));
                            uint8_t value145 = BUS8_RDP(c, (db_ret77 << 0x10) + 8 + value144);
                            if (value145 == 0) {
                                if (m_ret33) {
                                    a_hi_aa0c = a_all77 >> 8;
                                    y_aa0c = value144;
                                    carry_aa0c = carry_ret77;
                                    overflow_aa0c = overflow_ret77;
                                    direct_page_aa0c = dp_ret74;
                                    data_bank_aa0c = db_ret77;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all77 >> 8;
                                    y_aa0c2 = value144;
                                    carry_aa0c2 = carry_ret77;
                                    overflow_aa0c2 = overflow_ret77;
                                    direct_page_aa0c2 = dp_ret74;
                                    data_bank_aa0c2 = db_ret77;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value145;
                            r->y = value144;
                            r->z = value145 == 0;
                            r->n = value145 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret75 = r->dp;
                            uint8_t db_ret78 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret155 = r->xf;
                            uint16_t a_all78 = r->a;
                            bool carry_ret78 = r->c;
                            bool overflow_ret78 = r->v;
                            if (x_ret155) {
                                a_hi_aa0c2 = a_all78 >> 8;
                                y_aa0c2 = value144;
                                carry_aa0c2 = carry_ret78;
                                overflow_aa0c2 = overflow_ret78;
                                direct_page_aa0c2 = dp_ret75;
                                data_bank_aa0c2 = db_ret78;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all78 >> 8;
                                y_aa0c3 = value144;
                                carry_aa0c3 = carry_ret78;
                                overflow_aa0c3 = overflow_ret78;
                                direct_page_aa0c3 = dp_ret75;
                                data_bank_aa0c3 = db_ret78;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value146 = BUS16_RDP(c, (uint16_t)(dp_ret74 + 1));
                            uint16_t value147 = BUS16_RDP(c, (db_ret77 << 0x10) + 8 + value146);
                            if (value147 == 0) {
                                if (m_ret33) {
                                    a_hi_aa0c4 = a_all77 >> 8;
                                    y_aa0c4 = value146;
                                    carry_aa0c4 = carry_ret77;
                                    overflow_aa0c4 = overflow_ret77;
                                    direct_page_aa0c4 = dp_ret74;
                                    data_bank_aa0c4 = db_ret77;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all77 >> 8;
                                    y_aa0c3 = value146;
                                    carry_aa0c3 = carry_ret77;
                                    overflow_aa0c3 = overflow_ret77;
                                    direct_page_aa0c3 = dp_ret74;
                                    data_bank_aa0c3 = db_ret77;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value147;
                            r->y = value146;
                            r->z = value147 == 0;
                            r->n = value147 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret76 = r->dp;
                            uint8_t db_ret79 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret157 = r->xf;
                            uint16_t a_all79 = r->a;
                            bool carry_ret79 = r->c;
                            bool overflow_ret79 = r->v;
                            if (x_ret157) {
                                a_hi_aa0c2 = a_all79 >> 8;
                                y_aa0c2 = (uint8_t)value146;
                                carry_aa0c2 = carry_ret79;
                                overflow_aa0c2 = overflow_ret79;
                                direct_page_aa0c2 = dp_ret76;
                                data_bank_aa0c2 = db_ret79;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all79 >> 8;
                                y_aa0c3 = value146;
                                carry_aa0c3 = carry_ret79;
                                overflow_aa0c3 = overflow_ret79;
                                direct_page_aa0c3 = dp_ret76;
                                data_bank_aa0c3 = db_ret79;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value148 = BUS16_RDP(c, (db_ret70 << 0x10) + 4 + value142);
                        r->a = value148;
                        r->x = value142;
                        r->z = value148 == 0;
                        r->n = value148 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret77 = r->dp;
                        uint8_t db_ret80 = r->db;
                        bool m_ret34 = r->mf;
                        bool x_ret159 = r->xf;
                        uint16_t a_all80 = r->a;
                        bool carry_ret80 = r->c;
                        bool overflow_ret80 = r->v;
                        if (x_ret159) {
                            uint8_t value149 = BUS8_RDP(c, (uint16_t)(dp_ret77 + 1));
                            uint8_t value150 = BUS8_RDP(c, (db_ret80 << 0x10) + 8 + value149);
                            if (value150 == 0) {
                                if (m_ret34) {
                                    a_hi_aa0c = a_all80 >> 8;
                                    y_aa0c = value149;
                                    carry_aa0c = carry_ret80;
                                    overflow_aa0c = overflow_ret80;
                                    direct_page_aa0c = dp_ret77;
                                    data_bank_aa0c = db_ret80;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all80 >> 8;
                                    y_aa0c2 = value149;
                                    carry_aa0c2 = carry_ret80;
                                    overflow_aa0c2 = overflow_ret80;
                                    direct_page_aa0c2 = dp_ret77;
                                    data_bank_aa0c2 = db_ret80;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value150;
                            r->y = value149;
                            r->z = value150 == 0;
                            r->n = value150 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret78 = r->dp;
                            uint8_t db_ret81 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret161 = r->xf;
                            uint16_t a_all81 = r->a;
                            bool carry_ret81 = r->c;
                            bool overflow_ret81 = r->v;
                            if (x_ret161) {
                                a_hi_aa0c2 = a_all81 >> 8;
                                y_aa0c2 = value149;
                                carry_aa0c2 = carry_ret81;
                                overflow_aa0c2 = overflow_ret81;
                                direct_page_aa0c2 = dp_ret78;
                                data_bank_aa0c2 = db_ret81;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all81 >> 8;
                                y_aa0c3 = value149;
                                carry_aa0c3 = carry_ret81;
                                overflow_aa0c3 = overflow_ret81;
                                direct_page_aa0c3 = dp_ret78;
                                data_bank_aa0c3 = db_ret81;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value151 = BUS16_RDP(c, (uint16_t)(dp_ret77 + 1));
                            uint16_t value152 = BUS16_RDP(c, (db_ret80 << 0x10) + 8 + value151);
                            if (value152 == 0) {
                                if (m_ret34) {
                                    a_hi_aa0c4 = a_all80 >> 8;
                                    y_aa0c4 = value151;
                                    carry_aa0c4 = carry_ret80;
                                    overflow_aa0c4 = overflow_ret80;
                                    direct_page_aa0c4 = dp_ret77;
                                    data_bank_aa0c4 = db_ret80;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all80 >> 8;
                                    y_aa0c3 = value151;
                                    carry_aa0c3 = carry_ret80;
                                    overflow_aa0c3 = overflow_ret80;
                                    direct_page_aa0c3 = dp_ret77;
                                    data_bank_aa0c3 = db_ret80;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value152;
                            r->y = value151;
                            r->z = value152 == 0;
                            r->n = value152 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret79 = r->dp;
                            uint8_t db_ret82 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret163 = r->xf;
                            uint16_t a_all82 = r->a;
                            bool carry_ret82 = r->c;
                            bool overflow_ret82 = r->v;
                            if (x_ret163) {
                                a_hi_aa0c2 = a_all82 >> 8;
                                y_aa0c2 = (uint8_t)value151;
                                carry_aa0c2 = carry_ret82;
                                overflow_aa0c2 = overflow_ret82;
                                direct_page_aa0c2 = dp_ret79;
                                data_bank_aa0c2 = db_ret82;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all82 >> 8;
                                y_aa0c3 = value151;
                                carry_aa0c3 = carry_ret82;
                                overflow_aa0c3 = overflow_ret82;
                                direct_page_aa0c3 = dp_ret79;
                                data_bank_aa0c3 = db_ret82;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                }
            }
        } else {
            uint16_t value153 = BUS16_RDP(c, (db_ret << 0x10) + 4 + value103);
            r->a = value153;
            r->x = value103;
            r->z = value153 == 0;
            r->n = value153 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA9F1, 0x7ECBDC); GUARD_JSR(c, sp_call, 0xA9F1); } /* clear_registrations_by_task */
            r->sp += 6;
            uint8_t db_ret83 = r->db;
            bool x_ret165 = r->xf;
            if (x_ret165) {
                uint8_t value154 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                uint8_t value155 = BUS8_RDP(c, (db_ret83 << 0x10) + 0x0A + value154);
                r->x = value155;
                r->y = value154;
                r->z = value155 == 0;
                r->n = value155 & 0x80;
                r->xf = 1;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA9F9, 0x7EB23A); GUARD_JSR(c, sp_call, 0xA9F9); } /* release_record_chain */
                r->sp += 6;
                uint16_t dp_ret80 = r->dp;
                uint8_t db_ret84 = r->db;
                bool m_ret36 = r->mf;
                bool x_ret167 = r->xf;
                uint16_t a_all84 = r->a;
                if (x_ret167) {
                    uint8_t value156 = BUS8_RDP(c, (uint16_t)(dp_ret80 + 1));
                    if (m_ret36) {
                        uint8_t value157 = BUS8_RDP(c, (db_ret84 << 0x10) + 4 + value156);
                        r->a = (a_all84 >> 8 << 8) | value157;
                        r->x = value156;
                        r->z = value157 == 0;
                        r->n = value157 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret81 = r->dp;
                        uint8_t db_ret85 = r->db;
                        bool m_ret37 = r->mf;
                        bool x_ret169 = r->xf;
                        uint16_t a_all85 = r->a;
                        bool carry_ret85 = r->c;
                        bool overflow_ret85 = r->v;
                        if (x_ret169) {
                            uint8_t value158 = BUS8_RDP(c, (uint16_t)(dp_ret81 + 1));
                            uint8_t value159 = BUS8_RDP(c, (db_ret85 << 0x10) + 8 + value158);
                            if (value159 == 0) {
                                if (m_ret37) {
                                    a_hi_aa0c = a_all85 >> 8;
                                    y_aa0c = value158;
                                    carry_aa0c = carry_ret85;
                                    overflow_aa0c = overflow_ret85;
                                    direct_page_aa0c = dp_ret81;
                                    data_bank_aa0c = db_ret85;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all85 >> 8;
                                    y_aa0c2 = value158;
                                    carry_aa0c2 = carry_ret85;
                                    overflow_aa0c2 = overflow_ret85;
                                    direct_page_aa0c2 = dp_ret81;
                                    data_bank_aa0c2 = db_ret85;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value159;
                            r->y = value158;
                            r->z = value159 == 0;
                            r->n = value159 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret82 = r->dp;
                            uint8_t db_ret86 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret171 = r->xf;
                            uint16_t a_all86 = r->a;
                            bool carry_ret86 = r->c;
                            bool overflow_ret86 = r->v;
                            if (x_ret171) {
                                a_hi_aa0c2 = a_all86 >> 8;
                                y_aa0c2 = value158;
                                carry_aa0c2 = carry_ret86;
                                overflow_aa0c2 = overflow_ret86;
                                direct_page_aa0c2 = dp_ret82;
                                data_bank_aa0c2 = db_ret86;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all86 >> 8;
                                y_aa0c3 = value158;
                                carry_aa0c3 = carry_ret86;
                                overflow_aa0c3 = overflow_ret86;
                                direct_page_aa0c3 = dp_ret82;
                                data_bank_aa0c3 = db_ret86;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value160 = BUS16_RDP(c, (uint16_t)(dp_ret81 + 1));
                            uint16_t value161 = BUS16_RDP(c, (db_ret85 << 0x10) + 8 + value160);
                            if (value161 == 0) {
                                if (m_ret37) {
                                    a_hi_aa0c4 = a_all85 >> 8;
                                    y_aa0c4 = value160;
                                    carry_aa0c4 = carry_ret85;
                                    overflow_aa0c4 = overflow_ret85;
                                    direct_page_aa0c4 = dp_ret81;
                                    data_bank_aa0c4 = db_ret85;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all85 >> 8;
                                    y_aa0c3 = value160;
                                    carry_aa0c3 = carry_ret85;
                                    overflow_aa0c3 = overflow_ret85;
                                    direct_page_aa0c3 = dp_ret81;
                                    data_bank_aa0c3 = db_ret85;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value161;
                            r->y = value160;
                            r->z = value161 == 0;
                            r->n = value161 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret83 = r->dp;
                            uint8_t db_ret87 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret173 = r->xf;
                            uint16_t a_all87 = r->a;
                            bool carry_ret87 = r->c;
                            bool overflow_ret87 = r->v;
                            if (x_ret173) {
                                a_hi_aa0c2 = a_all87 >> 8;
                                y_aa0c2 = (uint8_t)value160;
                                carry_aa0c2 = carry_ret87;
                                overflow_aa0c2 = overflow_ret87;
                                direct_page_aa0c2 = dp_ret83;
                                data_bank_aa0c2 = db_ret87;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all87 >> 8;
                                y_aa0c3 = value160;
                                carry_aa0c3 = carry_ret87;
                                overflow_aa0c3 = overflow_ret87;
                                direct_page_aa0c3 = dp_ret83;
                                data_bank_aa0c3 = db_ret87;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value162 = BUS16_RDP(c, (db_ret84 << 0x10) + 4 + value156);
                        r->a = value162;
                        r->x = value156;
                        r->z = value162 == 0;
                        r->n = value162 & 0x8000;
                        r->mf = 0;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret84 = r->dp;
                        uint8_t db_ret88 = r->db;
                        bool m_ret38 = r->mf;
                        bool x_ret175 = r->xf;
                        uint16_t a_all88 = r->a;
                        bool carry_ret88 = r->c;
                        bool overflow_ret88 = r->v;
                        if (x_ret175) {
                            uint8_t value163 = BUS8_RDP(c, (uint16_t)(dp_ret84 + 1));
                            uint8_t value164 = BUS8_RDP(c, (db_ret88 << 0x10) + 8 + value163);
                            if (value164 == 0) {
                                if (m_ret38) {
                                    a_hi_aa0c = a_all88 >> 8;
                                    y_aa0c = value163;
                                    carry_aa0c = carry_ret88;
                                    overflow_aa0c = overflow_ret88;
                                    direct_page_aa0c = dp_ret84;
                                    data_bank_aa0c = db_ret88;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all88 >> 8;
                                    y_aa0c2 = value163;
                                    carry_aa0c2 = carry_ret88;
                                    overflow_aa0c2 = overflow_ret88;
                                    direct_page_aa0c2 = dp_ret84;
                                    data_bank_aa0c2 = db_ret88;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value164;
                            r->y = value163;
                            r->z = value164 == 0;
                            r->n = value164 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret85 = r->dp;
                            uint8_t db_ret89 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret177 = r->xf;
                            uint16_t a_all89 = r->a;
                            bool carry_ret89 = r->c;
                            bool overflow_ret89 = r->v;
                            if (x_ret177) {
                                a_hi_aa0c2 = a_all89 >> 8;
                                y_aa0c2 = value163;
                                carry_aa0c2 = carry_ret89;
                                overflow_aa0c2 = overflow_ret89;
                                direct_page_aa0c2 = dp_ret85;
                                data_bank_aa0c2 = db_ret89;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all89 >> 8;
                                y_aa0c3 = value163;
                                carry_aa0c3 = carry_ret89;
                                overflow_aa0c3 = overflow_ret89;
                                direct_page_aa0c3 = dp_ret85;
                                data_bank_aa0c3 = db_ret89;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value165 = BUS16_RDP(c, (uint16_t)(dp_ret84 + 1));
                            uint16_t value166 = BUS16_RDP(c, (db_ret88 << 0x10) + 8 + value165);
                            if (value166 == 0) {
                                if (m_ret38) {
                                    a_hi_aa0c4 = a_all88 >> 8;
                                    y_aa0c4 = value165;
                                    carry_aa0c4 = carry_ret88;
                                    overflow_aa0c4 = overflow_ret88;
                                    direct_page_aa0c4 = dp_ret84;
                                    data_bank_aa0c4 = db_ret88;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all88 >> 8;
                                    y_aa0c3 = value165;
                                    carry_aa0c3 = carry_ret88;
                                    overflow_aa0c3 = overflow_ret88;
                                    direct_page_aa0c3 = dp_ret84;
                                    data_bank_aa0c3 = db_ret88;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value166;
                            r->y = value165;
                            r->z = value166 == 0;
                            r->n = value166 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret86 = r->dp;
                            uint8_t db_ret90 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret179 = r->xf;
                            uint16_t a_all90 = r->a;
                            bool carry_ret90 = r->c;
                            bool overflow_ret90 = r->v;
                            if (x_ret179) {
                                a_hi_aa0c2 = a_all90 >> 8;
                                y_aa0c2 = (uint8_t)value165;
                                carry_aa0c2 = carry_ret90;
                                overflow_aa0c2 = overflow_ret90;
                                direct_page_aa0c2 = dp_ret86;
                                data_bank_aa0c2 = db_ret90;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all90 >> 8;
                                y_aa0c3 = value165;
                                carry_aa0c3 = carry_ret90;
                                overflow_aa0c3 = overflow_ret90;
                                direct_page_aa0c3 = dp_ret86;
                                data_bank_aa0c3 = db_ret90;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                } else {
                    uint16_t value167 = BUS16_RDP(c, (uint16_t)(dp_ret80 + 1));
                    if (m_ret36) {
                        uint8_t value168 = BUS8_RDP(c, (db_ret84 << 0x10) + 4 + value167);
                        r->a = (a_all84 >> 8 << 8) | value168;
                        r->x = value167;
                        r->z = value168 == 0;
                        r->n = value168 & 0x80;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret87 = r->dp;
                        uint8_t db_ret91 = r->db;
                        bool m_ret39 = r->mf;
                        bool x_ret181 = r->xf;
                        uint16_t a_all91 = r->a;
                        bool carry_ret91 = r->c;
                        bool overflow_ret91 = r->v;
                        if (x_ret181) {
                            uint8_t value169 = BUS8_RDP(c, (uint16_t)(dp_ret87 + 1));
                            uint8_t value170 = BUS8_RDP(c, (db_ret91 << 0x10) + 8 + value169);
                            if (value170 == 0) {
                                if (m_ret39) {
                                    a_hi_aa0c = a_all91 >> 8;
                                    y_aa0c = value169;
                                    carry_aa0c = carry_ret91;
                                    overflow_aa0c = overflow_ret91;
                                    direct_page_aa0c = dp_ret87;
                                    data_bank_aa0c = db_ret91;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all91 >> 8;
                                    y_aa0c2 = value169;
                                    carry_aa0c2 = carry_ret91;
                                    overflow_aa0c2 = overflow_ret91;
                                    direct_page_aa0c2 = dp_ret87;
                                    data_bank_aa0c2 = db_ret91;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value170;
                            r->y = value169;
                            r->z = value170 == 0;
                            r->n = value170 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret88 = r->dp;
                            uint8_t db_ret92 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret183 = r->xf;
                            uint16_t a_all92 = r->a;
                            bool carry_ret92 = r->c;
                            bool overflow_ret92 = r->v;
                            if (x_ret183) {
                                a_hi_aa0c2 = a_all92 >> 8;
                                y_aa0c2 = value169;
                                carry_aa0c2 = carry_ret92;
                                overflow_aa0c2 = overflow_ret92;
                                direct_page_aa0c2 = dp_ret88;
                                data_bank_aa0c2 = db_ret92;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all92 >> 8;
                                y_aa0c3 = value169;
                                carry_aa0c3 = carry_ret92;
                                overflow_aa0c3 = overflow_ret92;
                                direct_page_aa0c3 = dp_ret88;
                                data_bank_aa0c3 = db_ret92;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value171 = BUS16_RDP(c, (uint16_t)(dp_ret87 + 1));
                            uint16_t value172 = BUS16_RDP(c, (db_ret91 << 0x10) + 8 + value171);
                            if (value172 == 0) {
                                if (m_ret39) {
                                    a_hi_aa0c4 = a_all91 >> 8;
                                    y_aa0c4 = value171;
                                    carry_aa0c4 = carry_ret91;
                                    overflow_aa0c4 = overflow_ret91;
                                    direct_page_aa0c4 = dp_ret87;
                                    data_bank_aa0c4 = db_ret91;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all91 >> 8;
                                    y_aa0c3 = value171;
                                    carry_aa0c3 = carry_ret91;
                                    overflow_aa0c3 = overflow_ret91;
                                    direct_page_aa0c3 = dp_ret87;
                                    data_bank_aa0c3 = db_ret91;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value172;
                            r->y = value171;
                            r->z = value172 == 0;
                            r->n = value172 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret89 = r->dp;
                            uint8_t db_ret93 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret185 = r->xf;
                            uint16_t a_all93 = r->a;
                            bool carry_ret93 = r->c;
                            bool overflow_ret93 = r->v;
                            if (x_ret185) {
                                a_hi_aa0c2 = a_all93 >> 8;
                                y_aa0c2 = (uint8_t)value171;
                                carry_aa0c2 = carry_ret93;
                                overflow_aa0c2 = overflow_ret93;
                                direct_page_aa0c2 = dp_ret89;
                                data_bank_aa0c2 = db_ret93;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all93 >> 8;
                                y_aa0c3 = value171;
                                carry_aa0c3 = carry_ret93;
                                overflow_aa0c3 = overflow_ret93;
                                direct_page_aa0c3 = dp_ret89;
                                data_bank_aa0c3 = db_ret93;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value173 = BUS16_RDP(c, (db_ret84 << 0x10) + 4 + value167);
                        r->a = value173;
                        r->x = value167;
                        r->z = value173 == 0;
                        r->n = value173 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret90 = r->dp;
                        uint8_t db_ret94 = r->db;
                        bool m_ret40 = r->mf;
                        bool x_ret187 = r->xf;
                        uint16_t a_all94 = r->a;
                        bool carry_ret94 = r->c;
                        bool overflow_ret94 = r->v;
                        if (x_ret187) {
                            uint8_t value174 = BUS8_RDP(c, (uint16_t)(dp_ret90 + 1));
                            uint8_t value175 = BUS8_RDP(c, (db_ret94 << 0x10) + 8 + value174);
                            if (value175 == 0) {
                                if (m_ret40) {
                                    a_hi_aa0c = a_all94 >> 8;
                                    y_aa0c = value174;
                                    carry_aa0c = carry_ret94;
                                    overflow_aa0c = overflow_ret94;
                                    direct_page_aa0c = dp_ret90;
                                    data_bank_aa0c = db_ret94;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all94 >> 8;
                                    y_aa0c2 = value174;
                                    carry_aa0c2 = carry_ret94;
                                    overflow_aa0c2 = overflow_ret94;
                                    direct_page_aa0c2 = dp_ret90;
                                    data_bank_aa0c2 = db_ret94;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value175;
                            r->y = value174;
                            r->z = value175 == 0;
                            r->n = value175 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret91 = r->dp;
                            uint8_t db_ret95 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret189 = r->xf;
                            uint16_t a_all95 = r->a;
                            bool carry_ret95 = r->c;
                            bool overflow_ret95 = r->v;
                            if (x_ret189) {
                                a_hi_aa0c2 = a_all95 >> 8;
                                y_aa0c2 = value174;
                                carry_aa0c2 = carry_ret95;
                                overflow_aa0c2 = overflow_ret95;
                                direct_page_aa0c2 = dp_ret91;
                                data_bank_aa0c2 = db_ret95;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all95 >> 8;
                                y_aa0c3 = value174;
                                carry_aa0c3 = carry_ret95;
                                overflow_aa0c3 = overflow_ret95;
                                direct_page_aa0c3 = dp_ret91;
                                data_bank_aa0c3 = db_ret95;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value176 = BUS16_RDP(c, (uint16_t)(dp_ret90 + 1));
                            uint16_t value177 = BUS16_RDP(c, (db_ret94 << 0x10) + 8 + value176);
                            if (value177 == 0) {
                                if (m_ret40) {
                                    a_hi_aa0c4 = a_all94 >> 8;
                                    y_aa0c4 = value176;
                                    carry_aa0c4 = carry_ret94;
                                    overflow_aa0c4 = overflow_ret94;
                                    direct_page_aa0c4 = dp_ret90;
                                    data_bank_aa0c4 = db_ret94;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all94 >> 8;
                                    y_aa0c3 = value176;
                                    carry_aa0c3 = carry_ret94;
                                    overflow_aa0c3 = overflow_ret94;
                                    direct_page_aa0c3 = dp_ret90;
                                    data_bank_aa0c3 = db_ret94;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value177;
                            r->y = value176;
                            r->z = value177 == 0;
                            r->n = value177 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret92 = r->dp;
                            uint8_t db_ret96 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret191 = r->xf;
                            uint16_t a_all96 = r->a;
                            bool carry_ret96 = r->c;
                            bool overflow_ret96 = r->v;
                            if (x_ret191) {
                                a_hi_aa0c2 = a_all96 >> 8;
                                y_aa0c2 = (uint8_t)value176;
                                carry_aa0c2 = carry_ret96;
                                overflow_aa0c2 = overflow_ret96;
                                direct_page_aa0c2 = dp_ret92;
                                data_bank_aa0c2 = db_ret96;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all96 >> 8;
                                y_aa0c3 = value176;
                                carry_aa0c3 = carry_ret96;
                                overflow_aa0c3 = overflow_ret96;
                                direct_page_aa0c3 = dp_ret92;
                                data_bank_aa0c3 = db_ret96;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                }
            } else {
                uint16_t value178 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                uint16_t value179 = BUS16_RDP(c, (db_ret83 << 0x10) + 0x0A + value178);
                r->x = value179;
                r->y = value178;
                r->z = value179 == 0;
                r->n = value179 & 0x8000;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA9F9, 0x7EB23A); GUARD_JSR(c, sp_call, 0xA9F9); } /* release_record_chain */
                r->sp += 6;
                uint16_t dp_ret93 = r->dp;
                uint8_t db_ret97 = r->db;
                bool m_ret41 = r->mf;
                bool x_ret193 = r->xf;
                uint16_t a_all97 = r->a;
                if (x_ret193) {
                    uint8_t value180 = BUS8_RDP(c, (uint16_t)(dp_ret93 + 1));
                    if (m_ret41) {
                        uint8_t value181 = BUS8_RDP(c, (db_ret97 << 0x10) + 4 + value180);
                        r->a = (a_all97 >> 8 << 8) | value181;
                        r->x = value180;
                        r->y = (uint8_t)value178;
                        r->z = value181 == 0;
                        r->n = value181 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret94 = r->dp;
                        uint8_t db_ret98 = r->db;
                        bool m_ret42 = r->mf;
                        bool x_ret195 = r->xf;
                        uint16_t a_all98 = r->a;
                        bool carry_ret98 = r->c;
                        bool overflow_ret98 = r->v;
                        if (x_ret195) {
                            uint8_t value182 = BUS8_RDP(c, (uint16_t)(dp_ret94 + 1));
                            uint8_t value183 = BUS8_RDP(c, (db_ret98 << 0x10) + 8 + value182);
                            if (value183 == 0) {
                                if (m_ret42) {
                                    a_hi_aa0c = a_all98 >> 8;
                                    y_aa0c = value182;
                                    carry_aa0c = carry_ret98;
                                    overflow_aa0c = overflow_ret98;
                                    direct_page_aa0c = dp_ret94;
                                    data_bank_aa0c = db_ret98;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all98 >> 8;
                                    y_aa0c2 = value182;
                                    carry_aa0c2 = carry_ret98;
                                    overflow_aa0c2 = overflow_ret98;
                                    direct_page_aa0c2 = dp_ret94;
                                    data_bank_aa0c2 = db_ret98;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value183;
                            r->y = value182;
                            r->z = value183 == 0;
                            r->n = value183 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret95 = r->dp;
                            uint8_t db_ret99 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret197 = r->xf;
                            uint16_t a_all99 = r->a;
                            bool carry_ret99 = r->c;
                            bool overflow_ret99 = r->v;
                            if (x_ret197) {
                                a_hi_aa0c2 = a_all99 >> 8;
                                y_aa0c2 = value182;
                                carry_aa0c2 = carry_ret99;
                                overflow_aa0c2 = overflow_ret99;
                                direct_page_aa0c2 = dp_ret95;
                                data_bank_aa0c2 = db_ret99;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all99 >> 8;
                                y_aa0c3 = value182;
                                carry_aa0c3 = carry_ret99;
                                overflow_aa0c3 = overflow_ret99;
                                direct_page_aa0c3 = dp_ret95;
                                data_bank_aa0c3 = db_ret99;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value184 = BUS16_RDP(c, (uint16_t)(dp_ret94 + 1));
                            uint16_t value185 = BUS16_RDP(c, (db_ret98 << 0x10) + 8 + value184);
                            if (value185 == 0) {
                                if (m_ret42) {
                                    a_hi_aa0c4 = a_all98 >> 8;
                                    y_aa0c4 = value184;
                                    carry_aa0c4 = carry_ret98;
                                    overflow_aa0c4 = overflow_ret98;
                                    direct_page_aa0c4 = dp_ret94;
                                    data_bank_aa0c4 = db_ret98;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all98 >> 8;
                                    y_aa0c3 = value184;
                                    carry_aa0c3 = carry_ret98;
                                    overflow_aa0c3 = overflow_ret98;
                                    direct_page_aa0c3 = dp_ret94;
                                    data_bank_aa0c3 = db_ret98;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value185;
                            r->y = value184;
                            r->z = value185 == 0;
                            r->n = value185 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret96 = r->dp;
                            uint8_t db_ret100 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret199 = r->xf;
                            uint16_t a_all100 = r->a;
                            bool carry_ret100 = r->c;
                            bool overflow_ret100 = r->v;
                            if (x_ret199) {
                                a_hi_aa0c2 = a_all100 >> 8;
                                y_aa0c2 = (uint8_t)value184;
                                carry_aa0c2 = carry_ret100;
                                overflow_aa0c2 = overflow_ret100;
                                direct_page_aa0c2 = dp_ret96;
                                data_bank_aa0c2 = db_ret100;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all100 >> 8;
                                y_aa0c3 = value184;
                                carry_aa0c3 = carry_ret100;
                                overflow_aa0c3 = overflow_ret100;
                                direct_page_aa0c3 = dp_ret96;
                                data_bank_aa0c3 = db_ret100;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value186 = BUS16_RDP(c, (db_ret97 << 0x10) + 4 + value180);
                        r->a = value186;
                        r->x = value180;
                        r->y = (uint8_t)value178;
                        r->z = value186 == 0;
                        r->n = value186 & 0x8000;
                        r->mf = 0;
                        r->xf = 1;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret97 = r->dp;
                        uint8_t db_ret101 = r->db;
                        bool m_ret43 = r->mf;
                        bool x_ret201 = r->xf;
                        uint16_t a_all101 = r->a;
                        bool carry_ret101 = r->c;
                        bool overflow_ret101 = r->v;
                        if (x_ret201) {
                            uint8_t value187 = BUS8_RDP(c, (uint16_t)(dp_ret97 + 1));
                            uint8_t value188 = BUS8_RDP(c, (db_ret101 << 0x10) + 8 + value187);
                            if (value188 == 0) {
                                if (m_ret43) {
                                    a_hi_aa0c = a_all101 >> 8;
                                    y_aa0c = value187;
                                    carry_aa0c = carry_ret101;
                                    overflow_aa0c = overflow_ret101;
                                    direct_page_aa0c = dp_ret97;
                                    data_bank_aa0c = db_ret101;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all101 >> 8;
                                    y_aa0c2 = value187;
                                    carry_aa0c2 = carry_ret101;
                                    overflow_aa0c2 = overflow_ret101;
                                    direct_page_aa0c2 = dp_ret97;
                                    data_bank_aa0c2 = db_ret101;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value188;
                            r->y = value187;
                            r->z = value188 == 0;
                            r->n = value188 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret98 = r->dp;
                            uint8_t db_ret102 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret203 = r->xf;
                            uint16_t a_all102 = r->a;
                            bool carry_ret102 = r->c;
                            bool overflow_ret102 = r->v;
                            if (x_ret203) {
                                a_hi_aa0c2 = a_all102 >> 8;
                                y_aa0c2 = value187;
                                carry_aa0c2 = carry_ret102;
                                overflow_aa0c2 = overflow_ret102;
                                direct_page_aa0c2 = dp_ret98;
                                data_bank_aa0c2 = db_ret102;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all102 >> 8;
                                y_aa0c3 = value187;
                                carry_aa0c3 = carry_ret102;
                                overflow_aa0c3 = overflow_ret102;
                                direct_page_aa0c3 = dp_ret98;
                                data_bank_aa0c3 = db_ret102;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value189 = BUS16_RDP(c, (uint16_t)(dp_ret97 + 1));
                            uint16_t value190 = BUS16_RDP(c, (db_ret101 << 0x10) + 8 + value189);
                            if (value190 == 0) {
                                if (m_ret43) {
                                    a_hi_aa0c4 = a_all101 >> 8;
                                    y_aa0c4 = value189;
                                    carry_aa0c4 = carry_ret101;
                                    overflow_aa0c4 = overflow_ret101;
                                    direct_page_aa0c4 = dp_ret97;
                                    data_bank_aa0c4 = db_ret101;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all101 >> 8;
                                    y_aa0c3 = value189;
                                    carry_aa0c3 = carry_ret101;
                                    overflow_aa0c3 = overflow_ret101;
                                    direct_page_aa0c3 = dp_ret97;
                                    data_bank_aa0c3 = db_ret101;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value190;
                            r->y = value189;
                            r->z = value190 == 0;
                            r->n = value190 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret99 = r->dp;
                            uint8_t db_ret103 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret205 = r->xf;
                            uint16_t a_all103 = r->a;
                            bool carry_ret103 = r->c;
                            bool overflow_ret103 = r->v;
                            if (x_ret205) {
                                a_hi_aa0c2 = a_all103 >> 8;
                                y_aa0c2 = (uint8_t)value189;
                                carry_aa0c2 = carry_ret103;
                                overflow_aa0c2 = overflow_ret103;
                                direct_page_aa0c2 = dp_ret99;
                                data_bank_aa0c2 = db_ret103;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all103 >> 8;
                                y_aa0c3 = value189;
                                carry_aa0c3 = carry_ret103;
                                overflow_aa0c3 = overflow_ret103;
                                direct_page_aa0c3 = dp_ret99;
                                data_bank_aa0c3 = db_ret103;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                } else {
                    uint16_t value191 = BUS16_RDP(c, (uint16_t)(dp_ret93 + 1));
                    if (m_ret41) {
                        uint8_t value192 = BUS8_RDP(c, (db_ret97 << 0x10) + 4 + value191);
                        r->a = (a_all97 >> 8 << 8) | value192;
                        r->x = value191;
                        r->z = value192 == 0;
                        r->n = value192 & 0x80;
                        r->mf = 1;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret100 = r->dp;
                        uint8_t db_ret104 = r->db;
                        bool m_ret44 = r->mf;
                        bool x_ret207 = r->xf;
                        uint16_t a_all104 = r->a;
                        bool carry_ret104 = r->c;
                        bool overflow_ret104 = r->v;
                        if (x_ret207) {
                            uint8_t value193 = BUS8_RDP(c, (uint16_t)(dp_ret100 + 1));
                            uint8_t value194 = BUS8_RDP(c, (db_ret104 << 0x10) + 8 + value193);
                            if (value194 == 0) {
                                if (m_ret44) {
                                    a_hi_aa0c = a_all104 >> 8;
                                    y_aa0c = value193;
                                    carry_aa0c = carry_ret104;
                                    overflow_aa0c = overflow_ret104;
                                    direct_page_aa0c = dp_ret100;
                                    data_bank_aa0c = db_ret104;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all104 >> 8;
                                    y_aa0c2 = value193;
                                    carry_aa0c2 = carry_ret104;
                                    overflow_aa0c2 = overflow_ret104;
                                    direct_page_aa0c2 = dp_ret100;
                                    data_bank_aa0c2 = db_ret104;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value194;
                            r->y = value193;
                            r->z = value194 == 0;
                            r->n = value194 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret101 = r->dp;
                            uint8_t db_ret105 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret209 = r->xf;
                            uint16_t a_all105 = r->a;
                            bool carry_ret105 = r->c;
                            bool overflow_ret105 = r->v;
                            if (x_ret209) {
                                a_hi_aa0c2 = a_all105 >> 8;
                                y_aa0c2 = value193;
                                carry_aa0c2 = carry_ret105;
                                overflow_aa0c2 = overflow_ret105;
                                direct_page_aa0c2 = dp_ret101;
                                data_bank_aa0c2 = db_ret105;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all105 >> 8;
                                y_aa0c3 = value193;
                                carry_aa0c3 = carry_ret105;
                                overflow_aa0c3 = overflow_ret105;
                                direct_page_aa0c3 = dp_ret101;
                                data_bank_aa0c3 = db_ret105;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value195 = BUS16_RDP(c, (uint16_t)(dp_ret100 + 1));
                            uint16_t value196 = BUS16_RDP(c, (db_ret104 << 0x10) + 8 + value195);
                            if (value196 == 0) {
                                if (m_ret44) {
                                    a_hi_aa0c4 = a_all104 >> 8;
                                    y_aa0c4 = value195;
                                    carry_aa0c4 = carry_ret104;
                                    overflow_aa0c4 = overflow_ret104;
                                    direct_page_aa0c4 = dp_ret100;
                                    data_bank_aa0c4 = db_ret104;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all104 >> 8;
                                    y_aa0c3 = value195;
                                    carry_aa0c3 = carry_ret104;
                                    overflow_aa0c3 = overflow_ret104;
                                    direct_page_aa0c3 = dp_ret100;
                                    data_bank_aa0c3 = db_ret104;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value196;
                            r->y = value195;
                            r->z = value196 == 0;
                            r->n = value196 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret102 = r->dp;
                            uint8_t db_ret106 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret211 = r->xf;
                            uint16_t a_all106 = r->a;
                            bool carry_ret106 = r->c;
                            bool overflow_ret106 = r->v;
                            if (x_ret211) {
                                a_hi_aa0c2 = a_all106 >> 8;
                                y_aa0c2 = (uint8_t)value195;
                                carry_aa0c2 = carry_ret106;
                                overflow_aa0c2 = overflow_ret106;
                                direct_page_aa0c2 = dp_ret102;
                                data_bank_aa0c2 = db_ret106;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all106 >> 8;
                                y_aa0c3 = value195;
                                carry_aa0c3 = carry_ret106;
                                overflow_aa0c3 = overflow_ret106;
                                direct_page_aa0c3 = dp_ret102;
                                data_bank_aa0c3 = db_ret106;
                                goto shared_AA0C_2;
                            }
                        }
                    } else {
                        uint16_t value197 = BUS16_RDP(c, (db_ret97 << 0x10) + 4 + value191);
                        r->a = value197;
                        r->x = value191;
                        r->z = value197 == 0;
                        r->n = value197 & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 6;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAA01, 0x7EB16F); GUARD_JSR(c, sp_call, 0xAA01); } /* release_records_held_by_task */
                        r->sp += 6;
                        uint16_t dp_ret103 = r->dp;
                        uint8_t db_ret107 = r->db;
                        bool m_ret45 = r->mf;
                        bool x_ret213 = r->xf;
                        uint16_t a_all107 = r->a;
                        bool carry_ret107 = r->c;
                        bool overflow_ret107 = r->v;
                        if (x_ret213) {
                            uint8_t value198 = BUS8_RDP(c, (uint16_t)(dp_ret103 + 1));
                            uint8_t value199 = BUS8_RDP(c, (db_ret107 << 0x10) + 8 + value198);
                            if (value199 == 0) {
                                if (m_ret45) {
                                    a_hi_aa0c = a_all107 >> 8;
                                    y_aa0c = value198;
                                    carry_aa0c = carry_ret107;
                                    overflow_aa0c = overflow_ret107;
                                    direct_page_aa0c = dp_ret103;
                                    data_bank_aa0c = db_ret107;
                                    goto shared_AA0C;
                                } else {
                                    a_hi_aa0c2 = a_all107 >> 8;
                                    y_aa0c2 = value198;
                                    carry_aa0c2 = carry_ret107;
                                    overflow_aa0c2 = overflow_ret107;
                                    direct_page_aa0c2 = dp_ret103;
                                    data_bank_aa0c2 = db_ret107;
                                    goto shared_AA0C_1;
                                }
                            }
                            r->x = value199;
                            r->y = value198;
                            r->z = value199 == 0;
                            r->n = value199 & 0x80;
                            r->xf = 1;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret104 = r->dp;
                            uint8_t db_ret108 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret215 = r->xf;
                            uint16_t a_all108 = r->a;
                            bool carry_ret108 = r->c;
                            bool overflow_ret108 = r->v;
                            if (x_ret215) {
                                a_hi_aa0c2 = a_all108 >> 8;
                                y_aa0c2 = value198;
                                carry_aa0c2 = carry_ret108;
                                overflow_aa0c2 = overflow_ret108;
                                direct_page_aa0c2 = dp_ret104;
                                data_bank_aa0c2 = db_ret108;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all108 >> 8;
                                y_aa0c3 = value198;
                                carry_aa0c3 = carry_ret108;
                                overflow_aa0c3 = overflow_ret108;
                                direct_page_aa0c3 = dp_ret104;
                                data_bank_aa0c3 = db_ret108;
                                goto shared_AA0C_2;
                            }
                        } else {
                            uint16_t value200 = BUS16_RDP(c, (uint16_t)(dp_ret103 + 1));
                            uint16_t value201 = BUS16_RDP(c, (db_ret107 << 0x10) + 8 + value200);
                            if (value201 == 0) {
                                if (m_ret45) {
                                    a_hi_aa0c4 = a_all107 >> 8;
                                    y_aa0c4 = value200;
                                    carry_aa0c4 = carry_ret107;
                                    overflow_aa0c4 = overflow_ret107;
                                    direct_page_aa0c4 = dp_ret103;
                                    data_bank_aa0c4 = db_ret107;
                                    goto shared_AA0C_3;
                                } else {
                                    a_hi_aa0c3 = a_all107 >> 8;
                                    y_aa0c3 = value200;
                                    carry_aa0c3 = carry_ret107;
                                    overflow_aa0c3 = overflow_ret107;
                                    direct_page_aa0c3 = dp_ret103;
                                    data_bank_aa0c3 = db_ret107;
                                    goto shared_AA0C_2;
                                }
                            }
                            r->x = value201;
                            r->y = value200;
                            r->z = value201 == 0;
                            r->n = value201 & 0x8000;
                            r->xf = 0;
                            r->sp -= 6;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAA0B, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xAA0B); } /* release_native_heap_suffix_through_bank_7f_api */
                            r->sp += 6;
                            uint16_t dp_ret105 = r->dp;
                            uint8_t db_ret109 = r->db;
                            if (r->mf != 0) { c->fail = 3; return; }
                            bool x_ret217 = r->xf;
                            uint16_t a_all109 = r->a;
                            bool carry_ret109 = r->c;
                            bool overflow_ret109 = r->v;
                            if (x_ret217) {
                                a_hi_aa0c2 = a_all109 >> 8;
                                y_aa0c2 = (uint8_t)value200;
                                carry_aa0c2 = carry_ret109;
                                overflow_aa0c2 = overflow_ret109;
                                direct_page_aa0c2 = dp_ret105;
                                data_bank_aa0c2 = db_ret109;
                                goto shared_AA0C_1;
                            } else {
                                a_hi_aa0c3 = a_all109 >> 8;
                                y_aa0c3 = value200;
                                carry_aa0c3 = carry_ret109;
                                overflow_aa0c3 = overflow_ret109;
                                direct_page_aa0c3 = dp_ret105;
                                data_bank_aa0c3 = db_ret109;
                                goto shared_AA0C_2;
                            }
                        }
                    }
                }
            }
        }
    }
    shared_AA0C:;
    uint8_t value202 = BUS8_RDP(c, (uint16_t)(direct_page_aa0c + 1));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_AA0C_1:;
    uint8_t value203 = BUS8_RDP(c, (uint16_t)(direct_page_aa0c2 + 1));
    BUS16_SET(c, (data_bank_aa0c2 << 0x10) + 2 + value203, 0);
    BUS16_SET(c, (data_bank_aa0c2 << 0x10) + 4 + value203, 0);
    r->a = 0;
    r->x = value203;
    r->y = y_aa0c2;
    r->c = carry_aa0c2;
    r->z = 1;
    r->n = 0;
    r->v = overflow_aa0c2;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_aa0c2;
    r->dp = direct_page_aa0c2;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAA19, 0x7EAAD7); GUARD_JSR(c, sp_call, 0xAA19); } /* free_task_id_and_record */
    r->sp += 6;
    uint8_t value204 = RAM8(0x0000 + sp0 - 5);
    uint8_t value207 = RAM8(0x0000 + sp0 - 2);
    uint8_t value208 = RAM8(0x0000 + sp0 - 1);
    uint8_t value209 = RAM8(0x0000 + sp0);
    r->c = value207 & 0x01;
    r->v = value207 & 0x40;
    r->mf = value207 & 0x20;
    r->xf = value207 & 0x10;
    r->db = value204;
    r->dp = (value209 << 8) | value208;
    r->i = value207 & 0x04;
    r->d = value207 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_AA0C_2:;
    uint16_t value210 = BUS16_RDP(c, (uint16_t)(direct_page_aa0c3 + 1));
    BUS16_SET(c, (data_bank_aa0c3 << 0x10) + 2 + value210, 0);
    BUS16_SET(c, (data_bank_aa0c3 << 0x10) + 4 + value210, 0);
    r->a = 0;
    r->x = value210;
    r->y = y_aa0c3;
    r->c = carry_aa0c3;
    r->z = 1;
    r->n = 0;
    r->v = overflow_aa0c3;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_aa0c3;
    r->dp = direct_page_aa0c3;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAA19, 0x7EAAD7); GUARD_JSR(c, sp_call, 0xAA19); } /* free_task_id_and_record */
    r->sp += 6;
    uint8_t value211 = RAM8(0x0000 + sp0 - 5);
    uint8_t value214 = RAM8(0x0000 + sp0 - 2);
    uint8_t value215 = RAM8(0x0000 + sp0 - 1);
    uint8_t value216 = RAM8(0x0000 + sp0);
    r->c = value214 & 0x01;
    r->v = value214 & 0x40;
    r->mf = value214 & 0x20;
    r->xf = value214 & 0x10;
    r->db = value211;
    r->dp = (value216 << 8) | value215;
    r->i = value214 & 0x04;
    r->d = value214 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_AA0C_3:;
    uint16_t value217 = BUS16_RDP(c, (uint16_t)(direct_page_aa0c4 + 1));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0x7EA9C7, SOM_RTS, "gen", reap_one_completed_task, 0, L_B | L_X | L_Y | L_C | L_V, 7, 1, 0, 91, 44)

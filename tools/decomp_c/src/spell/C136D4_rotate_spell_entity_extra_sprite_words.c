#include "som_c.h"

/* C136D4 rotate_spell_entity_extra_sprite_words   [class B, 61 bytes, 34 instructions]
 * Source: src/rom/rotate_spell_entity_extra_sprite_words.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void rotate_spell_entity_extra_sprite_words(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_36eb = 0;
    uint16_t y_36eb = 0;
    bool carry_36eb = 0;
    bool overflow_36eb = 0;
    uint16_t direct_page_36eb = 0;
    uint8_t data_bank_36eb = 0;
    uint16_t direct_page_3708 = 0;
    uint8_t data_bank_3708 = 0;
    uint8_t a_hi_36eb2 = 0;
    uint8_t y_36eb2 = 0;
    bool carry_36eb2 = 0;
    bool overflow_36eb2 = 0;
    uint16_t direct_page_36eb2 = 0;
    uint8_t data_bank_36eb2 = 0;
    uint16_t direct_page_37082 = 0;
    uint8_t data_bank_37082 = 0;
    uint8_t a_hi_36eb3 = 0;
    uint8_t y_36eb3 = 0;
    bool carry_36eb3 = 0;
    bool overflow_36eb3 = 0;
    uint16_t direct_page_36eb3 = 0;
    uint8_t data_bank_36eb3 = 0;
    uint16_t direct_page_37083 = 0;
    uint8_t data_bank_37083 = 0;
    uint8_t a_hi_36eb4 = 0;
    uint16_t y_36eb4 = 0;
    bool carry_36eb4 = 0;
    bool overflow_36eb4 = 0;
    uint16_t direct_page_36eb4 = 0;
    uint8_t data_bank_36eb4 = 0;
    uint16_t direct_page_37084 = 0;
    uint8_t data_bank_37084 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0026 + x, 2);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 7);
    a_hi_36eb = 0;
    y_36eb = x;
    carry_36eb = (uint16_t)(sp0 - 3) >= 4;
    overflow_36eb = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    direct_page_36eb = (uint16_t)(sp0 - 7);
    data_bank_36eb = 0x7E;
    shared_36EB:;
    BUS16_SET(c, (uint16_t)(direct_page_36eb + 3), (uint16_t)(y_36eb + 2));
    uint16_t value = BUS16_RDP(c, (data_bank_36eb << 0x10) + (uint16_t)(y_36eb + 2));
    if (value == 0) {
        direct_page_3708 = direct_page_36eb;
        data_bank_3708 = data_bank_36eb;
        goto shared_3708;
    }
    r->a = 0x0F01;
    r->x = value;
    r->y = (uint16_t)(y_36eb + 2);
    r->c = carry_36eb;
    r->z = 0;
    r->n = 0;
    r->v = overflow_36eb;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_36eb;
    r->dp = direct_page_36eb;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x36F9, 0xC1433E); GUARD_JSR(c, sp_call, 0x36F9); } /* rotate_spell_entity_words_backward */
    r->sp += 7;
    bool x_ret = r->xf;
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(direct_page_36eb + 3));
        uint8_t value3 = BUS8_RDP(c, (data_bank_36eb << 0x10) + value2);
        r->x = value3;
        r->y = value2;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->xf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3701, 0xC141F8); GUARD_JSR(c, sp_call, 0x3701); } /* queue_spell_entity_sprite_slot_write */
        r->sp += 7;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        if (x_ret3) {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 3));
            if (m_ret2) {
                uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value5 - 1));
                if ((uint8_t)(value5 - 1) != 0) {
                    a_hi_36eb2 = a_all2 >> 8;
                    y_36eb2 = value4;
                    carry_36eb2 = carry_ret2;
                    overflow_36eb2 = overflow_ret2;
                    direct_page_36eb2 = dp_ret;
                    data_bank_36eb2 = db_ret;
                    goto shared_36EB_1;
                }
                direct_page_37082 = dp_ret;
                data_bank_37082 = db_ret;
                goto shared_3708_1;
            } else {
                uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value6 - 1));
                if ((uint16_t)(value6 - 1) != 0) {
                    a_hi_36eb3 = a_all2 >> 8;
                    y_36eb3 = value4;
                    carry_36eb3 = carry_ret2;
                    overflow_36eb3 = overflow_ret2;
                    direct_page_36eb3 = dp_ret;
                    data_bank_36eb3 = db_ret;
                    goto shared_36EB_2;
                }
                direct_page_37083 = dp_ret;
                data_bank_37083 = db_ret;
                goto shared_3708_2;
            }
        } else {
            uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
            if (m_ret2) {
                uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value8 - 1));
                if ((uint8_t)(value8 - 1) != 0) {
                    a_hi_36eb4 = a_all2 >> 8;
                    y_36eb4 = value7;
                    carry_36eb4 = carry_ret2;
                    overflow_36eb4 = overflow_ret2;
                    direct_page_36eb4 = dp_ret;
                    data_bank_36eb4 = db_ret;
                    goto shared_36EB_3;
                }
                direct_page_37084 = dp_ret;
                data_bank_37084 = db_ret;
                goto shared_3708_3;
            } else {
                uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value9 - 1));
                if ((uint16_t)(value9 - 1) != 0) {
                    a_hi_36eb = a_all2 >> 8;
                    y_36eb = value7;
                    carry_36eb = carry_ret2;
                    overflow_36eb = overflow_ret2;
                    direct_page_36eb = dp_ret;
                    data_bank_36eb = db_ret;
                    goto shared_36EB;
                }
                direct_page_3708 = dp_ret;
                data_bank_3708 = db_ret;
                goto shared_3708;
            }
        }
    } else {
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(direct_page_36eb + 3));
        uint16_t value11 = BUS16_RDP(c, (data_bank_36eb << 0x10) + value10);
        r->x = value11;
        r->y = value10;
        r->z = value11 == 0;
        r->n = value11 & 0x8000;
        r->xf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3701, 0xC141F8); GUARD_JSR(c, sp_call, 0x3701); } /* queue_spell_entity_sprite_slot_write */
        r->sp += 7;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret5 = r->xf;
        uint16_t a_all3 = r->a;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        if (x_ret5) {
            uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 3));
            if (m_ret3) {
                uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value13 - 1));
                if ((uint8_t)(value13 - 1) != 0) {
                    a_hi_36eb2 = a_all3 >> 8;
                    y_36eb2 = value12;
                    carry_36eb2 = carry_ret3;
                    overflow_36eb2 = overflow_ret3;
                    direct_page_36eb2 = dp_ret2;
                    data_bank_36eb2 = db_ret2;
                    goto shared_36EB_1;
                }
                direct_page_37082 = dp_ret2;
                data_bank_37082 = db_ret2;
                goto shared_3708_1;
            } else {
                uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value14 - 1));
                if ((uint16_t)(value14 - 1) != 0) {
                    a_hi_36eb3 = a_all3 >> 8;
                    y_36eb3 = value12;
                    carry_36eb3 = carry_ret3;
                    overflow_36eb3 = overflow_ret3;
                    direct_page_36eb3 = dp_ret2;
                    data_bank_36eb3 = db_ret2;
                    goto shared_36EB_2;
                }
                direct_page_37083 = dp_ret2;
                data_bank_37083 = db_ret2;
                goto shared_3708_2;
            }
        } else {
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
            if (m_ret3) {
                uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value16 - 1));
                if ((uint8_t)(value16 - 1) != 0) {
                    a_hi_36eb4 = a_all3 >> 8;
                    y_36eb4 = value15;
                    carry_36eb4 = carry_ret3;
                    overflow_36eb4 = overflow_ret3;
                    direct_page_36eb4 = dp_ret2;
                    data_bank_36eb4 = db_ret2;
                    goto shared_36EB_3;
                }
                direct_page_37084 = dp_ret2;
                data_bank_37084 = db_ret2;
                goto shared_3708_3;
            } else {
                uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value17 - 1));
                if ((uint16_t)(value17 - 1) != 0) {
                    a_hi_36eb = a_all3 >> 8;
                    y_36eb = value15;
                    carry_36eb = carry_ret3;
                    overflow_36eb = overflow_ret3;
                    direct_page_36eb = dp_ret2;
                    data_bank_36eb = db_ret2;
                    goto shared_36EB;
                }
                direct_page_3708 = dp_ret2;
                data_bank_3708 = db_ret2;
                goto shared_3708;
            }
        }
    }
    shared_3708:;
    uint8_t value22 = RAM8(0x0000 + sp0 - 2);
    uint8_t value23 = RAM8(0x0000 + sp0 - 1);
    uint8_t value24 = RAM8(0x0000 + sp0);
    r->mf = value22 & 0x20;
    r->xf = value22 & 0x10;
    r->db = data_bank_3708;
    r->dp = (value24 << 8) | value23;
    r->i = value22 & 0x04;
    r->d = value22 & 0x08;
    RETURN_RTS(c);
    shared_36EB_1:;
    BUS8_SET(c, (uint16_t)(direct_page_36eb2 + 3), (uint8_t)(y_36eb2 + 2));
    uint8_t value25 = BUS8_RDP(c, (data_bank_36eb2 << 0x10) + (uint8_t)(y_36eb2 + 2));
    if (value25 == 0) {
        direct_page_37082 = direct_page_36eb2;
        data_bank_37082 = data_bank_36eb2;
        goto shared_3708_1;
    }
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_3708_1:;
    uint8_t value30 = RAM8(0x0000 + sp0 - 2);
    uint8_t value31 = RAM8(0x0000 + sp0 - 1);
    uint8_t value32 = RAM8(0x0000 + sp0);
    r->mf = value30 & 0x20;
    r->xf = value30 & 0x10;
    r->db = data_bank_37082;
    r->dp = (value32 << 8) | value31;
    r->i = value30 & 0x04;
    r->d = value30 & 0x08;
    RETURN_RTS(c);
    shared_36EB_2:;
    BUS8_SET(c, (uint16_t)(direct_page_36eb3 + 3), (uint8_t)(y_36eb3 + 2));
    uint8_t value33 = BUS8_RDP(c, (data_bank_36eb3 << 0x10) + (uint8_t)(y_36eb3 + 2));
    if (value33 == 0) {
        direct_page_37083 = direct_page_36eb3;
        data_bank_37083 = data_bank_36eb3;
        goto shared_3708_2;
    }
    r->a = 0x0F01;
    r->x = value33;
    r->y = (uint8_t)(y_36eb3 + 2);
    r->c = carry_36eb3;
    r->z = 0;
    r->n = 0;
    r->v = overflow_36eb3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_36eb3;
    r->dp = direct_page_36eb3;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x36F9, 0xC1433E); GUARD_JSR(c, sp_call, 0x36F9); } /* rotate_spell_entity_words_backward */
    r->sp += 7;
    bool x_ret7 = r->xf;
    if (x_ret7) {
        uint8_t value34 = BUS8_RDP(c, (uint16_t)(direct_page_36eb3 + 3));
        uint8_t value35 = BUS8_RDP(c, (data_bank_36eb3 << 0x10) + value34);
        r->x = value35;
        r->y = value34;
        r->z = value35 == 0;
        r->n = value35 & 0x80;
        r->xf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3701, 0xC141F8); GUARD_JSR(c, sp_call, 0x3701); } /* queue_spell_entity_sprite_slot_write */
        r->sp += 7;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret5 = r->mf;
        bool x_ret9 = r->xf;
        uint16_t a_all5 = r->a;
        bool carry_ret5 = r->c;
        bool overflow_ret5 = r->v;
        if (x_ret9) {
            uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 3));
            if (m_ret5) {
                uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value37 - 1));
                if ((uint8_t)(value37 - 1) != 0) {
                    a_hi_36eb2 = a_all5 >> 8;
                    y_36eb2 = value36;
                    carry_36eb2 = carry_ret5;
                    overflow_36eb2 = overflow_ret5;
                    direct_page_36eb2 = dp_ret3;
                    data_bank_36eb2 = db_ret3;
                    goto shared_36EB_1;
                }
                direct_page_37082 = dp_ret3;
                data_bank_37082 = db_ret3;
                goto shared_3708_1;
            } else {
                uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 1), (uint16_t)(value38 - 1));
                if ((uint16_t)(value38 - 1) != 0) {
                    a_hi_36eb3 = a_all5 >> 8;
                    y_36eb3 = value36;
                    carry_36eb3 = carry_ret5;
                    overflow_36eb3 = overflow_ret5;
                    direct_page_36eb3 = dp_ret3;
                    data_bank_36eb3 = db_ret3;
                    goto shared_36EB_2;
                }
                direct_page_37083 = dp_ret3;
                data_bank_37083 = db_ret3;
                goto shared_3708_2;
            }
        } else {
            uint16_t value39 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 3));
            if (m_ret5) {
                uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value40 - 1));
                if ((uint8_t)(value40 - 1) != 0) {
                    a_hi_36eb4 = a_all5 >> 8;
                    y_36eb4 = value39;
                    carry_36eb4 = carry_ret5;
                    overflow_36eb4 = overflow_ret5;
                    direct_page_36eb4 = dp_ret3;
                    data_bank_36eb4 = db_ret3;
                    goto shared_36EB_3;
                }
                direct_page_37084 = dp_ret3;
                data_bank_37084 = db_ret3;
                goto shared_3708_3;
            } else {
                uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 1), (uint16_t)(value41 - 1));
                if ((uint16_t)(value41 - 1) != 0) {
                    a_hi_36eb = a_all5 >> 8;
                    y_36eb = value39;
                    carry_36eb = carry_ret5;
                    overflow_36eb = overflow_ret5;
                    direct_page_36eb = dp_ret3;
                    data_bank_36eb = db_ret3;
                    goto shared_36EB;
                }
                direct_page_3708 = dp_ret3;
                data_bank_3708 = db_ret3;
                goto shared_3708;
            }
        }
    } else {
        uint16_t value42 = BUS16_RDP(c, (uint16_t)(direct_page_36eb3 + 3));
        uint16_t value43 = BUS16_RDP(c, (data_bank_36eb3 << 0x10) + value42);
        r->x = value43;
        r->y = value42;
        r->z = value43 == 0;
        r->n = value43 & 0x8000;
        r->xf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3701, 0xC141F8); GUARD_JSR(c, sp_call, 0x3701); } /* queue_spell_entity_sprite_slot_write */
        r->sp += 7;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        bool m_ret6 = r->mf;
        bool x_ret11 = r->xf;
        uint16_t a_all6 = r->a;
        bool carry_ret6 = r->c;
        bool overflow_ret6 = r->v;
        if (x_ret11) {
            uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 3));
            if (m_ret6) {
                uint8_t value45 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value45 - 1));
                if ((uint8_t)(value45 - 1) != 0) {
                    a_hi_36eb2 = a_all6 >> 8;
                    y_36eb2 = value44;
                    carry_36eb2 = carry_ret6;
                    overflow_36eb2 = overflow_ret6;
                    direct_page_36eb2 = dp_ret4;
                    data_bank_36eb2 = db_ret4;
                    goto shared_36EB_1;
                }
                direct_page_37082 = dp_ret4;
                data_bank_37082 = db_ret4;
                goto shared_3708_1;
            } else {
                uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 1), (uint16_t)(value46 - 1));
                if ((uint16_t)(value46 - 1) != 0) {
                    a_hi_36eb3 = a_all6 >> 8;
                    y_36eb3 = value44;
                    carry_36eb3 = carry_ret6;
                    overflow_36eb3 = overflow_ret6;
                    direct_page_36eb3 = dp_ret4;
                    data_bank_36eb3 = db_ret4;
                    goto shared_36EB_2;
                }
                direct_page_37083 = dp_ret4;
                data_bank_37083 = db_ret4;
                goto shared_3708_2;
            }
        } else {
            uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 3));
            if (m_ret6) {
                uint8_t value48 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret4 + 1), (uint8_t)(value48 - 1));
                if ((uint8_t)(value48 - 1) != 0) {
                    a_hi_36eb4 = a_all6 >> 8;
                    y_36eb4 = value47;
                    carry_36eb4 = carry_ret6;
                    overflow_36eb4 = overflow_ret6;
                    direct_page_36eb4 = dp_ret4;
                    data_bank_36eb4 = db_ret4;
                    goto shared_36EB_3;
                }
                direct_page_37084 = dp_ret4;
                data_bank_37084 = db_ret4;
                goto shared_3708_3;
            } else {
                uint16_t value49 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 1), (uint16_t)(value49 - 1));
                if ((uint16_t)(value49 - 1) != 0) {
                    a_hi_36eb = a_all6 >> 8;
                    y_36eb = value47;
                    carry_36eb = carry_ret6;
                    overflow_36eb = overflow_ret6;
                    direct_page_36eb = dp_ret4;
                    data_bank_36eb = db_ret4;
                    goto shared_36EB;
                }
                direct_page_3708 = dp_ret4;
                data_bank_3708 = db_ret4;
                goto shared_3708;
            }
        }
    }
    shared_3708_2:;
    uint8_t value54 = RAM8(0x0000 + sp0 - 2);
    uint8_t value55 = RAM8(0x0000 + sp0 - 1);
    uint8_t value56 = RAM8(0x0000 + sp0);
    r->mf = value54 & 0x20;
    r->xf = value54 & 0x10;
    r->db = data_bank_37083;
    r->dp = (value56 << 8) | value55;
    r->i = value54 & 0x04;
    r->d = value54 & 0x08;
    RETURN_RTS(c);
    shared_36EB_3:;
    BUS16_SET(c, (uint16_t)(direct_page_36eb4 + 3), (uint16_t)(y_36eb4 + 2));
    uint16_t value57 = BUS16_RDP(c, (data_bank_36eb4 << 0x10) + (uint16_t)(y_36eb4 + 2));
    if (value57 == 0) {
        direct_page_37084 = direct_page_36eb4;
        data_bank_37084 = data_bank_36eb4;
        goto shared_3708_3;
    }
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_3708_3:;
    uint8_t value62 = RAM8(0x0000 + sp0 - 2);
    uint8_t value63 = RAM8(0x0000 + sp0 - 1);
    uint8_t value64 = RAM8(0x0000 + sp0);
    r->mf = value62 & 0x20;
    r->xf = value62 & 0x10;
    r->db = data_bank_37084;
    r->dp = (value64 << 8) | value63;
    r->i = value62 & 0x04;
    r->d = value62 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC136D4, SOM_RTS, "gen", rotate_spell_entity_extra_sprite_words, 0, 0, 7, 1, 0, 61, 34)

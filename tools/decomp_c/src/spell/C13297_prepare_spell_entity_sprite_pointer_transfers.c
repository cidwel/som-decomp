#include "som_c.h"

/* C13297 prepare_spell_entity_sprite_pointer_transfers   [class B, 123 bytes, 67 instructions]
 * Source: src/rom/prepare_spell_entity_sprite_pointer_transfers.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: CV.
 */
static void prepare_spell_entity_sprite_pointer_transfers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0A) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_32cf = 0;
    uint16_t y_32cf = 0;
    bool carry_32cf = 0;
    bool overflow_32cf = 0;
    uint16_t direct_page_32cf = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0A), x);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0A), y);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)value;
    uint8_t value2 = RAM8(0x0000 + y);
    uint8_t value3 = RAM8(0xE180 + (uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1));
    if (value3 < 0x57) {
        a_hi_32cf = (uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1) >> 8;
        y_32cf = y;
        carry_32cf = value3 >= 0x57;
        overflow_32cf = (((uint16_t)(sp0 - 5) ^ 5) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
        direct_page_32cf = (uint16_t)(sp0 - 0x0A);
        goto shared_32CF;
    }
    if (value3 >= 0x80) {
        a_hi_32cf = (uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1) >> 8;
        y_32cf = y;
        carry_32cf = value3 >= 0x80;
        overflow_32cf = (((uint16_t)(sp0 - 5) ^ 5) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
        direct_page_32cf = (uint16_t)(sp0 - 0x0A);
        goto shared_32CF;
    }
    uint8_t value4 = RAM8(0x0001 + (uint16_t)(sp0 - 0x0A));
    uint16_t value5 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0A));
    r->a = ((uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1) >> 8 << 8) | value4;
    r->x = value5;
    r->c = value3 >= 0x80;
    r->z = value5 == 0;
    r->n = value5 & 0x8000;
    r->v = (((uint16_t)(sp0 - 5) ^ 5) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 0x0A);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x32CC, 0xC13113); GUARD_JSR(c, sp_call, 0x32CC); } /* construct_boss_spell_entity_sprite_pointer_set */
    r->sp += 10;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint16_t value6 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0A));
    RAM8(0x0006 + (uint16_t)(sp0 - 0x0A)) = 8;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t y1 = value6;
    bool carry1 = carry_ret;
    bool zero1 = 0;
    bool negative1 = 0;
    bool overflow1 = overflow_ret;
    uint8_t data_bank = db_ret;
    uint16_t direct_page = (uint16_t)(sp0 - 0x0A);
    for (;;) {
        uint16_t value7 = BUS16_RDP(c, (data_bank << 0x10) + y1);
        if (value7 == 0) {
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(direct_page + 6));
            BUS8_SET(c, (uint16_t)(direct_page + 6), (uint8_t)(value8 - 1));
            if ((uint8_t)(value8 - 1) != 0) {
                y1 = (uint16_t)(y1 + 2);
                zero1 = (uint8_t)(value8 - 1) == 0;
                negative1 = (uint8_t)(value8 - 1) & 0x80;
                continue;
            }
            y1 = (uint16_t)(y1 + 2);
            zero1 = (uint8_t)(value8 - 1) == 0;
            negative1 = (uint8_t)(value8 - 1) & 0x80;
            break;
        }
        RAM8(0x0000 + sp0 - 0x0A) = y1 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)y1;
        r->x = value7;
        r->y = y1;
        r->c = carry1;
        r->z = value7 == 0;
        r->n = value7 & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x32E4, 0xC14240); GUARD_JSR(c, sp_call, 0x32E4); } /* queue_spell_entity_sprite_slot_read */
        r->sp += 12;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        uint8_t value9 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value10 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 6));
        BUS8_SET(c, (uint16_t)(dp_ret + 6), (uint8_t)(value11 - 1));
        if ((uint8_t)(value11 - 1) != 0) {
            a_hi1 = a_all2 >> 8;
            y1 = (uint16_t)(((value10 << 8) | value9) + 2);
            carry1 = carry_ret2;
            zero1 = (uint8_t)(value11 - 1) == 0;
            negative1 = (uint8_t)(value11 - 1) & 0x80;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret;
            continue;
        }
        a_hi1 = a_all2 >> 8;
        y1 = (uint16_t)(((value10 << 8) | value9) + 2);
        carry1 = carry_ret2;
        zero1 = (uint8_t)(value11 - 1) == 0;
        negative1 = (uint8_t)(value11 - 1) & 0x80;
        overflow1 = overflow_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret;
        break;
    }
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x32EE, 0xC12FE4); GUARD_JSR(c, sp_call, 0x32EE); } /* wait_for_spell_entity_irq_completion */
    r->sp += 10;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint16_t value12 = BUS16_RDP(c, (uint16_t)(direct_page + 2));
    BUS8_SET(c, (uint16_t)(direct_page + 6), 8);
    uint16_t y2 = value12;
    bool carry2 = carry_ret3;
    bool overflow2 = overflow_ret3;
    uint8_t data_bank2 = data_bank;
    uint16_t direct_page2 = direct_page;
    for (;;) {
        uint16_t value13 = BUS16_RDP(c, (data_bank2 << 0x10) + y2);
        if (value13 == 0) {
            uint8_t value14 = BUS8_RDP(c, (uint16_t)(direct_page2 + 6));
            BUS8_SET(c, (uint16_t)(direct_page2 + 6), (uint8_t)(value14 - 1));
            if ((uint8_t)(value14 - 1) != 0) {
                y2 = (uint16_t)(y2 + 2);
                continue;
            }
            y2 = (uint16_t)(y2 + 2);
            break;
        }
        RAM8(0x0000 + sp0 - 0x0A) = y2 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)y2;
        r->x = value13;
        r->y = y2;
        r->c = carry2;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank2;
        r->dp = direct_page2;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x32FD, 0xC143B6); GUARD_JSR(c, sp_call, 0x32FD); } /* save_spell_entity_sprite_slot_shadow */
        r->sp += 12;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        uint8_t value15 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value16 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 6));
        BUS8_SET(c, (uint16_t)(dp_ret2 + 6), (uint8_t)(value17 - 1));
        if ((uint8_t)(value17 - 1) != 0) {
            y2 = (uint16_t)(((value16 << 8) | value15) + 2);
            carry2 = carry_ret4;
            overflow2 = overflow_ret4;
            data_bank2 = db_ret3;
            direct_page2 = dp_ret2;
            continue;
        }
        y2 = (uint16_t)(((value16 << 8) | value15) + 2);
        carry2 = carry_ret4;
        overflow2 = overflow_ret4;
        data_bank2 = db_ret3;
        direct_page2 = dp_ret2;
        break;
    }
    uint16_t value18 = BUS16_RDP(c, (uint16_t)(direct_page2 + 2));
    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
    uint8_t value21 = RAM8(0x0000 + sp0);
    r->c = value19 & 0x01;
    r->v = value19 & 0x40;
    r->mf = value19 & 0x20;
    r->xf = value19 & 0x10;
    r->db = data_bank2;
    r->dp = (value21 << 8) | value20;
    r->i = value19 & 0x04;
    r->d = value19 & 0x08;
    RETURN_RTS(c);
    shared_32CF:;
    uint8_t value22 = BUS8_RDP(c, (uint16_t)(direct_page_32cf + 1));
    uint16_t value23 = BUS16_RDP(c, (uint16_t)(direct_page_32cf + 2));
    r->a = (a_hi_32cf << 8) | value22;
    r->x = value23;
    r->y = y_32cf;
    r->c = carry_32cf;
    r->z = value23 == 0;
    r->n = value23 & 0x8000;
    r->v = overflow_32cf;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_32cf;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x32D5, 0xC131E4); GUARD_JSR(c, sp_call, 0x32D5); } /* construct_spell_entity_sprite_pointer_set */
    r->sp += 10;
    uint8_t db_ret4 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all5 = r->a;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    uint16_t value24 = BUS16_RDP(c, (uint16_t)(direct_page_32cf + 2));
    BUS8_SET(c, (uint16_t)(direct_page_32cf + 6), 8);
    uint8_t a_hi2 = a_all5 >> 8;
    uint16_t y3 = value24;
    bool carry3 = carry_ret5;
    bool zero2 = 0;
    bool negative2 = 0;
    bool overflow3 = overflow_ret5;
    uint8_t data_bank3 = db_ret4;
    uint16_t direct_page3 = direct_page_32cf;
    for (;;) {
        uint16_t value25 = BUS16_RDP(c, (data_bank3 << 0x10) + y3);
        if (value25 == 0) {
            uint8_t value26 = BUS8_RDP(c, (uint16_t)(direct_page3 + 6));
            BUS8_SET(c, (uint16_t)(direct_page3 + 6), (uint8_t)(value26 - 1));
            if ((uint8_t)(value26 - 1) != 0) {
                y3 = (uint16_t)(y3 + 2);
                zero2 = (uint8_t)(value26 - 1) == 0;
                negative2 = (uint8_t)(value26 - 1) & 0x80;
                continue;
            }
            y3 = (uint16_t)(y3 + 2);
            zero2 = (uint8_t)(value26 - 1) == 0;
            negative2 = (uint8_t)(value26 - 1) & 0x80;
            break;
        }
        RAM8(0x0000 + sp0 - 0x0A) = y3 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)y3;
        r->x = value25;
        r->y = y3;
        r->c = carry3;
        r->z = value25 == 0;
        r->n = value25 & 0x8000;
        r->v = overflow3;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank3;
        r->dp = direct_page3;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x32E4, 0xC14240); GUARD_JSR(c, sp_call, 0x32E4); } /* queue_spell_entity_sprite_slot_read */
        r->sp += 12;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret5 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all6 = r->a;
        bool carry_ret6 = r->c;
        bool overflow_ret6 = r->v;
        uint8_t value27 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value28 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 6));
        BUS8_SET(c, (uint16_t)(dp_ret3 + 6), (uint8_t)(value29 - 1));
        if ((uint8_t)(value29 - 1) != 0) {
            a_hi2 = a_all6 >> 8;
            y3 = (uint16_t)(((value28 << 8) | value27) + 2);
            carry3 = carry_ret6;
            zero2 = (uint8_t)(value29 - 1) == 0;
            negative2 = (uint8_t)(value29 - 1) & 0x80;
            overflow3 = overflow_ret6;
            data_bank3 = db_ret5;
            direct_page3 = dp_ret3;
            continue;
        }
        a_hi2 = a_all6 >> 8;
        y3 = (uint16_t)(((value28 << 8) | value27) + 2);
        carry3 = carry_ret6;
        zero2 = (uint8_t)(value29 - 1) == 0;
        negative2 = (uint8_t)(value29 - 1) & 0x80;
        overflow3 = overflow_ret6;
        data_bank3 = db_ret5;
        direct_page3 = dp_ret3;
        break;
    }
    r->y = y3;
    r->c = carry3;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank3;
    r->dp = direct_page3;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x32EE, 0xC12FE4); GUARD_JSR(c, sp_call, 0x32EE); } /* wait_for_spell_entity_irq_completion */
    r->sp += 10;
    bool carry_ret7 = r->c;
    bool overflow_ret7 = r->v;
    uint16_t value30 = BUS16_RDP(c, (uint16_t)(direct_page3 + 2));
    BUS8_SET(c, (uint16_t)(direct_page3 + 6), 8);
    uint16_t y4 = value30;
    bool carry4 = carry_ret7;
    bool overflow4 = overflow_ret7;
    uint8_t data_bank4 = data_bank3;
    uint16_t direct_page4 = direct_page3;
    for (;;) {
        uint16_t value31 = BUS16_RDP(c, (data_bank4 << 0x10) + y4);
        if (value31 == 0) {
            uint8_t value32 = BUS8_RDP(c, (uint16_t)(direct_page4 + 6));
            BUS8_SET(c, (uint16_t)(direct_page4 + 6), (uint8_t)(value32 - 1));
            if ((uint8_t)(value32 - 1) != 0) {
                y4 = (uint16_t)(y4 + 2);
                continue;
            }
            y4 = (uint16_t)(y4 + 2);
            break;
        }
        RAM8(0x0000 + sp0 - 0x0A) = y4 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)y4;
        r->x = value31;
        r->y = y4;
        r->c = carry4;
        r->z = value31 == 0;
        r->n = value31 & 0x8000;
        r->v = overflow4;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank4;
        r->dp = direct_page4;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x32FD, 0xC143B6); GUARD_JSR(c, sp_call, 0x32FD); } /* save_spell_entity_sprite_slot_shadow */
        r->sp += 12;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret6 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        bool carry_ret8 = r->c;
        bool overflow_ret8 = r->v;
        uint8_t value33 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value34 = RAM8(0x0000 + sp0 - 0x0A);
        uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 6));
        BUS8_SET(c, (uint16_t)(dp_ret4 + 6), (uint8_t)(value35 - 1));
        if ((uint8_t)(value35 - 1) != 0) {
            y4 = (uint16_t)(((value34 << 8) | value33) + 2);
            carry4 = carry_ret8;
            overflow4 = overflow_ret8;
            data_bank4 = db_ret6;
            direct_page4 = dp_ret4;
            continue;
        }
        y4 = (uint16_t)(((value34 << 8) | value33) + 2);
        carry4 = carry_ret8;
        overflow4 = overflow_ret8;
        data_bank4 = db_ret6;
        direct_page4 = dp_ret4;
        break;
    }
    uint16_t value36 = BUS16_RDP(c, (uint16_t)(direct_page4 + 2));
    uint8_t value37 = RAM8(0x0000 + sp0 - 2);
    uint8_t value38 = RAM8(0x0000 + sp0 - 1);
    uint8_t value39 = RAM8(0x0000 + sp0);
    r->c = value37 & 0x01;
    r->v = value37 & 0x40;
    r->mf = value37 & 0x20;
    r->xf = value37 & 0x10;
    r->db = data_bank4;
    r->dp = (value39 << 8) | value38;
    r->i = value37 & 0x04;
    r->d = value37 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13297, SOM_RTS, "gen", prepare_spell_entity_sprite_pointer_transfers, 0, L_C | L_V, 12, -1, 0, 123, 67)

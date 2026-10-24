#include "som_c.h"

/* C1332C construct_spell_entity_visual_resource   [class B, 302 bytes, 135 instructions]
 * Source: src/rom/construct_spell_entity_visual_resource.s
 * Documented in docs/actor-cast-entity-resources.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XY.
 */
static void construct_spell_entity_visual_resource(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 0x11) + 0xE > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x11), x);
    RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x11), y);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x11), (RAM16(0x0026 + y) & 4) << 1 << 1 << 1 << 1);
    uint16_t value2 = RAM16(0x0028 + y);
    BUS16_SET(c, 0x004202, ((value2 & 0x0600) >> 1 >> 8 << 8) | 5);
    RAM8(0x0000 + sp0 - 0x11) = (value2 & 0x0600) >> 1 >> 8;
    RAM8(0x0000 + sp0 - 0x12) = (uint8_t)(((value2 & 0x0600) >> 1 >> 8 << 8) | 5);
    uint16_t value3 = BUS16(c, 0x004216);
    uint16_t value4 = RAM16(0x0001 + (uint16_t)(sp0 - 0x11));
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x11), (uint16_t)((uint16_t)(value3 + 1) + value4));
    r->a = 0;
    r->x = 0x28;
    r->c = (uint16_t)(value3 + 1) + value4 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(value3 + 1) ^ (uint16_t)((uint16_t)(value3 + 1) + value4)) & (value4 ^ (uint16_t)((uint16_t)(value3 + 1) + value4)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x11);
    r->sp -= 17;
    { const uint16_t sp_call = r->sp; JSR(c, 0x336E, 0xC13D48); GUARD_JSR(c, sp_call, 0x336E); } /* allocate_and_fill_spell_entity_heap_bytes */
    r->sp += 17;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x11), x_ret);
    uint16_t value5 = RAM16(0x0005 + (uint16_t)(sp0 - 0x11));
    uint16_t value6 = RAM16(0x0003 + (uint16_t)(sp0 - 0x11));
    uint8_t value7 = BUS8(c, 0xDCF80B + value5);
    RAM8(0x0024 + value6) = value7;
    bool m_flag2;
    bool x_flag2;
    uint8_t a_hi2;
    uint16_t y2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (value7 == 0) {
        m_flag2 = 1;
        x_flag2 = 0;
        a_hi2 = a_all >> 8;
        y2 = value6;
        carry2 = carry_ret;
        zero2 = value7 == 0;
        negative2 = value7 & 0x80;
        overflow2 = overflow_ret;
        data_bank2 = 0x7E;
        direct_page2 = (uint16_t)(sp0 - 0x11);
    } else {
        RAM8(0x000E + (uint16_t)(sp0 - 0x11)) = (value7 & 0xC0) | 3;
        RAM8(0x000D + (uint16_t)(sp0 - 0x11)) = RAM8(0x0024 + value6) | 0xE0;
        uint8_t value10 = RAM8(0x002C + RAM16(0x0007 + (uint16_t)(sp0 - 0x11)));
        bool m_flag;
        bool x_flag;
        uint8_t a_hi1;
        uint16_t y1;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if (value10 != 0) {
            m_flag = 1;
            x_flag = 0;
            a_hi1 = a_all >> 8;
            y1 = value6;
            carry1 = carry_ret;
            zero1 = value10 == 0;
            negative1 = value10 & 0x80;
            overflow1 = overflow_ret;
            data_bank = 0x7E;
            direct_page = (uint16_t)(sp0 - 0x11);
        } else {
            r->a = (a_all >> 8 << 8) | 0x30;
            r->y = value6;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->sp -= 17;
            { const uint16_t sp_call = r->sp; JSR(c, 0x3398, 0xC144B3); GUARD_JSR(c, sp_call, 0x3398); } /* allocate_spell_entity_register_record */
            r->sp += 17;
            uint8_t db_ret = r->db;
            uint16_t x_ret3 = r->x;
            BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret3, 0);
            r->z = 1;
            r->n = 0;
            r->sp -= 17;
            { const uint16_t sp_call = r->sp; JSR(c, 0x33A0, 0xC14514); GUARD_JSR(c, sp_call, 0x33A0); } /* append_spell_entity_transient_register_record */
            r->sp += 17;
            uint16_t a_all3 = r->a;
            r->a = (a_all3 >> 8 << 8) | 0x31;
            r->z = 0;
            r->n = 0;
            r->sp -= 17;
            { const uint16_t sp_call = r->sp; JSR(c, 0x33A5, 0xC144B3); GUARD_JSR(c, sp_call, 0x33A5); } /* allocate_spell_entity_register_record */
            r->sp += 17;
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t x_ret6 = r->x;
            uint8_t value11 = RAM8(0x000E + dp_ret3);
            BUS8_SET(c, (db_ret3 << 0x10) + 2 + x_ret6, value11);
            r->z = value11 == 0;
            r->n = value11 & 0x80;
            r->sp -= 17;
            { const uint16_t sp_call = r->sp; JSR(c, 0x33AD, 0xC14514); GUARD_JSR(c, sp_call, 0x33AD); } /* append_spell_entity_transient_register_record */
            r->sp += 17;
            uint16_t a_all5 = r->a;
            r->a = (a_all5 >> 8 << 8) | 0x32;
            r->z = 0;
            r->n = 0;
            r->sp -= 17;
            { const uint16_t sp_call = r->sp; JSR(c, 0x33B2, 0xC144B3); GUARD_JSR(c, sp_call, 0x33B2); } /* allocate_spell_entity_register_record */
            r->sp += 17;
            uint16_t dp_ret5 = r->dp;
            uint8_t db_ret5 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t x_ret9 = r->x;
            uint8_t value12 = RAM8(0x000D + dp_ret5);
            BUS8_SET(c, (db_ret5 << 0x10) + 2 + x_ret9, value12);
            r->z = value12 == 0;
            r->n = value12 & 0x80;
            r->sp -= 17;
            { const uint16_t sp_call = r->sp; JSR(c, 0x33BA, 0xC14514); GUARD_JSR(c, sp_call, 0x33BA); } /* append_spell_entity_transient_register_record */
            r->sp += 17;
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            bool m_ret2 = r->mf;
            bool x_ret10 = r->xf;
            uint16_t a_all7 = r->a;
            uint16_t y_ret7 = r->y;
            bool carry_ret7 = r->c;
            bool zero_ret7 = r->z;
            bool negative_ret7 = r->n;
            bool overflow_ret7 = r->v;
            m_flag = m_ret2;
            x_flag = x_ret10;
            a_hi1 = a_all7 >> 8;
            y1 = y_ret7;
            carry1 = carry_ret7;
            zero1 = zero_ret7;
            negative1 = negative_ret7;
            overflow1 = overflow_ret7;
            data_bank = db_ret6;
            direct_page = dp_ret6;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a_hi2 = a_hi1;
        y2 = y1;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->y = y2;
    r->c = carry2;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    r->sp -= 17;
    { const uint16_t sp_call = r->sp; JSR(c, 0x33BD, 0xC12FE4); GUARD_JSR(c, sp_call, 0x33BD); } /* wait_for_spell_entity_irq_completion */
    r->sp += 17;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value13 = RAM16(0x0007 + direct_page2);
    uint16_t value14 = RAM16(0x0003 + direct_page2);
    uint16_t value15 = RAM16(0x0001 + direct_page2);
    r->a = value15;
    r->x = value14;
    r->y = value13;
    r->z = value15 == 0;
    r->n = value15 & 0x8000;
    r->mf = 0;
    r->sp -= 17;
    { const uint16_t sp_call = r->sp; JSR(c, 0x33C8, 0xC13297); GUARD_JSR(c, sp_call, 0x33C8); } /* prepare_spell_entity_sprite_pointer_transfers */
    r->sp += 17;
    uint8_t db_ret7 = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    bool carry_ret9 = r->c;
    bool overflow_ret9 = r->v;
    uint16_t value17 = BUS16(c, 0xDCF80C + RAM16(0x0005 + direct_page2));
    RAM16_SET(0x000B + direct_page2, value17);
    uint16_t value19 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x27 + RAM16(0x0007 + direct_page2));
    RAM16_SET(0x0009 + direct_page2, value19 & 0xFF);
    uint16_t value20 = RAM16(0x0003 + direct_page2);
    uint8_t a_hi3 = 0;
    uint16_t y3 = value20;
    bool carry3 = carry_ret9;
    bool overflow3 = overflow_ret9;
    for (;;) {
        uint16_t value21 = BUS16_RDP(c, (db_ret7 << 0x10) + (uint16_t)(y3 + 2));
        if (value21 == 0) {
            y3 = (uint16_t)(y3 + 2);
            break;
        }
        RAM8(0x0000 + sp0 - 0x11) = (uint16_t)(y3 + 2) >> 8;
        RAM8(0x0000 + sp0 - 0x12) = (uint8_t)(y3 + 2);
        uint16_t value22 = RAM16(0x000B + direct_page2);
        if (value22 == 0) {
            RAM16_SET(0x0009 + direct_page2, (uint16_t)(RAM16(0x0009 + direct_page2) - 1));
            if (RAM16(0x0009 + direct_page2) != 0) {
                y3 = (uint16_t)(y3 + 2);
                continue;
            }
            y3 = (uint16_t)(y3 + 2);
            break;
        }
        r->a = 0xC81E;
        r->x = value21;
        r->y = value22;
        r->c = carry3;
        r->z = 0;
        r->n = 1;
        r->v = overflow3;
        r->mf = 0;
        r->xf = 0;
        r->db = db_ret7;
        r->dp = direct_page2;
        r->sp -= 19;
        { const uint16_t sp_call = r->sp; JSR(c, 0x33EE, 0xC14297); GUARD_JSR(c, sp_call, 0x33EE); } /* copy_spell_entity_sprite_record_words */
        r->sp += 19;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all10 = r->a;
        bool carry_ret10 = r->c;
        bool overflow_ret10 = r->v;
        uint8_t value23 = RAM8(0x0000 + sp0 - 0x12);
        uint8_t value24 = RAM8(0x0000 + sp0 - 0x11);
        RAM16_SET(0x0009 + direct_page2, (uint16_t)(RAM16(0x0009 + direct_page2) - 1));
        if (RAM16(0x0009 + direct_page2) != 0) {
            a_hi3 = a_all10 >> 8;
            y3 = (value24 << 8) | value23;
            carry3 = carry_ret10;
            overflow3 = overflow_ret10;
            continue;
        }
        a_hi3 = a_all10 >> 8;
        y3 = (value24 << 8) | value23;
        carry3 = carry_ret10;
        overflow3 = overflow_ret10;
        break;
    }
    uint16_t value25 = RAM16(0x0003 + direct_page2);
    uint16_t value26 = RAM16(0x0005 + direct_page2);
    uint16_t value27 = BUS16(c, 0xDCF806 + value26);
    BUS16_SET(c, (db_ret7 << 0x10) + 0x10 + value25, value27 & 0xFF);
    uint16_t value28 = BUS16(c, 0xDCF807 + value26);
    BUS16_SET(c, (db_ret7 << 0x10) + 0x12 + value25, value28 & 0xFF);
    BUS16_SET(c, (db_ret7 << 0x10) + 0x14 + value25, value28 & 0xFF);
    uint16_t value29 = BUS16(c, 0xDCF80A + value26);
    BUS16_SET(c, (db_ret7 << 0x10) + 0x1E + value25, value29 & 0xFF);
    BUS16_SET(c, (db_ret7 << 0x10) + 0x20 + value25, value29 & 0xFF);
    uint16_t value30 = BUS16(c, 0xDCF808 + value26);
    BUS16_SET(c, (db_ret7 << 0x10) + 0x1A + value25, value30);
    uint16_t value31 = RAM16(0x0001 + direct_page2);
    BUS16_SET(c, (db_ret7 << 0x10) + 0x18 + value25, value31);
    uint16_t value32 = BUS16_RDP(c, (db_ret7 << 0x10) + value25);
    uint16_t value33 = BUS16(c, 0xDCF808 + value26);
    r->a = 0xD104;
    r->x = (uint16_t)(((value31 & 0x0F) << 1) + value32);
    r->y = value33;
    r->c = ((value31 & 0x0F) << 1) + value32 > 0xFFFF;
    r->z = 0;
    r->n = 1;
    r->v = ((((value31 & 0x0F) << 1) ^ (uint16_t)(((value31 & 0x0F) << 1) + value32)) & (value32 ^ (uint16_t)(((value31 & 0x0F) << 1) + value32)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = db_ret7;
    r->dp = direct_page2;
    r->sp -= 17;
    { const uint16_t sp_call = r->sp; JSR(c, 0x343C, 0xC14297); GUARD_JSR(c, sp_call, 0x343C); } /* copy_spell_entity_sprite_record_words */
    r->sp += 17;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value34 = RAM16(0x0003 + direct_page2);
    uint16_t value35 = BUS16_RDP(c, (db_ret7 << 0x10) + value34);
    r->x = value35;
    r->y = value34;
    r->z = value35 == 0;
    r->n = value35 & 0x8000;
    r->sp -= 17;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3444, 0xC141F8); GUARD_JSR(c, sp_call, 0x3444); } /* queue_spell_entity_sprite_slot_write */
    r->sp += 17;
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret8 = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value36 = RAM16(0x0003 + dp_ret7);
    uint16_t value37 = RAM16(0x000B + dp_ret7);
    if (value37 == 0) {
        uint8_t value38 = RAM8(0x0000 + sp0 - 2);
        uint8_t value39 = RAM8(0x0000 + sp0 - 1);
        uint8_t value40 = RAM8(0x0000 + sp0);
        r->x = value36;
        r->y = value37;
        r->mf = value38 & 0x20;
        r->xf = value38 & 0x10;
        r->dp = (value40 << 8) | value39;
        r->i = value38 & 0x04;
        r->d = value38 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    BUS16_SET(c, (db_ret8 << 0x10) + 0x26 + value36, 2);
    uint8_t value41 = RAM8(0x0000 + sp0 - 2);
    uint8_t value42 = RAM8(0x0000 + sp0 - 1);
    uint8_t value43 = RAM8(0x0000 + sp0);
    r->x = value36;
    r->y = value37;
    r->mf = value41 & 0x20;
    r->xf = value41 & 0x10;
    r->dp = (value43 << 8) | value42;
    r->i = value41 & 0x04;
    r->d = value41 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1332C, SOM_RTS, "gen", construct_spell_entity_visual_resource, 0, L_X | L_Y, 19, 1, 0, 302, 135)

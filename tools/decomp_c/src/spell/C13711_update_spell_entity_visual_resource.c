#include "som_c.h"

/* C13711 update_spell_entity_visual_resource   [class C, 89 bytes, 48 instructions]
 * Source: src/rom/update_spell_entity_visual_resource.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void update_spell_entity_visual_resource(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_373c = 0;
    uint16_t x_373c = 0;
    uint16_t y_373c = 0;
    bool carry_373c = 0;
    bool overflow_373c = 0;
    uint16_t direct_page_373c = 0;
    uint8_t data_bank_373c = 0;
    uint8_t a_hi_373c2 = 0;
    uint8_t x_373c2 = 0;
    uint8_t y_373c2 = 0;
    bool carry_373c2 = 0;
    bool overflow_373c2 = 0;
    uint16_t direct_page_373c2 = 0;
    uint8_t data_bank_373c2 = 0;
    uint8_t a_hi_3757 = 0;
    uint16_t x_3757 = 0;
    uint16_t y_3757 = 0;
    bool carry_3757 = 0;
    bool overflow_3757 = 0;
    uint16_t direct_page_3757 = 0;
    uint8_t data_bank_3757 = 0;
    uint8_t a_hi_37572 = 0;
    uint8_t x_37572 = 0;
    uint8_t y_37572 = 0;
    bool carry_37572 = 0;
    bool overflow_37572 = 0;
    uint16_t direct_page_37572 = 0;
    uint8_t data_bank_37572 = 0;
    uint8_t a_hi_37573 = 0;
    uint8_t x_37573 = 0;
    uint8_t y_37573 = 0;
    bool carry_37573 = 0;
    bool overflow_37573 = 0;
    uint16_t direct_page_37573 = 0;
    uint8_t data_bank_37573 = 0;
    uint8_t a_hi_37574 = 0;
    uint16_t x_37574 = 0;
    uint16_t y_37574 = 0;
    bool carry_37574 = 0;
    bool overflow_37574 = 0;
    uint16_t direct_page_37574 = 0;
    uint8_t data_bank_37574 = 0;
    uint8_t a_hi_375f = 0;
    uint16_t x_375f = 0;
    uint16_t y_375f = 0;
    uint16_t direct_page_375f = 0;
    uint8_t data_bank_375f = 0;
    uint8_t a_hi_375f2 = 0;
    uint8_t x_375f2 = 0;
    uint8_t y_375f2 = 0;
    uint16_t direct_page_375f2 = 0;
    uint8_t data_bank_375f2 = 0;
    uint8_t a_hi_375f3 = 0;
    uint8_t x_375f3 = 0;
    uint8_t y_375f3 = 0;
    uint16_t direct_page_375f3 = 0;
    uint8_t data_bank_375f3 = 0;
    uint8_t a_hi_375f4 = 0;
    uint16_t x_375f4 = 0;
    uint16_t y_375f4 = 0;
    uint16_t direct_page_375f4 = 0;
    uint8_t data_bank_375f4 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    RAM16_SET(0x0012 + x, (uint16_t)(RAM16(0x0012 + x) - 1));
    if (RAM16(0x0012 + x) != 0) {
        a_hi_373c = (uint16_t)(sp0 - 5) >> 8;
        x_373c = x;
        y_373c = y;
        carry_373c = carry;
        overflow_373c = overflow;
        direct_page_373c = (uint16_t)(sp0 - 5);
        data_bank_373c = 0x7E;
        goto shared_373C;
    }
    RAM16_SET(0x0012 + x, RAM16(0x0014 + x));
    uint16_t value2 = RAM16(0x0010 + x);
    r->a = (value2 & 0x0F) << 1;
    r->x = (value2 & 0x0F) << 1;
    r->y = x;
    r->c = value2 & 0x0F & 0x8000;
    r->z = (value2 & 0x0F) << 1 == 0;
    r->n = (value2 & 0x0F) << 1 & 0x8000;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp;
    switch ((value2 & 0x0F) << 1) {
    case 0x0000: JSR(c, 0x3739, 0xC136B3); GUARD_JSR(c, sp_call, 0x3739); break; /* spell_entity_resource_noop */
    case 0x0002: JSR(c, 0x3739, 0xC134E1); GUARD_JSR(c, sp_call, 0x3739); break; /* advance_spell_entity_five_frame_tiles */
    case 0x0004: JSR(c, 0x3739, 0xC1356D); GUARD_JSR(c, sp_call, 0x3739); break; /* rotate_spell_entity_palette_words */
    case 0x0006: JSR(c, 0x3739, 0xC13527); GUARD_JSR(c, sp_call, 0x3739); break; /* advance_spell_entity_three_frame_tiles */
    case 0x0008: JSR(c, 0x3739, 0xC136B3); GUARD_JSR(c, sp_call, 0x3739); break; /* spell_entity_resource_noop */
    case 0x000A: JSR(c, 0x3739, 0xC13597); GUARD_JSR(c, sp_call, 0x3739); break; /* cycle_spell_entity_blue_color */
    case 0x000C: JSR(c, 0x3739, 0xC13614); GUARD_JSR(c, sp_call, 0x3739); break; /* increment_spell_entity_all_color_channels */
    case 0x000E: JSR(c, 0x3739, 0xC13690); GUARD_JSR(c, sp_call, 0x3739); break; /* decrement_spell_entity_all_color_channels */
    case 0x0010: JSR(c, 0x3739, 0xC1366D); GUARD_JSR(c, sp_call, 0x3739); break; /* increment_spell_entity_dim_color */
    case 0x0012: JSR(c, 0x3739, 0xC13637); GUARD_JSR(c, sp_call, 0x3739); break; /* advance_spell_entity_color_phase */
    case 0x0014: JSR(c, 0x3739, 0xC135CD); GUARD_JSR(c, sp_call, 0x3739); break; /* increment_spell_entity_two_color_channels */
    case 0x0016: JSR(c, 0x3739, 0xC135F2); GUARD_JSR(c, sp_call, 0x3739); break; /* set_spell_entity_two_color_channels */
    default: JSR(c, 0x3739, 0xC10000 | BUS16(c, 0xC10000 + (uint16_t)(0x36BC + ((value2 & 0x0F) << 1)))); GUARD_JSR(c, sp_call, 0x3739);
    }
    }
    r->sp += 6;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        a_hi_373c2 = a_all >> 8;
        x_373c2 = value3;
        y_373c2 = (uint8_t)y_ret;
        carry_373c2 = carry_ret;
        overflow_373c2 = overflow_ret;
        direct_page_373c2 = dp_ret;
        data_bank_373c2 = db_ret;
        goto shared_373C_1;
    } else {
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        a_hi_373c = a_all >> 8;
        x_373c = value4;
        y_373c = y_ret;
        carry_373c = carry_ret;
        overflow_373c = overflow_ret;
        direct_page_373c = dp_ret;
        data_bank_373c = db_ret;
        goto shared_373C;
    }
    shared_373C:;
    uint16_t value5 = BUS16_RDP(c, (data_bank_373c << 0x10) + 0x1E + x_373c);
    BUS16_RMW_SET(c, (data_bank_373c << 0x10) + 0x1E + x_373c, (uint16_t)(value5 - 1));
    if ((uint16_t)(value5 - 1) != 0) {
        a_hi_3757 = a_hi_373c;
        x_3757 = x_373c;
        y_3757 = y_373c;
        carry_3757 = carry_373c;
        overflow_3757 = overflow_373c;
        direct_page_3757 = direct_page_373c;
        data_bank_3757 = data_bank_373c;
        goto shared_3757;
    }
    uint16_t value6 = BUS16_RDP(c, (data_bank_373c << 0x10) + 0x20 + x_373c);
    BUS16_SET(c, (data_bank_373c << 0x10) + 0x1E + x_373c, value6);
    uint16_t value7 = BUS16_RDP(c, (data_bank_373c << 0x10) + 0x10 + x_373c);
    r->a = (value7 & 0xF0) >> 3;
    r->x = (value7 & 0xF0) >> 3;
    r->y = x_373c;
    r->c = (value7 & 0xF0) >> 2 & 0x01;
    r->z = (value7 & 0xF0) >> 3 == 0;
    r->n = (value7 & 0xF0) >> 3 & 0x8000;
    r->v = overflow_373c;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_373c;
    r->dp = direct_page_373c;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp;
    switch ((value7 & 0xF0) >> 3) {
    case 0x0000: JSR(c, 0x3754, 0xC136B3); GUARD_JSR(c, sp_call, 0x3754); break; /* spell_entity_resource_noop */
    case 0x0002: JSR(c, 0x3754, 0xC13597); GUARD_JSR(c, sp_call, 0x3754); break; /* cycle_spell_entity_blue_color */
    case 0x0004: JSR(c, 0x3754, 0xC13614); GUARD_JSR(c, sp_call, 0x3754); break; /* increment_spell_entity_all_color_channels */
    case 0x0006: JSR(c, 0x3754, 0xC13690); GUARD_JSR(c, sp_call, 0x3754); break; /* decrement_spell_entity_all_color_channels */
    case 0x0008: JSR(c, 0x3754, 0xC1366D); GUARD_JSR(c, sp_call, 0x3754); break; /* increment_spell_entity_dim_color */
    case 0x000A: JSR(c, 0x3754, 0xC13637); GUARD_JSR(c, sp_call, 0x3754); break; /* advance_spell_entity_color_phase */
    case 0x000C: JSR(c, 0x3754, 0xC135CD); GUARD_JSR(c, sp_call, 0x3754); break; /* increment_spell_entity_two_color_channels */
    case 0x000E: JSR(c, 0x3754, 0xC135F2); GUARD_JSR(c, sp_call, 0x3754); break; /* set_spell_entity_two_color_channels */
    default: JSR(c, 0x3754, 0xC10000 | BUS16(c, 0xC10000 + (uint16_t)(0x36C4 + ((value7 & 0xF0) >> 3)))); GUARD_JSR(c, sp_call, 0x3754);
    }
    }
    r->sp += 6;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (x_ret3) {
        uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        if (m_ret) {
            a_hi_37572 = a_all2 >> 8;
            x_37572 = value8;
            y_37572 = (uint8_t)y_ret2;
            carry_37572 = carry_ret2;
            overflow_37572 = overflow_ret2;
            direct_page_37572 = dp_ret2;
            data_bank_37572 = db_ret2;
            goto shared_3757_1;
        } else {
            a_hi_37573 = a_all2 >> 8;
            x_37573 = value8;
            y_37573 = (uint8_t)y_ret2;
            carry_37573 = carry_ret2;
            overflow_37573 = overflow_ret2;
            direct_page_37573 = dp_ret2;
            data_bank_37573 = db_ret2;
            goto shared_3757_2;
        }
    } else {
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        if (m_ret) {
            a_hi_37574 = a_all2 >> 8;
            x_37574 = value9;
            y_37574 = y_ret2;
            carry_37574 = carry_ret2;
            overflow_37574 = overflow_ret2;
            direct_page_37574 = dp_ret2;
            data_bank_37574 = db_ret2;
            goto shared_3757_3;
        } else {
            a_hi_3757 = a_all2 >> 8;
            x_3757 = value9;
            y_3757 = y_ret2;
            carry_3757 = carry_ret2;
            overflow_3757 = overflow_ret2;
            direct_page_3757 = dp_ret2;
            data_bank_3757 = db_ret2;
            goto shared_3757;
        }
    }
    shared_373C_1:;
    uint16_t value10 = BUS16_RDP(c, (data_bank_373c2 << 0x10) + 0x1E + x_373c2);
    BUS16_RMW_SET(c, (data_bank_373c2 << 0x10) + 0x1E + x_373c2, (uint16_t)(value10 - 1));
    if ((uint16_t)(value10 - 1) != 0) {
        a_hi_37573 = a_hi_373c2;
        x_37573 = x_373c2;
        y_37573 = y_373c2;
        carry_37573 = carry_373c2;
        overflow_37573 = overflow_373c2;
        direct_page_37573 = direct_page_373c2;
        data_bank_37573 = data_bank_373c2;
        goto shared_3757_2;
    }
    uint16_t value11 = BUS16_RDP(c, (data_bank_373c2 << 0x10) + 0x20 + x_373c2);
    BUS16_SET(c, (data_bank_373c2 << 0x10) + 0x1E + x_373c2, value11);
    uint16_t value12 = BUS16_RDP(c, (data_bank_373c2 << 0x10) + 0x10 + x_373c2);
    r->a = (value12 & 0xF0) >> 3;
    r->x = (value12 & 0xF0) >> 3;
    r->y = x_373c2;
    r->c = (value12 & 0xF0) >> 2 & 0x01;
    r->z = (value12 & 0xF0) >> 3 == 0;
    r->n = (value12 & 0xF0) >> 3 & 0x80;
    r->v = overflow_373c2;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_373c2;
    r->dp = direct_page_373c2;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp;
    switch ((value12 & 0xF0) >> 3) {
    case 0x0000: JSR(c, 0x3754, 0xC136B3); GUARD_JSR(c, sp_call, 0x3754); break; /* spell_entity_resource_noop */
    case 0x0002: JSR(c, 0x3754, 0xC13597); GUARD_JSR(c, sp_call, 0x3754); break; /* cycle_spell_entity_blue_color */
    case 0x0004: JSR(c, 0x3754, 0xC13614); GUARD_JSR(c, sp_call, 0x3754); break; /* increment_spell_entity_all_color_channels */
    case 0x0006: JSR(c, 0x3754, 0xC13690); GUARD_JSR(c, sp_call, 0x3754); break; /* decrement_spell_entity_all_color_channels */
    case 0x0008: JSR(c, 0x3754, 0xC1366D); GUARD_JSR(c, sp_call, 0x3754); break; /* increment_spell_entity_dim_color */
    case 0x000A: JSR(c, 0x3754, 0xC13637); GUARD_JSR(c, sp_call, 0x3754); break; /* advance_spell_entity_color_phase */
    case 0x000C: JSR(c, 0x3754, 0xC135CD); GUARD_JSR(c, sp_call, 0x3754); break; /* increment_spell_entity_two_color_channels */
    case 0x000E: JSR(c, 0x3754, 0xC135F2); GUARD_JSR(c, sp_call, 0x3754); break; /* set_spell_entity_two_color_channels */
    default: JSR(c, 0x3754, 0xC10000 | BUS16(c, 0xC10000 + (uint16_t)(0x36C4 + ((value12 & 0xF0) >> 3)))); GUARD_JSR(c, sp_call, 0x3754);
    }
    }
    r->sp += 6;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret5 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    if (x_ret5) {
        uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
        if (m_ret2) {
            a_hi_37572 = a_all3 >> 8;
            x_37572 = value13;
            y_37572 = (uint8_t)y_ret3;
            carry_37572 = carry_ret3;
            overflow_37572 = overflow_ret3;
            direct_page_37572 = dp_ret3;
            data_bank_37572 = db_ret3;
            goto shared_3757_1;
        } else {
            a_hi_37573 = a_all3 >> 8;
            x_37573 = value13;
            y_37573 = (uint8_t)y_ret3;
            carry_37573 = carry_ret3;
            overflow_37573 = overflow_ret3;
            direct_page_37573 = dp_ret3;
            data_bank_37573 = db_ret3;
            goto shared_3757_2;
        }
    } else {
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        if (m_ret2) {
            a_hi_37574 = a_all3 >> 8;
            x_37574 = value14;
            y_37574 = y_ret3;
            carry_37574 = carry_ret3;
            overflow_37574 = overflow_ret3;
            direct_page_37574 = dp_ret3;
            data_bank_37574 = db_ret3;
            goto shared_3757_3;
        } else {
            a_hi_3757 = a_all3 >> 8;
            x_3757 = value14;
            y_3757 = y_ret3;
            carry_3757 = carry_ret3;
            overflow_3757 = overflow_ret3;
            direct_page_3757 = dp_ret3;
            data_bank_3757 = db_ret3;
            goto shared_3757;
        }
    }
    shared_3757:;
    uint16_t value15 = BUS16_RDP(c, (data_bank_3757 << 0x10) + 0x26 + x_3757);
    BUS16_RMW_SET(c, (data_bank_3757 << 0x10) + 0x26 + x_3757, (uint16_t)(value15 - 1));
    if ((uint16_t)(value15 - 1) != 0) {
        a_hi_375f = a_hi_3757;
        x_375f = x_3757;
        y_375f = y_3757;
        direct_page_375f = direct_page_3757;
        data_bank_375f = data_bank_3757;
        goto shared_375F;
    }
    r->x = x_3757;
    r->y = y_3757;
    r->c = carry_3757;
    r->z = (uint16_t)(value15 - 1) == 0;
    r->n = (uint16_t)(value15 - 1) & 0x8000;
    r->v = overflow_3757;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_3757;
    r->dp = direct_page_3757;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x375E, 0xC136D4); GUARD_JSR(c, sp_call, 0x375E); } /* rotate_spell_entity_extra_sprite_words */
    r->sp += 6;
    uint8_t db_ret4 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret7 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret8 = r->x;
    uint16_t y_ret4 = r->y;
    if (x_ret7) {
        a_hi_375f2 = a_all4 >> 8;
        x_375f2 = (uint8_t)x_ret8;
        y_375f2 = (uint8_t)y_ret4;
        direct_page_375f2 = direct_page_3757;
        data_bank_375f2 = db_ret4;
        goto shared_375F_1;
    } else {
        a_hi_375f = a_all4 >> 8;
        x_375f = x_ret8;
        y_375f = y_ret4;
        direct_page_375f = direct_page_3757;
        data_bank_375f = db_ret4;
        goto shared_375F;
    }
    shared_3757_1:;
    uint8_t value16 = BUS8_RDP(c, (data_bank_37572 << 0x10) + 0x26 + x_37572);
    BUS8_SET(c, (data_bank_37572 << 0x10) + 0x26 + x_37572, (uint8_t)(value16 - 1));
    if ((uint8_t)(value16 - 1) != 0) {
        a_hi_375f3 = a_hi_37572;
        x_375f3 = x_37572;
        y_375f3 = y_37572;
        direct_page_375f3 = direct_page_37572;
        data_bank_375f3 = data_bank_37572;
        goto shared_375F_2;
    }
    r->x = x_37572;
    r->y = y_37572;
    r->c = carry_37572;
    r->z = (uint8_t)(value16 - 1) == 0;
    r->n = (uint8_t)(value16 - 1) & 0x80;
    r->v = overflow_37572;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_37572;
    r->dp = direct_page_37572;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x375E, 0xC136D4); GUARD_JSR(c, sp_call, 0x375E); } /* rotate_spell_entity_extra_sprite_words */
    r->sp += 6;
    uint8_t db_ret5 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret9 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret10 = r->x;
    uint16_t y_ret5 = r->y;
    if (x_ret9) {
        a_hi_375f2 = a_all5 >> 8;
        x_375f2 = (uint8_t)x_ret10;
        y_375f2 = (uint8_t)y_ret5;
        direct_page_375f2 = direct_page_37572;
        data_bank_375f2 = db_ret5;
        goto shared_375F_1;
    } else {
        a_hi_375f = a_all5 >> 8;
        x_375f = x_ret10;
        y_375f = y_ret5;
        direct_page_375f = direct_page_37572;
        data_bank_375f = db_ret5;
        goto shared_375F;
    }
    shared_3757_2:;
    uint16_t value17 = BUS16_RDP(c, (data_bank_37573 << 0x10) + 0x26 + x_37573);
    BUS16_RMW_SET(c, (data_bank_37573 << 0x10) + 0x26 + x_37573, (uint16_t)(value17 - 1));
    if ((uint16_t)(value17 - 1) != 0) {
        a_hi_375f2 = a_hi_37573;
        x_375f2 = x_37573;
        y_375f2 = y_37573;
        direct_page_375f2 = direct_page_37573;
        data_bank_375f2 = data_bank_37573;
        goto shared_375F_1;
    }
    r->x = x_37573;
    r->y = y_37573;
    r->c = carry_37573;
    r->z = (uint16_t)(value17 - 1) == 0;
    r->n = (uint16_t)(value17 - 1) & 0x8000;
    r->v = overflow_37573;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_37573;
    r->dp = direct_page_37573;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x375E, 0xC136D4); GUARD_JSR(c, sp_call, 0x375E); } /* rotate_spell_entity_extra_sprite_words */
    r->sp += 6;
    uint8_t db_ret6 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret11 = r->xf;
    uint16_t a_all6 = r->a;
    uint16_t x_ret12 = r->x;
    uint16_t y_ret6 = r->y;
    if (x_ret11) {
        a_hi_375f2 = a_all6 >> 8;
        x_375f2 = (uint8_t)x_ret12;
        y_375f2 = (uint8_t)y_ret6;
        direct_page_375f2 = direct_page_37573;
        data_bank_375f2 = db_ret6;
        goto shared_375F_1;
    } else {
        a_hi_375f = a_all6 >> 8;
        x_375f = x_ret12;
        y_375f = y_ret6;
        direct_page_375f = direct_page_37573;
        data_bank_375f = db_ret6;
        goto shared_375F;
    }
    shared_3757_3:;
    uint8_t value18 = BUS8_RDP(c, (data_bank_37574 << 0x10) + 0x26 + x_37574);
    BUS8_SET(c, (data_bank_37574 << 0x10) + 0x26 + x_37574, (uint8_t)(value18 - 1));
    if ((uint8_t)(value18 - 1) != 0) {
        a_hi_375f4 = a_hi_37574;
        x_375f4 = x_37574;
        y_375f4 = y_37574;
        direct_page_375f4 = direct_page_37574;
        data_bank_375f4 = data_bank_37574;
        goto shared_375F_3;
    }
    r->x = x_37574;
    r->y = y_37574;
    r->c = carry_37574;
    r->z = (uint8_t)(value18 - 1) == 0;
    r->n = (uint8_t)(value18 - 1) & 0x80;
    r->v = overflow_37574;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_37574;
    r->dp = direct_page_37574;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x375E, 0xC136D4); GUARD_JSR(c, sp_call, 0x375E); } /* rotate_spell_entity_extra_sprite_words */
    r->sp += 6;
    uint8_t db_ret7 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret13 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t x_ret14 = r->x;
    uint16_t y_ret7 = r->y;
    if (x_ret13) {
        a_hi_375f2 = a_all7 >> 8;
        x_375f2 = (uint8_t)x_ret14;
        y_375f2 = (uint8_t)y_ret7;
        direct_page_375f2 = direct_page_37574;
        data_bank_375f2 = db_ret7;
        goto shared_375F_1;
    } else {
        a_hi_375f = a_all7 >> 8;
        x_375f = x_ret14;
        y_375f = y_ret7;
        direct_page_375f = direct_page_37574;
        data_bank_375f = db_ret7;
        goto shared_375F;
    }
    shared_375F:;
    uint8_t value19 = RAM8(0x0000 + sp0 - 5);
    uint8_t value21 = RAM8(0x0000 + sp0 - 3);
    uint8_t value22 = RAM8(0x0000 + sp0 - 2);
    uint8_t value23 = RAM8(0x0000 + sp0 - 1);
    uint8_t value24 = RAM8(0x0000 + sp0);
    r->a = value21;
    r->x = x_375f;
    r->y = y_375f;
    r->c = value22 & 0x01;
    r->z = ((value24 << 8) | value23) == 0;
    r->n = ((value24 << 8) | value23) & 0x8000;
    r->v = value22 & 0x40;
    r->mf = value22 & 0x20;
    r->xf = value22 & 0x10;
    r->db = value19;
    r->dp = (value24 << 8) | value23;
    r->i = value22 & 0x04;
    r->d = value22 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_375F_1:;
    uint8_t value25 = RAM8(0x0000 + sp0 - 5);
    uint8_t value27 = RAM8(0x0000 + sp0 - 3);
    uint8_t value28 = RAM8(0x0000 + sp0 - 2);
    uint8_t value29 = RAM8(0x0000 + sp0 - 1);
    uint8_t value30 = RAM8(0x0000 + sp0);
    r->a = value27;
    r->x = x_375f2;
    r->y = y_375f2;
    r->c = value28 & 0x01;
    r->z = ((value30 << 8) | value29) == 0;
    r->n = ((value30 << 8) | value29) & 0x8000;
    r->v = value28 & 0x40;
    r->mf = value28 & 0x20;
    r->xf = value28 & 0x10;
    r->db = value25;
    r->dp = (value30 << 8) | value29;
    r->i = value28 & 0x04;
    r->d = value28 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_375F_2:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_375F_3:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0xC13711, SOM_RTS, "gen", update_spell_entity_visual_resource, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 89, 48)

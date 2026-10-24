#include "som_c.h"

/* C18C96 cancel_cast_and_deliver_pending_target_hits   [class B, 115 bytes, 52 instructions]
 * Source: src/rom/cancel_cast_and_deliver_pending_target_hits.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void cancel_cast_and_deliver_pending_target_hits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t a_8cb9 = 0;
    uint8_t a_hi_8cb9 = 0;
    uint16_t x_8cb9 = 0;
    bool carry_8cb9 = 0;
    bool overflow_8cb9 = 0;
    uint16_t direct_page_8cb9 = 0;
    uint8_t data_bank_8cb9 = 0;
    uint8_t a_8ccb = 0;
    uint8_t a_hi_8ccb = 0;
    uint16_t x_8ccb = 0;
    bool carry_8ccb = 0;
    bool overflow_8ccb = 0;
    uint16_t direct_page_8ccb = 0;
    uint8_t data_bank_8ccb = 0;
    uint8_t a_8ccb2 = 0;
    uint8_t a_hi_8ccb2 = 0;
    uint16_t x_8ccb2 = 0;
    bool carry_8ccb2 = 0;
    bool overflow_8ccb2 = 0;
    uint16_t direct_page_8ccb2 = 0;
    uint8_t data_bank_8ccb2 = 0;
    uint8_t a_hi_8ced = 0;
    uint16_t x_8ced = 0;
    uint16_t y_8ced = 0;
    bool carry_8ced = 0;
    bool overflow_8ced = 0;
    uint16_t direct_page_8ced = 0;
    uint8_t data_bank_8ced = 0;
    uint8_t a_8cdc = 0;
    uint8_t a_hi_8cdc = 0;
    uint16_t x_8cdc = 0;
    bool carry_8cdc = 0;
    bool overflow_8cdc = 0;
    uint16_t direct_page_8cdc = 0;
    uint8_t data_bank_8cdc = 0;
    uint8_t a_8cdc2 = 0;
    uint8_t a_hi_8cdc2 = 0;
    uint16_t x_8cdc2 = 0;
    bool carry_8cdc2 = 0;
    bool overflow_8cdc2 = 0;
    uint16_t direct_page_8cdc2 = 0;
    uint8_t data_bank_8cdc2 = 0;
    uint8_t a_hi_8ced2 = 0;
    uint16_t x_8ced2 = 0;
    uint16_t y_8ced2 = 0;
    bool carry_8ced2 = 0;
    bool overflow_8ced2 = 0;
    uint16_t direct_page_8ced2 = 0;
    uint8_t data_bank_8ced2 = 0;
    uint8_t a_hi_8d08 = 0;
    uint16_t x_8d08 = 0;
    uint16_t y_8d08 = 0;
    bool carry_8d08 = 0;
    bool overflow_8d08 = 0;
    uint16_t direct_page_8d08 = 0;
    uint8_t data_bank_8d08 = 0;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    uint8_t value2 = RAM8(0xE110 + value);
    if (value2 < 8) {
        a_8cb9 = value2;
        a_hi_8cb9 = a_hi;
        x_8cb9 = value;
        carry_8cb9 = value2 >= 8;
        overflow_8cb9 = overflow;
        direct_page_8cb9 = dp;
        data_bank_8cb9 = 0x7E;
        goto shared_8CB9;
    }
    RAM8(0x0000 + sp0) = value2;
    RAM8(0x0000 + sp0 - 1) = value >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)value;
    r->a = (a_hi << 8) | value2;
    r->x = value;
    r->c = value2 >= 8;
    r->z = value2 == 8;
    r->n = (uint8_t)(value2 - 8) & 0x80;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8CA6, 0x00E328); GUARD_JSL(c, sp_call, 0x8CA6); } /* cast_sprite_emission_long */
    r->sp += 3;
    uint16_t dp_ret = r->dp;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    BUS16_SET(c, (uint16_t)(dp_ret + 0x14), (value4 << 8) | value3);
    r->a = (a_all >> 8 << 8) | value5;
    r->x = (value4 << 8) | value3;
    r->z = value5 == 0;
    r->n = value5 & 0x80;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8CB0, 0xC10038); GUARD_JSL(c, sp_call, 0x8CB0); } /* execute_native_spell_entity_scheduler_long */
    { const uint16_t sp_call = r->sp; JSL(c, 0x8CB4, 0x00E351); GUARD_JSL(c, sp_call, 0x8CB4); } /* initialize_sprite_workspace_long */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    uint16_t a_all3 = r->a;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x14));
    a_8cb9 = (uint8_t)a_all3;
    a_hi_8cb9 = a_all3 >> 8;
    x_8cb9 = value6;
    carry_8cb9 = carry_ret3;
    overflow_8cb9 = overflow_ret3;
    direct_page_8cb9 = dp_ret3;
    data_bank_8cb9 = db_ret3;
    shared_8CB9:;
    BUS8_SET(c, (data_bank_8cb9 << 0x10) + 0xE060 + x_8cb9, 0);
    uint16_t value7 = BUS16_RDP(c, (data_bank_8cb9 << 0x10) + 0xE116 + x_8cb9);
    RAM8(0x0000 + sp0) = x_8cb9 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_8cb9;
    r->a = (a_hi_8cb9 << 8) | a_8cb9;
    r->x = x_8cb9;
    r->y = value7;
    r->c = carry_8cb9;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->v = overflow_8cb9;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8cb9;
    r->dp = direct_page_8cb9;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CC2, 0xC18D12); GUARD_JSR(c, sp_call, 0x8CC2); } /* deliver_complete_cast_hit_to_target */
    r->sp += 2;
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool m_ret2 = r->mf;
    uint16_t a_all4 = r->a;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    if (!carry_ret4) {
        if (m_ret2) {
            a_8ccb = (uint8_t)a_all4;
            a_hi_8ccb = a_all4 >> 8;
            x_8ccb = (value9 << 8) | value8;
            carry_8ccb = carry_ret4;
            overflow_8ccb = overflow_ret4;
            direct_page_8ccb = dp_ret4;
            data_bank_8ccb = db_ret4;
            goto shared_8CCB;
        } else {
            a_8ccb2 = (uint8_t)a_all4;
            a_hi_8ccb2 = a_all4 >> 8;
            x_8ccb2 = (value9 << 8) | value8;
            carry_8ccb2 = carry_ret4;
            overflow_8ccb2 = overflow_ret4;
            direct_page_8ccb2 = dp_ret4;
            data_bank_8ccb2 = db_ret4;
            goto shared_8CCB_1;
        }
    }
    r->x = (value9 << 8) | value8;
    r->z = ((value9 << 8) | value8) == 0;
    r->n = ((value9 << 8) | value8) & 0x8000;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CCA, 0xC18D09); GUARD_JSR(c, sp_call, 0x8CCA); } /* deliver_reflected_cast_hit_preserving_actor */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    bool m_ret3 = r->mf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret7 = r->x;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (m_ret3) {
        a_8ccb = (uint8_t)a_all5;
        a_hi_8ccb = a_all5 >> 8;
        x_8ccb = x_ret7;
        carry_8ccb = carry_ret5;
        overflow_8ccb = overflow_ret5;
        direct_page_8ccb = dp_ret5;
        data_bank_8ccb = db_ret5;
        goto shared_8CCB;
    } else {
        a_8ccb2 = (uint8_t)a_all5;
        a_hi_8ccb2 = a_all5 >> 8;
        x_8ccb2 = x_ret7;
        carry_8ccb2 = carry_ret5;
        overflow_8ccb2 = overflow_ret5;
        direct_page_8ccb2 = dp_ret5;
        data_bank_8ccb2 = db_ret5;
        goto shared_8CCB_1;
    }
    shared_8CCB:;
    uint16_t value10 = BUS16_RDP(c, (data_bank_8ccb << 0x10) + 0xE126 + x_8ccb);
    if (value10 & 0x8000) {
        a_hi_8ced = a_hi_8ccb;
        x_8ced = x_8ccb;
        y_8ced = value10;
        carry_8ced = carry_8ccb;
        overflow_8ced = overflow_8ccb;
        direct_page_8ced = direct_page_8ccb;
        data_bank_8ced = data_bank_8ccb;
        goto shared_8CED;
    }
    RAM8(0x0000 + sp0) = x_8ccb >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_8ccb;
    r->a = (a_hi_8ccb << 8) | a_8ccb;
    r->x = x_8ccb;
    r->y = value10;
    r->c = carry_8ccb;
    r->z = value10 == 0;
    r->n = value10 & 0x8000;
    r->v = overflow_8ccb;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8ccb;
    r->dp = direct_page_8ccb;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CD3, 0xC18D12); GUARD_JSR(c, sp_call, 0x8CD3); } /* deliver_complete_cast_hit_to_target */
    r->sp += 2;
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool m_ret4 = r->mf;
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    bool overflow_ret6 = r->v;
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    if (!carry_ret6) {
        if (m_ret4) {
            a_8cdc = (uint8_t)a_all6;
            a_hi_8cdc = a_all6 >> 8;
            x_8cdc = (value12 << 8) | value11;
            carry_8cdc = carry_ret6;
            overflow_8cdc = overflow_ret6;
            direct_page_8cdc = dp_ret6;
            data_bank_8cdc = db_ret6;
            goto shared_8CDC;
        } else {
            a_8cdc2 = (uint8_t)a_all6;
            a_hi_8cdc2 = a_all6 >> 8;
            x_8cdc2 = (value12 << 8) | value11;
            carry_8cdc2 = carry_ret6;
            overflow_8cdc2 = overflow_ret6;
            direct_page_8cdc2 = dp_ret6;
            data_bank_8cdc2 = db_ret6;
            goto shared_8CDC_1;
        }
    }
    r->x = (value12 << 8) | value11;
    r->z = ((value12 << 8) | value11) == 0;
    r->n = ((value12 << 8) | value11) & 0x8000;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CDB, 0xC18D09); GUARD_JSR(c, sp_call, 0x8CDB); } /* deliver_reflected_cast_hit_preserving_actor */
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool m_ret5 = r->mf;
    uint16_t a_all7 = r->a;
    uint16_t x_ret10 = r->x;
    bool carry_ret7 = r->c;
    bool overflow_ret7 = r->v;
    if (m_ret5) {
        a_8cdc = (uint8_t)a_all7;
        a_hi_8cdc = a_all7 >> 8;
        x_8cdc = x_ret10;
        carry_8cdc = carry_ret7;
        overflow_8cdc = overflow_ret7;
        direct_page_8cdc = dp_ret7;
        data_bank_8cdc = db_ret7;
        goto shared_8CDC;
    } else {
        a_8cdc2 = (uint8_t)a_all7;
        a_hi_8cdc2 = a_all7 >> 8;
        x_8cdc2 = x_ret10;
        carry_8cdc2 = carry_ret7;
        overflow_8cdc2 = overflow_ret7;
        direct_page_8cdc2 = dp_ret7;
        data_bank_8cdc2 = db_ret7;
        goto shared_8CDC_1;
    }
    shared_8CCB_1:;
    uint16_t value13 = BUS16_RDP(c, (data_bank_8ccb2 << 0x10) + 0xE126 + x_8ccb2);
    if (value13 & 0x8000) {
        a_hi_8ced2 = a_hi_8ccb2;
        x_8ced2 = x_8ccb2;
        y_8ced2 = value13;
        carry_8ced2 = carry_8ccb2;
        overflow_8ced2 = overflow_8ccb2;
        direct_page_8ced2 = direct_page_8ccb2;
        data_bank_8ced2 = data_bank_8ccb2;
        goto shared_8CED_1;
    }
    RAM8(0x0000 + sp0) = x_8ccb2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_8ccb2;
    r->a = (a_hi_8ccb2 << 8) | a_8ccb2;
    r->x = x_8ccb2;
    r->y = value13;
    r->c = carry_8ccb2;
    r->z = value13 == 0;
    r->n = value13 & 0x8000;
    r->v = overflow_8ccb2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_8ccb2;
    r->dp = direct_page_8ccb2;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CD3, 0xC18D12); GUARD_JSR(c, sp_call, 0x8CD3); } /* deliver_complete_cast_hit_to_target */
    r->sp += 2;
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    bool m_ret6 = r->mf;
    uint16_t a_all8 = r->a;
    bool carry_ret8 = r->c;
    bool overflow_ret8 = r->v;
    uint8_t value14 = RAM8(0x0000 + sp0 - 1);
    uint8_t value15 = RAM8(0x0000 + sp0);
    if (!carry_ret8) {
        if (m_ret6) {
            a_8cdc = (uint8_t)a_all8;
            a_hi_8cdc = a_all8 >> 8;
            x_8cdc = (value15 << 8) | value14;
            carry_8cdc = carry_ret8;
            overflow_8cdc = overflow_ret8;
            direct_page_8cdc = dp_ret8;
            data_bank_8cdc = db_ret8;
            goto shared_8CDC;
        } else {
            a_8cdc2 = (uint8_t)a_all8;
            a_hi_8cdc2 = a_all8 >> 8;
            x_8cdc2 = (value15 << 8) | value14;
            carry_8cdc2 = carry_ret8;
            overflow_8cdc2 = overflow_ret8;
            direct_page_8cdc2 = dp_ret8;
            data_bank_8cdc2 = db_ret8;
            goto shared_8CDC_1;
        }
    }
    r->x = (value15 << 8) | value14;
    r->z = ((value15 << 8) | value14) == 0;
    r->n = ((value15 << 8) | value14) & 0x8000;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CDB, 0xC18D09); GUARD_JSR(c, sp_call, 0x8CDB); } /* deliver_reflected_cast_hit_preserving_actor */
    uint16_t dp_ret9 = r->dp;
    uint8_t db_ret9 = r->db;
    bool m_ret7 = r->mf;
    uint16_t a_all9 = r->a;
    uint16_t x_ret13 = r->x;
    bool carry_ret9 = r->c;
    bool overflow_ret9 = r->v;
    if (m_ret7) {
        a_8cdc = (uint8_t)a_all9;
        a_hi_8cdc = a_all9 >> 8;
        x_8cdc = x_ret13;
        carry_8cdc = carry_ret9;
        overflow_8cdc = overflow_ret9;
        direct_page_8cdc = dp_ret9;
        data_bank_8cdc = db_ret9;
        goto shared_8CDC;
    } else {
        a_8cdc2 = (uint8_t)a_all9;
        a_hi_8cdc2 = a_all9 >> 8;
        x_8cdc2 = x_ret13;
        carry_8cdc2 = carry_ret9;
        overflow_8cdc2 = overflow_ret9;
        direct_page_8cdc2 = dp_ret9;
        data_bank_8cdc2 = db_ret9;
        goto shared_8CDC_1;
    }
    shared_8CED:;
    uint8_t value16 = BUS8_RDP(c, (data_bank_8ced << 0x10) + 0xE108 + x_8ced);
    if (!(value16 & 0x80)) {
        if (x_8ced >= 0x0600) {
            a_hi_8d08 = a_hi_8ced;
            x_8d08 = x_8ced;
            y_8d08 = y_8ced;
            carry_8d08 = x_8ced >= 0x0600;
            overflow_8d08 = overflow_8ced;
            direct_page_8d08 = direct_page_8ced;
            data_bank_8d08 = data_bank_8ced;
            goto shared_8D08;
        }
        uint8_t value17 = BUS8_RDP(c, (data_bank_8ced << 0x10) + 0xE060 + x_8ced);
        if (value17 != 0) {
            a_hi_8d08 = a_hi_8ced;
            x_8d08 = x_8ced;
            y_8d08 = y_8ced;
            carry_8d08 = x_8ced >= 0x0600;
            overflow_8d08 = overflow_8ced;
            direct_page_8d08 = direct_page_8ced;
            data_bank_8d08 = data_bank_8ced;
            goto shared_8D08;
        }
        BUS8_SET(c, (data_bank_8ced << 0x10) + 0xE104 + x_8ced, 0);
        r->a = (a_hi_8ced << 8) | value17;
        r->x = x_8ced;
        r->y = y_8ced;
        r->c = x_8ced >= 0x0600;
        r->z = value17 == 0;
        r->n = value17 & 0x80;
        r->v = overflow_8ced;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_8ced;
        r->dp = direct_page_8ced;
        TAIL_CALL(c, 0xC18DAB, SOM_RTS); /* restore_actor_weapon_after_cast */
    }
    r->a = (a_hi_8ced << 8) | value16;
    r->x = x_8ced;
    r->y = x_8ced;
    r->c = carry_8ced;
    r->z = x_8ced == 0;
    r->n = x_8ced & 0x8000;
    r->v = overflow_8ced;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8ced;
    r->dp = direct_page_8ced;
    TAIL_CALL(c, 0xC187C2, SOM_RTS); /* transfer_cast_presentation_to_target */
    shared_8CDC:;
    uint16_t value18 = BUS16_RDP(c, (data_bank_8cdc << 0x10) + 0xE136 + x_8cdc);
    if (value18 & 0x8000) {
        a_hi_8ced = a_hi_8cdc;
        x_8ced = x_8cdc;
        y_8ced = value18;
        carry_8ced = carry_8cdc;
        overflow_8ced = overflow_8cdc;
        direct_page_8ced = direct_page_8cdc;
        data_bank_8ced = data_bank_8cdc;
        goto shared_8CED;
    }
    RAM8(0x0000 + sp0) = x_8cdc >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_8cdc;
    r->a = (a_hi_8cdc << 8) | a_8cdc;
    r->x = x_8cdc;
    r->y = value18;
    r->c = carry_8cdc;
    r->z = value18 == 0;
    r->n = value18 & 0x8000;
    r->v = overflow_8cdc;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8cdc;
    r->dp = direct_page_8cdc;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CE4, 0xC18D12); GUARD_JSR(c, sp_call, 0x8CE4); } /* deliver_complete_cast_hit_to_target */
    r->sp += 2;
    uint16_t dp_ret10 = r->dp;
    uint8_t db_ret10 = r->db;
    bool m_ret8 = r->mf;
    uint16_t a_all10 = r->a;
    uint16_t y_ret10 = r->y;
    bool carry_ret10 = r->c;
    bool overflow_ret10 = r->v;
    uint8_t value19 = RAM8(0x0000 + sp0 - 1);
    uint8_t value20 = RAM8(0x0000 + sp0);
    if (!carry_ret10) {
        if (m_ret8) {
            a_hi_8ced = a_all10 >> 8;
            x_8ced = (value20 << 8) | value19;
            y_8ced = y_ret10;
            carry_8ced = carry_ret10;
            overflow_8ced = overflow_ret10;
            direct_page_8ced = dp_ret10;
            data_bank_8ced = db_ret10;
            goto shared_8CED;
        } else {
            a_hi_8ced2 = a_all10 >> 8;
            x_8ced2 = (value20 << 8) | value19;
            y_8ced2 = y_ret10;
            carry_8ced2 = carry_ret10;
            overflow_8ced2 = overflow_ret10;
            direct_page_8ced2 = dp_ret10;
            data_bank_8ced2 = db_ret10;
            goto shared_8CED_1;
        }
    }
    r->x = (value20 << 8) | value19;
    r->z = ((value20 << 8) | value19) == 0;
    r->n = ((value20 << 8) | value19) & 0x8000;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CEC, 0xC18D09); GUARD_JSR(c, sp_call, 0x8CEC); } /* deliver_reflected_cast_hit_preserving_actor */
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret11 = r->db;
    bool m_ret9 = r->mf;
    uint16_t a_all11 = r->a;
    uint16_t x_ret16 = r->x;
    uint16_t y_ret11 = r->y;
    bool carry_ret11 = r->c;
    bool overflow_ret11 = r->v;
    if (m_ret9) {
        a_hi_8ced = a_all11 >> 8;
        x_8ced = x_ret16;
        y_8ced = y_ret11;
        carry_8ced = carry_ret11;
        overflow_8ced = overflow_ret11;
        direct_page_8ced = dp_ret11;
        data_bank_8ced = db_ret11;
        goto shared_8CED;
    } else {
        a_hi_8ced2 = a_all11 >> 8;
        x_8ced2 = x_ret16;
        y_8ced2 = y_ret11;
        carry_8ced2 = carry_ret11;
        overflow_8ced2 = overflow_ret11;
        direct_page_8ced2 = dp_ret11;
        data_bank_8ced2 = db_ret11;
        goto shared_8CED_1;
    }
    shared_8CDC_1:;
    uint16_t value21 = BUS16_RDP(c, (data_bank_8cdc2 << 0x10) + 0xE136 + x_8cdc2);
    if (value21 & 0x8000) {
        a_hi_8ced2 = a_hi_8cdc2;
        x_8ced2 = x_8cdc2;
        y_8ced2 = value21;
        carry_8ced2 = carry_8cdc2;
        overflow_8ced2 = overflow_8cdc2;
        direct_page_8ced2 = direct_page_8cdc2;
        data_bank_8ced2 = data_bank_8cdc2;
        goto shared_8CED_1;
    }
    RAM8(0x0000 + sp0) = x_8cdc2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_8cdc2;
    r->a = (a_hi_8cdc2 << 8) | a_8cdc2;
    r->x = x_8cdc2;
    r->y = value21;
    r->c = carry_8cdc2;
    r->z = value21 == 0;
    r->n = value21 & 0x8000;
    r->v = overflow_8cdc2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_8cdc2;
    r->dp = direct_page_8cdc2;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CE4, 0xC18D12); GUARD_JSR(c, sp_call, 0x8CE4); } /* deliver_complete_cast_hit_to_target */
    r->sp += 2;
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    bool m_ret10 = r->mf;
    uint16_t a_all12 = r->a;
    uint16_t y_ret12 = r->y;
    bool carry_ret12 = r->c;
    bool overflow_ret12 = r->v;
    uint8_t value22 = RAM8(0x0000 + sp0 - 1);
    uint8_t value23 = RAM8(0x0000 + sp0);
    if (!carry_ret12) {
        if (m_ret10) {
            a_hi_8ced = a_all12 >> 8;
            x_8ced = (value23 << 8) | value22;
            y_8ced = y_ret12;
            carry_8ced = carry_ret12;
            overflow_8ced = overflow_ret12;
            direct_page_8ced = dp_ret12;
            data_bank_8ced = db_ret12;
            goto shared_8CED;
        } else {
            a_hi_8ced2 = a_all12 >> 8;
            x_8ced2 = (value23 << 8) | value22;
            y_8ced2 = y_ret12;
            carry_8ced2 = carry_ret12;
            overflow_8ced2 = overflow_ret12;
            direct_page_8ced2 = dp_ret12;
            data_bank_8ced2 = db_ret12;
            goto shared_8CED_1;
        }
    }
    r->x = (value23 << 8) | value22;
    r->z = ((value23 << 8) | value22) == 0;
    r->n = ((value23 << 8) | value22) & 0x8000;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8CEC, 0xC18D09); GUARD_JSR(c, sp_call, 0x8CEC); } /* deliver_reflected_cast_hit_preserving_actor */
    uint16_t dp_ret13 = r->dp;
    uint8_t db_ret13 = r->db;
    bool m_ret11 = r->mf;
    uint16_t a_all13 = r->a;
    uint16_t x_ret19 = r->x;
    uint16_t y_ret13 = r->y;
    bool carry_ret13 = r->c;
    bool overflow_ret13 = r->v;
    if (m_ret11) {
        a_hi_8ced = a_all13 >> 8;
        x_8ced = x_ret19;
        y_8ced = y_ret13;
        carry_8ced = carry_ret13;
        overflow_8ced = overflow_ret13;
        direct_page_8ced = dp_ret13;
        data_bank_8ced = db_ret13;
        goto shared_8CED;
    } else {
        a_hi_8ced2 = a_all13 >> 8;
        x_8ced2 = x_ret19;
        y_8ced2 = y_ret13;
        carry_8ced2 = carry_ret13;
        overflow_8ced2 = overflow_ret13;
        direct_page_8ced2 = dp_ret13;
        data_bank_8ced2 = db_ret13;
        goto shared_8CED_1;
    }
    shared_8CED_1:;
    uint8_t value24 = BUS8_RDP(c, (data_bank_8ced2 << 0x10) + 0xE108 + x_8ced2);
    if (!(value24 & 0x80)) {
        if (x_8ced2 >= 0x0600) {
            a_hi_8d08 = a_hi_8ced2;
            x_8d08 = x_8ced2;
            y_8d08 = y_8ced2;
            carry_8d08 = x_8ced2 >= 0x0600;
            overflow_8d08 = overflow_8ced2;
            direct_page_8d08 = direct_page_8ced2;
            data_bank_8d08 = data_bank_8ced2;
            goto shared_8D08;
        }
        uint8_t value25 = BUS8_RDP(c, (data_bank_8ced2 << 0x10) + 0xE060 + x_8ced2);
        if (value25 != 0) {
            a_hi_8d08 = a_hi_8ced2;
            x_8d08 = x_8ced2;
            y_8d08 = y_8ced2;
            carry_8d08 = x_8ced2 >= 0x0600;
            overflow_8d08 = overflow_8ced2;
            direct_page_8d08 = direct_page_8ced2;
            data_bank_8d08 = data_bank_8ced2;
            goto shared_8D08;
        }
        BUS8_SET(c, (data_bank_8ced2 << 0x10) + 0xE104 + x_8ced2, 0);
        r->a = (a_hi_8ced2 << 8) | value25;
        r->x = x_8ced2;
        r->y = y_8ced2;
        r->c = x_8ced2 >= 0x0600;
        r->z = value25 == 0;
        r->n = value25 & 0x80;
        r->v = overflow_8ced2;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_8ced2;
        r->dp = direct_page_8ced2;
        TAIL_CALL(c, 0xC18DAB, SOM_RTS); /* restore_actor_weapon_after_cast */
    }
    r->a = (a_hi_8ced2 << 8) | value24;
    r->x = x_8ced2;
    r->y = x_8ced2;
    r->c = carry_8ced2;
    r->z = x_8ced2 == 0;
    r->n = x_8ced2 & 0x8000;
    r->v = overflow_8ced2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8ced2;
    r->dp = direct_page_8ced2;
    TAIL_CALL(c, 0xC187C2, SOM_RTS); /* transfer_cast_presentation_to_target */
    shared_8D08:;
    r->a = (a_hi_8d08 << 8) | a;
    r->x = x_8d08;
    r->y = y_8d08;
    r->c = carry_8d08;
    r->v = overflow_8d08;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8d08;
    r->dp = direct_page_8d08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18C96, SOM_RTS, "gen", cancel_cast_and_deliver_pending_target_hits, 0, L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 115, 52)

#include "som_c.h"

/* C285EB execute_native59_variant_projectile_or_conditioned_spell   [class B, 143 bytes, 57 instructions]
 * Source: src/rom/execute_native59_variant_projectile_or_conditioned_spell.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void execute_native59_variant_projectile_or_conditioned_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint8_t a_8673 = 0;
    uint8_t a_hi_8673 = 0;
    uint16_t y_8673 = 0;
    bool overflow_8673 = 0;
    uint16_t direct_page_8673 = 0;
    uint8_t data_bank_8673 = 0;
    uint8_t a_86732 = 0;
    uint8_t a_hi_86732 = 0;
    uint8_t y_86732 = 0;
    bool overflow_86732 = 0;
    uint16_t direct_page_86732 = 0;
    uint8_t data_bank_86732 = 0;
    uint8_t a_86733 = 0;
    uint8_t a_hi_86733 = 0;
    uint8_t y_86733 = 0;
    bool overflow_86733 = 0;
    uint16_t direct_page_86733 = 0;
    uint8_t data_bank_86733 = 0;
    uint8_t a_86734 = 0;
    uint8_t a_hi_86734 = 0;
    uint16_t y_86734 = 0;
    bool overflow_86734 = 0;
    uint16_t direct_page_86734 = 0;
    uint8_t data_bank_86734 = 0;
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x85EF, 0xC23372); GUARD_JSR(c, sp_call, 0x85EF); } /* derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction */
    RAM16_SET(0x00AD + value, 0);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x85F5, 0xC2325A); GUARD_JSR(c, sp_call, 0x85F5); } /* select_farthest_active_living_party_actor_last_tie */
    uint16_t a_all2 = r->a;
    bool overflow_ret2 = r->v;
    uint16_t value2 = RAM16(0x0287);
    RAM16_SET(0x00A9 + value2, a_all2);
    uint16_t value3 = RAM16(0x0042 + value2);
    if (value3 != 0) {
        r->a = value3;
        r->x = value2;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8621, 0xC2867A); GUARD_JSR(c, sp_call, 0x8621); } /* consume_native59_known_action_spell_or_report_unrecognized */
        uint16_t a_all3 = r->a;
        bool carry_ret3 = r->c;
        if (carry_ret3) {
            r->a = 1;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8647, 0xC2300B); GUARD_JSR(c, sp_call, 0x8647); } /* draw_boss_frame_random_number */
            uint16_t a_all4 = r->a;
            uint16_t y_ret3 = r->y;
            bool zero_ret4 = r->z;
            if (!zero_ret4) {
                a_8673 = (uint8_t)a_all4;
                a_hi_8673 = a_all4 >> 8;
                y_8673 = y_ret3;
                overflow_8673 = overflow_ret2;
                direct_page_8673 = 0x0200;
                data_bank_8673 = 0x7E;
                goto shared_8673;
            }
            r->a = 3;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x864F, 0xC2300B); GUARD_JSR(c, sp_call, 0x864F); } /* draw_boss_frame_random_number */
            uint16_t a_all5 = r->a;
            uint16_t value4 = BUS16(c, 0xC286AF + a_all5);
            uint16_t value5 = RAM16(0x0287);
            r->a = value4 & 0xFF;
            r->x = value5;
            r->z = value5 == 0;
            r->n = value5 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x865F, 0xC2396D); GUARD_JSR(c, sp_call, 0x865F); } /* prepare_boss_spell_targets */
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x8663, 0xC0001B); GUARD_JSL(c, sp_call, 0x8663); } /* cast_spell_public_jump */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret6 = r->xf;
            uint16_t a_all7 = r->a;
            uint16_t y_ret6 = r->y;
            bool overflow_ret4 = r->v;
            if ((a_all7 & 0xFF) != 0) {
                if (x_ret6) {
                    a_86732 = a_all7 & 0xFF;
                    a_hi_86732 = 0;
                    y_86732 = (uint8_t)y_ret6;
                    overflow_86732 = overflow_ret4;
                    direct_page_86732 = dp_ret;
                    data_bank_86732 = db_ret;
                    goto shared_8673_1;
                } else {
                    a_8673 = a_all7 & 0xFF;
                    a_hi_8673 = 0;
                    y_8673 = y_ret6;
                    overflow_8673 = overflow_ret4;
                    direct_page_8673 = dp_ret;
                    data_bank_8673 = db_ret;
                    goto shared_8673;
                }
            }
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            if (x_ret6) {
                r->a = value6 & 0x1FFF;
                r->x = (uint8_t)(value6 & 0x1FFF);
                r->y = (uint8_t)y_ret6;
                r->z = (uint8_t)(value6 & 0x1FFF) == 0;
                r->n = (uint8_t)(value6 & 0x1FFF) & 0x80;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSL(c, 0x8672, 0x01800F); GUARD_JSL(c, sp_call, 0x8672); } /* cast_actor_request_public_jump */
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret = r->mf;
                bool x_ret8 = r->xf;
                uint16_t a_all8 = r->a;
                uint16_t y_ret7 = r->y;
                bool overflow_ret5 = r->v;
                if (m_ret) {
                    if (x_ret8) {
                        a_86733 = (uint8_t)a_all8;
                        a_hi_86733 = a_all8 >> 8;
                        y_86733 = (uint8_t)y_ret7;
                        overflow_86733 = overflow_ret5;
                        direct_page_86733 = dp_ret2;
                        data_bank_86733 = db_ret2;
                        goto shared_8673_2;
                    } else {
                        a_86734 = (uint8_t)a_all8;
                        a_hi_86734 = a_all8 >> 8;
                        y_86734 = y_ret7;
                        overflow_86734 = overflow_ret5;
                        direct_page_86734 = dp_ret2;
                        data_bank_86734 = db_ret2;
                        goto shared_8673_3;
                    }
                } else {
                    if (x_ret8) {
                        a_86732 = (uint8_t)a_all8;
                        a_hi_86732 = a_all8 >> 8;
                        y_86732 = (uint8_t)y_ret7;
                        overflow_86732 = overflow_ret5;
                        direct_page_86732 = dp_ret2;
                        data_bank_86732 = db_ret2;
                        goto shared_8673_1;
                    } else {
                        a_8673 = (uint8_t)a_all8;
                        a_hi_8673 = a_all8 >> 8;
                        y_8673 = y_ret7;
                        overflow_8673 = overflow_ret5;
                        direct_page_8673 = dp_ret2;
                        data_bank_8673 = db_ret2;
                        goto shared_8673;
                    }
                }
            } else {
                r->a = value6 & 0x1FFF;
                r->x = value6 & 0x1FFF;
                r->z = (value6 & 0x1FFF) == 0;
                r->n = value6 & 0x1FFF & 0x8000;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0x8672, 0x01800F); GUARD_JSL(c, sp_call, 0x8672); } /* cast_actor_request_public_jump */
                uint16_t dp_ret3 = r->dp;
                uint8_t db_ret3 = r->db;
                bool m_ret2 = r->mf;
                bool x_ret10 = r->xf;
                uint16_t a_all9 = r->a;
                uint16_t y_ret8 = r->y;
                bool overflow_ret6 = r->v;
                if (m_ret2) {
                    if (x_ret10) {
                        a_86733 = (uint8_t)a_all9;
                        a_hi_86733 = a_all9 >> 8;
                        y_86733 = (uint8_t)y_ret8;
                        overflow_86733 = overflow_ret6;
                        direct_page_86733 = dp_ret3;
                        data_bank_86733 = db_ret3;
                        goto shared_8673_2;
                    } else {
                        a_86734 = (uint8_t)a_all9;
                        a_hi_86734 = a_all9 >> 8;
                        y_86734 = y_ret8;
                        overflow_86734 = overflow_ret6;
                        direct_page_86734 = dp_ret3;
                        data_bank_86734 = db_ret3;
                        goto shared_8673_3;
                    }
                } else {
                    if (x_ret10) {
                        a_86732 = (uint8_t)a_all9;
                        a_hi_86732 = a_all9 >> 8;
                        y_86732 = (uint8_t)y_ret8;
                        overflow_86732 = overflow_ret6;
                        direct_page_86732 = dp_ret3;
                        data_bank_86732 = db_ret3;
                        goto shared_8673_1;
                    } else {
                        a_8673 = (uint8_t)a_all9;
                        a_hi_8673 = a_all9 >> 8;
                        y_8673 = y_ret8;
                        overflow_8673 = overflow_ret6;
                        direct_page_8673 = dp_ret3;
                        data_bank_8673 = db_ret3;
                        goto shared_8673;
                    }
                }
            }
        }
        r->a = a_all3 & 0xFF;
        r->z = (a_all3 & 0xFF) == 0;
        r->n = a_all3 & 0xFF & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x862C, 0xC2396D); GUARD_JSR(c, sp_call, 0x862C); } /* prepare_boss_spell_targets */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x8630, 0xC0001B); GUARD_JSL(c, sp_call, 0x8630); } /* cast_spell_public_jump */
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret13 = r->xf;
        uint16_t a_all11 = r->a;
        uint16_t y_ret10 = r->y;
        bool overflow_ret8 = r->v;
        if ((a_all11 & 0xFF) != 0) {
            if (x_ret13) {
                a_86732 = a_all11 & 0xFF;
                a_hi_86732 = 0;
                y_86732 = (uint8_t)y_ret10;
                overflow_86732 = overflow_ret8;
                direct_page_86732 = dp_ret4;
                data_bank_86732 = db_ret4;
                goto shared_8673_1;
            } else {
                a_8673 = a_all11 & 0xFF;
                a_hi_8673 = 0;
                y_8673 = y_ret10;
                overflow_8673 = overflow_ret8;
                direct_page_8673 = dp_ret4;
                data_bank_8673 = db_ret4;
                goto shared_8673;
            }
        }
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 0x87));
        if (x_ret13) {
            r->a = value7 & 0x1FFF;
            r->x = (uint8_t)(value7 & 0x1FFF);
            r->y = (uint8_t)y_ret10;
            r->z = (uint8_t)(value7 & 0x1FFF) == 0;
            r->n = (uint8_t)(value7 & 0x1FFF) & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x863F, 0x01800F); GUARD_JSL(c, sp_call, 0x863F); } /* cast_actor_request_public_jump */
            uint16_t dp_ret5 = r->dp;
            uint8_t db_ret5 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret15 = r->xf;
            uint16_t a_all12 = r->a;
            uint16_t y_ret11 = r->y;
            bool overflow_ret9 = r->v;
            if (x_ret15) {
                a_86732 = (uint8_t)a_all12;
                a_hi_86732 = a_all12 >> 8;
                y_86732 = (uint8_t)y_ret11;
                overflow_86732 = overflow_ret9;
                direct_page_86732 = dp_ret5;
                data_bank_86732 = db_ret5;
                goto shared_8673_1;
            } else {
                a_8673 = (uint8_t)a_all12;
                a_hi_8673 = a_all12 >> 8;
                y_8673 = y_ret11;
                overflow_8673 = overflow_ret9;
                direct_page_8673 = dp_ret5;
                data_bank_8673 = db_ret5;
                goto shared_8673;
            }
        } else {
            r->a = value7 & 0x1FFF;
            r->x = value7 & 0x1FFF;
            r->z = (value7 & 0x1FFF) == 0;
            r->n = value7 & 0x1FFF & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x863F, 0x01800F); GUARD_JSL(c, sp_call, 0x863F); } /* cast_actor_request_public_jump */
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret17 = r->xf;
            uint16_t a_all13 = r->a;
            uint16_t y_ret12 = r->y;
            bool overflow_ret10 = r->v;
            if (x_ret17) {
                a_86732 = (uint8_t)a_all13;
                a_hi_86732 = a_all13 >> 8;
                y_86732 = (uint8_t)y_ret12;
                overflow_86732 = overflow_ret10;
                direct_page_86732 = dp_ret6;
                data_bank_86732 = db_ret6;
                goto shared_8673_1;
            } else {
                a_8673 = (uint8_t)a_all13;
                a_hi_8673 = a_all13 >> 8;
                y_8673 = y_ret12;
                overflow_8673 = overflow_ret10;
                direct_page_8673 = dp_ret6;
                data_bank_8673 = db_ret6;
                goto shared_8673;
            }
        }
    }
    r->a = 3;
    r->x = value2;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8605, 0xC2300B); GUARD_JSR(c, sp_call, 0x8605); } /* draw_boss_frame_random_number */
    bool zero_ret14 = r->z;
    if (!zero_ret14) {
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8614, 0xC286E4); GUARD_JSR(c, sp_call, 0x8614); } /* prepare_native59_attack_and_allocate_target_linked_projectile */
        bool x_ret20 = r->xf;
        uint16_t y_ret14 = r->y;
        if (x_ret20) {
            uint8_t value8 = RAM8(0x0287);
            RAM16_SET(0x00B6 + value8, (uint16_t)(RAM16(0x00B6 + value8) + 1));
            RAM16_SET(OBJECT_PHASE + value8, (uint16_t)(RAM16(OBJECT_PHASE + value8) - 1));
            r->x = value8;
            r->y = (uint8_t)y_ret14;
            r->c = 0;
            r->z = RAM16(OBJECT_PHASE + value8) == 0;
            r->n = RAM16(OBJECT_PHASE + value8) & 0x8000;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value9 = RAM16(0x0287);
            RAM16_SET(0x00B6 + value9, (uint16_t)(RAM16(0x00B6 + value9) + 1));
            RAM16_SET(OBJECT_PHASE + value9, (uint16_t)(RAM16(OBJECT_PHASE + value9) - 1));
            r->x = value9;
            r->c = 0;
            r->z = RAM16(OBJECT_PHASE + value9) == 0;
            r->n = RAM16(OBJECT_PHASE + value9) & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x860A, 0xC286B3); GUARD_JSR(c, sp_call, 0x860A); } /* cast_native59_weighted_random_spell */
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret22 = r->xf;
    uint16_t y_ret15 = r->y;
    if (x_ret22) {
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 0x87));
        if (m_ret3) {
            uint8_t value11 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x94 + value10);
            BUS8_SET(c, (db_ret7 << 0x10) + 0x94 + value10, (uint8_t)(value11 - 1));
            r->x = value10;
            r->y = (uint8_t)y_ret15;
            r->c = 0;
            r->z = (uint8_t)(value11 - 1) == 0;
            r->n = (uint8_t)(value11 - 1) & 0x80;
            r->mf = 1;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value12 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value10);
            BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x94 + value10, (uint16_t)(value12 - 1));
            r->x = value10;
            r->y = (uint8_t)y_ret15;
            r->c = 0;
            r->z = (uint16_t)(value12 - 1) == 0;
            r->n = (uint16_t)(value12 - 1) & 0x8000;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
    } else {
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x87));
        if (m_ret3) {
            uint8_t value14 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x94 + value13);
            BUS8_SET(c, (db_ret7 << 0x10) + 0x94 + value13, (uint8_t)(value14 - 1));
            r->x = value13;
            r->c = 0;
            r->z = (uint8_t)(value14 - 1) == 0;
            r->n = (uint8_t)(value14 - 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        } else {
            uint16_t value15 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x94 + value13);
            BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x94 + value13, (uint16_t)(value15 - 1));
            r->x = value13;
            r->c = 0;
            r->z = (uint16_t)(value15 - 1) == 0;
            r->n = (uint16_t)(value15 - 1) & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    shared_8673:;
    uint16_t value16 = BUS16_RDP(c, (uint16_t)(direct_page_8673 + 0x87));
    uint16_t value17 = BUS16_RDP(c, (data_bank_8673 << 0x10) + 0x94 + value16);
    BUS16_RMW_SET(c, (data_bank_8673 << 0x10) + 0x94 + value16, (uint16_t)(value17 - 1));
    r->a = (a_hi_8673 << 8) | a_8673;
    r->x = value16;
    r->y = y_8673;
    r->c = 0;
    r->z = (uint16_t)(value17 - 1) == 0;
    r->n = (uint16_t)(value17 - 1) & 0x8000;
    r->v = overflow_8673;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_8673;
    r->dp = direct_page_8673;
    RETURN_RTS(c);
    shared_8673_1:;
    uint8_t value18 = BUS8_RDP(c, (uint16_t)(direct_page_86732 + 0x87));
    uint16_t value19 = BUS16_RDP(c, (data_bank_86732 << 0x10) + 0x94 + value18);
    BUS16_RMW_SET(c, (data_bank_86732 << 0x10) + 0x94 + value18, (uint16_t)(value19 - 1));
    r->a = (a_hi_86732 << 8) | a_86732;
    r->x = value18;
    r->y = y_86732;
    r->c = 0;
    r->z = (uint16_t)(value19 - 1) == 0;
    r->n = (uint16_t)(value19 - 1) & 0x8000;
    r->v = overflow_86732;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_86732;
    r->dp = direct_page_86732;
    RETURN_RTS(c);
    shared_8673_2:;
    uint8_t value20 = BUS8_RDP(c, (uint16_t)(direct_page_86733 + 0x87));
    uint8_t value21 = BUS8_RDP(c, (data_bank_86733 << 0x10) + 0x94 + value20);
    BUS8_SET(c, (data_bank_86733 << 0x10) + 0x94 + value20, (uint8_t)(value21 - 1));
    r->a = (a_hi_86733 << 8) | a_86733;
    r->x = value20;
    r->y = y_86733;
    r->c = 0;
    r->z = (uint8_t)(value21 - 1) == 0;
    r->n = (uint8_t)(value21 - 1) & 0x80;
    r->v = overflow_86733;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_86733;
    r->dp = direct_page_86733;
    RETURN_RTS(c);
    shared_8673_3:;
    uint16_t value22 = BUS16_RDP(c, (uint16_t)(direct_page_86734 + 0x87));
    uint8_t value23 = BUS8_RDP(c, (data_bank_86734 << 0x10) + 0x94 + value22);
    BUS8_SET(c, (data_bank_86734 << 0x10) + 0x94 + value22, (uint8_t)(value23 - 1));
    r->a = (a_hi_86734 << 8) | a_86734;
    r->x = value22;
    r->y = y_86734;
    r->c = 0;
    r->z = (uint8_t)(value23 - 1) == 0;
    r->n = (uint8_t)(value23 - 1) & 0x80;
    r->v = overflow_86734;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_86734;
    r->dp = direct_page_86734;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC285EB, SOM_RTS, "gen", execute_native59_variant_projectile_or_conditioned_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 143, 57)

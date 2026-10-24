#include "som_c.h"

/* C24812 choose_native54_hp_target_conditioned_spell_and_execute_success   [class B, 77 bytes, 33 instructions]
 * Source: src/rom/choose_native54_hp_target_conditioned_spell_and_execute_success.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void choose_native54_hp_target_conditioned_spell_and_execute_success(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint8_t a_4840 = 0;
    uint8_t a_hi_4840 = 0;
    uint16_t y_4840 = 0;
    bool overflow_4840 = 0;
    uint16_t direct_page_485e = 0;
    uint8_t data_bank_485e = 0;
    uint16_t direct_page_485e2 = 0;
    uint8_t data_bank_485e2 = 0;
    uint16_t direct_page_485e3 = 0;
    uint8_t data_bank_485e3 = 0;
    uint16_t direct_page_485e4 = 0;
    uint8_t data_bank_485e4 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4814, 0xC209B4); GUARD_JSR(c, sp_call, 0x4814); } /* compute_capped_boss_maximum_over_current_hp_ratio */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool overflow_ret = r->v;
    if (a_all >= 2) {
        r->a = 2;
        r->c = a_all >= 2;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x483F, 0xC2300B); GUARD_JSR(c, sp_call, 0x483F); } /* draw_boss_frame_random_number */
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        a_4840 = (uint8_t)a_all2;
        a_hi_4840 = a_all2 >> 8;
        y_4840 = y_ret2;
        overflow_4840 = overflow_ret;
        goto shared_4840;
    }
    uint16_t value = RAM16(0x00A9 + x_ret);
    if (RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) != 0) {
        r->a = 1;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
        r->c = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4837, 0xC2300B); GUARD_JSR(c, sp_call, 0x4837); } /* draw_boss_frame_random_number */
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        a_4840 = (uint8_t)a_all3;
        a_hi_4840 = a_all3 >> 8;
        y_4840 = y_ret3;
        overflow_4840 = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        goto shared_4840;
    }
    r->a = 1;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x482E, 0xC2300B); GUARD_JSR(c, sp_call, 0x482E); } /* draw_boss_frame_random_number */
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    a_4840 = (uint8_t)(a_all4 + 1);
    a_hi_4840 = (uint16_t)(a_all4 + 1) >> 8;
    y_4840 = y_ret4;
    overflow_4840 = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    shared_4840:;
    uint16_t value3 = BUS16(c, 0xC2485F + (uint16_t)(((a_hi_4840 << 8) | a_4840) << 1));
    uint16_t value4 = RAM16(0x0287);
    r->a = value3;
    r->x = value4;
    r->y = y_4840;
    r->c = ((a_hi_4840 << 8) | a_4840) & 0x8000;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->v = overflow_4840;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    { const uint16_t sp_call = r->sp; JSR(c, 0x484A, 0xC2396D); GUARD_JSR(c, sp_call, 0x484A); } /* prepare_boss_spell_targets */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x484E, 0xC0001B); GUARD_JSL(c, sp_call, 0x484E); } /* cast_spell_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret6 = r->xf;
    uint16_t a_all6 = r->a;
    uint16_t y_ret6 = r->y;
    if ((a_all6 & 0xFF) != 0) {
        if (x_ret6) {
            direct_page_485e = dp_ret;
            data_bank_485e = db_ret;
            goto shared_485E;
        } else {
            direct_page_485e2 = dp_ret;
            data_bank_485e2 = db_ret;
            goto shared_485E_1;
        }
    }
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
    if (x_ret6) {
        r->a = value5 & 0x1FFF;
        r->x = (uint8_t)(value5 & 0x1FFF);
        r->y = (uint8_t)y_ret6;
        r->z = (uint8_t)(value5 & 0x1FFF) == 0;
        r->n = (uint8_t)(value5 & 0x1FFF) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x485D, 0x01800F); GUARD_JSL(c, sp_call, 0x485D); } /* cast_actor_request_public_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret8 = r->xf;
        if (m_ret) {
            if (x_ret8) {
                direct_page_485e3 = dp_ret2;
                data_bank_485e3 = db_ret2;
                goto shared_485E_2;
            } else {
                direct_page_485e4 = dp_ret2;
                data_bank_485e4 = db_ret2;
                goto shared_485E_3;
            }
        } else {
            if (x_ret8) {
                direct_page_485e = dp_ret2;
                data_bank_485e = db_ret2;
                goto shared_485E;
            } else {
                direct_page_485e2 = dp_ret2;
                data_bank_485e2 = db_ret2;
                goto shared_485E_1;
            }
        }
    } else {
        r->a = value5 & 0x1FFF;
        r->x = value5 & 0x1FFF;
        r->z = (value5 & 0x1FFF) == 0;
        r->n = value5 & 0x1FFF & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x485D, 0x01800F); GUARD_JSL(c, sp_call, 0x485D); } /* cast_actor_request_public_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret10 = r->xf;
        if (m_ret2) {
            if (x_ret10) {
                direct_page_485e3 = dp_ret3;
                data_bank_485e3 = db_ret3;
                goto shared_485E_2;
            } else {
                direct_page_485e4 = dp_ret3;
                data_bank_485e4 = db_ret3;
                goto shared_485E_3;
            }
        } else {
            if (x_ret10) {
                direct_page_485e = dp_ret3;
                data_bank_485e = db_ret3;
                goto shared_485E;
            } else {
                direct_page_485e2 = dp_ret3;
                data_bank_485e2 = db_ret3;
                goto shared_485E_1;
            }
        }
    }
    shared_485E:;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_485e;
    r->dp = direct_page_485e;
    RETURN_RTS(c);
    shared_485E_1:;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_485e2;
    r->dp = direct_page_485e2;
    RETURN_RTS(c);
    shared_485E_2:;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_485e3;
    r->dp = direct_page_485e3;
    RETURN_RTS(c);
    shared_485E_3:;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_485e4;
    r->dp = direct_page_485e4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24812, SOM_RTS, "gen", choose_native54_hp_target_conditioned_spell_and_execute_success, 0, 0, 1, 0, 0, 77, 33)

#include "som_c.h"

/* C272C1 publish_descriptor_seven_reward_then_explode_until_terminal_event_phase   [class B, 62 bytes, 25 instructions]
 * Source: src/rom/publish_descriptor_seven_reward_then_explode_until_terminal_event_phase.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void publish_descriptor_seven_reward_then_explode_until_terminal_event_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_72dc = 0;
    uint8_t a_hi_72dc = 0;
    uint16_t x_72dc = 0;
    uint16_t y_72dc = 0;
    bool overflow_72dc = 0;
    uint16_t direct_page_72dc = 0;
    uint8_t data_bank_72dc = 0;
    uint8_t a_72dc2 = 0;
    uint8_t a_hi_72dc2 = 0;
    uint8_t x_72dc2 = 0;
    uint8_t y_72dc2 = 0;
    bool overflow_72dc2 = 0;
    uint16_t direct_page_72dc2 = 0;
    uint8_t data_bank_72dc2 = 0;
    uint8_t a_72e9 = 0;
    uint8_t a_hi_72e9 = 0;
    uint16_t x_72e9 = 0;
    uint16_t y_72e9 = 0;
    bool zero_72e9 = 0;
    bool negative_72e9 = 0;
    bool overflow_72e9 = 0;
    uint16_t direct_page_72e9 = 0;
    uint8_t data_bank_72e9 = 0;
    uint8_t a_72e92 = 0;
    uint8_t a_hi_72e92 = 0;
    uint8_t x_72e92 = 0;
    uint8_t y_72e92 = 0;
    bool zero_72e92 = 0;
    bool negative_72e92 = 0;
    bool overflow_72e92 = 0;
    uint16_t direct_page_72e92 = 0;
    uint8_t data_bank_72e92 = 0;
    uint8_t a_72e93 = 0;
    uint8_t a_hi_72e93 = 0;
    uint16_t x_72e93 = 0;
    uint16_t y_72e93 = 0;
    bool zero_72e93 = 0;
    bool negative_72e93 = 0;
    bool overflow_72e93 = 0;
    uint16_t direct_page_72e93 = 0;
    uint8_t data_bank_72e93 = 0;
    uint8_t a_72e94 = 0;
    uint8_t a_hi_72e94 = 0;
    uint8_t x_72e94 = 0;
    uint8_t y_72e94 = 0;
    bool zero_72e94 = 0;
    bool negative_72e94 = 0;
    bool overflow_72e94 = 0;
    uint16_t direct_page_72e94 = 0;
    uint8_t data_bank_72e94 = 0;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    if (value2 != 0x18) {
        a_72dc = (uint8_t)value2;
        a_hi_72dc = value2 >> 8;
        x_72dc = value;
        y_72dc = y;
        overflow_72dc = overflow;
        direct_page_72dc = dp;
        data_bank_72dc = 0x7E;
        goto shared_72DC;
    }
    r->a = 0x07F8;
    r->x = value;
    r->c = value2 >= 0x18;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x72D0, 0xC20C11); GUARD_JSR(c, sp_call, 0x72D0); } /* mark_controller_and_request_numeric_boss_death_event */
    uint16_t dp_ret = r->dp;
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->x = value3;
        r->y = (uint8_t)y_ret;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x72D6, 0xC0006F); GUARD_JSL(c, sp_call, 0x72D6); } /* public_actor_death_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        if (x_ret3) {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x87));
            uint16_t value5 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x96 + value4);
            a_72dc2 = (uint8_t)value5;
            a_hi_72dc2 = value5 >> 8;
            x_72dc2 = value4;
            y_72dc2 = (uint8_t)y_ret2;
            overflow_72dc2 = overflow_ret2;
            direct_page_72dc2 = dp_ret2;
            data_bank_72dc2 = db_ret2;
            goto shared_72DC_1;
        } else {
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x87));
            uint16_t value7 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x96 + value6);
            a_72dc = (uint8_t)value7;
            a_hi_72dc = value7 >> 8;
            x_72dc = value6;
            y_72dc = y_ret2;
            overflow_72dc = overflow_ret2;
            direct_page_72dc = dp_ret2;
            data_bank_72dc = db_ret2;
            goto shared_72DC;
        }
    } else {
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->x = value8;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x72D6, 0xC0006F); GUARD_JSL(c, sp_call, 0x72D6); } /* public_actor_death_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret5 = r->xf;
        uint16_t y_ret3 = r->y;
        bool overflow_ret3 = r->v;
        if (x_ret5) {
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x87));
            uint16_t value10 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x96 + value9);
            a_72dc2 = (uint8_t)value10;
            a_hi_72dc2 = value10 >> 8;
            x_72dc2 = value9;
            y_72dc2 = (uint8_t)y_ret3;
            overflow_72dc2 = overflow_ret3;
            direct_page_72dc2 = dp_ret3;
            data_bank_72dc2 = db_ret3;
            goto shared_72DC_1;
        } else {
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x87));
            uint16_t value12 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x96 + value11);
            a_72dc = (uint8_t)value12;
            a_hi_72dc = value12 >> 8;
            x_72dc = value11;
            y_72dc = y_ret3;
            overflow_72dc = overflow_ret3;
            direct_page_72dc = dp_ret3;
            data_bank_72dc = db_ret3;
            goto shared_72DC;
        }
    }
    shared_72DC:;
    if (((a_hi_72dc << 8) | a_72dc) >= 0x30) {
        BUS16_SET(c, (data_bank_72dc << 0x10) + 0xA7 + x_72dc, 0);
        uint16_t value13 = BUS16_RDP(c, (data_bank_72dc << 0x10) + 0x94 + x_72dc);
        BUS16_RMW_SET(c, (data_bank_72dc << 0x10) + 0x94 + x_72dc, (uint16_t)(value13 + 1));
        BUS16_SET(c, (data_bank_72dc << 0x10) + 0x96 + x_72dc, 0);
        r->a = 0x8A00;
        r->x = x_72dc;
        r->y = y_72dc;
        r->c = ((a_hi_72dc << 8) | a_72dc) >= 0x30;
        r->z = 0;
        r->n = 1;
        r->v = overflow_72dc;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank_72dc;
        r->dp = direct_page_72dc;
        { const uint16_t sp_call = r->sp; JSR(c, 0x72FC, 0xC23963); GUARD_JSR(c, sp_call, 0x72FC); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if ((((a_hi_72dc << 8) | a_72dc) & 3) != 0) {
        a_72e9 = ((a_hi_72dc << 8) | a_72dc) & 3;
        a_hi_72e9 = 0;
        x_72e9 = x_72dc;
        y_72e9 = y_72dc;
        zero_72e9 = (((a_hi_72dc << 8) | a_72dc) & 3) == 0;
        negative_72e9 = ((a_hi_72dc << 8) | a_72dc) & 3 & 0x8000;
        overflow_72e9 = overflow_72dc;
        direct_page_72e9 = direct_page_72dc;
        data_bank_72e9 = data_bank_72dc;
        goto shared_72E9;
    }
    r->a = ((a_hi_72dc << 8) | a_72dc) & 3;
    r->x = x_72dc;
    r->y = y_72dc;
    r->c = ((a_hi_72dc << 8) | a_72dc) >= 0x30;
    r->z = (((a_hi_72dc << 8) | a_72dc) & 3) == 0;
    r->n = ((a_hi_72dc << 8) | a_72dc) & 3 & 0x8000;
    r->v = overflow_72dc;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_72dc;
    r->dp = direct_page_72dc;
    { const uint16_t sp_call = r->sp; JSR(c, 0x72E8, 0xC20C3C); GUARD_JSR(c, sp_call, 0x72E8); } /* external */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret9 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret10 = r->x;
    uint16_t y_ret5 = r->y;
    bool zero_ret5 = r->z;
    bool negative_ret5 = r->n;
    bool overflow_ret5 = r->v;
    if (m_ret3) {
        if (x_ret9) {
            a_72e92 = (uint8_t)a_all5;
            a_hi_72e92 = a_all5 >> 8;
            x_72e92 = (uint8_t)x_ret10;
            y_72e92 = (uint8_t)y_ret5;
            zero_72e92 = zero_ret5;
            negative_72e92 = negative_ret5;
            overflow_72e92 = overflow_ret5;
            direct_page_72e92 = dp_ret5;
            data_bank_72e92 = db_ret5;
            goto shared_72E9_1;
        } else {
            a_72e93 = (uint8_t)a_all5;
            a_hi_72e93 = a_all5 >> 8;
            x_72e93 = x_ret10;
            y_72e93 = y_ret5;
            zero_72e93 = zero_ret5;
            negative_72e93 = negative_ret5;
            overflow_72e93 = overflow_ret5;
            direct_page_72e93 = dp_ret5;
            data_bank_72e93 = db_ret5;
            goto shared_72E9_2;
        }
    } else {
        if (x_ret9) {
            a_72e94 = (uint8_t)a_all5;
            a_hi_72e94 = a_all5 >> 8;
            x_72e94 = (uint8_t)x_ret10;
            y_72e94 = (uint8_t)y_ret5;
            zero_72e94 = zero_ret5;
            negative_72e94 = negative_ret5;
            overflow_72e94 = overflow_ret5;
            direct_page_72e94 = dp_ret5;
            data_bank_72e94 = db_ret5;
            goto shared_72E9_3;
        } else {
            a_72e9 = (uint8_t)a_all5;
            a_hi_72e9 = a_all5 >> 8;
            x_72e9 = x_ret10;
            y_72e9 = y_ret5;
            zero_72e9 = zero_ret5;
            negative_72e9 = negative_ret5;
            overflow_72e9 = overflow_ret5;
            direct_page_72e9 = dp_ret5;
            data_bank_72e9 = db_ret5;
            goto shared_72E9;
        }
    }
    shared_72DC_1:;
    if (((a_hi_72dc2 << 8) | a_72dc2) >= 0x30) {
        BUS16_SET(c, (data_bank_72dc2 << 0x10) + 0xA7 + x_72dc2, 0);
        uint16_t value14 = BUS16_RDP(c, (data_bank_72dc2 << 0x10) + 0x94 + x_72dc2);
        BUS16_RMW_SET(c, (data_bank_72dc2 << 0x10) + 0x94 + x_72dc2, (uint16_t)(value14 + 1));
        BUS16_SET(c, (data_bank_72dc2 << 0x10) + 0x96 + x_72dc2, 0);
        r->a = 0x8A00;
        r->x = x_72dc2;
        r->y = y_72dc2;
        r->c = ((a_hi_72dc2 << 8) | a_72dc2) >= 0x30;
        r->z = 0;
        r->n = 1;
        r->v = overflow_72dc2;
        r->mf = 0;
        r->xf = 1;
        r->db = data_bank_72dc2;
        r->dp = direct_page_72dc2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x72FC, 0xC23963); GUARD_JSR(c, sp_call, 0x72FC); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if ((((a_hi_72dc2 << 8) | a_72dc2) & 3) != 0) {
        a_72e94 = ((a_hi_72dc2 << 8) | a_72dc2) & 3;
        a_hi_72e94 = 0;
        x_72e94 = x_72dc2;
        y_72e94 = y_72dc2;
        zero_72e94 = (((a_hi_72dc2 << 8) | a_72dc2) & 3) == 0;
        negative_72e94 = ((a_hi_72dc2 << 8) | a_72dc2) & 3 & 0x8000;
        overflow_72e94 = overflow_72dc2;
        direct_page_72e94 = direct_page_72dc2;
        data_bank_72e94 = data_bank_72dc2;
        goto shared_72E9_3;
    }
    r->a = ((a_hi_72dc2 << 8) | a_72dc2) & 3;
    r->x = x_72dc2;
    r->y = y_72dc2;
    r->c = ((a_hi_72dc2 << 8) | a_72dc2) >= 0x30;
    r->z = (((a_hi_72dc2 << 8) | a_72dc2) & 3) == 0;
    r->n = ((a_hi_72dc2 << 8) | a_72dc2) & 3 & 0x8000;
    r->v = overflow_72dc2;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_72dc2;
    r->dp = direct_page_72dc2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x72E8, 0xC20C3C); GUARD_JSR(c, sp_call, 0x72E8); } /* external */
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool m_ret5 = r->mf;
    bool x_ret13 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t x_ret14 = r->x;
    uint16_t y_ret7 = r->y;
    bool zero_ret7 = r->z;
    bool negative_ret7 = r->n;
    bool overflow_ret7 = r->v;
    if (m_ret5) {
        if (x_ret13) {
            a_72e92 = (uint8_t)a_all7;
            a_hi_72e92 = a_all7 >> 8;
            x_72e92 = (uint8_t)x_ret14;
            y_72e92 = (uint8_t)y_ret7;
            zero_72e92 = zero_ret7;
            negative_72e92 = negative_ret7;
            overflow_72e92 = overflow_ret7;
            direct_page_72e92 = dp_ret7;
            data_bank_72e92 = db_ret7;
            goto shared_72E9_1;
        } else {
            a_72e93 = (uint8_t)a_all7;
            a_hi_72e93 = a_all7 >> 8;
            x_72e93 = x_ret14;
            y_72e93 = y_ret7;
            zero_72e93 = zero_ret7;
            negative_72e93 = negative_ret7;
            overflow_72e93 = overflow_ret7;
            direct_page_72e93 = dp_ret7;
            data_bank_72e93 = db_ret7;
            goto shared_72E9_2;
        }
    } else {
        if (x_ret13) {
            a_72e94 = (uint8_t)a_all7;
            a_hi_72e94 = a_all7 >> 8;
            x_72e94 = (uint8_t)x_ret14;
            y_72e94 = (uint8_t)y_ret7;
            zero_72e94 = zero_ret7;
            negative_72e94 = negative_ret7;
            overflow_72e94 = overflow_ret7;
            direct_page_72e94 = dp_ret7;
            data_bank_72e94 = db_ret7;
            goto shared_72E9_3;
        } else {
            a_72e9 = (uint8_t)a_all7;
            a_hi_72e9 = a_all7 >> 8;
            x_72e9 = x_ret14;
            y_72e9 = y_ret7;
            zero_72e9 = zero_ret7;
            negative_72e9 = negative_ret7;
            overflow_72e9 = overflow_ret7;
            direct_page_72e9 = dp_ret7;
            data_bank_72e9 = db_ret7;
            goto shared_72E9;
        }
    }
    shared_72E9:;
    r->a = (a_hi_72e9 << 8) | a_72e9;
    r->x = x_72e9;
    r->y = y_72e9;
    r->z = zero_72e9;
    r->n = negative_72e9;
    r->v = overflow_72e9;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_72e9;
    r->dp = direct_page_72e9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x72EB, 0xC20C89); GUARD_JSR(c, sp_call, 0x72EB); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
    shared_72E9_1:;
    r->a = (a_hi_72e92 << 8) | a_72e92;
    r->x = x_72e92;
    r->y = y_72e92;
    r->z = zero_72e92;
    r->n = negative_72e92;
    r->v = overflow_72e92;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_72e92;
    r->dp = direct_page_72e92;
    { const uint16_t sp_call = r->sp; JSR(c, 0x72EB, 0xC20C89); GUARD_JSR(c, sp_call, 0x72EB); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
    shared_72E9_2:;
    r->a = (a_hi_72e93 << 8) | a_72e93;
    r->x = x_72e93;
    r->y = y_72e93;
    r->z = zero_72e93;
    r->n = negative_72e93;
    r->v = overflow_72e93;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_72e93;
    r->dp = direct_page_72e93;
    { const uint16_t sp_call = r->sp; JSR(c, 0x72EB, 0xC20C89); GUARD_JSR(c, sp_call, 0x72EB); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
    shared_72E9_3:;
    r->a = (a_hi_72e94 << 8) | a_72e94;
    r->x = x_72e94;
    r->y = y_72e94;
    r->z = zero_72e94;
    r->n = negative_72e94;
    r->v = overflow_72e94;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_72e94;
    r->dp = direct_page_72e94;
    { const uint16_t sp_call = r->sp; JSR(c, 0x72EB, 0xC20C89); GUARD_JSR(c, sp_call, 0x72EB); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC272C1, SOM_RTS, "gen", publish_descriptor_seven_reward_then_explode_until_terminal_event_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 62, 25)

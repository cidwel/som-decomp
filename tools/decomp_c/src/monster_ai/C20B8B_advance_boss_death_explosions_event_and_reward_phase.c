#include "som_c.h"

/* C20B8B advance_boss_death_explosions_event_and_reward_phase   [class B, 62 bytes, 25 instructions]
 * Source: src/rom/advance_boss_death_explosions_event_and_reward_phase.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_boss_death_explosions_event_and_reward_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_0ba6 = 0;
    uint8_t a_hi_0ba6 = 0;
    uint16_t x_0ba6 = 0;
    uint16_t y_0ba6 = 0;
    bool overflow_0ba6 = 0;
    uint16_t direct_page_0ba6 = 0;
    uint8_t data_bank_0ba6 = 0;
    uint8_t a_0ba62 = 0;
    uint8_t a_hi_0ba62 = 0;
    uint8_t x_0ba62 = 0;
    uint8_t y_0ba62 = 0;
    bool overflow_0ba62 = 0;
    uint16_t direct_page_0ba62 = 0;
    uint8_t data_bank_0ba62 = 0;
    uint8_t a_0bb3 = 0;
    uint8_t a_hi_0bb3 = 0;
    uint16_t x_0bb3 = 0;
    uint16_t y_0bb3 = 0;
    bool zero_0bb3 = 0;
    bool negative_0bb3 = 0;
    bool overflow_0bb3 = 0;
    uint16_t direct_page_0bb3 = 0;
    uint8_t data_bank_0bb3 = 0;
    uint8_t a_0bb32 = 0;
    uint8_t a_hi_0bb32 = 0;
    uint8_t x_0bb32 = 0;
    uint8_t y_0bb32 = 0;
    bool zero_0bb32 = 0;
    bool negative_0bb32 = 0;
    bool overflow_0bb32 = 0;
    uint16_t direct_page_0bb32 = 0;
    uint8_t data_bank_0bb32 = 0;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    if (value2 != 0x18) {
        a_0ba6 = (uint8_t)value2;
        a_hi_0ba6 = value2 >> 8;
        x_0ba6 = value;
        y_0ba6 = y;
        overflow_0ba6 = overflow;
        direct_page_0ba6 = 0x0200;
        data_bank_0ba6 = 0x7E;
        goto shared_0BA6;
    }
    r->a = 0x07F8;
    r->x = value;
    r->c = value2 >= 0x18;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0B9A, 0xC20C11); GUARD_JSR(c, sp_call, 0x0B9A); } /* mark_controller_and_request_numeric_boss_death_event */
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
        { const uint16_t sp_call = r->sp; JSL(c, 0x0BA0, 0xC0006F); GUARD_JSL(c, sp_call, 0x0BA0); } /* public_actor_death_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        if (x_ret3) {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x87));
            uint16_t value5 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x96 + value4);
            a_0ba62 = (uint8_t)value5;
            a_hi_0ba62 = value5 >> 8;
            x_0ba62 = value4;
            y_0ba62 = (uint8_t)y_ret2;
            overflow_0ba62 = overflow_ret2;
            direct_page_0ba62 = dp_ret2;
            data_bank_0ba62 = db_ret2;
            goto shared_0BA6_1;
        } else {
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x87));
            uint16_t value7 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x96 + value6);
            a_0ba6 = (uint8_t)value7;
            a_hi_0ba6 = value7 >> 8;
            x_0ba6 = value6;
            y_0ba6 = y_ret2;
            overflow_0ba6 = overflow_ret2;
            direct_page_0ba6 = dp_ret2;
            data_bank_0ba6 = db_ret2;
            goto shared_0BA6;
        }
    } else {
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->x = value8;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x0BA0, 0xC0006F); GUARD_JSL(c, sp_call, 0x0BA0); } /* public_actor_death_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret5 = r->xf;
        uint16_t y_ret3 = r->y;
        bool overflow_ret3 = r->v;
        if (x_ret5) {
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x87));
            uint16_t value10 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x96 + value9);
            a_0ba62 = (uint8_t)value10;
            a_hi_0ba62 = value10 >> 8;
            x_0ba62 = value9;
            y_0ba62 = (uint8_t)y_ret3;
            overflow_0ba62 = overflow_ret3;
            direct_page_0ba62 = dp_ret3;
            data_bank_0ba62 = db_ret3;
            goto shared_0BA6_1;
        } else {
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x87));
            uint16_t value12 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x96 + value11);
            a_0ba6 = (uint8_t)value12;
            a_hi_0ba6 = value12 >> 8;
            x_0ba6 = value11;
            y_0ba6 = y_ret3;
            overflow_0ba6 = overflow_ret3;
            direct_page_0ba6 = dp_ret3;
            data_bank_0ba6 = db_ret3;
            goto shared_0BA6;
        }
    }
    shared_0BA6:;
    if (((a_hi_0ba6 << 8) | a_0ba6) >= 0x34) {
        BUS16_SET(c, (data_bank_0ba6 << 0x10) + 0xA7 + x_0ba6, 0);
        uint16_t value13 = BUS16_RDP(c, (data_bank_0ba6 << 0x10) + 0x94 + x_0ba6);
        BUS16_RMW_SET(c, (data_bank_0ba6 << 0x10) + 0x94 + x_0ba6, (uint16_t)(value13 + 1));
        BUS16_SET(c, (data_bank_0ba6 << 0x10) + 0x96 + x_0ba6, 0);
        r->a = 0x8A00;
        r->x = x_0ba6;
        r->y = y_0ba6;
        r->c = ((a_hi_0ba6 << 8) | a_0ba6) >= 0x34;
        r->z = 0;
        r->n = 1;
        r->v = overflow_0ba6;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank_0ba6;
        r->dp = direct_page_0ba6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0BC6, 0xC23963); GUARD_JSR(c, sp_call, 0x0BC6); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if ((((a_hi_0ba6 << 8) | a_0ba6) & 3) != 0) {
        a_0bb3 = ((a_hi_0ba6 << 8) | a_0ba6) & 3;
        a_hi_0bb3 = 0;
        x_0bb3 = x_0ba6;
        y_0bb3 = y_0ba6;
        zero_0bb3 = (((a_hi_0ba6 << 8) | a_0ba6) & 3) == 0;
        negative_0bb3 = ((a_hi_0ba6 << 8) | a_0ba6) & 3 & 0x8000;
        overflow_0bb3 = overflow_0ba6;
        direct_page_0bb3 = direct_page_0ba6;
        data_bank_0bb3 = data_bank_0ba6;
        goto shared_0BB3;
    }
    r->a = ((a_hi_0ba6 << 8) | a_0ba6) & 3;
    r->x = x_0ba6;
    r->y = y_0ba6;
    r->c = ((a_hi_0ba6 << 8) | a_0ba6) >= 0x34;
    r->z = (((a_hi_0ba6 << 8) | a_0ba6) & 3) == 0;
    r->n = ((a_hi_0ba6 << 8) | a_0ba6) & 3 & 0x8000;
    r->v = overflow_0ba6;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_0ba6;
    r->dp = direct_page_0ba6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0BB2, 0xC20C33); GUARD_JSR(c, sp_call, 0x0BB2); } /* create_randomly_positioned_boss_death_explosion_actor */
    uint16_t a_all5 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret5 = r->y;
    bool zero_ret5 = r->z;
    bool negative_ret5 = r->n;
    bool overflow_ret5 = r->v;
    a_0bb3 = (uint8_t)a_all5;
    a_hi_0bb3 = a_all5 >> 8;
    x_0bb3 = x_ret9;
    y_0bb3 = y_ret5;
    zero_0bb3 = zero_ret5;
    negative_0bb3 = negative_ret5;
    overflow_0bb3 = overflow_ret5;
    direct_page_0bb3 = direct_page_0ba6;
    data_bank_0bb3 = data_bank_0ba6;
    goto shared_0BB3;
    shared_0BA6_1:;
    if (((a_hi_0ba62 << 8) | a_0ba62) >= 0x34) {
        BUS16_SET(c, (data_bank_0ba62 << 0x10) + 0xA7 + x_0ba62, 0);
        uint16_t value14 = BUS16_RDP(c, (data_bank_0ba62 << 0x10) + 0x94 + x_0ba62);
        BUS16_RMW_SET(c, (data_bank_0ba62 << 0x10) + 0x94 + x_0ba62, (uint16_t)(value14 + 1));
        BUS16_SET(c, (data_bank_0ba62 << 0x10) + 0x96 + x_0ba62, 0);
        r->a = 0x8A00;
        r->x = x_0ba62;
        r->y = y_0ba62;
        r->c = ((a_hi_0ba62 << 8) | a_0ba62) >= 0x34;
        r->z = 0;
        r->n = 1;
        r->v = overflow_0ba62;
        r->mf = 0;
        r->xf = 1;
        r->db = data_bank_0ba62;
        r->dp = direct_page_0ba62;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0BC6, 0xC23963); GUARD_JSR(c, sp_call, 0x0BC6); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if ((((a_hi_0ba62 << 8) | a_0ba62) & 3) != 0) {
        a_0bb32 = ((a_hi_0ba62 << 8) | a_0ba62) & 3;
        a_hi_0bb32 = 0;
        x_0bb32 = x_0ba62;
        y_0bb32 = y_0ba62;
        zero_0bb32 = (((a_hi_0ba62 << 8) | a_0ba62) & 3) == 0;
        negative_0bb32 = ((a_hi_0ba62 << 8) | a_0ba62) & 3 & 0x8000;
        overflow_0bb32 = overflow_0ba62;
        direct_page_0bb32 = direct_page_0ba62;
        data_bank_0bb32 = data_bank_0ba62;
        goto shared_0BB3_1;
    }
    r->a = ((a_hi_0ba62 << 8) | a_0ba62) & 3;
    r->x = x_0ba62;
    r->y = y_0ba62;
    r->c = ((a_hi_0ba62 << 8) | a_0ba62) >= 0x34;
    r->z = (((a_hi_0ba62 << 8) | a_0ba62) & 3) == 0;
    r->n = ((a_hi_0ba62 << 8) | a_0ba62) & 3 & 0x8000;
    r->v = overflow_0ba62;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_0ba62;
    r->dp = direct_page_0ba62;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0BB2, 0xC20C33); GUARD_JSR(c, sp_call, 0x0BB2); } /* create_randomly_positioned_boss_death_explosion_actor */
    uint16_t a_all7 = r->a;
    uint16_t x_ret12 = r->x;
    uint16_t y_ret7 = r->y;
    bool zero_ret7 = r->z;
    bool negative_ret7 = r->n;
    bool overflow_ret7 = r->v;
    a_0bb3 = (uint8_t)a_all7;
    a_hi_0bb3 = a_all7 >> 8;
    x_0bb3 = x_ret12;
    y_0bb3 = y_ret7;
    zero_0bb3 = zero_ret7;
    negative_0bb3 = negative_ret7;
    overflow_0bb3 = overflow_ret7;
    direct_page_0bb3 = direct_page_0ba62;
    data_bank_0bb3 = data_bank_0ba62;
    goto shared_0BB3;
    shared_0BB3:;
    r->a = (a_hi_0bb3 << 8) | a_0bb3;
    r->x = x_0bb3;
    r->y = y_0bb3;
    r->z = zero_0bb3;
    r->n = negative_0bb3;
    r->v = overflow_0bb3;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_0bb3;
    r->dp = direct_page_0bb3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0BB5, 0xC20C89); GUARD_JSR(c, sp_call, 0x0BB5); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
    shared_0BB3_1:;
    r->a = (a_hi_0bb32 << 8) | a_0bb32;
    r->x = x_0bb32;
    r->y = y_0bb32;
    r->z = zero_0bb32;
    r->n = negative_0bb32;
    r->v = overflow_0bb32;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_0bb32;
    r->dp = direct_page_0bb32;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0BB5, 0xC20C89); GUARD_JSR(c, sp_call, 0x0BB5); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20B8B, SOM_RTS, "gen", advance_boss_death_explosions_event_and_reward_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 62, 25)

#include "som_c.h"

/* C282E4 cast_selected_spell_at_parent_target_and_execute_success   [class B, 62 bytes, 26 instructions]
 * Source: src/rom/cast_selected_spell_at_parent_target_and_execute_success.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void cast_selected_spell_at_parent_target_and_execute_success_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t direct_page_8321 = 0;
    uint8_t data_bank_8321 = 0;
    uint16_t direct_page_83212 = 0;
    uint8_t data_bank_83212 = 0;
    uint16_t direct_page_83213 = 0;
    uint8_t data_bank_83213 = 0;
    uint16_t direct_page_83214 = 0;
    uint8_t data_bank_83214 = 0;
    RAM16_SET(0x0397, a);
    uint16_t value = RAM16(0x00B0 + RAM16(BATTLE_DEFENCE_WORK));
    RAM16_SET(0x0395, value);
    RAM8(0x0170 + value) = RAM8(0x0397);
    RAM8(0x0176 + value) = 1;
    RAM8(0x0177 + value) = 0;
    uint8_t value3 = RAM8(0x00A9 + value);
    RAM8(0x0178 + value) = (uint8_t)(value3 + 1);
    RAM8(0x0179 + value) = 0;
    RAM8(0x017A + value) = 0;
    uint16_t value4 = RAM16(0x0395);
    r->a = (value >> 8 << 8) | (uint8_t)(value3 + 1);
    r->x = value4;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8311, 0xC0001B); GUARD_JSL(c, sp_call, 0x8311); } /* cast_spell_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    if ((a_all & 0xFF) != 0) {
        if (x_ret) {
            direct_page_8321 = dp_ret;
            data_bank_8321 = db_ret;
            goto shared_8321;
        } else {
            direct_page_83212 = dp_ret;
            data_bank_83212 = db_ret;
            goto shared_8321_1;
        }
    }
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
    if (x_ret) {
        r->a = value5 & 0x1FFF;
        r->x = (uint8_t)(value5 & 0x1FFF);
        r->y = (uint8_t)y_ret;
        r->z = (uint8_t)(value5 & 0x1FFF) == 0;
        r->n = (uint8_t)(value5 & 0x1FFF) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x8320, 0x01800F); GUARD_JSL(c, sp_call, 0x8320); } /* cast_actor_request_public_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        if (m_ret) {
            if (x_ret3) {
                direct_page_83213 = dp_ret2;
                data_bank_83213 = db_ret2;
                goto shared_8321_2;
            } else {
                direct_page_83214 = dp_ret2;
                data_bank_83214 = db_ret2;
                goto shared_8321_3;
            }
        } else {
            if (x_ret3) {
                direct_page_8321 = dp_ret2;
                data_bank_8321 = db_ret2;
                goto shared_8321;
            } else {
                direct_page_83212 = dp_ret2;
                data_bank_83212 = db_ret2;
                goto shared_8321_1;
            }
        }
    } else {
        r->a = value5 & 0x1FFF;
        r->x = value5 & 0x1FFF;
        r->z = (value5 & 0x1FFF) == 0;
        r->n = value5 & 0x1FFF & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x8320, 0x01800F); GUARD_JSL(c, sp_call, 0x8320); } /* cast_actor_request_public_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret5 = r->xf;
        if (m_ret2) {
            if (x_ret5) {
                direct_page_83213 = dp_ret3;
                data_bank_83213 = db_ret3;
                goto shared_8321_2;
            } else {
                direct_page_83214 = dp_ret3;
                data_bank_83214 = db_ret3;
                goto shared_8321_3;
            }
        } else {
            if (x_ret5) {
                direct_page_8321 = dp_ret3;
                data_bank_8321 = db_ret3;
                goto shared_8321;
            } else {
                direct_page_83212 = dp_ret3;
                data_bank_83212 = db_ret3;
                goto shared_8321_1;
            }
        }
    }
    shared_8321:;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_8321;
    r->dp = direct_page_8321;
    RETURN_RTS(c);
    shared_8321_1:;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_83212;
    r->dp = direct_page_83212;
    RETURN_RTS(c);
    shared_8321_2:;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_83213;
    r->dp = direct_page_83213;
    RETURN_RTS(c);
    shared_8321_3:;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_83214;
    r->dp = direct_page_83214;
    RETURN_RTS(c);
}

/* C282E4 cast_selected_spell_at_parent_target_and_execute_success   [class B, 62 bytes, 26 instructions]
 * Source: src/rom/cast_selected_spell_at_parent_target_and_execute_success.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void cast_selected_spell_at_parent_target_and_execute_success_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint16_t direct_page_8321 = 0;
    uint8_t data_bank_8321 = 0;
    uint16_t direct_page_83212 = 0;
    uint8_t data_bank_83212 = 0;
    uint16_t direct_page_83213 = 0;
    uint8_t data_bank_83213 = 0;
    uint16_t direct_page_83214 = 0;
    uint8_t data_bank_83214 = 0;
    RAM8(0x0397) = a;
    uint8_t value = RAM8(0x00B0 + RAM16(BATTLE_DEFENCE_WORK));
    RAM8(0x0395) = value;
    RAM8(0x0170 + ((a_hi << 8) | value)) = RAM8(0x0397);
    RAM8(0x0176 + ((a_hi << 8) | value)) = 1;
    RAM8(0x0177 + ((a_hi << 8) | value)) = 0;
    uint8_t value3 = RAM8(0x00A9 + ((a_hi << 8) | value));
    RAM8(0x0178 + ((a_hi << 8) | value)) = (uint8_t)(value3 + 1);
    RAM8(0x0179 + ((a_hi << 8) | value)) = 0;
    RAM8(0x017A + ((a_hi << 8) | value)) = 0;
    uint16_t value4 = RAM16(0x0395);
    r->a = (a_hi << 8) | (uint8_t)(value3 + 1);
    r->x = value4;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8311, 0xC0001B); GUARD_JSL(c, sp_call, 0x8311); } /* cast_spell_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    if ((a_all & 0xFF) != 0) {
        if (x_ret) {
            direct_page_8321 = dp_ret;
            data_bank_8321 = db_ret;
            goto shared_8321;
        } else {
            direct_page_83212 = dp_ret;
            data_bank_83212 = db_ret;
            goto shared_8321_1;
        }
    }
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
    if (x_ret) {
        r->a = value5 & 0x1FFF;
        r->x = (uint8_t)(value5 & 0x1FFF);
        r->y = (uint8_t)y_ret;
        r->z = (uint8_t)(value5 & 0x1FFF) == 0;
        r->n = (uint8_t)(value5 & 0x1FFF) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x8320, 0x01800F); GUARD_JSL(c, sp_call, 0x8320); } /* cast_actor_request_public_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        if (m_ret) {
            if (x_ret3) {
                direct_page_83213 = dp_ret2;
                data_bank_83213 = db_ret2;
                goto shared_8321_2;
            } else {
                direct_page_83214 = dp_ret2;
                data_bank_83214 = db_ret2;
                goto shared_8321_3;
            }
        } else {
            if (x_ret3) {
                direct_page_8321 = dp_ret2;
                data_bank_8321 = db_ret2;
                goto shared_8321;
            } else {
                direct_page_83212 = dp_ret2;
                data_bank_83212 = db_ret2;
                goto shared_8321_1;
            }
        }
    } else {
        r->a = value5 & 0x1FFF;
        r->x = value5 & 0x1FFF;
        r->z = (value5 & 0x1FFF) == 0;
        r->n = value5 & 0x1FFF & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x8320, 0x01800F); GUARD_JSL(c, sp_call, 0x8320); } /* cast_actor_request_public_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret5 = r->xf;
        if (m_ret2) {
            if (x_ret5) {
                direct_page_83213 = dp_ret3;
                data_bank_83213 = db_ret3;
                goto shared_8321_2;
            } else {
                direct_page_83214 = dp_ret3;
                data_bank_83214 = db_ret3;
                goto shared_8321_3;
            }
        } else {
            if (x_ret5) {
                direct_page_8321 = dp_ret3;
                data_bank_8321 = db_ret3;
                goto shared_8321;
            } else {
                direct_page_83212 = dp_ret3;
                data_bank_83212 = db_ret3;
                goto shared_8321_1;
            }
        }
    }
    shared_8321:;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_8321;
    r->dp = direct_page_8321;
    RETURN_RTS(c);
    shared_8321_1:;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_83212;
    r->dp = direct_page_83212;
    RETURN_RTS(c);
    shared_8321_2:;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_83213;
    r->dp = direct_page_83213;
    RETURN_RTS(c);
    shared_8321_3:;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_83214;
    r->dp = direct_page_83214;
    RETURN_RTS(c);
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void cast_selected_spell_at_parent_target_and_execute_success(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { cast_selected_spell_at_parent_target_and_execute_success_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { cast_selected_spell_at_parent_target_and_execute_success_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC282E4, SOM_RTS, "gen", cast_selected_spell_at_parent_target_and_execute_success, 0, 0, 1, -1, -1, 62, 26)

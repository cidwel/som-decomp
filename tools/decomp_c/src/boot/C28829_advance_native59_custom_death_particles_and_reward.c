#include "som_c.h"

/* C28829 advance_native59_custom_death_particles_and_reward   [class B, 54 bytes, 22 instructions]
 * Source: src/rom/advance_native59_custom_death_particles_and_reward.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void advance_native59_custom_death_particles_and_reward(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_883c = 0;
    uint8_t a_hi_883c = 0;
    uint16_t x_883c = 0;
    uint16_t y_883c = 0;
    bool overflow_883c = 0;
    uint16_t direct_page_883c = 0;
    uint8_t data_bank_883c = 0;
    uint8_t a_883c2 = 0;
    uint8_t a_hi_883c2 = 0;
    uint8_t x_883c2 = 0;
    uint8_t y_883c2 = 0;
    bool overflow_883c2 = 0;
    uint16_t direct_page_883c2 = 0;
    uint8_t data_bank_883c2 = 0;
    uint8_t a_8849 = 0;
    uint8_t a_hi_8849 = 0;
    uint16_t x_8849 = 0;
    uint16_t y_8849 = 0;
    bool zero_8849 = 0;
    bool negative_8849 = 0;
    bool overflow_8849 = 0;
    uint16_t direct_page_8849 = 0;
    uint8_t data_bank_8849 = 0;
    uint8_t a_88492 = 0;
    uint8_t a_hi_88492 = 0;
    uint8_t x_88492 = 0;
    uint8_t y_88492 = 0;
    bool zero_88492 = 0;
    bool negative_88492 = 0;
    bool overflow_88492 = 0;
    uint16_t direct_page_88492 = 0;
    uint8_t data_bank_88492 = 0;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    if (value2 != 0x18) {
        a_883c = (uint8_t)value2;
        a_hi_883c = value2 >> 8;
        x_883c = value;
        y_883c = y;
        overflow_883c = overflow;
        direct_page_883c = dp;
        data_bank_883c = 0x7E;
        goto shared_883C;
    }
    r->a = value2;
    r->x = value;
    r->c = value2 >= 0x18;
    r->z = value2 == 0x18;
    r->n = (uint16_t)(value2 - 0x18) & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8836, 0xC0006F); GUARD_JSL(c, sp_call, 0x8836); } /* public_actor_death_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x96 + value3);
        a_883c2 = (uint8_t)value4;
        a_hi_883c2 = value4 >> 8;
        x_883c2 = value3;
        y_883c2 = (uint8_t)y_ret;
        overflow_883c2 = overflow_ret;
        direct_page_883c2 = dp_ret;
        data_bank_883c2 = db_ret;
        goto shared_883C_1;
    } else {
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0x96 + value5);
        a_883c = (uint8_t)value6;
        a_hi_883c = value6 >> 8;
        x_883c = value5;
        y_883c = y_ret;
        overflow_883c = overflow_ret;
        direct_page_883c = dp_ret;
        data_bank_883c = db_ret;
        goto shared_883C;
    }
    shared_883C:;
    if (((a_hi_883c << 8) | a_883c) >= 0x30) {
        BUS16_SET(c, (data_bank_883c << 0x10) + 0xA7 + x_883c, 0);
        uint16_t value7 = BUS16_RDP(c, (data_bank_883c << 0x10) + 0x94 + x_883c);
        BUS16_RMW_SET(c, (data_bank_883c << 0x10) + 0x94 + x_883c, (uint16_t)(value7 + 1));
        BUS16_SET(c, (data_bank_883c << 0x10) + 0x96 + x_883c, 0);
        r->a = 0x8A00;
        r->x = x_883c;
        r->y = y_883c;
        r->c = ((a_hi_883c << 8) | a_883c) >= 0x30;
        r->z = 0;
        r->n = 1;
        r->v = overflow_883c;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank_883c;
        r->dp = direct_page_883c;
        { const uint16_t sp_call = r->sp; JSR(c, 0x885C, 0xC23963); GUARD_JSR(c, sp_call, 0x885C); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if ((((a_hi_883c << 8) | a_883c) & 3) != 0) {
        a_8849 = ((a_hi_883c << 8) | a_883c) & 3;
        a_hi_8849 = 0;
        x_8849 = x_883c;
        y_8849 = y_883c;
        zero_8849 = (((a_hi_883c << 8) | a_883c) & 3) == 0;
        negative_8849 = ((a_hi_883c << 8) | a_883c) & 3 & 0x8000;
        overflow_8849 = overflow_883c;
        direct_page_8849 = direct_page_883c;
        data_bank_8849 = data_bank_883c;
        goto shared_8849;
    }
    r->a = ((a_hi_883c << 8) | a_883c) & 3;
    r->x = x_883c;
    r->y = y_883c;
    r->c = ((a_hi_883c << 8) | a_883c) >= 0x30;
    r->z = (((a_hi_883c << 8) | a_883c) & 3) == 0;
    r->n = ((a_hi_883c << 8) | a_883c) & 3 & 0x8000;
    r->v = overflow_883c;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_883c;
    r->dp = direct_page_883c;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8848, 0xC20C33); GUARD_JSR(c, sp_call, 0x8848); } /* create_randomly_positioned_boss_death_explosion_actor */
    uint16_t a_all3 = r->a;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret3 = r->y;
    bool zero_ret3 = r->z;
    bool negative_ret3 = r->n;
    bool overflow_ret3 = r->v;
    a_8849 = (uint8_t)a_all3;
    a_hi_8849 = a_all3 >> 8;
    x_8849 = x_ret5;
    y_8849 = y_ret3;
    zero_8849 = zero_ret3;
    negative_8849 = negative_ret3;
    overflow_8849 = overflow_ret3;
    direct_page_8849 = direct_page_883c;
    data_bank_8849 = data_bank_883c;
    goto shared_8849;
    shared_883C_1:;
    if (((a_hi_883c2 << 8) | a_883c2) >= 0x30) {
        BUS16_SET(c, (data_bank_883c2 << 0x10) + 0xA7 + x_883c2, 0);
        uint16_t value8 = BUS16_RDP(c, (data_bank_883c2 << 0x10) + 0x94 + x_883c2);
        BUS16_RMW_SET(c, (data_bank_883c2 << 0x10) + 0x94 + x_883c2, (uint16_t)(value8 + 1));
        BUS16_SET(c, (data_bank_883c2 << 0x10) + 0x96 + x_883c2, 0);
        r->a = 0x8A00;
        r->x = x_883c2;
        r->y = y_883c2;
        r->c = ((a_hi_883c2 << 8) | a_883c2) >= 0x30;
        r->z = 0;
        r->n = 1;
        r->v = overflow_883c2;
        r->mf = 0;
        r->xf = 1;
        r->db = data_bank_883c2;
        r->dp = direct_page_883c2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x885C, 0xC23963); GUARD_JSR(c, sp_call, 0x885C); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if ((((a_hi_883c2 << 8) | a_883c2) & 3) != 0) {
        a_88492 = ((a_hi_883c2 << 8) | a_883c2) & 3;
        a_hi_88492 = 0;
        x_88492 = x_883c2;
        y_88492 = y_883c2;
        zero_88492 = (((a_hi_883c2 << 8) | a_883c2) & 3) == 0;
        negative_88492 = ((a_hi_883c2 << 8) | a_883c2) & 3 & 0x8000;
        overflow_88492 = overflow_883c2;
        direct_page_88492 = direct_page_883c2;
        data_bank_88492 = data_bank_883c2;
        goto shared_8849_1;
    }
    r->a = ((a_hi_883c2 << 8) | a_883c2) & 3;
    r->x = x_883c2;
    r->y = y_883c2;
    r->c = ((a_hi_883c2 << 8) | a_883c2) >= 0x30;
    r->z = (((a_hi_883c2 << 8) | a_883c2) & 3) == 0;
    r->n = ((a_hi_883c2 << 8) | a_883c2) & 3 & 0x8000;
    r->v = overflow_883c2;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_883c2;
    r->dp = direct_page_883c2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8848, 0xC20C33); GUARD_JSR(c, sp_call, 0x8848); } /* create_randomly_positioned_boss_death_explosion_actor */
    uint16_t a_all5 = r->a;
    uint16_t x_ret8 = r->x;
    uint16_t y_ret5 = r->y;
    bool zero_ret5 = r->z;
    bool negative_ret5 = r->n;
    bool overflow_ret5 = r->v;
    a_8849 = (uint8_t)a_all5;
    a_hi_8849 = a_all5 >> 8;
    x_8849 = x_ret8;
    y_8849 = y_ret5;
    zero_8849 = zero_ret5;
    negative_8849 = negative_ret5;
    overflow_8849 = overflow_ret5;
    direct_page_8849 = direct_page_883c2;
    data_bank_8849 = data_bank_883c2;
    goto shared_8849;
    shared_8849:;
    r->a = (a_hi_8849 << 8) | a_8849;
    r->x = x_8849;
    r->y = y_8849;
    r->z = zero_8849;
    r->n = negative_8849;
    r->v = overflow_8849;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_8849;
    r->dp = direct_page_8849;
    { const uint16_t sp_call = r->sp; JSR(c, 0x884B, 0xC20C89); GUARD_JSR(c, sp_call, 0x884B); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
    shared_8849_1:;
    r->a = (a_hi_88492 << 8) | a_88492;
    r->x = x_88492;
    r->y = y_88492;
    r->z = zero_88492;
    r->n = negative_88492;
    r->v = overflow_88492;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_88492;
    r->dp = direct_page_88492;
    { const uint16_t sp_call = r->sp; JSR(c, 0x884B, 0xC20C89); GUARD_JSR(c, sp_call, 0x884B); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28829, SOM_RTS, "gen", advance_native59_custom_death_particles_and_reward, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 54, 22)

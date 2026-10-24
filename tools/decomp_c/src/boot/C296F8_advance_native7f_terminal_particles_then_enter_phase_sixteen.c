#include "som_c.h"

/* C296F8 advance_native7f_terminal_particles_then_enter_phase_sixteen   [class B, 131 bytes, 48 instructions]
 * Source: src/rom/advance_native7f_terminal_particles_then_enter_phase_sixteen.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void advance_native7f_terminal_particles_then_enter_phase_sixteen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_970d = 0;
    uint8_t a_hi_970d = 0;
    uint16_t x_970d = 0;
    uint16_t y_970d = 0;
    bool overflow_970d = 0;
    uint16_t direct_page_970d = 0;
    uint8_t data_bank_970d = 0;
    uint8_t a_970d2 = 0;
    uint8_t a_hi_970d2 = 0;
    uint8_t x_970d2 = 0;
    uint8_t y_970d2 = 0;
    bool overflow_970d2 = 0;
    uint16_t direct_page_970d2 = 0;
    uint8_t data_bank_970d2 = 0;
    uint8_t a_971a = 0;
    uint8_t a_hi_971a = 0;
    uint16_t x_971a = 0;
    uint16_t y_971a = 0;
    bool zero_971a = 0;
    bool negative_971a = 0;
    bool overflow_971a = 0;
    uint16_t direct_page_971a = 0;
    uint8_t data_bank_971a = 0;
    uint8_t a_971a2 = 0;
    uint8_t a_hi_971a2 = 0;
    uint8_t x_971a2 = 0;
    uint8_t y_971a2 = 0;
    bool zero_971a2 = 0;
    bool negative_971a2 = 0;
    bool overflow_971a2 = 0;
    uint16_t direct_page_971a2 = 0;
    uint8_t data_bank_971a2 = 0;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    if (value2 != 0x18) {
        a_970d = (uint8_t)value2;
        a_hi_970d = value2 >> 8;
        x_970d = value;
        y_970d = y;
        overflow_970d = overflow;
        direct_page_970d = dp;
        data_bank_970d = 0x7E;
        goto shared_970D;
    }
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    r->a = value2;
    r->x = value3;
    r->c = value2 >= 0x18;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x9707, 0xC0006F); GUARD_JSL(c, sp_call, 0x9707); } /* public_actor_death_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    if (x_ret) {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0x96 + value4);
        a_970d2 = (uint8_t)value5;
        a_hi_970d2 = value5 >> 8;
        x_970d2 = value4;
        y_970d2 = (uint8_t)y_ret;
        overflow_970d2 = overflow_ret;
        direct_page_970d2 = dp_ret;
        data_bank_970d2 = db_ret;
        goto shared_970D_1;
    } else {
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x96 + value6);
        a_970d = (uint8_t)value7;
        a_hi_970d = value7 >> 8;
        x_970d = value6;
        y_970d = y_ret;
        overflow_970d = overflow_ret;
        direct_page_970d = dp_ret;
        data_bank_970d = db_ret;
        goto shared_970D;
    }
    shared_970D:;
    if (((a_hi_970d << 8) | a_970d) >= 0x34) {
        BUS16_SET(c, (data_bank_970d << 0x10) + 0xA7 + x_970d, 0);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0x94 + x_970d, 0x10);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0x96 + x_970d, 0);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0xB0 + x_970d, 0x80);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0xB2 + x_970d, 0x80);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0xB4 + x_970d, 0);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0xB6 + x_970d, 0);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0xB8 + x_970d, 0);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0xBA + x_970d, 0);
        BUS16_SET(c, (data_bank_970d << 0x10) + 0xBC + x_970d, 0);
        r->a = 0x01E0;
        r->x = 0x86;
        r->y = 4;
        r->c = ((a_hi_970d << 8) | a_970d) >= 0x34;
        r->z = 0;
        r->n = 0;
        r->v = overflow_970d;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank_970d;
        r->dp = direct_page_970d;
        { const uint16_t sp_call = r->sp; JSR(c, 0x974E, 0xC2272D); GUARD_JSR(c, sp_call, 0x974E); } /* allocate_boss_palette_transition_object */
        r->a = 0x01E0;
        r->x = 0x86;
        r->y = 5;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x975A, 0xC2272D); GUARD_JSR(c, sp_call, 0x975A); } /* allocate_boss_palette_transition_object */
        r->a = 0x01E0;
        r->x = 0x86;
        r->y = 6;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9766, 0xC2272D); GUARD_JSR(c, sp_call, 0x9766); } /* allocate_boss_palette_transition_object */
        r->a = 0x01E0;
        r->x = 0x86;
        r->y = 7;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9772, 0xC2272D); GUARD_JSR(c, sp_call, 0x9772); } /* allocate_boss_palette_transition_object */
        r->a = 0x8A00;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9778, 0xC23963); GUARD_JSR(c, sp_call, 0x9778); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if ((((a_hi_970d << 8) | a_970d) & 3) != 0) {
        a_971a = ((a_hi_970d << 8) | a_970d) & 3;
        a_hi_971a = 0;
        x_971a = x_970d;
        y_971a = y_970d;
        zero_971a = (((a_hi_970d << 8) | a_970d) & 3) == 0;
        negative_971a = ((a_hi_970d << 8) | a_970d) & 3 & 0x8000;
        overflow_971a = overflow_970d;
        direct_page_971a = direct_page_970d;
        data_bank_971a = data_bank_970d;
        goto shared_971A;
    }
    r->a = ((a_hi_970d << 8) | a_970d) & 3;
    r->x = x_970d;
    r->y = y_970d;
    r->c = ((a_hi_970d << 8) | a_970d) >= 0x34;
    r->z = (((a_hi_970d << 8) | a_970d) & 3) == 0;
    r->n = ((a_hi_970d << 8) | a_970d) & 3 & 0x8000;
    r->v = overflow_970d;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_970d;
    r->dp = direct_page_970d;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9719, 0xC20C33); GUARD_JSR(c, sp_call, 0x9719); } /* create_randomly_positioned_boss_death_explosion_actor */
    uint16_t a_all7 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret7 = r->y;
    bool zero_ret7 = r->z;
    bool negative_ret7 = r->n;
    bool overflow_ret7 = r->v;
    a_971a = (uint8_t)a_all7;
    a_hi_971a = a_all7 >> 8;
    x_971a = x_ret9;
    y_971a = y_ret7;
    zero_971a = zero_ret7;
    negative_971a = negative_ret7;
    overflow_971a = overflow_ret7;
    direct_page_971a = direct_page_970d;
    data_bank_971a = data_bank_970d;
    goto shared_971A;
    shared_970D_1:;
    if (((a_hi_970d2 << 8) | a_970d2) >= 0x34) {
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0xA7 + x_970d2, 0);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0x94 + x_970d2, 0x10);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0x96 + x_970d2, 0);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0xB0 + x_970d2, 0x80);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0xB2 + x_970d2, 0x80);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0xB4 + x_970d2, 0);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0xB6 + x_970d2, 0);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0xB8 + x_970d2, 0);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0xBA + x_970d2, 0);
        BUS16_SET(c, (data_bank_970d2 << 0x10) + 0xBC + x_970d2, 0);
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    if ((((a_hi_970d2 << 8) | a_970d2) & 3) != 0) {
        a_971a2 = ((a_hi_970d2 << 8) | a_970d2) & 3;
        a_hi_971a2 = 0;
        x_971a2 = x_970d2;
        y_971a2 = y_970d2;
        zero_971a2 = (((a_hi_970d2 << 8) | a_970d2) & 3) == 0;
        negative_971a2 = ((a_hi_970d2 << 8) | a_970d2) & 3 & 0x8000;
        overflow_971a2 = overflow_970d2;
        direct_page_971a2 = direct_page_970d2;
        data_bank_971a2 = data_bank_970d2;
        goto shared_971A_1;
    }
    r->a = ((a_hi_970d2 << 8) | a_970d2) & 3;
    r->x = x_970d2;
    r->y = y_970d2;
    r->c = ((a_hi_970d2 << 8) | a_970d2) >= 0x34;
    r->z = (((a_hi_970d2 << 8) | a_970d2) & 3) == 0;
    r->n = ((a_hi_970d2 << 8) | a_970d2) & 3 & 0x8000;
    r->v = overflow_970d2;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_970d2;
    r->dp = direct_page_970d2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9719, 0xC20C33); GUARD_JSR(c, sp_call, 0x9719); } /* create_randomly_positioned_boss_death_explosion_actor */
    uint16_t a_all8 = r->a;
    uint16_t x_ret10 = r->x;
    uint16_t y_ret8 = r->y;
    bool zero_ret8 = r->z;
    bool negative_ret8 = r->n;
    bool overflow_ret8 = r->v;
    a_971a = (uint8_t)a_all8;
    a_hi_971a = a_all8 >> 8;
    x_971a = x_ret10;
    y_971a = y_ret8;
    zero_971a = zero_ret8;
    negative_971a = negative_ret8;
    overflow_971a = overflow_ret8;
    direct_page_971a = direct_page_970d2;
    data_bank_971a = data_bank_970d2;
    goto shared_971A;
    shared_971A:;
    r->a = (a_hi_971a << 8) | a_971a;
    r->x = x_971a;
    r->y = y_971a;
    r->z = zero_971a;
    r->n = negative_971a;
    r->v = overflow_971a;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_971a;
    r->dp = direct_page_971a;
    { const uint16_t sp_call = r->sp; JSR(c, 0x971C, 0xC20C89); GUARD_JSR(c, sp_call, 0x971C); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
    shared_971A_1:;
    r->a = (a_hi_971a2 << 8) | a_971a2;
    r->x = x_971a2;
    r->y = y_971a2;
    r->z = zero_971a2;
    r->n = negative_971a2;
    r->v = overflow_971a2;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_971a2;
    r->dp = direct_page_971a2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x971C, 0xC20C89); GUARD_JSR(c, sp_call, 0x971C); } /* rotate_fourteen_colors_in_each_selected_boss_palette */
    r->c = 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC296F8, SOM_RTS, "gen", advance_native7f_terminal_particles_then_enter_phase_sixteen, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 131, 48)

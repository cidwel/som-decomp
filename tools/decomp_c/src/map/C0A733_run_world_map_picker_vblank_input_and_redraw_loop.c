#include "som_c.h"

/* SOM_POLL_HOOK */


/* Wait detection of the harness for a routine that waits for the NMI: the interpreter (rt/somrt.c spin_check) delivers the next recorded interrupt when a backward
 * branch is reached twice with the same registers and no memory change in between.  This is the same test, called at the same backward branches of C0A733 with the
 * register state the original has there; nothing else in the runtime changes (the generic poll rules of the C hook stay as they are). */
static int a733_spin(SomCtx *c, uint32_t target, uint16_t a, uint16_t x, uint16_t y, bool n, bool v, bool z, bool cf, uint16_t dp, uint8_t db)
{
    Cpu *r = &c->cpu;
    if (!(c->ev_mode == 2 || c->ev_mode == 3) || c->ev_next >= c->ev_n) return 0;
    const uint32_t pc = ((uint32_t)r->k << 16) | target;
    const uint8_t p = (uint8_t)((n << 7) | (v << 6) | (1 << 5) | (1 << 4) | (r->d << 3) | (r->i << 2) | (z << 1) | cf);
    const unsigned h = (pc * 2654435761u ^ a * 40503u ^ x * 69069u ^ y * 1103515245u ^ r->sp) >> 7 & 63;
    typeof(c->spin[0]) *e = &c->spin[h];
    if (e->epoch == c->wepoch && e->pc == pc && e->a == a && e->x == x && e->y == y && e->s == r->sp && e->d == dp && e->p == p && e->db == db) {
        e->epoch = ~0ull;
        som_deliver_event(c, &c->ev[c->ev_next++]);
        return 1;
    }
    *e = (typeof(*e)){ pc, a, x, y, r->sp, dp, p, db, c->wepoch };
    return 0;
}

/* C0A733 run_world_map_picker_vblank_input_and_redraw_loop   [class D, 101 bytes, 48 instructions]
 * Source: src/rom/run_world_map_picker_vblank_input_and_redraw_loop.s
 * Entry: M=8 bit X=any DB=$00 D=$0000 (the routine zero-extends X and Y at C0A744 before it uses them).  Callers read: BXYCV.
 */
static void run_world_map_picker_vblank_input_and_redraw_loop(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 3;
    uint64_t loop_guard = 0;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_a735 = 0;
    uint16_t x_a735 = 0;
    uint16_t y_a735 = 0;
    bool carry_a735 = 0;
    bool overflow_a735 = 0;
    uint8_t a_hi_a73a = 0;
    uint16_t x_a73a = 0;
    uint16_t y_a73a = 0;
    bool carry_a73a = 0;
    bool overflow_a73a = 0;
    uint8_t a_hi_a744 = 0;
    uint16_t x_a744 = 0;
    uint16_t y_a744 = 0;
    bool carry_a744 = 0;
    bool overflow_a744 = 0;
    uint8_t a_hi_a748 = 0;
    uint8_t x_a748 = 0;
    uint8_t y_a748 = 0;
    bool carry_a748 = 0;
    bool overflow_a748 = 0;
    uint16_t direct_page_a748 = 0;
    uint8_t data_bank_a748 = 0;
    uint8_t a_a750 = 0;
    uint8_t a_hi_a750 = 0;
    uint8_t x_a750 = 0;
    uint8_t y_a750 = 0;
    bool carry_a750 = 0;
    bool overflow_a750 = 0;
    uint16_t direct_page_a750 = 0;
    uint8_t data_bank_a750 = 0;
    uint8_t a_hi_a7442 = 0;
    uint8_t x_a7442 = 0;
    uint8_t y_a7442 = 0;
    bool carry_a7442 = 0;
    bool overflow_a7442 = 0;
    uint16_t direct_page_a744 = 0;
    uint8_t data_bank_a744 = 0;
    uint8_t a_a767 = 0;
    uint8_t a_hi_a767 = 0;
    uint8_t x_a767 = 0;
    uint8_t y_a767 = 0;
    bool carry_a767 = 0;
    uint16_t direct_page_a767 = 0;
    uint8_t data_bank_a767 = 0;
    uint8_t a_a761 = 0;
    uint8_t a_hi_a761 = 0;
    uint8_t x_a761 = 0;
    uint8_t y_a761 = 0;
    bool carry_a761 = 0;
    uint16_t direct_page_a761 = 0;
    uint8_t data_bank_a761 = 0;
    a_hi_a735 = a_hi;
    x_a735 = x;
    y_a735 = y;
    carry_a735 = carry;
    overflow_a735 = overflow;
    shared_A735:;
    LOOP_GUARD(loop_guard);
    uint8_t value = BUS8(c, 0x004210);
    if (!(value & 0x80)) {
        goto shared_A735;
    }
    a_hi_a73a = a_hi_a735;
    x_a73a = x_a735;
    y_a73a = y_a735;
    carry_a73a = carry_a735;
    overflow_a73a = overflow_a735;
    goto shared_A73A;
    shared_A73A:;
    LOOP_GUARD(loop_guard);
    uint8_t value2 = BUS8(c, 0x004210);
    if (value2 & 0x80) {
        goto shared_A73A;
    }
    BUS8_SET(c, 0x004200, 0x81);
    a_hi_a744 = a_hi_a73a;
    x_a744 = x_a73a;
    y_a744 = y_a73a;
    carry_a744 = carry_a73a;
    overflow_a744 = overflow_a73a;
    goto shared_A744;
    shared_A744:;
    LOOP_GUARD(loop_guard);
    a_hi_a748 = a_hi_a744;
    x_a748 = (uint8_t)x_a744;
    y_a748 = (uint8_t)y_a744;
    carry_a748 = carry_a744;
    overflow_a748 = overflow_a744;
    direct_page_a748 = 0;
    data_bank_a748 = 0;
    goto shared_A748;
    shared_A748:;
    LOOP_GUARD(loop_guard);
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(direct_page_a748 + 0x0E));
    if (value3 != 0) {
        a733_spin(c, 0xA748, (a_hi_a748 << 8) | value3, x_a748, y_a748, value3 & 0x80, overflow_a748, 0, carry_a748, direct_page_a748, data_bank_a748);
        goto shared_A748;
    }
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(direct_page_a748 + 0x0C));
    if (value4 != 0) {
        a733_spin(c, 0xA748, (a_hi_a748 << 8) | value4, x_a748, y_a748, value4 & 0x80, overflow_a748, 0, carry_a748, direct_page_a748, data_bank_a748);
        goto shared_A748;
    }
    a_a750 = value4;
    a_hi_a750 = a_hi_a748;
    x_a750 = x_a748;
    y_a750 = y_a748;
    carry_a750 = carry_a748;
    overflow_a750 = overflow_a748;
    direct_page_a750 = direct_page_a748;
    data_bank_a750 = data_bank_a748;
    goto shared_A750;
    shared_A750:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_a750 << 8) | a_a750;
    r->x = x_a750;
    r->y = y_a750;
    r->c = carry_a750;
    r->v = overflow_a750;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_a750;
    r->dp = direct_page_a750;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA752, 0xC0A7D8); GUARD_JSR(c, sp_call, 0xA752); } /* consume_complete_world_map_picker_rotation_motion_and_buttons */
    uint16_t a_all = r->a;
    uint8_t x_ret = r->x;
    uint8_t y_ret = r->y;
    bool carry_ret = r->c;
    if (!carry_ret) {
        if ((uint8_t)a_all >= 1) {
            r->c = (uint8_t)a_all >= 1;
            r->z = (uint8_t)a_all == 1;
            r->n = (uint8_t)((uint8_t)a_all - 1) & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA76F, 0xC0AA14); GUARD_JSR(c, sp_call, 0xA76F); } /* construct_all_world_map_picker_image_rows */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            uint16_t a_all2 = r->a;
            uint8_t x_ret2 = r->x;
            uint8_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            a_hi_a7442 = a_all2 >> 8;
            x_a7442 = x_ret2;
            y_a7442 = y_ret2;
            carry_a7442 = carry_ret2;
            overflow_a7442 = overflow_ret2;
            direct_page_a744 = dp_ret;
            data_bank_a744 = db_ret;
            a733_spin(c, 0xA744, a_all2, x_ret2, y_ret2, r->n, overflow_ret2, r->z, carry_ret2, dp_ret, db_ret);
            goto shared_A744_1;
        }
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(direct_page_a750 + 0xF4));
        if ((value5 & 1) == 0) {
            a_a767 = 1;
            a_hi_a767 = a_all >> 8;
            x_a767 = x_ret;
            y_a767 = y_ret;
            carry_a767 = (uint8_t)a_all >= 1;
            direct_page_a767 = direct_page_a750;
            data_bank_a767 = data_bank_a750;
            goto shared_A767;
        }
        a_a761 = 1;
        a_hi_a761 = a_all >> 8;
        x_a761 = x_ret;
        y_a761 = y_ret;
        carry_a761 = (uint8_t)a_all >= 1;
        direct_page_a761 = direct_page_a750;
        data_bank_a761 = data_bank_a750;
        goto shared_A761;
    }
    if ((uint8_t)a_all < 1) {
        BUS8_SET(c, (data_bank_a750 << 0x10) + 0x0102, RAM8(0x0000 + sp0 - 2));
        BUS8_SET(c, (data_bank_a750 << 0x10) + 0x0101, RAM8(0x0000 + sp0 - 1));
        BUS8_SET(c, (data_bank_a750 << 0x10) + 0x0100, RAM8(0x0000 + sp0));
        r->c = (uint8_t)a_all >= 1;
        r->mf = 1;
        r->xf = 1;
        r->sp += 3;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (data_bank_a750 << 0x10) + 0x0102, RAM8(0x0000 + sp0 - 2));
    BUS8_SET(c, (data_bank_a750 << 0x10) + 0x0101, RAM8(0x0000 + sp0 - 1));
    uint8_t value11 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (data_bank_a750 << 0x10) + 0x0100, value11);
    r->a = (a_all >> 8 << 8) | value11;
    r->c = (uint8_t)a_all >= 1;
    r->z = value11 == 0;
    r->n = value11 & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->sp += 3;
    TAIL_CALL(c, 0xC0ABB3, SOM_RTS); /* initialize_and_run_confirmed_world_map_survey_scene */
    shared_A744_1:;
    LOOP_GUARD(loop_guard);
    a_hi_a748 = a_hi_a7442;
    x_a748 = x_a7442;
    y_a748 = y_a7442;
    carry_a748 = carry_a7442;
    overflow_a748 = overflow_a7442;
    direct_page_a748 = direct_page_a744;
    data_bank_a748 = data_bank_a744;
    goto shared_A748;
    shared_A767:;
    LOOP_GUARD(loop_guard);
    uint8_t value12 = BUS8_RDP(c, (uint16_t)(direct_page_a767 + 0xF4));
    if ((a_a767 & value12) == 0) {
        a733_spin(c, 0xA767, (a_hi_a767 << 8) | a_a767, x_a767, y_a767, value12 & 0x80, value12 & 0x40, 1, carry_a767, direct_page_a767, data_bank_a767);
        goto shared_A767;
    }
    a_a750 = a_a767;
    a_hi_a750 = a_hi_a767;
    x_a750 = x_a767;
    y_a750 = y_a767;
    carry_a750 = carry_a767;
    overflow_a750 = value12 & 0x40;
    direct_page_a750 = direct_page_a767;
    data_bank_a750 = data_bank_a767;
    a733_spin(c, 0xA750, (a_hi_a750 << 8) | a_a750, x_a750, y_a750, value12 & 0x80, overflow_a750, 0, carry_a750, direct_page_a750, data_bank_a750);
    goto shared_A750;
    shared_A761:;
    LOOP_GUARD(loop_guard);
    uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page_a761 + 0xF4));
    if ((a_a761 & value13) != 0) {
        a733_spin(c, 0xA761, (a_hi_a761 << 8) | a_a761, x_a761, y_a761, value13 & 0x80, value13 & 0x40, 0, carry_a761, direct_page_a761, data_bank_a761);
        goto shared_A761;
    }
    a_a750 = a_a761;
    a_hi_a750 = a_hi_a761;
    x_a750 = x_a761;
    y_a750 = y_a761;
    carry_a750 = carry_a761;
    overflow_a750 = value13 & 0x40;
    direct_page_a750 = direct_page_a761;
    data_bank_a750 = data_bank_a761;
    a733_spin(c, 0xA750, (a_hi_a750 << 8) | a_a750, x_a750, y_a750, value13 & 0x80, overflow_a750, 1, carry_a750, direct_page_a750, data_bank_a750);
    goto shared_A750;
}
SOM_REGISTER(0xC0A733, SOM_RTS, "hand", run_world_map_picker_vblank_input_and_redraw_loop, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 3, -1, -1, 101, 48)

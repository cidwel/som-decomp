#include "som_c.h"

/* C0B03F initialize_main_map_loop_before_native_nmi_wait   [class D, 984 bytes, 455 instructions]
 * Source: src/rom/initialize_main_map_loop_before_native_nmi_wait.s
 * Documented in docs/ui-native-map-entry-prefix.md
 * Entry: M=8 bit X=any DB=any D=any.  Callers read: ABXYCV.
 */
/* The frame loop never returns: an exit window (capture option exit=C0B08A@5) ends at the Nth arrival of the original code at the loop-back BRA, before it runs.
 * inc = A.low after INC A; reset = the CMP #$05 / BCC fell through (LDA #$00 / STA $56 ran, which leaves C from the CMP and N/Z from the LDA). */
static inline int frame_loop_exit(SomCtx *c, uint16_t a_all, uint8_t inc, uint16_t x, uint16_t y, bool v, uint8_t db, uint16_t dp, bool reset)
{
    Cpu *r = &c->cpu;
    if (!c->nexit) return 0;
    r->a = (a_all & 0xFF00) | (reset ? 0 : inc);
    r->x = x; r->y = y; r->v = v; r->mf = 1; r->db = db; r->dp = dp;
    r->c = inc >= 5;
    if (reset) { r->n = 0; r->z = 1; } else { const uint8_t d = (uint8_t)(inc - 5); r->n = d >> 7; r->z = d == 0; }
    return som_spin_exit(c, 0xC0B08A);
}

static void initialize_main_map_loop_before_native_nmi_wait(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    uint16_t sp0 = r->sp;
    uint8_t a = r->a & 0xFF;
    r->sp = 0x01FF;
    c->routine_ret = 0; /* S was reset: the entry S says nothing about the returns of the callees */
    sp0 = r->sp;
    r->x = 0x01FF;
    r->xf = 0;
    r->i = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB048, 0xC087C4); GUARD_JSR(c, sp_call, 0xB048); } /* blank_display_disable_interrupts_and_clear_windows_for_map_entry */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB04B, 0xC0BC9B); GUARD_JSR(c, sp_call, 0xB04B); } /* clear_map_direct_page_scratch_preserving_first_word */
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB04E, 0xC0BC0B); GUARD_JSR(c, sp_call, 0xB04E); } /* initialize_complete_map_entry */
    uint16_t dp_ret = r->dp;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB051, 0xC0E9F8); GUARD_JSR(c, sp_call, 0xB051); } /* refresh_three_party_weapon_graphics_with_saved_bank */
    { const uint16_t sp_call = r->sp; JSR(c, 0xB054, 0xC0BEAA); GUARD_JSR(c, sp_call, 0xB054); } /* request_actual_map_entry_event_and_restore_deferred_party_actor */
    uint8_t db_ret3 = r->db;
    uint16_t a_all5 = r->a;
    uint16_t x_ret7 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    for (;;) {
        uint8_t value = BUS8(c, (db_ret3 << 0x10) + 0x4210);
        if (!(!(value & 0x80))) break;
    }
    uint8_t value2 = BUS8(c, (db_ret3 << 0x10) + 0x4210);
    BUS8_SET(c, (db_ret3 << 0x10) + 0x4200, 0xB1);
    RAM8(0x00EC + dp_ret) = 2;
    a = 0x02; /* LDA #$02 / STA $EC: the accumulator the frame loop starts with */
    bool overflow1 = value2 & 0x40;
    for (;;) {
        uint8_t value3 = RAM8(0x00EC + dp_ret);
        overflow1 = value3 & 0x40;
        if (!((value3 & 2) != 0)) break;
    }
    RAM8(0x0056 + dp_ret) = 0;
    RAM8(0x0057 + dp_ret) = 0;
    uint8_t a_hi1 = a_all5 >> 8;
    uint16_t x1 = (uint8_t)x_ret7;
    uint16_t y1 = (uint8_t)y_ret3;
    bool carry1 = carry_ret3;
    bool overflow2 = overflow1;
    uint8_t data_bank = db_ret3;
    bool i1 = r->i; /* SEI at the entry; the frame callee may clear it */
    uint16_t direct_page = dp_ret;
    uint8_t width_pass = 0;
    for (;;) {
        if (width_pass == 0) {
            r->a = (a_hi1 << 8) | a;
            r->x = (uint8_t)x1;
            r->y = (uint8_t)y1;
            r->c = carry1;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 1;
            r->db = data_bank;
            r->dp = dp_ret;
            r->i = i1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB072, 0xC0B08C); GUARD_JSR(c, sp_call, 0xB072); } /* advance_complete_main_map_frame_and_finalize_native_oam */
            i1 = r->i; /* I as the frame callee left it: the next pass starts with it */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret4 = r->db;
            uint16_t a_all6 = r->a;
            uint16_t x_ret8 = r->x;
            uint16_t y_ret4 = r->y;
            bool overflow_ret4 = r->v;
            RAM8(0x00EC + dp_ret2) |= 1;
            bool overflow3 = overflow_ret4;
            for (;;) {
                uint8_t value5 = RAM8(0x00EC + dp_ret2);
                overflow3 = value5 & 0x40;
                if (!((value5 & 1) != 0)) break;
            }
            uint8_t value6 = RAM8(0x0056 + dp_ret2);
            RAM8(0x0056 + dp_ret2) = (uint8_t)(value6 + 1);
            if ((uint8_t)(value6 + 1) < 5) {
                if (frame_loop_exit(c, a_all6, (uint8_t)(value6 + 1), x_ret8, y_ret4, overflow3, db_ret4, dp_ret2, false)) return;
                a_hi1 = a_all6 >> 8;
                x1 = x_ret8;
                y1 = y_ret4;
                carry1 = (uint8_t)(value6 + 1) >= 5;
                overflow2 = overflow3;
                data_bank = db_ret4;
                direct_page = dp_ret2;
                width_pass = 2;
                continue;
            }
            RAM8(0x0056 + dp_ret2) = 0;
            if (frame_loop_exit(c, a_all6, (uint8_t)(value6 + 1), x_ret8, y_ret4, overflow3, db_ret4, dp_ret2, true)) return;
            a_hi1 = a_all6 >> 8;
            x1 = x_ret8;
            y1 = y_ret4;
            carry1 = (uint8_t)(value6 + 1) >= 5;
            overflow2 = overflow3;
            data_bank = db_ret4;
            direct_page = dp_ret2;
            width_pass = 2;
            continue;
        } else if (width_pass == 1) {
            r->a = (a_hi1 << 8) | a;
            r->x = (uint8_t)x1;
            r->y = (uint8_t)y1;
            r->c = carry1;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->i = i1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB072, 0xC0B08C); GUARD_JSR(c, sp_call, 0xB072); } /* advance_complete_main_map_frame_and_finalize_native_oam */
            i1 = r->i; /* I as the frame callee left it: the next pass starts with it */
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret5 = r->db;
            uint16_t a_all7 = r->a;
            uint16_t x_ret9 = r->x;
            uint16_t y_ret5 = r->y;
            bool overflow_ret5 = r->v;
            RAM8(0x00EC + dp_ret3) |= 1;
            bool overflow4 = overflow_ret5;
            for (;;) {
                uint8_t value8 = RAM8(0x00EC + dp_ret3);
                overflow4 = value8 & 0x40;
                if (!((value8 & 1) != 0)) break;
            }
            uint8_t value9 = RAM8(0x0056 + dp_ret3);
            RAM8(0x0056 + dp_ret3) = (uint8_t)(value9 + 1);
            if ((uint8_t)(value9 + 1) < 5) {
                if (frame_loop_exit(c, a_all7, (uint8_t)(value9 + 1), x_ret9, y_ret5, overflow4, db_ret5, dp_ret3, false)) return;
                a_hi1 = a_all7 >> 8;
                x1 = x_ret9;
                y1 = y_ret5;
                carry1 = (uint8_t)(value9 + 1) >= 5;
                overflow2 = overflow4;
                data_bank = db_ret5;
                direct_page = dp_ret3;
                continue;
            }
            RAM8(0x0056 + dp_ret3) = 0;
            if (frame_loop_exit(c, a_all7, (uint8_t)(value9 + 1), x_ret9, y_ret5, overflow4, db_ret5, dp_ret3, true)) return;
            a_hi1 = a_all7 >> 8;
            x1 = x_ret9;
            y1 = y_ret5;
            carry1 = (uint8_t)(value9 + 1) >= 5;
            overflow2 = overflow4;
            data_bank = db_ret5;
            direct_page = dp_ret3;
            continue;
        } else {
            r->a = (a_hi1 << 8) | a;
            r->x = (uint8_t)x1;
            r->y = (uint8_t)y1;
            r->c = carry1;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = dp_ret;
            r->i = i1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB072, 0xC0B08C); GUARD_JSR(c, sp_call, 0xB072); } /* advance_complete_main_map_frame_and_finalize_native_oam */
            i1 = r->i; /* I as the frame callee left it: the next pass starts with it */
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret6 = r->db;
            uint16_t a_all8 = r->a;
            uint16_t x_ret10 = r->x;
            uint16_t y_ret6 = r->y;
            bool overflow_ret6 = r->v;
            RAM8(0x00EC + dp_ret4) |= 1;
            bool overflow5 = overflow_ret6;
            for (;;) {
                uint8_t value11 = RAM8(0x00EC + dp_ret4);
                overflow5 = value11 & 0x40;
                if (!((value11 & 1) != 0)) break;
            }
            uint8_t value12 = RAM8(0x0056 + dp_ret4);
            RAM8(0x0056 + dp_ret4) = (uint8_t)(value12 + 1);
            if ((uint8_t)(value12 + 1) < 5) {
                if (frame_loop_exit(c, a_all8, (uint8_t)(value12 + 1), x_ret10, y_ret6, overflow5, db_ret6, dp_ret4, false)) return;
                a_hi1 = a_all8 >> 8;
                x1 = x_ret10;
                y1 = y_ret6;
                carry1 = (uint8_t)(value12 + 1) >= 5;
                overflow2 = overflow5;
                data_bank = db_ret6;
                direct_page = dp_ret4;
                continue;
            }
            RAM8(0x0056 + dp_ret4) = 0;
            if (frame_loop_exit(c, a_all8, (uint8_t)(value12 + 1), x_ret10, y_ret6, overflow5, db_ret6, dp_ret4, true)) return;
            a_hi1 = a_all8 >> 8;
            x1 = x_ret10;
            y1 = y_ret6;
            carry1 = (uint8_t)(value12 + 1) >= 5;
            overflow2 = overflow5;
            data_bank = db_ret6;
            direct_page = dp_ret4;
            continue;
        }
    }
}
SOM_REGISTER(0xC0B03F, SOM_RTS, "hand", initialize_main_map_loop_before_native_nmi_wait, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 3010, 455)

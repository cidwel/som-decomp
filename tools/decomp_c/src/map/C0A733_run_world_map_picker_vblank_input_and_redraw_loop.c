#include "som_c.h"
/* SOM_POLL_HOOK */

/* C0A733 run_world_map_picker_vblank_input_and_redraw_loop   [class D, 101 bytes, 48 instructions]
 * Source: src/rom/run_world_map_picker_vblank_input_and_redraw_loop.s
 * Documented in docs/ui-native-world-map-picker-composition.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void run_world_map_picker_vblank_input_and_redraw_loop(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 3;
    uint64_t loop_guard = 0;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value = BUS8(c, 0x004210);
        if (!(!(value & 0x80))) break;
    }
    uint8_t a_hi2 = a_hi1;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value2 = BUS8(c, 0x004210);
        if (!(value2 & 0x80)) break;
    }
    BUS8_SET(c, 0x004200, 0x81);
    uint8_t a1 = 0x81;
    uint8_t a_hi3 = a_hi2;
    uint8_t x1 = x;
    uint8_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0;
    uint16_t direct_page = 0;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t a2 = a1;
        uint8_t a_hi4 = a_hi3;
        for (;;) {
            LOOP_GUARD(loop_guard);
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(direct_page + 0x0E));
            if (value3 != 0) {
                a2 = value3;
                continue;
            }
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(direct_page + 0x0C));
            a2 = value4;
            if (!(a2 != 0)) break;
        }
        uint8_t a3 = a2;
        uint8_t a_hi5 = a_hi4;
        uint8_t x2 = x1;
        uint8_t y2 = y1;
        bool carry2 = carry1;
        bool overflow2 = overflow1;
        for (;;) {
            LOOP_GUARD(loop_guard);
            r->a = (a_hi5 << 8) | a3;
            r->x = x2;
            r->y = y2;
            r->c = carry2;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 1;
            r->db = data_bank;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA752, 0xC0A7D8); GUARD_JSR(c, sp_call, 0xA752); } /* consume_complete_world_map_picker_rotation_motion_and_buttons */
            uint16_t a_all = r->a;
            uint8_t x_ret = r->x;
            uint8_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            if (!carry_ret) {
                if ((uint8_t)a_all >= 1) {
                    a3 = (uint8_t)a_all;
                    a_hi5 = a_all >> 8;
                    x2 = x_ret;
                    y2 = y_ret;
                    carry2 = (uint8_t)a_all >= 1;
                    overflow2 = overflow_ret;
                    break;
                }
                uint8_t value5 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF4));
                if ((value5 & 1) == 0) {
                    bool overflow3 = value5 & 0x40;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value6 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF4));
                        overflow3 = value6 & 0x40;
                        if (!((value6 & 1) == 0)) break;
                    }
                    a3 = 1;
                    a_hi5 = a_all >> 8;
                    x2 = x_ret;
                    y2 = y_ret;
                    carry2 = (uint8_t)a_all >= 1;
                    overflow2 = overflow3;
                    continue;
                }
                bool overflow4 = value5 & 0x40;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value7 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF4));
                    overflow4 = value7 & 0x40;
                    if (!((value7 & 1) != 0)) break;
                }
                a3 = 1;
                a_hi5 = a_all >> 8;
                x2 = x_ret;
                y2 = y_ret;
                carry2 = (uint8_t)a_all >= 1;
                overflow2 = overflow4;
                continue;
            }
            a1 = (uint8_t)a_all;
            a_hi3 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
            goto leave_loop_C0A744_4;
        }
        r->a = (a_hi5 << 8) | a3;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA76F, 0xC0AA14); GUARD_JSR(c, sp_call, 0xA76F); } /* construct_all_world_map_picker_image_rows */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        uint16_t a_all2 = r->a;
        uint8_t x_ret2 = r->x;
        uint8_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        a1 = (uint8_t)a_all2;
        a_hi3 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    leave_loop_C0A744_4:;
    if (a1 < 1) {
        BUS8_SET(c, (data_bank << 0x10) + 0x0102, RAM8(0x0000 + sp0 - 2));
        BUS8_SET(c, (data_bank << 0x10) + 0x0101, RAM8(0x0000 + sp0 - 1));
        uint8_t value10 = RAM8(0x0000 + sp0);
        BUS8_SET(c, (data_bank << 0x10) + 0x0100, value10);
        r->a = (a_hi3 << 8) | value10;
        r->x = x1;
        r->y = y1;
        r->c = a1 >= 1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp += 3;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (data_bank << 0x10) + 0x0102, RAM8(0x0000 + sp0 - 2));
    BUS8_SET(c, (data_bank << 0x10) + 0x0101, RAM8(0x0000 + sp0 - 1));
    uint8_t value13 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (data_bank << 0x10) + 0x0100, value13);
    r->a = (a_hi3 << 8) | value13;
    r->x = x1;
    r->y = y1;
    r->c = a1 >= 1;
    r->z = value13 == 0;
    r->n = value13 & 0x80;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp += 3;
    TAIL_CALL(c, 0xC0ABB3, SOM_RTS); /* initialize_and_run_confirmed_world_map_survey_scene */
}
SOM_REGISTER(0xC0A733, SOM_RTS, "gen", run_world_map_picker_vblank_input_and_redraw_loop, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 3, 1, 1, 101, 48)

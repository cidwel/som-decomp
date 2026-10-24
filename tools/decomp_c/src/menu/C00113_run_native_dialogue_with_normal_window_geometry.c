#include "som_c.h"

/* C00113 run_native_dialogue_with_normal_window_geometry   [class C, 278 bytes, 123 instructions]
 * Source: src/rom/run_native_dialogue_with_normal_window_geometry.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void run_native_dialogue_with_normal_window_geometry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    if (RAM8(0xA162) != 2) {
        RAM8(0xA162) = 1;
        RAM8(0x1D10) = 1;
    }
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0;
    RAM8(0x0000 + sp0 - 3) = 0;
    RAM8(0x0000 + sp0 - 4) = 0;
    RAM8(0x0000 + sp0 - 5) = 0;
    RAM8(0x0000 + sp0 - 4) = 0;
    uint8_t value2 = RAM8(0x0029);
    RAM8(0x1D05) = value2 & 7;
    if ((value2 & 7) == 7) {
        RAM8(0xA162) = 1;
    }
    uint8_t value3 = RAM8(0x1D04);
    bool x_flag5;
    uint8_t a_hi6;
    uint16_t x5;
    uint16_t y5;
    uint8_t data_bank5;
    uint16_t direct_page5;
    if ((value3 & 2) == 0) {
        RAM8(0x1D04) |= 1;
        uint8_t value5 = RAM8(0x1D03);
        uint16_t value6 = RAM16(0x1D01);
        RAM8(0x0000 + sp0 - 4) = value5;
        uint8_t value7 = RAM8(0xA170);
        bool x_flag4;
        uint8_t a_hi5;
        uint16_t x4;
        uint16_t y4;
        uint8_t data_bank4;
        uint16_t direct_page4;
        if (value7 != 0x7D) {
            bool x_flag3;
            uint8_t a_hi4;
            uint16_t x3;
            uint16_t y3;
            uint8_t data_bank3;
            uint16_t direct_page3;
            if (value7 != 0) {
                RAM8(0x0000 + sp0 - 4) = value7;
                RAM8(0x0000 + sp0 - 5) = 0x7E;
                RAM8(0xA170) = value7;
                r->a = value7;
                r->x = (uint8_t)((uint8_t)(value7 - 0x50) << 1);
                r->y = value6;
                r->c = (uint8_t)(value7 - 0x50) & 0x80;
                r->z = value7 == 0;
                r->n = value7 & 0x80;
                r->v = ((value7 ^ 0x50) & (value7 ^ (uint8_t)(value7 - 0x50)) & 0x80) != 0;
                r->db = 0x7E;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp;
                switch ((uint8_t)((uint8_t)(value7 - 0x50) << 1)) {
                case 0x0000: JSR(c, 0x01D4, 0xC00229); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_native_dialogue_window_construction_phases */
                case 0x0002: JSR(c, 0x01D4, 0xC00611); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_native_dialogue_window_closing_phases */
                case 0x0004: JSR(c, 0x01D4, 0xC012FF); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_native_dialogue_window_completion_phase */
                case 0x0006: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x0008: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x000A: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x000C: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x000E: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x0010: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x0012: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x0014: JSR(c, 0x01D4, 0xC01A46); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_three_native_dialogue_numeric_selection_phases */
                case 0x0016: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x0018: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                case 0x001A: JSR(c, 0x01D4, 0xC00F6C); GUARD_JSR(c, sp_call, 0x01D4); break; /* request_dialogue_primary_window_pause */
                case 0x001C: JSR(c, 0x01D4, 0xC00F59); GUARD_JSR(c, sp_call, 0x01D4); break; /* request_dialogue_secondary_window_pause */
                case 0x001E: JSR(c, 0x01D4, 0xC00F87); GUARD_JSR(c, sp_call, 0x01D4); break; /* open_temporary_numeric_dialogue_window */
                case 0x0020: JSR(c, 0x01D4, 0xC004E2); GUARD_JSR(c, sp_call, 0x01D4); break; /* expand_dialogue_window_tile_forward_with_plane_mask */
                case 0x0022: JSR(c, 0x01D4, 0xC0054D); GUARD_JSR(c, sp_call, 0x01D4); break; /* expand_dialogue_window_tile_forward_with_reversed_bits */
                case 0x0024: JSR(c, 0x01D4, 0xC00515); GUARD_JSR(c, sp_call, 0x01D4); break; /* expand_dialogue_window_tile_backward */
                case 0x0026: JSR(c, 0x01D4, 0xC00583); GUARD_JSR(c, sp_call, 0x01D4); break; /* expand_dialogue_window_tile_backward_with_reversed_bits */
                default: JSR(c, 0x01D4, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x10DA + ((uint8_t)((uint8_t)(value7 - 0x50) << 1))))); GUARD_JSR(c, sp_call, 0x01D4);
                }
                }
                r->sp += 4;
                uint16_t dp_ret = r->dp;
                uint8_t db_ret = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret = r->y;
                x_flag3 = x_ret;
                a_hi4 = a_all >> 8;
                x3 = x_ret2;
                y3 = y_ret;
                data_bank3 = db_ret;
                direct_page3 = dp_ret;
            } else {
                uint8_t value8 = BUS8_RDP(c, (value5 << 0x10) + value6);
                bool x_flag2;
                uint8_t a_hi3;
                uint16_t x2;
                uint16_t y2;
                uint8_t data_bank2;
                uint16_t direct_page2;
                if (value8 != 0x7D) {
                    bool x_flag;
                    uint8_t a_hi2;
                    uint16_t x1;
                    uint16_t y1;
                    uint8_t data_bank;
                    uint16_t direct_page;
                    if (value8 < 0x50) {
                        uint8_t value9 = RAM8(0x1D04);
                        uint8_t a_hi1;
                        if ((value9 & 0x80) == 0) {
                            a_hi1 = 0;
                        } else {
                            uint16_t value10 = RAM16(0xA1D5);
                            RAM16_SET(0x1D01, value10);
                            a_hi1 = value10 >> 8;
                        }
                        RAM8(0xA15D) = 0;
                        RAM8(0x1D04) &= 0xFE;
                        RAM8(0x1D00) &= 0xFB;
                        if ((RAM8(0x1D00) & 0x80) != 0) {
                            RAM8(0x1D00) &= 0x7F;
                            RAM8(0x1D04) &= 0x7F;
                            if ((RAM8(0xA187) & 1) == 0) {
                                RAM8(0x1D04) &= 0xDF;
                                RAM8(0x1D12) &= 0xDF;
                                RAM8(0x1D10) &= 0xFE;
                            }
                        }
                        x_flag = 0;
                        a_hi2 = a_hi1;
                        x1 = 0;
                        y1 = value6;
                        data_bank = 0;
                        direct_page = 0;
                    } else {
                        uint8_t a1;
                        if (value8 < 0x60) {
                            a1 = value8;
                        } else {
                            a1 = 0x53;
                        }
                        RAM8(0x0000 + sp0 - 4) = a1;
                        RAM8(0x0000 + sp0 - 5) = 0x7E;
                        RAM8(0xA170) = a1;
                        r->a = a1;
                        r->x = (uint8_t)((uint8_t)(a1 - 0x50) << 1);
                        r->y = value6;
                        r->c = (uint8_t)(a1 - 0x50) & 0x80;
                        r->z = a1 == 0;
                        r->n = a1 & 0x80;
                        r->v = ((a1 ^ 0x50) & (a1 ^ (uint8_t)(a1 - 0x50)) & 0x80) != 0;
                        r->db = 0x7E;
                        r->sp -= 4;
                        { const uint16_t sp_call = r->sp;
                        switch ((uint8_t)((uint8_t)(a1 - 0x50) << 1)) {
                        case 0x0000: JSR(c, 0x01D4, 0xC00229); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_native_dialogue_window_construction_phases */
                        case 0x0002: JSR(c, 0x01D4, 0xC00611); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_native_dialogue_window_closing_phases */
                        case 0x0004: JSR(c, 0x01D4, 0xC012FF); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_native_dialogue_window_completion_phase */
                        case 0x0006: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x0008: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x000A: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x000C: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x000E: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x0010: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x0012: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x0014: JSR(c, 0x01D4, 0xC01A46); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_three_native_dialogue_numeric_selection_phases */
                        case 0x0016: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x0018: JSR(c, 0x01D4, 0xC0111A); GUARD_JSR(c, sp_call, 0x01D4); break; /* dispatch_all_eleven_native_dialogue_render_phases */
                        case 0x001A: JSR(c, 0x01D4, 0xC00F6C); GUARD_JSR(c, sp_call, 0x01D4); break; /* request_dialogue_primary_window_pause */
                        case 0x001C: JSR(c, 0x01D4, 0xC00F59); GUARD_JSR(c, sp_call, 0x01D4); break; /* request_dialogue_secondary_window_pause */
                        case 0x001E: JSR(c, 0x01D4, 0xC00F87); GUARD_JSR(c, sp_call, 0x01D4); break; /* open_temporary_numeric_dialogue_window */
                        case 0x0020: JSR(c, 0x01D4, 0xC004E2); GUARD_JSR(c, sp_call, 0x01D4); break; /* expand_dialogue_window_tile_forward_with_plane_mask */
                        case 0x0022: JSR(c, 0x01D4, 0xC0054D); GUARD_JSR(c, sp_call, 0x01D4); break; /* expand_dialogue_window_tile_forward_with_reversed_bits */
                        case 0x0024: JSR(c, 0x01D4, 0xC00515); GUARD_JSR(c, sp_call, 0x01D4); break; /* expand_dialogue_window_tile_backward */
                        case 0x0026: JSR(c, 0x01D4, 0xC00583); GUARD_JSR(c, sp_call, 0x01D4); break; /* expand_dialogue_window_tile_backward_with_reversed_bits */
                        default: JSR(c, 0x01D4, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x10DA + ((uint8_t)((uint8_t)(a1 - 0x50) << 1))))); GUARD_JSR(c, sp_call, 0x01D4);
                        }
                        }
                        r->sp += 4;
                        uint16_t dp_ret2 = r->dp;
                        uint8_t db_ret2 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret3 = r->xf;
                        uint16_t a_all2 = r->a;
                        uint16_t x_ret4 = r->x;
                        uint16_t y_ret2 = r->y;
                        x_flag = x_ret3;
                        a_hi2 = a_all2 >> 8;
                        x1 = x_ret4;
                        y1 = y_ret2;
                        data_bank = db_ret2;
                        direct_page = dp_ret2;
                    }
                    x_flag2 = x_flag;
                    a_hi3 = a_hi2;
                    x2 = x1;
                    y2 = y1;
                    data_bank2 = data_bank;
                    direct_page2 = direct_page;
                } else {
                    r->a = value8;
                    r->x = 0;
                    r->y = value6;
                    r->c = value8 >= 0x7D;
                    r->z = value8 == 0x7D;
                    r->n = (uint8_t)(value8 - 0x7D) & 0x80;
                    r->db = value5;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x01B7, 0xCC0900); GUARD_JSL(c, sp_call, 0x01B7); } /* dispatch_seven_scrolling_dialogue_states */
                    r->sp += 4;
                    uint16_t dp_ret3 = r->dp;
                    uint8_t db_ret3 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret5 = r->xf;
                    uint16_t a_all3 = r->a;
                    uint16_t x_ret6 = r->x;
                    uint16_t y_ret3 = r->y;
                    x_flag2 = x_ret5;
                    a_hi3 = a_all3 >> 8;
                    x2 = x_ret6;
                    y2 = y_ret3;
                    data_bank2 = db_ret3;
                    direct_page2 = dp_ret3;
                }
                x_flag3 = x_flag2;
                a_hi4 = a_hi3;
                x3 = x2;
                y3 = y2;
                data_bank3 = data_bank2;
                direct_page3 = direct_page2;
            }
            x_flag4 = x_flag3;
            a_hi5 = a_hi4;
            x4 = x3;
            y4 = y3;
            data_bank4 = data_bank3;
            direct_page4 = direct_page3;
        } else {
            r->a = value7;
            r->x = 0;
            r->y = value6;
            r->c = value7 >= 0x7D;
            r->z = value7 == 0x7D;
            r->n = (uint8_t)(value7 - 0x7D) & 0x80;
            r->db = value5;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSL(c, 0x01A6, 0xCC0900); GUARD_JSL(c, sp_call, 0x01A6); } /* dispatch_seven_scrolling_dialogue_states */
            r->sp += 4;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret7 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret8 = r->x;
            uint16_t y_ret4 = r->y;
            x_flag4 = x_ret7;
            a_hi5 = a_all4 >> 8;
            x4 = x_ret8;
            y4 = y_ret4;
            data_bank4 = db_ret4;
            direct_page4 = dp_ret4;
        }
        x_flag5 = x_flag4;
        a_hi6 = a_hi5;
        x5 = x4;
        y5 = y4;
        data_bank5 = data_bank4;
        direct_page5 = direct_page4;
    } else {
        x_flag5 = 0;
        a_hi6 = 0;
        x5 = 0;
        y5 = y;
        data_bank5 = 0;
        direct_page5 = 0;
    }
    RAM8(0x1D13) = 0;
    uint8_t value20 = RAM8(0x0000 + sp0 - 3);
    uint8_t value21 = RAM8(0x0000 + sp0 - 2);
    uint8_t value22 = RAM8(0x0000 + sp0 - 1);
    uint8_t value23 = RAM8(0x0000 + sp0);
    r->a = (a_hi6 << 8) | 0;
    r->x = x5;
    r->y = y5;
    r->c = value23 & 0x01;
    r->z = value23 & 0x02;
    r->n = value23 & 0x80;
    r->v = value23 & 0x40;
    r->mf = value23 & 0x20;
    r->xf = value23 & 0x10;
    r->db = value22;
    r->dp = (value21 << 8) | value20;
    r->i = value23 & 0x04;
    r->d = value23 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC00113, SOM_RTL, "gen", run_native_dialogue_with_normal_window_geometry, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 278, 123)

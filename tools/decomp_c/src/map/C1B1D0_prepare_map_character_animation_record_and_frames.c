#include "som_c.h"

/* C1B1D0 prepare_map_character_animation_record_and_frames   [class D, 295 bytes, 144 instructions]
 * Source: src/rom/prepare_map_character_animation_record_and_frames.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=any D=$0000.  Callers read: B.
 */
static void prepare_map_character_animation_record_and_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16(c, 0xC80000 + x);
    RAM8(0x0000 + sp0) = value >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value;
    uint16_t value2 = RAM16(0x0014);
    BUS16_SET(c, (db << 0x10) + 0x8206 + value2, (value & 0x03FF) << 1 << 1 << 1 << 1);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    RAM8(0x0000 + sp0) = value4;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((value4 << 8) | value3);
    BUS16_SET(c, (db << 0x10) + 0x8200 + value2, (((value4 << 8) | value3) >> 4) & 0x0F00);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    uint8_t a2;
    uint8_t a_hi1;
    if (((((value6 << 8) | value5) >> 2) & 0x0300) != 0) {
        uint8_t a1;
        if (((((value6 << 8) | value5) >> 2) & 0x0300) >> 8 != 3) {
            a1 = RAM8(0x0012) & 3;
        } else {
            a1 = RAM8(0x0012) & 7;
        }
        a2 = a1;
        a_hi1 = (((((value6 << 8) | value5) >> 2) & 0x0300) >> 8 << 1) | 1;
    } else {
        a2 = RAM8(0x0012) & 1;
        a_hi1 = 1;
    }
    RAM8(0x0012)++;
    BUS16_SET(c, (db << 0x10) + 0x8208 + value2, (a_hi1 << 8) | a2);
    BUS16_SET(c, (db << 0x10) + 0x8202 + value2, RAM16(0x0006));
    BUS16_SET(c, (db << 0x10) + 0x8204 + value2, 0);
    RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 0x10));
    uint16_t value13 = BUS16_RDP(c, (db << 0x10) + 0x8206 + value2);
    RAM8(0x0000 + sp0) = (uint8_t)value13;
    RAM8(0x0000 + sp0 - 1) = 0;
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x002116, value13);
    BUS16_SET(c, 0x004370, 0x3981);
    BUS16_SET(c, 0x004372, RAM16(0x0006));
    BUS16_SET(c, 0x004375, 0xC0);
    uint16_t value15 = BUS16(c, 0x002139);
    BUS8_SET(c, 0x004374, 0x7F);
    BUS8_SET(c, 0x00420B, 0x80);
    RAM8(0x0000 + sp0) = 0x7F;
    uint8_t value16 = RAM8(0x18201 + (uint8_t)value2);
    if (value16 < 8) {
        if (value16 >= 4) {
            if (value16 == 4) {
                r->a = (value15 >> 8 << 8) | value16;
                r->mf = 1;
                r->xf = 1;
                r->db = 0x7F;
                TAIL_CALL(c, 0xC1B687, SOM_RTS); /* build_map_graphics_wave_frames */
            }
            if (value16 == 5) {
                r->a = (value15 >> 8 << 8) | value16;
                r->x = (uint8_t)value2;
                r->mf = 1;
                r->xf = 1;
                r->db = 0x7F;
                TAIL_CALL(c, 0xC1B5AD, SOM_RTS); /* build_map_graphics_transposed_wave_frames */
            }
            if (value16 == 6) {
                uint8_t a_hi2 = value15 >> 8;
                uint8_t x1 = 7;
                bool first_pass = true;
                for (;;) {
                    if (first_pass) {
                        r->x = x1;
                        r->mf = 1;
                        r->xf = 1;
                        r->db = 0x7F;
                        r->dp = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xB2D7, 0xC1B411); GUARD_JSR(c, sp_call, 0xB2D7); } /* shift_map_graphics_odd_columns_up */
                        r->mf = 0;
                        r->xf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xB2DA, 0xC1B478); GUARD_JSR(c, sp_call, 0xB2DA); } /* shift_map_graphics_even_columns_up */
                        uint16_t a_all2 = r->a;
                        if ((uint8_t)(x1 - 1) != 0) {
                            a_hi2 = a_all2 >> 8;
                            x1 = (uint8_t)(x1 - 1);
                            first_pass = false;
                            continue;
                        }
                        a_hi2 = a_all2 >> 8;
                        x1 = (uint8_t)(x1 - 1);
                        break;
                    } else {
                        r->x = x1;
                        r->mf = 0;
                        r->xf = 1;
                        r->db = 0x7F;
                        r->dp = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xB2D7, 0xC1B411); GUARD_JSR(c, sp_call, 0xB2D7); } /* shift_map_graphics_odd_columns_up */
                        r->mf = 0;
                        r->xf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xB2DA, 0xC1B478); GUARD_JSR(c, sp_call, 0xB2DA); } /* shift_map_graphics_even_columns_up */
                        uint16_t a_all4 = r->a;
                        if ((uint8_t)(x1 - 1) != 0) {
                            a_hi2 = a_all4 >> 8;
                            x1 = (uint8_t)(x1 - 1);
                            continue;
                        }
                        a_hi2 = a_all4 >> 8;
                        x1 = (uint8_t)(x1 - 1);
                        break;
                    }
                }
                r->x = x1;
                r->mf = 0;
                r->xf = 1;
                r->db = 0x7F;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB2E0, 0xC1B411); GUARD_JSR(c, sp_call, 0xB2E0); } /* shift_map_graphics_odd_columns_up */
                r->mf = 0;
                r->xf = 1;
                TAIL_CALL(c, 0xC1B406, SOM_RTS); /* advance_map_graphics_frame_pointer */
            }
            uint8_t a_hi3 = value15 >> 8;
            uint8_t x2 = 7;
            bool first_pass2 = true;
            for (;;) {
                if (first_pass2) {
                    r->x = x2;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB2EA, 0xC1B4DF); GUARD_JSR(c, sp_call, 0xB2EA); } /* shift_map_graphics_odd_columns_down */
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB2ED, 0xC1B546); GUARD_JSR(c, sp_call, 0xB2ED); } /* shift_map_graphics_even_columns_down */
                    uint16_t a_all7 = r->a;
                    if ((uint8_t)(x2 - 1) != 0) {
                        a_hi3 = a_all7 >> 8;
                        x2 = (uint8_t)(x2 - 1);
                        first_pass2 = false;
                        continue;
                    }
                    a_hi3 = a_all7 >> 8;
                    x2 = (uint8_t)(x2 - 1);
                    break;
                } else {
                    r->x = x2;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB2EA, 0xC1B4DF); GUARD_JSR(c, sp_call, 0xB2EA); } /* shift_map_graphics_odd_columns_down */
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB2ED, 0xC1B546); GUARD_JSR(c, sp_call, 0xB2ED); } /* shift_map_graphics_even_columns_down */
                    uint16_t a_all9 = r->a;
                    if ((uint8_t)(x2 - 1) != 0) {
                        a_hi3 = a_all9 >> 8;
                        x2 = (uint8_t)(x2 - 1);
                        continue;
                    }
                    a_hi3 = a_all9 >> 8;
                    x2 = (uint8_t)(x2 - 1);
                    break;
                }
            }
            r->x = x2;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB2F3, 0xC1B4DF); GUARD_JSR(c, sp_call, 0xB2F3); } /* shift_map_graphics_odd_columns_down */
            r->mf = 0;
            r->xf = 1;
            TAIL_CALL(c, 0xC1B406, SOM_RTS); /* advance_map_graphics_frame_pointer */
        }
        if (value16 == 0) {
            uint8_t a_hi4 = value15 >> 8;
            uint8_t x3 = 8;
            bool first_pass3 = true;
            for (;;) {
                if (first_pass3) {
                    r->x = x3;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB27D, 0xC1B2F7); GUARD_JSR(c, sp_call, 0xB27D); } /* rotate_map_graphics_even_rows_left */
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB280, 0xC1B35F); GUARD_JSR(c, sp_call, 0xB280); } /* rotate_map_graphics_odd_rows_left */
                    uint16_t a_all12 = r->a;
                    uint8_t x_ret2 = r->x;
                    if ((uint8_t)(x_ret2 - 1) != 0) {
                        a_hi4 = a_all12 >> 8;
                        x3 = (uint8_t)(x_ret2 - 1);
                        first_pass3 = false;
                        continue;
                    }
                    a_hi4 = a_all12 >> 8;
                    x3 = (uint8_t)(x_ret2 - 1);
                    break;
                } else {
                    r->x = x3;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB27D, 0xC1B2F7); GUARD_JSR(c, sp_call, 0xB27D); } /* rotate_map_graphics_even_rows_left */
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB280, 0xC1B35F); GUARD_JSR(c, sp_call, 0xB280); } /* rotate_map_graphics_odd_rows_left */
                    uint16_t a_all14 = r->a;
                    uint8_t x_ret4 = r->x;
                    if ((uint8_t)(x_ret4 - 1) != 0) {
                        a_hi4 = a_all14 >> 8;
                        x3 = (uint8_t)(x_ret4 - 1);
                        continue;
                    }
                    a_hi4 = a_all14 >> 8;
                    x3 = (uint8_t)(x_ret4 - 1);
                    break;
                }
            }
            r->a = (a_hi4 << 8) | (uint8_t)a;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if (value16 == 1) {
            uint8_t a_hi5 = value15 >> 8;
            uint8_t x4 = 8;
            bool first_pass4 = true;
            for (;;) {
                if (first_pass4) {
                    r->x = x4;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB28B, 0xC1B32A); GUARD_JSR(c, sp_call, 0xB28B); } /* rotate_map_graphics_even_rows_right */
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB28E, 0xC1B392); GUARD_JSR(c, sp_call, 0xB28E); } /* rotate_map_graphics_odd_rows_right */
                    uint16_t a_all16 = r->a;
                    uint8_t x_ret6 = r->x;
                    if ((uint8_t)(x_ret6 - 1) != 0) {
                        a_hi5 = a_all16 >> 8;
                        x4 = (uint8_t)(x_ret6 - 1);
                        first_pass4 = false;
                        continue;
                    }
                    a_hi5 = a_all16 >> 8;
                    x4 = (uint8_t)(x_ret6 - 1);
                    break;
                } else {
                    r->x = x4;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB28B, 0xC1B32A); GUARD_JSR(c, sp_call, 0xB28B); } /* rotate_map_graphics_even_rows_right */
                    r->mf = 0;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB28E, 0xC1B392); GUARD_JSR(c, sp_call, 0xB28E); } /* rotate_map_graphics_odd_rows_right */
                    uint16_t a_all18 = r->a;
                    uint8_t x_ret8 = r->x;
                    if ((uint8_t)(x_ret8 - 1) != 0) {
                        a_hi5 = a_all18 >> 8;
                        x4 = (uint8_t)(x_ret8 - 1);
                        continue;
                    }
                    a_hi5 = a_all18 >> 8;
                    x4 = (uint8_t)(x_ret8 - 1);
                    break;
                }
            }
            r->a = (a_hi5 << 8) | (uint8_t)a;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if (value16 == 2) {
            uint8_t a_hi6 = value15 >> 8;
            uint8_t x5 = 7;
            bool first_pass5 = true;
            for (;;) {
                if (first_pass5) {
                    r->x = x5;
                    r->mf = 1;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB299, 0xC1B3C7); GUARD_JSR(c, sp_call, 0xB299); } /* rotate_map_graphics_all_rows_left */
                    uint16_t a_all19 = r->a;
                    uint8_t x_ret9 = r->x;
                    if ((uint8_t)(x_ret9 - 1) != 0) {
                        a_hi6 = a_all19 >> 8;
                        x5 = (uint8_t)(x_ret9 - 1);
                        first_pass5 = false;
                        continue;
                    }
                    a_hi6 = a_all19 >> 8;
                    x5 = (uint8_t)(x_ret9 - 1);
                    break;
                } else {
                    r->x = x5;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB299, 0xC1B3C7); GUARD_JSR(c, sp_call, 0xB299); } /* rotate_map_graphics_all_rows_left */
                    uint16_t a_all20 = r->a;
                    uint8_t x_ret10 = r->x;
                    if ((uint8_t)(x_ret10 - 1) != 0) {
                        a_hi6 = a_all20 >> 8;
                        x5 = (uint8_t)(x_ret10 - 1);
                        continue;
                    }
                    a_hi6 = a_all20 >> 8;
                    x5 = (uint8_t)(x_ret10 - 1);
                    break;
                }
            }
            r->a = (a_hi6 << 8) | (uint8_t)a;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            TAIL_CALL(c, 0xC1B406, SOM_RTS); /* advance_map_graphics_frame_pointer */
        }
        uint8_t a_hi7 = value15 >> 8;
        uint8_t x6 = 7;
        bool first_pass6 = true;
        for (;;) {
            if (first_pass6) {
                r->x = x6;
                r->mf = 1;
                r->xf = 1;
                r->db = 0x7F;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB2A6, 0xC1B3E6); GUARD_JSR(c, sp_call, 0xB2A6); } /* rotate_map_graphics_all_rows_right */
                uint16_t a_all21 = r->a;
                uint8_t x_ret11 = r->x;
                if ((uint8_t)(x_ret11 - 1) != 0) {
                    a_hi7 = a_all21 >> 8;
                    x6 = (uint8_t)(x_ret11 - 1);
                    first_pass6 = false;
                    continue;
                }
                a_hi7 = a_all21 >> 8;
                x6 = (uint8_t)(x_ret11 - 1);
                break;
            } else {
                r->x = x6;
                r->mf = 0;
                r->xf = 1;
                r->db = 0x7F;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB2A6, 0xC1B3E6); GUARD_JSR(c, sp_call, 0xB2A6); } /* rotate_map_graphics_all_rows_right */
                uint16_t a_all22 = r->a;
                uint8_t x_ret12 = r->x;
                if ((uint8_t)(x_ret12 - 1) != 0) {
                    a_hi7 = a_all22 >> 8;
                    x6 = (uint8_t)(x_ret12 - 1);
                    continue;
                }
                a_hi7 = a_all22 >> 8;
                x6 = (uint8_t)(x_ret12 - 1);
                break;
            }
        }
        r->a = (a_hi7 << 8) | (uint8_t)a;
        r->mf = 0;
        r->xf = 1;
        r->db = 0x7F;
        r->dp = 0;
        TAIL_CALL(c, 0xC1B406, SOM_RTS); /* advance_map_graphics_frame_pointer */
    }
    r->a = (value15 >> 8 << 8) | value16;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7F;
    TAIL_CALL(c, 0xC1C1A1, SOM_RTS); /* dispatch_map_graphics_two_tile_motion_type */
}
SOM_REGISTER(0xC1B1D0, SOM_RTS, "gen", prepare_map_character_animation_record_and_frames, 0, L_B, 2, 0, 0, 295, 144)

#include "som_c.h"

static void integrate_automatic_ui_fractional_motion_and_request_tile_edges(SomCtx *c);

/* C08C78 advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition   [class D, 451 bytes, 228 instructions]
 * Source: src/rom/advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition.s
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: XY.
 */
static void advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const uint8_t db = r->db;
    if (RAM8(0x008C) != 0) {
        uint8_t value2 = RAM8(0x00E3);
        if ((value2 & 6) == 0) {
            if (value2 & 0x01) {
                uint16_t value3 = RAM16(0x008E);
                RAM16_SET(0x008E, (uint16_t)(value3 - 1));
                if ((uint16_t)(value3 - 1) != 0) {
                    uint8_t value4 = RAM8(0x008F);
                    uint8_t value5 = RAM8(0x008E);
                    if (!(value4 & 0x01)) {
                        if (value5 < 0x40) {
                            BUS8_SET(c, (db << 0x10) + 0x2100, value5 >> 2);
                        }
                    }
                    BUS8_SET(c, (db << 0x10) + 0x4202, (RAM8(0x008E) >> 1) | ((RAM8(0x008F) & 1) << 7));
                    BUS8_SET(c, (db << 0x10) + 0x4203, 0xD0);
                    uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0x4217);
                    RAM8(0x00F8) = (uint8_t)(value8 + 0x10);
                    uint16_t value9 = RAM16(0x008E);
                    RAM16_SET(0x0000, 0);
                    if ((value9 & 0x0100) != 0) {
                        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
                    }
                    uint8_t a1;
                    uint8_t a_hi1;
                    if ((value9 & 0x80) == 0) {
                        a1 = (uint8_t)value9;
                        a_hi1 = value9 >> 8;
                    } else {
                        a1 = (uint8_t)(value9 ^ 0x7F);
                        a_hi1 = (value9 ^ 0x7F) >> 8;
                    }
                    uint16_t value10 = BUS16_RDP(c, (db << 0x10) + 0xFD22 + ((((a_hi1 << 8) | a1) & 0x7F) << 1 << 1));
                    uint16_t value11 = RAM16(0x0000);
                    uint8_t a2;
                    uint8_t a_hi2;
                    if (!(value11 & 0x8000)) {
                        a2 = (uint8_t)(value10 >> 1);
                        a_hi2 = value10 >> 1 >> 8;
                    } else {
                        a2 = (uint8_t)((value10 >> 1) ^ 0xFFFF);
                        a_hi2 = ((value10 >> 1) ^ 0xFFFF) >> 8;
                    }
                    uint16_t value12 = RAM16(0x0096);
                    RAM16_SET(0x00F6, (uint16_t)(((a_hi2 << 8) | a2) + value12) & 0x03FF);
                    r->a = (uint16_t)(((a_hi2 << 8) | a2) + value12) & 0x03FF;
                    r->x = (((a_hi1 << 8) | a1) & 0x7F) << 1 << 1;
                    r->c = ((a_hi2 << 8) | a2) + value12 > 0xFFFF;
                    r->z = ((uint16_t)(((a_hi2 << 8) | a2) + value12) & 0x03FF) == 0;
                    r->n = (uint16_t)(((a_hi2 << 8) | a2) + value12) & 0x03FF & 0x8000;
                    r->v = ((((a_hi2 << 8) | a2) ^ (uint16_t)(((a_hi2 << 8) | a2) + value12)) & (value12 ^ (uint16_t)(((a_hi2 << 8) | a2) + value12)) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x8D72, integrate_automatic_ui_fractional_motion_and_request_tile_edges, sp_in, 2); GUARD_JSR(c, sp_call, 0x8D72); }
                    uint16_t dp_ret = r->dp;
                    uint16_t a_all = r->a;
                    uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x8F));
                    uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x8E));
                    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xF4));
                    if ((value15 & 1) == 0) {
                        r->a = (a_all >> 8 << 8) | value15;
                        r->x = (uint8_t)(a_all >> 8 << 8 | (((((value13 >> 2) | ((value13 & 1) << 7)) ^ value14 ^ 0x80) >> 2) & 0x20));
                        r->y = 2;
                        r->c = (((value13 >> 2) | ((value13 & 1) << 7)) ^ value14 ^ 0x80) >> 1 & 0x01;
                        r->z = (value15 & 1) == 0;
                        r->n = value15 & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        TAIL_CALL(c, 0xC08455, SOM_RTS); /* advance_two_scene_attribute_windows_and_rom_rows */
                    }
                    r->x = (uint8_t)(a_all >> 8 << 8 | (((((value13 >> 2) | ((value13 & 1) << 7)) ^ value14 ^ 0x80) >> 2) & 0x20));
                    r->y = 2;
                    r->mf = 1;
                    r->xf = 1;
                    RETURN_RTS(c);
                }
                RAM8(0x00F2) = 0x80;
                r->a = ((uint16_t)(value3 - 1) >> 8 << 8) | 0x80;
                r->c = value2 & 0x01;
                r->z = 0;
                r->n = 1;
                TAIL_CALL(c, 0xC0824E, SOM_RTS); /* derive_automatic_ui_map_target_before_native_stack_reset */
            }
            RAM16_SET(0x00F6, (uint16_t)(RAM16(0x00F6) - 4));
            uint16_t value17 = RAM16(0x008E);
            RAM16_SET(0x008E, (uint16_t)(value17 - 1));
            if (value17 >= 1) {
                RAM16_SET(0x008E, (uint16_t)(value17 - 1));
                uint8_t a4;
                if ((uint16_t)(value17 - 1) < 0x0100) {
                    uint8_t a3;
                    if ((uint8_t)(value17 - 1) >= 0x40) {
                        a3 = (uint8_t)(value17 - 1);
                    } else {
                        RAM8(0x0000 + sp0) = (uint8_t)(value17 - 1);
                        BUS8_SET(c, (db << 0x10) + 0x2100, (uint8_t)(value17 - 1) >> 2);
                        a3 = RAM8(0x0000 + sp0);
                    }
                    a4 = a3;
                } else {
                    a4 = (uint8_t)(value17 - 1) ^ 0xFF;
                }
                uint16_t value19 = BUS16_RDP(c, (db << 0x10) + 0xFD22 + (((((uint16_t)(value17 - 1) >> 8 << 8) | a4) & 0xFF) << 1));
                uint8_t a5;
                if (value19 != 0x0100) {
                    a5 = (uint8_t)value19;
                } else {
                    a5 = 0xFF;
                }
                BUS8_SET(c, (db << 0x10) + 0x4202, a5);
                BUS8_SET(c, (db << 0x10) + 0x4203, 0xF8);
                uint8_t value20 = BUS8_RDP(c, (db << 0x10) + 0x4217);
                RAM8(0x0090) = value20 | 1;
                uint8_t value21 = RAM8(0x008F);
                if (value21 == 0) {
                    r->x = (uint8_t)(((((uint16_t)(value17 - 1) >> 8 << 8) | a4) & 0xFF) << 1);
                    RETURN_RTS(c);
                }
                r->a = (value19 >> 8 << 8) | value21;
                r->x = (uint8_t)(((((uint16_t)(value17 - 1) >> 8 << 8) | a4) & 0xFF) << 1);
                r->c = value19 >= 0x0100;
                r->z = value21 == 0;
                r->n = value21 & 0x80;
                r->v = ((value17 ^ 1) & (value17 ^ (uint16_t)(value17 - 1)) & 0x8000) != 0;
                integrate_automatic_ui_fractional_motion_and_request_tile_edges(c); return;
            }
            RAM8(0x008C) = 0;
            r->a = (uint16_t)(value17 - 1);
            r->x = 0;
            r->c = value17 >= 1;
            r->z = 1;
            r->n = 0;
            r->v = ((value17 ^ 1) & (value17 ^ (uint16_t)(value17 - 1)) & 0x8000) != 0;
            r->mf = 0;
            TAIL_CALL(c, 0xC0824E, SOM_RTS); /* derive_automatic_ui_map_target_before_native_stack_reset */
        }
        if ((value2 & 4) != 0) {
            RAM8(0x00E7) = 0x0C;
        }
        RAM16_SET(0x00F6, (uint16_t)(RAM16(0x00F6) + 1) & 0x03FF);
        uint16_t value23 = RAM16(0x00F4);
        uint8_t a_hi3;
        uint8_t x1;
        uint8_t y1;
        if (value23 & 0x01) {
            a_hi3 = value23 >> 1 >> 8;
            x1 = x;
            y1 = y;
        } else {
            r->a = value23 >> 1;
            r->x = 0;
            r->y = 2;
            r->c = value23 & 0x01;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8CA4, 0xC08455); GUARD_JSR(c, sp_call, 0x8CA4); } /* advance_two_scene_attribute_windows_and_rom_rows */
            uint16_t a_all2 = r->a;
            uint8_t x_ret3 = r->x;
            a_hi3 = a_all2 >> 8;
            x1 = x_ret3;
            y1 = 2;
        }
        uint16_t value24 = RAM16(0x008E);
        RAM16_SET(0x008E, (uint16_t)(value24 - 1));
        if ((uint16_t)(value24 - 1) != 0) {
            r->a = (uint16_t)(value24 - 1);
            r->x = x1;
            r->y = y1;
            r->z = (uint16_t)(value24 - 1) == 0;
            r->n = (uint16_t)(value24 - 1) & 0x8000;
            r->mf = 1;
            r->xf = 1;
            TAIL_CALL(c, 0xC08F24, SOM_RTS); /* advance_automatic_ui_radial_focus_and_publish_attribute_sample */
        }
        BUS8_SET(c, (db << 0x10) + 0x1E02, 0);
        uint8_t value25 = RAM8(0x00E3);
        RAM8(0x00E3) = 0;
        uint8_t a6;
        if ((value25 & 2) >= 2) {
            a6 = value25 & 2;
        } else {
            a6 = 3;
        }
        BUS8_SET(c, (db << 0x10) + 0x1E01, a6);
        RAM8(0x00E3) = (RAM8(0x00E3) >> 1) | (((value25 & 2) >= 2) << 7);
        if (!(RAM8(0x00E3) & 0x80)) {
            BUS8_SET(c, (db << 0x10) + 0x1E02, 0x0B);
            RAM8(0x00E3) |= 0x40;
        }
        RAM8(0x008C) = 0;
        uint8_t value28 = RAM8(0x00E3);
        RAM8(0xCF02) = (uint8_t)(((uint8_t)(((uint8_t)(value28 << 1) << 1) | (value28 >> 7)) << 1) | ((uint8_t)(value28 << 1) >> 7)) & 3;
        BUS8_SET(c, (db << 0x10) + 0x1E00, 1);
        BUS8_SET(c, (db << 0x10) + 0x1E03, 0x0F);
        BUS8_SET(c, (db << 0x10) + 0x4200, 0);
        uint8_t value29 = RAM8(0x00E3);
        bool x_flag;
        uint8_t a7;
        uint8_t a_hi4;
        uint16_t x2;
        uint16_t y2;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        uint8_t data_bank;
        if (!(value29 & 0x40)) {
            x_flag = 1;
            a7 = 0x0F;
            a_hi4 = (uint16_t)(value24 - 1) >> 8;
            x2 = x1;
            y2 = y1;
            carry1 = (uint8_t)(((uint8_t)(value28 << 1) << 1) | (value28 >> 7)) & 0x80;
            zero1 = (value29 & 0x0F) == 0;
            negative1 = value29 & 0x80;
            overflow1 = value29 & 0x40;
            data_bank = db;
        } else {
            r->a = ((uint16_t)(value24 - 1) >> 8 << 8) | 0x0F;
            r->x = x1;
            r->y = y1;
            r->c = (uint8_t)(((uint8_t)(value28 << 1) << 1) | (value28 >> 7)) & 0x80;
            r->z = (value29 & 0x0F) == 0;
            r->n = value29 & 0x80;
            r->v = value29 & 0x40;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x8CF2, 0x01F8E5); GUARD_JSL(c, sp_call, 0x8CF2); } /* prepare_scene_palette_templates_long */
            uint8_t db_ret2 = r->db;
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            bool overflow_ret3 = r->v;
            x_flag = x_ret4;
            a7 = (uint8_t)a_all3;
            a_hi4 = a_all3 >> 8;
            x2 = x_ret5;
            y2 = y_ret2;
            carry1 = carry_ret3;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow1 = overflow_ret3;
            data_bank = db_ret2;
        }
        r->a = (a_hi4 << 8) | a7;
        r->x = x2;
        r->y = y2;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = x_flag;
        r->db = data_bank;
        { const uint16_t sp_call = r->sp; JSL(c, 0x8CF6, 0xC30004); GUARD_JSL(c, sp_call, 0x8CF6); } /* audio_command_sender_public_jump */
        BUS8_SET(c, (data_bank << 0x10) + 0x4200, 0xB1);
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08C78, SOM_RTS, "gen", advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition, 0, L_X | L_Y, 5, 1, 1, 451, 228)

/* C08DEE integrate_automatic_ui_fractional_motion_and_request_tile_edges   [class A, 77 bytes, 41 instructions]
 * Source: src/rom/advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition.s
 * Subroutine of advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition, translated in place.
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void integrate_automatic_ui_fractional_motion_and_request_tile_edges(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0084);
    uint16_t value2 = RAM16(0x0086);
    uint16_t value3 = RAM16(0x0088);
    uint16_t value4 = RAM16(0x008A);
    RAM8(0x008A) = (uint8_t)(value3 + value4);
    RAM8(0x0000) = (uint16_t)(value3 + value4) >> 8;
    RAM8(0x0086) = (uint8_t)(value + value2);
    uint8_t value5 = RAM8(0x008D);
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value5 & 0x80)) {
        a1 = ((uint16_t)(value + value2) >> 8) & 0x0F;
        a_hi1 = 0;
    } else {
        a1 = (uint8_t)(((((uint16_t)(value + value2) >> 8) & 0x0F) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((((uint16_t)(value + value2) >> 8) & 0x0F) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0066, (a_hi1 << 8) | a1);
    uint8_t value6 = RAM8(0x0000);
    uint8_t a2;
    uint8_t a_hi2;
    if (!(value5 & 0x40)) {
        a2 = value6 & 0x0F;
        a_hi2 = 0;
    } else {
        a2 = (uint8_t)(((value6 & 0x0F) ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)(((value6 & 0x0F) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0068, (a_hi2 << 8) | a2);
    r->a = 0;
    r->x = 0;
    r->y = 0;
    r->c = value3 + value4 > 0xFFFF;
    r->z = 1;
    r->n = 0;
    r->v = value5 & 0x40;
    r->mf = 0;
    r->xf = 1;
    TAIL_CALL(c, 0xC08648, SOM_RTS); /* external */
}

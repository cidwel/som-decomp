#include "som_c.h"

static void publish_main_menu_transition_hdma_stripes_from_rom_patterns(SomCtx *c);
static void publish_main_menu_transition_hdma_stripes_from_rom_patterns_v2(SomCtx *c);

/* C0A462 advance_main_frame_menu_transition_and_native_wait   [class C, 362 bytes, 195 instructions]
 * Source: src/rom/advance_main_frame_menu_transition_and_native_wait.s
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_main_frame_menu_transition_and_native_wait(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x0052);
    if (value != 0) {
        if (value & 0x80) {
            SET_A8(r, value);
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->z = value == 0;
            r->n = value & 0x80;
            r->xf = 1;
            RETURN_RTS(c);
        }
        if (value >= 3) {
            uint8_t value2 = RAM8(0x003E);
            RAM8(0x003E) = (uint8_t)(value2 - 8);
            if ((uint8_t)(value2 - 8) != 0) {
                r->a = (a_hi << 8) | (uint8_t)(value2 - 8);
                r->x = (uint8_t)x;
                r->y = (uint8_t)y;
                r->c = value2 >= 8;
                r->z = (uint8_t)(value2 - 8) == 0;
                r->n = (uint8_t)(value2 - 8) & 0x80;
                r->v = ((value2 ^ 8) & (value2 ^ (uint8_t)(value2 - 8)) & 0x80) != 0;
                r->xf = 1;
                publish_main_menu_transition_hdma_stripes_from_rom_patterns(c); return;
            }
            RAM8(0x0052) = (uint8_t)(value + 1);
            if ((uint8_t)(value + 1) < 5) {
                RAM8(0x00FF) = 0x80;
                RAM8(0x00E0) = 0;
                r->a = (a_hi << 8) | 0;
                r->x = (uint8_t)x;
                r->y = (uint8_t)y;
                r->c = (uint8_t)(value + 1) >= 5;
                r->z = 1;
                r->n = 0;
                r->v = ((value2 ^ 8) & (value2 ^ (uint8_t)(value2 - 8)) & 0x80) != 0;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA4EB, 0xC08B16); GUARD_JSR(c, sp_call, 0xA4EB); } /* request_slow_black_fade */
                uint16_t y_ret = r->y;
                r->y = (uint8_t)y_ret;
                r->mf = 1;
                r->xf = 1;
                publish_main_menu_transition_hdma_stripes_from_rom_patterns_v2(c); return;
            }
            RAM8(0x0052) = 0;
            SET_A8(r, 0);
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->c = (uint8_t)(value + 1) >= 5;
            r->z = 1;
            r->n = 0;
            r->v = ((value2 ^ 8) & (value2 ^ (uint8_t)(value2 - 8)) & 0x80) != 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t value3 = RAM8(0x003E);
        RAM8(0x003E) = (uint8_t)(value3 + 8);
        if ((uint8_t)(value3 + 8) == 0) {
            RAM8(0x0052)++;
            uint8_t value4 = RAM8(0x0052);
            r->a = (a_hi << 8) | (uint8_t)(value3 + 8);
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->c = value3 + 8 > 0xFF;
            r->z = value4 == 0;
            r->n = value4 & 0x80;
            r->v = ((value3 ^ (uint8_t)(value3 + 8)) & ((uint8_t)(value3 + 8) ^ 8) & 0x80) != 0;
            r->xf = 1;
            publish_main_menu_transition_hdma_stripes_from_rom_patterns(c); return;
        }
        if ((uint8_t)(value3 + 8) != 0xC0) {
            r->a = (a_hi << 8) | (uint8_t)(value3 + 8);
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->c = (uint8_t)(value3 + 8) >= 0xC0;
            r->z = (uint8_t)(value3 + 8) == 0xC0;
            r->n = (uint8_t)((uint8_t)(value3 + 8) - 0xC0) & 0x80;
            r->v = ((value3 ^ (uint8_t)(value3 + 8)) & ((uint8_t)(value3 + 8) ^ 8) & 0x80) != 0;
            r->xf = 1;
            publish_main_menu_transition_hdma_stripes_from_rom_patterns(c); return;
        }
        if (value >= 2) {
            RAM8(0x0052) = 0;
            uint8_t x1 = 0x1D;
            for (;;) {
                BUS8_SET(c, (db << 0x10) + 0x0602 + x1, 0);
                RAM8(0xDE02 + x1) = 0;
                x1 = (uint8_t)(x1 - 1);
                if (!(!(x1 & 0x80))) break;
            }
            uint8_t a_hi1 = a_hi;
            uint8_t x2 = 3;
            for (;;) {
                uint8_t value5 = BUS8(c, 0xD27E00 + x2);
                BUS8_SET(c, (db << 0x10) + 0x0604 + x2, value5);
                RAM8(0xDE04 + x2) = value5;
                x2 = (uint8_t)(x2 - 1);
                if (!(!(x2 & 0x80))) break;
            }
            RAM8(0x003E) = 0;
            RAM8(0x0040) = 0;
            RAM8(0x00EC) = 2;
            bool overflow1 = ((value3 ^ (uint8_t)(value3 + 8)) & ((uint8_t)(value3 + 8) ^ 8) & 0x80) != 0;
            for (;;) {
                uint8_t value6 = RAM8(0x00EC);
                overflow1 = value6 & 0x40;
                if (!((value6 & 2) != 0)) break;
            }
            BUS8_SET(c, (db << 0x10) + 0x2109, 0x58);
            BUS8_SET(c, (db << 0x10) + 0x2111, 0);
            BUS8_SET(c, (db << 0x10) + 0x2111, 0);
            BUS8_SET(c, (db << 0x10) + 0x2112, 0);
            BUS8_SET(c, (db << 0x10) + 0x2112, 0);
            r->a = (a_hi1 << 8) | 0x58;
            r->x = x2;
            r->y = (uint8_t)y;
            r->c = value >= 2;
            r->z = 0;
            r->n = 0;
            r->v = overflow1;
            r->xf = 1;
            RETURN_RTS(c);
        }
        r->a = (a_hi << 8) | value;
        r->x = (uint8_t)x;
        r->y = (uint8_t)y;
        r->c = value >= 2;
        r->z = value == 2;
        r->n = (uint8_t)(value - 2) & 0x80;
        r->v = ((value3 ^ (uint8_t)(value3 + 8)) & ((uint8_t)(value3 + 8) ^ 8) & 0x80) != 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xA484, publish_main_menu_transition_hdma_stripes_from_rom_patterns, sp_in, 2); GUARD_JSR(c, sp_call, 0xA484); }
        r->mf = 1;
        r->xf = 1;
        TAIL_CALL(c, 0xC0C059, SOM_RTS); /* slide_special_scene_camera_across_128_real_frames */
    }
    SET_A8(r, value);
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->z = value == 0;
    r->n = value & 0x80;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0A462, SOM_RTS, "gen", advance_main_frame_menu_transition_and_native_wait, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 11, 1, 0, 362, 195)

/* C0A4EE publish_main_menu_transition_hdma_stripes_from_rom_patterns   [class A, 222 bytes, 129 instructions]
 * Source: src/rom/advance_main_frame_menu_transition_and_native_wait.s
 * Subroutine of advance_main_frame_menu_transition_and_native_wait, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_main_menu_transition_hdma_stripes_from_rom_patterns(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x0052);
    if (value & 0x01) {
        uint8_t value2 = RAM8(0x003E);
        uint8_t a1;
        if (!(value2 & 0x80)) {
            a1 = value2;
        } else {
            a1 = value2 ^ 0xFF;
        }
        RAM8(0x0040) = (a1 ^ 0x7F) >> 3;
    }
    if (value >= 3) {
        uint8_t value3 = RAM8(0x003E);
        if (value == 4) {
            uint8_t x1 = 0;
            for (;;) {
                BUS16_SET(c, 0x7FFF00 + x1, 0);
                x1 = (uint8_t)(x1 + 2);
                if (!(x1 < 0x24)) break;
            }
            RAM16_SET(0x0074, (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00);
            r->a = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00;
            r->x = x1;
            r->y = (uint8_t)((a_hi << 8) | (value3 >> 3));
            r->c = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 > 0xFFFF;
            r->z = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 == 0;
            r->n = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 & 0x8000;
            r->v = (((uint8_t)((a_hi << 8) | (value3 >> 3)) ^ (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00) & ((uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)((a_hi << 8) | ((value3 >> 3) ^ 0x1F)) < 0x18) {
            RAM8(0x0004) = 4;
            RAM16_SET(0x0074, (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00);
            RAM8(0x0002) = (uint8_t)((a_hi << 8) | ((value3 >> 3) ^ 0x1F));
            RAM8(0x0000 + sp0) = db;
            RAM8(0x0000 + sp0 - 1) = 0x7F;
            uint8_t a_hi1 = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 >> 8;
            uint16_t x2 = (uint8_t)((a_hi << 8) | ((value3 >> 3) ^ 0x1F));
            uint16_t y1 = 0;
            for (;;) {
                uint8_t value4 = BUS8(c, 0xC67400 + x2);
                uint8_t a2;
                if (!(value4 & 0x80)) {
                    a2 = (uint8_t)(value4 + 0x20);
                } else {
                    a2 = 0x20;
                }
                BUS8_SET(c, 0x7FFF00 + y1, a2);
                uint8_t a_hi1_next = (uint16_t)(x2 + 0x18) >> 8;
                uint16_t x2_next = (uint16_t)(x2 + 0x18);
                uint16_t y1_next = (uint16_t)(y1 + 2);
                a_hi1 = a_hi1_next;
                x2 = x2_next;
                y1 = y1_next;
                if (!(y1 < 0x24)) break;
            }
            RAM8(0x0000) = 0;
            uint8_t value5 = RAM8(0x0002);
            uint8_t value6 = RAM8(0x0000);
            RAM8(0x0000) = (RAM8(0x0000) >> 1) | ((value5 & 1) << 7);
            uint8_t a3 = value5 >> 1;
            uint8_t a_hi2 = a_hi1;
            uint8_t x3 = (uint8_t)((a_hi1 << 8) | (value5 >> 1));
            uint8_t y2 = 1;
            bool carry1 = value6 & 0x01;
            bool zero1 = 0;
            bool negative1 = 0;
            bool overflow1 = 0;
            for (;;) {
                uint8_t value7 = BUS8(c, 0xC67520 + x3);
                uint8_t value8 = RAM8(0x0000);
                uint8_t a4;
                if (!(value8 & 0x80)) {
                    a4 = value7;
                } else {
                    a4 = value7 >> 4;
                }
                uint8_t value9 = RAM8(0x0004);
                RAM8(0x0002) = (a4 & 0x0F) ^ value9;
                RAM8(0x0003) = ((a4 & 0x0F) ^ value9) & 3;
                RAM8(0x1FF00 + y2) = (uint8_t)(((uint8_t)(((((RAM8(0x0002) & 0x0C) | 2) << 1 << 1) | RAM8(0x0003)) << 1) << 1) | 1);
                uint8_t a3_next = (uint8_t)(x3 + 0x0C);
                uint8_t x3_next = (uint8_t)((a_hi2 << 8) | (uint8_t)(x3 + 0x0C));
                uint8_t y2_next = (uint8_t)(y2 + 2);
                bool carry1_next = (uint8_t)(y2 + 2) >= 0x18;
                bool zero1_next = (uint8_t)(y2 + 2) == 0x18;
                bool negative1_next = (uint8_t)((uint8_t)(y2 + 2) - 0x18) & 0x80;
                bool overflow1_next = ((x3 ^ (uint8_t)(x3 + 0x0C)) & ((uint8_t)(x3 + 0x0C) ^ 0x0C) & 0x80) != 0;
                a3 = a3_next;
                x3 = x3_next;
                y2 = y2_next;
                carry1 = carry1_next;
                zero1 = zero1_next;
                negative1 = negative1_next;
                overflow1 = overflow1_next;
                if (!(y2 < 0x18)) break;
            }
            uint8_t value12 = RAM8(0x0000 + sp0);
            r->a = (a_hi2 << 8) | a3;
            r->x = x3;
            r->y = y2;
            r->c = carry1;
            r->z = value12 == 0;
            r->n = value12 & 0x80;
            r->v = overflow1;
            r->db = value12;
            RETURN_RTS(c);
        }
        uint8_t x4 = 0;
        for (;;) {
            BUS16_SET(c, 0x7FFF00 + x4, 0);
            x4 = (uint8_t)(x4 + 2);
            if (!(x4 < 0x24)) break;
        }
        RAM16_SET(0x0074, (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00);
        r->a = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00;
        r->x = x4;
        r->y = (uint8_t)((a_hi << 8) | (value3 >> 3));
        r->c = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 > 0xFFFF;
        r->z = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 == 0;
        r->n = (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 & 0x8000;
        r->v = (((uint8_t)((a_hi << 8) | (value3 >> 3)) ^ (uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00) & ((uint8_t)((a_hi << 8) | (value3 >> 3)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint8_t value13 = RAM8(0x003E);
    if (value == 2) {
        uint8_t x5 = 0;
        for (;;) {
            BUS16_SET(c, 0x7FFF00 + x5, 0);
            x5 = (uint8_t)(x5 + 2);
            if (!(x5 < 0x24)) break;
        }
        RAM16_SET(0x0074, (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00);
        r->a = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00;
        r->x = x5;
        r->y = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F));
        r->c = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 > 0xFFFF;
        r->z = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 == 0;
        r->n = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 & 0x8000;
        r->v = (((uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) ^ (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00) & ((uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint8_t)((a_hi << 8) | (value13 >> 3)) >= 0x18) {
        uint8_t x6 = 0;
        for (;;) {
            BUS16_SET(c, 0x7FFF00 + x6, 0);
            x6 = (uint8_t)(x6 + 2);
            if (!(x6 < 0x24)) break;
        }
        RAM16_SET(0x0074, (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00);
        r->a = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00;
        r->x = x6;
        r->y = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F));
        r->c = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 > 0xFFFF;
        r->z = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 == 0;
        r->n = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 & 0x8000;
        r->v = (((uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) ^ (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00) & ((uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint8_t)((a_hi << 8) | (value13 >> 3)) < 0x18) {
        RAM8(0x0004) = 0;
        RAM16_SET(0x0074, (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00);
        RAM8(0x0002) = (uint8_t)((a_hi << 8) | (value13 >> 3));
        RAM8(0x0000 + sp0) = db;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        uint8_t a_hi3 = (uint8_t)(a_hi << 8 | ((value13 >> 3) + 0x1F & 0x1F)) + 0x5D00 >> 8;
        uint16_t x7 = (uint8_t)((a_hi << 8) | (value13 >> 3));
        uint16_t y3 = 0;
        for (;;) {
            uint8_t value14 = BUS8(c, 0xC67400 + x7);
            uint8_t a5;
            if (!(value14 & 0x80)) {
                a5 = (uint8_t)(value14 + 0x20);
            } else {
                a5 = 0x20;
            }
            BUS8_SET(c, 0x7FFF00 + y3, a5);
            uint8_t a_hi3_next = (uint16_t)(x7 + 0x18) >> 8;
            uint16_t x7_next = (uint16_t)(x7 + 0x18);
            uint16_t y3_next = (uint16_t)(y3 + 2);
            a_hi3 = a_hi3_next;
            x7 = x7_next;
            y3 = y3_next;
            if (!(y3 < 0x24)) break;
        }
        RAM8(0x0000) = 0;
        uint8_t value15 = RAM8(0x0002);
        uint8_t value16 = RAM8(0x0000);
        RAM8(0x0000) = (RAM8(0x0000) >> 1) | ((value15 & 1) << 7);
        uint8_t a6 = value15 >> 1;
        uint8_t a_hi4 = a_hi3;
        uint8_t x8 = (uint8_t)((a_hi3 << 8) | (value15 >> 1));
        uint8_t y4 = 1;
        bool carry2 = value16 & 0x01;
        bool zero2 = 0;
        bool negative2 = 0;
        bool overflow2 = 0;
        for (;;) {
            uint8_t value17 = BUS8(c, 0xC67520 + x8);
            uint8_t value18 = RAM8(0x0000);
            uint8_t a7;
            if (!(value18 & 0x80)) {
                a7 = value17;
            } else {
                a7 = value17 >> 4;
            }
            uint8_t value19 = RAM8(0x0004);
            RAM8(0x0002) = (a7 & 0x0F) ^ value19;
            RAM8(0x0003) = ((a7 & 0x0F) ^ value19) & 3;
            RAM8(0x1FF00 + y4) = (uint8_t)(((uint8_t)(((((RAM8(0x0002) & 0x0C) | 2) << 1 << 1) | RAM8(0x0003)) << 1) << 1) | 1);
            uint8_t a6_next = (uint8_t)(x8 + 0x0C);
            uint8_t x8_next = (uint8_t)((a_hi4 << 8) | (uint8_t)(x8 + 0x0C));
            uint8_t y4_next = (uint8_t)(y4 + 2);
            bool carry2_next = (uint8_t)(y4 + 2) >= 0x18;
            bool zero2_next = (uint8_t)(y4 + 2) == 0x18;
            bool negative2_next = (uint8_t)((uint8_t)(y4 + 2) - 0x18) & 0x80;
            bool overflow2_next = ((x8 ^ (uint8_t)(x8 + 0x0C)) & ((uint8_t)(x8 + 0x0C) ^ 0x0C) & 0x80) != 0;
            a6 = a6_next;
            x8 = x8_next;
            y4 = y4_next;
            carry2 = carry2_next;
            zero2 = zero2_next;
            negative2 = negative2_next;
            overflow2 = overflow2_next;
            if (!(y4 < 0x18)) break;
        }
        uint8_t value22 = RAM8(0x0000 + sp0);
        r->a = (a_hi4 << 8) | a6;
        r->x = x8;
        r->y = y4;
        r->c = carry2;
        r->z = value22 == 0;
        r->n = value22 & 0x80;
        r->v = overflow2;
        r->db = value22;
        RETURN_RTS(c);
    }
    if (value == 4) {
        uint8_t x9 = 0;
        for (;;) {
            BUS16_SET(c, 0x7FFF00 + x9, 0);
            x9 = (uint8_t)(x9 + 2);
            if (!(x9 < 0x24)) break;
        }
        RAM16_SET(0x0074, (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00);
        r->a = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00;
        r->x = x9;
        r->y = (uint8_t)((a_hi << 8) | (value13 >> 3));
        r->c = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 > 0xFFFF;
        r->z = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 == 0;
        r->n = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 & 0x8000;
        r->v = (((uint8_t)((a_hi << 8) | (value13 >> 3)) ^ (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00) & ((uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint8_t)((a_hi << 8) | ((value13 >> 3) ^ 0x1F)) < 0x18) {
        RAM8(0x0004) = 4;
        RAM16_SET(0x0074, (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00);
        RAM8(0x0002) = (uint8_t)((a_hi << 8) | ((value13 >> 3) ^ 0x1F));
        RAM8(0x0000 + sp0) = db;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        uint8_t a_hi5 = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 >> 8;
        uint16_t x10 = (uint8_t)((a_hi << 8) | ((value13 >> 3) ^ 0x1F));
        uint16_t y5 = 0;
        for (;;) {
            uint8_t value23 = BUS8(c, 0xC67400 + x10);
            uint8_t a8;
            if (!(value23 & 0x80)) {
                a8 = (uint8_t)(value23 + 0x20);
            } else {
                a8 = 0x20;
            }
            BUS8_SET(c, 0x7FFF00 + y5, a8);
            uint8_t a_hi5_next = (uint16_t)(x10 + 0x18) >> 8;
            uint16_t x10_next = (uint16_t)(x10 + 0x18);
            uint16_t y5_next = (uint16_t)(y5 + 2);
            a_hi5 = a_hi5_next;
            x10 = x10_next;
            y5 = y5_next;
            if (!(y5 < 0x24)) break;
        }
        RAM8(0x0000) = 0;
        uint8_t value24 = RAM8(0x0002);
        uint8_t value25 = RAM8(0x0000);
        RAM8(0x0000) = (RAM8(0x0000) >> 1) | ((value24 & 1) << 7);
        uint8_t a9 = value24 >> 1;
        uint8_t a_hi6 = a_hi5;
        uint8_t x11 = (uint8_t)((a_hi5 << 8) | (value24 >> 1));
        uint8_t y6 = 1;
        bool carry3 = value25 & 0x01;
        bool zero3 = 0;
        bool negative3 = 0;
        bool overflow3 = 0;
        for (;;) {
            uint8_t value26 = BUS8(c, 0xC67520 + x11);
            uint8_t value27 = RAM8(0x0000);
            uint8_t a10;
            if (!(value27 & 0x80)) {
                a10 = value26;
            } else {
                a10 = value26 >> 4;
            }
            uint8_t value28 = RAM8(0x0004);
            RAM8(0x0002) = (a10 & 0x0F) ^ value28;
            RAM8(0x0003) = ((a10 & 0x0F) ^ value28) & 3;
            RAM8(0x1FF00 + y6) = (uint8_t)(((uint8_t)(((((RAM8(0x0002) & 0x0C) | 2) << 1 << 1) | RAM8(0x0003)) << 1) << 1) | 1);
            uint8_t a9_next = (uint8_t)(x11 + 0x0C);
            uint8_t x11_next = (uint8_t)((a_hi6 << 8) | (uint8_t)(x11 + 0x0C));
            uint8_t y6_next = (uint8_t)(y6 + 2);
            bool carry3_next = (uint8_t)(y6 + 2) >= 0x18;
            bool zero3_next = (uint8_t)(y6 + 2) == 0x18;
            bool negative3_next = (uint8_t)((uint8_t)(y6 + 2) - 0x18) & 0x80;
            bool overflow3_next = ((x11 ^ (uint8_t)(x11 + 0x0C)) & ((uint8_t)(x11 + 0x0C) ^ 0x0C) & 0x80) != 0;
            a9 = a9_next;
            x11 = x11_next;
            y6 = y6_next;
            carry3 = carry3_next;
            zero3 = zero3_next;
            negative3 = negative3_next;
            overflow3 = overflow3_next;
            if (!(y6 < 0x18)) break;
        }
        uint8_t value31 = RAM8(0x0000 + sp0);
        r->a = (a_hi6 << 8) | a9;
        r->x = x11;
        r->y = y6;
        r->c = carry3;
        r->z = value31 == 0;
        r->n = value31 & 0x80;
        r->v = overflow3;
        r->db = value31;
        RETURN_RTS(c);
    }
    uint8_t x12 = 0;
    for (;;) {
        BUS16_SET(c, 0x7FFF00 + x12, 0);
        x12 = (uint8_t)(x12 + 2);
        if (!(x12 < 0x24)) break;
    }
    RAM16_SET(0x0074, (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00);
    r->a = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00;
    r->x = x12;
    r->y = (uint8_t)((a_hi << 8) | (value13 >> 3));
    r->c = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 > 0xFFFF;
    r->z = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 == 0;
    r->n = (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 & 0x8000;
    r->v = (((uint8_t)((a_hi << 8) | (value13 >> 3)) ^ (uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00) & ((uint8_t)((a_hi << 8) | (value13 >> 3)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
    RETURN_RTS(c);
}

/* C0A4EE publish_main_menu_transition_hdma_stripes_from_rom_patterns_v2   [class A, 222 bytes, 129 instructions]
 * Source: src/rom/advance_main_frame_menu_transition_and_native_wait.s
 * Subroutine of advance_main_frame_menu_transition_and_native_wait, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void publish_main_menu_transition_hdma_stripes_from_rom_patterns_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x52));
    if (value & 0x01) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0x3E));
        uint8_t a1;
        if (!(value2 & 0x80)) {
            a1 = value2;
        } else {
            a1 = value2 ^ 0xFF;
        }
        BUS8_SET(c, (uint16_t)(dp + 0x40), (a1 ^ 0x7F) >> 3);
    }
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0x52));
    if (value3 >= 3) {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 0x3E));
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0x52));
        if (value5 == 4) {
            uint8_t x1 = 0;
            for (;;) {
                BUS16_SET(c, 0x7FFF00 + x1, 0);
                x1 = (uint8_t)(x1 + 2);
                if (!(x1 < 0x24)) break;
            }
            BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00);
            r->a = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00;
            r->x = x1;
            r->y = (uint8_t)((a_hi << 8) | (value4 >> 3));
            r->c = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 > 0xFFFF;
            r->z = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 == 0;
            r->n = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 & 0x8000;
            r->v = (((uint8_t)((a_hi << 8) | (value4 >> 3)) ^ (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00) & ((uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)((a_hi << 8) | ((value4 >> 3) ^ 0x1F)) < 0x18) {
            BUS8_SET(c, (uint16_t)(dp + 4), 4);
            BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00);
            BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)((a_hi << 8) | ((value4 >> 3) ^ 0x1F)));
            RAM8(0x0000 + sp0) = db;
            RAM8(0x0000 + sp0 - 1) = 0x7F;
            uint8_t a_hi1 = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 >> 8;
            uint16_t x2 = (uint8_t)((a_hi << 8) | ((value4 >> 3) ^ 0x1F));
            uint16_t y1 = 0;
            for (;;) {
                uint8_t value6 = BUS8(c, 0xC67400 + x2);
                uint8_t a2;
                if (!(value6 & 0x80)) {
                    a2 = (uint8_t)(value6 + 0x20);
                } else {
                    a2 = 0x20;
                }
                BUS8_SET(c, 0x7FFF00 + y1, a2);
                uint8_t a_hi1_next = (uint16_t)(x2 + 0x18) >> 8;
                uint16_t x2_next = (uint16_t)(x2 + 0x18);
                uint16_t y1_next = (uint16_t)(y1 + 2);
                a_hi1 = a_hi1_next;
                x2 = x2_next;
                y1 = y1_next;
                if (!(y1 < 0x24)) break;
            }
            BUS8_SET(c, dp, 0);
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 2));
            uint8_t value8 = BUS8_RDP(c, dp);
            BUS8_SET(c, dp, (value8 >> 1) | ((value7 & 1) << 7));
            uint8_t a3 = value7 >> 1;
            uint8_t a_hi2 = a_hi1;
            uint8_t x3 = (uint8_t)((a_hi1 << 8) | (value7 >> 1));
            uint8_t y2 = 1;
            bool carry1 = value8 & 0x01;
            bool zero1 = 0;
            bool negative1 = 0;
            bool overflow1 = 0;
            for (;;) {
                uint8_t value9 = BUS8(c, 0xC67520 + x3);
                uint8_t value10 = BUS8_RDP(c, dp);
                uint8_t a4;
                if (!(value10 & 0x80)) {
                    a4 = value9;
                } else {
                    a4 = value9 >> 4;
                }
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 4));
                BUS8_SET(c, (uint16_t)(dp + 2), (a4 & 0x0F) ^ value11);
                BUS8_SET(c, (uint16_t)(dp + 3), ((a4 & 0x0F) ^ value11) & 3);
                uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 2));
                uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp + 3));
                RAM8(0x1FF00 + y2) = (uint8_t)(((uint8_t)(((((value12 & 0x0C) | 2) << 1 << 1) | value13) << 1) << 1) | 1);
                uint8_t a3_next = (uint8_t)(x3 + 0x0C);
                uint8_t x3_next = (uint8_t)((a_hi2 << 8) | (uint8_t)(x3 + 0x0C));
                uint8_t y2_next = (uint8_t)(y2 + 2);
                bool carry1_next = (uint8_t)(y2 + 2) >= 0x18;
                bool zero1_next = (uint8_t)(y2 + 2) == 0x18;
                bool negative1_next = (uint8_t)((uint8_t)(y2 + 2) - 0x18) & 0x80;
                bool overflow1_next = ((x3 ^ (uint8_t)(x3 + 0x0C)) & ((uint8_t)(x3 + 0x0C) ^ 0x0C) & 0x80) != 0;
                a3 = a3_next;
                x3 = x3_next;
                y2 = y2_next;
                carry1 = carry1_next;
                zero1 = zero1_next;
                negative1 = negative1_next;
                overflow1 = overflow1_next;
                if (!(y2 < 0x18)) break;
            }
            uint8_t value14 = RAM8(0x0000 + sp0);
            r->a = (a_hi2 << 8) | a3;
            r->x = x3;
            r->y = y2;
            r->c = carry1;
            r->z = value14 == 0;
            r->n = value14 & 0x80;
            r->v = overflow1;
            r->db = value14;
            RETURN_RTS(c);
        }
        uint8_t x4 = 0;
        for (;;) {
            BUS16_SET(c, 0x7FFF00 + x4, 0);
            x4 = (uint8_t)(x4 + 2);
            if (!(x4 < 0x24)) break;
        }
        BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00);
        r->a = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00;
        r->x = x4;
        r->y = (uint8_t)((a_hi << 8) | (value4 >> 3));
        r->c = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 > 0xFFFF;
        r->z = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 == 0;
        r->n = (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 & 0x8000;
        r->v = (((uint8_t)((a_hi << 8) | (value4 >> 3)) ^ (uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00) & ((uint8_t)((a_hi << 8) | (value4 >> 3)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 0x3E));
    uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp + 0x52));
    if (value16 == 2) {
        uint8_t x5 = 0;
        for (;;) {
            BUS16_SET(c, 0x7FFF00 + x5, 0);
            x5 = (uint8_t)(x5 + 2);
            if (!(x5 < 0x24)) break;
        }
        BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00);
        r->a = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00;
        r->x = x5;
        r->y = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F));
        r->c = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 > 0xFFFF;
        r->z = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 == 0;
        r->n = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 & 0x8000;
        r->v = (((uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) ^ (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00) & ((uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint8_t)((a_hi << 8) | (value15 >> 3)) >= 0x18) {
        uint8_t x6 = 0;
        for (;;) {
            BUS16_SET(c, 0x7FFF00 + x6, 0);
            x6 = (uint8_t)(x6 + 2);
            if (!(x6 < 0x24)) break;
        }
        BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00);
        r->a = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00;
        r->x = x6;
        r->y = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F));
        r->c = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 > 0xFFFF;
        r->z = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 == 0;
        r->n = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 & 0x8000;
        r->v = (((uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) ^ (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00) & ((uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint8_t)((a_hi << 8) | (value15 >> 3)) < 0x18) {
        BUS8_SET(c, (uint16_t)(dp + 4), 0);
        BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00);
        BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)((a_hi << 8) | (value15 >> 3)));
        RAM8(0x0000 + sp0) = db;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        uint8_t a_hi3 = (uint8_t)(a_hi << 8 | ((value15 >> 3) + 0x1F & 0x1F)) + 0x5D00 >> 8;
        uint16_t x7 = (uint8_t)((a_hi << 8) | (value15 >> 3));
        uint16_t y3 = 0;
        for (;;) {
            uint8_t value17 = BUS8(c, 0xC67400 + x7);
            uint8_t a5;
            if (!(value17 & 0x80)) {
                a5 = (uint8_t)(value17 + 0x20);
            } else {
                a5 = 0x20;
            }
            BUS8_SET(c, 0x7FFF00 + y3, a5);
            uint8_t a_hi3_next = (uint16_t)(x7 + 0x18) >> 8;
            uint16_t x7_next = (uint16_t)(x7 + 0x18);
            uint16_t y3_next = (uint16_t)(y3 + 2);
            a_hi3 = a_hi3_next;
            x7 = x7_next;
            y3 = y3_next;
            if (!(y3 < 0x24)) break;
        }
        BUS8_SET(c, dp, 0);
        uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp + 2));
        uint8_t value19 = BUS8_RDP(c, dp);
        BUS8_SET(c, dp, (value19 >> 1) | ((value18 & 1) << 7));
        uint8_t a6 = value18 >> 1;
        uint8_t a_hi4 = a_hi3;
        uint8_t x8 = (uint8_t)((a_hi3 << 8) | (value18 >> 1));
        uint8_t y4 = 1;
        bool carry2 = value19 & 0x01;
        bool zero2 = 0;
        bool negative2 = 0;
        bool overflow2 = 0;
        for (;;) {
            uint8_t value20 = BUS8(c, 0xC67520 + x8);
            uint8_t value21 = BUS8_RDP(c, dp);
            uint8_t a7;
            if (!(value21 & 0x80)) {
                a7 = value20;
            } else {
                a7 = value20 >> 4;
            }
            uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp + 4));
            BUS8_SET(c, (uint16_t)(dp + 2), (a7 & 0x0F) ^ value22);
            BUS8_SET(c, (uint16_t)(dp + 3), ((a7 & 0x0F) ^ value22) & 3);
            uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp + 2));
            uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp + 3));
            RAM8(0x1FF00 + y4) = (uint8_t)(((uint8_t)(((((value23 & 0x0C) | 2) << 1 << 1) | value24) << 1) << 1) | 1);
            uint8_t a6_next = (uint8_t)(x8 + 0x0C);
            uint8_t x8_next = (uint8_t)((a_hi4 << 8) | (uint8_t)(x8 + 0x0C));
            uint8_t y4_next = (uint8_t)(y4 + 2);
            bool carry2_next = (uint8_t)(y4 + 2) >= 0x18;
            bool zero2_next = (uint8_t)(y4 + 2) == 0x18;
            bool negative2_next = (uint8_t)((uint8_t)(y4 + 2) - 0x18) & 0x80;
            bool overflow2_next = ((x8 ^ (uint8_t)(x8 + 0x0C)) & ((uint8_t)(x8 + 0x0C) ^ 0x0C) & 0x80) != 0;
            a6 = a6_next;
            x8 = x8_next;
            y4 = y4_next;
            carry2 = carry2_next;
            zero2 = zero2_next;
            negative2 = negative2_next;
            overflow2 = overflow2_next;
            if (!(y4 < 0x18)) break;
        }
        uint8_t value25 = RAM8(0x0000 + sp0);
        r->a = (a_hi4 << 8) | a6;
        r->x = x8;
        r->y = y4;
        r->c = carry2;
        r->z = value25 == 0;
        r->n = value25 & 0x80;
        r->v = overflow2;
        r->db = value25;
        RETURN_RTS(c);
    }
    uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp + 0x3E));
    uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp + 0x52));
    if (value27 == 4) {
        uint8_t x9 = 0;
        for (;;) {
            BUS16_SET(c, 0x7FFF00 + x9, 0);
            x9 = (uint8_t)(x9 + 2);
            if (!(x9 < 0x24)) break;
        }
        BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00);
        r->a = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00;
        r->x = x9;
        r->y = (uint8_t)((a_hi << 8) | (value26 >> 3));
        r->c = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 > 0xFFFF;
        r->z = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 == 0;
        r->n = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 & 0x8000;
        r->v = (((uint8_t)((a_hi << 8) | (value26 >> 3)) ^ (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00) & ((uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    if ((uint8_t)((a_hi << 8) | ((value26 >> 3) ^ 0x1F)) < 0x18) {
        BUS8_SET(c, (uint16_t)(dp + 4), 4);
        BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00);
        BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)((a_hi << 8) | ((value26 >> 3) ^ 0x1F)));
        RAM8(0x0000 + sp0) = db;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        uint8_t a_hi5 = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 >> 8;
        uint16_t x10 = (uint8_t)((a_hi << 8) | ((value26 >> 3) ^ 0x1F));
        uint16_t y5 = 0;
        for (;;) {
            uint8_t value28 = BUS8(c, 0xC67400 + x10);
            uint8_t a8;
            if (!(value28 & 0x80)) {
                a8 = (uint8_t)(value28 + 0x20);
            } else {
                a8 = 0x20;
            }
            BUS8_SET(c, 0x7FFF00 + y5, a8);
            uint8_t a_hi5_next = (uint16_t)(x10 + 0x18) >> 8;
            uint16_t x10_next = (uint16_t)(x10 + 0x18);
            uint16_t y5_next = (uint16_t)(y5 + 2);
            a_hi5 = a_hi5_next;
            x10 = x10_next;
            y5 = y5_next;
            if (!(y5 < 0x24)) break;
        }
        BUS8_SET(c, dp, 0);
        uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 2));
        uint8_t value30 = BUS8_RDP(c, dp);
        BUS8_SET(c, dp, (value30 >> 1) | ((value29 & 1) << 7));
        uint8_t a9 = value29 >> 1;
        uint8_t a_hi6 = a_hi5;
        uint8_t x11 = (uint8_t)((a_hi5 << 8) | (value29 >> 1));
        uint8_t y6 = 1;
        bool carry3 = value30 & 0x01;
        bool zero3 = 0;
        bool negative3 = 0;
        bool overflow3 = 0;
        for (;;) {
            uint8_t value31 = BUS8(c, 0xC67520 + x11);
            uint8_t value32 = BUS8_RDP(c, dp);
            uint8_t a10;
            if (!(value32 & 0x80)) {
                a10 = value31;
            } else {
                a10 = value31 >> 4;
            }
            uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp + 4));
            BUS8_SET(c, (uint16_t)(dp + 2), (a10 & 0x0F) ^ value33);
            BUS8_SET(c, (uint16_t)(dp + 3), ((a10 & 0x0F) ^ value33) & 3);
            uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp + 2));
            uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp + 3));
            RAM8(0x1FF00 + y6) = (uint8_t)(((uint8_t)(((((value34 & 0x0C) | 2) << 1 << 1) | value35) << 1) << 1) | 1);
            uint8_t a9_next = (uint8_t)(x11 + 0x0C);
            uint8_t x11_next = (uint8_t)((a_hi6 << 8) | (uint8_t)(x11 + 0x0C));
            uint8_t y6_next = (uint8_t)(y6 + 2);
            bool carry3_next = (uint8_t)(y6 + 2) >= 0x18;
            bool zero3_next = (uint8_t)(y6 + 2) == 0x18;
            bool negative3_next = (uint8_t)((uint8_t)(y6 + 2) - 0x18) & 0x80;
            bool overflow3_next = ((x11 ^ (uint8_t)(x11 + 0x0C)) & ((uint8_t)(x11 + 0x0C) ^ 0x0C) & 0x80) != 0;
            a9 = a9_next;
            x11 = x11_next;
            y6 = y6_next;
            carry3 = carry3_next;
            zero3 = zero3_next;
            negative3 = negative3_next;
            overflow3 = overflow3_next;
            if (!(y6 < 0x18)) break;
        }
        uint8_t value36 = RAM8(0x0000 + sp0);
        r->a = (a_hi6 << 8) | a9;
        r->x = x11;
        r->y = y6;
        r->c = carry3;
        r->z = value36 == 0;
        r->n = value36 & 0x80;
        r->v = overflow3;
        r->db = value36;
        RETURN_RTS(c);
    }
    uint8_t x12 = 0;
    for (;;) {
        BUS16_SET(c, 0x7FFF00 + x12, 0);
        x12 = (uint8_t)(x12 + 2);
        if (!(x12 < 0x24)) break;
    }
    BUS16_SET(c, (uint16_t)(dp + 0x74), (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00);
    r->a = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00;
    r->x = x12;
    r->y = (uint8_t)((a_hi << 8) | (value26 >> 3));
    r->c = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 > 0xFFFF;
    r->z = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 == 0;
    r->n = (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 & 0x8000;
    r->v = (((uint8_t)((a_hi << 8) | (value26 >> 3)) ^ (uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00) & ((uint8_t)((a_hi << 8) | (value26 >> 3)) + 0x5D00 ^ 0x5D00) & 0x8000) != 0;
    RETURN_RTS(c);
}

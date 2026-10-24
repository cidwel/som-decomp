#include "som_c.h"

/* C08598 advance_complete_ui_scale_input_and_boundary_transitions   [class C, 160 bytes, 87 instructions]
 * Source: src/rom/advance_complete_ui_scale_input_and_boundary_transitions.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_complete_ui_scale_input_and_boundary_transitions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    uint8_t a_85c1 = 0;
    uint8_t a_hi_85c1 = 0;
    uint8_t x_85c1 = 0;
    uint8_t y_85c1 = 0;
    bool carry_85c1 = 0;
    uint8_t value = RAM8(0x0042);
    if (!(value & 0x80)) {
        uint8_t value2 = RAM8(0x00F8);
        if (value2 >= 0x30) {
            a_85c1 = value2;
            a_hi_85c1 = a_hi;
            x_85c1 = x;
            y_85c1 = 2;
            carry_85c1 = value2 >= 0x30;
            goto shared_85C1;
        }
        if (value2 >= 0x20) {
            a_85c1 = value2;
            a_hi_85c1 = a_hi;
            x_85c1 = x;
            y_85c1 = 1;
            carry_85c1 = value2 >= 0x20;
            goto shared_85C1;
        }
        uint8_t value3 = RAM8(0x00F4);
        if (((((value2 >> 2) & 3) ^ 3 | 1) & value3) == 0) {
            a_85c1 = (((value2 >> 2) & 3) ^ 3 | 1) & value3;
            a_hi_85c1 = a_hi;
            x_85c1 = x;
            y_85c1 = 1;
            carry_85c1 = value2 >> 1 & 0x01;
            goto shared_85C1;
        }
        r->y = 1;
        r->c = value2 >> 1 & 0x01;
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0x00F8);
    uint8_t y1;
    if (value4 >= 0x30) {
        y1 = 2;
    } else {
        y1 = 1;
    }
    a_85c1 = value4;
    a_hi_85c1 = a_hi;
    x_85c1 = x;
    y_85c1 = y1;
    carry_85c1 = value4 >= 0x30;
    shared_85C1:;
    if (RAM8(0x0042) & 0x80) {
        RAM8(0x006B) = 4;
        RAM8(0x006A) = 1;
        uint8_t value6 = RAM8(0x00F8);
        RAM8(0x00F8) = (uint8_t)(y_85c1 + value6);
        if ((uint8_t)(y_85c1 + value6) < 0x32) {
            r->a = (a_hi_85c1 << 8) | (uint8_t)(y_85c1 + value6);
            r->x = x_85c1;
            r->y = y_85c1;
            r->c = (uint8_t)(y_85c1 + value6) >= 0x32;
            r->v = ((y_85c1 ^ (uint8_t)(y_85c1 + value6)) & (value6 ^ (uint8_t)(y_85c1 + value6)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)(y_85c1 + value6) < 0xE0) {
            uint8_t value7 = RAM8(0x009E);
            RAM8(0x009E) &= 0xEF;
            if ((value7 & 0x10) != 0) {
                RAM8(0x00CC) |= 0x10;
            }
            r->a = (a_hi_85c1 << 8) | a;
            r->x = x_85c1;
            r->y = y_85c1;
            r->c = (uint8_t)(y_85c1 + value6) >= 0xE0;
            r->v = ((y_85c1 ^ (uint8_t)(y_85c1 + value6)) & (value6 ^ (uint8_t)(y_85c1 + value6)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        RAM8(0x006B) = 4;
        RAM8(0x006A) = 2;
        uint8_t value9 = RAM8(0x00F8);
        if ((uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9) >= 0x2B) {
            RAM8(0x00F8) = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9);
            r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9);
            r->x = x_85c1;
            r->y = y_85c1;
            r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9) >= 0x2B;
            r->v = (((uint8_t)((y_85c1 ^ 0xFF) + 1) ^ (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9)) & (value9 ^ (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value10 = RAM8(0x00F2);
        if (!(value10 & 0x80)) {
            if ((value10 & 3) == 0) {
                RAM8(0x009E) |= 0x10;
                r->a = (a_hi_85c1 << 8) | 0x10;
                r->x = x_85c1;
                r->y = y_85c1;
                r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9) >= 0x2B;
                r->v = value10 & 0x40;
                r->mf = 1;
                r->xf = 1;
                r->db = 0;
                r->dp = 0;
                TAIL_CALL(c, 0xC087B7, SOM_RTS); /* start_ui_window_color_transition */
            }
            r->a = (a_hi_85c1 << 8) | 3;
            r->x = x_85c1;
            r->y = y_85c1;
            r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9) >= 0x2B;
            r->v = value10 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9) < 0x10) {
            r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9);
            r->x = x_85c1;
            r->y = y_85c1;
            r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9) >= 0x10;
            r->v = value10 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            TAIL_CALL(c, 0xC08159, SOM_RTS); /* test_ui_target_tile_permission_and_request_map_transition */
        }
        RAM8(0x00F8) = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9);
        r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9);
        r->x = x_85c1;
        r->y = y_85c1;
        r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value9) >= 0x10;
        r->v = value10 & 0x40;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value12 = RAM8(0x0043);
    if (value12 & 0x80) {
        RAM8(0x006B) = 4;
        RAM8(0x006A) = 2;
        uint8_t value13 = RAM8(0x00F8);
        if ((uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13) >= 0x2B) {
            RAM8(0x00F8) = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13);
            r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13);
            r->x = x_85c1;
            r->y = y_85c1;
            r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13) >= 0x2B;
            r->v = (((uint8_t)((y_85c1 ^ 0xFF) + 1) ^ (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13)) & (value13 ^ (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value14 = RAM8(0x00F2);
        if (!(value14 & 0x80)) {
            if ((value14 & 3) == 0) {
                RAM8(0x009E) |= 0x10;
                r->a = (a_hi_85c1 << 8) | 0x10;
                r->x = x_85c1;
                r->y = y_85c1;
                r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13) >= 0x2B;
                r->v = value14 & 0x40;
                r->mf = 1;
                r->xf = 1;
                r->db = 0;
                r->dp = 0;
                TAIL_CALL(c, 0xC087B7, SOM_RTS); /* start_ui_window_color_transition */
            }
            r->a = (a_hi_85c1 << 8) | 3;
            r->x = x_85c1;
            r->y = y_85c1;
            r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13) >= 0x2B;
            r->v = value14 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13) < 0x10) {
            r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13);
            r->x = x_85c1;
            r->y = y_85c1;
            r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13) >= 0x10;
            r->v = value14 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            TAIL_CALL(c, 0xC08159, SOM_RTS); /* test_ui_target_tile_permission_and_request_map_transition */
        }
        RAM8(0x00F8) = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13);
        r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13);
        r->x = x_85c1;
        r->y = y_85c1;
        r->c = (uint8_t)((uint8_t)((y_85c1 ^ 0xFF) + 1) + value13) >= 0x10;
        r->v = value14 & 0x40;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value16 = RAM8(0x006B);
    if (value16 == 0) {
        r->a = (a_hi_85c1 << 8) | value16;
        r->x = x_85c1;
        r->y = y_85c1;
        r->c = carry_85c1;
        r->v = value12 & 0x40;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value17 = RAM8(0x006A);
    RAM8(0x006A) = (uint8_t)(value17 + 4);
    if (((uint8_t)(value17 + 4) & value16) == 0) {
        r->a = a_hi_85c1 << 8 | ((uint8_t)(value17 + 4) & value16);
        r->x = x_85c1;
        r->y = y_85c1;
        r->c = value17 + 4 > 0xFF;
        r->v = ((value17 ^ (uint8_t)(value17 + 4)) & ((uint8_t)(value17 + 4) ^ 4) & 0x80) != 0;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value18 = RAM8(0x006B);
    RAM8(0x006B) <<= 1;
    uint8_t y2;
    if (!((uint8_t)(y_85c1 - 1) & 0x80)) {
        y2 = (uint8_t)(y_85c1 - 1);
    } else {
        y2 = 0;
    }
    uint8_t value19 = RAM8(0x006A);
    if ((value19 & 1) != 0) {
        uint8_t value20 = RAM8(0x00F8);
        RAM8(0x00F8) = (uint8_t)(y2 + value20);
        if ((uint8_t)(y2 + value20) < 0x32) {
            r->a = (a_hi_85c1 << 8) | (uint8_t)(y2 + value20);
            r->x = x_85c1;
            r->y = y2;
            r->c = (uint8_t)(y2 + value20) >= 0x32;
            r->v = ((y2 ^ (uint8_t)(y2 + value20)) & (value20 ^ (uint8_t)(y2 + value20)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)(y2 + value20) < 0xE0) {
            uint8_t value21 = RAM8(0x009E);
            RAM8(0x009E) &= 0xEF;
            if ((value21 & 0x10) != 0) {
                RAM8(0x00CC) |= 0x10;
            }
            r->a = (a_hi_85c1 << 8) | a;
            r->x = x_85c1;
            r->y = y2;
            r->c = (uint8_t)(y2 + value20) >= 0xE0;
            r->v = ((y2 ^ (uint8_t)(y2 + value20)) & (value20 ^ (uint8_t)(y2 + value20)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        RAM8(0x006B) = 4;
        RAM8(0x006A) = 2;
        uint8_t value23 = RAM8(0x00F8);
        if ((uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23) >= 0x2B) {
            RAM8(0x00F8) = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23);
            r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23);
            r->x = x_85c1;
            r->y = y2;
            r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23) >= 0x2B;
            r->v = (((uint8_t)((y2 ^ 0xFF) + 1) ^ (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23)) & (value23 ^ (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value24 = RAM8(0x00F2);
        if (!(value24 & 0x80)) {
            if ((value24 & 3) == 0) {
                RAM8(0x009E) |= 0x10;
                r->a = (a_hi_85c1 << 8) | 0x10;
                r->x = x_85c1;
                r->y = y2;
                r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23) >= 0x2B;
                r->v = value24 & 0x40;
                r->mf = 1;
                r->xf = 1;
                r->db = 0;
                r->dp = 0;
                TAIL_CALL(c, 0xC087B7, SOM_RTS); /* start_ui_window_color_transition */
            }
            r->a = (a_hi_85c1 << 8) | 3;
            r->x = x_85c1;
            r->y = y2;
            r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23) >= 0x2B;
            r->v = value24 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23) < 0x10) {
            r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23);
            r->x = x_85c1;
            r->y = y2;
            r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23) >= 0x10;
            r->v = value24 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            TAIL_CALL(c, 0xC08159, SOM_RTS); /* test_ui_target_tile_permission_and_request_map_transition */
        }
        RAM8(0x00F8) = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23);
        r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23);
        r->x = x_85c1;
        r->y = y2;
        r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value23) >= 0x10;
        r->v = value24 & 0x40;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if ((value19 & 1) == 0) {
        uint8_t value26 = RAM8(0x00F8);
        if ((uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26) >= 0x2B) {
            RAM8(0x00F8) = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26);
            r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26);
            r->x = x_85c1;
            r->y = y2;
            r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26) >= 0x2B;
            r->v = (((uint8_t)((y2 ^ 0xFF) + 1) ^ (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26)) & (value26 ^ (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value27 = RAM8(0x00F2);
        if (!(value27 & 0x80)) {
            if ((value27 & 3) == 0) {
                RAM8(0x009E) |= 0x10;
                r->a = (a_hi_85c1 << 8) | 0x10;
                r->x = x_85c1;
                r->y = y2;
                r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26) >= 0x2B;
                r->v = value27 & 0x40;
                r->mf = 1;
                r->xf = 1;
                r->db = 0;
                r->dp = 0;
                TAIL_CALL(c, 0xC087B7, SOM_RTS); /* start_ui_window_color_transition */
            }
            r->a = (a_hi_85c1 << 8) | 3;
            r->x = x_85c1;
            r->y = y2;
            r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26) >= 0x2B;
            r->v = value27 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26) < 0x10) {
            r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26);
            r->x = x_85c1;
            r->y = y2;
            r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26) >= 0x10;
            r->v = value27 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            TAIL_CALL(c, 0xC08159, SOM_RTS); /* test_ui_target_tile_permission_and_request_map_transition */
        }
        RAM8(0x00F8) = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26);
        r->a = (a_hi_85c1 << 8) | (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26);
        r->x = x_85c1;
        r->y = y2;
        r->c = (uint8_t)((uint8_t)((y2 ^ 0xFF) + 1) + value26) >= 0x10;
        r->v = value27 & 0x40;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi_85c1 << 8) | 1;
    r->x = x_85c1;
    r->y = y2;
    r->c = value18 & 0x80;
    r->v = value19 & 0x40;
    r->mf = 1;
    r->xf = 1;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08598, SOM_RTS, "gen", advance_complete_ui_scale_input_and_boundary_transitions, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 160, 87)

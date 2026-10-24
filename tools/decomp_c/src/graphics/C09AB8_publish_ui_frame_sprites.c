#include "som_c.h"

static void prepare_ui_sprite_grid_component_three(SomCtx *c);
static void prepare_ui_sprite_grid_component_three_v2(SomCtx *c);

/* C09AB8 publish_ui_frame_sprites   [class B, 166 bytes, 77 instructions]
 * Source: src/rom/publish_ui_frame_sprites.s
 * Entry: M=any X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void publish_ui_frame_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_9ad0 = 0;
    uint8_t y_9ad0 = 0;
    bool carry_9ad0 = 0;
    bool overflow_9ad0 = 0;
    if (RAM8(0x008C) == 0) {
        a_hi_9ad0 = a >> 8;
        y_9ad0 = (uint8_t)y;
        carry_9ad0 = carry;
        overflow_9ad0 = overflow;
        goto shared_9AD0;
    }
    uint8_t value2 = RAM8(0x00E3);
    if ((value2 & 6) != 0) {
        a_hi_9ad0 = a >> 8;
        y_9ad0 = (uint8_t)y;
        carry_9ad0 = carry;
        overflow_9ad0 = overflow;
        goto shared_9AD0;
    }
    if (value2 & 0x01) {
        r->x = (uint8_t)x;
        r->y = (uint8_t)y;
        r->c = value2 & 0x01;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->a = (a >> 8 << 8) | (value2 >> 1);
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->c = value2 & 0x01;
    r->z = value2 >> 1 == 0;
    r->n = value2 >> 1 & 0x80;
    r->mf = 1;
    r->xf = 1;
    TAIL_CALL(c, 0xC09DFC, SOM_RTS); /* advance_and_publish_automatic_ui_party_icons */
    shared_9AD0:;
    uint8_t value3 = RAM8(0x00BF);
    if (value3 != 0) {
        RAM8(0x007C) = 0;
        uint8_t value4 = RAM8(0x007C);
        uint8_t a_hi1 = a_hi_9ad0;
        uint8_t x1 = value4;
        for (;;) {
            RAM16_SET(0x0800 + x1, 0xE0FF);
            a_hi1 = 0xE0;
            x1 = (uint8_t)(x1 + 4);
            if (!(x1 != 0)) break;
        }
        r->a = (a_hi1 << 8) | (uint8_t)a;
        r->x = x1;
        r->y = y_9ad0;
        r->c = carry_9ad0;
        r->v = overflow_9ad0;
        r->mf = 0;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value5 = RAM8(0x007A);
    uint8_t value6 = RAM8(0x007B);
    uint8_t a_hi2;
    uint8_t x2;
    uint8_t y1;
    bool carry1;
    bool overflow1;
    if (value5 == value6) {
        r->a = (a_hi_9ad0 << 8) | value3;
        r->x = value5;
        r->y = y_9ad0;
        r->c = value5 >= value6;
        r->z = value5 == value6;
        r->n = (uint8_t)(value5 - value6) & 0x80;
        r->v = overflow_9ad0;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9AE3, 0xC09D0A); GUARD_JSR(c, sp_call, 0x9AE3); } /* advance_ui_sprite_coordinates_and_hardware_timed_phase */
        uint16_t a_all = r->a;
        uint8_t x_ret = r->x;
        uint8_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    } else {
        RAM8(0x007B) = value5;
        r->a = (a_hi_9ad0 << 8) | value3;
        r->x = value5;
        r->y = y_9ad0;
        r->c = value5 >= value6;
        r->z = value5 == value6;
        r->n = (uint8_t)(value5 - value6) & 0x80;
        r->v = overflow_9ad0;
        r->mf = 1;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9ADE, 0xC09D78); GUARD_JSR(c, sp_call, 0x9ADE); } /* select_scene_color_targets_from_cursor_and_fade_flags */
        uint16_t a_all2 = r->a;
        uint8_t x_ret2 = r->x;
        uint8_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        a_hi2 = a_all2 >> 8;
        x2 = x_ret2;
        y1 = y_ret2;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    }
    uint8_t value7 = RAM8(0x00F2);
    if (!(value7 & 0x80)) {
        if ((RAM8(0x005F) & 4) == 0) {
            uint8_t value9 = RAM8(0x007A);
            uint8_t a3;
            if (value9 == 0) {
                a3 = 0;
            } else {
                uint8_t a2;
                if (!(value9 & 0x80)) {
                    a2 = 4;
                } else {
                    uint8_t a1;
                    if (value9 & 0x80) {
                        a1 = 2;
                    } else {
                        a1 = 0;
                    }
                    a2 = a1;
                }
                a3 = a2;
            }
            RAM8(0x0010) = a3;
            uint8_t value10 = RAM8(0x00F4);
            if (value10 & 0x01) {
                r->a = (a_hi2 << 8) | (value10 >> 1);
                r->x = x2;
                r->y = y1;
                r->c = value10 & 0x01;
                r->z = value10 >> 1 == 0;
                r->n = value10 >> 1 & 0x80;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x9B20, 0xC09B7B); GUARD_JSR(c, sp_call, 0x9B20); } /* prepare_ui_sprite_grid_component_one */
                uint16_t dp_ret = r->dp;
                uint8_t db_ret = r->db;
                { const uint16_t sp_call = r->sp; JSR(c, 0x9B23, 0xC09B4B); GUARD_JSR(c, sp_call, 0x9B23); } /* prepare_ui_sprite_grid_component_zero */
                uint16_t a_all4 = r->a;
                uint8_t y_ret4 = r->y;
                bool carry_ret4 = r->c;
                bool overflow_ret4 = r->v;
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x7C));
                uint8_t a_hi3 = a_all4 >> 8;
                uint8_t x3 = value11;
                for (;;) {
                    BUS16_SET(c, (db_ret << 0x10) + 0x0800 + x3, 0xE0FF);
                    a_hi3 = 0xE0;
                    x3 = (uint8_t)(x3 + 4);
                    if (!(x3 != 0)) break;
                }
                r->a = (a_hi3 << 8) | (uint8_t)a;
                r->x = x3;
                r->y = y_ret4;
                r->c = carry_ret4;
                r->v = overflow_ret4;
                r->mf = 0;
                r->xf = 1;
                RETURN_RTS(c);
            }
            RAM8(0x007C) = 0;
            RAM8(RING_OPEN) = 0;
            r->a = (a_hi2 << 8) | 0;
            r->x = x2;
            r->y = y1;
            r->c = value10 & 0x01;
            r->z = 1;
            r->n = 0;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9B14, 0xC09BEE); GUARD_JSR(c, sp_call, 0x9B14); } /* prepare_ui_sprite_grid_component_five */
            { const uint16_t sp_call = r->sp; JSR(c, 0x9B17, 0xC09B6B); GUARD_JSR(c, sp_call, 0x9B17); } /* prepare_ui_sprite_grid_component_four */
            if (r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9B1A, prepare_ui_sprite_grid_component_three, sp_in, 2); GUARD_JSR(c, sp_call, 0x9B1A); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9B1A, prepare_ui_sprite_grid_component_three_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x9B1A); }
            r->mf = 1;
            r->xf = 1;
            TAIL_CALL(c, 0xC09B9A, SOM_RTS); /* prepare_ui_sprite_grid_component_two */
        }
        RAM8(0x0010) = 6;
        uint8_t value12 = RAM8(0x00F4);
        if (!(value12 & 0x01)) {
            r->a = (a_hi2 << 8) | (value12 >> 1);
            r->x = x2;
            r->y = y1;
            r->c = value12 & 0x01;
            r->z = value12 >> 1 == 0;
            r->n = value12 >> 1 & 0x80;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9B3E, 0xC09B9A); GUARD_JSR(c, sp_call, 0x9B3E); } /* prepare_ui_sprite_grid_component_two */
            if (r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9B41, prepare_ui_sprite_grid_component_three, sp_in, 2); GUARD_JSR(c, sp_call, 0x9B41); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9B41, prepare_ui_sprite_grid_component_three_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x9B41); }
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9B44, 0xC09B6B); GUARD_JSR(c, sp_call, 0x9B44); } /* prepare_ui_sprite_grid_component_four */
            { const uint16_t sp_call = r->sp; JSR(c, 0x9B47, 0xC09BEE); GUARD_JSR(c, sp_call, 0x9B47); } /* prepare_ui_sprite_grid_component_five */
            uint16_t dp_ret8 = r->dp;
            uint8_t db_ret8 = r->db;
            uint16_t a_all11 = r->a;
            uint16_t y_ret11 = r->y;
            bool carry_ret11 = r->c;
            bool overflow_ret11 = r->v;
            uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 0x7C));
            uint8_t a_hi4 = a_all11 >> 8;
            uint8_t x4 = value13;
            for (;;) {
                BUS16_SET(c, (db_ret8 << 0x10) + 0x0800 + x4, 0xE0FF);
                a_hi4 = 0xE0;
                x4 = (uint8_t)(x4 + 4);
                if (!(x4 != 0)) break;
            }
            r->a = (a_hi4 << 8) | (uint8_t)a;
            r->x = x4;
            r->y = (uint8_t)y_ret11;
            r->c = carry_ret11;
            r->v = overflow_ret11;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        RAM8(0x007C) = 0;
        RAM8(RING_OPEN) = 0;
        r->a = (a_hi2 << 8) | 0;
        r->x = x2;
        r->y = y1;
        r->c = value12 & 0x01;
        r->z = 1;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9B38, 0xC09B4B); GUARD_JSR(c, sp_call, 0x9B38); } /* prepare_ui_sprite_grid_component_zero */
        r->mf = 1;
        r->xf = 1;
        TAIL_CALL(c, 0xC09B7B, SOM_RTS); /* prepare_ui_sprite_grid_component_one */
    }
    r->a = (a_hi2 << 8) | value7;
    r->x = x2;
    r->y = y1;
    r->c = carry1;
    r->z = value7 == 0;
    r->n = value7 & 0x80;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 1;
    TAIL_CALL(c, 0xC09F02, SOM_RTS); /* publish_signed_turn_ui_sprite_components */
}
SOM_REGISTER(0xC09AB8, SOM_RTS, "gen", publish_ui_frame_sprites, 0, L_B | L_X | L_Y | L_C | L_V, 9, -1, -1, 836, 77)

/* C09B5B prepare_ui_sprite_grid_component_three   [class A, 65 bytes, 33 instructions]
 * Source: src/rom/publish_ui_frame_sprites.s
 * Subroutine of publish_ui_frame_sprites, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void prepare_ui_sprite_grid_component_three(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    BUS16_SET(c, (uint16_t)(dp + 8), 0xF8F8);
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x10));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0xA09A + value);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}

/* C09B5B prepare_ui_sprite_grid_component_three_v2   [class A, 65 bytes, 33 instructions]
 * Source: src/rom/publish_ui_frame_sprites.s
 * Subroutine of publish_ui_frame_sprites, translated in place.
 * Entry: M=any X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void prepare_ui_sprite_grid_component_three_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 1)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    BUS16_SET(c, (uint16_t)(dp + 8), 0xF8F8);
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0xA09A + value);
    BUS16_SET(c, dp, value2);
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x0A43);
    uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x9CD9 + value3);
    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0xCF));
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp + 9));
    BUS8_SET(c, (uint16_t)(dp + 9), (uint8_t)((uint8_t)((uint8_t)(value4 + 0x50) - value5) + value6));
    uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0x0A49);
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 0x5F));
    uint8_t a1;
    if (value8 != 4) {
        a1 = value7;
    } else {
        a1 = (uint8_t)((((uint8_t)(value7 - 0x80) >> 1) | (((uint8_t)(value7 - 0x80) >= 0x80) << 7)) + 0x80);
    }
    uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 8));
    BUS8_SET(c, (uint16_t)(dp + 8), (uint8_t)(a1 + value9));
    BUS8_SET(c, (uint16_t)(dp + 0x12), 0);
    r->a = (value2 >> 8 << 8) | (uint8_t)(a1 + value9);
    r->x = value8;
    r->y = 3;
    r->c = a1 + value9 > 0xFF;
    r->z = (uint8_t)(a1 + value9) == 0;
    r->n = (uint8_t)(a1 + value9) & 0x80;
    r->v = ((a1 ^ (uint8_t)(a1 + value9)) & (value9 ^ (uint8_t)(a1 + value9)) & 0x80) != 0;
    r->mf = 1;
    TAIL_CALL(c, 0xC09C2B, SOM_RTS); /* emit_ui_sprite_tile_grid */
}

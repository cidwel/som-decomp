#include "som_c.h"

static void select_and_emit_actor_sprite_lists(SomCtx *c);
static void clip_and_emit_ground_shadow_piece(SomCtx *c);
static void clip_and_emit_ground_shadow_piece_v2(SomCtx *c);
static void prepare_and_emit_actor_body_sprites(SomCtx *c);
static void prepare_and_emit_actor_body_sprites_v2(SomCtx *c);
static void sub_C0E5F5(SomCtx *c);
static void sub_C0E5F5_v2(SomCtx *c);
static void emit_packed_actor_sprite_list(SomCtx *c);
static void emit_packed_actor_sprite_list_v2(SomCtx *c);

/* C0E3CF emit_one_actor_or_boss_sprite   [class C, 361 bytes, 166 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXC.
 */
static void emit_one_actor_or_boss_sprite(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM16_SET(0x0014, x);
    if (x < 0x0600) {
        uint8_t value = RAM8(0xE000 + x);
        if (value != 0) {
            if (value & 0x80) {
                SET_A8(r, value);
                r->c = x >= 0x0600;
                RETURN_RTS(c);
            }
            RAM8(0x0000 + sp0) = x >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
            r->a = (a_hi << 8) | value;
            r->c = x >= 0x0600;
            r->z = value == 0;
            r->n = value & 0x80;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xE409, 0xC0E40E); GUARD_JSR(c, sp_call, 0xE409); } /* update_actor_screen_position_and_emit_sprites */
            r->sp += 2;
            bool x_ret = r->xf;
            if (x_ret) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                uint8_t value3 = RAM8(0x0000 + sp0 - 1);
                uint8_t value4 = RAM8(0x0000 + sp0);
                RAM16_SET(0x0004, 0xFFF8);
                uint8_t value5 = RAM8(0xE00F + ((value4 << 8) | value3));
                if (value5 == 0) {
                    uint8_t value6 = RAM8(0xCF01);
                    if ((value6 & 6) == 0) {
                        uint8_t value7 = RAM8(0xE00E + ((value4 << 8) | value3));
                        if (value7 & 0x80) {
                            SET_A8(r, value7);
                            r->x = (value4 << 8) | value3;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value8 = RAM8(0xE074 + ((value4 << 8) | value3));
                        if (!(value8 & 0x80)) {
                            SET_A8(r, value8);
                            r->x = (value4 << 8) | value3;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x000E) = 0;
                        uint8_t value9 = RAM8(0xE08E + ((value4 << 8) | value3));
                        if (value9 == 0) {
                            RAM8(0x000F) = RAM8(0xE08B + ((value4 << 8) | value3)) & 0x30;
                            uint8_t value11 = RAM8(0xE089 + ((value4 << 8) | value3));
                            if ((value11 & 3) == 0) {
                                r->a = 0x0200;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF8;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece(c); return;
                            }
                            if ((uint8_t)((value11 & 3) - 1) == 0) {
                                r->a = 0x0202;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF0;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                                r->a = 0x4202;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            if ((uint8_t)((value11 & 3) - 2) == 0) {
                                r->a = 0x0204;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF0;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                                r->a = 0x4204;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            r->a = 0x0206;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFE8;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                            r->a = 0x0208;
                            r->y = 0xFFF8;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                            r->a = 0x4206;
                            r->y = 8;
                            r->z = 0;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        RAM8(0x000F) = (uint8_t)(value9 << 4) & 0x30;
                        uint8_t value12 = RAM8(0xE089 + ((value4 << 8) | value3));
                        if ((value12 & 3) == 0) {
                            r->a = 0x0200;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF8;
                            r->c = (uint8_t)(value9 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece(c); return;
                        }
                        if ((uint8_t)((value12 & 3) - 1) == 0) {
                            r->a = 0x0202;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value9 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                            r->a = 0x4202;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        if ((uint8_t)((value12 & 3) - 2) == 0) {
                            r->a = 0x0204;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value9 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                            r->a = 0x4204;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        r->a = 0x0206;
                        r->x = (value4 << 8) | value3;
                        r->y = 0xFFE8;
                        r->c = (uint8_t)(value9 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                        r->a = 0x0208;
                        r->y = 0xFFF8;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                        r->a = 0x4206;
                        r->y = 8;
                        r->z = 0;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    if ((value6 & 4) == 0) {
                        if (((value4 << 8) | value3) < 0x0600) {
                            SET_A8(r, value6);
                            r->x = (value4 << 8) | value3;
                            r->c = ((value4 << 8) | value3) >= 0x0600;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value13 = RAM8(0xE00E + ((value4 << 8) | value3));
                        if (value13 & 0x80) {
                            SET_A8(r, value13);
                            r->x = (value4 << 8) | value3;
                            r->c = ((value4 << 8) | value3) >= 0x0600;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value14 = RAM8(0xE074 + ((value4 << 8) | value3));
                        if (!(value14 & 0x80)) {
                            SET_A8(r, value14);
                            r->x = (value4 << 8) | value3;
                            r->c = ((value4 << 8) | value3) >= 0x0600;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x000E) = 0;
                        uint8_t value15 = RAM8(0xE08E + ((value4 << 8) | value3));
                        if (value15 == 0) {
                            RAM8(0x000F) = RAM8(0xE08B + ((value4 << 8) | value3)) & 0x30;
                            uint8_t value17 = RAM8(0xE089 + ((value4 << 8) | value3));
                            if ((value17 & 3) == 0) {
                                r->a = 0x0200;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF8;
                                r->c = ((value4 << 8) | value3) >= 0x0600;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece(c); return;
                            }
                            if ((uint8_t)((value17 & 3) - 1) == 0) {
                                r->a = 0x0202;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF0;
                                r->c = ((value4 << 8) | value3) >= 0x0600;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                                r->a = 0x4202;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            if ((uint8_t)((value17 & 3) - 2) == 0) {
                                r->a = 0x0204;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF0;
                                r->c = ((value4 << 8) | value3) >= 0x0600;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                                r->a = 0x4204;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            r->a = 0x0206;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFE8;
                            r->c = ((value4 << 8) | value3) >= 0x0600;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                            r->a = 0x0208;
                            r->y = 0xFFF8;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                            r->a = 0x4206;
                            r->y = 8;
                            r->z = 0;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        RAM8(0x000F) = (uint8_t)(value15 << 4) & 0x30;
                        uint8_t value18 = RAM8(0xE089 + ((value4 << 8) | value3));
                        if ((value18 & 3) == 0) {
                            r->a = 0x0200;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF8;
                            r->c = (uint8_t)(value15 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece(c); return;
                        }
                        if ((uint8_t)((value18 & 3) - 1) == 0) {
                            r->a = 0x0202;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value15 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                            r->a = 0x4202;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        if ((uint8_t)((value18 & 3) - 2) == 0) {
                            r->a = 0x0204;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value15 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                            r->a = 0x4204;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        r->a = 0x0206;
                        r->x = (value4 << 8) | value3;
                        r->y = 0xFFE8;
                        r->c = (uint8_t)(value15 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                        r->a = 0x0208;
                        r->y = 0xFFF8;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                        r->a = 0x4206;
                        r->y = 8;
                        r->z = 0;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    uint16_t value19 = RAM16(0x00D4);
                    if (((value4 << 8) | value3) == value19) {
                        SET_A8(r, value6);
                        r->x = (value4 << 8) | value3;
                        r->c = ((value4 << 8) | value3) >= value19;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    if (((value4 << 8) | value3) != value19) {
                        uint8_t value20 = RAM8(0xE00E + ((value4 << 8) | value3));
                        if (value20 & 0x80) {
                            SET_A8(r, value20);
                            r->x = (value4 << 8) | value3;
                            r->c = ((value4 << 8) | value3) >= value19;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value21 = RAM8(0xE074 + ((value4 << 8) | value3));
                        if (!(value21 & 0x80)) {
                            SET_A8(r, value21);
                            r->x = (value4 << 8) | value3;
                            r->c = ((value4 << 8) | value3) >= value19;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x000E) = 0;
                        uint8_t value22 = RAM8(0xE08E + ((value4 << 8) | value3));
                        if (value22 == 0) {
                            RAM8(0x000F) = RAM8(0xE08B + ((value4 << 8) | value3)) & 0x30;
                            uint8_t value24 = RAM8(0xE089 + ((value4 << 8) | value3));
                            if ((value24 & 3) == 0) {
                                r->a = 0x0200;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF8;
                                r->c = ((value4 << 8) | value3) >= value19;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece(c); return;
                            }
                            if ((uint8_t)((value24 & 3) - 1) == 0) {
                                r->a = 0x0202;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF0;
                                r->c = ((value4 << 8) | value3) >= value19;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                                r->a = 0x4202;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            if ((uint8_t)((value24 & 3) - 2) == 0) {
                                r->a = 0x0204;
                                r->x = (value4 << 8) | value3;
                                r->y = 0xFFF0;
                                r->c = ((value4 << 8) | value3) >= value19;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                                r->a = 0x4204;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            r->a = 0x0206;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFE8;
                            r->c = ((value4 << 8) | value3) >= value19;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                            r->a = 0x0208;
                            r->y = 0xFFF8;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                            r->a = 0x4206;
                            r->y = 8;
                            r->z = 0;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        RAM8(0x000F) = (uint8_t)(value22 << 4) & 0x30;
                        uint8_t value25 = RAM8(0xE089 + ((value4 << 8) | value3));
                        if ((value25 & 3) == 0) {
                            r->a = 0x0200;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF8;
                            r->c = (uint8_t)(value22 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece(c); return;
                        }
                        if ((uint8_t)((value25 & 3) - 1) == 0) {
                            r->a = 0x0202;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value22 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                            r->a = 0x4202;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        if ((uint8_t)((value25 & 3) - 2) == 0) {
                            r->a = 0x0204;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value22 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                            r->a = 0x4204;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        r->a = 0x0206;
                        r->x = (value4 << 8) | value3;
                        r->y = 0xFFE8;
                        r->c = (uint8_t)(value22 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                        r->a = 0x0208;
                        r->y = 0xFFF8;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                        r->a = 0x4206;
                        r->y = 8;
                        r->z = 0;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    if (((value4 << 8) | value3) < 0x0600) {
                        SET_A8(r, value6);
                        r->x = (value4 << 8) | value3;
                        r->c = ((value4 << 8) | value3) >= 0x0600;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value26 = RAM8(0xE00E + ((value4 << 8) | value3));
                    if (value26 & 0x80) {
                        SET_A8(r, value26);
                        r->x = (value4 << 8) | value3;
                        r->c = ((value4 << 8) | value3) >= 0x0600;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value27 = RAM8(0xE074 + ((value4 << 8) | value3));
                    if (!(value27 & 0x80)) {
                        SET_A8(r, value27);
                        r->x = (value4 << 8) | value3;
                        r->c = ((value4 << 8) | value3) >= 0x0600;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x000E) = 0;
                    uint8_t value28 = RAM8(0xE08E + ((value4 << 8) | value3));
                    if (value28 == 0) {
                        RAM8(0x000F) = RAM8(0xE08B + ((value4 << 8) | value3)) & 0x30;
                        uint8_t value30 = RAM8(0xE089 + ((value4 << 8) | value3));
                        if ((value30 & 3) == 0) {
                            r->a = 0x0200;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF8;
                            r->c = ((value4 << 8) | value3) >= 0x0600;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece(c); return;
                        }
                        if ((uint8_t)((value30 & 3) - 1) == 0) {
                            r->a = 0x0202;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF0;
                            r->c = ((value4 << 8) | value3) >= 0x0600;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                            r->a = 0x4202;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        if ((uint8_t)((value30 & 3) - 2) == 0) {
                            r->a = 0x0204;
                            r->x = (value4 << 8) | value3;
                            r->y = 0xFFF0;
                            r->c = ((value4 << 8) | value3) >= 0x0600;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                            r->a = 0x4204;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        r->a = 0x0206;
                        r->x = (value4 << 8) | value3;
                        r->y = 0xFFE8;
                        r->c = ((value4 << 8) | value3) >= 0x0600;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                        r->a = 0x0208;
                        r->y = 0xFFF8;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                        r->a = 0x4206;
                        r->y = 8;
                        r->z = 0;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    RAM8(0x000F) = (uint8_t)(value28 << 4) & 0x30;
                    uint8_t value31 = RAM8(0xE089 + ((value4 << 8) | value3));
                    if ((value31 & 3) == 0) {
                        r->a = 0x0200;
                        r->x = (value4 << 8) | value3;
                        r->y = 0xFFF8;
                        r->c = (uint8_t)(value28 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece(c); return;
                    }
                    if ((uint8_t)((value31 & 3) - 1) == 0) {
                        r->a = 0x0202;
                        r->x = (value4 << 8) | value3;
                        r->y = 0xFFF0;
                        r->c = (uint8_t)(value28 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                        r->a = 0x4202;
                        r->y = 0;
                        r->z = 1;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    if ((uint8_t)((value31 & 3) - 2) == 0) {
                        r->a = 0x0204;
                        r->x = (value4 << 8) | value3;
                        r->y = 0xFFF0;
                        r->c = (uint8_t)(value28 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                        r->a = 0x4204;
                        r->y = 0;
                        r->z = 1;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    r->a = 0x0206;
                    r->x = (value4 << 8) | value3;
                    r->y = 0xFFE8;
                    r->c = (uint8_t)(value28 << 3) & 0x80;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                    r->a = 0x0208;
                    r->y = 0xFFF8;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                    r->a = 0x4206;
                    r->y = 8;
                    r->z = 0;
                    r->n = 0;
                    r->mf = 0;
                    r->xf = 0;
                    clip_and_emit_ground_shadow_piece_v2(c); return;
                }
                SET_A8(r, value5);
                r->x = (value4 << 8) | value3;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
        SET_A8(r, value);
        r->c = x >= 0x0600;
        RETURN_RTS(c);
    }
    uint8_t value32 = RAM8(0x005C);
    if (!(value32 & 0x80)) {
        uint8_t value33 = RAM8(0xE000 + x);
        if (value33 != 0) {
            if (value33 & 0x80) {
                SET_A8(r, value33);
                r->c = x >= 0x0600;
                RETURN_RTS(c);
            }
            RAM8(0x0000 + sp0) = x >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
            r->a = (a_hi << 8) | value33;
            r->c = x >= 0x0600;
            r->z = value33 == 0;
            r->n = value33 & 0x80;
            r->v = value32 & 0x40;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xE409, 0xC0E40E); GUARD_JSR(c, sp_call, 0xE409); } /* update_actor_screen_position_and_emit_sprites */
            r->sp += 2;
            bool x_ret35 = r->xf;
            if (x_ret35) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                uint8_t value35 = RAM8(0x0000 + sp0 - 1);
                uint8_t value36 = RAM8(0x0000 + sp0);
                RAM16_SET(0x0004, 0xFFF8);
                uint8_t value37 = RAM8(0xE00F + ((value36 << 8) | value35));
                if (value37 == 0) {
                    uint8_t value38 = RAM8(0xCF01);
                    if ((value38 & 6) == 0) {
                        uint8_t value39 = RAM8(0xE00E + ((value36 << 8) | value35));
                        if (value39 & 0x80) {
                            SET_A8(r, value39);
                            r->x = (value36 << 8) | value35;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value40 = RAM8(0xE074 + ((value36 << 8) | value35));
                        if (!(value40 & 0x80)) {
                            SET_A8(r, value40);
                            r->x = (value36 << 8) | value35;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x000E) = 0;
                        uint8_t value41 = RAM8(0xE08E + ((value36 << 8) | value35));
                        if (value41 == 0) {
                            RAM8(0x000F) = RAM8(0xE08B + ((value36 << 8) | value35)) & 0x30;
                            uint8_t value43 = RAM8(0xE089 + ((value36 << 8) | value35));
                            if ((value43 & 3) == 0) {
                                r->a = 0x0200;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF8;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece(c); return;
                            }
                            if ((uint8_t)((value43 & 3) - 1) == 0) {
                                r->a = 0x0202;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF0;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                                r->a = 0x4202;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            if ((uint8_t)((value43 & 3) - 2) == 0) {
                                r->a = 0x0204;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF0;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                                r->a = 0x4204;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            r->a = 0x0206;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFE8;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                            r->a = 0x0208;
                            r->y = 0xFFF8;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                            r->a = 0x4206;
                            r->y = 8;
                            r->z = 0;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        RAM8(0x000F) = (uint8_t)(value41 << 4) & 0x30;
                        uint8_t value44 = RAM8(0xE089 + ((value36 << 8) | value35));
                        if ((value44 & 3) == 0) {
                            r->a = 0x0200;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF8;
                            r->c = (uint8_t)(value41 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece(c); return;
                        }
                        if ((uint8_t)((value44 & 3) - 1) == 0) {
                            r->a = 0x0202;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value41 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                            r->a = 0x4202;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        if ((uint8_t)((value44 & 3) - 2) == 0) {
                            r->a = 0x0204;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value41 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                            r->a = 0x4204;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        r->a = 0x0206;
                        r->x = (value36 << 8) | value35;
                        r->y = 0xFFE8;
                        r->c = (uint8_t)(value41 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                        r->a = 0x0208;
                        r->y = 0xFFF8;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                        r->a = 0x4206;
                        r->y = 8;
                        r->z = 0;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    if ((value38 & 4) == 0) {
                        if (((value36 << 8) | value35) < 0x0600) {
                            SET_A8(r, value38);
                            r->x = (value36 << 8) | value35;
                            r->c = ((value36 << 8) | value35) >= 0x0600;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value45 = RAM8(0xE00E + ((value36 << 8) | value35));
                        if (value45 & 0x80) {
                            SET_A8(r, value45);
                            r->x = (value36 << 8) | value35;
                            r->c = ((value36 << 8) | value35) >= 0x0600;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value46 = RAM8(0xE074 + ((value36 << 8) | value35));
                        if (!(value46 & 0x80)) {
                            SET_A8(r, value46);
                            r->x = (value36 << 8) | value35;
                            r->c = ((value36 << 8) | value35) >= 0x0600;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x000E) = 0;
                        uint8_t value47 = RAM8(0xE08E + ((value36 << 8) | value35));
                        if (value47 == 0) {
                            RAM8(0x000F) = RAM8(0xE08B + ((value36 << 8) | value35)) & 0x30;
                            uint8_t value49 = RAM8(0xE089 + ((value36 << 8) | value35));
                            if ((value49 & 3) == 0) {
                                r->a = 0x0200;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF8;
                                r->c = ((value36 << 8) | value35) >= 0x0600;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece(c); return;
                            }
                            if ((uint8_t)((value49 & 3) - 1) == 0) {
                                r->a = 0x0202;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF0;
                                r->c = ((value36 << 8) | value35) >= 0x0600;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                                r->a = 0x4202;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            if ((uint8_t)((value49 & 3) - 2) == 0) {
                                r->a = 0x0204;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF0;
                                r->c = ((value36 << 8) | value35) >= 0x0600;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                                r->a = 0x4204;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            r->a = 0x0206;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFE8;
                            r->c = ((value36 << 8) | value35) >= 0x0600;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                            r->a = 0x0208;
                            r->y = 0xFFF8;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                            r->a = 0x4206;
                            r->y = 8;
                            r->z = 0;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        RAM8(0x000F) = (uint8_t)(value47 << 4) & 0x30;
                        uint8_t value50 = RAM8(0xE089 + ((value36 << 8) | value35));
                        if ((value50 & 3) == 0) {
                            r->a = 0x0200;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF8;
                            r->c = (uint8_t)(value47 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece(c); return;
                        }
                        if ((uint8_t)((value50 & 3) - 1) == 0) {
                            r->a = 0x0202;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value47 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                            r->a = 0x4202;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        if ((uint8_t)((value50 & 3) - 2) == 0) {
                            r->a = 0x0204;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value47 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                            r->a = 0x4204;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        r->a = 0x0206;
                        r->x = (value36 << 8) | value35;
                        r->y = 0xFFE8;
                        r->c = (uint8_t)(value47 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                        r->a = 0x0208;
                        r->y = 0xFFF8;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                        r->a = 0x4206;
                        r->y = 8;
                        r->z = 0;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    uint16_t value51 = RAM16(0x00D4);
                    if (((value36 << 8) | value35) == value51) {
                        SET_A8(r, value38);
                        r->x = (value36 << 8) | value35;
                        r->c = ((value36 << 8) | value35) >= value51;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    if (((value36 << 8) | value35) != value51) {
                        uint8_t value52 = RAM8(0xE00E + ((value36 << 8) | value35));
                        if (value52 & 0x80) {
                            SET_A8(r, value52);
                            r->x = (value36 << 8) | value35;
                            r->c = ((value36 << 8) | value35) >= value51;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value53 = RAM8(0xE074 + ((value36 << 8) | value35));
                        if (!(value53 & 0x80)) {
                            SET_A8(r, value53);
                            r->x = (value36 << 8) | value35;
                            r->c = ((value36 << 8) | value35) >= value51;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x000E) = 0;
                        uint8_t value54 = RAM8(0xE08E + ((value36 << 8) | value35));
                        if (value54 == 0) {
                            RAM8(0x000F) = RAM8(0xE08B + ((value36 << 8) | value35)) & 0x30;
                            uint8_t value56 = RAM8(0xE089 + ((value36 << 8) | value35));
                            if ((value56 & 3) == 0) {
                                r->a = 0x0200;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF8;
                                r->c = ((value36 << 8) | value35) >= value51;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece(c); return;
                            }
                            if ((uint8_t)((value56 & 3) - 1) == 0) {
                                r->a = 0x0202;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF0;
                                r->c = ((value36 << 8) | value35) >= value51;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                                r->a = 0x4202;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            if ((uint8_t)((value56 & 3) - 2) == 0) {
                                r->a = 0x0204;
                                r->x = (value36 << 8) | value35;
                                r->y = 0xFFF0;
                                r->c = ((value36 << 8) | value35) >= value51;
                                r->z = 0;
                                r->n = 1;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                                r->a = 0x4204;
                                r->y = 0;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 0;
                                r->xf = 0;
                                clip_and_emit_ground_shadow_piece_v2(c); return;
                            }
                            r->a = 0x0206;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFE8;
                            r->c = ((value36 << 8) | value35) >= value51;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                            r->a = 0x0208;
                            r->y = 0xFFF8;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                            r->a = 0x4206;
                            r->y = 8;
                            r->z = 0;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        RAM8(0x000F) = (uint8_t)(value54 << 4) & 0x30;
                        uint8_t value57 = RAM8(0xE089 + ((value36 << 8) | value35));
                        if ((value57 & 3) == 0) {
                            r->a = 0x0200;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF8;
                            r->c = (uint8_t)(value54 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece(c); return;
                        }
                        if ((uint8_t)((value57 & 3) - 1) == 0) {
                            r->a = 0x0202;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value54 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                            r->a = 0x4202;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        if ((uint8_t)((value57 & 3) - 2) == 0) {
                            r->a = 0x0204;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF0;
                            r->c = (uint8_t)(value54 << 3) & 0x80;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                            r->a = 0x4204;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        r->a = 0x0206;
                        r->x = (value36 << 8) | value35;
                        r->y = 0xFFE8;
                        r->c = (uint8_t)(value54 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                        r->a = 0x0208;
                        r->y = 0xFFF8;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                        r->a = 0x4206;
                        r->y = 8;
                        r->z = 0;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    if (((value36 << 8) | value35) < 0x0600) {
                        SET_A8(r, value38);
                        r->x = (value36 << 8) | value35;
                        r->c = ((value36 << 8) | value35) >= 0x0600;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value58 = RAM8(0xE00E + ((value36 << 8) | value35));
                    if (value58 & 0x80) {
                        SET_A8(r, value58);
                        r->x = (value36 << 8) | value35;
                        r->c = ((value36 << 8) | value35) >= 0x0600;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value59 = RAM8(0xE074 + ((value36 << 8) | value35));
                    if (!(value59 & 0x80)) {
                        SET_A8(r, value59);
                        r->x = (value36 << 8) | value35;
                        r->c = ((value36 << 8) | value35) >= 0x0600;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x000E) = 0;
                    uint8_t value60 = RAM8(0xE08E + ((value36 << 8) | value35));
                    if (value60 == 0) {
                        RAM8(0x000F) = RAM8(0xE08B + ((value36 << 8) | value35)) & 0x30;
                        uint8_t value62 = RAM8(0xE089 + ((value36 << 8) | value35));
                        if ((value62 & 3) == 0) {
                            r->a = 0x0200;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF8;
                            r->c = ((value36 << 8) | value35) >= 0x0600;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece(c); return;
                        }
                        if ((uint8_t)((value62 & 3) - 1) == 0) {
                            r->a = 0x0202;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF0;
                            r->c = ((value36 << 8) | value35) >= 0x0600;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                            r->a = 0x4202;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        if ((uint8_t)((value62 & 3) - 2) == 0) {
                            r->a = 0x0204;
                            r->x = (value36 << 8) | value35;
                            r->y = 0xFFF0;
                            r->c = ((value36 << 8) | value35) >= 0x0600;
                            r->z = 0;
                            r->n = 1;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                            r->a = 0x4204;
                            r->y = 0;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 0;
                            r->xf = 0;
                            clip_and_emit_ground_shadow_piece_v2(c); return;
                        }
                        r->a = 0x0206;
                        r->x = (value36 << 8) | value35;
                        r->y = 0xFFE8;
                        r->c = ((value36 << 8) | value35) >= 0x0600;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                        r->a = 0x0208;
                        r->y = 0xFFF8;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                        r->a = 0x4206;
                        r->y = 8;
                        r->z = 0;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    RAM8(0x000F) = (uint8_t)(value60 << 4) & 0x30;
                    uint8_t value63 = RAM8(0xE089 + ((value36 << 8) | value35));
                    if ((value63 & 3) == 0) {
                        r->a = 0x0200;
                        r->x = (value36 << 8) | value35;
                        r->y = 0xFFF8;
                        r->c = (uint8_t)(value60 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece(c); return;
                    }
                    if ((uint8_t)((value63 & 3) - 1) == 0) {
                        r->a = 0x0202;
                        r->x = (value36 << 8) | value35;
                        r->y = 0xFFF0;
                        r->c = (uint8_t)(value60 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7C7, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7C7); }
                        r->a = 0x4202;
                        r->y = 0;
                        r->z = 1;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    if ((uint8_t)((value63 & 3) - 2) == 0) {
                        r->a = 0x0204;
                        r->x = (value36 << 8) | value35;
                        r->y = 0xFFF0;
                        r->c = (uint8_t)(value60 << 3) & 0x80;
                        r->z = 0;
                        r->n = 1;
                        r->mf = 0;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7DD, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7DD); }
                        r->a = 0x4204;
                        r->y = 0;
                        r->z = 1;
                        r->n = 0;
                        r->mf = 0;
                        r->xf = 0;
                        clip_and_emit_ground_shadow_piece_v2(c); return;
                    }
                    r->a = 0x0206;
                    r->x = (value36 << 8) | value35;
                    r->y = 0xFFE8;
                    r->c = (uint8_t)(value60 << 3) & 0x80;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7F3, clip_and_emit_ground_shadow_piece, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7F3); }
                    r->a = 0x0208;
                    r->y = 0xFFF8;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE7FE, clip_and_emit_ground_shadow_piece_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE7FE); }
                    r->a = 0x4206;
                    r->y = 8;
                    r->z = 0;
                    r->n = 0;
                    r->mf = 0;
                    r->xf = 0;
                    clip_and_emit_ground_shadow_piece_v2(c); return;
                }
                SET_A8(r, value37);
                r->x = (value36 << 8) | value35;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
        SET_A8(r, value33);
        r->c = x >= 0x0600;
        RETURN_RTS(c);
    }
    uint8_t value64 = RAM8(0xE000 + x);
    if (value64 == 0) {
        SET_A8(r, value64);
        r->c = x >= 0x0600;
        RETURN_RTS(c);
    }
    if (x >= 0x0C00) {
        r->a = ((uint8_t)((uint16_t)(x - 0x0600) >> 1) << 8) | ((uint16_t)(x - 0x0600) >> 1 >> 8);
        r->c = (uint16_t)(x - 0x0600) & 0x01;
        r->z = (uint16_t)(x - 0x0600) >> 1 >> 8 == 0;
        r->n = (uint16_t)(x - 0x0600) >> 1 >> 8 & 0x80;
        r->v = ((x ^ 0x0600) & (x ^ (uint16_t)(x - 0x0600)) & 0x8000) != 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xE3FC, 0xC20006); GUARD_JSL(c, sp_call, 0xE3FC); } /* boss_selected_object_emission_public_jump */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint8_t value65 = RAM8(0xE060 + x);
    if (value65 == 0) {
        r->a = ((uint8_t)((uint16_t)(x - 0x0600) >> 1) << 8) | ((uint16_t)(x - 0x0600) >> 1 >> 8);
        r->c = (uint16_t)(x - 0x0600) & 0x01;
        r->z = (uint16_t)(x - 0x0600) >> 1 >> 8 == 0;
        r->n = (uint16_t)(x - 0x0600) >> 1 >> 8 & 0x80;
        r->v = ((x ^ 0x0600) & (x ^ (uint16_t)(x - 0x0600)) & 0x8000) != 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xE3FC, 0xC20006); GUARD_JSL(c, sp_call, 0xE3FC); } /* boss_selected_object_emission_public_jump */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->a = (a_hi << 8) | value65;
    r->c = x >= 0x0C00;
    r->z = value65 == 0;
    r->n = value65 & 0x80;
    r->v = value32 & 0x40;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE3EE, select_and_emit_actor_sprite_lists, sp_in, 2); GUARD_JSR(c, sp_call, 0xE3EE); }
    r->sp += 2;
    bool x_ret73 = r->xf;
    if (x_ret73) {
        c->fail = 3;
        return;
    } else {
        uint8_t value67 = RAM8(0x0000 + sp0 - 1);
        uint8_t value68 = RAM8(0x0000 + sp0);
        r->a = ((uint8_t)((uint16_t)(((value68 << 8) | value67) - 0x0600) >> 1) << 8) | ((uint16_t)(((value68 << 8) | value67) - 0x0600) >> 1 >> 8);
        r->x = (value68 << 8) | value67;
        r->c = (uint16_t)(((value68 << 8) | value67) - 0x0600) & 0x01;
        r->z = (uint16_t)(((value68 << 8) | value67) - 0x0600) >> 1 >> 8 == 0;
        r->n = (uint16_t)(((value68 << 8) | value67) - 0x0600) >> 1 >> 8 & 0x80;
        r->v = ((((value68 << 8) | value67) ^ 0x0600) & (((value68 << 8) | value67) ^ (uint16_t)(((value68 << 8) | value67) - 0x0600)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xE3FC, 0xC20006); GUARD_JSL(c, sp_call, 0xE3FC); } /* boss_selected_object_emission_public_jump */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC0E3CF, SOM_RTS, "gen", emit_one_actor_or_boss_sprite, 0, L_A | L_B | L_X | L_C, 38, 1, 0, 1211, 166)

/* C0E4C1 select_and_emit_actor_sprite_lists   [class A, 748 bytes, 340 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void select_and_emit_actor_sprite_lists(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t a_hi_e553 = 0;
    uint16_t x_e553 = 0;
    uint16_t y_e553 = 0;
    bool carry_e553 = 0;
    bool overflow_e553 = 0;
    uint8_t a_e4f0 = 0;
    uint8_t a_hi_e4f0 = 0;
    uint16_t x_e4f0 = 0;
    uint16_t y_e4f0 = 0;
    bool overflow_e4f0 = 0;
    uint8_t value = RAM8(0xE084 + x);
    RAM8(0x0002) = value & 0x0F;
    if ((value & 0x0F) == 0) {
        uint16_t value2 = RAM16(0x0014);
        if (value2 < 0x0600) {
            r->a = a >> 8 << 8 | (value & 0x0F);
            r->x = value2;
            r->c = value2 >= 0x0600;
            r->z = value2 == 0x0600;
            r->n = (uint16_t)(value2 - 0x0600) & 0x8000;
            r->mf = 1;
            prepare_and_emit_actor_body_sprites(c); return;
        }
        uint8_t value3 = RAM8(0x005C);
        if (value3 & 0x80) {
            SET_A8(r, value & 0x0F);
            r->x = value2;
            r->c = value2 >= 0x0600;
            r->z = (value & 0x0F & value3) == 0;
            r->n = value3 & 0x80;
            r->v = value3 & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        r->a = a >> 8 << 8 | (value & 0x0F);
        r->x = value2;
        r->c = value2 >= 0x0600;
        r->z = (value & 0x0F & value3) == 0;
        r->n = value3 & 0x80;
        r->v = value3 & 0x40;
        r->mf = 1;
        prepare_and_emit_actor_body_sprites(c); return;
    }
    uint8_t value4 = RAM8(0x00ED);
    if (value4 & 0x80) {
        uint8_t value5 = RAM8(0xE060 + x);
        if (value5 == 0) {
            a_hi_e553 = a >> 8;
            x_e553 = x;
            y_e553 = y;
            carry_e553 = carry;
            overflow_e553 = value4 & 0x40;
            goto shared_E553;
        }
        a_e4f0 = value5;
        a_hi_e4f0 = a >> 8;
        x_e4f0 = x;
        y_e4f0 = y;
        overflow_e4f0 = value4 & 0x40;
        goto shared_E4F0;
    }
    if (value4 & 0x40) {
        uint16_t value6 = RAM16(0x0014);
        if (value6 < 0x0600) {
            r->a = a >> 8 << 8 | (value & 0x0F);
            r->x = value6;
            r->c = value6 >= 0x0600;
            r->z = value6 == 0x0600;
            r->n = (uint16_t)(value6 - 0x0600) & 0x8000;
            r->v = value4 & 0x40;
            r->mf = 1;
            prepare_and_emit_actor_body_sprites(c); return;
        }
        uint8_t value7 = RAM8(0x005C);
        if (value7 & 0x80) {
            SET_A8(r, value & 0x0F);
            r->x = value6;
            r->c = value6 >= 0x0600;
            r->z = (value & 0x0F & value7) == 0;
            r->n = value7 & 0x80;
            r->v = value7 & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        r->a = a >> 8 << 8 | (value & 0x0F);
        r->x = value6;
        r->c = value6 >= 0x0600;
        r->z = (value & 0x0F & value7) == 0;
        r->n = value7 & 0x80;
        r->v = value7 & 0x40;
        r->mf = 1;
        prepare_and_emit_actor_body_sprites(c); return;
    }
    if (x >= 0x0600) {
        uint16_t value8 = RAM16(0x0014);
        if (value8 < 0x0600) {
            r->a = a >> 8 << 8 | (value & 0x0F);
            r->x = value8;
            r->c = value8 >= 0x0600;
            r->z = value8 == 0x0600;
            r->n = (uint16_t)(value8 - 0x0600) & 0x8000;
            r->v = value4 & 0x40;
            r->mf = 1;
            prepare_and_emit_actor_body_sprites(c); return;
        }
        uint8_t value9 = RAM8(0x005C);
        if (value9 & 0x80) {
            SET_A8(r, value & 0x0F);
            r->x = value8;
            r->c = value8 >= 0x0600;
            r->z = (value & 0x0F & value9) == 0;
            r->n = value9 & 0x80;
            r->v = value9 & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        r->a = a >> 8 << 8 | (value & 0x0F);
        r->x = value8;
        r->c = value8 >= 0x0600;
        r->z = (value & 0x0F & value9) == 0;
        r->n = value9 & 0x80;
        r->v = value9 & 0x40;
        r->mf = 1;
        prepare_and_emit_actor_body_sprites(c); return;
    }
    if (RAM8(0xE02F + x) != 0) {
        a_hi_e553 = a >> 8;
        x_e553 = x;
        y_e553 = y;
        carry_e553 = x >= 0x0600;
        overflow_e553 = value4 & 0x40;
        goto shared_E553;
    }
    uint8_t value11 = RAM8(0xE060 + x);
    if (value11 != 0) {
        a_e4f0 = value11;
        a_hi_e4f0 = a >> 8;
        x_e4f0 = x;
        y_e4f0 = y;
        overflow_e4f0 = value4 & 0x40;
        goto shared_E4F0;
    }
    uint8_t value12 = RAM8(ACTOR_STATUS_HIGH + x);
    if ((value12 & 0xC5) != 0) {
        a_hi_e553 = a >> 8;
        x_e553 = x;
        y_e553 = y;
        carry_e553 = x >= 0x0600;
        overflow_e553 = value4 & 0x40;
        goto shared_E553;
    }
    uint16_t value13 = RAM16(0x0014);
    if (value13 < 0x0600) {
        r->a = (a >> 8 << 8) | value12;
        r->x = value13;
        r->c = value13 >= 0x0600;
        r->z = value13 == 0x0600;
        r->n = (uint16_t)(value13 - 0x0600) & 0x8000;
        r->v = value4 & 0x40;
        r->mf = 1;
        prepare_and_emit_actor_body_sprites(c); return;
    }
    uint8_t value14 = RAM8(0x005C);
    if (value14 & 0x80) {
        SET_A8(r, value12);
        r->x = value13;
        r->c = value13 >= 0x0600;
        r->z = (value12 & value14) == 0;
        r->n = value14 & 0x80;
        r->v = value14 & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    r->a = (a >> 8 << 8) | value12;
    r->x = value13;
    r->c = value13 >= 0x0600;
    r->z = (value12 & value14) == 0;
    r->n = value14 & 0x80;
    r->v = value14 & 0x40;
    r->mf = 1;
    prepare_and_emit_actor_body_sprites(c); return;
    shared_E553:;
    uint8_t value15 = RAM8(0xE024 + x_e553);
    if (!(value15 & 0x80)) {
        r->a = (a_hi_e553 << 8) | value15;
        r->x = x_e553;
        r->y = y_e553;
        r->c = carry_e553;
        r->z = value15 == 0;
        r->n = value15 & 0x80;
        r->v = overflow_e553;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE567, prepare_and_emit_actor_body_sprites, sp_in, 2); GUARD_JSR(c, sp_call, 0xE567); }
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x14));
        uint16_t value17 = BUS16_RDP(c, (db_ret << 0x10) + 0xE084 + value16);
        BUS16_SET(c, (uint16_t)(dp_ret + 2), value17 & 0x0F);
        r->a = value16 | 0xE0D0;
        r->x = value16;
        r->y = value16 | 0xE0D0;
        r->z = (value16 | 0xE0D0) == 0;
        r->n = (value16 | 0xE0D0) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        sub_C0E5F5(c); return;
    }
    r->a = x_e553 | 0xE0D0;
    r->x = x_e553;
    r->y = x_e553 | 0xE0D0;
    r->c = carry_e553;
    r->z = (x_e553 | 0xE0D0) == 0;
    r->n = (x_e553 | 0xE0D0) & 0x8000;
    r->v = overflow_e553;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE561, sub_C0E5F5_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE561); }
    r->xf = 0;
    prepare_and_emit_actor_body_sprites_v2(c); return;
    shared_E4F0:;
    if (a_e4f0 != 0xE0) {
        if (a_e4f0 == 0x20) {
            a_hi_e553 = a_hi_e4f0;
            x_e553 = x_e4f0;
            y_e553 = y_e4f0;
            carry_e553 = a_e4f0 >= 0x20;
            overflow_e553 = overflow_e4f0;
            goto shared_E553;
        }
        bool m_flag26;
        uint8_t a32;
        uint8_t a_hi32;
        uint16_t y26;
        bool overflow26;
        uint8_t data_bank26;
        uint16_t direct_page26;
        if (a_e4f0 == 0x40) {
            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + x_e4f0)));
            uint16_t value20 = RAM16(0xE074 + x_e4f0);
            uint16_t value21 = RAM16(0xE045 + x_e4f0);
            uint16_t value22 = RAM16(0xE11A + x_e4f0);
            uint16_t value23 = RAM16(0xE022 + x_e4f0);
            RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF)));
            r->a = x_e4f0 | 0xE0D0;
            r->x = x_e4f0 | 0xE0D0;
            r->y = y_e4f0;
            r->c = (uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF) > 0xFFFF;
            r->z = (x_e4f0 | 0xE0D0) == 0;
            r->n = (x_e4f0 | 0xE0D0) & 0x8000;
            r->v = (((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & (value23 ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            bool m_ret3 = r->mf;
            uint16_t a_all3 = r->a;
            uint16_t y_ret3 = r->y;
            bool overflow_ret3 = r->v;
            m_flag26 = m_ret3;
            a32 = (uint8_t)a_all3;
            a_hi32 = a_all3 >> 8;
            y26 = y_ret3;
            overflow26 = overflow_ret3;
            data_bank26 = db_ret3;
            direct_page26 = dp_ret3;
        } else {
            bool m_flag25;
            uint8_t a31;
            uint8_t a_hi31;
            uint16_t y25;
            bool overflow25;
            uint8_t data_bank25;
            uint16_t direct_page25;
            if (a_e4f0 == 0x80) {
                RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + x_e4f0)));
                uint16_t value26 = RAM16(0xE074 + x_e4f0);
                uint16_t value27 = RAM16(0xE045 + x_e4f0);
                uint16_t value28 = RAM16(0xE11A + x_e4f0);
                uint16_t value29 = RAM16(0xE022 + x_e4f0);
                RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1) + value29 + (((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1 > 0xFFFF)));
                r->a = x_e4f0 | 0xE0D0;
                r->x = x_e4f0 | 0xE0D0;
                r->y = y_e4f0;
                r->c = (uint16_t)(((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1) + value29 + (((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1 > 0xFFFF) > 0xFFFF;
                r->z = (x_e4f0 | 0xE0D0) == 0;
                r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                r->v = (((uint16_t)(((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1) + value29 + (((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1 > 0xFFFF))) & (value29 ^ (uint16_t)((uint16_t)(((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1) + value29 + (((uint16_t)((value26 & 0x7F) + value27) ^ 0xFFFF) + value28 + 1 > 0xFFFF))) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
                uint16_t dp_ret4 = r->dp;
                uint8_t db_ret4 = r->db;
                bool m_ret4 = r->mf;
                uint16_t a_all4 = r->a;
                uint16_t y_ret4 = r->y;
                bool overflow_ret4 = r->v;
                m_flag25 = m_ret4;
                a31 = (uint8_t)a_all4;
                a_hi31 = a_all4 >> 8;
                y25 = y_ret4;
                overflow25 = overflow_ret4;
                data_bank25 = db_ret4;
                direct_page25 = dp_ret4;
            } else {
                uint8_t value30 = RAM8(0xE00E + x_e4f0);
                bool m_flag24;
                uint8_t a30;
                uint8_t a_hi30;
                uint16_t y24;
                bool overflow24;
                uint8_t data_bank24;
                uint16_t direct_page24;
                if ((value30 & 0x20) == 0) {
                    uint8_t value31 = RAM8(0xE110 + x_e4f0);
                    bool m_flag7;
                    uint8_t a9;
                    uint8_t a_hi9;
                    uint16_t y7;
                    bool overflow7;
                    uint8_t data_bank7;
                    uint16_t direct_page7;
                    if (value31 < 5) {
                        uint8_t value32 = RAM8(0xE028 + x_e4f0);
                        bool m_flag2;
                        uint8_t a2;
                        uint8_t a_hi2;
                        uint16_t y2;
                        bool overflow2;
                        uint8_t data_bank2;
                        uint16_t direct_page2;
                        if ((value32 & 0x20) != 0) {
                            bool m_flag;
                            uint8_t a1;
                            uint8_t a_hi1;
                            uint16_t y1;
                            bool overflow1;
                            uint8_t data_bank;
                            uint16_t direct_page;
                            if ((value32 & 0x10) == 0) {
                                RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + 0x80));
                                uint16_t value34 = RAM16(0xE11A + x_e4f0);
                                RAM16_SET(0x0006, (uint16_t)(value34 + 0x70));
                                r->a = x_e4f0 | 0xE0D0;
                                r->x = x_e4f0 | 0xE0D0;
                                r->y = y_e4f0;
                                r->c = value34 + 0x70 > 0xFFFF;
                                r->z = (x_e4f0 | 0xE0D0) == 0;
                                r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                r->v = ((value34 ^ (uint16_t)(value34 + 0x70)) & ((uint16_t)(value34 + 0x70) ^ 0x70) & 0x8000) != 0;
                                r->mf = 0;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5CA, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5CA); }
                                uint16_t dp_ret5 = r->dp;
                                uint8_t db_ret5 = r->db;
                                bool m_ret5 = r->mf;
                                uint16_t a_all5 = r->a;
                                uint16_t y_ret5 = r->y;
                                bool overflow_ret5 = r->v;
                                m_flag = m_ret5;
                                a1 = (uint8_t)a_all5;
                                a_hi1 = a_all5 >> 8;
                                y1 = y_ret5;
                                overflow1 = overflow_ret5;
                                data_bank = db_ret5;
                                direct_page = dp_ret5;
                            } else {
                                uint16_t value35 = RAM16(0xE10C + x_e4f0);
                                RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + value35)));
                                uint16_t value38 = RAM16(0xE074 + value35);
                                uint16_t value39 = RAM16(0xE045 + value35);
                                uint16_t value40 = RAM16(0xE11A + x_e4f0);
                                uint16_t value41 = RAM16(0xE022 + value35);
                                RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1) + value41 + (((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1 > 0xFFFF)));
                                r->a = x_e4f0 | 0xE0D0;
                                r->x = x_e4f0 | 0xE0D0;
                                r->y = value35;
                                r->c = (uint16_t)(((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1) + value41 + (((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1 > 0xFFFF) > 0xFFFF;
                                r->z = (x_e4f0 | 0xE0D0) == 0;
                                r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                r->v = (((uint16_t)(((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1) + value41 + (((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1 > 0xFFFF))) & (value41 ^ (uint16_t)((uint16_t)(((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1) + value41 + (((uint16_t)((value38 & 0x7F) + value39) ^ 0xFFFF) + value40 + 1 > 0xFFFF))) & 0x8000) != 0;
                                r->mf = 0;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5AB, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5AB); }
                                uint16_t dp_ret6 = r->dp;
                                uint8_t db_ret6 = r->db;
                                bool m_ret6 = r->mf;
                                uint16_t a_all6 = r->a;
                                uint16_t y_ret6 = r->y;
                                bool overflow_ret6 = r->v;
                                m_flag = m_ret6;
                                a1 = (uint8_t)a_all6;
                                a_hi1 = a_all6 >> 8;
                                y1 = y_ret6;
                                overflow1 = overflow_ret6;
                                data_bank = db_ret6;
                                direct_page = dp_ret6;
                            }
                            m_flag2 = m_flag;
                            a2 = a1;
                            a_hi2 = a_hi1;
                            y2 = y1;
                            overflow2 = overflow1;
                            data_bank2 = data_bank;
                            direct_page2 = direct_page;
                        } else {
                            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + x_e4f0)));
                            uint16_t value44 = RAM16(0xE074 + x_e4f0);
                            uint16_t value45 = RAM16(0xE045 + x_e4f0);
                            uint16_t value46 = RAM16(0xE11A + x_e4f0);
                            uint16_t value47 = RAM16(0xE022 + x_e4f0);
                            RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1) + value47 + (((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1 > 0xFFFF)));
                            r->a = x_e4f0 | 0xE0D0;
                            r->x = x_e4f0 | 0xE0D0;
                            r->y = y_e4f0;
                            r->c = (uint16_t)(((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1) + value47 + (((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1 > 0xFFFF) > 0xFFFF;
                            r->z = (x_e4f0 | 0xE0D0) == 0;
                            r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                            r->v = (((uint16_t)(((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1) + value47 + (((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1 > 0xFFFF))) & (value47 ^ (uint16_t)((uint16_t)(((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1) + value47 + (((uint16_t)((value44 & 0x7F) + value45) ^ 0xFFFF) + value46 + 1 > 0xFFFF))) & 0x8000) != 0;
                            r->mf = 0;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
                            uint16_t dp_ret7 = r->dp;
                            uint8_t db_ret7 = r->db;
                            bool m_ret7 = r->mf;
                            uint16_t a_all7 = r->a;
                            uint16_t y_ret7 = r->y;
                            bool overflow_ret7 = r->v;
                            m_flag2 = m_ret7;
                            a2 = (uint8_t)a_all7;
                            a_hi2 = a_all7 >> 8;
                            y2 = y_ret7;
                            overflow2 = overflow_ret7;
                            data_bank2 = db_ret7;
                            direct_page2 = dp_ret7;
                        }
                        m_flag7 = m_flag2;
                        a9 = a2;
                        a_hi9 = a_hi2;
                        y7 = y2;
                        overflow7 = overflow2;
                        data_bank7 = data_bank2;
                        direct_page7 = direct_page2;
                    } else {
                        uint8_t value48 = RAM8(0xE114 + x_e4f0);
                        bool m_flag6;
                        uint8_t a8;
                        uint8_t a_hi8;
                        uint16_t y6;
                        bool overflow6;
                        uint8_t data_bank6;
                        uint16_t direct_page6;
                        if (!(value48 & 0x40)) {
                            uint8_t value49 = RAM8(0xE028 + x_e4f0);
                            bool m_flag4;
                            uint8_t a4;
                            uint8_t a_hi4;
                            uint16_t y4;
                            bool overflow4;
                            uint8_t data_bank4;
                            uint16_t direct_page4;
                            if ((value49 & 0x20) != 0) {
                                bool m_flag3;
                                uint8_t a3;
                                uint8_t a_hi3;
                                uint16_t y3;
                                bool overflow3;
                                uint8_t data_bank3;
                                uint16_t direct_page3;
                                if ((value49 & 0x10) == 0) {
                                    RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + 0x80));
                                    uint16_t value51 = RAM16(0xE11A + x_e4f0);
                                    RAM16_SET(0x0006, (uint16_t)(value51 + 0x70));
                                    r->a = x_e4f0 | 0xE0D0;
                                    r->x = x_e4f0 | 0xE0D0;
                                    r->y = y_e4f0;
                                    r->c = value51 + 0x70 > 0xFFFF;
                                    r->z = (x_e4f0 | 0xE0D0) == 0;
                                    r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                    r->v = ((value51 ^ (uint16_t)(value51 + 0x70)) & ((uint16_t)(value51 + 0x70) ^ 0x70) & 0x8000) != 0;
                                    r->mf = 0;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5CA, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5CA); }
                                    uint16_t dp_ret8 = r->dp;
                                    uint8_t db_ret8 = r->db;
                                    bool m_ret8 = r->mf;
                                    uint16_t a_all8 = r->a;
                                    uint16_t y_ret8 = r->y;
                                    bool overflow_ret8 = r->v;
                                    m_flag3 = m_ret8;
                                    a3 = (uint8_t)a_all8;
                                    a_hi3 = a_all8 >> 8;
                                    y3 = y_ret8;
                                    overflow3 = overflow_ret8;
                                    data_bank3 = db_ret8;
                                    direct_page3 = dp_ret8;
                                } else {
                                    uint16_t value52 = RAM16(0xE10C + x_e4f0);
                                    RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + value52)));
                                    uint16_t value55 = RAM16(0xE074 + value52);
                                    uint16_t value56 = RAM16(0xE045 + value52);
                                    uint16_t value57 = RAM16(0xE11A + x_e4f0);
                                    uint16_t value58 = RAM16(0xE022 + value52);
                                    RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1) + value58 + (((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1 > 0xFFFF)));
                                    r->a = x_e4f0 | 0xE0D0;
                                    r->x = x_e4f0 | 0xE0D0;
                                    r->y = value52;
                                    r->c = (uint16_t)(((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1) + value58 + (((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1 > 0xFFFF) > 0xFFFF;
                                    r->z = (x_e4f0 | 0xE0D0) == 0;
                                    r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                    r->v = (((uint16_t)(((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1) + value58 + (((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1 > 0xFFFF))) & (value58 ^ (uint16_t)((uint16_t)(((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1) + value58 + (((uint16_t)((value55 & 0x7F) + value56) ^ 0xFFFF) + value57 + 1 > 0xFFFF))) & 0x8000) != 0;
                                    r->mf = 0;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5AB, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5AB); }
                                    uint16_t dp_ret9 = r->dp;
                                    uint8_t db_ret9 = r->db;
                                    bool m_ret9 = r->mf;
                                    uint16_t a_all9 = r->a;
                                    uint16_t y_ret9 = r->y;
                                    bool overflow_ret9 = r->v;
                                    m_flag3 = m_ret9;
                                    a3 = (uint8_t)a_all9;
                                    a_hi3 = a_all9 >> 8;
                                    y3 = y_ret9;
                                    overflow3 = overflow_ret9;
                                    data_bank3 = db_ret9;
                                    direct_page3 = dp_ret9;
                                }
                                m_flag4 = m_flag3;
                                a4 = a3;
                                a_hi4 = a_hi3;
                                y4 = y3;
                                overflow4 = overflow3;
                                data_bank4 = data_bank3;
                                direct_page4 = direct_page3;
                            } else {
                                RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + x_e4f0)));
                                uint16_t value61 = RAM16(0xE074 + x_e4f0);
                                uint16_t value62 = RAM16(0xE045 + x_e4f0);
                                uint16_t value63 = RAM16(0xE11A + x_e4f0);
                                uint16_t value64 = RAM16(0xE022 + x_e4f0);
                                RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1) + value64 + (((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1 > 0xFFFF)));
                                r->a = x_e4f0 | 0xE0D0;
                                r->x = x_e4f0 | 0xE0D0;
                                r->y = y_e4f0;
                                r->c = (uint16_t)(((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1) + value64 + (((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1 > 0xFFFF) > 0xFFFF;
                                r->z = (x_e4f0 | 0xE0D0) == 0;
                                r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                r->v = (((uint16_t)(((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1) + value64 + (((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1 > 0xFFFF))) & (value64 ^ (uint16_t)((uint16_t)(((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1) + value64 + (((uint16_t)((value61 & 0x7F) + value62) ^ 0xFFFF) + value63 + 1 > 0xFFFF))) & 0x8000) != 0;
                                r->mf = 0;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
                                uint16_t dp_ret10 = r->dp;
                                uint8_t db_ret10 = r->db;
                                bool m_ret10 = r->mf;
                                uint16_t a_all10 = r->a;
                                uint16_t y_ret10 = r->y;
                                bool overflow_ret10 = r->v;
                                m_flag4 = m_ret10;
                                a4 = (uint8_t)a_all10;
                                a_hi4 = a_all10 >> 8;
                                y4 = y_ret10;
                                overflow4 = overflow_ret10;
                                data_bank4 = db_ret10;
                                direct_page4 = dp_ret10;
                            }
                            m_flag6 = m_flag4;
                            a8 = a4;
                            a_hi8 = a_hi4;
                            y6 = y4;
                            overflow6 = overflow4;
                            data_bank6 = data_bank4;
                            direct_page6 = direct_page4;
                        } else {
                            bool m_flag5;
                            uint8_t a7;
                            uint8_t a_hi7;
                            uint16_t y5;
                            bool overflow5;
                            uint8_t data_bank5;
                            uint16_t direct_page5;
                            if (value31 != 5) {
                                uint8_t value65 = RAM8(0xE116 + x_e4f0);
                                RAM8(0x0000 + sp0) = value65;
                                uint8_t a5;
                                if ((value65 & 0x0F) < 6) {
                                    a5 = value65 & 0x0F;
                                } else {
                                    a5 = 5;
                                }
                                RAM8(0x0002) = a5;
                                uint8_t a6;
                                uint8_t a_hi5;
                                if ((value65 & 0x0F) < 6) {
                                    a6 = 0xD0;
                                    a_hi5 = 0;
                                } else {
                                    a6 = (uint8_t)((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value65) & 0x0F) - 5 - ((value65 & 0x0F) >= 6 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value65) & 0x0F) - 5 - ((value65 & 0x0F) >= 6 ^ 1)) << 1) >> 0x0F));
                                    a_hi5 = (uint16_t)((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value65) & 0x0F) - 5 - ((value65 & 0x0F) >= 6 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value65) & 0x0F) - 5 - ((value65 & 0x0F) >= 6 ^ 1)) << 1) >> 0x0F)) >> 8;
                                }
                                uint16_t value66 = RAM16(0x0014);
                                uint16_t value67 = RAM16(0xE028 + x_e4f0);
                                uint8_t a_hi6;
                                uint16_t x1;
                                if ((value67 & 0x30) != 0x30) {
                                    a_hi6 = 0;
                                    x1 = x_e4f0;
                                } else {
                                    uint16_t value68 = RAM16(0xE10C + x_e4f0);
                                    a_hi6 = value68 >> 8;
                                    x1 = value68;
                                }
                                RAM16_SET(0x0004, RAM16(0xE020 + x1));
                                uint16_t value70 = RAM16(0xE074 + x1);
                                uint16_t value71 = RAM16(0xE045 + x1);
                                uint16_t value72 = RAM16(0xE022 + x1);
                                RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30)) ^ 0xFFFF) + value72 + ((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30) > 0xFFFF)));
                                r->a = (uint16_t)(((uint16_t)((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30)) ^ 0xFFFF) + value72 + ((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30) > 0xFFFF));
                                r->x = value66;
                                r->y = (a_hi5 << 8) | a6 | value66 | 0xE000;
                                r->c = ((uint16_t)((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30)) ^ 0xFFFF) + value72 + ((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30) > 0xFFFF) > 0xFFFF;
                                r->z = value66 == 0;
                                r->n = value66 & 0x8000;
                                r->v = (((uint16_t)((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30)) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30)) ^ 0xFFFF) + value72 + ((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30) > 0xFFFF))) & (value72 ^ (uint16_t)(((uint16_t)((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30)) ^ 0xFFFF) + value72 + ((value70 & 0x7F) + value71 + ((value67 & 0x30) >= 0x30) > 0xFFFF))) & 0x8000) != 0;
                                r->mf = 0;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                { const uint16_t sp_call = r->sp; JSL(c, 0xE759, 0x02AB54); GUARD_JSL(c, sp_call, 0xE759); } /* duplicate_and_mirror_actor_sprite_list */
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE75C, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE75C); }
                                uint16_t dp_ret11 = r->dp;
                                uint8_t db_ret11 = r->db;
                                bool m_ret11 = r->mf;
                                uint16_t a_all12 = r->a;
                                uint16_t y_ret12 = r->y;
                                bool overflow_ret12 = r->v;
                                m_flag5 = m_ret11;
                                a7 = (uint8_t)a_all12;
                                a_hi7 = a_all12 >> 8;
                                y5 = y_ret12;
                                overflow5 = overflow_ret12;
                                data_bank5 = db_ret11;
                                direct_page5 = dp_ret11;
                            } else {
                                uint16_t value73 = RAM16(0x0014);
                                RAM8(0x0002) = RAM8(0xE116 + value73) & 0x0F;
                                RAM16_SET(0x0004, RAM16(0xE020 + value73));
                                uint16_t value76 = RAM16(0xE074 + value73);
                                uint16_t value77 = RAM16(0xE045 + value73);
                                uint16_t value78 = RAM16(0xE022 + value73);
                                RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value78 + ((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF)));
                                r->a = value73 | 0xE0D0;
                                r->x = value73 | 0xE0D0;
                                r->y = y_e4f0;
                                r->c = ((uint16_t)((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value78 + ((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF) > 0xFFFF;
                                r->z = (value73 | 0xE0D0) == 0;
                                r->n = (value73 | 0xE0D0) & 0x8000;
                                r->v = (((uint16_t)((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value78 + ((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & (value78 ^ (uint16_t)(((uint16_t)((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value78 + ((value76 & 0x7F) + 0x60 + value77 + ((value76 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & 0x8000) != 0;
                                r->mf = 0;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE700, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE700); }
                                uint16_t dp_ret12 = r->dp;
                                uint8_t db_ret12 = r->db;
                                bool m_ret12 = r->mf;
                                uint16_t a_all13 = r->a;
                                uint16_t y_ret13 = r->y;
                                bool overflow_ret13 = r->v;
                                m_flag5 = m_ret12;
                                a7 = (uint8_t)a_all13;
                                a_hi7 = a_all13 >> 8;
                                y5 = y_ret13;
                                overflow5 = overflow_ret13;
                                data_bank5 = db_ret12;
                                direct_page5 = dp_ret12;
                            }
                            m_flag6 = m_flag5;
                            a8 = a7;
                            a_hi8 = a_hi7;
                            y6 = y5;
                            overflow6 = overflow5;
                            data_bank6 = data_bank5;
                            direct_page6 = direct_page5;
                        }
                        m_flag7 = m_flag6;
                        a9 = a8;
                        a_hi9 = a_hi8;
                        y7 = y6;
                        overflow7 = overflow6;
                        data_bank7 = data_bank6;
                        direct_page7 = direct_page6;
                    }
                    m_flag24 = m_flag7;
                    a30 = a9;
                    a_hi30 = a_hi9;
                    y24 = y7;
                    overflow24 = overflow7;
                    data_bank24 = data_bank7;
                    direct_page24 = direct_page7;
                } else {
                    uint8_t value79 = RAM8(0x00F4);
                    bool m_flag23;
                    uint8_t a29;
                    uint8_t a_hi29;
                    uint16_t y23;
                    bool overflow23;
                    uint8_t data_bank23;
                    uint16_t direct_page23;
                    if (!(value79 & 0x01)) {
                        uint8_t value80 = RAM8(0xE110 + x_e4f0);
                        bool m_flag14;
                        uint8_t a18;
                        uint8_t a_hi18;
                        uint16_t y14;
                        bool overflow14;
                        uint8_t data_bank14;
                        uint16_t direct_page14;
                        if (value80 < 5) {
                            uint8_t value81 = RAM8(0xE028 + x_e4f0);
                            bool m_flag9;
                            uint8_t a11;
                            uint8_t a_hi11;
                            uint16_t y9;
                            bool overflow9;
                            uint8_t data_bank9;
                            uint16_t direct_page9;
                            if ((value81 & 0x20) != 0) {
                                bool m_flag8;
                                uint8_t a10;
                                uint8_t a_hi10;
                                uint16_t y8;
                                bool overflow8;
                                uint8_t data_bank8;
                                uint16_t direct_page8;
                                if ((value81 & 0x10) == 0) {
                                    RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + 0x80));
                                    uint16_t value83 = RAM16(0xE11A + x_e4f0);
                                    RAM16_SET(0x0006, (uint16_t)(value83 + 0x70));
                                    r->a = x_e4f0 | 0xE0D0;
                                    r->x = x_e4f0 | 0xE0D0;
                                    r->y = y_e4f0;
                                    r->c = value83 + 0x70 > 0xFFFF;
                                    r->z = (x_e4f0 | 0xE0D0) == 0;
                                    r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                    r->v = ((value83 ^ (uint16_t)(value83 + 0x70)) & ((uint16_t)(value83 + 0x70) ^ 0x70) & 0x8000) != 0;
                                    r->mf = 0;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5CA, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5CA); }
                                    uint16_t dp_ret13 = r->dp;
                                    uint8_t db_ret13 = r->db;
                                    bool m_ret13 = r->mf;
                                    uint16_t a_all14 = r->a;
                                    uint16_t y_ret14 = r->y;
                                    bool overflow_ret14 = r->v;
                                    m_flag8 = m_ret13;
                                    a10 = (uint8_t)a_all14;
                                    a_hi10 = a_all14 >> 8;
                                    y8 = y_ret14;
                                    overflow8 = overflow_ret14;
                                    data_bank8 = db_ret13;
                                    direct_page8 = dp_ret13;
                                } else {
                                    uint16_t value84 = RAM16(0xE10C + x_e4f0);
                                    RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + value84)));
                                    uint16_t value87 = RAM16(0xE074 + value84);
                                    uint16_t value88 = RAM16(0xE045 + value84);
                                    uint16_t value89 = RAM16(0xE11A + x_e4f0);
                                    uint16_t value90 = RAM16(0xE022 + value84);
                                    RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1) + value90 + (((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1 > 0xFFFF)));
                                    r->a = x_e4f0 | 0xE0D0;
                                    r->x = x_e4f0 | 0xE0D0;
                                    r->y = value84;
                                    r->c = (uint16_t)(((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1) + value90 + (((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1 > 0xFFFF) > 0xFFFF;
                                    r->z = (x_e4f0 | 0xE0D0) == 0;
                                    r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                    r->v = (((uint16_t)(((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1) + value90 + (((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1 > 0xFFFF))) & (value90 ^ (uint16_t)((uint16_t)(((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1) + value90 + (((uint16_t)((value87 & 0x7F) + value88) ^ 0xFFFF) + value89 + 1 > 0xFFFF))) & 0x8000) != 0;
                                    r->mf = 0;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5AB, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5AB); }
                                    uint16_t dp_ret14 = r->dp;
                                    uint8_t db_ret14 = r->db;
                                    bool m_ret14 = r->mf;
                                    uint16_t a_all15 = r->a;
                                    uint16_t y_ret15 = r->y;
                                    bool overflow_ret15 = r->v;
                                    m_flag8 = m_ret14;
                                    a10 = (uint8_t)a_all15;
                                    a_hi10 = a_all15 >> 8;
                                    y8 = y_ret15;
                                    overflow8 = overflow_ret15;
                                    data_bank8 = db_ret14;
                                    direct_page8 = dp_ret14;
                                }
                                m_flag9 = m_flag8;
                                a11 = a10;
                                a_hi11 = a_hi10;
                                y9 = y8;
                                overflow9 = overflow8;
                                data_bank9 = data_bank8;
                                direct_page9 = direct_page8;
                            } else {
                                RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + x_e4f0)));
                                uint16_t value93 = RAM16(0xE074 + x_e4f0);
                                uint16_t value94 = RAM16(0xE045 + x_e4f0);
                                uint16_t value95 = RAM16(0xE11A + x_e4f0);
                                uint16_t value96 = RAM16(0xE022 + x_e4f0);
                                RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1) + value96 + (((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1 > 0xFFFF)));
                                r->a = x_e4f0 | 0xE0D0;
                                r->x = x_e4f0 | 0xE0D0;
                                r->y = y_e4f0;
                                r->c = (uint16_t)(((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1) + value96 + (((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1 > 0xFFFF) > 0xFFFF;
                                r->z = (x_e4f0 | 0xE0D0) == 0;
                                r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                r->v = (((uint16_t)(((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1) + value96 + (((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1 > 0xFFFF))) & (value96 ^ (uint16_t)((uint16_t)(((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1) + value96 + (((uint16_t)((value93 & 0x7F) + value94) ^ 0xFFFF) + value95 + 1 > 0xFFFF))) & 0x8000) != 0;
                                r->mf = 0;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
                                uint16_t dp_ret15 = r->dp;
                                uint8_t db_ret15 = r->db;
                                bool m_ret15 = r->mf;
                                uint16_t a_all16 = r->a;
                                uint16_t y_ret16 = r->y;
                                bool overflow_ret16 = r->v;
                                m_flag9 = m_ret15;
                                a11 = (uint8_t)a_all16;
                                a_hi11 = a_all16 >> 8;
                                y9 = y_ret16;
                                overflow9 = overflow_ret16;
                                data_bank9 = db_ret15;
                                direct_page9 = dp_ret15;
                            }
                            m_flag14 = m_flag9;
                            a18 = a11;
                            a_hi18 = a_hi11;
                            y14 = y9;
                            overflow14 = overflow9;
                            data_bank14 = data_bank9;
                            direct_page14 = direct_page9;
                        } else {
                            uint8_t value97 = RAM8(0xE114 + x_e4f0);
                            bool m_flag13;
                            uint8_t a17;
                            uint8_t a_hi17;
                            uint16_t y13;
                            bool overflow13;
                            uint8_t data_bank13;
                            uint16_t direct_page13;
                            if (!(value97 & 0x40)) {
                                uint8_t value98 = RAM8(0xE028 + x_e4f0);
                                bool m_flag11;
                                uint8_t a13;
                                uint8_t a_hi13;
                                uint16_t y11;
                                bool overflow11;
                                uint8_t data_bank11;
                                uint16_t direct_page11;
                                if ((value98 & 0x20) != 0) {
                                    bool m_flag10;
                                    uint8_t a12;
                                    uint8_t a_hi12;
                                    uint16_t y10;
                                    bool overflow10;
                                    uint8_t data_bank10;
                                    uint16_t direct_page10;
                                    if ((value98 & 0x10) == 0) {
                                        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + 0x80));
                                        uint16_t value100 = RAM16(0xE11A + x_e4f0);
                                        RAM16_SET(0x0006, (uint16_t)(value100 + 0x70));
                                        r->a = x_e4f0 | 0xE0D0;
                                        r->x = x_e4f0 | 0xE0D0;
                                        r->y = y_e4f0;
                                        r->c = value100 + 0x70 > 0xFFFF;
                                        r->z = (x_e4f0 | 0xE0D0) == 0;
                                        r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                        r->v = ((value100 ^ (uint16_t)(value100 + 0x70)) & ((uint16_t)(value100 + 0x70) ^ 0x70) & 0x8000) != 0;
                                        r->mf = 0;
                                        r->xf = 0;
                                        r->db = 0x7E;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5CA, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5CA); }
                                        uint16_t dp_ret16 = r->dp;
                                        uint8_t db_ret16 = r->db;
                                        bool m_ret16 = r->mf;
                                        uint16_t a_all17 = r->a;
                                        uint16_t y_ret17 = r->y;
                                        bool overflow_ret17 = r->v;
                                        m_flag10 = m_ret16;
                                        a12 = (uint8_t)a_all17;
                                        a_hi12 = a_all17 >> 8;
                                        y10 = y_ret17;
                                        overflow10 = overflow_ret17;
                                        data_bank10 = db_ret16;
                                        direct_page10 = dp_ret16;
                                    } else {
                                        uint16_t value101 = RAM16(0xE10C + x_e4f0);
                                        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + value101)));
                                        uint16_t value104 = RAM16(0xE074 + value101);
                                        uint16_t value105 = RAM16(0xE045 + value101);
                                        uint16_t value106 = RAM16(0xE11A + x_e4f0);
                                        uint16_t value107 = RAM16(0xE022 + value101);
                                        RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1) + value107 + (((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1 > 0xFFFF)));
                                        r->a = x_e4f0 | 0xE0D0;
                                        r->x = x_e4f0 | 0xE0D0;
                                        r->y = value101;
                                        r->c = (uint16_t)(((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1) + value107 + (((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1 > 0xFFFF) > 0xFFFF;
                                        r->z = (x_e4f0 | 0xE0D0) == 0;
                                        r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                        r->v = (((uint16_t)(((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1) + value107 + (((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1 > 0xFFFF))) & (value107 ^ (uint16_t)((uint16_t)(((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1) + value107 + (((uint16_t)((value104 & 0x7F) + value105) ^ 0xFFFF) + value106 + 1 > 0xFFFF))) & 0x8000) != 0;
                                        r->mf = 0;
                                        r->xf = 0;
                                        r->db = 0x7E;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5AB, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5AB); }
                                        uint16_t dp_ret17 = r->dp;
                                        uint8_t db_ret17 = r->db;
                                        bool m_ret17 = r->mf;
                                        uint16_t a_all18 = r->a;
                                        uint16_t y_ret18 = r->y;
                                        bool overflow_ret18 = r->v;
                                        m_flag10 = m_ret17;
                                        a12 = (uint8_t)a_all18;
                                        a_hi12 = a_all18 >> 8;
                                        y10 = y_ret18;
                                        overflow10 = overflow_ret18;
                                        data_bank10 = db_ret17;
                                        direct_page10 = dp_ret17;
                                    }
                                    m_flag11 = m_flag10;
                                    a13 = a12;
                                    a_hi13 = a_hi12;
                                    y11 = y10;
                                    overflow11 = overflow10;
                                    data_bank11 = data_bank10;
                                    direct_page11 = direct_page10;
                                } else {
                                    RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + x_e4f0)));
                                    uint16_t value110 = RAM16(0xE074 + x_e4f0);
                                    uint16_t value111 = RAM16(0xE045 + x_e4f0);
                                    uint16_t value112 = RAM16(0xE11A + x_e4f0);
                                    uint16_t value113 = RAM16(0xE022 + x_e4f0);
                                    RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1) + value113 + (((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1 > 0xFFFF)));
                                    r->a = x_e4f0 | 0xE0D0;
                                    r->x = x_e4f0 | 0xE0D0;
                                    r->y = y_e4f0;
                                    r->c = (uint16_t)(((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1) + value113 + (((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1 > 0xFFFF) > 0xFFFF;
                                    r->z = (x_e4f0 | 0xE0D0) == 0;
                                    r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                    r->v = (((uint16_t)(((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1) + value113 + (((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1 > 0xFFFF))) & (value113 ^ (uint16_t)((uint16_t)(((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1) + value113 + (((uint16_t)((value110 & 0x7F) + value111) ^ 0xFFFF) + value112 + 1 > 0xFFFF))) & 0x8000) != 0;
                                    r->mf = 0;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
                                    uint16_t dp_ret18 = r->dp;
                                    uint8_t db_ret18 = r->db;
                                    bool m_ret18 = r->mf;
                                    uint16_t a_all19 = r->a;
                                    uint16_t y_ret19 = r->y;
                                    bool overflow_ret19 = r->v;
                                    m_flag11 = m_ret18;
                                    a13 = (uint8_t)a_all19;
                                    a_hi13 = a_all19 >> 8;
                                    y11 = y_ret19;
                                    overflow11 = overflow_ret19;
                                    data_bank11 = db_ret18;
                                    direct_page11 = dp_ret18;
                                }
                                m_flag13 = m_flag11;
                                a17 = a13;
                                a_hi17 = a_hi13;
                                y13 = y11;
                                overflow13 = overflow11;
                                data_bank13 = data_bank11;
                                direct_page13 = direct_page11;
                            } else {
                                bool m_flag12;
                                uint8_t a16;
                                uint8_t a_hi16;
                                uint16_t y12;
                                bool overflow12;
                                uint8_t data_bank12;
                                uint16_t direct_page12;
                                if (value80 != 5) {
                                    uint8_t value114 = RAM8(0xE116 + x_e4f0);
                                    RAM8(0x0000 + sp0) = value114;
                                    uint8_t a14;
                                    if ((value114 & 0x0F) < 6) {
                                        a14 = value114 & 0x0F;
                                    } else {
                                        a14 = 5;
                                    }
                                    RAM8(0x0002) = a14;
                                    uint8_t a15;
                                    uint8_t a_hi14;
                                    if ((value114 & 0x0F) < 6) {
                                        a15 = 0xD0;
                                        a_hi14 = 0;
                                    } else {
                                        a15 = (uint8_t)((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value114) & 0x0F) - 5 - ((value114 & 0x0F) >= 6 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value114) & 0x0F) - 5 - ((value114 & 0x0F) >= 6 ^ 1)) << 1) >> 0x0F));
                                        a_hi14 = (uint16_t)((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value114) & 0x0F) - 5 - ((value114 & 0x0F) >= 6 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value114) & 0x0F) - 5 - ((value114 & 0x0F) >= 6 ^ 1)) << 1) >> 0x0F)) >> 8;
                                    }
                                    uint16_t value115 = RAM16(0x0014);
                                    uint16_t value116 = RAM16(0xE028 + x_e4f0);
                                    uint8_t a_hi15;
                                    uint16_t x2;
                                    if ((value116 & 0x30) != 0x30) {
                                        a_hi15 = 0;
                                        x2 = x_e4f0;
                                    } else {
                                        uint16_t value117 = RAM16(0xE10C + x_e4f0);
                                        a_hi15 = value117 >> 8;
                                        x2 = value117;
                                    }
                                    RAM16_SET(0x0004, RAM16(0xE020 + x2));
                                    uint16_t value119 = RAM16(0xE074 + x2);
                                    uint16_t value120 = RAM16(0xE045 + x2);
                                    uint16_t value121 = RAM16(0xE022 + x2);
                                    RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30)) ^ 0xFFFF) + value121 + ((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30) > 0xFFFF)));
                                    r->a = (uint16_t)(((uint16_t)((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30)) ^ 0xFFFF) + value121 + ((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30) > 0xFFFF));
                                    r->x = value115;
                                    r->y = (a_hi14 << 8) | a15 | value115 | 0xE000;
                                    r->c = ((uint16_t)((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30)) ^ 0xFFFF) + value121 + ((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30) > 0xFFFF) > 0xFFFF;
                                    r->z = value115 == 0;
                                    r->n = value115 & 0x8000;
                                    r->v = (((uint16_t)((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30)) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30)) ^ 0xFFFF) + value121 + ((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30) > 0xFFFF))) & (value121 ^ (uint16_t)(((uint16_t)((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30)) ^ 0xFFFF) + value121 + ((value119 & 0x7F) + value120 + ((value116 & 0x30) >= 0x30) > 0xFFFF))) & 0x8000) != 0;
                                    r->mf = 0;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    { const uint16_t sp_call = r->sp; JSL(c, 0xE759, 0x02AB54); GUARD_JSL(c, sp_call, 0xE759); } /* duplicate_and_mirror_actor_sprite_list */
                                    r->mf = 0;
                                    r->xf = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE75C, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE75C); }
                                    uint16_t dp_ret19 = r->dp;
                                    uint8_t db_ret19 = r->db;
                                    bool m_ret19 = r->mf;
                                    uint16_t a_all21 = r->a;
                                    uint16_t y_ret21 = r->y;
                                    bool overflow_ret21 = r->v;
                                    m_flag12 = m_ret19;
                                    a16 = (uint8_t)a_all21;
                                    a_hi16 = a_all21 >> 8;
                                    y12 = y_ret21;
                                    overflow12 = overflow_ret21;
                                    data_bank12 = db_ret19;
                                    direct_page12 = dp_ret19;
                                } else {
                                    uint16_t value122 = RAM16(0x0014);
                                    RAM8(0x0002) = RAM8(0xE116 + value122) & 0x0F;
                                    RAM16_SET(0x0004, RAM16(0xE020 + value122));
                                    uint16_t value125 = RAM16(0xE074 + value122);
                                    uint16_t value126 = RAM16(0xE045 + value122);
                                    uint16_t value127 = RAM16(0xE022 + value122);
                                    RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value127 + ((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF)));
                                    r->a = value122 | 0xE0D0;
                                    r->x = value122 | 0xE0D0;
                                    r->y = y_e4f0;
                                    r->c = ((uint16_t)((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value127 + ((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF) > 0xFFFF;
                                    r->z = (value122 | 0xE0D0) == 0;
                                    r->n = (value122 | 0xE0D0) & 0x8000;
                                    r->v = (((uint16_t)((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value127 + ((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & (value127 ^ (uint16_t)(((uint16_t)((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value127 + ((value125 & 0x7F) + 0x60 + value126 + ((value125 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & 0x8000) != 0;
                                    r->mf = 0;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE700, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE700); }
                                    uint16_t dp_ret20 = r->dp;
                                    uint8_t db_ret20 = r->db;
                                    bool m_ret20 = r->mf;
                                    uint16_t a_all22 = r->a;
                                    uint16_t y_ret22 = r->y;
                                    bool overflow_ret22 = r->v;
                                    m_flag12 = m_ret20;
                                    a16 = (uint8_t)a_all22;
                                    a_hi16 = a_all22 >> 8;
                                    y12 = y_ret22;
                                    overflow12 = overflow_ret22;
                                    data_bank12 = db_ret20;
                                    direct_page12 = dp_ret20;
                                }
                                m_flag13 = m_flag12;
                                a17 = a16;
                                a_hi17 = a_hi16;
                                y13 = y12;
                                overflow13 = overflow12;
                                data_bank13 = data_bank12;
                                direct_page13 = direct_page12;
                            }
                            m_flag14 = m_flag13;
                            a18 = a17;
                            a_hi18 = a_hi17;
                            y14 = y13;
                            overflow14 = overflow13;
                            data_bank14 = data_bank13;
                            direct_page14 = direct_page13;
                        }
                        m_flag23 = m_flag14;
                        a29 = a18;
                        a_hi29 = a_hi18;
                        y23 = y14;
                        overflow23 = overflow14;
                        data_bank23 = data_bank14;
                        direct_page23 = direct_page14;
                    } else {
                        bool m_flag22;
                        uint8_t a28;
                        uint8_t a_hi28;
                        uint16_t y22;
                        bool overflow22;
                        uint8_t data_bank22;
                        uint16_t direct_page22;
                        if (value79 & 0x01) {
                            m_flag22 = 1;
                            a28 = value79 >> 1;
                            a_hi28 = a_hi_e4f0;
                            y22 = y_e4f0;
                            overflow22 = overflow_e4f0;
                            data_bank22 = 0x7E;
                            direct_page22 = 0;
                        } else {
                            uint8_t value128 = RAM8(0xE110 + x_e4f0);
                            bool m_flag21;
                            uint8_t a27;
                            uint8_t a_hi27;
                            uint16_t y21;
                            bool overflow21;
                            uint8_t data_bank21;
                            uint16_t direct_page21;
                            if (value128 < 5) {
                                uint8_t value129 = RAM8(0xE028 + x_e4f0);
                                bool m_flag16;
                                uint8_t a20;
                                uint8_t a_hi20;
                                uint16_t y16;
                                bool overflow16;
                                uint8_t data_bank16;
                                uint16_t direct_page16;
                                if ((value129 & 0x20) != 0) {
                                    bool m_flag15;
                                    uint8_t a19;
                                    uint8_t a_hi19;
                                    uint16_t y15;
                                    bool overflow15;
                                    uint8_t data_bank15;
                                    uint16_t direct_page15;
                                    if ((value129 & 0x10) == 0) {
                                        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + 0x80));
                                        uint16_t value131 = RAM16(0xE11A + x_e4f0);
                                        RAM16_SET(0x0006, (uint16_t)(value131 + 0x70));
                                        r->a = x_e4f0 | 0xE0D0;
                                        r->x = x_e4f0 | 0xE0D0;
                                        r->y = y_e4f0;
                                        r->c = value131 + 0x70 > 0xFFFF;
                                        r->z = (x_e4f0 | 0xE0D0) == 0;
                                        r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                        r->v = ((value131 ^ (uint16_t)(value131 + 0x70)) & ((uint16_t)(value131 + 0x70) ^ 0x70) & 0x8000) != 0;
                                        r->mf = 0;
                                        r->xf = 0;
                                        r->db = 0x7E;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5CA, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5CA); }
                                        uint16_t dp_ret21 = r->dp;
                                        uint8_t db_ret21 = r->db;
                                        bool m_ret21 = r->mf;
                                        uint16_t a_all23 = r->a;
                                        uint16_t y_ret23 = r->y;
                                        bool overflow_ret23 = r->v;
                                        m_flag15 = m_ret21;
                                        a19 = (uint8_t)a_all23;
                                        a_hi19 = a_all23 >> 8;
                                        y15 = y_ret23;
                                        overflow15 = overflow_ret23;
                                        data_bank15 = db_ret21;
                                        direct_page15 = dp_ret21;
                                    } else {
                                        uint16_t value132 = RAM16(0xE10C + x_e4f0);
                                        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + value132)));
                                        uint16_t value135 = RAM16(0xE074 + value132);
                                        uint16_t value136 = RAM16(0xE045 + value132);
                                        uint16_t value137 = RAM16(0xE11A + x_e4f0);
                                        uint16_t value138 = RAM16(0xE022 + value132);
                                        RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1) + value138 + (((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1 > 0xFFFF)));
                                        r->a = x_e4f0 | 0xE0D0;
                                        r->x = x_e4f0 | 0xE0D0;
                                        r->y = value132;
                                        r->c = (uint16_t)(((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1) + value138 + (((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1 > 0xFFFF) > 0xFFFF;
                                        r->z = (x_e4f0 | 0xE0D0) == 0;
                                        r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                        r->v = (((uint16_t)(((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1) + value138 + (((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1 > 0xFFFF))) & (value138 ^ (uint16_t)((uint16_t)(((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1) + value138 + (((uint16_t)((value135 & 0x7F) + value136) ^ 0xFFFF) + value137 + 1 > 0xFFFF))) & 0x8000) != 0;
                                        r->mf = 0;
                                        r->xf = 0;
                                        r->db = 0x7E;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5AB, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5AB); }
                                        uint16_t dp_ret22 = r->dp;
                                        uint8_t db_ret22 = r->db;
                                        bool m_ret22 = r->mf;
                                        uint16_t a_all24 = r->a;
                                        uint16_t y_ret24 = r->y;
                                        bool overflow_ret24 = r->v;
                                        m_flag15 = m_ret22;
                                        a19 = (uint8_t)a_all24;
                                        a_hi19 = a_all24 >> 8;
                                        y15 = y_ret24;
                                        overflow15 = overflow_ret24;
                                        data_bank15 = db_ret22;
                                        direct_page15 = dp_ret22;
                                    }
                                    m_flag16 = m_flag15;
                                    a20 = a19;
                                    a_hi20 = a_hi19;
                                    y16 = y15;
                                    overflow16 = overflow15;
                                    data_bank16 = data_bank15;
                                    direct_page16 = direct_page15;
                                } else {
                                    RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + x_e4f0)));
                                    uint16_t value141 = RAM16(0xE074 + x_e4f0);
                                    uint16_t value142 = RAM16(0xE045 + x_e4f0);
                                    uint16_t value143 = RAM16(0xE11A + x_e4f0);
                                    uint16_t value144 = RAM16(0xE022 + x_e4f0);
                                    RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1) + value144 + (((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1 > 0xFFFF)));
                                    r->a = x_e4f0 | 0xE0D0;
                                    r->x = x_e4f0 | 0xE0D0;
                                    r->y = y_e4f0;
                                    r->c = (uint16_t)(((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1) + value144 + (((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1 > 0xFFFF) > 0xFFFF;
                                    r->z = (x_e4f0 | 0xE0D0) == 0;
                                    r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                    r->v = (((uint16_t)(((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1) + value144 + (((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1 > 0xFFFF))) & (value144 ^ (uint16_t)((uint16_t)(((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1) + value144 + (((uint16_t)((value141 & 0x7F) + value142) ^ 0xFFFF) + value143 + 1 > 0xFFFF))) & 0x8000) != 0;
                                    r->mf = 0;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
                                    uint16_t dp_ret23 = r->dp;
                                    uint8_t db_ret23 = r->db;
                                    bool m_ret23 = r->mf;
                                    uint16_t a_all25 = r->a;
                                    uint16_t y_ret25 = r->y;
                                    bool overflow_ret25 = r->v;
                                    m_flag16 = m_ret23;
                                    a20 = (uint8_t)a_all25;
                                    a_hi20 = a_all25 >> 8;
                                    y16 = y_ret25;
                                    overflow16 = overflow_ret25;
                                    data_bank16 = db_ret23;
                                    direct_page16 = dp_ret23;
                                }
                                m_flag21 = m_flag16;
                                a27 = a20;
                                a_hi27 = a_hi20;
                                y21 = y16;
                                overflow21 = overflow16;
                                data_bank21 = data_bank16;
                                direct_page21 = direct_page16;
                            } else {
                                uint8_t value145 = RAM8(0xE114 + x_e4f0);
                                bool m_flag20;
                                uint8_t a26;
                                uint8_t a_hi26;
                                uint16_t y20;
                                bool overflow20;
                                uint8_t data_bank20;
                                uint16_t direct_page20;
                                if (!(value145 & 0x40)) {
                                    uint8_t value146 = RAM8(0xE028 + x_e4f0);
                                    bool m_flag18;
                                    uint8_t a22;
                                    uint8_t a_hi22;
                                    uint16_t y18;
                                    bool overflow18;
                                    uint8_t data_bank18;
                                    uint16_t direct_page18;
                                    if ((value146 & 0x20) != 0) {
                                        bool m_flag17;
                                        uint8_t a21;
                                        uint8_t a_hi21;
                                        uint16_t y17;
                                        bool overflow17;
                                        uint8_t data_bank17;
                                        uint16_t direct_page17;
                                        if ((value146 & 0x10) == 0) {
                                            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + 0x80));
                                            uint16_t value148 = RAM16(0xE11A + x_e4f0);
                                            RAM16_SET(0x0006, (uint16_t)(value148 + 0x70));
                                            r->a = x_e4f0 | 0xE0D0;
                                            r->x = x_e4f0 | 0xE0D0;
                                            r->y = y_e4f0;
                                            r->c = value148 + 0x70 > 0xFFFF;
                                            r->z = (x_e4f0 | 0xE0D0) == 0;
                                            r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                            r->v = ((value148 ^ (uint16_t)(value148 + 0x70)) & ((uint16_t)(value148 + 0x70) ^ 0x70) & 0x8000) != 0;
                                            r->mf = 0;
                                            r->xf = 0;
                                            r->db = 0x7E;
                                            r->dp = 0;
                                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5CA, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5CA); }
                                            uint16_t dp_ret24 = r->dp;
                                            uint8_t db_ret24 = r->db;
                                            bool m_ret24 = r->mf;
                                            uint16_t a_all26 = r->a;
                                            uint16_t y_ret26 = r->y;
                                            bool overflow_ret26 = r->v;
                                            m_flag17 = m_ret24;
                                            a21 = (uint8_t)a_all26;
                                            a_hi21 = a_all26 >> 8;
                                            y17 = y_ret26;
                                            overflow17 = overflow_ret26;
                                            data_bank17 = db_ret24;
                                            direct_page17 = dp_ret24;
                                        } else {
                                            uint16_t value149 = RAM16(0xE10C + x_e4f0);
                                            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + value149)));
                                            uint16_t value152 = RAM16(0xE074 + value149);
                                            uint16_t value153 = RAM16(0xE045 + value149);
                                            uint16_t value154 = RAM16(0xE11A + x_e4f0);
                                            uint16_t value155 = RAM16(0xE022 + value149);
                                            RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1) + value155 + (((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1 > 0xFFFF)));
                                            r->a = x_e4f0 | 0xE0D0;
                                            r->x = x_e4f0 | 0xE0D0;
                                            r->y = value149;
                                            r->c = (uint16_t)(((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1) + value155 + (((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1 > 0xFFFF) > 0xFFFF;
                                            r->z = (x_e4f0 | 0xE0D0) == 0;
                                            r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                            r->v = (((uint16_t)(((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1) + value155 + (((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1 > 0xFFFF))) & (value155 ^ (uint16_t)((uint16_t)(((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1) + value155 + (((uint16_t)((value152 & 0x7F) + value153) ^ 0xFFFF) + value154 + 1 > 0xFFFF))) & 0x8000) != 0;
                                            r->mf = 0;
                                            r->xf = 0;
                                            r->db = 0x7E;
                                            r->dp = 0;
                                            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5AB, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5AB); }
                                            uint16_t dp_ret25 = r->dp;
                                            uint8_t db_ret25 = r->db;
                                            bool m_ret25 = r->mf;
                                            uint16_t a_all27 = r->a;
                                            uint16_t y_ret27 = r->y;
                                            bool overflow_ret27 = r->v;
                                            m_flag17 = m_ret25;
                                            a21 = (uint8_t)a_all27;
                                            a_hi21 = a_all27 >> 8;
                                            y17 = y_ret27;
                                            overflow17 = overflow_ret27;
                                            data_bank17 = db_ret25;
                                            direct_page17 = dp_ret25;
                                        }
                                        m_flag18 = m_flag17;
                                        a22 = a21;
                                        a_hi22 = a_hi21;
                                        y18 = y17;
                                        overflow18 = overflow17;
                                        data_bank18 = data_bank17;
                                        direct_page18 = direct_page17;
                                    } else {
                                        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e4f0) + RAM16(0xE020 + x_e4f0)));
                                        uint16_t value158 = RAM16(0xE074 + x_e4f0);
                                        uint16_t value159 = RAM16(0xE045 + x_e4f0);
                                        uint16_t value160 = RAM16(0xE11A + x_e4f0);
                                        uint16_t value161 = RAM16(0xE022 + x_e4f0);
                                        RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1) + value161 + (((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1 > 0xFFFF)));
                                        r->a = x_e4f0 | 0xE0D0;
                                        r->x = x_e4f0 | 0xE0D0;
                                        r->y = y_e4f0;
                                        r->c = (uint16_t)(((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1) + value161 + (((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1 > 0xFFFF) > 0xFFFF;
                                        r->z = (x_e4f0 | 0xE0D0) == 0;
                                        r->n = (x_e4f0 | 0xE0D0) & 0x8000;
                                        r->v = (((uint16_t)(((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1) + value161 + (((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1 > 0xFFFF))) & (value161 ^ (uint16_t)((uint16_t)(((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1) + value161 + (((uint16_t)((value158 & 0x7F) + value159) ^ 0xFFFF) + value160 + 1 > 0xFFFF))) & 0x8000) != 0;
                                        r->mf = 0;
                                        r->xf = 0;
                                        r->db = 0x7E;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
                                        uint16_t dp_ret26 = r->dp;
                                        uint8_t db_ret26 = r->db;
                                        bool m_ret26 = r->mf;
                                        uint16_t a_all28 = r->a;
                                        uint16_t y_ret28 = r->y;
                                        bool overflow_ret28 = r->v;
                                        m_flag18 = m_ret26;
                                        a22 = (uint8_t)a_all28;
                                        a_hi22 = a_all28 >> 8;
                                        y18 = y_ret28;
                                        overflow18 = overflow_ret28;
                                        data_bank18 = db_ret26;
                                        direct_page18 = dp_ret26;
                                    }
                                    m_flag20 = m_flag18;
                                    a26 = a22;
                                    a_hi26 = a_hi22;
                                    y20 = y18;
                                    overflow20 = overflow18;
                                    data_bank20 = data_bank18;
                                    direct_page20 = direct_page18;
                                } else {
                                    bool m_flag19;
                                    uint8_t a25;
                                    uint8_t a_hi25;
                                    uint16_t y19;
                                    bool overflow19;
                                    uint8_t data_bank19;
                                    uint16_t direct_page19;
                                    if (value128 != 5) {
                                        uint8_t value162 = RAM8(0xE116 + x_e4f0);
                                        RAM8(0x0000 + sp0) = value162;
                                        uint8_t a23;
                                        if ((value162 & 0x0F) < 6) {
                                            a23 = value162 & 0x0F;
                                        } else {
                                            a23 = 5;
                                        }
                                        RAM8(0x0002) = a23;
                                        uint8_t a24;
                                        uint8_t a_hi23;
                                        if ((value162 & 0x0F) < 6) {
                                            a24 = 0xD0;
                                            a_hi23 = 0;
                                        } else {
                                            a24 = (uint8_t)((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value162) & 0x0F) - 5 - ((value162 & 0x0F) >= 6 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value162) & 0x0F) - 5 - ((value162 & 0x0F) >= 6 ^ 1)) << 1) >> 0x0F));
                                            a_hi23 = (uint16_t)((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value162) & 0x0F) - 5 - ((value162 & 0x0F) >= 6 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e4f0 << 8) | value162) & 0x0F) - 5 - ((value162 & 0x0F) >= 6 ^ 1)) << 1) >> 0x0F)) >> 8;
                                        }
                                        uint16_t value163 = RAM16(0x0014);
                                        uint16_t value164 = RAM16(0xE028 + x_e4f0);
                                        uint8_t a_hi24;
                                        uint16_t x3;
                                        if ((value164 & 0x30) != 0x30) {
                                            a_hi24 = 0;
                                            x3 = x_e4f0;
                                        } else {
                                            uint16_t value165 = RAM16(0xE10C + x_e4f0);
                                            a_hi24 = value165 >> 8;
                                            x3 = value165;
                                        }
                                        RAM16_SET(0x0004, RAM16(0xE020 + x3));
                                        uint16_t value167 = RAM16(0xE074 + x3);
                                        uint16_t value168 = RAM16(0xE045 + x3);
                                        uint16_t value169 = RAM16(0xE022 + x3);
                                        RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30)) ^ 0xFFFF) + value169 + ((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30) > 0xFFFF)));
                                        r->a = (uint16_t)(((uint16_t)((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30)) ^ 0xFFFF) + value169 + ((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30) > 0xFFFF));
                                        r->x = value163;
                                        r->y = (a_hi23 << 8) | a24 | value163 | 0xE000;
                                        r->c = ((uint16_t)((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30)) ^ 0xFFFF) + value169 + ((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30) > 0xFFFF) > 0xFFFF;
                                        r->z = value163 == 0;
                                        r->n = value163 & 0x8000;
                                        r->v = (((uint16_t)((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30)) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30)) ^ 0xFFFF) + value169 + ((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30) > 0xFFFF))) & (value169 ^ (uint16_t)(((uint16_t)((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30)) ^ 0xFFFF) + value169 + ((value167 & 0x7F) + value168 + ((value164 & 0x30) >= 0x30) > 0xFFFF))) & 0x8000) != 0;
                                        r->mf = 0;
                                        r->xf = 0;
                                        r->db = 0x7E;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSL(c, 0xE759, 0x02AB54); GUARD_JSL(c, sp_call, 0xE759); } /* duplicate_and_mirror_actor_sprite_list */
                                        r->mf = 0;
                                        r->xf = 0;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE75C, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE75C); }
                                        uint16_t dp_ret27 = r->dp;
                                        uint8_t db_ret27 = r->db;
                                        bool m_ret27 = r->mf;
                                        uint16_t a_all30 = r->a;
                                        uint16_t y_ret30 = r->y;
                                        bool overflow_ret30 = r->v;
                                        m_flag19 = m_ret27;
                                        a25 = (uint8_t)a_all30;
                                        a_hi25 = a_all30 >> 8;
                                        y19 = y_ret30;
                                        overflow19 = overflow_ret30;
                                        data_bank19 = db_ret27;
                                        direct_page19 = dp_ret27;
                                    } else {
                                        uint16_t value170 = RAM16(0x0014);
                                        RAM8(0x0002) = RAM8(0xE116 + value170) & 0x0F;
                                        RAM16_SET(0x0004, RAM16(0xE020 + value170));
                                        uint16_t value173 = RAM16(0xE074 + value170);
                                        uint16_t value174 = RAM16(0xE045 + value170);
                                        uint16_t value175 = RAM16(0xE022 + value170);
                                        RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value175 + ((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF)));
                                        r->a = value170 | 0xE0D0;
                                        r->x = value170 | 0xE0D0;
                                        r->y = y_e4f0;
                                        r->c = ((uint16_t)((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value175 + ((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF) > 0xFFFF;
                                        r->z = (value170 | 0xE0D0) == 0;
                                        r->n = (value170 | 0xE0D0) & 0x8000;
                                        r->v = (((uint16_t)((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value175 + ((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & (value175 ^ (uint16_t)(((uint16_t)((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value175 + ((value173 & 0x7F) + 0x60 + value174 + ((value173 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & 0x8000) != 0;
                                        r->mf = 0;
                                        r->xf = 0;
                                        r->db = 0x7E;
                                        r->dp = 0;
                                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE700, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE700); }
                                        uint16_t dp_ret28 = r->dp;
                                        uint8_t db_ret28 = r->db;
                                        bool m_ret28 = r->mf;
                                        uint16_t a_all31 = r->a;
                                        uint16_t y_ret31 = r->y;
                                        bool overflow_ret31 = r->v;
                                        m_flag19 = m_ret28;
                                        a25 = (uint8_t)a_all31;
                                        a_hi25 = a_all31 >> 8;
                                        y19 = y_ret31;
                                        overflow19 = overflow_ret31;
                                        data_bank19 = db_ret28;
                                        direct_page19 = dp_ret28;
                                    }
                                    m_flag20 = m_flag19;
                                    a26 = a25;
                                    a_hi26 = a_hi25;
                                    y20 = y19;
                                    overflow20 = overflow19;
                                    data_bank20 = data_bank19;
                                    direct_page20 = direct_page19;
                                }
                                m_flag21 = m_flag20;
                                a27 = a26;
                                a_hi27 = a_hi26;
                                y21 = y20;
                                overflow21 = overflow20;
                                data_bank21 = data_bank20;
                                direct_page21 = direct_page20;
                            }
                            m_flag22 = m_flag21;
                            a28 = a27;
                            a_hi28 = a_hi27;
                            y22 = y21;
                            overflow22 = overflow21;
                            data_bank22 = data_bank21;
                            direct_page22 = direct_page21;
                        }
                        m_flag23 = m_flag22;
                        a29 = a28;
                        a_hi29 = a_hi28;
                        y23 = y22;
                        overflow23 = overflow22;
                        data_bank23 = data_bank22;
                        direct_page23 = direct_page22;
                    }
                    m_flag24 = m_flag23;
                    a30 = a29;
                    a_hi30 = a_hi29;
                    y24 = y23;
                    overflow24 = overflow23;
                    data_bank24 = data_bank23;
                    direct_page24 = direct_page23;
                }
                m_flag25 = m_flag24;
                a31 = a30;
                a_hi31 = a_hi30;
                y25 = y24;
                overflow25 = overflow24;
                data_bank25 = data_bank24;
                direct_page25 = direct_page24;
            }
            m_flag26 = m_flag25;
            a32 = a31;
            a_hi32 = a_hi31;
            y26 = y25;
            overflow26 = overflow25;
            data_bank26 = data_bank25;
            direct_page26 = direct_page25;
        }
        uint16_t value176 = BUS16_RDP(c, (uint16_t)(direct_page26 + 0x14));
        if (value176 < 0x0600) {
            r->a = (a_hi32 << 8) | a32;
            r->x = value176;
            r->y = y26;
            r->c = value176 >= 0x0600;
            r->z = value176 == 0x0600;
            r->n = (uint16_t)(value176 - 0x0600) & 0x8000;
            r->v = overflow26;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank26;
            r->dp = direct_page26;
            prepare_and_emit_actor_body_sprites_v2(c); return;
        }
        uint8_t value177 = BUS8_RDP(c, (uint16_t)(direct_page26 + 0x5C));
        if (value177 & 0x80) {
            r->a = (a_hi32 << 8) | a32;
            r->x = value176;
            r->y = y26;
            r->c = value176 >= 0x0600;
            r->z = (a32 & value177) == 0;
            r->n = value177 & 0x80;
            r->v = value177 & 0x40;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank26;
            r->dp = direct_page26;
            RETURN_RTS(c);
        }
        r->a = (a_hi32 << 8) | a32;
        r->x = value176;
        r->y = y26;
        r->c = value176 >= 0x0600;
        r->z = (a32 & value177) == 0;
        r->n = value177 & 0x80;
        r->v = value177 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank26;
        r->dp = direct_page26;
        prepare_and_emit_actor_body_sprites_v2(c); return;
    }
    uint16_t value178 = RAM16(0x0014);
    r->a = value178;
    r->x = x_e4f0;
    r->y = value178;
    r->c = a_e4f0 >= 0xE0;
    r->z = value178 == 0;
    r->n = value178 & 0x8000;
    r->v = overflow_e4f0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE895, 0x019106); GUARD_JSL(c, sp_call, 0xE895); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret29 = r->mf;
    uint16_t a_all32 = r->a;
    uint16_t x_ret32 = r->x;
    bool carry_ret32 = r->c;
    bool overflow_ret32 = r->v;
    bool m_flag27;
    uint8_t a_hi33;
    uint16_t x4;
    bool carry1;
    bool overflow27;
    uint8_t data_bank27;
    uint16_t direct_page27;
    if (!carry_ret32) {
        m_flag27 = m_ret29;
        a_hi33 = a_all32 >> 8;
        x4 = x_ret32;
        carry1 = carry_ret32;
        overflow27 = overflow_ret32;
        data_bank27 = 0x7E;
        direct_page27 = 0;
    } else {
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE89A, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE89A); }
        uint16_t dp_ret29 = r->dp;
        uint8_t db_ret29 = r->db;
        bool m_ret30 = r->mf;
        uint16_t a_all33 = r->a;
        uint16_t x_ret33 = r->x;
        bool carry_ret33 = r->c;
        bool overflow_ret33 = r->v;
        m_flag27 = m_ret30;
        a_hi33 = a_all33 >> 8;
        x4 = x_ret33;
        carry1 = carry_ret33;
        overflow27 = overflow_ret33;
        data_bank27 = db_ret29;
        direct_page27 = dp_ret29;
    }
    uint16_t value179 = BUS16_RDP(c, (uint16_t)(direct_page27 + 0x14));
    r->a = value179 | 0x10;
    r->x = x4;
    r->y = value179 | 0x10;
    r->c = carry1;
    r->z = (value179 | 0x10) == 0;
    r->n = (value179 | 0x10) & 0x8000;
    r->v = overflow27;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank27;
    r->dp = direct_page27;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8A6, 0x019106); GUARD_JSL(c, sp_call, 0xE8A6); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret31 = r->mf;
    uint16_t a_all34 = r->a;
    uint16_t x_ret34 = r->x;
    bool carry_ret34 = r->c;
    bool overflow_ret34 = r->v;
    bool m_flag28;
    uint8_t a_hi34;
    uint16_t x5;
    bool carry2;
    bool overflow28;
    uint8_t data_bank28;
    uint16_t direct_page28;
    if (!carry_ret34) {
        m_flag28 = m_ret31;
        a_hi34 = a_all34 >> 8;
        x5 = x_ret34;
        carry2 = carry_ret34;
        overflow28 = overflow_ret34;
        data_bank28 = data_bank27;
        direct_page28 = direct_page27;
    } else {
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8AB, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8AB); }
        uint16_t dp_ret30 = r->dp;
        uint8_t db_ret30 = r->db;
        bool m_ret32 = r->mf;
        uint16_t a_all35 = r->a;
        uint16_t x_ret35 = r->x;
        bool carry_ret35 = r->c;
        bool overflow_ret35 = r->v;
        m_flag28 = m_ret32;
        a_hi34 = a_all35 >> 8;
        x5 = x_ret35;
        carry2 = carry_ret35;
        overflow28 = overflow_ret35;
        data_bank28 = db_ret30;
        direct_page28 = dp_ret30;
    }
    uint16_t value180 = BUS16_RDP(c, (uint16_t)(direct_page28 + 0x14));
    r->a = value180 | 0x20;
    r->x = x5;
    r->y = value180 | 0x20;
    r->c = carry2;
    r->z = (value180 | 0x20) == 0;
    r->n = (value180 | 0x20) & 0x8000;
    r->v = overflow28;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank28;
    r->dp = direct_page28;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8B7, 0x019106); GUARD_JSL(c, sp_call, 0xE8B7); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret33 = r->mf;
    uint16_t a_all36 = r->a;
    uint16_t x_ret36 = r->x;
    bool carry_ret36 = r->c;
    bool overflow_ret36 = r->v;
    bool m_flag29;
    uint8_t a33;
    uint8_t a_hi35;
    uint16_t x6;
    uint16_t y27;
    bool carry3;
    bool overflow29;
    uint8_t data_bank29;
    uint16_t direct_page29;
    if (!carry_ret36) {
        m_flag29 = m_ret33;
        a33 = (uint8_t)a_all36;
        a_hi35 = a_all36 >> 8;
        x6 = x_ret36;
        y27 = value180 | 0x20;
        carry3 = carry_ret36;
        overflow29 = overflow_ret36;
        data_bank29 = data_bank28;
        direct_page29 = direct_page28;
    } else {
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8BC, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8BC); }
        uint16_t dp_ret31 = r->dp;
        uint8_t db_ret31 = r->db;
        bool m_ret34 = r->mf;
        uint16_t a_all37 = r->a;
        uint16_t x_ret37 = r->x;
        uint16_t y_ret34 = r->y;
        bool carry_ret37 = r->c;
        bool overflow_ret37 = r->v;
        m_flag29 = m_ret34;
        a33 = (uint8_t)a_all37;
        a_hi35 = a_all37 >> 8;
        x6 = x_ret37;
        y27 = y_ret34;
        carry3 = carry_ret37;
        overflow29 = overflow_ret37;
        data_bank29 = db_ret31;
        direct_page29 = dp_ret31;
    }
    r->a = (a_hi35 << 8) | a33;
    r->x = x6;
    r->y = y27;
    r->c = carry3;
    r->v = overflow29;
    r->mf = m_flag29;
    r->xf = 0;
    r->db = data_bank29;
    r->dp = direct_page29;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8C0, 0x019017); GUARD_JSL(c, sp_call, 0xE8C0); } /* prepare_merged_actor_effect_sprites */
    bool m_ret35 = r->mf;
    uint16_t a_all38 = r->a;
    uint16_t y_ret35 = r->y;
    bool carry_ret38 = r->c;
    bool overflow_ret38 = r->v;
    bool m_flag30;
    uint8_t a34;
    uint8_t a_hi36;
    uint16_t y28;
    bool overflow30;
    uint8_t data_bank30;
    uint16_t direct_page30;
    if (!carry_ret38) {
        m_flag30 = m_ret35;
        a34 = (uint8_t)a_all38;
        a_hi36 = a_all38 >> 8;
        y28 = y_ret35;
        overflow30 = overflow_ret38;
        data_bank30 = data_bank29;
        direct_page30 = direct_page29;
    } else {
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8C5, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8C5); }
        uint16_t dp_ret32 = r->dp;
        uint8_t db_ret32 = r->db;
        bool m_ret36 = r->mf;
        uint16_t a_all39 = r->a;
        uint16_t y_ret36 = r->y;
        bool overflow_ret39 = r->v;
        m_flag30 = m_ret36;
        a34 = (uint8_t)a_all39;
        a_hi36 = a_all39 >> 8;
        y28 = y_ret36;
        overflow30 = overflow_ret39;
        data_bank30 = db_ret32;
        direct_page30 = dp_ret32;
    }
    uint16_t value181 = BUS16_RDP(c, (uint16_t)(direct_page30 + 0x14));
    if (value181 < 0x0600) {
        r->a = (a_hi36 << 8) | a34;
        r->x = value181;
        r->y = y28;
        r->c = value181 >= 0x0600;
        r->z = value181 == 0x0600;
        r->n = (uint16_t)(value181 - 0x0600) & 0x8000;
        r->v = overflow30;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank30;
        r->dp = direct_page30;
        prepare_and_emit_actor_body_sprites_v2(c); return;
    }
    uint8_t value182 = BUS8_RDP(c, (uint16_t)(direct_page30 + 0x5C));
    if (value182 & 0x80) {
        r->a = (a_hi36 << 8) | a34;
        r->x = value181;
        r->y = y28;
        r->c = value181 >= 0x0600;
        r->z = (a34 & value182) == 0;
        r->n = value182 & 0x80;
        r->v = value182 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank30;
        r->dp = direct_page30;
        RETURN_RTS(c);
    }
    r->a = (a_hi36 << 8) | a34;
    r->x = value181;
    r->y = y28;
    r->c = value181 >= 0x0600;
    r->z = (a34 & value182) == 0;
    r->n = value182 & 0x80;
    r->v = value182 & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank30;
    r->dp = direct_page30;
    prepare_and_emit_actor_body_sprites_v2(c); return;
}

/* C0E807 clip_and_emit_ground_shadow_piece   [class A, 131 bytes, 64 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void clip_and_emit_ground_shadow_piece(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_e829 = 0;
    uint8_t a_hi_e829 = 0;
    uint16_t x_e829 = 0;
    uint16_t y_e829 = 0;
    uint8_t a_e81c = 0;
    uint8_t a_hi_e81c = 0;
    uint16_t x_e81c = 0;
    uint16_t y_e81c = 0;
    bool carry_e81c = 0;
    bool zero_e81c = 0;
    bool negative_e81c = 0;
    bool overflow_e81c = 0;
    uint16_t value = RAM16(0x0098);
    RAM16_SET(0x0002, y);
    RAM16_SET(0x0000, a | value | RAM16(0x000E));
    uint16_t value3 = RAM16(0x0004);
    uint16_t value4 = RAM16(0xE022 + x);
    if ((uint16_t)(value3 + value4) & 0x8000) {
        if ((uint16_t)(value3 + value4) >= 0xFFF0) {
            a_e829 = (uint8_t)(value3 + value4);
            a_hi_e829 = (uint16_t)(value3 + value4) >> 8;
            x_e829 = x;
            y_e829 = y;
            goto shared_E829;
        }
        uint16_t value5 = RAM16(0x00C2);
        if ((uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) >= 0xE0) {
            a_e81c = (uint8_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0));
            a_hi_e81c = (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) >> 8;
            x_e81c = x;
            y_e81c = y;
            carry_e81c = (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) >= 0xE0;
            zero_e81c = (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) == 0xE0;
            negative_e81c = (uint16_t)((uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) - 0xE0) & 0x8000;
            overflow_e81c = (((uint16_t)(value3 + value4) ^ (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0))) & (value5 ^ (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0))) & 0x8000) != 0;
            goto shared_E81C;
        }
        a_e829 = (uint8_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0));
        a_hi_e829 = (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) >> 8;
        x_e829 = x;
        y_e829 = y;
        goto shared_E829;
    }
    if ((uint16_t)(value3 + value4) < 0xE0) {
        a_e829 = (uint8_t)(value3 + value4);
        a_hi_e829 = (uint16_t)(value3 + value4) >> 8;
        x_e829 = x;
        y_e829 = y;
        goto shared_E829;
    }
    a_e81c = (uint8_t)(value3 + value4);
    a_hi_e81c = (uint16_t)(value3 + value4) >> 8;
    x_e81c = x;
    y_e81c = y;
    carry_e81c = (uint16_t)(value3 + value4) >= 0xE0;
    zero_e81c = (uint16_t)(value3 + value4) == 0xE0;
    negative_e81c = (uint16_t)((uint16_t)(value3 + value4) - 0xE0) & 0x8000;
    overflow_e81c = ((value3 ^ (uint16_t)(value3 + value4)) & (value4 ^ (uint16_t)(value3 + value4)) & 0x8000) != 0;
    shared_E81C:;
    r->a = (a_hi_e81c << 8) | a_e81c;
    r->x = x_e81c;
    r->y = y_e81c;
    r->c = carry_e81c;
    r->z = zero_e81c;
    r->n = negative_e81c;
    r->v = overflow_e81c;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_E829:;
    RAM8(0x0008) = a_e829;
    uint16_t value6 = RAM16(0x0002);
    uint16_t value7 = RAM16(0xE020 + x_e829);
    if ((uint16_t)(value6 + value7) & 0x8000) {
        if ((uint16_t)(value6 + value7) >= 0xFFE0) {
            uint16_t value8 = RAM16(0x007C);
            if (value8 >= 0x0200) {
                r->a = (uint16_t)(value6 + value7);
                r->x = x_e829;
                r->y = value8;
                r->c = value8 >= 0x0200;
                r->z = value8 == 0x0200;
                r->n = (uint16_t)(value8 - 0x0200) & 0x8000;
                r->v = ((value6 ^ (uint16_t)(value6 + value7)) & (value7 ^ (uint16_t)(value6 + value7)) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            RAM8(0x0800 + value8) = (uint8_t)(value6 + value7);
            uint8_t value9 = RAM8(0x0008);
            RAM8(0x0801 + value8) = value9;
            uint8_t a_hi1;
            uint16_t y1;
            if ((uint16_t)(value6 + value7) >> 8 == 0) {
                a_hi1 = value9;
                y1 = value8;
            } else {
                uint8_t value10 = RAM8(0x005A);
                RAM8(0x0A00 + value10) ^= RAM8(0x0059);
                uint16_t value13 = RAM16(0x007C);
                a_hi1 = 0;
                y1 = value13;
            }
            RAM16_SET(0x0802 + y1, RAM16(0x0000));
            RAM16_SET(0x007C, (uint16_t)(y1 + 4));
            uint8_t value15 = RAM8(0x0059);
            uint8_t a1;
            bool zero1;
            bool negative1;
            if (!((uint8_t)(value15 << 1) & 0x80)) {
                a1 = (uint8_t)(value15 << 2);
                zero1 = (uint8_t)(value15 << 2) == 0;
                negative1 = (uint8_t)(value15 << 2) & 0x80;
            } else {
                RAM8(0x005A)++;
                a1 = 1;
                zero1 = 0;
                negative1 = 0;
            }
            RAM8(0x0059) = a1;
            r->a = ((uint16_t)(y1 + 4) >> 8 << 8) | a1;
            r->x = x_e829;
            r->y = y1;
            r->c = (uint8_t)(value15 << 1) & 0x80;
            r->z = zero1;
            r->n = negative1;
            r->v = ((y1 ^ (uint16_t)(y1 + 4)) & ((uint16_t)(y1 + 4) ^ 4) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint16_t value16 = RAM16(0x00C0);
        if ((uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0)) >= 0x0100) {
            r->a = (uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0));
            r->x = x_e829;
            r->y = y_e829;
            r->c = (uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0)) >= 0x0100;
            r->z = (uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0)) == 0x0100;
            r->n = (uint16_t)((uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0)) - 0x0100) & 0x8000;
            r->v = (((uint16_t)(value6 + value7) ^ (uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0))) & (value16 ^ (uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0))) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint16_t value17 = RAM16(0x007C);
        if (value17 >= 0x0200) {
            r->a = (uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0));
            r->x = x_e829;
            r->y = value17;
            r->c = value17 >= 0x0200;
            r->z = value17 == 0x0200;
            r->n = (uint16_t)(value17 - 0x0200) & 0x8000;
            r->v = (((uint16_t)(value6 + value7) ^ (uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0))) & (value16 ^ (uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0))) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        RAM8(0x0800 + value17) = (uint8_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0));
        uint8_t value18 = RAM8(0x0008);
        RAM8(0x0801 + value17) = value18;
        uint8_t a_hi2;
        uint16_t y2;
        if ((uint16_t)((uint16_t)(value6 + value7) + value16 + ((uint16_t)(value6 + value7) >= 0xFFE0)) >> 8 == 0) {
            a_hi2 = value18;
            y2 = value17;
        } else {
            uint8_t value19 = RAM8(0x005A);
            RAM8(0x0A00 + value19) ^= RAM8(0x0059);
            uint16_t value22 = RAM16(0x007C);
            a_hi2 = 0;
            y2 = value22;
        }
        RAM16_SET(0x0802 + y2, RAM16(0x0000));
        RAM16_SET(0x007C, (uint16_t)(y2 + 4));
        uint8_t value24 = RAM8(0x0059);
        uint8_t a2;
        bool zero2;
        bool negative2;
        if (!((uint8_t)(value24 << 1) & 0x80)) {
            a2 = (uint8_t)(value24 << 2);
            zero2 = (uint8_t)(value24 << 2) == 0;
            negative2 = (uint8_t)(value24 << 2) & 0x80;
        } else {
            RAM8(0x005A)++;
            a2 = 1;
            zero2 = 0;
            negative2 = 0;
        }
        RAM8(0x0059) = a2;
        r->a = ((uint16_t)(y2 + 4) >> 8 << 8) | a2;
        r->x = x_e829;
        r->y = y2;
        r->c = (uint8_t)(value24 << 1) & 0x80;
        r->z = zero2;
        r->n = negative2;
        r->v = ((y2 ^ (uint16_t)(y2 + 4)) & ((uint16_t)(y2 + 4) ^ 4) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value6 + value7) < 0x0100) {
        uint16_t value25 = RAM16(0x007C);
        if (value25 >= 0x0200) {
            r->a = (uint16_t)(value6 + value7);
            r->x = x_e829;
            r->y = value25;
            r->c = value25 >= 0x0200;
            r->z = value25 == 0x0200;
            r->n = (uint16_t)(value25 - 0x0200) & 0x8000;
            r->v = ((value6 ^ (uint16_t)(value6 + value7)) & (value7 ^ (uint16_t)(value6 + value7)) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        RAM8(0x0800 + value25) = (uint8_t)(value6 + value7);
        uint8_t value26 = RAM8(0x0008);
        RAM8(0x0801 + value25) = value26;
        uint8_t a_hi3;
        uint16_t y3;
        if ((uint16_t)(value6 + value7) >> 8 == 0) {
            a_hi3 = value26;
            y3 = value25;
        } else {
            uint8_t value27 = RAM8(0x005A);
            RAM8(0x0A00 + value27) ^= RAM8(0x0059);
            uint16_t value30 = RAM16(0x007C);
            a_hi3 = 0;
            y3 = value30;
        }
        RAM16_SET(0x0802 + y3, RAM16(0x0000));
        RAM16_SET(0x007C, (uint16_t)(y3 + 4));
        uint8_t value32 = RAM8(0x0059);
        uint8_t a3;
        bool zero3;
        bool negative3;
        if (!((uint8_t)(value32 << 1) & 0x80)) {
            a3 = (uint8_t)(value32 << 2);
            zero3 = (uint8_t)(value32 << 2) == 0;
            negative3 = (uint8_t)(value32 << 2) & 0x80;
        } else {
            RAM8(0x005A)++;
            a3 = 1;
            zero3 = 0;
            negative3 = 0;
        }
        RAM8(0x0059) = a3;
        r->a = ((uint16_t)(y3 + 4) >> 8 << 8) | a3;
        r->x = x_e829;
        r->y = y3;
        r->c = (uint8_t)(value32 << 1) & 0x80;
        r->z = zero3;
        r->n = negative3;
        r->v = ((y3 ^ (uint16_t)(y3 + 4)) & ((uint16_t)(y3 + 4) ^ 4) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->a = (uint16_t)(value6 + value7);
    r->x = x_e829;
    r->y = y_e829;
    r->c = (uint16_t)(value6 + value7) >= 0x0100;
    r->z = (uint16_t)(value6 + value7) == 0x0100;
    r->n = (uint16_t)((uint16_t)(value6 + value7) - 0x0100) & 0x8000;
    r->v = ((value6 ^ (uint16_t)(value6 + value7)) & (value7 ^ (uint16_t)(value6 + value7)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}

/* C0E807 clip_and_emit_ground_shadow_piece_v2   [class A, 131 bytes, 64 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void clip_and_emit_ground_shadow_piece_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t a_e829 = 0;
    uint8_t a_hi_e829 = 0;
    uint16_t x_e829 = 0;
    uint16_t y_e829 = 0;
    uint8_t a_e81c = 0;
    uint8_t a_hi_e81c = 0;
    uint16_t x_e81c = 0;
    uint16_t y_e81c = 0;
    bool carry_e81c = 0;
    bool zero_e81c = 0;
    bool negative_e81c = 0;
    bool overflow_e81c = 0;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x98));
    BUS16_SET(c, (uint16_t)(dp + 2), y);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x0E));
    BUS16_SET(c, dp, a | value | value2);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 4));
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0xE022 + x);
    if ((uint16_t)(value3 + value4) & 0x8000) {
        if ((uint16_t)(value3 + value4) >= 0xFFF0) {
            a_e829 = (uint8_t)(value3 + value4);
            a_hi_e829 = (uint16_t)(value3 + value4) >> 8;
            x_e829 = x;
            y_e829 = y;
            goto shared_E829;
        }
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0xC2));
        if ((uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) >= 0xE0) {
            a_e81c = (uint8_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0));
            a_hi_e81c = (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) >> 8;
            x_e81c = x;
            y_e81c = y;
            carry_e81c = (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) >= 0xE0;
            zero_e81c = (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) == 0xE0;
            negative_e81c = (uint16_t)((uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) - 0xE0) & 0x8000;
            overflow_e81c = (((uint16_t)(value3 + value4) ^ (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0))) & (value5 ^ (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0))) & 0x8000) != 0;
            goto shared_E81C;
        }
        a_e829 = (uint8_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0));
        a_hi_e829 = (uint16_t)((uint16_t)(value3 + value4) + value5 + ((uint16_t)(value3 + value4) >= 0xFFF0)) >> 8;
        x_e829 = x;
        y_e829 = y;
        goto shared_E829;
    }
    if ((uint16_t)(value3 + value4) < 0xE0) {
        a_e829 = (uint8_t)(value3 + value4);
        a_hi_e829 = (uint16_t)(value3 + value4) >> 8;
        x_e829 = x;
        y_e829 = y;
        goto shared_E829;
    }
    a_e81c = (uint8_t)(value3 + value4);
    a_hi_e81c = (uint16_t)(value3 + value4) >> 8;
    x_e81c = x;
    y_e81c = y;
    carry_e81c = (uint16_t)(value3 + value4) >= 0xE0;
    zero_e81c = (uint16_t)(value3 + value4) == 0xE0;
    negative_e81c = (uint16_t)((uint16_t)(value3 + value4) - 0xE0) & 0x8000;
    overflow_e81c = ((value3 ^ (uint16_t)(value3 + value4)) & (value4 ^ (uint16_t)(value3 + value4)) & 0x8000) != 0;
    shared_E81C:;
    r->a = (a_hi_e81c << 8) | a_e81c;
    r->x = x_e81c;
    r->y = y_e81c;
    r->c = carry_e81c;
    r->z = zero_e81c;
    r->n = negative_e81c;
    r->v = overflow_e81c;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
    shared_E829:;
    BUS8_SET(c, (uint16_t)(dp + 8), a_e829);
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 2));
    uint16_t value7 = BUS16_RDP(c, (db << 0x10) + 0xE020 + x_e829);
    if ((uint16_t)(value6 + value7) & 0x8000) {
        if ((uint16_t)(value6 + value7) >= 0xFFE0) {
            uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
            if (value8 >= 0x0200) {
                r->a = (uint16_t)(value6 + value7);
                r->x = x_e829;
                r->y = value8;
                r->c = value8 >= 0x0200;
                r->z = value8 == 0x0200;
                r->n = (uint16_t)(value8 - 0x0200) & 0x8000;
                r->v = ((value6 ^ (uint16_t)(value6 + value7)) & (value7 ^ (uint16_t)(value6 + value7)) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 0;
                r->db = db;
                r->dp = dp;
                RETURN_RTS(c);
            }
            BUS8_SET(c, (db << 0x10) + 0x0800 + value8, (uint8_t)(value6 + value7));
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 8));
            BUS8_SET(c, (db << 0x10) + 0x0801 + value8, value9);
            uint8_t a_hi1;
            uint16_t y1;
            if ((uint16_t)(value6 + value7) >> 8 == 0) {
                a_hi1 = value9;
                y1 = value8;
            } else {
                uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                uint8_t value11 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value10);
                uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                BUS8_SET(c, (db << 0x10) + 0x0A00 + value10, value11 ^ value12);
                uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                a_hi1 = 0;
                y1 = value13;
            }
            uint16_t value14 = BUS16_RDP(c, dp);
            BUS16_SET(c, (db << 0x10) + 0x0802 + y1, value14);
            BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y1 + 4));
            uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
            uint8_t a1;
            bool zero1;
            bool negative1;
            if (!((uint8_t)(value15 << 1) & 0x80)) {
                a1 = (uint8_t)(value15 << 2);
                zero1 = (uint8_t)(value15 << 2) == 0;
                negative1 = (uint8_t)(value15 << 2) & 0x80;
            } else {
                uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value16 + 1));
                a1 = 1;
                zero1 = 0;
                negative1 = 0;
            }
            BUS8_SET(c, (uint16_t)(dp + 0x59), a1);
            r->a = ((uint16_t)(y1 + 4) >> 8 << 8) | a1;
            r->x = x_e829;
            r->y = y1;
            r->c = (uint8_t)(value15 << 1) & 0x80;
            r->z = zero1;
            r->n = negative1;
            r->v = ((y1 ^ (uint16_t)(y1 + 4)) & ((uint16_t)(y1 + 4) ^ 4) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = db;
            r->dp = dp;
            RETURN_RTS(c);
        }
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp + 0xC0));
        if ((uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0)) >= 0x0100) {
            r->a = (uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0));
            r->x = x_e829;
            r->y = y_e829;
            r->c = (uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0)) >= 0x0100;
            r->z = (uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0)) == 0x0100;
            r->n = (uint16_t)((uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0)) - 0x0100) & 0x8000;
            r->v = (((uint16_t)(value6 + value7) ^ (uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0))) & (value17 ^ (uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0))) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = db;
            r->dp = dp;
            RETURN_RTS(c);
        }
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
        if (value18 >= 0x0200) {
            r->a = (uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0));
            r->x = x_e829;
            r->y = value18;
            r->c = value18 >= 0x0200;
            r->z = value18 == 0x0200;
            r->n = (uint16_t)(value18 - 0x0200) & 0x8000;
            r->v = (((uint16_t)(value6 + value7) ^ (uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0))) & (value17 ^ (uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0))) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = db;
            r->dp = dp;
            RETURN_RTS(c);
        }
        BUS8_SET(c, (db << 0x10) + 0x0800 + value18, (uint8_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0)));
        uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp + 8));
        BUS8_SET(c, (db << 0x10) + 0x0801 + value18, value19);
        uint8_t a_hi2;
        uint16_t y2;
        if ((uint16_t)((uint16_t)(value6 + value7) + value17 + ((uint16_t)(value6 + value7) >= 0xFFE0)) >> 8 == 0) {
            a_hi2 = value19;
            y2 = value18;
        } else {
            uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
            uint8_t value21 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value20);
            uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
            BUS8_SET(c, (db << 0x10) + 0x0A00 + value20, value21 ^ value22);
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
            a_hi2 = 0;
            y2 = value23;
        }
        uint16_t value24 = BUS16_RDP(c, dp);
        BUS16_SET(c, (db << 0x10) + 0x0802 + y2, value24);
        BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y2 + 4));
        uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
        uint8_t a2;
        bool zero2;
        bool negative2;
        if (!((uint8_t)(value25 << 1) & 0x80)) {
            a2 = (uint8_t)(value25 << 2);
            zero2 = (uint8_t)(value25 << 2) == 0;
            negative2 = (uint8_t)(value25 << 2) & 0x80;
        } else {
            uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
            BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value26 + 1));
            a2 = 1;
            zero2 = 0;
            negative2 = 0;
        }
        BUS8_SET(c, (uint16_t)(dp + 0x59), a2);
        r->a = ((uint16_t)(y2 + 4) >> 8 << 8) | a2;
        r->x = x_e829;
        r->y = y2;
        r->c = (uint8_t)(value25 << 1) & 0x80;
        r->z = zero2;
        r->n = negative2;
        r->v = ((y2 ^ (uint16_t)(y2 + 4)) & ((uint16_t)(y2 + 4) ^ 4) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = dp;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value6 + value7) < 0x0100) {
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
        if (value27 >= 0x0200) {
            r->a = (uint16_t)(value6 + value7);
            r->x = x_e829;
            r->y = value27;
            r->c = value27 >= 0x0200;
            r->z = value27 == 0x0200;
            r->n = (uint16_t)(value27 - 0x0200) & 0x8000;
            r->v = ((value6 ^ (uint16_t)(value6 + value7)) & (value7 ^ (uint16_t)(value6 + value7)) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = db;
            r->dp = dp;
            RETURN_RTS(c);
        }
        BUS8_SET(c, (db << 0x10) + 0x0800 + value27, (uint8_t)(value6 + value7));
        uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp + 8));
        BUS8_SET(c, (db << 0x10) + 0x0801 + value27, value28);
        uint8_t a_hi3;
        uint16_t y3;
        if ((uint16_t)(value6 + value7) >> 8 == 0) {
            a_hi3 = value28;
            y3 = value27;
        } else {
            uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
            uint8_t value30 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value29);
            uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
            BUS8_SET(c, (db << 0x10) + 0x0A00 + value29, value30 ^ value31);
            uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
            a_hi3 = 0;
            y3 = value32;
        }
        uint16_t value33 = BUS16_RDP(c, dp);
        BUS16_SET(c, (db << 0x10) + 0x0802 + y3, value33);
        BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y3 + 4));
        uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
        uint8_t a3;
        bool zero3;
        bool negative3;
        if (!((uint8_t)(value34 << 1) & 0x80)) {
            a3 = (uint8_t)(value34 << 2);
            zero3 = (uint8_t)(value34 << 2) == 0;
            negative3 = (uint8_t)(value34 << 2) & 0x80;
        } else {
            uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
            BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value35 + 1));
            a3 = 1;
            zero3 = 0;
            negative3 = 0;
        }
        BUS8_SET(c, (uint16_t)(dp + 0x59), a3);
        r->a = ((uint16_t)(y3 + 4) >> 8 << 8) | a3;
        r->x = x_e829;
        r->y = y3;
        r->c = (uint8_t)(value34 << 1) & 0x80;
        r->z = zero3;
        r->n = negative3;
        r->v = ((y3 ^ (uint16_t)(y3 + 4)) & ((uint16_t)(y3 + 4) ^ 4) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = dp;
        RETURN_RTS(c);
    }
    r->a = (uint16_t)(value6 + value7);
    r->x = x_e829;
    r->y = y_e829;
    r->c = (uint16_t)(value6 + value7) >= 0x0100;
    r->z = (uint16_t)(value6 + value7) == 0x0100;
    r->n = (uint16_t)((uint16_t)(value6 + value7) - 0x0100) & 0x8000;
    r->v = ((value6 ^ (uint16_t)(value6 + value7)) & (value7 ^ (uint16_t)(value6 + value7)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
}

/* C0E5CE prepare_and_emit_actor_body_sprites   [class A, 257 bytes, 129 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void prepare_and_emit_actor_body_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_e5e0 = 0;
    uint16_t x_e5e0 = 0;
    uint16_t y_e5e0 = 0;
    bool carry_e5e0 = 0;
    bool overflow_e5e0 = 0;
    uint8_t a_e5df = 0;
    uint8_t a_hi_e5df = 0;
    uint16_t x_e5df = 0;
    uint16_t y_e5df = 0;
    bool carry_e5df = 0;
    bool zero_e5df = 0;
    bool negative_e5df = 0;
    bool overflow_e5df = 0;
    uint8_t a_e5df2 = 0;
    uint8_t a_hi_e5df2 = 0;
    uint16_t x_e5df2 = 0;
    uint16_t y_e5df2 = 0;
    bool carry_e5df2 = 0;
    bool zero_e5df2 = 0;
    bool negative_e5df2 = 0;
    bool overflow_e5df2 = 0;
    uint16_t value = RAM16(0x0014);
    uint8_t value2 = RAM8(0xE00E + value);
    if (value2 == 0) {
        a_hi_e5e0 = a >> 8;
        x_e5e0 = value;
        y_e5e0 = y;
        carry_e5e0 = carry;
        overflow_e5e0 = overflow;
        goto shared_E5E0;
    }
    if (!((uint8_t)(value2 << 1) & 0x80)) {
        a_hi_e5e0 = a >> 8;
        x_e5e0 = value;
        y_e5e0 = y;
        carry_e5e0 = value2 & 0x80;
        overflow_e5e0 = overflow;
        goto shared_E5E0;
    }
    uint8_t value3 = RAM8(0x00F4);
    if (!(value3 & 0x01)) {
        a_hi_e5e0 = a >> 8;
        x_e5e0 = value;
        y_e5e0 = y;
        carry_e5e0 = value3 & 0x01;
        overflow_e5e0 = overflow;
        goto shared_E5E0;
    }
    a_e5df = value3 >> 1;
    a_hi_e5df = a >> 8;
    x_e5df = value;
    y_e5df = y;
    carry_e5df = value3 & 0x01;
    zero_e5df = value3 >> 1 == 0;
    negative_e5df = value3 >> 1 & 0x80;
    overflow_e5df = overflow;
    r->a = (a_hi_e5df << 8) | a_e5df;
    r->x = x_e5df;
    r->y = y_e5df;
    r->c = carry_e5df;
    r->z = zero_e5df;
    r->n = negative_e5df;
    r->v = overflow_e5df;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_E5E0:;
    uint16_t value4 = RAM16(0xE083 + x_e5e0);
    RAM16_SET(0x0002, value4 & 0x0F);
    if ((value4 & 0x0F) == 0) {
        a_e5df2 = value4 & 0x0F;
        a_hi_e5df2 = 0;
        x_e5df2 = x_e5e0;
        y_e5df2 = y_e5e0;
        carry_e5df2 = carry_e5e0;
        zero_e5df2 = (value4 & 0x0F) == 0;
        negative_e5df2 = value4 & 0x0F & 0x8000;
        overflow_e5df2 = overflow_e5e0;
        goto shared_E5DF_1;
    }
    uint16_t value5 = RAM16(0x0014);
    RAM16_SET(0x0004, RAM16(0xE020 + value5));
    uint16_t value7 = RAM16(0xE074 + value5);
    uint16_t value8 = RAM16(0xE045 + value5);
    uint16_t value9 = RAM16(0xE022 + value5);
    RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF) + value9 + 1));
    uint8_t value10 = RAM8(0xE00D + value5);
    uint8_t a3;
    bool overflow1;
    if (value10 == 0) {
        a3 = value10;
        overflow1 = (((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF) + value9 + 1)) & (value9 ^ (uint16_t)(((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF) + value9 + 1)) & 0x8000) != 0;
    } else {
        RAM8(0xE00D + value5) = (uint8_t)(value10 - 0x10);
        uint8_t a2;
        if (value10 >= 0x10) {
            if ((uint8_t)(value10 - 0x10) & 0x01) {
                RAM8(0x0000 + sp0) = (uint8_t)(value10 - 0x10) >> 1;
                RAM8(0x0004) = ((RAM8(0x00F4) & 1) << 1) ^ RAM8(0x0004);
            }
            uint8_t a1;
            if (!((uint8_t)(value10 - 0x10) >> 1 & 0x01)) {
                a1 = (uint8_t)(value10 - 0x10) >> 2;
            } else {
                uint8_t value13 = RAM8(0x00F4);
                uint8_t value14 = RAM8(0x0006);
                RAM8(0x0006) = ((value13 & 1) << 1) ^ value14;
                a1 = ((value13 & 1) << 1) ^ value14;
            }
            a2 = a1;
        } else {
            RAM8(0xE00D + value5) = 0;
            a2 = 0;
        }
        a3 = a2;
        overflow1 = ((value10 ^ 0x10) & (value10 ^ (uint8_t)(value10 - 0x10)) & 0x80) != 0;
    }
    uint8_t a4 = a3;
    uint8_t a_hi1 = (uint16_t)(((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF) + value9 + 1) >> 8;
    uint16_t x1 = value5 | 0x90 | 0xE000;
    uint16_t y1 = value5 | 0x90 | 0xE000;
    bool carry1 = 0;
    bool zero1 = (value5 | 0x90 | 0xE000) == 0;
    bool negative1 = (value5 | 0x90 | 0xE000) & 0x8000;
    bool overflow2 = overflow1;
    for (;;) {
        uint16_t value15 = RAM16(0x007C);
        if (value15 >= 0x0200) {
            r->a = (a_hi1 << 8) | a4;
            r->x = x1;
            r->y = value15;
            r->c = value15 >= 0x0200;
            r->z = value15 == 0x0200;
            r->n = (uint16_t)(value15 - 0x0200) & 0x8000;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value16 = RAM8(0x0001 + x1);
        uint8_t a5;
        uint8_t a_hi2;
        if (!(value16 & 0x80)) {
            a5 = value16;
            a_hi2 = 0;
        } else {
            a5 = (uint8_t)(value16 | 0xFF00);
            a_hi2 = (value16 | 0xFF00) >> 8;
        }
        uint16_t value17 = RAM16(0x0006);
        if ((uint16_t)(((a_hi2 << 8) | a5) + value17) & 0x8000) {
            bool m_flag6;
            uint8_t a15;
            uint8_t a_hi12;
            uint16_t y10;
            bool carry7;
            bool overflow8;
            if ((uint16_t)(((a_hi2 << 8) | a5) + value17) < 0xFFF0) {
                m_flag6 = 0;
                a15 = (uint8_t)(((a_hi2 << 8) | a5) + value17);
                a_hi12 = (uint16_t)(((a_hi2 << 8) | a5) + value17) >> 8;
                y10 = value15;
                carry7 = (uint16_t)(((a_hi2 << 8) | a5) + value17) >= 0xFFF0;
                overflow8 = ((((a_hi2 << 8) | a5) ^ (uint16_t)(((a_hi2 << 8) | a5) + value17)) & (value17 ^ (uint16_t)(((a_hi2 << 8) | a5) + value17)) & 0x8000) != 0;
            } else {
                RAM8(0x0801 + value15) = (uint8_t)(((a_hi2 << 8) | a5) + value17);
                uint8_t value18 = RAM8(0x0000 + x1);
                uint8_t a6;
                uint8_t a_hi3;
                if (!(value18 & 0x80)) {
                    a6 = value18;
                    a_hi3 = 0;
                } else {
                    a6 = (uint8_t)(value18 | 0xFF00);
                    a_hi3 = (value18 | 0xFF00) >> 8;
                }
                uint16_t value19 = RAM16(0x0004);
                bool m_flag5;
                uint8_t a14;
                uint8_t a_hi11;
                uint16_t y9;
                bool carry6;
                bool overflow7;
                if ((uint16_t)(((a_hi3 << 8) | a6) + value19) & 0x8000) {
                    bool m_flag;
                    uint8_t a8;
                    uint8_t a_hi5;
                    uint16_t y3;
                    bool carry2;
                    bool overflow3;
                    if ((uint16_t)(((a_hi3 << 8) | a6) + value19) < 0xFFF0) {
                        m_flag = 0;
                        a8 = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                        a_hi5 = (uint16_t)(((a_hi3 << 8) | a6) + value19) >> 8;
                        y3 = value15;
                        carry2 = (uint16_t)(((a_hi3 << 8) | a6) + value19) >= 0xFFF0;
                        overflow3 = ((((a_hi3 << 8) | a6) ^ (uint16_t)(((a_hi3 << 8) | a6) + value19)) & (value19 ^ (uint16_t)(((a_hi3 << 8) | a6) + value19)) & 0x8000) != 0;
                    } else {
                        RAM8(0x0800 + value15) = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                        uint8_t a_hi4;
                        uint16_t y2;
                        if ((uint16_t)(((a_hi3 << 8) | a6) + value19) >> 8 == 0) {
                            a_hi4 = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                            y2 = value15;
                        } else {
                            uint8_t value20 = RAM8(0x005A);
                            RAM8(0x0A00 + value20) ^= RAM8(0x0059);
                            uint16_t value23 = RAM16(0x007C);
                            a_hi4 = 0;
                            y2 = value23;
                        }
                        RAM16_SET(0x0802 + y2, RAM16(0x0002 + x1));
                        RAM16_SET(0x007C, (uint16_t)(y2 + 4));
                        uint8_t value25 = RAM8(0x0059);
                        uint8_t a7;
                        if (!((uint8_t)(value25 << 1) & 0x80)) {
                            a7 = (uint8_t)(value25 << 2);
                        } else {
                            RAM8(0x005A)++;
                            a7 = 1;
                        }
                        RAM8(0x0059) = a7;
                        m_flag = 1;
                        a8 = a7;
                        a_hi5 = (uint16_t)(y2 + 4) >> 8;
                        y3 = (uint16_t)(y2 + 4);
                        carry2 = (uint8_t)(value25 << 1) & 0x80;
                        overflow3 = ((y2 ^ (uint16_t)(y2 + 4)) & ((uint16_t)(y2 + 4) ^ 4) & 0x8000) != 0;
                    }
                    m_flag5 = m_flag;
                    a14 = a8;
                    a_hi11 = a_hi5;
                    y9 = y3;
                    carry6 = carry2;
                    overflow7 = overflow3;
                } else {
                    bool m_flag4;
                    uint8_t a13;
                    uint8_t a_hi10;
                    uint16_t y8;
                    bool carry5;
                    bool overflow6;
                    if ((uint16_t)(((a_hi3 << 8) | a6) + value19) < 0x0100) {
                        RAM8(0x0800 + value15) = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                        uint8_t a_hi6;
                        uint16_t y4;
                        if ((uint16_t)(((a_hi3 << 8) | a6) + value19) >> 8 == 0) {
                            a_hi6 = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                            y4 = value15;
                        } else {
                            uint8_t value26 = RAM8(0x005A);
                            RAM8(0x0A00 + value26) ^= RAM8(0x0059);
                            uint16_t value29 = RAM16(0x007C);
                            a_hi6 = 0;
                            y4 = value29;
                        }
                        RAM16_SET(0x0802 + y4, RAM16(0x0002 + x1));
                        RAM16_SET(0x007C, (uint16_t)(y4 + 4));
                        uint8_t value31 = RAM8(0x0059);
                        uint8_t a9;
                        if (!((uint8_t)(value31 << 1) & 0x80)) {
                            a9 = (uint8_t)(value31 << 2);
                        } else {
                            RAM8(0x005A)++;
                            a9 = 1;
                        }
                        RAM8(0x0059) = a9;
                        m_flag4 = 1;
                        a13 = a9;
                        a_hi10 = (uint16_t)(y4 + 4) >> 8;
                        y8 = (uint16_t)(y4 + 4);
                        carry5 = (uint8_t)(value31 << 1) & 0x80;
                        overflow6 = ((y4 ^ (uint16_t)(y4 + 4)) & ((uint16_t)(y4 + 4) ^ 4) & 0x8000) != 0;
                    } else {
                        bool m_flag3;
                        uint8_t a12;
                        uint8_t a_hi9;
                        uint16_t y7;
                        bool carry4;
                        bool overflow5;
                        if ((uint16_t)(((a_hi3 << 8) | a6) + value19) >= 0x0100) {
                            m_flag3 = 0;
                            a12 = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                            a_hi9 = (uint16_t)(((a_hi3 << 8) | a6) + value19) >> 8;
                            y7 = value15;
                            carry4 = (uint16_t)(((a_hi3 << 8) | a6) + value19) >= 0x0100;
                            overflow5 = ((((a_hi3 << 8) | a6) ^ (uint16_t)(((a_hi3 << 8) | a6) + value19)) & (value19 ^ (uint16_t)(((a_hi3 << 8) | a6) + value19)) & 0x8000) != 0;
                        } else {
                            bool m_flag2;
                            uint8_t a11;
                            uint8_t a_hi8;
                            uint16_t y6;
                            bool carry3;
                            bool overflow4;
                            if ((uint16_t)(((a_hi3 << 8) | a6) + value19) < 0xFFF0) {
                                m_flag2 = 0;
                                a11 = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                                a_hi8 = (uint16_t)(((a_hi3 << 8) | a6) + value19) >> 8;
                                y6 = value15;
                                carry3 = (uint16_t)(((a_hi3 << 8) | a6) + value19) >= 0xFFF0;
                                overflow4 = ((((a_hi3 << 8) | a6) ^ (uint16_t)(((a_hi3 << 8) | a6) + value19)) & (value19 ^ (uint16_t)(((a_hi3 << 8) | a6) + value19)) & 0x8000) != 0;
                            } else {
                                RAM8(0x0800 + value15) = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                                uint8_t a_hi7;
                                uint16_t y5;
                                if ((uint16_t)(((a_hi3 << 8) | a6) + value19) >> 8 == 0) {
                                    a_hi7 = (uint8_t)(((a_hi3 << 8) | a6) + value19);
                                    y5 = value15;
                                } else {
                                    uint8_t value32 = RAM8(0x005A);
                                    RAM8(0x0A00 + value32) ^= RAM8(0x0059);
                                    uint16_t value35 = RAM16(0x007C);
                                    a_hi7 = 0;
                                    y5 = value35;
                                }
                                RAM16_SET(0x0802 + y5, RAM16(0x0002 + x1));
                                RAM16_SET(0x007C, (uint16_t)(y5 + 4));
                                uint8_t value37 = RAM8(0x0059);
                                uint8_t a10;
                                if (!((uint8_t)(value37 << 1) & 0x80)) {
                                    a10 = (uint8_t)(value37 << 2);
                                } else {
                                    RAM8(0x005A)++;
                                    a10 = 1;
                                }
                                RAM8(0x0059) = a10;
                                m_flag2 = 1;
                                a11 = a10;
                                a_hi8 = (uint16_t)(y5 + 4) >> 8;
                                y6 = (uint16_t)(y5 + 4);
                                carry3 = (uint8_t)(value37 << 1) & 0x80;
                                overflow4 = ((y5 ^ (uint16_t)(y5 + 4)) & ((uint16_t)(y5 + 4) ^ 4) & 0x8000) != 0;
                            }
                            m_flag3 = m_flag2;
                            a12 = a11;
                            a_hi9 = a_hi8;
                            y7 = y6;
                            carry4 = carry3;
                            overflow5 = overflow4;
                        }
                        m_flag4 = m_flag3;
                        a13 = a12;
                        a_hi10 = a_hi9;
                        y8 = y7;
                        carry5 = carry4;
                        overflow6 = overflow5;
                    }
                    m_flag5 = m_flag4;
                    a14 = a13;
                    a_hi11 = a_hi10;
                    y9 = y8;
                    carry6 = carry5;
                    overflow7 = overflow6;
                }
                m_flag6 = m_flag5;
                a15 = a14;
                a_hi12 = a_hi11;
                y10 = y9;
                carry7 = carry6;
                overflow8 = overflow7;
            }
            RAM8(0x0002)--;
            if (RAM8(0x0002) == 0) {
                a4 = a15;
                a_hi1 = a_hi12;
                y1 = y10;
                carry1 = carry7;
                zero1 = RAM8(0x0002) == 0;
                negative1 = RAM8(0x0002) & 0x80;
                overflow2 = overflow8;
                break;
            }
            uint8_t a4_next = a15;
            uint8_t a_hi1_next = a_hi12;
            uint16_t x1_next = (uint16_t)(x1 + 4);
            uint16_t y1_next = y10;
            bool carry1_next = carry7;
            bool zero1_next = (uint16_t)(x1 + 4) == 0;
            bool negative1_next = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next = overflow8;
            a4 = a4_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            zero1 = zero1_next;
            negative1 = negative1_next;
            overflow2 = overflow2_next;
            continue;
        }
        if ((uint16_t)(((a_hi2 << 8) | a5) + value17) < 0xE0) {
            RAM8(0x0801 + value15) = (uint8_t)(((a_hi2 << 8) | a5) + value17);
            uint8_t value38 = RAM8(0x0000 + x1);
            uint8_t a16;
            uint8_t a_hi13;
            if (!(value38 & 0x80)) {
                a16 = value38;
                a_hi13 = 0;
            } else {
                a16 = (uint8_t)(value38 | 0xFF00);
                a_hi13 = (value38 | 0xFF00) >> 8;
            }
            uint16_t value39 = RAM16(0x0004);
            bool m_flag11;
            uint8_t a24;
            uint8_t a_hi21;
            uint16_t y18;
            bool carry12;
            bool overflow13;
            if ((uint16_t)(((a_hi13 << 8) | a16) + value39) & 0x8000) {
                bool m_flag7;
                uint8_t a18;
                uint8_t a_hi15;
                uint16_t y12;
                bool carry8;
                bool overflow9;
                if ((uint16_t)(((a_hi13 << 8) | a16) + value39) < 0xFFF0) {
                    m_flag7 = 0;
                    a18 = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                    a_hi15 = (uint16_t)(((a_hi13 << 8) | a16) + value39) >> 8;
                    y12 = value15;
                    carry8 = (uint16_t)(((a_hi13 << 8) | a16) + value39) >= 0xFFF0;
                    overflow9 = ((((a_hi13 << 8) | a16) ^ (uint16_t)(((a_hi13 << 8) | a16) + value39)) & (value39 ^ (uint16_t)(((a_hi13 << 8) | a16) + value39)) & 0x8000) != 0;
                } else {
                    RAM8(0x0800 + value15) = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                    uint8_t a_hi14;
                    uint16_t y11;
                    if ((uint16_t)(((a_hi13 << 8) | a16) + value39) >> 8 == 0) {
                        a_hi14 = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                        y11 = value15;
                    } else {
                        uint8_t value40 = RAM8(0x005A);
                        RAM8(0x0A00 + value40) ^= RAM8(0x0059);
                        uint16_t value43 = RAM16(0x007C);
                        a_hi14 = 0;
                        y11 = value43;
                    }
                    RAM16_SET(0x0802 + y11, RAM16(0x0002 + x1));
                    RAM16_SET(0x007C, (uint16_t)(y11 + 4));
                    uint8_t value45 = RAM8(0x0059);
                    uint8_t a17;
                    if (!((uint8_t)(value45 << 1) & 0x80)) {
                        a17 = (uint8_t)(value45 << 2);
                    } else {
                        RAM8(0x005A)++;
                        a17 = 1;
                    }
                    RAM8(0x0059) = a17;
                    m_flag7 = 1;
                    a18 = a17;
                    a_hi15 = (uint16_t)(y11 + 4) >> 8;
                    y12 = (uint16_t)(y11 + 4);
                    carry8 = (uint8_t)(value45 << 1) & 0x80;
                    overflow9 = ((y11 ^ (uint16_t)(y11 + 4)) & ((uint16_t)(y11 + 4) ^ 4) & 0x8000) != 0;
                }
                m_flag11 = m_flag7;
                a24 = a18;
                a_hi21 = a_hi15;
                y18 = y12;
                carry12 = carry8;
                overflow13 = overflow9;
            } else {
                bool m_flag10;
                uint8_t a23;
                uint8_t a_hi20;
                uint16_t y17;
                bool carry11;
                bool overflow12;
                if ((uint16_t)(((a_hi13 << 8) | a16) + value39) < 0x0100) {
                    RAM8(0x0800 + value15) = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                    uint8_t a_hi16;
                    uint16_t y13;
                    if ((uint16_t)(((a_hi13 << 8) | a16) + value39) >> 8 == 0) {
                        a_hi16 = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                        y13 = value15;
                    } else {
                        uint8_t value46 = RAM8(0x005A);
                        RAM8(0x0A00 + value46) ^= RAM8(0x0059);
                        uint16_t value49 = RAM16(0x007C);
                        a_hi16 = 0;
                        y13 = value49;
                    }
                    RAM16_SET(0x0802 + y13, RAM16(0x0002 + x1));
                    RAM16_SET(0x007C, (uint16_t)(y13 + 4));
                    uint8_t value51 = RAM8(0x0059);
                    uint8_t a19;
                    if (!((uint8_t)(value51 << 1) & 0x80)) {
                        a19 = (uint8_t)(value51 << 2);
                    } else {
                        RAM8(0x005A)++;
                        a19 = 1;
                    }
                    RAM8(0x0059) = a19;
                    m_flag10 = 1;
                    a23 = a19;
                    a_hi20 = (uint16_t)(y13 + 4) >> 8;
                    y17 = (uint16_t)(y13 + 4);
                    carry11 = (uint8_t)(value51 << 1) & 0x80;
                    overflow12 = ((y13 ^ (uint16_t)(y13 + 4)) & ((uint16_t)(y13 + 4) ^ 4) & 0x8000) != 0;
                } else {
                    bool m_flag9;
                    uint8_t a22;
                    uint8_t a_hi19;
                    uint16_t y16;
                    bool carry10;
                    bool overflow11;
                    if ((uint16_t)(((a_hi13 << 8) | a16) + value39) >= 0x0100) {
                        m_flag9 = 0;
                        a22 = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                        a_hi19 = (uint16_t)(((a_hi13 << 8) | a16) + value39) >> 8;
                        y16 = value15;
                        carry10 = (uint16_t)(((a_hi13 << 8) | a16) + value39) >= 0x0100;
                        overflow11 = ((((a_hi13 << 8) | a16) ^ (uint16_t)(((a_hi13 << 8) | a16) + value39)) & (value39 ^ (uint16_t)(((a_hi13 << 8) | a16) + value39)) & 0x8000) != 0;
                    } else {
                        bool m_flag8;
                        uint8_t a21;
                        uint8_t a_hi18;
                        uint16_t y15;
                        bool carry9;
                        bool overflow10;
                        if ((uint16_t)(((a_hi13 << 8) | a16) + value39) < 0xFFF0) {
                            m_flag8 = 0;
                            a21 = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                            a_hi18 = (uint16_t)(((a_hi13 << 8) | a16) + value39) >> 8;
                            y15 = value15;
                            carry9 = (uint16_t)(((a_hi13 << 8) | a16) + value39) >= 0xFFF0;
                            overflow10 = ((((a_hi13 << 8) | a16) ^ (uint16_t)(((a_hi13 << 8) | a16) + value39)) & (value39 ^ (uint16_t)(((a_hi13 << 8) | a16) + value39)) & 0x8000) != 0;
                        } else {
                            RAM8(0x0800 + value15) = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                            uint8_t a_hi17;
                            uint16_t y14;
                            if ((uint16_t)(((a_hi13 << 8) | a16) + value39) >> 8 == 0) {
                                a_hi17 = (uint8_t)(((a_hi13 << 8) | a16) + value39);
                                y14 = value15;
                            } else {
                                uint8_t value52 = RAM8(0x005A);
                                RAM8(0x0A00 + value52) ^= RAM8(0x0059);
                                uint16_t value55 = RAM16(0x007C);
                                a_hi17 = 0;
                                y14 = value55;
                            }
                            RAM16_SET(0x0802 + y14, RAM16(0x0002 + x1));
                            RAM16_SET(0x007C, (uint16_t)(y14 + 4));
                            uint8_t value57 = RAM8(0x0059);
                            uint8_t a20;
                            if (!((uint8_t)(value57 << 1) & 0x80)) {
                                a20 = (uint8_t)(value57 << 2);
                            } else {
                                RAM8(0x005A)++;
                                a20 = 1;
                            }
                            RAM8(0x0059) = a20;
                            m_flag8 = 1;
                            a21 = a20;
                            a_hi18 = (uint16_t)(y14 + 4) >> 8;
                            y15 = (uint16_t)(y14 + 4);
                            carry9 = (uint8_t)(value57 << 1) & 0x80;
                            overflow10 = ((y14 ^ (uint16_t)(y14 + 4)) & ((uint16_t)(y14 + 4) ^ 4) & 0x8000) != 0;
                        }
                        m_flag9 = m_flag8;
                        a22 = a21;
                        a_hi19 = a_hi18;
                        y16 = y15;
                        carry10 = carry9;
                        overflow11 = overflow10;
                    }
                    m_flag10 = m_flag9;
                    a23 = a22;
                    a_hi20 = a_hi19;
                    y17 = y16;
                    carry11 = carry10;
                    overflow12 = overflow11;
                }
                m_flag11 = m_flag10;
                a24 = a23;
                a_hi21 = a_hi20;
                y18 = y17;
                carry12 = carry11;
                overflow13 = overflow12;
            }
            RAM8(0x0002)--;
            if (RAM8(0x0002) == 0) {
                a4 = a24;
                a_hi1 = a_hi21;
                y1 = y18;
                carry1 = carry12;
                zero1 = RAM8(0x0002) == 0;
                negative1 = RAM8(0x0002) & 0x80;
                overflow2 = overflow13;
                break;
            }
            uint8_t a4_next2 = a24;
            uint8_t a_hi1_next2 = a_hi21;
            uint16_t x1_next2 = (uint16_t)(x1 + 4);
            uint16_t y1_next2 = y18;
            bool carry1_next2 = carry12;
            bool zero1_next2 = (uint16_t)(x1 + 4) == 0;
            bool negative1_next2 = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next2 = overflow13;
            a4 = a4_next2;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            y1 = y1_next2;
            carry1 = carry1_next2;
            zero1 = zero1_next2;
            negative1 = negative1_next2;
            overflow2 = overflow2_next2;
            continue;
        }
        if ((uint16_t)(((a_hi2 << 8) | a5) + value17) >= 0xE0) {
            RAM8(0x0002)--;
            if (RAM8(0x0002) == 0) {
                a4 = (uint8_t)(((a_hi2 << 8) | a5) + value17);
                a_hi1 = (uint16_t)(((a_hi2 << 8) | a5) + value17) >> 8;
                y1 = value15;
                carry1 = (uint16_t)(((a_hi2 << 8) | a5) + value17) >= 0xE0;
                zero1 = RAM8(0x0002) == 0;
                negative1 = RAM8(0x0002) & 0x80;
                overflow2 = ((((a_hi2 << 8) | a5) ^ (uint16_t)(((a_hi2 << 8) | a5) + value17)) & (value17 ^ (uint16_t)(((a_hi2 << 8) | a5) + value17)) & 0x8000) != 0;
                break;
            }
            uint8_t a4_next3 = (uint8_t)(((a_hi2 << 8) | a5) + value17);
            uint8_t a_hi1_next3 = (uint16_t)(((a_hi2 << 8) | a5) + value17) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 + 4);
            uint16_t y1_next3 = value15;
            bool carry1_next3 = (uint16_t)(((a_hi2 << 8) | a5) + value17) >= 0xE0;
            bool zero1_next3 = (uint16_t)(x1 + 4) == 0;
            bool negative1_next3 = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next3 = ((((a_hi2 << 8) | a5) ^ (uint16_t)(((a_hi2 << 8) | a5) + value17)) & (value17 ^ (uint16_t)(((a_hi2 << 8) | a5) + value17)) & 0x8000) != 0;
            a4 = a4_next3;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            y1 = y1_next3;
            carry1 = carry1_next3;
            zero1 = zero1_next3;
            negative1 = negative1_next3;
            overflow2 = overflow2_next3;
            continue;
        }
        r->a = (uint16_t)(((a_hi2 << 8) | a5) + value17);
        r->x = x1;
        r->y = value15;
        r->c = (uint16_t)(((a_hi2 << 8) | a5) + value17) >= 0xE0;
        r->z = (uint16_t)(((a_hi2 << 8) | a5) + value17) == 0xE0;
        r->n = (uint16_t)((uint16_t)(((a_hi2 << 8) | a5) + value17) - 0xE0) & 0x8000;
        r->v = ((((a_hi2 << 8) | a5) ^ (uint16_t)(((a_hi2 << 8) | a5) + value17)) & (value17 ^ (uint16_t)(((a_hi2 << 8) | a5) + value17)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi1 << 8) | a4;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_E5DF_1:;
    r->a = (a_hi_e5df2 << 8) | a_e5df2;
    r->x = x_e5df2;
    r->y = y_e5df2;
    r->c = carry_e5df2;
    r->z = zero_e5df2;
    r->n = negative_e5df2;
    r->v = overflow_e5df2;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}

/* C0E5CE prepare_and_emit_actor_body_sprites_v2   [class A, 257 bytes, 129 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void prepare_and_emit_actor_body_sprites_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_hi_e5e0 = 0;
    uint16_t x_e5e0 = 0;
    uint16_t y_e5e0 = 0;
    bool carry_e5e0 = 0;
    bool overflow_e5e0 = 0;
    uint8_t a_e5df = 0;
    uint8_t a_hi_e5df = 0;
    uint16_t x_e5df = 0;
    uint16_t y_e5df = 0;
    bool carry_e5df = 0;
    bool zero_e5df = 0;
    bool negative_e5df = 0;
    bool overflow_e5df = 0;
    uint8_t a_e5df2 = 0;
    uint8_t a_hi_e5df2 = 0;
    uint16_t x_e5df2 = 0;
    uint16_t y_e5df2 = 0;
    bool carry_e5df2 = 0;
    bool zero_e5df2 = 0;
    bool negative_e5df2 = 0;
    bool overflow_e5df2 = 0;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xE00E + value);
    if (value2 == 0) {
        a_hi_e5e0 = a >> 8;
        x_e5e0 = value;
        y_e5e0 = y;
        carry_e5e0 = carry;
        overflow_e5e0 = overflow;
        goto shared_E5E0;
    }
    if (!((uint8_t)(value2 << 1) & 0x80)) {
        a_hi_e5e0 = a >> 8;
        x_e5e0 = value;
        y_e5e0 = y;
        carry_e5e0 = value2 & 0x80;
        overflow_e5e0 = overflow;
        goto shared_E5E0;
    }
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
    if (!(value3 & 0x01)) {
        a_hi_e5e0 = a >> 8;
        x_e5e0 = value;
        y_e5e0 = y;
        carry_e5e0 = value3 & 0x01;
        overflow_e5e0 = overflow;
        goto shared_E5E0;
    }
    a_e5df = value3 >> 1;
    a_hi_e5df = a >> 8;
    x_e5df = value;
    y_e5df = y;
    carry_e5df = value3 & 0x01;
    zero_e5df = value3 >> 1 == 0;
    negative_e5df = value3 >> 1 & 0x80;
    overflow_e5df = overflow;
    r->a = (a_hi_e5df << 8) | a_e5df;
    r->x = x_e5df;
    r->y = y_e5df;
    r->c = carry_e5df;
    r->z = zero_e5df;
    r->n = negative_e5df;
    r->v = overflow_e5df;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
    shared_E5E0:;
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0xE083 + x_e5e0);
    BUS16_SET(c, (uint16_t)(dp + 2), value4 & 0x0F);
    if ((value4 & 0x0F) == 0) {
        a_e5df2 = value4 & 0x0F;
        a_hi_e5df2 = 0;
        x_e5df2 = x_e5e0;
        y_e5df2 = y_e5e0;
        carry_e5df2 = carry_e5e0;
        zero_e5df2 = (value4 & 0x0F) == 0;
        negative_e5df2 = value4 & 0x0F & 0x8000;
        overflow_e5df2 = overflow_e5e0;
        goto shared_E5DF_1;
    }
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    uint16_t value7 = BUS16_RDP(c, (db << 0x10) + 0xE020 + value6);
    BUS16_SET(c, (uint16_t)(dp + 4), value7);
    uint16_t value8 = BUS16_RDP(c, (db << 0x10) + 0xE074 + value6);
    uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0xE045 + value6);
    uint16_t value10 = BUS16_RDP(c, (db << 0x10) + 0xE022 + value6);
    BUS16_SET(c, (uint16_t)(dp + 6), (uint16_t)(((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF) + value10 + 1));
    uint8_t value11 = BUS8_RDP(c, (db << 0x10) + 0xE00D + value6);
    uint8_t a4;
    bool overflow1;
    if (value11 == 0) {
        a4 = value11;
        overflow1 = (((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF) + value10 + 1)) & (value10 ^ (uint16_t)(((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF) + value10 + 1)) & 0x8000) != 0;
    } else {
        BUS8_SET(c, (db << 0x10) + 0xE00D + value6, (uint8_t)(value11 - 0x10));
        uint8_t a3;
        if (value11 >= 0x10) {
            uint8_t a1;
            if (!((uint8_t)(value11 - 0x10) & 0x01)) {
                a1 = (uint8_t)(value11 - 0x10) >> 1;
            } else {
                RAM8(0x0000 + sp0) = (uint8_t)(value11 - 0x10) >> 1;
                uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp + 4));
                BUS8_SET(c, (uint16_t)(dp + 4), ((value12 & 1) << 1) ^ value13);
                a1 = RAM8(0x0000 + sp0);
            }
            uint8_t a2;
            if (!(a1 & 0x01)) {
                a2 = a1 >> 1;
            } else {
                uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp + 6));
                BUS8_SET(c, (uint16_t)(dp + 6), ((value15 & 1) << 1) ^ value16);
                a2 = ((value15 & 1) << 1) ^ value16;
            }
            a3 = a2;
        } else {
            BUS8_SET(c, (db << 0x10) + 0xE00D + value6, 0);
            a3 = 0;
        }
        a4 = a3;
        overflow1 = ((value11 ^ 0x10) & (value11 ^ (uint8_t)(value11 - 0x10)) & 0x80) != 0;
    }
    uint8_t a5 = a4;
    uint8_t a_hi1 = (uint16_t)(((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF) + value10 + 1) >> 8;
    uint16_t x1 = value5 | 0x90 | 0xE000;
    uint16_t y1 = value5 | 0x90 | 0xE000;
    bool carry1 = 0;
    bool zero1 = (value5 | 0x90 | 0xE000) == 0;
    bool negative1 = (value5 | 0x90 | 0xE000) & 0x8000;
    bool overflow2 = overflow1;
    for (;;) {
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
        if (value17 >= 0x0200) {
            r->a = (a_hi1 << 8) | a5;
            r->x = x1;
            r->y = value17;
            r->c = value17 >= 0x0200;
            r->z = value17 == 0x0200;
            r->n = (uint16_t)(value17 - 0x0200) & 0x8000;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = db;
            r->dp = dp;
            RETURN_RTS(c);
        }
        uint8_t value18 = BUS8_RDP(c, (db << 0x10) + 1 + x1);
        uint8_t a6;
        uint8_t a_hi2;
        if (!(value18 & 0x80)) {
            a6 = value18;
            a_hi2 = 0;
        } else {
            a6 = (uint8_t)(value18 | 0xFF00);
            a_hi2 = (value18 | 0xFF00) >> 8;
        }
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp + 6));
        if ((uint16_t)(((a_hi2 << 8) | a6) + value19) & 0x8000) {
            bool m_flag6;
            uint8_t a16;
            uint8_t a_hi12;
            uint16_t y10;
            bool carry7;
            bool overflow8;
            if ((uint16_t)(((a_hi2 << 8) | a6) + value19) < 0xFFF0) {
                m_flag6 = 0;
                a16 = (uint8_t)(((a_hi2 << 8) | a6) + value19);
                a_hi12 = (uint16_t)(((a_hi2 << 8) | a6) + value19) >> 8;
                y10 = value17;
                carry7 = (uint16_t)(((a_hi2 << 8) | a6) + value19) >= 0xFFF0;
                overflow8 = ((((a_hi2 << 8) | a6) ^ (uint16_t)(((a_hi2 << 8) | a6) + value19)) & (value19 ^ (uint16_t)(((a_hi2 << 8) | a6) + value19)) & 0x8000) != 0;
            } else {
                BUS8_SET(c, (db << 0x10) + 0x0801 + value17, (uint8_t)(((a_hi2 << 8) | a6) + value19));
                uint8_t value20 = BUS8_RDP(c, (db << 0x10) + x1);
                uint8_t a7;
                uint8_t a_hi3;
                if (!(value20 & 0x80)) {
                    a7 = value20;
                    a_hi3 = 0;
                } else {
                    a7 = (uint8_t)(value20 | 0xFF00);
                    a_hi3 = (value20 | 0xFF00) >> 8;
                }
                uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp + 4));
                bool m_flag5;
                uint8_t a15;
                uint8_t a_hi11;
                uint16_t y9;
                bool carry6;
                bool overflow7;
                if ((uint16_t)(((a_hi3 << 8) | a7) + value21) & 0x8000) {
                    bool m_flag;
                    uint8_t a9;
                    uint8_t a_hi5;
                    uint16_t y3;
                    bool carry2;
                    bool overflow3;
                    if ((uint16_t)(((a_hi3 << 8) | a7) + value21) < 0xFFF0) {
                        m_flag = 0;
                        a9 = (uint8_t)(((a_hi3 << 8) | a7) + value21);
                        a_hi5 = (uint16_t)(((a_hi3 << 8) | a7) + value21) >> 8;
                        y3 = value17;
                        carry2 = (uint16_t)(((a_hi3 << 8) | a7) + value21) >= 0xFFF0;
                        overflow3 = ((((a_hi3 << 8) | a7) ^ (uint16_t)(((a_hi3 << 8) | a7) + value21)) & (value21 ^ (uint16_t)(((a_hi3 << 8) | a7) + value21)) & 0x8000) != 0;
                    } else {
                        BUS8_SET(c, (db << 0x10) + 0x0800 + value17, (uint8_t)(((a_hi3 << 8) | a7) + value21));
                        uint8_t a_hi4;
                        uint16_t y2;
                        if ((uint16_t)(((a_hi3 << 8) | a7) + value21) >> 8 == 0) {
                            a_hi4 = (uint8_t)(((a_hi3 << 8) | a7) + value21);
                            y2 = value17;
                        } else {
                            uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                            uint8_t value23 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value22);
                            uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                            BUS8_SET(c, (db << 0x10) + 0x0A00 + value22, value23 ^ value24);
                            uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                            a_hi4 = 0;
                            y2 = value25;
                        }
                        uint16_t value26 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                        BUS16_SET(c, (db << 0x10) + 0x0802 + y2, value26);
                        BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y2 + 4));
                        uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                        uint8_t a8;
                        if (!((uint8_t)(value27 << 1) & 0x80)) {
                            a8 = (uint8_t)(value27 << 2);
                        } else {
                            uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                            BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value28 + 1));
                            a8 = 1;
                        }
                        BUS8_SET(c, (uint16_t)(dp + 0x59), a8);
                        m_flag = 1;
                        a9 = a8;
                        a_hi5 = (uint16_t)(y2 + 4) >> 8;
                        y3 = (uint16_t)(y2 + 4);
                        carry2 = (uint8_t)(value27 << 1) & 0x80;
                        overflow3 = ((y2 ^ (uint16_t)(y2 + 4)) & ((uint16_t)(y2 + 4) ^ 4) & 0x8000) != 0;
                    }
                    m_flag5 = m_flag;
                    a15 = a9;
                    a_hi11 = a_hi5;
                    y9 = y3;
                    carry6 = carry2;
                    overflow7 = overflow3;
                } else {
                    bool m_flag4;
                    uint8_t a14;
                    uint8_t a_hi10;
                    uint16_t y8;
                    bool carry5;
                    bool overflow6;
                    if ((uint16_t)(((a_hi3 << 8) | a7) + value21) < 0x0100) {
                        BUS8_SET(c, (db << 0x10) + 0x0800 + value17, (uint8_t)(((a_hi3 << 8) | a7) + value21));
                        uint8_t a_hi6;
                        uint16_t y4;
                        if ((uint16_t)(((a_hi3 << 8) | a7) + value21) >> 8 == 0) {
                            a_hi6 = (uint8_t)(((a_hi3 << 8) | a7) + value21);
                            y4 = value17;
                        } else {
                            uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                            uint8_t value30 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value29);
                            uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                            BUS8_SET(c, (db << 0x10) + 0x0A00 + value29, value30 ^ value31);
                            uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                            a_hi6 = 0;
                            y4 = value32;
                        }
                        uint16_t value33 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                        BUS16_SET(c, (db << 0x10) + 0x0802 + y4, value33);
                        BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y4 + 4));
                        uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                        uint8_t a10;
                        if (!((uint8_t)(value34 << 1) & 0x80)) {
                            a10 = (uint8_t)(value34 << 2);
                        } else {
                            uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                            BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value35 + 1));
                            a10 = 1;
                        }
                        BUS8_SET(c, (uint16_t)(dp + 0x59), a10);
                        m_flag4 = 1;
                        a14 = a10;
                        a_hi10 = (uint16_t)(y4 + 4) >> 8;
                        y8 = (uint16_t)(y4 + 4);
                        carry5 = (uint8_t)(value34 << 1) & 0x80;
                        overflow6 = ((y4 ^ (uint16_t)(y4 + 4)) & ((uint16_t)(y4 + 4) ^ 4) & 0x8000) != 0;
                    } else {
                        bool m_flag3;
                        uint8_t a13;
                        uint8_t a_hi9;
                        uint16_t y7;
                        bool carry4;
                        bool overflow5;
                        if ((uint16_t)(((a_hi3 << 8) | a7) + value21) >= 0x0100) {
                            m_flag3 = 0;
                            a13 = (uint8_t)(((a_hi3 << 8) | a7) + value21);
                            a_hi9 = (uint16_t)(((a_hi3 << 8) | a7) + value21) >> 8;
                            y7 = value17;
                            carry4 = (uint16_t)(((a_hi3 << 8) | a7) + value21) >= 0x0100;
                            overflow5 = ((((a_hi3 << 8) | a7) ^ (uint16_t)(((a_hi3 << 8) | a7) + value21)) & (value21 ^ (uint16_t)(((a_hi3 << 8) | a7) + value21)) & 0x8000) != 0;
                        } else {
                            bool m_flag2;
                            uint8_t a12;
                            uint8_t a_hi8;
                            uint16_t y6;
                            bool carry3;
                            bool overflow4;
                            if ((uint16_t)(((a_hi3 << 8) | a7) + value21) < 0xFFF0) {
                                m_flag2 = 0;
                                a12 = (uint8_t)(((a_hi3 << 8) | a7) + value21);
                                a_hi8 = (uint16_t)(((a_hi3 << 8) | a7) + value21) >> 8;
                                y6 = value17;
                                carry3 = (uint16_t)(((a_hi3 << 8) | a7) + value21) >= 0xFFF0;
                                overflow4 = ((((a_hi3 << 8) | a7) ^ (uint16_t)(((a_hi3 << 8) | a7) + value21)) & (value21 ^ (uint16_t)(((a_hi3 << 8) | a7) + value21)) & 0x8000) != 0;
                            } else {
                                BUS8_SET(c, (db << 0x10) + 0x0800 + value17, (uint8_t)(((a_hi3 << 8) | a7) + value21));
                                uint8_t a_hi7;
                                uint16_t y5;
                                if ((uint16_t)(((a_hi3 << 8) | a7) + value21) >> 8 == 0) {
                                    a_hi7 = (uint8_t)(((a_hi3 << 8) | a7) + value21);
                                    y5 = value17;
                                } else {
                                    uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                                    uint8_t value37 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value36);
                                    uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                                    BUS8_SET(c, (db << 0x10) + 0x0A00 + value36, value37 ^ value38);
                                    uint16_t value39 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                                    a_hi7 = 0;
                                    y5 = value39;
                                }
                                uint16_t value40 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                                BUS16_SET(c, (db << 0x10) + 0x0802 + y5, value40);
                                BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y5 + 4));
                                uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                                uint8_t a11;
                                if (!((uint8_t)(value41 << 1) & 0x80)) {
                                    a11 = (uint8_t)(value41 << 2);
                                } else {
                                    uint8_t value42 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                                    BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value42 + 1));
                                    a11 = 1;
                                }
                                BUS8_SET(c, (uint16_t)(dp + 0x59), a11);
                                m_flag2 = 1;
                                a12 = a11;
                                a_hi8 = (uint16_t)(y5 + 4) >> 8;
                                y6 = (uint16_t)(y5 + 4);
                                carry3 = (uint8_t)(value41 << 1) & 0x80;
                                overflow4 = ((y5 ^ (uint16_t)(y5 + 4)) & ((uint16_t)(y5 + 4) ^ 4) & 0x8000) != 0;
                            }
                            m_flag3 = m_flag2;
                            a13 = a12;
                            a_hi9 = a_hi8;
                            y7 = y6;
                            carry4 = carry3;
                            overflow5 = overflow4;
                        }
                        m_flag4 = m_flag3;
                        a14 = a13;
                        a_hi10 = a_hi9;
                        y8 = y7;
                        carry5 = carry4;
                        overflow6 = overflow5;
                    }
                    m_flag5 = m_flag4;
                    a15 = a14;
                    a_hi11 = a_hi10;
                    y9 = y8;
                    carry6 = carry5;
                    overflow7 = overflow6;
                }
                m_flag6 = m_flag5;
                a16 = a15;
                a_hi12 = a_hi11;
                y10 = y9;
                carry7 = carry6;
                overflow8 = overflow7;
            }
            uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp + 2));
            BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)(value43 - 1));
            if ((uint8_t)(value43 - 1) == 0) {
                a5 = a16;
                a_hi1 = a_hi12;
                y1 = y10;
                carry1 = carry7;
                zero1 = (uint8_t)(value43 - 1) == 0;
                negative1 = (uint8_t)(value43 - 1) & 0x80;
                overflow2 = overflow8;
                break;
            }
            uint8_t a5_next = a16;
            uint8_t a_hi1_next = a_hi12;
            uint16_t x1_next = (uint16_t)(x1 + 4);
            uint16_t y1_next = y10;
            bool carry1_next = carry7;
            bool zero1_next = (uint16_t)(x1 + 4) == 0;
            bool negative1_next = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next = overflow8;
            a5 = a5_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            zero1 = zero1_next;
            negative1 = negative1_next;
            overflow2 = overflow2_next;
            continue;
        }
        if ((uint16_t)(((a_hi2 << 8) | a6) + value19) < 0xE0) {
            BUS8_SET(c, (db << 0x10) + 0x0801 + value17, (uint8_t)(((a_hi2 << 8) | a6) + value19));
            uint8_t value44 = BUS8_RDP(c, (db << 0x10) + x1);
            uint8_t a17;
            uint8_t a_hi13;
            if (!(value44 & 0x80)) {
                a17 = value44;
                a_hi13 = 0;
            } else {
                a17 = (uint8_t)(value44 | 0xFF00);
                a_hi13 = (value44 | 0xFF00) >> 8;
            }
            uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp + 4));
            bool m_flag11;
            uint8_t a25;
            uint8_t a_hi21;
            uint16_t y18;
            bool carry12;
            bool overflow13;
            if ((uint16_t)(((a_hi13 << 8) | a17) + value45) & 0x8000) {
                bool m_flag7;
                uint8_t a19;
                uint8_t a_hi15;
                uint16_t y12;
                bool carry8;
                bool overflow9;
                if ((uint16_t)(((a_hi13 << 8) | a17) + value45) < 0xFFF0) {
                    m_flag7 = 0;
                    a19 = (uint8_t)(((a_hi13 << 8) | a17) + value45);
                    a_hi15 = (uint16_t)(((a_hi13 << 8) | a17) + value45) >> 8;
                    y12 = value17;
                    carry8 = (uint16_t)(((a_hi13 << 8) | a17) + value45) >= 0xFFF0;
                    overflow9 = ((((a_hi13 << 8) | a17) ^ (uint16_t)(((a_hi13 << 8) | a17) + value45)) & (value45 ^ (uint16_t)(((a_hi13 << 8) | a17) + value45)) & 0x8000) != 0;
                } else {
                    BUS8_SET(c, (db << 0x10) + 0x0800 + value17, (uint8_t)(((a_hi13 << 8) | a17) + value45));
                    uint8_t a_hi14;
                    uint16_t y11;
                    if ((uint16_t)(((a_hi13 << 8) | a17) + value45) >> 8 == 0) {
                        a_hi14 = (uint8_t)(((a_hi13 << 8) | a17) + value45);
                        y11 = value17;
                    } else {
                        uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                        uint8_t value47 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value46);
                        uint8_t value48 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                        BUS8_SET(c, (db << 0x10) + 0x0A00 + value46, value47 ^ value48);
                        uint16_t value49 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                        a_hi14 = 0;
                        y11 = value49;
                    }
                    uint16_t value50 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                    BUS16_SET(c, (db << 0x10) + 0x0802 + y11, value50);
                    BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y11 + 4));
                    uint8_t value51 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                    uint8_t a18;
                    if (!((uint8_t)(value51 << 1) & 0x80)) {
                        a18 = (uint8_t)(value51 << 2);
                    } else {
                        uint8_t value52 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                        BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value52 + 1));
                        a18 = 1;
                    }
                    BUS8_SET(c, (uint16_t)(dp + 0x59), a18);
                    m_flag7 = 1;
                    a19 = a18;
                    a_hi15 = (uint16_t)(y11 + 4) >> 8;
                    y12 = (uint16_t)(y11 + 4);
                    carry8 = (uint8_t)(value51 << 1) & 0x80;
                    overflow9 = ((y11 ^ (uint16_t)(y11 + 4)) & ((uint16_t)(y11 + 4) ^ 4) & 0x8000) != 0;
                }
                m_flag11 = m_flag7;
                a25 = a19;
                a_hi21 = a_hi15;
                y18 = y12;
                carry12 = carry8;
                overflow13 = overflow9;
            } else {
                bool m_flag10;
                uint8_t a24;
                uint8_t a_hi20;
                uint16_t y17;
                bool carry11;
                bool overflow12;
                if ((uint16_t)(((a_hi13 << 8) | a17) + value45) < 0x0100) {
                    BUS8_SET(c, (db << 0x10) + 0x0800 + value17, (uint8_t)(((a_hi13 << 8) | a17) + value45));
                    uint8_t a_hi16;
                    uint16_t y13;
                    if ((uint16_t)(((a_hi13 << 8) | a17) + value45) >> 8 == 0) {
                        a_hi16 = (uint8_t)(((a_hi13 << 8) | a17) + value45);
                        y13 = value17;
                    } else {
                        uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                        uint8_t value54 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value53);
                        uint8_t value55 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                        BUS8_SET(c, (db << 0x10) + 0x0A00 + value53, value54 ^ value55);
                        uint16_t value56 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                        a_hi16 = 0;
                        y13 = value56;
                    }
                    uint16_t value57 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                    BUS16_SET(c, (db << 0x10) + 0x0802 + y13, value57);
                    BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y13 + 4));
                    uint8_t value58 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                    uint8_t a20;
                    if (!((uint8_t)(value58 << 1) & 0x80)) {
                        a20 = (uint8_t)(value58 << 2);
                    } else {
                        uint8_t value59 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                        BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value59 + 1));
                        a20 = 1;
                    }
                    BUS8_SET(c, (uint16_t)(dp + 0x59), a20);
                    m_flag10 = 1;
                    a24 = a20;
                    a_hi20 = (uint16_t)(y13 + 4) >> 8;
                    y17 = (uint16_t)(y13 + 4);
                    carry11 = (uint8_t)(value58 << 1) & 0x80;
                    overflow12 = ((y13 ^ (uint16_t)(y13 + 4)) & ((uint16_t)(y13 + 4) ^ 4) & 0x8000) != 0;
                } else {
                    bool m_flag9;
                    uint8_t a23;
                    uint8_t a_hi19;
                    uint16_t y16;
                    bool carry10;
                    bool overflow11;
                    if ((uint16_t)(((a_hi13 << 8) | a17) + value45) >= 0x0100) {
                        m_flag9 = 0;
                        a23 = (uint8_t)(((a_hi13 << 8) | a17) + value45);
                        a_hi19 = (uint16_t)(((a_hi13 << 8) | a17) + value45) >> 8;
                        y16 = value17;
                        carry10 = (uint16_t)(((a_hi13 << 8) | a17) + value45) >= 0x0100;
                        overflow11 = ((((a_hi13 << 8) | a17) ^ (uint16_t)(((a_hi13 << 8) | a17) + value45)) & (value45 ^ (uint16_t)(((a_hi13 << 8) | a17) + value45)) & 0x8000) != 0;
                    } else {
                        bool m_flag8;
                        uint8_t a22;
                        uint8_t a_hi18;
                        uint16_t y15;
                        bool carry9;
                        bool overflow10;
                        if ((uint16_t)(((a_hi13 << 8) | a17) + value45) < 0xFFF0) {
                            m_flag8 = 0;
                            a22 = (uint8_t)(((a_hi13 << 8) | a17) + value45);
                            a_hi18 = (uint16_t)(((a_hi13 << 8) | a17) + value45) >> 8;
                            y15 = value17;
                            carry9 = (uint16_t)(((a_hi13 << 8) | a17) + value45) >= 0xFFF0;
                            overflow10 = ((((a_hi13 << 8) | a17) ^ (uint16_t)(((a_hi13 << 8) | a17) + value45)) & (value45 ^ (uint16_t)(((a_hi13 << 8) | a17) + value45)) & 0x8000) != 0;
                        } else {
                            BUS8_SET(c, (db << 0x10) + 0x0800 + value17, (uint8_t)(((a_hi13 << 8) | a17) + value45));
                            uint8_t a_hi17;
                            uint16_t y14;
                            if ((uint16_t)(((a_hi13 << 8) | a17) + value45) >> 8 == 0) {
                                a_hi17 = (uint8_t)(((a_hi13 << 8) | a17) + value45);
                                y14 = value17;
                            } else {
                                uint8_t value60 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                                uint8_t value61 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value60);
                                uint8_t value62 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                                BUS8_SET(c, (db << 0x10) + 0x0A00 + value60, value61 ^ value62);
                                uint16_t value63 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                                a_hi17 = 0;
                                y14 = value63;
                            }
                            uint16_t value64 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                            BUS16_SET(c, (db << 0x10) + 0x0802 + y14, value64);
                            BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y14 + 4));
                            uint8_t value65 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                            uint8_t a21;
                            if (!((uint8_t)(value65 << 1) & 0x80)) {
                                a21 = (uint8_t)(value65 << 2);
                            } else {
                                uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                                BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value66 + 1));
                                a21 = 1;
                            }
                            BUS8_SET(c, (uint16_t)(dp + 0x59), a21);
                            m_flag8 = 1;
                            a22 = a21;
                            a_hi18 = (uint16_t)(y14 + 4) >> 8;
                            y15 = (uint16_t)(y14 + 4);
                            carry9 = (uint8_t)(value65 << 1) & 0x80;
                            overflow10 = ((y14 ^ (uint16_t)(y14 + 4)) & ((uint16_t)(y14 + 4) ^ 4) & 0x8000) != 0;
                        }
                        m_flag9 = m_flag8;
                        a23 = a22;
                        a_hi19 = a_hi18;
                        y16 = y15;
                        carry10 = carry9;
                        overflow11 = overflow10;
                    }
                    m_flag10 = m_flag9;
                    a24 = a23;
                    a_hi20 = a_hi19;
                    y17 = y16;
                    carry11 = carry10;
                    overflow12 = overflow11;
                }
                m_flag11 = m_flag10;
                a25 = a24;
                a_hi21 = a_hi20;
                y18 = y17;
                carry12 = carry11;
                overflow13 = overflow12;
            }
            uint8_t value67 = BUS8_RDP(c, (uint16_t)(dp + 2));
            BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)(value67 - 1));
            if ((uint8_t)(value67 - 1) == 0) {
                a5 = a25;
                a_hi1 = a_hi21;
                y1 = y18;
                carry1 = carry12;
                zero1 = (uint8_t)(value67 - 1) == 0;
                negative1 = (uint8_t)(value67 - 1) & 0x80;
                overflow2 = overflow13;
                break;
            }
            uint8_t a5_next2 = a25;
            uint8_t a_hi1_next2 = a_hi21;
            uint16_t x1_next2 = (uint16_t)(x1 + 4);
            uint16_t y1_next2 = y18;
            bool carry1_next2 = carry12;
            bool zero1_next2 = (uint16_t)(x1 + 4) == 0;
            bool negative1_next2 = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next2 = overflow13;
            a5 = a5_next2;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            y1 = y1_next2;
            carry1 = carry1_next2;
            zero1 = zero1_next2;
            negative1 = negative1_next2;
            overflow2 = overflow2_next2;
            continue;
        }
        if ((uint16_t)(((a_hi2 << 8) | a6) + value19) >= 0xE0) {
            uint8_t value68 = BUS8_RDP(c, (uint16_t)(dp + 2));
            BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)(value68 - 1));
            if ((uint8_t)(value68 - 1) == 0) {
                a5 = (uint8_t)(((a_hi2 << 8) | a6) + value19);
                a_hi1 = (uint16_t)(((a_hi2 << 8) | a6) + value19) >> 8;
                y1 = value17;
                carry1 = (uint16_t)(((a_hi2 << 8) | a6) + value19) >= 0xE0;
                zero1 = (uint8_t)(value68 - 1) == 0;
                negative1 = (uint8_t)(value68 - 1) & 0x80;
                overflow2 = ((((a_hi2 << 8) | a6) ^ (uint16_t)(((a_hi2 << 8) | a6) + value19)) & (value19 ^ (uint16_t)(((a_hi2 << 8) | a6) + value19)) & 0x8000) != 0;
                break;
            }
            uint8_t a5_next3 = (uint8_t)(((a_hi2 << 8) | a6) + value19);
            uint8_t a_hi1_next3 = (uint16_t)(((a_hi2 << 8) | a6) + value19) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 + 4);
            uint16_t y1_next3 = value17;
            bool carry1_next3 = (uint16_t)(((a_hi2 << 8) | a6) + value19) >= 0xE0;
            bool zero1_next3 = (uint16_t)(x1 + 4) == 0;
            bool negative1_next3 = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next3 = ((((a_hi2 << 8) | a6) ^ (uint16_t)(((a_hi2 << 8) | a6) + value19)) & (value19 ^ (uint16_t)(((a_hi2 << 8) | a6) + value19)) & 0x8000) != 0;
            a5 = a5_next3;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            y1 = y1_next3;
            carry1 = carry1_next3;
            zero1 = zero1_next3;
            negative1 = negative1_next3;
            overflow2 = overflow2_next3;
            continue;
        }
        r->a = (uint16_t)(((a_hi2 << 8) | a6) + value19);
        r->x = x1;
        r->y = value17;
        r->c = (uint16_t)(((a_hi2 << 8) | a6) + value19) >= 0xE0;
        r->z = (uint16_t)(((a_hi2 << 8) | a6) + value19) == 0xE0;
        r->n = (uint16_t)((uint16_t)(((a_hi2 << 8) | a6) + value19) - 0xE0) & 0x8000;
        r->v = ((((a_hi2 << 8) | a6) ^ (uint16_t)(((a_hi2 << 8) | a6) + value19)) & (value19 ^ (uint16_t)(((a_hi2 << 8) | a6) + value19)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = db;
        r->dp = dp;
        RETURN_RTS(c);
    }
    r->a = (a_hi1 << 8) | a5;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
    shared_E5DF_1:;
    r->a = (a_hi_e5df2 << 8) | a_e5df2;
    r->x = x_e5df2;
    r->y = y_e5df2;
    r->c = carry_e5df2;
    r->z = zero_e5df2;
    r->n = negative_e5df2;
    r->v = overflow_e5df2;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
}

/* C0E5F5 sub_C0E5F5   [class A, 218 bytes, 110 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void sub_C0E5F5(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0xE020 + value);
    BUS16_SET(c, (uint16_t)(dp + 4), value2);
    uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0xE074 + value);
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0xE045 + value);
    uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0xE022 + value);
    BUS16_SET(c, (uint16_t)(dp + 6), (uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5 + 1));
    uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0xE00D + value);
    uint8_t a4;
    bool overflow1;
    if (value6 == 0) {
        a4 = value6;
        overflow1 = (((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5 + 1)) & (value5 ^ (uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5 + 1)) & 0x8000) != 0;
    } else {
        BUS8_SET(c, (db << 0x10) + 0xE00D + value, (uint8_t)(value6 - 0x10));
        uint8_t a3;
        if (value6 >= 0x10) {
            uint8_t a1;
            if (!((uint8_t)(value6 - 0x10) & 0x01)) {
                a1 = (uint8_t)(value6 - 0x10) >> 1;
            } else {
                RAM8(0x0000 + sp0) = (uint8_t)(value6 - 0x10) >> 1;
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 4));
                BUS8_SET(c, (uint16_t)(dp + 4), ((value7 & 1) << 1) ^ value8);
                a1 = RAM8(0x0000 + sp0);
            }
            uint8_t a2;
            if (!(a1 & 0x01)) {
                a2 = a1 >> 1;
            } else {
                uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 6));
                BUS8_SET(c, (uint16_t)(dp + 6), ((value10 & 1) << 1) ^ value11);
                a2 = ((value10 & 1) << 1) ^ value11;
            }
            a3 = a2;
        } else {
            BUS8_SET(c, (db << 0x10) + 0xE00D + value, 0);
            a3 = 0;
        }
        a4 = a3;
        overflow1 = ((value6 ^ 0x10) & (value6 ^ (uint8_t)(value6 - 0x10)) & 0x80) != 0;
    }
    uint8_t a5 = a4;
    uint8_t a_hi1 = (uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5 + 1) >> 8;
    uint16_t x1 = y;
    uint16_t y1 = y;
    bool carry1 = 0;
    bool zero1 = y == 0;
    bool negative1 = y & 0x8000;
    bool overflow2 = overflow1;
    for (;;) {
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
        if (value12 >= 0x0200) {
            r->a = (a_hi1 << 8) | a5;
            r->x = x1;
            r->y = value12;
            r->c = value12 >= 0x0200;
            r->z = value12 == 0x0200;
            r->n = (uint16_t)(value12 - 0x0200) & 0x8000;
            r->v = overflow2;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value13 = BUS8_RDP(c, (db << 0x10) + 1 + x1);
        uint8_t a6;
        uint8_t a_hi2;
        if (!(value13 & 0x80)) {
            a6 = value13;
            a_hi2 = 0;
        } else {
            a6 = (uint8_t)(value13 | 0xFF00);
            a_hi2 = (value13 | 0xFF00) >> 8;
        }
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp + 6));
        if ((uint16_t)(((a_hi2 << 8) | a6) + value14) & 0x8000) {
            bool m_flag6;
            uint8_t a16;
            uint8_t a_hi12;
            uint16_t y10;
            bool carry7;
            bool overflow8;
            if ((uint16_t)(((a_hi2 << 8) | a6) + value14) < 0xFFF0) {
                m_flag6 = 0;
                a16 = (uint8_t)(((a_hi2 << 8) | a6) + value14);
                a_hi12 = (uint16_t)(((a_hi2 << 8) | a6) + value14) >> 8;
                y10 = value12;
                carry7 = (uint16_t)(((a_hi2 << 8) | a6) + value14) >= 0xFFF0;
                overflow8 = ((((a_hi2 << 8) | a6) ^ (uint16_t)(((a_hi2 << 8) | a6) + value14)) & (value14 ^ (uint16_t)(((a_hi2 << 8) | a6) + value14)) & 0x8000) != 0;
            } else {
                BUS8_SET(c, (db << 0x10) + 0x0801 + value12, (uint8_t)(((a_hi2 << 8) | a6) + value14));
                uint8_t value15 = BUS8_RDP(c, (db << 0x10) + x1);
                uint8_t a7;
                uint8_t a_hi3;
                if (!(value15 & 0x80)) {
                    a7 = value15;
                    a_hi3 = 0;
                } else {
                    a7 = (uint8_t)(value15 | 0xFF00);
                    a_hi3 = (value15 | 0xFF00) >> 8;
                }
                uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp + 4));
                bool m_flag5;
                uint8_t a15;
                uint8_t a_hi11;
                uint16_t y9;
                bool carry6;
                bool overflow7;
                if ((uint16_t)(((a_hi3 << 8) | a7) + value16) & 0x8000) {
                    bool m_flag;
                    uint8_t a9;
                    uint8_t a_hi5;
                    uint16_t y3;
                    bool carry2;
                    bool overflow3;
                    if ((uint16_t)(((a_hi3 << 8) | a7) + value16) < 0xFFF0) {
                        m_flag = 0;
                        a9 = (uint8_t)(((a_hi3 << 8) | a7) + value16);
                        a_hi5 = (uint16_t)(((a_hi3 << 8) | a7) + value16) >> 8;
                        y3 = value12;
                        carry2 = (uint16_t)(((a_hi3 << 8) | a7) + value16) >= 0xFFF0;
                        overflow3 = ((((a_hi3 << 8) | a7) ^ (uint16_t)(((a_hi3 << 8) | a7) + value16)) & (value16 ^ (uint16_t)(((a_hi3 << 8) | a7) + value16)) & 0x8000) != 0;
                    } else {
                        BUS8_SET(c, (db << 0x10) + 0x0800 + value12, (uint8_t)(((a_hi3 << 8) | a7) + value16));
                        uint8_t a_hi4;
                        uint16_t y2;
                        if ((uint16_t)(((a_hi3 << 8) | a7) + value16) >> 8 == 0) {
                            a_hi4 = (uint8_t)(((a_hi3 << 8) | a7) + value16);
                            y2 = value12;
                        } else {
                            uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                            uint8_t value18 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value17);
                            uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                            BUS8_SET(c, (db << 0x10) + 0x0A00 + value17, value18 ^ value19);
                            uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                            a_hi4 = 0;
                            y2 = value20;
                        }
                        uint16_t value21 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                        BUS16_SET(c, (db << 0x10) + 0x0802 + y2, value21);
                        BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y2 + 4));
                        uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                        uint8_t a8;
                        if (!((uint8_t)(value22 << 1) & 0x80)) {
                            a8 = (uint8_t)(value22 << 2);
                        } else {
                            uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                            BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value23 + 1));
                            a8 = 1;
                        }
                        BUS8_SET(c, (uint16_t)(dp + 0x59), a8);
                        m_flag = 1;
                        a9 = a8;
                        a_hi5 = (uint16_t)(y2 + 4) >> 8;
                        y3 = (uint16_t)(y2 + 4);
                        carry2 = (uint8_t)(value22 << 1) & 0x80;
                        overflow3 = ((y2 ^ (uint16_t)(y2 + 4)) & ((uint16_t)(y2 + 4) ^ 4) & 0x8000) != 0;
                    }
                    m_flag5 = m_flag;
                    a15 = a9;
                    a_hi11 = a_hi5;
                    y9 = y3;
                    carry6 = carry2;
                    overflow7 = overflow3;
                } else {
                    bool m_flag4;
                    uint8_t a14;
                    uint8_t a_hi10;
                    uint16_t y8;
                    bool carry5;
                    bool overflow6;
                    if ((uint16_t)(((a_hi3 << 8) | a7) + value16) < 0x0100) {
                        BUS8_SET(c, (db << 0x10) + 0x0800 + value12, (uint8_t)(((a_hi3 << 8) | a7) + value16));
                        uint8_t a_hi6;
                        uint16_t y4;
                        if ((uint16_t)(((a_hi3 << 8) | a7) + value16) >> 8 == 0) {
                            a_hi6 = (uint8_t)(((a_hi3 << 8) | a7) + value16);
                            y4 = value12;
                        } else {
                            uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                            uint8_t value25 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value24);
                            uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                            BUS8_SET(c, (db << 0x10) + 0x0A00 + value24, value25 ^ value26);
                            uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                            a_hi6 = 0;
                            y4 = value27;
                        }
                        uint16_t value28 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                        BUS16_SET(c, (db << 0x10) + 0x0802 + y4, value28);
                        BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y4 + 4));
                        uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                        uint8_t a10;
                        if (!((uint8_t)(value29 << 1) & 0x80)) {
                            a10 = (uint8_t)(value29 << 2);
                        } else {
                            uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                            BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value30 + 1));
                            a10 = 1;
                        }
                        BUS8_SET(c, (uint16_t)(dp + 0x59), a10);
                        m_flag4 = 1;
                        a14 = a10;
                        a_hi10 = (uint16_t)(y4 + 4) >> 8;
                        y8 = (uint16_t)(y4 + 4);
                        carry5 = (uint8_t)(value29 << 1) & 0x80;
                        overflow6 = ((y4 ^ (uint16_t)(y4 + 4)) & ((uint16_t)(y4 + 4) ^ 4) & 0x8000) != 0;
                    } else {
                        bool m_flag3;
                        uint8_t a13;
                        uint8_t a_hi9;
                        uint16_t y7;
                        bool carry4;
                        bool overflow5;
                        if ((uint16_t)(((a_hi3 << 8) | a7) + value16) >= 0x0100) {
                            m_flag3 = 0;
                            a13 = (uint8_t)(((a_hi3 << 8) | a7) + value16);
                            a_hi9 = (uint16_t)(((a_hi3 << 8) | a7) + value16) >> 8;
                            y7 = value12;
                            carry4 = (uint16_t)(((a_hi3 << 8) | a7) + value16) >= 0x0100;
                            overflow5 = ((((a_hi3 << 8) | a7) ^ (uint16_t)(((a_hi3 << 8) | a7) + value16)) & (value16 ^ (uint16_t)(((a_hi3 << 8) | a7) + value16)) & 0x8000) != 0;
                        } else {
                            bool m_flag2;
                            uint8_t a12;
                            uint8_t a_hi8;
                            uint16_t y6;
                            bool carry3;
                            bool overflow4;
                            if ((uint16_t)(((a_hi3 << 8) | a7) + value16) < 0xFFF0) {
                                m_flag2 = 0;
                                a12 = (uint8_t)(((a_hi3 << 8) | a7) + value16);
                                a_hi8 = (uint16_t)(((a_hi3 << 8) | a7) + value16) >> 8;
                                y6 = value12;
                                carry3 = (uint16_t)(((a_hi3 << 8) | a7) + value16) >= 0xFFF0;
                                overflow4 = ((((a_hi3 << 8) | a7) ^ (uint16_t)(((a_hi3 << 8) | a7) + value16)) & (value16 ^ (uint16_t)(((a_hi3 << 8) | a7) + value16)) & 0x8000) != 0;
                            } else {
                                BUS8_SET(c, (db << 0x10) + 0x0800 + value12, (uint8_t)(((a_hi3 << 8) | a7) + value16));
                                uint8_t a_hi7;
                                uint16_t y5;
                                if ((uint16_t)(((a_hi3 << 8) | a7) + value16) >> 8 == 0) {
                                    a_hi7 = (uint8_t)(((a_hi3 << 8) | a7) + value16);
                                    y5 = value12;
                                } else {
                                    uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                                    uint8_t value32 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value31);
                                    uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                                    BUS8_SET(c, (db << 0x10) + 0x0A00 + value31, value32 ^ value33);
                                    uint16_t value34 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                                    a_hi7 = 0;
                                    y5 = value34;
                                }
                                uint16_t value35 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                                BUS16_SET(c, (db << 0x10) + 0x0802 + y5, value35);
                                BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y5 + 4));
                                uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                                uint8_t a11;
                                if (!((uint8_t)(value36 << 1) & 0x80)) {
                                    a11 = (uint8_t)(value36 << 2);
                                } else {
                                    uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                                    BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value37 + 1));
                                    a11 = 1;
                                }
                                BUS8_SET(c, (uint16_t)(dp + 0x59), a11);
                                m_flag2 = 1;
                                a12 = a11;
                                a_hi8 = (uint16_t)(y5 + 4) >> 8;
                                y6 = (uint16_t)(y5 + 4);
                                carry3 = (uint8_t)(value36 << 1) & 0x80;
                                overflow4 = ((y5 ^ (uint16_t)(y5 + 4)) & ((uint16_t)(y5 + 4) ^ 4) & 0x8000) != 0;
                            }
                            m_flag3 = m_flag2;
                            a13 = a12;
                            a_hi9 = a_hi8;
                            y7 = y6;
                            carry4 = carry3;
                            overflow5 = overflow4;
                        }
                        m_flag4 = m_flag3;
                        a14 = a13;
                        a_hi10 = a_hi9;
                        y8 = y7;
                        carry5 = carry4;
                        overflow6 = overflow5;
                    }
                    m_flag5 = m_flag4;
                    a15 = a14;
                    a_hi11 = a_hi10;
                    y9 = y8;
                    carry6 = carry5;
                    overflow7 = overflow6;
                }
                m_flag6 = m_flag5;
                a16 = a15;
                a_hi12 = a_hi11;
                y10 = y9;
                carry7 = carry6;
                overflow8 = overflow7;
            }
            uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp + 2));
            BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)(value38 - 1));
            if ((uint8_t)(value38 - 1) == 0) {
                a5 = a16;
                a_hi1 = a_hi12;
                y1 = y10;
                carry1 = carry7;
                zero1 = (uint8_t)(value38 - 1) == 0;
                negative1 = (uint8_t)(value38 - 1) & 0x80;
                overflow2 = overflow8;
                break;
            }
            uint8_t a5_next = a16;
            uint8_t a_hi1_next = a_hi12;
            uint16_t x1_next = (uint16_t)(x1 + 4);
            uint16_t y1_next = y10;
            bool carry1_next = carry7;
            bool zero1_next = (uint16_t)(x1 + 4) == 0;
            bool negative1_next = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next = overflow8;
            a5 = a5_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            zero1 = zero1_next;
            negative1 = negative1_next;
            overflow2 = overflow2_next;
            continue;
        }
        if ((uint16_t)(((a_hi2 << 8) | a6) + value14) < 0xE0) {
            BUS8_SET(c, (db << 0x10) + 0x0801 + value12, (uint8_t)(((a_hi2 << 8) | a6) + value14));
            uint8_t value39 = BUS8_RDP(c, (db << 0x10) + x1);
            uint8_t a17;
            uint8_t a_hi13;
            if (!(value39 & 0x80)) {
                a17 = value39;
                a_hi13 = 0;
            } else {
                a17 = (uint8_t)(value39 | 0xFF00);
                a_hi13 = (value39 | 0xFF00) >> 8;
            }
            uint16_t value40 = BUS16_RDP(c, (uint16_t)(dp + 4));
            bool m_flag11;
            uint8_t a25;
            uint8_t a_hi21;
            uint16_t y18;
            bool carry12;
            bool overflow13;
            if ((uint16_t)(((a_hi13 << 8) | a17) + value40) & 0x8000) {
                bool m_flag7;
                uint8_t a19;
                uint8_t a_hi15;
                uint16_t y12;
                bool carry8;
                bool overflow9;
                if ((uint16_t)(((a_hi13 << 8) | a17) + value40) < 0xFFF0) {
                    m_flag7 = 0;
                    a19 = (uint8_t)(((a_hi13 << 8) | a17) + value40);
                    a_hi15 = (uint16_t)(((a_hi13 << 8) | a17) + value40) >> 8;
                    y12 = value12;
                    carry8 = (uint16_t)(((a_hi13 << 8) | a17) + value40) >= 0xFFF0;
                    overflow9 = ((((a_hi13 << 8) | a17) ^ (uint16_t)(((a_hi13 << 8) | a17) + value40)) & (value40 ^ (uint16_t)(((a_hi13 << 8) | a17) + value40)) & 0x8000) != 0;
                } else {
                    BUS8_SET(c, (db << 0x10) + 0x0800 + value12, (uint8_t)(((a_hi13 << 8) | a17) + value40));
                    uint8_t a_hi14;
                    uint16_t y11;
                    if ((uint16_t)(((a_hi13 << 8) | a17) + value40) >> 8 == 0) {
                        a_hi14 = (uint8_t)(((a_hi13 << 8) | a17) + value40);
                        y11 = value12;
                    } else {
                        uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                        uint8_t value42 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value41);
                        uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                        BUS8_SET(c, (db << 0x10) + 0x0A00 + value41, value42 ^ value43);
                        uint16_t value44 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                        a_hi14 = 0;
                        y11 = value44;
                    }
                    uint16_t value45 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                    BUS16_SET(c, (db << 0x10) + 0x0802 + y11, value45);
                    BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y11 + 4));
                    uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                    uint8_t a18;
                    if (!((uint8_t)(value46 << 1) & 0x80)) {
                        a18 = (uint8_t)(value46 << 2);
                    } else {
                        uint8_t value47 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                        BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value47 + 1));
                        a18 = 1;
                    }
                    BUS8_SET(c, (uint16_t)(dp + 0x59), a18);
                    m_flag7 = 1;
                    a19 = a18;
                    a_hi15 = (uint16_t)(y11 + 4) >> 8;
                    y12 = (uint16_t)(y11 + 4);
                    carry8 = (uint8_t)(value46 << 1) & 0x80;
                    overflow9 = ((y11 ^ (uint16_t)(y11 + 4)) & ((uint16_t)(y11 + 4) ^ 4) & 0x8000) != 0;
                }
                m_flag11 = m_flag7;
                a25 = a19;
                a_hi21 = a_hi15;
                y18 = y12;
                carry12 = carry8;
                overflow13 = overflow9;
            } else {
                bool m_flag10;
                uint8_t a24;
                uint8_t a_hi20;
                uint16_t y17;
                bool carry11;
                bool overflow12;
                if ((uint16_t)(((a_hi13 << 8) | a17) + value40) < 0x0100) {
                    BUS8_SET(c, (db << 0x10) + 0x0800 + value12, (uint8_t)(((a_hi13 << 8) | a17) + value40));
                    uint8_t a_hi16;
                    uint16_t y13;
                    if ((uint16_t)(((a_hi13 << 8) | a17) + value40) >> 8 == 0) {
                        a_hi16 = (uint8_t)(((a_hi13 << 8) | a17) + value40);
                        y13 = value12;
                    } else {
                        uint8_t value48 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                        uint8_t value49 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value48);
                        uint8_t value50 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                        BUS8_SET(c, (db << 0x10) + 0x0A00 + value48, value49 ^ value50);
                        uint16_t value51 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                        a_hi16 = 0;
                        y13 = value51;
                    }
                    uint16_t value52 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                    BUS16_SET(c, (db << 0x10) + 0x0802 + y13, value52);
                    BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y13 + 4));
                    uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                    uint8_t a20;
                    if (!((uint8_t)(value53 << 1) & 0x80)) {
                        a20 = (uint8_t)(value53 << 2);
                    } else {
                        uint8_t value54 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                        BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value54 + 1));
                        a20 = 1;
                    }
                    BUS8_SET(c, (uint16_t)(dp + 0x59), a20);
                    m_flag10 = 1;
                    a24 = a20;
                    a_hi20 = (uint16_t)(y13 + 4) >> 8;
                    y17 = (uint16_t)(y13 + 4);
                    carry11 = (uint8_t)(value53 << 1) & 0x80;
                    overflow12 = ((y13 ^ (uint16_t)(y13 + 4)) & ((uint16_t)(y13 + 4) ^ 4) & 0x8000) != 0;
                } else {
                    bool m_flag9;
                    uint8_t a23;
                    uint8_t a_hi19;
                    uint16_t y16;
                    bool carry10;
                    bool overflow11;
                    if ((uint16_t)(((a_hi13 << 8) | a17) + value40) >= 0x0100) {
                        m_flag9 = 0;
                        a23 = (uint8_t)(((a_hi13 << 8) | a17) + value40);
                        a_hi19 = (uint16_t)(((a_hi13 << 8) | a17) + value40) >> 8;
                        y16 = value12;
                        carry10 = (uint16_t)(((a_hi13 << 8) | a17) + value40) >= 0x0100;
                        overflow11 = ((((a_hi13 << 8) | a17) ^ (uint16_t)(((a_hi13 << 8) | a17) + value40)) & (value40 ^ (uint16_t)(((a_hi13 << 8) | a17) + value40)) & 0x8000) != 0;
                    } else {
                        bool m_flag8;
                        uint8_t a22;
                        uint8_t a_hi18;
                        uint16_t y15;
                        bool carry9;
                        bool overflow10;
                        if ((uint16_t)(((a_hi13 << 8) | a17) + value40) < 0xFFF0) {
                            m_flag8 = 0;
                            a22 = (uint8_t)(((a_hi13 << 8) | a17) + value40);
                            a_hi18 = (uint16_t)(((a_hi13 << 8) | a17) + value40) >> 8;
                            y15 = value12;
                            carry9 = (uint16_t)(((a_hi13 << 8) | a17) + value40) >= 0xFFF0;
                            overflow10 = ((((a_hi13 << 8) | a17) ^ (uint16_t)(((a_hi13 << 8) | a17) + value40)) & (value40 ^ (uint16_t)(((a_hi13 << 8) | a17) + value40)) & 0x8000) != 0;
                        } else {
                            BUS8_SET(c, (db << 0x10) + 0x0800 + value12, (uint8_t)(((a_hi13 << 8) | a17) + value40));
                            uint8_t a_hi17;
                            uint16_t y14;
                            if ((uint16_t)(((a_hi13 << 8) | a17) + value40) >> 8 == 0) {
                                a_hi17 = (uint8_t)(((a_hi13 << 8) | a17) + value40);
                                y14 = value12;
                            } else {
                                uint8_t value55 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                                uint8_t value56 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value55);
                                uint8_t value57 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                                BUS8_SET(c, (db << 0x10) + 0x0A00 + value55, value56 ^ value57);
                                uint16_t value58 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
                                a_hi17 = 0;
                                y14 = value58;
                            }
                            uint16_t value59 = BUS16_RDP(c, (db << 0x10) + 2 + x1);
                            BUS16_SET(c, (db << 0x10) + 0x0802 + y14, value59);
                            BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y14 + 4));
                            uint8_t value60 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
                            uint8_t a21;
                            if (!((uint8_t)(value60 << 1) & 0x80)) {
                                a21 = (uint8_t)(value60 << 2);
                            } else {
                                uint8_t value61 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
                                BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value61 + 1));
                                a21 = 1;
                            }
                            BUS8_SET(c, (uint16_t)(dp + 0x59), a21);
                            m_flag8 = 1;
                            a22 = a21;
                            a_hi18 = (uint16_t)(y14 + 4) >> 8;
                            y15 = (uint16_t)(y14 + 4);
                            carry9 = (uint8_t)(value60 << 1) & 0x80;
                            overflow10 = ((y14 ^ (uint16_t)(y14 + 4)) & ((uint16_t)(y14 + 4) ^ 4) & 0x8000) != 0;
                        }
                        m_flag9 = m_flag8;
                        a23 = a22;
                        a_hi19 = a_hi18;
                        y16 = y15;
                        carry10 = carry9;
                        overflow11 = overflow10;
                    }
                    m_flag10 = m_flag9;
                    a24 = a23;
                    a_hi20 = a_hi19;
                    y17 = y16;
                    carry11 = carry10;
                    overflow12 = overflow11;
                }
                m_flag11 = m_flag10;
                a25 = a24;
                a_hi21 = a_hi20;
                y18 = y17;
                carry12 = carry11;
                overflow13 = overflow12;
            }
            uint8_t value62 = BUS8_RDP(c, (uint16_t)(dp + 2));
            BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)(value62 - 1));
            if ((uint8_t)(value62 - 1) == 0) {
                a5 = a25;
                a_hi1 = a_hi21;
                y1 = y18;
                carry1 = carry12;
                zero1 = (uint8_t)(value62 - 1) == 0;
                negative1 = (uint8_t)(value62 - 1) & 0x80;
                overflow2 = overflow13;
                break;
            }
            uint8_t a5_next2 = a25;
            uint8_t a_hi1_next2 = a_hi21;
            uint16_t x1_next2 = (uint16_t)(x1 + 4);
            uint16_t y1_next2 = y18;
            bool carry1_next2 = carry12;
            bool zero1_next2 = (uint16_t)(x1 + 4) == 0;
            bool negative1_next2 = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next2 = overflow13;
            a5 = a5_next2;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            y1 = y1_next2;
            carry1 = carry1_next2;
            zero1 = zero1_next2;
            negative1 = negative1_next2;
            overflow2 = overflow2_next2;
            continue;
        }
        if ((uint16_t)(((a_hi2 << 8) | a6) + value14) >= 0xE0) {
            uint8_t value63 = BUS8_RDP(c, (uint16_t)(dp + 2));
            BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)(value63 - 1));
            if ((uint8_t)(value63 - 1) == 0) {
                a5 = (uint8_t)(((a_hi2 << 8) | a6) + value14);
                a_hi1 = (uint16_t)(((a_hi2 << 8) | a6) + value14) >> 8;
                y1 = value12;
                carry1 = (uint16_t)(((a_hi2 << 8) | a6) + value14) >= 0xE0;
                zero1 = (uint8_t)(value63 - 1) == 0;
                negative1 = (uint8_t)(value63 - 1) & 0x80;
                overflow2 = ((((a_hi2 << 8) | a6) ^ (uint16_t)(((a_hi2 << 8) | a6) + value14)) & (value14 ^ (uint16_t)(((a_hi2 << 8) | a6) + value14)) & 0x8000) != 0;
                break;
            }
            uint8_t a5_next3 = (uint8_t)(((a_hi2 << 8) | a6) + value14);
            uint8_t a_hi1_next3 = (uint16_t)(((a_hi2 << 8) | a6) + value14) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 + 4);
            uint16_t y1_next3 = value12;
            bool carry1_next3 = (uint16_t)(((a_hi2 << 8) | a6) + value14) >= 0xE0;
            bool zero1_next3 = (uint16_t)(x1 + 4) == 0;
            bool negative1_next3 = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next3 = ((((a_hi2 << 8) | a6) ^ (uint16_t)(((a_hi2 << 8) | a6) + value14)) & (value14 ^ (uint16_t)(((a_hi2 << 8) | a6) + value14)) & 0x8000) != 0;
            a5 = a5_next3;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            y1 = y1_next3;
            carry1 = carry1_next3;
            zero1 = zero1_next3;
            negative1 = negative1_next3;
            overflow2 = overflow2_next3;
            continue;
        }
        r->a = (uint16_t)(((a_hi2 << 8) | a6) + value14);
        r->x = x1;
        r->y = value12;
        r->c = (uint16_t)(((a_hi2 << 8) | a6) + value14) >= 0xE0;
        r->z = (uint16_t)(((a_hi2 << 8) | a6) + value14) == 0xE0;
        r->n = (uint16_t)((uint16_t)(((a_hi2 << 8) | a6) + value14) - 0xE0) & 0x8000;
        r->v = ((((a_hi2 << 8) | a6) ^ (uint16_t)(((a_hi2 << 8) | a6) + value14)) & (value14 ^ (uint16_t)(((a_hi2 << 8) | a6) + value14)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi1 << 8) | a5;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow2;
    r->mf = 1;
    RETURN_RTS(c);
}

/* C0E5F5 sub_C0E5F5_v2   [class A, 218 bytes, 110 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void sub_C0E5F5_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0014);
    RAM16_SET(0x0004, RAM16(0xE020 + value));
    uint16_t value3 = RAM16(0xE074 + value);
    uint16_t value4 = RAM16(0xE045 + value);
    uint16_t value5 = RAM16(0xE022 + value);
    RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5 + 1));
    uint8_t value6 = RAM8(0xE00D + value);
    uint8_t a3;
    bool overflow1;
    if (value6 == 0) {
        a3 = value6;
        overflow1 = (((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5 + 1)) & (value5 ^ (uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5 + 1)) & 0x8000) != 0;
    } else {
        RAM8(0xE00D + value) = (uint8_t)(value6 - 0x10);
        uint8_t a2;
        if (value6 >= 0x10) {
            if ((uint8_t)(value6 - 0x10) & 0x01) {
                RAM8(0x0000 + sp0) = (uint8_t)(value6 - 0x10) >> 1;
                RAM8(0x0004) = ((RAM8(0x00F4) & 1) << 1) ^ RAM8(0x0004);
            }
            uint8_t a1;
            if (!((uint8_t)(value6 - 0x10) >> 1 & 0x01)) {
                a1 = (uint8_t)(value6 - 0x10) >> 2;
            } else {
                uint8_t value9 = RAM8(0x00F4);
                uint8_t value10 = RAM8(0x0006);
                RAM8(0x0006) = ((value9 & 1) << 1) ^ value10;
                a1 = ((value9 & 1) << 1) ^ value10;
            }
            a2 = a1;
        } else {
            RAM8(0xE00D + value) = 0;
            a2 = 0;
        }
        a3 = a2;
        overflow1 = ((value6 ^ 0x10) & (value6 ^ (uint8_t)(value6 - 0x10)) & 0x80) != 0;
    }
    uint8_t a4 = a3;
    uint8_t a_hi1 = (uint16_t)(((uint16_t)((value3 & 0x7F) + value4) ^ 0xFFFF) + value5 + 1) >> 8;
    uint16_t x1 = y;
    uint16_t y1 = y;
    bool carry1 = 0;
    bool zero1 = y == 0;
    bool negative1 = y & 0x8000;
    bool overflow2 = overflow1;
    for (;;) {
        uint16_t value11 = RAM16(0x007C);
        if (value11 >= 0x0200) {
            r->a = (a_hi1 << 8) | a4;
            r->x = x1;
            r->y = value11;
            r->c = value11 >= 0x0200;
            r->z = value11 == 0x0200;
            r->n = (uint16_t)(value11 - 0x0200) & 0x8000;
            r->v = overflow2;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value12 = RAM8(0x0001 + x1);
        uint8_t a5;
        uint8_t a_hi2;
        if (!(value12 & 0x80)) {
            a5 = value12;
            a_hi2 = 0;
        } else {
            a5 = (uint8_t)(value12 | 0xFF00);
            a_hi2 = (value12 | 0xFF00) >> 8;
        }
        uint16_t value13 = RAM16(0x0006);
        if ((uint16_t)(((a_hi2 << 8) | a5) + value13) & 0x8000) {
            bool m_flag6;
            uint8_t a15;
            uint8_t a_hi12;
            uint16_t y10;
            bool carry7;
            bool overflow8;
            if ((uint16_t)(((a_hi2 << 8) | a5) + value13) < 0xFFF0) {
                m_flag6 = 0;
                a15 = (uint8_t)(((a_hi2 << 8) | a5) + value13);
                a_hi12 = (uint16_t)(((a_hi2 << 8) | a5) + value13) >> 8;
                y10 = value11;
                carry7 = (uint16_t)(((a_hi2 << 8) | a5) + value13) >= 0xFFF0;
                overflow8 = ((((a_hi2 << 8) | a5) ^ (uint16_t)(((a_hi2 << 8) | a5) + value13)) & (value13 ^ (uint16_t)(((a_hi2 << 8) | a5) + value13)) & 0x8000) != 0;
            } else {
                RAM8(0x0801 + value11) = (uint8_t)(((a_hi2 << 8) | a5) + value13);
                uint8_t value14 = RAM8(0x0000 + x1);
                uint8_t a6;
                uint8_t a_hi3;
                if (!(value14 & 0x80)) {
                    a6 = value14;
                    a_hi3 = 0;
                } else {
                    a6 = (uint8_t)(value14 | 0xFF00);
                    a_hi3 = (value14 | 0xFF00) >> 8;
                }
                uint16_t value15 = RAM16(0x0004);
                bool m_flag5;
                uint8_t a14;
                uint8_t a_hi11;
                uint16_t y9;
                bool carry6;
                bool overflow7;
                if ((uint16_t)(((a_hi3 << 8) | a6) + value15) & 0x8000) {
                    bool m_flag;
                    uint8_t a8;
                    uint8_t a_hi5;
                    uint16_t y3;
                    bool carry2;
                    bool overflow3;
                    if ((uint16_t)(((a_hi3 << 8) | a6) + value15) < 0xFFF0) {
                        m_flag = 0;
                        a8 = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                        a_hi5 = (uint16_t)(((a_hi3 << 8) | a6) + value15) >> 8;
                        y3 = value11;
                        carry2 = (uint16_t)(((a_hi3 << 8) | a6) + value15) >= 0xFFF0;
                        overflow3 = ((((a_hi3 << 8) | a6) ^ (uint16_t)(((a_hi3 << 8) | a6) + value15)) & (value15 ^ (uint16_t)(((a_hi3 << 8) | a6) + value15)) & 0x8000) != 0;
                    } else {
                        RAM8(0x0800 + value11) = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                        uint8_t a_hi4;
                        uint16_t y2;
                        if ((uint16_t)(((a_hi3 << 8) | a6) + value15) >> 8 == 0) {
                            a_hi4 = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                            y2 = value11;
                        } else {
                            uint8_t value16 = RAM8(0x005A);
                            RAM8(0x0A00 + value16) ^= RAM8(0x0059);
                            uint16_t value19 = RAM16(0x007C);
                            a_hi4 = 0;
                            y2 = value19;
                        }
                        RAM16_SET(0x0802 + y2, RAM16(0x0002 + x1));
                        RAM16_SET(0x007C, (uint16_t)(y2 + 4));
                        uint8_t value21 = RAM8(0x0059);
                        uint8_t a7;
                        if (!((uint8_t)(value21 << 1) & 0x80)) {
                            a7 = (uint8_t)(value21 << 2);
                        } else {
                            RAM8(0x005A)++;
                            a7 = 1;
                        }
                        RAM8(0x0059) = a7;
                        m_flag = 1;
                        a8 = a7;
                        a_hi5 = (uint16_t)(y2 + 4) >> 8;
                        y3 = (uint16_t)(y2 + 4);
                        carry2 = (uint8_t)(value21 << 1) & 0x80;
                        overflow3 = ((y2 ^ (uint16_t)(y2 + 4)) & ((uint16_t)(y2 + 4) ^ 4) & 0x8000) != 0;
                    }
                    m_flag5 = m_flag;
                    a14 = a8;
                    a_hi11 = a_hi5;
                    y9 = y3;
                    carry6 = carry2;
                    overflow7 = overflow3;
                } else {
                    bool m_flag4;
                    uint8_t a13;
                    uint8_t a_hi10;
                    uint16_t y8;
                    bool carry5;
                    bool overflow6;
                    if ((uint16_t)(((a_hi3 << 8) | a6) + value15) < 0x0100) {
                        RAM8(0x0800 + value11) = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                        uint8_t a_hi6;
                        uint16_t y4;
                        if ((uint16_t)(((a_hi3 << 8) | a6) + value15) >> 8 == 0) {
                            a_hi6 = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                            y4 = value11;
                        } else {
                            uint8_t value22 = RAM8(0x005A);
                            RAM8(0x0A00 + value22) ^= RAM8(0x0059);
                            uint16_t value25 = RAM16(0x007C);
                            a_hi6 = 0;
                            y4 = value25;
                        }
                        RAM16_SET(0x0802 + y4, RAM16(0x0002 + x1));
                        RAM16_SET(0x007C, (uint16_t)(y4 + 4));
                        uint8_t value27 = RAM8(0x0059);
                        uint8_t a9;
                        if (!((uint8_t)(value27 << 1) & 0x80)) {
                            a9 = (uint8_t)(value27 << 2);
                        } else {
                            RAM8(0x005A)++;
                            a9 = 1;
                        }
                        RAM8(0x0059) = a9;
                        m_flag4 = 1;
                        a13 = a9;
                        a_hi10 = (uint16_t)(y4 + 4) >> 8;
                        y8 = (uint16_t)(y4 + 4);
                        carry5 = (uint8_t)(value27 << 1) & 0x80;
                        overflow6 = ((y4 ^ (uint16_t)(y4 + 4)) & ((uint16_t)(y4 + 4) ^ 4) & 0x8000) != 0;
                    } else {
                        bool m_flag3;
                        uint8_t a12;
                        uint8_t a_hi9;
                        uint16_t y7;
                        bool carry4;
                        bool overflow5;
                        if ((uint16_t)(((a_hi3 << 8) | a6) + value15) >= 0x0100) {
                            m_flag3 = 0;
                            a12 = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                            a_hi9 = (uint16_t)(((a_hi3 << 8) | a6) + value15) >> 8;
                            y7 = value11;
                            carry4 = (uint16_t)(((a_hi3 << 8) | a6) + value15) >= 0x0100;
                            overflow5 = ((((a_hi3 << 8) | a6) ^ (uint16_t)(((a_hi3 << 8) | a6) + value15)) & (value15 ^ (uint16_t)(((a_hi3 << 8) | a6) + value15)) & 0x8000) != 0;
                        } else {
                            bool m_flag2;
                            uint8_t a11;
                            uint8_t a_hi8;
                            uint16_t y6;
                            bool carry3;
                            bool overflow4;
                            if ((uint16_t)(((a_hi3 << 8) | a6) + value15) < 0xFFF0) {
                                m_flag2 = 0;
                                a11 = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                                a_hi8 = (uint16_t)(((a_hi3 << 8) | a6) + value15) >> 8;
                                y6 = value11;
                                carry3 = (uint16_t)(((a_hi3 << 8) | a6) + value15) >= 0xFFF0;
                                overflow4 = ((((a_hi3 << 8) | a6) ^ (uint16_t)(((a_hi3 << 8) | a6) + value15)) & (value15 ^ (uint16_t)(((a_hi3 << 8) | a6) + value15)) & 0x8000) != 0;
                            } else {
                                RAM8(0x0800 + value11) = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                                uint8_t a_hi7;
                                uint16_t y5;
                                if ((uint16_t)(((a_hi3 << 8) | a6) + value15) >> 8 == 0) {
                                    a_hi7 = (uint8_t)(((a_hi3 << 8) | a6) + value15);
                                    y5 = value11;
                                } else {
                                    uint8_t value28 = RAM8(0x005A);
                                    RAM8(0x0A00 + value28) ^= RAM8(0x0059);
                                    uint16_t value31 = RAM16(0x007C);
                                    a_hi7 = 0;
                                    y5 = value31;
                                }
                                RAM16_SET(0x0802 + y5, RAM16(0x0002 + x1));
                                RAM16_SET(0x007C, (uint16_t)(y5 + 4));
                                uint8_t value33 = RAM8(0x0059);
                                uint8_t a10;
                                if (!((uint8_t)(value33 << 1) & 0x80)) {
                                    a10 = (uint8_t)(value33 << 2);
                                } else {
                                    RAM8(0x005A)++;
                                    a10 = 1;
                                }
                                RAM8(0x0059) = a10;
                                m_flag2 = 1;
                                a11 = a10;
                                a_hi8 = (uint16_t)(y5 + 4) >> 8;
                                y6 = (uint16_t)(y5 + 4);
                                carry3 = (uint8_t)(value33 << 1) & 0x80;
                                overflow4 = ((y5 ^ (uint16_t)(y5 + 4)) & ((uint16_t)(y5 + 4) ^ 4) & 0x8000) != 0;
                            }
                            m_flag3 = m_flag2;
                            a12 = a11;
                            a_hi9 = a_hi8;
                            y7 = y6;
                            carry4 = carry3;
                            overflow5 = overflow4;
                        }
                        m_flag4 = m_flag3;
                        a13 = a12;
                        a_hi10 = a_hi9;
                        y8 = y7;
                        carry5 = carry4;
                        overflow6 = overflow5;
                    }
                    m_flag5 = m_flag4;
                    a14 = a13;
                    a_hi11 = a_hi10;
                    y9 = y8;
                    carry6 = carry5;
                    overflow7 = overflow6;
                }
                m_flag6 = m_flag5;
                a15 = a14;
                a_hi12 = a_hi11;
                y10 = y9;
                carry7 = carry6;
                overflow8 = overflow7;
            }
            RAM8(0x0002)--;
            if (RAM8(0x0002) == 0) {
                a4 = a15;
                a_hi1 = a_hi12;
                y1 = y10;
                carry1 = carry7;
                zero1 = RAM8(0x0002) == 0;
                negative1 = RAM8(0x0002) & 0x80;
                overflow2 = overflow8;
                break;
            }
            uint8_t a4_next = a15;
            uint8_t a_hi1_next = a_hi12;
            uint16_t x1_next = (uint16_t)(x1 + 4);
            uint16_t y1_next = y10;
            bool carry1_next = carry7;
            bool zero1_next = (uint16_t)(x1 + 4) == 0;
            bool negative1_next = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next = overflow8;
            a4 = a4_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            zero1 = zero1_next;
            negative1 = negative1_next;
            overflow2 = overflow2_next;
            continue;
        }
        if ((uint16_t)(((a_hi2 << 8) | a5) + value13) < 0xE0) {
            RAM8(0x0801 + value11) = (uint8_t)(((a_hi2 << 8) | a5) + value13);
            uint8_t value34 = RAM8(0x0000 + x1);
            uint8_t a16;
            uint8_t a_hi13;
            if (!(value34 & 0x80)) {
                a16 = value34;
                a_hi13 = 0;
            } else {
                a16 = (uint8_t)(value34 | 0xFF00);
                a_hi13 = (value34 | 0xFF00) >> 8;
            }
            uint16_t value35 = RAM16(0x0004);
            bool m_flag11;
            uint8_t a24;
            uint8_t a_hi21;
            uint16_t y18;
            bool carry12;
            bool overflow13;
            if ((uint16_t)(((a_hi13 << 8) | a16) + value35) & 0x8000) {
                bool m_flag7;
                uint8_t a18;
                uint8_t a_hi15;
                uint16_t y12;
                bool carry8;
                bool overflow9;
                if ((uint16_t)(((a_hi13 << 8) | a16) + value35) < 0xFFF0) {
                    m_flag7 = 0;
                    a18 = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                    a_hi15 = (uint16_t)(((a_hi13 << 8) | a16) + value35) >> 8;
                    y12 = value11;
                    carry8 = (uint16_t)(((a_hi13 << 8) | a16) + value35) >= 0xFFF0;
                    overflow9 = ((((a_hi13 << 8) | a16) ^ (uint16_t)(((a_hi13 << 8) | a16) + value35)) & (value35 ^ (uint16_t)(((a_hi13 << 8) | a16) + value35)) & 0x8000) != 0;
                } else {
                    RAM8(0x0800 + value11) = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                    uint8_t a_hi14;
                    uint16_t y11;
                    if ((uint16_t)(((a_hi13 << 8) | a16) + value35) >> 8 == 0) {
                        a_hi14 = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                        y11 = value11;
                    } else {
                        uint8_t value36 = RAM8(0x005A);
                        RAM8(0x0A00 + value36) ^= RAM8(0x0059);
                        uint16_t value39 = RAM16(0x007C);
                        a_hi14 = 0;
                        y11 = value39;
                    }
                    RAM16_SET(0x0802 + y11, RAM16(0x0002 + x1));
                    RAM16_SET(0x007C, (uint16_t)(y11 + 4));
                    uint8_t value41 = RAM8(0x0059);
                    uint8_t a17;
                    if (!((uint8_t)(value41 << 1) & 0x80)) {
                        a17 = (uint8_t)(value41 << 2);
                    } else {
                        RAM8(0x005A)++;
                        a17 = 1;
                    }
                    RAM8(0x0059) = a17;
                    m_flag7 = 1;
                    a18 = a17;
                    a_hi15 = (uint16_t)(y11 + 4) >> 8;
                    y12 = (uint16_t)(y11 + 4);
                    carry8 = (uint8_t)(value41 << 1) & 0x80;
                    overflow9 = ((y11 ^ (uint16_t)(y11 + 4)) & ((uint16_t)(y11 + 4) ^ 4) & 0x8000) != 0;
                }
                m_flag11 = m_flag7;
                a24 = a18;
                a_hi21 = a_hi15;
                y18 = y12;
                carry12 = carry8;
                overflow13 = overflow9;
            } else {
                bool m_flag10;
                uint8_t a23;
                uint8_t a_hi20;
                uint16_t y17;
                bool carry11;
                bool overflow12;
                if ((uint16_t)(((a_hi13 << 8) | a16) + value35) < 0x0100) {
                    RAM8(0x0800 + value11) = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                    uint8_t a_hi16;
                    uint16_t y13;
                    if ((uint16_t)(((a_hi13 << 8) | a16) + value35) >> 8 == 0) {
                        a_hi16 = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                        y13 = value11;
                    } else {
                        uint8_t value42 = RAM8(0x005A);
                        RAM8(0x0A00 + value42) ^= RAM8(0x0059);
                        uint16_t value45 = RAM16(0x007C);
                        a_hi16 = 0;
                        y13 = value45;
                    }
                    RAM16_SET(0x0802 + y13, RAM16(0x0002 + x1));
                    RAM16_SET(0x007C, (uint16_t)(y13 + 4));
                    uint8_t value47 = RAM8(0x0059);
                    uint8_t a19;
                    if (!((uint8_t)(value47 << 1) & 0x80)) {
                        a19 = (uint8_t)(value47 << 2);
                    } else {
                        RAM8(0x005A)++;
                        a19 = 1;
                    }
                    RAM8(0x0059) = a19;
                    m_flag10 = 1;
                    a23 = a19;
                    a_hi20 = (uint16_t)(y13 + 4) >> 8;
                    y17 = (uint16_t)(y13 + 4);
                    carry11 = (uint8_t)(value47 << 1) & 0x80;
                    overflow12 = ((y13 ^ (uint16_t)(y13 + 4)) & ((uint16_t)(y13 + 4) ^ 4) & 0x8000) != 0;
                } else {
                    bool m_flag9;
                    uint8_t a22;
                    uint8_t a_hi19;
                    uint16_t y16;
                    bool carry10;
                    bool overflow11;
                    if ((uint16_t)(((a_hi13 << 8) | a16) + value35) >= 0x0100) {
                        m_flag9 = 0;
                        a22 = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                        a_hi19 = (uint16_t)(((a_hi13 << 8) | a16) + value35) >> 8;
                        y16 = value11;
                        carry10 = (uint16_t)(((a_hi13 << 8) | a16) + value35) >= 0x0100;
                        overflow11 = ((((a_hi13 << 8) | a16) ^ (uint16_t)(((a_hi13 << 8) | a16) + value35)) & (value35 ^ (uint16_t)(((a_hi13 << 8) | a16) + value35)) & 0x8000) != 0;
                    } else {
                        bool m_flag8;
                        uint8_t a21;
                        uint8_t a_hi18;
                        uint16_t y15;
                        bool carry9;
                        bool overflow10;
                        if ((uint16_t)(((a_hi13 << 8) | a16) + value35) < 0xFFF0) {
                            m_flag8 = 0;
                            a21 = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                            a_hi18 = (uint16_t)(((a_hi13 << 8) | a16) + value35) >> 8;
                            y15 = value11;
                            carry9 = (uint16_t)(((a_hi13 << 8) | a16) + value35) >= 0xFFF0;
                            overflow10 = ((((a_hi13 << 8) | a16) ^ (uint16_t)(((a_hi13 << 8) | a16) + value35)) & (value35 ^ (uint16_t)(((a_hi13 << 8) | a16) + value35)) & 0x8000) != 0;
                        } else {
                            RAM8(0x0800 + value11) = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                            uint8_t a_hi17;
                            uint16_t y14;
                            if ((uint16_t)(((a_hi13 << 8) | a16) + value35) >> 8 == 0) {
                                a_hi17 = (uint8_t)(((a_hi13 << 8) | a16) + value35);
                                y14 = value11;
                            } else {
                                uint8_t value48 = RAM8(0x005A);
                                RAM8(0x0A00 + value48) ^= RAM8(0x0059);
                                uint16_t value51 = RAM16(0x007C);
                                a_hi17 = 0;
                                y14 = value51;
                            }
                            RAM16_SET(0x0802 + y14, RAM16(0x0002 + x1));
                            RAM16_SET(0x007C, (uint16_t)(y14 + 4));
                            uint8_t value53 = RAM8(0x0059);
                            uint8_t a20;
                            if (!((uint8_t)(value53 << 1) & 0x80)) {
                                a20 = (uint8_t)(value53 << 2);
                            } else {
                                RAM8(0x005A)++;
                                a20 = 1;
                            }
                            RAM8(0x0059) = a20;
                            m_flag8 = 1;
                            a21 = a20;
                            a_hi18 = (uint16_t)(y14 + 4) >> 8;
                            y15 = (uint16_t)(y14 + 4);
                            carry9 = (uint8_t)(value53 << 1) & 0x80;
                            overflow10 = ((y14 ^ (uint16_t)(y14 + 4)) & ((uint16_t)(y14 + 4) ^ 4) & 0x8000) != 0;
                        }
                        m_flag9 = m_flag8;
                        a22 = a21;
                        a_hi19 = a_hi18;
                        y16 = y15;
                        carry10 = carry9;
                        overflow11 = overflow10;
                    }
                    m_flag10 = m_flag9;
                    a23 = a22;
                    a_hi20 = a_hi19;
                    y17 = y16;
                    carry11 = carry10;
                    overflow12 = overflow11;
                }
                m_flag11 = m_flag10;
                a24 = a23;
                a_hi21 = a_hi20;
                y18 = y17;
                carry12 = carry11;
                overflow13 = overflow12;
            }
            RAM8(0x0002)--;
            if (RAM8(0x0002) == 0) {
                a4 = a24;
                a_hi1 = a_hi21;
                y1 = y18;
                carry1 = carry12;
                zero1 = RAM8(0x0002) == 0;
                negative1 = RAM8(0x0002) & 0x80;
                overflow2 = overflow13;
                break;
            }
            uint8_t a4_next2 = a24;
            uint8_t a_hi1_next2 = a_hi21;
            uint16_t x1_next2 = (uint16_t)(x1 + 4);
            uint16_t y1_next2 = y18;
            bool carry1_next2 = carry12;
            bool zero1_next2 = (uint16_t)(x1 + 4) == 0;
            bool negative1_next2 = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next2 = overflow13;
            a4 = a4_next2;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            y1 = y1_next2;
            carry1 = carry1_next2;
            zero1 = zero1_next2;
            negative1 = negative1_next2;
            overflow2 = overflow2_next2;
            continue;
        }
        if ((uint16_t)(((a_hi2 << 8) | a5) + value13) >= 0xE0) {
            RAM8(0x0002)--;
            if (RAM8(0x0002) == 0) {
                a4 = (uint8_t)(((a_hi2 << 8) | a5) + value13);
                a_hi1 = (uint16_t)(((a_hi2 << 8) | a5) + value13) >> 8;
                y1 = value11;
                carry1 = (uint16_t)(((a_hi2 << 8) | a5) + value13) >= 0xE0;
                zero1 = RAM8(0x0002) == 0;
                negative1 = RAM8(0x0002) & 0x80;
                overflow2 = ((((a_hi2 << 8) | a5) ^ (uint16_t)(((a_hi2 << 8) | a5) + value13)) & (value13 ^ (uint16_t)(((a_hi2 << 8) | a5) + value13)) & 0x8000) != 0;
                break;
            }
            uint8_t a4_next3 = (uint8_t)(((a_hi2 << 8) | a5) + value13);
            uint8_t a_hi1_next3 = (uint16_t)(((a_hi2 << 8) | a5) + value13) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 + 4);
            uint16_t y1_next3 = value11;
            bool carry1_next3 = (uint16_t)(((a_hi2 << 8) | a5) + value13) >= 0xE0;
            bool zero1_next3 = (uint16_t)(x1 + 4) == 0;
            bool negative1_next3 = (uint16_t)(x1 + 4) & 0x8000;
            bool overflow2_next3 = ((((a_hi2 << 8) | a5) ^ (uint16_t)(((a_hi2 << 8) | a5) + value13)) & (value13 ^ (uint16_t)(((a_hi2 << 8) | a5) + value13)) & 0x8000) != 0;
            a4 = a4_next3;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            y1 = y1_next3;
            carry1 = carry1_next3;
            zero1 = zero1_next3;
            negative1 = negative1_next3;
            overflow2 = overflow2_next3;
            continue;
        }
        r->a = (uint16_t)(((a_hi2 << 8) | a5) + value13);
        r->x = x1;
        r->y = value11;
        r->c = (uint16_t)(((a_hi2 << 8) | a5) + value13) >= 0xE0;
        r->z = (uint16_t)(((a_hi2 << 8) | a5) + value13) == 0xE0;
        r->n = (uint16_t)((uint16_t)(((a_hi2 << 8) | a5) + value13) - 0xE0) & 0x8000;
        r->v = ((((a_hi2 << 8) | a5) ^ (uint16_t)(((a_hi2 << 8) | a5) + value13)) & (value13 ^ (uint16_t)(((a_hi2 << 8) | a5) + value13)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi1 << 8) | a4;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow2;
    r->mf = 1;
    RETURN_RTS(c);
}

/* C0E640 emit_packed_actor_sprite_list   [class A, 143 bytes, 72 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void emit_packed_actor_sprite_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint8_t a_e662 = 0;
    uint8_t a_hi_e662 = 0;
    uint16_t x_e662 = 0;
    uint16_t y_e662 = 0;
    bool carry_e662 = 0;
    bool zero_e662 = 0;
    bool negative_e662 = 0;
    bool overflow_e662 = 0;
    uint8_t a_e656 = 0;
    uint8_t a_hi_e656 = 0;
    uint16_t x_e656 = 0;
    uint16_t y_e656 = 0;
    uint8_t a_e6c1 = 0;
    uint8_t a_hi_e6c1 = 0;
    uint16_t x_e6c1 = 0;
    uint16_t y_e6c1 = 0;
    bool carry_e6c1 = 0;
    bool overflow_e6c1 = 0;
    uint8_t a_e668 = 0;
    uint8_t a_hi_e668 = 0;
    uint16_t x_e668 = 0;
    uint16_t y_e668 = 0;
    uint8_t a_e6622 = 0;
    uint8_t a_hi_e6622 = 0;
    uint16_t x_e6622 = 0;
    uint16_t y_e6622 = 0;
    bool carry_e6622 = 0;
    bool zero_e6622 = 0;
    bool negative_e6622 = 0;
    bool overflow_e6622 = 0;
    uint8_t a_e67a = 0;
    uint8_t a_hi_e67a = 0;
    uint16_t x_e67a = 0;
    uint16_t y_e67a = 0;
    uint8_t a_e686 = 0;
    uint8_t a_hi_e686 = 0;
    uint16_t x_e686 = 0;
    uint16_t y_e686 = 0;
    bool overflow_e686 = 0;
    uint8_t a_e68b = 0;
    uint8_t a_hi_e68b = 0;
    uint16_t x_e68b = 0;
    uint16_t y_e68b = 0;
    uint8_t a_hi_e6a3 = 0;
    uint16_t x_e6a3 = 0;
    uint16_t y_e6a3 = 0;
    uint8_t a_e6bf = 0;
    uint8_t a_hi_e6bf = 0;
    uint16_t x_e6bf = 0;
    uint16_t y_e6bf = 0;
    bool carry_e6bf = 0;
    bool overflow_e6bf = 0;
    uint8_t a_e6c12 = 0;
    uint8_t a_hi_e6c12 = 0;
    uint16_t x_e6c12 = 0;
    uint16_t y_e6c12 = 0;
    bool carry_e6c12 = 0;
    bool overflow_e6c12 = 0;
    uint16_t value = RAM16(0x007C);
    if (value >= 0x0200) {
        a_e662 = (uint8_t)a;
        a_hi_e662 = a >> 8;
        x_e662 = x;
        y_e662 = value;
        carry_e662 = value >= 0x0200;
        zero_e662 = value == 0x0200;
        negative_e662 = (uint16_t)(value - 0x0200) & 0x8000;
        overflow_e662 = overflow;
        goto shared_E662;
    }
    uint8_t value2 = RAM8(0x0001 + x);
    if (!(value2 & 0x80)) {
        a_e656 = value2;
        a_hi_e656 = 0;
        x_e656 = x;
        y_e656 = value;
        goto shared_E656;
    }
    a_e656 = (uint8_t)(value2 | 0xFF00);
    a_hi_e656 = (value2 | 0xFF00) >> 8;
    x_e656 = x;
    y_e656 = value;
    shared_E656:;
    uint16_t value3 = RAM16(0x0006);
    if ((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) & 0x8000) {
        if ((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) < 0xFFF0) {
            a_e6c1 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
            a_hi_e6c1 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
            x_e6c1 = x_e656;
            y_e6c1 = y_e656;
            carry_e6c1 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >= 0xFFF0;
            overflow_e6c1 = ((((a_hi_e656 << 8) | a_e656) ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & (value3 ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & 0x8000) != 0;
            goto shared_E6C1;
        }
        a_e668 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
        a_hi_e668 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
        x_e668 = x_e656;
        y_e668 = y_e656;
        goto shared_E668;
    }
    if ((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) < 0xE0) {
        a_e668 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
        a_hi_e668 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
        x_e668 = x_e656;
        y_e668 = y_e656;
        goto shared_E668;
    }
    if ((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >= 0xE0) {
        a_e6c1 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
        a_hi_e6c1 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
        x_e6c1 = x_e656;
        y_e6c1 = y_e656;
        carry_e6c1 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >= 0xE0;
        overflow_e6c1 = ((((a_hi_e656 << 8) | a_e656) ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & (value3 ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & 0x8000) != 0;
        goto shared_E6C1;
    }
    a_e6622 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
    a_hi_e6622 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
    x_e6622 = x_e656;
    y_e6622 = y_e656;
    carry_e6622 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >= 0xE0;
    zero_e6622 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) == 0xE0;
    negative_e6622 = (uint16_t)((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) - 0xE0) & 0x8000;
    overflow_e6622 = ((((a_hi_e656 << 8) | a_e656) ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & (value3 ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & 0x8000) != 0;
    goto shared_E662_1;
    shared_E662:;
    r->a = (a_hi_e662 << 8) | a_e662;
    r->x = x_e662;
    r->y = y_e662;
    r->c = carry_e662;
    r->z = zero_e662;
    r->n = negative_e662;
    r->v = overflow_e662;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_E6C1:;
    RAM8(0x0002)--;
    if (RAM8(0x0002) == 0) {
        r->a = (a_hi_e6c1 << 8) | a_e6c1;
        r->x = x_e6c1;
        r->y = y_e6c1;
        r->c = carry_e6c1;
        r->z = RAM8(0x0002) == 0;
        r->n = RAM8(0x0002) & 0x80;
        r->v = overflow_e6c1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(0x007C);
    if (value4 >= 0x0200) {
        a_e662 = a_e6c1;
        a_hi_e662 = a_hi_e6c1;
        x_e662 = (uint16_t)(x_e6c1 + 4);
        y_e662 = value4;
        carry_e662 = value4 >= 0x0200;
        zero_e662 = value4 == 0x0200;
        negative_e662 = (uint16_t)(value4 - 0x0200) & 0x8000;
        overflow_e662 = overflow_e6c1;
        goto shared_E662;
    }
    uint8_t value5 = RAM8(0x0001 + (uint16_t)(x_e6c1 + 4));
    if (!(value5 & 0x80)) {
        a_e656 = value5;
        a_hi_e656 = 0;
        x_e656 = (uint16_t)(x_e6c1 + 4);
        y_e656 = value4;
        goto shared_E656;
    }
    a_e656 = (uint8_t)(value5 | 0xFF00);
    a_hi_e656 = (value5 | 0xFF00) >> 8;
    x_e656 = (uint16_t)(x_e6c1 + 4);
    y_e656 = value4;
    goto shared_E656;
    shared_E668:;
    RAM8(0x0801 + y_e668) = a_e668;
    uint8_t value6 = RAM8(0x0000 + x_e668);
    if (!(value6 & 0x80)) {
        a_e67a = value6;
        a_hi_e67a = 0;
        x_e67a = x_e668;
        y_e67a = y_e668;
        goto shared_E67A;
    }
    a_e67a = (uint8_t)(value6 | 0xFF00);
    a_hi_e67a = (value6 | 0xFF00) >> 8;
    x_e67a = x_e668;
    y_e67a = y_e668;
    goto shared_E67A;
    shared_E662_1:;
    r->a = (a_hi_e6622 << 8) | a_e6622;
    r->x = x_e6622;
    r->y = y_e6622;
    r->c = carry_e6622;
    r->z = zero_e6622;
    r->n = negative_e6622;
    r->v = overflow_e6622;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_E67A:;
    uint16_t value7 = RAM16(0x0004);
    if ((uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7) & 0x8000) {
        a_e686 = (uint8_t)(((a_hi_e67a << 8) | a_e67a) + value7);
        a_hi_e686 = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7) >> 8;
        x_e686 = x_e67a;
        y_e686 = y_e67a;
        overflow_e686 = ((((a_hi_e67a << 8) | a_e67a) ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7)) & (value7 ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7)) & 0x8000) != 0;
        goto shared_E686;
    }
    if ((uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7) < 0x0100) {
        a_e68b = (uint8_t)(((a_hi_e67a << 8) | a_e67a) + value7);
        a_hi_e68b = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7) >> 8;
        x_e68b = x_e67a;
        y_e68b = y_e67a;
        goto shared_E68B;
    }
    if ((uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7) >= 0x0100) {
        a_e6c1 = (uint8_t)(((a_hi_e67a << 8) | a_e67a) + value7);
        a_hi_e6c1 = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7) >> 8;
        x_e6c1 = x_e67a;
        y_e6c1 = y_e67a;
        carry_e6c1 = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7) >= 0x0100;
        overflow_e6c1 = ((((a_hi_e67a << 8) | a_e67a) ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7)) & (value7 ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7)) & 0x8000) != 0;
        goto shared_E6C1;
    }
    a_e686 = (uint8_t)(((a_hi_e67a << 8) | a_e67a) + value7);
    a_hi_e686 = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7) >> 8;
    x_e686 = x_e67a;
    y_e686 = y_e67a;
    overflow_e686 = ((((a_hi_e67a << 8) | a_e67a) ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7)) & (value7 ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value7)) & 0x8000) != 0;
    goto shared_E686;
    shared_E686:;
    if (((a_hi_e686 << 8) | a_e686) < 0xFFF0) {
        a_e6c1 = a_e686;
        a_hi_e6c1 = a_hi_e686;
        x_e6c1 = x_e686;
        y_e6c1 = y_e686;
        carry_e6c1 = ((a_hi_e686 << 8) | a_e686) >= 0xFFF0;
        overflow_e6c1 = overflow_e686;
        goto shared_E6C1;
    }
    a_e68b = a_e686;
    a_hi_e68b = a_hi_e686;
    x_e68b = x_e686;
    y_e68b = y_e686;
    goto shared_E68B;
    shared_E68B:;
    RAM8(0x0800 + y_e68b) = a_e68b;
    if (a_hi_e68b == 0) {
        a_hi_e6a3 = a_e68b;
        x_e6a3 = x_e68b;
        y_e6a3 = y_e68b;
        goto shared_E6A3;
    }
    uint8_t value8 = RAM8(0x005A);
    RAM8(0x0A00 + value8) ^= RAM8(0x0059);
    uint16_t value11 = RAM16(0x007C);
    a_hi_e6a3 = 0;
    x_e6a3 = x_e68b;
    y_e6a3 = value11;
    goto shared_E6A3;
    shared_E6A3:;
    RAM16_SET(0x0802 + y_e6a3, RAM16(0x0002 + x_e6a3));
    RAM16_SET(0x007C, (uint16_t)(y_e6a3 + 4));
    uint8_t value13 = RAM8(0x0059);
    if (!((uint8_t)(value13 << 1) & 0x80)) {
        a_e6bf = (uint8_t)(value13 << 2);
        a_hi_e6bf = (uint16_t)(y_e6a3 + 4) >> 8;
        x_e6bf = x_e6a3;
        y_e6bf = (uint16_t)(y_e6a3 + 4);
        carry_e6bf = (uint8_t)(value13 << 1) & 0x80;
        overflow_e6bf = ((y_e6a3 ^ (uint16_t)(y_e6a3 + 4)) & ((uint16_t)(y_e6a3 + 4) ^ 4) & 0x8000) != 0;
        goto shared_E6BF;
    }
    RAM8(0x005A)++;
    a_e6bf = 1;
    a_hi_e6bf = (uint16_t)(y_e6a3 + 4) >> 8;
    x_e6bf = x_e6a3;
    y_e6bf = (uint16_t)(y_e6a3 + 4);
    carry_e6bf = (uint8_t)(value13 << 1) & 0x80;
    overflow_e6bf = ((y_e6a3 ^ (uint16_t)(y_e6a3 + 4)) & ((uint16_t)(y_e6a3 + 4) ^ 4) & 0x8000) != 0;
    goto shared_E6BF;
    shared_E6BF:;
    RAM8(0x0059) = a_e6bf;
    a_e6c12 = a_e6bf;
    a_hi_e6c12 = a_hi_e6bf;
    x_e6c12 = x_e6bf;
    y_e6c12 = y_e6bf;
    carry_e6c12 = carry_e6bf;
    overflow_e6c12 = overflow_e6bf;
    goto shared_E6C1_1;
    shared_E6C1_1:;
    RAM8(0x0002)--;
    if (RAM8(0x0002) == 0) {
        r->a = (a_hi_e6c12 << 8) | a_e6c12;
        r->x = x_e6c12;
        r->y = y_e6c12;
        r->c = carry_e6c12;
        r->z = RAM8(0x0002) == 0;
        r->n = RAM8(0x0002) & 0x80;
        r->v = overflow_e6c12;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint16_t value14 = RAM16(0x007C);
    if (value14 >= 0x0200) {
        a_e662 = a_e6c12;
        a_hi_e662 = a_hi_e6c12;
        x_e662 = (uint16_t)(x_e6c12 + 4);
        y_e662 = value14;
        carry_e662 = value14 >= 0x0200;
        zero_e662 = value14 == 0x0200;
        negative_e662 = (uint16_t)(value14 - 0x0200) & 0x8000;
        overflow_e662 = overflow_e6c12;
        goto shared_E662;
    }
    uint8_t value15 = RAM8(0x0001 + (uint16_t)(x_e6c12 + 4));
    if (!(value15 & 0x80)) {
        a_e656 = value15;
        a_hi_e656 = 0;
        x_e656 = (uint16_t)(x_e6c12 + 4);
        y_e656 = value14;
        goto shared_E656;
    }
    a_e656 = (uint8_t)(value15 | 0xFF00);
    a_hi_e656 = (value15 | 0xFF00) >> 8;
    x_e656 = (uint16_t)(x_e6c12 + 4);
    y_e656 = value14;
    goto shared_E656;
}

/* C0E640 emit_packed_actor_sprite_list_v2   [class A, 143 bytes, 72 instructions]
 * Source: src/rom/emit_one_actor_or_boss_sprite.s
 * Subroutine of emit_one_actor_or_boss_sprite, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void emit_packed_actor_sprite_list_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_e662 = 0;
    uint8_t a_hi_e662 = 0;
    uint16_t x_e662 = 0;
    uint16_t y_e662 = 0;
    bool carry_e662 = 0;
    bool zero_e662 = 0;
    bool negative_e662 = 0;
    bool overflow_e662 = 0;
    uint8_t a_e656 = 0;
    uint8_t a_hi_e656 = 0;
    uint16_t x_e656 = 0;
    uint16_t y_e656 = 0;
    uint8_t a_e6c1 = 0;
    uint8_t a_hi_e6c1 = 0;
    uint16_t x_e6c1 = 0;
    uint16_t y_e6c1 = 0;
    bool carry_e6c1 = 0;
    bool overflow_e6c1 = 0;
    uint8_t a_e668 = 0;
    uint8_t a_hi_e668 = 0;
    uint16_t x_e668 = 0;
    uint16_t y_e668 = 0;
    uint8_t a_e6622 = 0;
    uint8_t a_hi_e6622 = 0;
    uint16_t x_e6622 = 0;
    uint16_t y_e6622 = 0;
    bool carry_e6622 = 0;
    bool zero_e6622 = 0;
    bool negative_e6622 = 0;
    bool overflow_e6622 = 0;
    uint8_t a_e67a = 0;
    uint8_t a_hi_e67a = 0;
    uint16_t x_e67a = 0;
    uint16_t y_e67a = 0;
    uint8_t a_e686 = 0;
    uint8_t a_hi_e686 = 0;
    uint16_t x_e686 = 0;
    uint16_t y_e686 = 0;
    bool overflow_e686 = 0;
    uint8_t a_e68b = 0;
    uint8_t a_hi_e68b = 0;
    uint16_t x_e68b = 0;
    uint16_t y_e68b = 0;
    uint8_t a_hi_e6a3 = 0;
    uint16_t x_e6a3 = 0;
    uint16_t y_e6a3 = 0;
    uint8_t a_e6bf = 0;
    uint8_t a_hi_e6bf = 0;
    uint16_t x_e6bf = 0;
    uint16_t y_e6bf = 0;
    bool carry_e6bf = 0;
    bool overflow_e6bf = 0;
    uint8_t a_e6c12 = 0;
    uint8_t a_hi_e6c12 = 0;
    uint16_t x_e6c12 = 0;
    uint16_t y_e6c12 = 0;
    bool carry_e6c12 = 0;
    bool overflow_e6c12 = 0;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
    if (value >= 0x0200) {
        a_e662 = (uint8_t)a;
        a_hi_e662 = a >> 8;
        x_e662 = x;
        y_e662 = value;
        carry_e662 = value >= 0x0200;
        zero_e662 = value == 0x0200;
        negative_e662 = (uint16_t)(value - 0x0200) & 0x8000;
        overflow_e662 = overflow;
        goto shared_E662;
    }
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 1 + x);
    if (!(value2 & 0x80)) {
        a_e656 = value2;
        a_hi_e656 = 0;
        x_e656 = x;
        y_e656 = value;
        goto shared_E656;
    }
    a_e656 = (uint8_t)(value2 | 0xFF00);
    a_hi_e656 = (value2 | 0xFF00) >> 8;
    x_e656 = x;
    y_e656 = value;
    shared_E656:;
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 6));
    if ((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) & 0x8000) {
        if ((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) < 0xFFF0) {
            a_e6c1 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
            a_hi_e6c1 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
            x_e6c1 = x_e656;
            y_e6c1 = y_e656;
            carry_e6c1 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >= 0xFFF0;
            overflow_e6c1 = ((((a_hi_e656 << 8) | a_e656) ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & (value3 ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & 0x8000) != 0;
            goto shared_E6C1;
        }
        a_e668 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
        a_hi_e668 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
        x_e668 = x_e656;
        y_e668 = y_e656;
        goto shared_E668;
    }
    if ((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) < 0xE0) {
        a_e668 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
        a_hi_e668 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
        x_e668 = x_e656;
        y_e668 = y_e656;
        goto shared_E668;
    }
    if ((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >= 0xE0) {
        a_e6c1 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
        a_hi_e6c1 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
        x_e6c1 = x_e656;
        y_e6c1 = y_e656;
        carry_e6c1 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >= 0xE0;
        overflow_e6c1 = ((((a_hi_e656 << 8) | a_e656) ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & (value3 ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & 0x8000) != 0;
        goto shared_E6C1;
    }
    a_e6622 = (uint8_t)(((a_hi_e656 << 8) | a_e656) + value3);
    a_hi_e6622 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >> 8;
    x_e6622 = x_e656;
    y_e6622 = y_e656;
    carry_e6622 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) >= 0xE0;
    zero_e6622 = (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) == 0xE0;
    negative_e6622 = (uint16_t)((uint16_t)(((a_hi_e656 << 8) | a_e656) + value3) - 0xE0) & 0x8000;
    overflow_e6622 = ((((a_hi_e656 << 8) | a_e656) ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & (value3 ^ (uint16_t)(((a_hi_e656 << 8) | a_e656) + value3)) & 0x8000) != 0;
    goto shared_E662_1;
    shared_E662:;
    r->a = (a_hi_e662 << 8) | a_e662;
    r->x = x_e662;
    r->y = y_e662;
    r->c = carry_e662;
    r->z = zero_e662;
    r->n = negative_e662;
    r->v = overflow_e662;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
    shared_E6C1:;
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 2));
    BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)(value4 - 1));
    if ((uint8_t)(value4 - 1) == 0) {
        r->a = (a_hi_e6c1 << 8) | a_e6c1;
        r->x = x_e6c1;
        r->y = y_e6c1;
        r->c = carry_e6c1;
        r->z = (uint8_t)(value4 - 1) == 0;
        r->n = (uint8_t)(value4 - 1) & 0x80;
        r->v = overflow_e6c1;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = dp;
        RETURN_RTS(c);
    }
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
    if (value5 >= 0x0200) {
        a_e662 = a_e6c1;
        a_hi_e662 = a_hi_e6c1;
        x_e662 = (uint16_t)(x_e6c1 + 4);
        y_e662 = value5;
        carry_e662 = value5 >= 0x0200;
        zero_e662 = value5 == 0x0200;
        negative_e662 = (uint16_t)(value5 - 0x0200) & 0x8000;
        overflow_e662 = overflow_e6c1;
        goto shared_E662;
    }
    uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 1 + (uint16_t)(x_e6c1 + 4));
    if (!(value6 & 0x80)) {
        a_e656 = value6;
        a_hi_e656 = 0;
        x_e656 = (uint16_t)(x_e6c1 + 4);
        y_e656 = value5;
        goto shared_E656;
    }
    a_e656 = (uint8_t)(value6 | 0xFF00);
    a_hi_e656 = (value6 | 0xFF00) >> 8;
    x_e656 = (uint16_t)(x_e6c1 + 4);
    y_e656 = value5;
    goto shared_E656;
    shared_E668:;
    BUS8_SET(c, (db << 0x10) + 0x0801 + y_e668, a_e668);
    uint8_t value7 = BUS8_RDP(c, (db << 0x10) + x_e668);
    if (!(value7 & 0x80)) {
        a_e67a = value7;
        a_hi_e67a = 0;
        x_e67a = x_e668;
        y_e67a = y_e668;
        goto shared_E67A;
    }
    a_e67a = (uint8_t)(value7 | 0xFF00);
    a_hi_e67a = (value7 | 0xFF00) >> 8;
    x_e67a = x_e668;
    y_e67a = y_e668;
    goto shared_E67A;
    shared_E662_1:;
    r->a = (a_hi_e6622 << 8) | a_e6622;
    r->x = x_e6622;
    r->y = y_e6622;
    r->c = carry_e6622;
    r->z = zero_e6622;
    r->n = negative_e6622;
    r->v = overflow_e6622;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
    shared_E67A:;
    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp + 4));
    if ((uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8) & 0x8000) {
        a_e686 = (uint8_t)(((a_hi_e67a << 8) | a_e67a) + value8);
        a_hi_e686 = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8) >> 8;
        x_e686 = x_e67a;
        y_e686 = y_e67a;
        overflow_e686 = ((((a_hi_e67a << 8) | a_e67a) ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8)) & (value8 ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8)) & 0x8000) != 0;
        goto shared_E686;
    }
    if ((uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8) < 0x0100) {
        a_e68b = (uint8_t)(((a_hi_e67a << 8) | a_e67a) + value8);
        a_hi_e68b = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8) >> 8;
        x_e68b = x_e67a;
        y_e68b = y_e67a;
        goto shared_E68B;
    }
    if ((uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8) >= 0x0100) {
        a_e6c1 = (uint8_t)(((a_hi_e67a << 8) | a_e67a) + value8);
        a_hi_e6c1 = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8) >> 8;
        x_e6c1 = x_e67a;
        y_e6c1 = y_e67a;
        carry_e6c1 = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8) >= 0x0100;
        overflow_e6c1 = ((((a_hi_e67a << 8) | a_e67a) ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8)) & (value8 ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8)) & 0x8000) != 0;
        goto shared_E6C1;
    }
    a_e686 = (uint8_t)(((a_hi_e67a << 8) | a_e67a) + value8);
    a_hi_e686 = (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8) >> 8;
    x_e686 = x_e67a;
    y_e686 = y_e67a;
    overflow_e686 = ((((a_hi_e67a << 8) | a_e67a) ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8)) & (value8 ^ (uint16_t)(((a_hi_e67a << 8) | a_e67a) + value8)) & 0x8000) != 0;
    goto shared_E686;
    shared_E686:;
    if (((a_hi_e686 << 8) | a_e686) < 0xFFF0) {
        a_e6c1 = a_e686;
        a_hi_e6c1 = a_hi_e686;
        x_e6c1 = x_e686;
        y_e6c1 = y_e686;
        carry_e6c1 = ((a_hi_e686 << 8) | a_e686) >= 0xFFF0;
        overflow_e6c1 = overflow_e686;
        goto shared_E6C1;
    }
    a_e68b = a_e686;
    a_hi_e68b = a_hi_e686;
    x_e68b = x_e686;
    y_e68b = y_e686;
    goto shared_E68B;
    shared_E68B:;
    BUS8_SET(c, (db << 0x10) + 0x0800 + y_e68b, a_e68b);
    if (a_hi_e68b == 0) {
        a_hi_e6a3 = a_e68b;
        x_e6a3 = x_e68b;
        y_e6a3 = y_e68b;
        goto shared_E6A3;
    }
    uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
    uint8_t value10 = BUS8_RDP(c, (db << 0x10) + 0x0A00 + value9);
    uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
    BUS8_SET(c, (db << 0x10) + 0x0A00 + value9, value10 ^ value11);
    uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
    a_hi_e6a3 = 0;
    x_e6a3 = x_e68b;
    y_e6a3 = value12;
    goto shared_E6A3;
    shared_E6A3:;
    uint16_t value13 = BUS16_RDP(c, (db << 0x10) + 2 + x_e6a3);
    BUS16_SET(c, (db << 0x10) + 0x0802 + y_e6a3, value13);
    BUS16_SET(c, (uint16_t)(dp + 0x7C), (uint16_t)(y_e6a3 + 4));
    uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp + 0x59));
    if (!((uint8_t)(value14 << 1) & 0x80)) {
        a_e6bf = (uint8_t)(value14 << 2);
        a_hi_e6bf = (uint16_t)(y_e6a3 + 4) >> 8;
        x_e6bf = x_e6a3;
        y_e6bf = (uint16_t)(y_e6a3 + 4);
        carry_e6bf = (uint8_t)(value14 << 1) & 0x80;
        overflow_e6bf = ((y_e6a3 ^ (uint16_t)(y_e6a3 + 4)) & ((uint16_t)(y_e6a3 + 4) ^ 4) & 0x8000) != 0;
        goto shared_E6BF;
    }
    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 0x5A));
    BUS8_SET(c, (uint16_t)(dp + 0x5A), (uint8_t)(value15 + 1));
    a_e6bf = 1;
    a_hi_e6bf = (uint16_t)(y_e6a3 + 4) >> 8;
    x_e6bf = x_e6a3;
    y_e6bf = (uint16_t)(y_e6a3 + 4);
    carry_e6bf = (uint8_t)(value14 << 1) & 0x80;
    overflow_e6bf = ((y_e6a3 ^ (uint16_t)(y_e6a3 + 4)) & ((uint16_t)(y_e6a3 + 4) ^ 4) & 0x8000) != 0;
    goto shared_E6BF;
    shared_E6BF:;
    BUS8_SET(c, (uint16_t)(dp + 0x59), a_e6bf);
    a_e6c12 = a_e6bf;
    a_hi_e6c12 = a_hi_e6bf;
    x_e6c12 = x_e6bf;
    y_e6c12 = y_e6bf;
    carry_e6c12 = carry_e6bf;
    overflow_e6c12 = overflow_e6bf;
    goto shared_E6C1_1;
    shared_E6C1_1:;
    uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp + 2));
    BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)(value16 - 1));
    if ((uint8_t)(value16 - 1) == 0) {
        r->a = (a_hi_e6c12 << 8) | a_e6c12;
        r->x = x_e6c12;
        r->y = y_e6c12;
        r->c = carry_e6c12;
        r->z = (uint8_t)(value16 - 1) == 0;
        r->n = (uint8_t)(value16 - 1) & 0x80;
        r->v = overflow_e6c12;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = dp;
        RETURN_RTS(c);
    }
    uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp + 0x7C));
    if (value17 >= 0x0200) {
        a_e662 = a_e6c12;
        a_hi_e662 = a_hi_e6c12;
        x_e662 = (uint16_t)(x_e6c12 + 4);
        y_e662 = value17;
        carry_e662 = value17 >= 0x0200;
        zero_e662 = value17 == 0x0200;
        negative_e662 = (uint16_t)(value17 - 0x0200) & 0x8000;
        overflow_e662 = overflow_e6c12;
        goto shared_E662;
    }
    uint8_t value18 = BUS8_RDP(c, (db << 0x10) + 1 + (uint16_t)(x_e6c12 + 4));
    if (!(value18 & 0x80)) {
        a_e656 = value18;
        a_hi_e656 = 0;
        x_e656 = (uint16_t)(x_e6c12 + 4);
        y_e656 = value17;
        goto shared_E656;
    }
    a_e656 = (uint8_t)(value18 | 0xFF00);
    a_hi_e656 = (value18 | 0xFF00) >> 8;
    x_e656 = (uint16_t)(x_e6c12 + 4);
    y_e656 = value17;
    goto shared_E656;
}

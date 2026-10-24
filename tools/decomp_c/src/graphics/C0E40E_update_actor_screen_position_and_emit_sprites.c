#include "som_c.h"

static void prepare_and_emit_actor_body_sprites(SomCtx *c);
static void prepare_and_emit_actor_body_sprites_v2(SomCtx *c);
static void prepare_and_emit_actor_body_sprites_v3(SomCtx *c);
static void prepare_and_emit_actor_body_sprites_v4(SomCtx *c);
static void sub_C0E5F5(SomCtx *c);
static void sub_C0E5F5_v2(SomCtx *c);
static void sub_C0E5F5_v3(SomCtx *c);
static void sub_C0E5F5_v4(SomCtx *c);
static void emit_packed_actor_sprite_list(SomCtx *c);
static void emit_packed_actor_sprite_list_v2(SomCtx *c);
static void emit_packed_actor_sprite_list_v3(SomCtx *c);
static void emit_packed_actor_sprite_list_v4(SomCtx *c);

/* C0E40E update_actor_screen_position_and_emit_sprites   [class C, 927 bytes, 419 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void update_actor_screen_position_and_emit_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_hi_e45a = 0;
    uint16_t x_e45a = 0;
    uint16_t y_e45a = 0;
    uint8_t a_hi_e42c = 0;
    uint16_t x_e42c = 0;
    uint16_t y_e42c = 0;
    uint8_t a_hi_e46f = 0;
    uint16_t x_e46f = 0;
    uint16_t y_e46f = 0;
    bool carry_e46f = 0;
    bool overflow_e46f = 0;
    uint8_t a_hi_e47c = 0;
    uint16_t x_e47c = 0;
    uint16_t y_e47c = 0;
    bool carry_e47c = 0;
    bool overflow_e47c = 0;
    uint8_t a_e47b = 0;
    uint8_t a_hi_e47b = 0;
    uint16_t x_e47b = 0;
    uint16_t y_e47b = 0;
    bool carry_e47b = 0;
    bool overflow_e47b = 0;
    uint8_t a_hi_e4b2 = 0;
    uint16_t x_e4b2 = 0;
    uint16_t y_e4b2 = 0;
    bool carry_e4b2 = 0;
    bool overflow_e4b2 = 0;
    uint8_t a_hi_e4c1 = 0;
    uint16_t x_e4c1 = 0;
    uint16_t y_e4c1 = 0;
    bool carry_e4c1 = 0;
    bool overflow_e4c1 = 0;
    uint8_t a_hi_e4c12 = 0;
    uint8_t x_e4c12 = 0;
    uint8_t y_e4c12 = 0;
    bool carry_e4c12 = 0;
    bool overflow_e4c12 = 0;
    uint8_t a_hi_e4c13 = 0;
    uint8_t x_e4c13 = 0;
    uint8_t y_e4c13 = 0;
    bool carry_e4c13 = 0;
    bool overflow_e4c13 = 0;
    uint8_t a_hi_e4c14 = 0;
    uint16_t x_e4c14 = 0;
    uint16_t y_e4c14 = 0;
    bool carry_e4c14 = 0;
    bool overflow_e4c14 = 0;
    uint8_t a_e4e8 = 0;
    uint8_t a_hi_e4e8 = 0;
    uint16_t y_e4e8 = 0;
    bool overflow_e4e8 = 0;
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
    uint8_t a_e4e82 = 0;
    uint8_t a_hi_e4e82 = 0;
    uint8_t y_e4e82 = 0;
    bool overflow_e4e82 = 0;
    uint8_t a_hi_e5532 = 0;
    uint8_t x_e5532 = 0;
    uint8_t y_e5532 = 0;
    bool carry_e5532 = 0;
    bool overflow_e5532 = 0;
    uint8_t a_e4f02 = 0;
    uint8_t a_hi_e4f02 = 0;
    uint8_t x_e4f02 = 0;
    uint8_t y_e4f02 = 0;
    bool overflow_e4f02 = 0;
    uint8_t a_e8c6 = 0;
    uint8_t a_hi_e8c6 = 0;
    uint16_t y_e8c6 = 0;
    bool overflow_e8c6 = 0;
    uint16_t direct_page_e8c6 = 0;
    uint8_t data_bank_e8c6 = 0;
    uint8_t a_hi_e527 = 0;
    uint16_t x_e527 = 0;
    uint16_t y_e527 = 0;
    uint8_t a_hi_e511 = 0;
    uint16_t x_e511 = 0;
    uint16_t y_e511 = 0;
    uint8_t a_hi_e89b = 0;
    uint16_t x_e89b = 0;
    bool carry_e89b = 0;
    bool overflow_e89b = 0;
    uint16_t direct_page_e89b = 0;
    uint8_t data_bank_e89b = 0;
    uint8_t a_hi_e89b2 = 0;
    uint16_t x_e89b2 = 0;
    bool carry_e89b2 = 0;
    bool overflow_e89b2 = 0;
    uint16_t direct_page_e89b2 = 0;
    uint8_t data_bank_e89b2 = 0;
    uint8_t a_e8c62 = 0;
    uint8_t a_hi_e8c62 = 0;
    uint8_t y_e8c62 = 0;
    bool overflow_e8c62 = 0;
    uint16_t direct_page_e8c62 = 0;
    uint8_t data_bank_e8c62 = 0;
    uint8_t a_hi_e5272 = 0;
    uint8_t x_e5272 = 0;
    uint8_t y_e5272 = 0;
    uint8_t a_hi_e5112 = 0;
    uint8_t x_e5112 = 0;
    uint8_t y_e5112 = 0;
    uint8_t a_hi_e89b3 = 0;
    uint8_t x_e89b3 = 0;
    bool carry_e89b3 = 0;
    bool overflow_e89b3 = 0;
    uint16_t direct_page_e89b3 = 0;
    uint8_t data_bank_e89b3 = 0;
    uint8_t a_hi_e89b4 = 0;
    uint8_t x_e89b4 = 0;
    bool carry_e89b4 = 0;
    bool overflow_e89b4 = 0;
    uint16_t direct_page_e89b4 = 0;
    uint8_t data_bank_e89b4 = 0;
    uint8_t a_hi_e8d3 = 0;
    uint16_t y_e8d3 = 0;
    bool carry_e8d3 = 0;
    bool overflow_e8d3 = 0;
    uint16_t direct_page_e8d3 = 0;
    uint8_t data_bank_e8d3 = 0;
    uint8_t a_e8c63 = 0;
    uint8_t a_hi_e8c63 = 0;
    uint16_t y_e8c63 = 0;
    bool overflow_e8c63 = 0;
    uint16_t direct_page_e8c63 = 0;
    uint8_t data_bank_e8c63 = 0;
    uint8_t a_hi_e520 = 0;
    uint16_t x_e520 = 0;
    uint16_t y_e520 = 0;
    uint8_t a_e710 = 0;
    uint8_t a_hi_e710 = 0;
    uint16_t x_e710 = 0;
    bool carry_e710 = 0;
    uint8_t a_hi_e8ac = 0;
    uint16_t x_e8ac = 0;
    bool carry_e8ac = 0;
    bool overflow_e8ac = 0;
    uint16_t direct_page_e8ac = 0;
    uint8_t data_bank_e8ac = 0;
    uint8_t a_hi_e8ac2 = 0;
    uint16_t x_e8ac2 = 0;
    bool carry_e8ac2 = 0;
    bool overflow_e8ac2 = 0;
    uint16_t direct_page_e8ac2 = 0;
    uint8_t data_bank_e8ac2 = 0;
    uint8_t a_e8c64 = 0;
    uint8_t a_hi_e8c64 = 0;
    uint8_t y_e8c64 = 0;
    bool overflow_e8c64 = 0;
    uint16_t direct_page_e8c64 = 0;
    uint8_t data_bank_e8c64 = 0;
    uint8_t a_hi_e5202 = 0;
    uint8_t x_e5202 = 0;
    uint8_t y_e5202 = 0;
    uint8_t a_e7102 = 0;
    uint8_t a_hi_e7102 = 0;
    uint8_t x_e7102 = 0;
    bool carry_e7102 = 0;
    uint8_t a_hi_e8ac3 = 0;
    uint8_t x_e8ac3 = 0;
    bool carry_e8ac3 = 0;
    bool overflow_e8ac3 = 0;
    uint16_t direct_page_e8ac3 = 0;
    uint8_t data_bank_e8ac3 = 0;
    uint8_t a_hi_e8ac4 = 0;
    uint8_t x_e8ac4 = 0;
    bool carry_e8ac4 = 0;
    bool overflow_e8ac4 = 0;
    uint16_t direct_page_e8ac4 = 0;
    uint8_t data_bank_e8ac4 = 0;
    uint8_t a_e727 = 0;
    uint8_t a_hi_e727 = 0;
    uint16_t x_e727 = 0;
    uint8_t a_e8bd = 0;
    uint8_t a_hi_e8bd = 0;
    uint16_t x_e8bd = 0;
    uint16_t y_e8bd = 0;
    bool carry_e8bd = 0;
    bool overflow_e8bd = 0;
    uint16_t direct_page_e8bd = 0;
    uint8_t data_bank_e8bd = 0;
    uint8_t a_e8bd2 = 0;
    uint8_t a_hi_e8bd2 = 0;
    uint16_t x_e8bd2 = 0;
    uint16_t y_e8bd2 = 0;
    bool carry_e8bd2 = 0;
    bool overflow_e8bd2 = 0;
    uint16_t direct_page_e8bd2 = 0;
    uint8_t data_bank_e8bd2 = 0;
    uint8_t a_e7272 = 0;
    uint8_t a_hi_e7272 = 0;
    uint8_t x_e7272 = 0;
    uint8_t a_e8bd3 = 0;
    uint8_t a_hi_e8bd3 = 0;
    uint8_t x_e8bd3 = 0;
    uint8_t y_e8bd3 = 0;
    bool carry_e8bd3 = 0;
    bool overflow_e8bd3 = 0;
    uint16_t direct_page_e8bd3 = 0;
    uint8_t data_bank_e8bd3 = 0;
    uint8_t a_e8bd4 = 0;
    uint8_t a_hi_e8bd4 = 0;
    uint8_t x_e8bd4 = 0;
    uint8_t y_e8bd4 = 0;
    bool carry_e8bd4 = 0;
    bool overflow_e8bd4 = 0;
    uint16_t direct_page_e8bd4 = 0;
    uint8_t data_bank_e8bd4 = 0;
    uint8_t a_hi_e73e = 0;
    uint16_t x_e73e = 0;
    uint16_t y_e73e = 0;
    bool carry_e73e = 0;
    uint8_t a_hi_e73e2 = 0;
    uint8_t x_e73e2 = 0;
    uint8_t y_e73e2 = 0;
    bool carry_e73e2 = 0;
    if (!(RAM8(0xE00B + x) & 0x80)) {
        uint16_t value2 = RAM16(0xE002 + x);
        uint16_t value3 = RAM16(0x00A8);
        RAM16_SET(0xE020 + x, (uint16_t)(value2 - value3));
        if (value2 >= value3) {
            a_hi_e45a = (uint16_t)(value2 - value3) >> 8;
            x_e45a = x;
            y_e45a = y;
            goto shared_E45A;
        }
        uint16_t value4 = RAM16(0x00C0);
        if ((uint16_t)((uint16_t)(value2 - value3) + value4 + (value2 >= value3)) >= 0x0180) {
            a_hi_e45a = (uint16_t)((uint16_t)(value2 - value3) + value4 + (value2 >= value3)) >> 8;
            x_e45a = x;
            y_e45a = y;
            goto shared_E45A;
        }
        RAM16_SET(0xE020 + x, (uint16_t)((uint16_t)(value2 - value3) + value4 + (value2 >= value3)));
        a_hi_e45a = (uint16_t)((uint16_t)(value2 - value3) + value4 + (value2 >= value3)) >> 8;
        x_e45a = x;
        y_e45a = y;
        goto shared_E45A;
    }
    uint16_t value5 = RAM16(0xE002 + x);
    uint16_t value6 = RAM16(0x00AC);
    RAM16_SET(0xE020 + x, (uint16_t)(value5 - value6));
    if (value5 >= value6) {
        a_hi_e42c = (uint16_t)(value5 - value6) >> 8;
        x_e42c = x;
        y_e42c = y;
        goto shared_E42C;
    }
    uint16_t value7 = RAM16(0x00C0);
    if ((uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6)) >= 0x0180) {
        a_hi_e42c = (uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6)) >> 8;
        x_e42c = x;
        y_e42c = y;
        goto shared_E42C;
    }
    RAM16_SET(0xE020 + x, (uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6)));
    a_hi_e42c = (uint16_t)((uint16_t)(value5 - value6) + value7 + (value5 >= value6)) >> 8;
    x_e42c = x;
    y_e42c = y;
    shared_E42C:;
    uint16_t value11 = RAM16(0xE004 + x_e42c);
    uint16_t value12 = RAM16(0x00AE);
    RAM16_SET(0xE022 + x_e42c, (uint16_t)(value11 - value12));
    if (value11 >= value12) {
        a_hi_e46f = (uint16_t)(value11 - value12) >> 8;
        x_e46f = x_e42c;
        y_e46f = y_e42c;
        carry_e46f = value11 >= value12;
        overflow_e46f = ((value11 ^ value12) & (value11 ^ (uint16_t)(value11 - value12)) & 0x8000) != 0;
        goto shared_E46F;
    }
    uint16_t value13 = RAM16(0x00C2);
    if ((uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)) >= 0x0140) {
        a_hi_e46f = (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)) >> 8;
        x_e46f = x_e42c;
        y_e46f = y_e42c;
        carry_e46f = (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)) >= 0x0140;
        overflow_e46f = (((uint16_t)(value11 - value12) ^ (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12))) & (value13 ^ (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12))) & 0x8000) != 0;
        goto shared_E46F;
    }
    RAM16_SET(0xE022 + x_e42c, (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)));
    a_hi_e46f = (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)) >> 8;
    x_e46f = x_e42c;
    y_e46f = y_e42c;
    carry_e46f = (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12)) >= 0x0140;
    overflow_e46f = (((uint16_t)(value11 - value12) ^ (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12))) & (value13 ^ (uint16_t)((uint16_t)(value11 - value12) + value13 + (value11 >= value12))) & 0x8000) != 0;
    goto shared_E46F;
    shared_E45A:;
    uint16_t value8 = RAM16(0xE004 + x_e45a);
    uint16_t value9 = RAM16(0x00AA);
    RAM16_SET(0xE022 + x_e45a, (uint16_t)(value8 - value9));
    if (value8 >= value9) {
        a_hi_e46f = (uint16_t)(value8 - value9) >> 8;
        x_e46f = x_e45a;
        y_e46f = y_e45a;
        carry_e46f = value8 >= value9;
        overflow_e46f = ((value8 ^ value9) & (value8 ^ (uint16_t)(value8 - value9)) & 0x8000) != 0;
        goto shared_E46F;
    }
    uint16_t value10 = RAM16(0x00C2);
    if ((uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)) >= 0x0140) {
        a_hi_e46f = (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)) >> 8;
        x_e46f = x_e45a;
        y_e46f = y_e45a;
        carry_e46f = (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)) >= 0x0140;
        overflow_e46f = (((uint16_t)(value8 - value9) ^ (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9))) & (value10 ^ (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9))) & 0x8000) != 0;
        goto shared_E46F;
    }
    RAM16_SET(0xE022 + x_e45a, (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)));
    a_hi_e46f = (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)) >> 8;
    x_e46f = x_e45a;
    y_e46f = y_e45a;
    carry_e46f = (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9)) >= 0x0140;
    overflow_e46f = (((uint16_t)(value8 - value9) ^ (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9))) & (value10 ^ (uint16_t)((uint16_t)(value8 - value9) + value10 + (value8 >= value9))) & 0x8000) != 0;
    goto shared_E46F;
    shared_E46F:;
    uint8_t value14 = RAM8(0xE00F + x_e46f);
    if (value14 == 0) {
        a_hi_e47c = a_hi_e46f;
        x_e47c = x_e46f;
        y_e47c = y_e46f;
        carry_e47c = carry_e46f;
        overflow_e47c = overflow_e46f;
        goto shared_E47C;
    }
    r->a = (a_hi_e46f << 8) | value14;
    r->x = x_e46f;
    r->y = y_e46f;
    r->c = carry_e46f;
    r->z = value14 == 0;
    r->n = value14 & 0x80;
    r->v = overflow_e46f;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE478, 0xC0E382); GUARD_JSR(c, sp_call, 0xE478); } /* advance_actor_sprite_visibility_timer */
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    if (!carry_ret) {
        a_hi_e47c = a_all >> 8;
        x_e47c = x_e46f;
        y_e47c = y_e46f;
        carry_e47c = carry_ret;
        overflow_e47c = overflow_e46f;
        goto shared_E47C;
    }
    a_e47b = (uint8_t)a_all;
    a_hi_e47b = a_all >> 8;
    x_e47b = x_e46f;
    y_e47b = y_e46f;
    carry_e47b = carry_ret;
    overflow_e47b = overflow_e46f;
    goto shared_E47B;
    shared_E47C:;
    uint8_t value15 = RAM8(0xE00E + x_e47c);
    if (value15 == 0) {
        a_hi_e4b2 = a_hi_e47c;
        x_e4b2 = x_e47c;
        y_e4b2 = y_e47c;
        carry_e4b2 = carry_e47c;
        overflow_e4b2 = overflow_e47c;
        goto shared_E4B2;
    }
    if (value15 & 0x80) {
        a_e47b = (uint8_t)(value15 << 1);
        a_hi_e47b = a_hi_e47c;
        x_e47b = x_e47c;
        y_e47b = y_e47c;
        carry_e47b = value15 & 0x80;
        overflow_e47b = overflow_e47c;
        goto shared_E47B;
    }
    if (((uint8_t)(value15 << 1) & 6) == 0) {
        a_hi_e4b2 = a_hi_e47c;
        x_e4b2 = x_e47c;
        y_e4b2 = y_e47c;
        carry_e4b2 = value15 & 0x80;
        overflow_e4b2 = overflow_e47c;
        goto shared_E4B2;
    }
    RAM8(0xE039 + x_e47c)--;
    if (RAM8(0xE039 + x_e47c) != 0) {
        uint8_t value16 = RAM8(0x00F4);
        if (value16 & 0x01) {
            a_hi_e4b2 = a_hi_e47c;
            x_e4b2 = x_e47c;
            y_e4b2 = y_e47c;
            carry_e4b2 = value16 & 0x01;
            overflow_e4b2 = overflow_e47c;
            goto shared_E4B2;
        }
        uint8_t value17 = RAM8(0xE00E + x_e47c);
        RAM8(0x0000 + sp0) = value17;
        RAM8(0xE020 + x_e47c) = (value17 & 1) ^ RAM8(0xE020 + x_e47c);
        uint8_t value19 = RAM8(0x0000 + sp0);
        RAM8(0xE022 + x_e47c) = ((value19 & 2) >> 1) ^ RAM8(0xE022 + x_e47c);
        a_hi_e4b2 = a_hi_e47c;
        x_e4b2 = x_e47c;
        y_e4b2 = y_e47c;
        carry_e4b2 = value19 & 2 & 0x01;
        overflow_e4b2 = overflow_e47c;
        goto shared_E4B2;
    }
    RAM8(0xE00E + x_e47c) &= 0xF0;
    a_hi_e4b2 = a_hi_e47c;
    x_e4b2 = x_e47c;
    y_e4b2 = y_e47c;
    carry_e4b2 = value15 & 0x80;
    overflow_e4b2 = overflow_e47c;
    goto shared_E4B2;
    shared_E47B:;
    r->a = (a_hi_e47b << 8) | a_e47b;
    r->x = x_e47b;
    r->y = y_e47b;
    r->c = carry_e47b;
    r->v = overflow_e47b;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_E4B2:;
    uint8_t value22 = RAM8(0xE061 + x_e4b2);
    if (value22 == 0) {
        a_hi_e4c1 = a_hi_e4b2;
        x_e4c1 = x_e4b2;
        y_e4c1 = y_e4b2;
        carry_e4c1 = carry_e4b2;
        overflow_e4c1 = overflow_e4b2;
        goto shared_E4C1;
    }
    uint8_t value23 = RAM8(0x00ED);
    if (value23 & 0x40) {
        a_hi_e4c1 = a_hi_e4b2;
        x_e4c1 = x_e4b2;
        y_e4c1 = y_e4b2;
        carry_e4c1 = carry_e4b2;
        overflow_e4c1 = value23 & 0x40;
        goto shared_E4C1;
    }
    r->a = (a_hi_e4b2 << 8) | value22;
    r->x = x_e4b2;
    r->y = y_e4b2;
    r->c = carry_e4b2;
    r->z = (value22 & value23) == 0;
    r->n = value23 & 0x80;
    r->v = value23 & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE4C0, 0x02C3C1); GUARD_JSL(c, sp_call, 0xE4C0); } /* emit_three_actor_auxiliary_sprite_records */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret = r->v;
    if (m_ret) {
        if (x_ret) {
            a_hi_e4c12 = a_all2 >> 8;
            x_e4c12 = (uint8_t)x_ret2;
            y_e4c12 = (uint8_t)y_ret;
            carry_e4c12 = carry_ret2;
            overflow_e4c12 = overflow_ret;
            goto shared_E4C1_1;
        } else {
            a_hi_e4c1 = a_all2 >> 8;
            x_e4c1 = x_ret2;
            y_e4c1 = y_ret;
            carry_e4c1 = carry_ret2;
            overflow_e4c1 = overflow_ret;
            goto shared_E4C1;
        }
    } else {
        if (x_ret) {
            a_hi_e4c13 = a_all2 >> 8;
            x_e4c13 = (uint8_t)x_ret2;
            y_e4c13 = (uint8_t)y_ret;
            carry_e4c13 = carry_ret2;
            overflow_e4c13 = overflow_ret;
            goto shared_E4C1_2;
        } else {
            a_hi_e4c14 = a_all2 >> 8;
            x_e4c14 = x_ret2;
            y_e4c14 = y_ret;
            carry_e4c14 = carry_ret2;
            overflow_e4c14 = overflow_ret;
            goto shared_E4C1_3;
        }
    }
    shared_E4C1:;
    uint8_t value24 = RAM8(0xE084 + x_e4c1);
    RAM8(0x0002) = value24 & 0x0F;
    if ((value24 & 0x0F) == 0) {
        a_e4e8 = value24 & 0x0F;
        a_hi_e4e8 = a_hi_e4c1;
        y_e4e8 = y_e4c1;
        overflow_e4e8 = overflow_e4c1;
        goto shared_E4E8;
    }
    uint8_t value25 = RAM8(0x00ED);
    if (value25 & 0x80) {
        uint8_t value26 = RAM8(0xE060 + x_e4c1);
        if (value26 == 0) {
            a_hi_e553 = a_hi_e4c1;
            x_e553 = x_e4c1;
            y_e553 = y_e4c1;
            carry_e553 = carry_e4c1;
            overflow_e553 = value25 & 0x40;
            goto shared_E553;
        }
        a_e4f0 = value26;
        a_hi_e4f0 = a_hi_e4c1;
        x_e4f0 = x_e4c1;
        y_e4f0 = y_e4c1;
        overflow_e4f0 = value25 & 0x40;
        goto shared_E4F0;
    }
    if (value25 & 0x40) {
        a_e4e8 = value24 & 0x0F;
        a_hi_e4e8 = a_hi_e4c1;
        y_e4e8 = y_e4c1;
        overflow_e4e8 = value25 & 0x40;
        goto shared_E4E8;
    }
    if (x_e4c1 >= 0x0600) {
        a_e4e8 = value24 & 0x0F;
        a_hi_e4e8 = a_hi_e4c1;
        y_e4e8 = y_e4c1;
        overflow_e4e8 = value25 & 0x40;
        goto shared_E4E8;
    }
    if (RAM8(0xE02F + x_e4c1) != 0) {
        a_hi_e553 = a_hi_e4c1;
        x_e553 = x_e4c1;
        y_e553 = y_e4c1;
        carry_e553 = x_e4c1 >= 0x0600;
        overflow_e553 = value25 & 0x40;
        goto shared_E553;
    }
    uint8_t value28 = RAM8(0xE060 + x_e4c1);
    if (value28 != 0) {
        a_e4f0 = value28;
        a_hi_e4f0 = a_hi_e4c1;
        x_e4f0 = x_e4c1;
        y_e4f0 = y_e4c1;
        overflow_e4f0 = value25 & 0x40;
        goto shared_E4F0;
    }
    uint8_t value29 = RAM8(ACTOR_STATUS_HIGH + x_e4c1);
    if ((value29 & 0xC5) != 0) {
        a_hi_e553 = a_hi_e4c1;
        x_e553 = x_e4c1;
        y_e553 = y_e4c1;
        carry_e553 = x_e4c1 >= 0x0600;
        overflow_e553 = value25 & 0x40;
        goto shared_E553;
    }
    a_e4e8 = value29;
    a_hi_e4e8 = a_hi_e4c1;
    y_e4e8 = y_e4c1;
    overflow_e4e8 = value25 & 0x40;
    goto shared_E4E8;
    shared_E4C1_1:;
    uint8_t value30 = RAM8(0xE084 + x_e4c12);
    RAM8(0x0002) = value30 & 0x0F;
    if ((value30 & 0x0F) == 0) {
        a_e4e82 = value30 & 0x0F;
        a_hi_e4e82 = a_hi_e4c12;
        y_e4e82 = y_e4c12;
        overflow_e4e82 = overflow_e4c12;
        goto shared_E4E8_1;
    }
    uint8_t value31 = RAM8(0x00ED);
    if (value31 & 0x80) {
        uint8_t value32 = RAM8(0xE060 + x_e4c12);
        if (value32 == 0) {
            a_hi_e5532 = a_hi_e4c12;
            x_e5532 = x_e4c12;
            y_e5532 = y_e4c12;
            carry_e5532 = carry_e4c12;
            overflow_e5532 = value31 & 0x40;
            goto shared_E553_1;
        }
        a_e4f02 = value32;
        a_hi_e4f02 = a_hi_e4c12;
        x_e4f02 = x_e4c12;
        y_e4f02 = y_e4c12;
        overflow_e4f02 = value31 & 0x40;
        goto shared_E4F0_1;
    }
    if (value31 & 0x40) {
        a_e4e82 = value30 & 0x0F;
        a_hi_e4e82 = a_hi_e4c12;
        y_e4e82 = y_e4c12;
        overflow_e4e82 = value31 & 0x40;
        goto shared_E4E8_1;
    }
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_E4C1_2:;
    uint8_t value33 = RAM8(0xE084 + x_e4c13);
    RAM8(0x0002) = value33 & 0x0F;
    if ((value33 & 0x0F) == 0) {
        a_e4e82 = value33 & 0x0F;
        a_hi_e4e82 = a_hi_e4c13;
        y_e4e82 = y_e4c13;
        overflow_e4e82 = overflow_e4c13;
        goto shared_E4E8_1;
    }
    uint8_t value34 = RAM8(0x00ED);
    if (value34 & 0x80) {
        uint8_t value35 = RAM8(0xE060 + x_e4c13);
        if (value35 == 0) {
            a_hi_e5532 = a_hi_e4c13;
            x_e5532 = x_e4c13;
            y_e5532 = y_e4c13;
            carry_e5532 = carry_e4c13;
            overflow_e5532 = value34 & 0x40;
            goto shared_E553_1;
        }
        a_e4f02 = value35;
        a_hi_e4f02 = a_hi_e4c13;
        x_e4f02 = x_e4c13;
        y_e4f02 = y_e4c13;
        overflow_e4f02 = value34 & 0x40;
        goto shared_E4F0_1;
    }
    if (value34 & 0x40) {
        a_e4e82 = value33 & 0x0F;
        a_hi_e4e82 = a_hi_e4c13;
        y_e4e82 = y_e4c13;
        overflow_e4e82 = value34 & 0x40;
        goto shared_E4E8_1;
    }
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_E4C1_3:;
    uint8_t value36 = RAM8(0xE084 + x_e4c14);
    RAM8(0x0002) = value36 & 0x0F;
    if ((value36 & 0x0F) == 0) {
        a_e4e8 = value36 & 0x0F;
        a_hi_e4e8 = a_hi_e4c14;
        y_e4e8 = y_e4c14;
        overflow_e4e8 = overflow_e4c14;
        goto shared_E4E8;
    }
    uint8_t value37 = RAM8(0x00ED);
    if (value37 & 0x80) {
        uint8_t value38 = RAM8(0xE060 + x_e4c14);
        if (value38 == 0) {
            a_hi_e553 = a_hi_e4c14;
            x_e553 = x_e4c14;
            y_e553 = y_e4c14;
            carry_e553 = carry_e4c14;
            overflow_e553 = value37 & 0x40;
            goto shared_E553;
        }
        a_e4f0 = value38;
        a_hi_e4f0 = a_hi_e4c14;
        x_e4f0 = x_e4c14;
        y_e4f0 = y_e4c14;
        overflow_e4f0 = value37 & 0x40;
        goto shared_E4F0;
    }
    if (value37 & 0x40) {
        a_e4e8 = value36 & 0x0F;
        a_hi_e4e8 = a_hi_e4c14;
        y_e4e8 = y_e4c14;
        overflow_e4e8 = value37 & 0x40;
        goto shared_E4E8;
    }
    if (x_e4c14 >= 0x0600) {
        a_e4e8 = value36 & 0x0F;
        a_hi_e4e8 = a_hi_e4c14;
        y_e4e8 = y_e4c14;
        overflow_e4e8 = value37 & 0x40;
        goto shared_E4E8;
    }
    if (RAM8(0xE02F + x_e4c14) != 0) {
        a_hi_e553 = a_hi_e4c14;
        x_e553 = x_e4c14;
        y_e553 = y_e4c14;
        carry_e553 = x_e4c14 >= 0x0600;
        overflow_e553 = value37 & 0x40;
        goto shared_E553;
    }
    uint8_t value40 = RAM8(0xE060 + x_e4c14);
    if (value40 != 0) {
        a_e4f0 = value40;
        a_hi_e4f0 = a_hi_e4c14;
        x_e4f0 = x_e4c14;
        y_e4f0 = y_e4c14;
        overflow_e4f0 = value37 & 0x40;
        goto shared_E4F0;
    }
    uint8_t value41 = RAM8(ACTOR_STATUS_HIGH + x_e4c14);
    if ((value41 & 0xC5) != 0) {
        a_hi_e553 = a_hi_e4c14;
        x_e553 = x_e4c14;
        y_e553 = y_e4c14;
        carry_e553 = x_e4c14 >= 0x0600;
        overflow_e553 = value37 & 0x40;
        goto shared_E553;
    }
    a_e4e8 = value41;
    a_hi_e4e8 = a_hi_e4c14;
    y_e4e8 = y_e4c14;
    overflow_e4e8 = value37 & 0x40;
    goto shared_E4E8;
    shared_E4E8:;
    a_e8c6 = a_e4e8;
    a_hi_e8c6 = a_hi_e4e8;
    y_e8c6 = y_e4e8;
    overflow_e8c6 = overflow_e4e8;
    direct_page_e8c6 = 0;
    data_bank_e8c6 = 0x7E;
    goto shared_E8C6;
    shared_E553:;
    uint8_t value42 = RAM8(0xE024 + x_e553);
    if (!(value42 & 0x80)) {
        r->a = (a_hi_e553 << 8) | value42;
        r->x = x_e553;
        r->y = y_e553;
        r->c = carry_e553;
        r->z = value42 == 0;
        r->n = value42 & 0x80;
        r->v = overflow_e553;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE567, prepare_and_emit_actor_body_sprites, sp_in, 2); GUARD_JSR(c, sp_call, 0xE567); }
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        uint16_t value43 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x14));
        uint16_t value44 = BUS16_RDP(c, (db_ret << 0x10) + 0xE084 + value43);
        BUS16_SET(c, (uint16_t)(dp_ret + 2), value44 & 0x0F);
        r->a = value43 | 0xE0D0;
        r->x = value43;
        r->y = value43 | 0xE0D0;
        r->z = (value43 | 0xE0D0) == 0;
        r->n = (value43 | 0xE0D0) & 0x8000;
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
        if (a_e4f0 == 0x40) {
            a_hi_e527 = a_hi_e4f0;
            x_e527 = x_e4f0;
            y_e527 = y_e4f0;
            goto shared_E527;
        }
        if (a_e4f0 == 0x80) {
            a_hi_e527 = a_hi_e4f0;
            x_e527 = x_e4f0;
            y_e527 = y_e4f0;
            goto shared_E527;
        }
        if ((RAM8(0xE00E + x_e4f0) & 0x20) == 0) {
            a_hi_e511 = a_hi_e4f0;
            x_e511 = x_e4f0;
            y_e511 = y_e4f0;
            goto shared_E511;
        }
        uint8_t value46 = RAM8(0x00F4);
        if (!(value46 & 0x01)) {
            a_hi_e511 = a_hi_e4f0;
            x_e511 = x_e4f0;
            y_e511 = y_e4f0;
            goto shared_E511;
        }
        if (value46 & 0x01) {
            a_e4e8 = value46 >> 1;
            a_hi_e4e8 = a_hi_e4f0;
            y_e4e8 = y_e4f0;
            overflow_e4e8 = overflow_e4f0;
            goto shared_E4E8;
        }
        a_hi_e511 = a_hi_e4f0;
        x_e511 = x_e4f0;
        y_e511 = y_e4f0;
        goto shared_E511;
    }
    uint16_t value47 = RAM16(0x0014);
    r->a = value47;
    r->x = x_e4f0;
    r->y = value47;
    r->c = a_e4f0 >= 0xE0;
    r->z = value47 == 0;
    r->n = value47 & 0x8000;
    r->v = overflow_e4f0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE895, 0x019106); GUARD_JSL(c, sp_call, 0xE895); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret4 = r->mf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret5 = r->x;
    bool carry_ret5 = r->c;
    bool overflow_ret4 = r->v;
    if (!carry_ret5) {
        if (m_ret4) {
            a_hi_e89b = a_all5 >> 8;
            x_e89b = x_ret5;
            carry_e89b = carry_ret5;
            overflow_e89b = overflow_ret4;
            direct_page_e89b = 0;
            data_bank_e89b = 0x7E;
            goto shared_E89B;
        } else {
            a_hi_e89b2 = a_all5 >> 8;
            x_e89b2 = x_ret5;
            carry_e89b2 = carry_ret5;
            overflow_e89b2 = overflow_ret4;
            direct_page_e89b2 = 0;
            data_bank_e89b2 = 0x7E;
            goto shared_E89B_1;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE89A, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE89A); }
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool m_ret5 = r->mf;
    uint16_t a_all6 = r->a;
    uint16_t x_ret6 = r->x;
    bool carry_ret6 = r->c;
    bool overflow_ret5 = r->v;
    if (m_ret5) {
        a_hi_e89b = a_all6 >> 8;
        x_e89b = x_ret6;
        carry_e89b = carry_ret6;
        overflow_e89b = overflow_ret5;
        direct_page_e89b = dp_ret3;
        data_bank_e89b = db_ret3;
        goto shared_E89B;
    } else {
        a_hi_e89b2 = a_all6 >> 8;
        x_e89b2 = x_ret6;
        carry_e89b2 = carry_ret6;
        overflow_e89b2 = overflow_ret5;
        direct_page_e89b2 = dp_ret3;
        data_bank_e89b2 = db_ret3;
        goto shared_E89B_1;
    }
    shared_E4E8_1:;
    a_e8c62 = a_e4e82;
    a_hi_e8c62 = a_hi_e4e82;
    y_e8c62 = y_e4e82;
    overflow_e8c62 = overflow_e4e82;
    direct_page_e8c62 = 0;
    data_bank_e8c62 = 0x7E;
    goto shared_E8C6_1;
    shared_E553_1:;
    uint8_t value48 = RAM8(0xE024 + x_e5532);
    if (!(value48 & 0x80)) {
        r->a = (a_hi_e5532 << 8) | value48;
        r->x = x_e5532;
        r->y = y_e5532;
        r->c = carry_e5532;
        r->z = value48 == 0;
        r->n = value48 & 0x80;
        r->v = overflow_e5532;
        r->mf = 1;
        r->xf = 1;
        r->db = 0x7E;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE567, prepare_and_emit_actor_body_sprites_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xE567); }
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        uint8_t value49 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 0x14));
        uint16_t value50 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xE084 + value49);
        BUS16_SET(c, (uint16_t)(dp_ret4 + 2), value50 & 0x0F);
        r->a = value49 | 0xE0D0;
        r->x = value49;
        r->y = (uint8_t)(value49 | 0xE0D0);
        r->z = (uint8_t)(value49 | 0xE0D0) == 0;
        r->n = (uint8_t)(value49 | 0xE0D0) & 0x80;
        r->mf = 0;
        r->xf = 1;
        sub_C0E5F5_v3(c); return;
    }
    r->a = x_e5532 | 0xE0D0;
    r->x = x_e5532;
    r->y = (uint8_t)(x_e5532 | 0xE0D0);
    r->c = carry_e5532;
    r->z = (uint8_t)(x_e5532 | 0xE0D0) == 0;
    r->n = (uint8_t)(x_e5532 | 0xE0D0) & 0x80;
    r->v = overflow_e5532;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE561, sub_C0E5F5_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xE561); }
    r->xf = 1;
    prepare_and_emit_actor_body_sprites_v4(c); return;
    shared_E4F0_1:;
    if (a_e4f02 != 0xE0) {
        if (a_e4f02 == 0x20) {
            a_hi_e5532 = a_hi_e4f02;
            x_e5532 = x_e4f02;
            y_e5532 = y_e4f02;
            carry_e5532 = a_e4f02 >= 0x20;
            overflow_e5532 = overflow_e4f02;
            goto shared_E553_1;
        }
        if (a_e4f02 == 0x40) {
            a_hi_e5272 = a_hi_e4f02;
            x_e5272 = x_e4f02;
            y_e5272 = y_e4f02;
            goto shared_E527_1;
        }
        if (a_e4f02 == 0x80) {
            a_hi_e5272 = a_hi_e4f02;
            x_e5272 = x_e4f02;
            y_e5272 = y_e4f02;
            goto shared_E527_1;
        }
        if ((RAM8(0xE00E + x_e4f02) & 0x20) == 0) {
            a_hi_e5112 = a_hi_e4f02;
            x_e5112 = x_e4f02;
            y_e5112 = y_e4f02;
            goto shared_E511_1;
        }
        uint8_t value52 = RAM8(0x00F4);
        if (!(value52 & 0x01)) {
            a_hi_e5112 = a_hi_e4f02;
            x_e5112 = x_e4f02;
            y_e5112 = y_e4f02;
            goto shared_E511_1;
        }
        if (value52 & 0x01) {
            a_e4e82 = value52 >> 1;
            a_hi_e4e82 = a_hi_e4f02;
            y_e4e82 = y_e4f02;
            overflow_e4e82 = overflow_e4f02;
            goto shared_E4E8_1;
        }
        a_hi_e5112 = a_hi_e4f02;
        x_e5112 = x_e4f02;
        y_e5112 = y_e4f02;
        goto shared_E511_1;
    }
    uint16_t value53 = RAM16(0x0014);
    r->a = value53;
    r->x = x_e4f02;
    r->y = (uint8_t)value53;
    r->c = a_e4f02 >= 0xE0;
    r->z = (uint8_t)value53 == 0;
    r->n = (uint8_t)value53 & 0x80;
    r->v = overflow_e4f02;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE895, 0x019106); GUARD_JSL(c, sp_call, 0xE895); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret8 = r->mf;
    uint16_t a_all9 = r->a;
    uint8_t x_ret9 = r->x;
    bool carry_ret9 = r->c;
    bool overflow_ret8 = r->v;
    if (!carry_ret9) {
        if (m_ret8) {
            a_hi_e89b3 = a_all9 >> 8;
            x_e89b3 = x_ret9;
            carry_e89b3 = carry_ret9;
            overflow_e89b3 = overflow_ret8;
            direct_page_e89b3 = 0;
            data_bank_e89b3 = 0x7E;
            goto shared_E89B_2;
        } else {
            a_hi_e89b4 = a_all9 >> 8;
            x_e89b4 = x_ret9;
            carry_e89b4 = carry_ret9;
            overflow_e89b4 = overflow_ret8;
            direct_page_e89b4 = 0;
            data_bank_e89b4 = 0x7E;
            goto shared_E89B_3;
        }
    }
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE89A, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE89A); }
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool m_ret9 = r->mf;
    uint16_t a_all10 = r->a;
    uint8_t x_ret10 = r->x;
    bool carry_ret10 = r->c;
    bool overflow_ret9 = r->v;
    if (m_ret9) {
        a_hi_e89b3 = a_all10 >> 8;
        x_e89b3 = x_ret10;
        carry_e89b3 = carry_ret10;
        overflow_e89b3 = overflow_ret9;
        direct_page_e89b3 = dp_ret6;
        data_bank_e89b3 = db_ret6;
        goto shared_E89B_2;
    } else {
        a_hi_e89b4 = a_all10 >> 8;
        x_e89b4 = x_ret10;
        carry_e89b4 = carry_ret10;
        overflow_e89b4 = overflow_ret9;
        direct_page_e89b4 = dp_ret6;
        data_bank_e89b4 = db_ret6;
        goto shared_E89B_3;
    }
    shared_E8C6:;
    uint16_t value54 = BUS16_RDP(c, (uint16_t)(direct_page_e8c6 + 0x14));
    if (value54 < 0x0600) {
        a_hi_e8d3 = a_hi_e8c6;
        y_e8d3 = y_e8c6;
        carry_e8d3 = value54 >= 0x0600;
        overflow_e8d3 = overflow_e8c6;
        direct_page_e8d3 = direct_page_e8c6;
        data_bank_e8d3 = data_bank_e8c6;
        goto shared_E8D3;
    }
    uint8_t value55 = BUS8_RDP(c, (uint16_t)(direct_page_e8c6 + 0x5C));
    if (value55 & 0x80) {
        r->a = (a_hi_e8c6 << 8) | a_e8c6;
        r->x = value54;
        r->y = y_e8c6;
        r->c = value54 >= 0x0600;
        r->v = value55 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_e8c6;
        r->dp = direct_page_e8c6;
        RETURN_RTS(c);
    }
    a_hi_e8d3 = a_hi_e8c6;
    y_e8d3 = y_e8c6;
    carry_e8d3 = value54 >= 0x0600;
    overflow_e8d3 = value55 & 0x40;
    direct_page_e8d3 = direct_page_e8c6;
    data_bank_e8d3 = data_bank_e8c6;
    goto shared_E8D3;
    shared_E527:;
    RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e527) + RAM16(0xE020 + x_e527)));
    uint16_t value58 = RAM16(0xE074 + x_e527);
    uint16_t value59 = RAM16(0xE045 + x_e527);
    uint16_t value60 = RAM16(0xE11A + x_e527);
    uint16_t value61 = RAM16(0xE022 + x_e527);
    RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1) + value61 + (((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1 > 0xFFFF)));
    r->a = x_e527 | 0xE0D0;
    r->x = x_e527 | 0xE0D0;
    r->y = y_e527;
    r->c = (uint16_t)(((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1) + value61 + (((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1 > 0xFFFF) > 0xFFFF;
    r->z = (x_e527 | 0xE0D0) == 0;
    r->n = (x_e527 | 0xE0D0) & 0x8000;
    r->v = (((uint16_t)(((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1) + value61 + (((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1 > 0xFFFF))) & (value61 ^ (uint16_t)((uint16_t)(((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1) + value61 + (((uint16_t)((value58 & 0x7F) + value59) ^ 0xFFFF) + value60 + 1 > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool m_ret10 = r->mf;
    uint16_t a_all11 = r->a;
    uint16_t y_ret8 = r->y;
    bool overflow_ret10 = r->v;
    if (m_ret10) {
        a_e8c6 = (uint8_t)a_all11;
        a_hi_e8c6 = a_all11 >> 8;
        y_e8c6 = y_ret8;
        overflow_e8c6 = overflow_ret10;
        direct_page_e8c6 = dp_ret7;
        data_bank_e8c6 = db_ret7;
        goto shared_E8C6;
    } else {
        a_e8c63 = (uint8_t)a_all11;
        a_hi_e8c63 = a_all11 >> 8;
        y_e8c63 = y_ret8;
        overflow_e8c63 = overflow_ret10;
        direct_page_e8c63 = dp_ret7;
        data_bank_e8c63 = db_ret7;
        goto shared_E8C6_2;
    }
    shared_E511:;
    uint8_t value62 = RAM8(0xE110 + x_e511);
    if (value62 < 5) {
        a_hi_e520 = a_hi_e511;
        x_e520 = x_e511;
        y_e520 = y_e511;
        goto shared_E520;
    }
    if (!(RAM8(0xE114 + x_e511) & 0x40)) {
        a_hi_e520 = a_hi_e511;
        x_e520 = x_e511;
        y_e520 = y_e511;
        goto shared_E520;
    }
    if (value62 != 5) {
        uint8_t value64 = RAM8(0xE116 + x_e511);
        RAM8(0x0000 + sp0) = value64;
        if ((value64 & 0x0F) < 6) {
            a_e710 = value64 & 0x0F;
            a_hi_e710 = a_hi_e511;
            x_e710 = x_e511;
            carry_e710 = (value64 & 0x0F) >= 6;
            goto shared_E710;
        }
        a_e710 = 5;
        a_hi_e710 = a_hi_e511;
        x_e710 = x_e511;
        carry_e710 = (value64 & 0x0F) >= 6;
        goto shared_E710;
    }
    uint16_t value65 = RAM16(0x0014);
    RAM8(0x0002) = RAM8(0xE116 + value65) & 0x0F;
    RAM16_SET(0x0004, RAM16(0xE020 + value65));
    uint16_t value68 = RAM16(0xE074 + value65);
    uint16_t value69 = RAM16(0xE045 + value65);
    uint16_t value70 = RAM16(0xE022 + value65);
    RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value70 + ((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF)));
    r->a = value65 | 0xE0D0;
    r->x = value65 | 0xE0D0;
    r->y = y_e511;
    r->c = ((uint16_t)((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value70 + ((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF) > 0xFFFF;
    r->z = (value65 | 0xE0D0) == 0;
    r->n = (value65 | 0xE0D0) & 0x8000;
    r->v = (((uint16_t)((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value70 + ((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & (value70 ^ (uint16_t)(((uint16_t)((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value70 + ((value68 & 0x7F) + 0x60 + value69 + ((value68 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE700, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE700); }
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    bool m_ret11 = r->mf;
    uint16_t a_all12 = r->a;
    uint16_t y_ret9 = r->y;
    bool overflow_ret11 = r->v;
    if (m_ret11) {
        a_e8c6 = (uint8_t)a_all12;
        a_hi_e8c6 = a_all12 >> 8;
        y_e8c6 = y_ret9;
        overflow_e8c6 = overflow_ret11;
        direct_page_e8c6 = dp_ret8;
        data_bank_e8c6 = db_ret8;
        goto shared_E8C6;
    } else {
        a_e8c63 = (uint8_t)a_all12;
        a_hi_e8c63 = a_all12 >> 8;
        y_e8c63 = y_ret9;
        overflow_e8c63 = overflow_ret11;
        direct_page_e8c63 = dp_ret8;
        data_bank_e8c63 = db_ret8;
        goto shared_E8C6_2;
    }
    shared_E89B:;
    uint16_t value71 = BUS16_RDP(c, (uint16_t)(direct_page_e89b + 0x14));
    r->a = value71 | 0x10;
    r->x = x_e89b;
    r->y = value71 | 0x10;
    r->c = carry_e89b;
    r->z = (value71 | 0x10) == 0;
    r->n = (value71 | 0x10) & 0x8000;
    r->v = overflow_e89b;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_e89b;
    r->dp = direct_page_e89b;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8A6, 0x019106); GUARD_JSL(c, sp_call, 0xE8A6); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret12 = r->mf;
    uint16_t a_all13 = r->a;
    uint16_t x_ret13 = r->x;
    bool carry_ret13 = r->c;
    bool overflow_ret12 = r->v;
    if (!carry_ret13) {
        if (m_ret12) {
            a_hi_e8ac = a_all13 >> 8;
            x_e8ac = x_ret13;
            carry_e8ac = carry_ret13;
            overflow_e8ac = overflow_ret12;
            direct_page_e8ac = direct_page_e89b;
            data_bank_e8ac = data_bank_e89b;
            goto shared_E8AC;
        } else {
            a_hi_e8ac2 = a_all13 >> 8;
            x_e8ac2 = x_ret13;
            carry_e8ac2 = carry_ret13;
            overflow_e8ac2 = overflow_ret12;
            direct_page_e8ac2 = direct_page_e89b;
            data_bank_e8ac2 = data_bank_e89b;
            goto shared_E8AC_1;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8AB, emit_packed_actor_sprite_list_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8AB); }
    uint16_t dp_ret9 = r->dp;
    uint8_t db_ret9 = r->db;
    bool m_ret13 = r->mf;
    uint16_t a_all14 = r->a;
    uint16_t x_ret14 = r->x;
    bool carry_ret14 = r->c;
    bool overflow_ret13 = r->v;
    if (m_ret13) {
        a_hi_e8ac = a_all14 >> 8;
        x_e8ac = x_ret14;
        carry_e8ac = carry_ret14;
        overflow_e8ac = overflow_ret13;
        direct_page_e8ac = dp_ret9;
        data_bank_e8ac = db_ret9;
        goto shared_E8AC;
    } else {
        a_hi_e8ac2 = a_all14 >> 8;
        x_e8ac2 = x_ret14;
        carry_e8ac2 = carry_ret14;
        overflow_e8ac2 = overflow_ret13;
        direct_page_e8ac2 = dp_ret9;
        data_bank_e8ac2 = db_ret9;
        goto shared_E8AC_1;
    }
    shared_E89B_1:;
    uint16_t value72 = BUS16_RDP(c, (uint16_t)(direct_page_e89b2 + 0x14));
    r->a = value72 | 0x10;
    r->x = x_e89b2;
    r->y = value72 | 0x10;
    r->c = carry_e89b2;
    r->z = (value72 | 0x10) == 0;
    r->n = (value72 | 0x10) & 0x8000;
    r->v = overflow_e89b2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_e89b2;
    r->dp = direct_page_e89b2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8A6, 0x019106); GUARD_JSL(c, sp_call, 0xE8A6); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret14 = r->mf;
    uint16_t a_all15 = r->a;
    uint16_t x_ret15 = r->x;
    bool carry_ret15 = r->c;
    bool overflow_ret14 = r->v;
    if (!carry_ret15) {
        if (m_ret14) {
            a_hi_e8ac = a_all15 >> 8;
            x_e8ac = x_ret15;
            carry_e8ac = carry_ret15;
            overflow_e8ac = overflow_ret14;
            direct_page_e8ac = direct_page_e89b2;
            data_bank_e8ac = data_bank_e89b2;
            goto shared_E8AC;
        } else {
            a_hi_e8ac2 = a_all15 >> 8;
            x_e8ac2 = x_ret15;
            carry_e8ac2 = carry_ret15;
            overflow_e8ac2 = overflow_ret14;
            direct_page_e8ac2 = direct_page_e89b2;
            data_bank_e8ac2 = data_bank_e89b2;
            goto shared_E8AC_1;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8AB, emit_packed_actor_sprite_list_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8AB); }
    uint16_t dp_ret10 = r->dp;
    uint8_t db_ret10 = r->db;
    bool m_ret15 = r->mf;
    uint16_t a_all16 = r->a;
    uint16_t x_ret16 = r->x;
    bool carry_ret16 = r->c;
    bool overflow_ret15 = r->v;
    if (m_ret15) {
        a_hi_e8ac = a_all16 >> 8;
        x_e8ac = x_ret16;
        carry_e8ac = carry_ret16;
        overflow_e8ac = overflow_ret15;
        direct_page_e8ac = dp_ret10;
        data_bank_e8ac = db_ret10;
        goto shared_E8AC;
    } else {
        a_hi_e8ac2 = a_all16 >> 8;
        x_e8ac2 = x_ret16;
        carry_e8ac2 = carry_ret16;
        overflow_e8ac2 = overflow_ret15;
        direct_page_e8ac2 = dp_ret10;
        data_bank_e8ac2 = db_ret10;
        goto shared_E8AC_1;
    }
    shared_E8C6_1:;
    uint8_t value73 = BUS8_RDP(c, (uint16_t)(direct_page_e8c62 + 0x14));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_E527_1:;
    RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e5272) + RAM16(0xE020 + x_e5272)));
    uint16_t value76 = RAM16(0xE074 + x_e5272);
    uint16_t value77 = RAM16(0xE045 + x_e5272);
    uint16_t value78 = RAM16(0xE11A + x_e5272);
    uint16_t value79 = RAM16(0xE022 + x_e5272);
    RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1) + value79 + (((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1 > 0xFFFF)));
    r->a = x_e5272 | 0xE0D0;
    r->x = (uint8_t)(x_e5272 | 0xE0D0);
    r->y = y_e5272;
    r->c = (uint16_t)(((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1) + value79 + (((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1 > 0xFFFF) > 0xFFFF;
    r->z = (uint8_t)(x_e5272 | 0xE0D0) == 0;
    r->n = (uint8_t)(x_e5272 | 0xE0D0) & 0x80;
    r->v = (((uint16_t)(((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1) + value79 + (((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1 > 0xFFFF))) & (value79 ^ (uint16_t)((uint16_t)(((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1) + value79 + (((uint16_t)((value76 & 0x7F) + value77) ^ 0xFFFF) + value78 + 1 > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE54F, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE54F); }
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret11 = r->db;
    bool m_ret16 = r->mf;
    uint16_t a_all17 = r->a;
    uint8_t y_ret12 = r->y;
    bool overflow_ret16 = r->v;
    if (m_ret16) {
        a_e8c62 = (uint8_t)a_all17;
        a_hi_e8c62 = a_all17 >> 8;
        y_e8c62 = y_ret12;
        overflow_e8c62 = overflow_ret16;
        direct_page_e8c62 = dp_ret11;
        data_bank_e8c62 = db_ret11;
        goto shared_E8C6_1;
    } else {
        a_e8c64 = (uint8_t)a_all17;
        a_hi_e8c64 = a_all17 >> 8;
        y_e8c64 = y_ret12;
        overflow_e8c64 = overflow_ret16;
        direct_page_e8c64 = dp_ret11;
        data_bank_e8c64 = db_ret11;
        goto shared_E8C6_3;
    }
    shared_E511_1:;
    uint8_t value80 = RAM8(0xE110 + x_e5112);
    if (value80 < 5) {
        a_hi_e5202 = a_hi_e5112;
        x_e5202 = x_e5112;
        y_e5202 = y_e5112;
        goto shared_E520_1;
    }
    if (!(RAM8(0xE114 + x_e5112) & 0x40)) {
        a_hi_e5202 = a_hi_e5112;
        x_e5202 = x_e5112;
        y_e5202 = y_e5112;
        goto shared_E520_1;
    }
    if (value80 != 5) {
        uint8_t value82 = RAM8(0xE116 + x_e5112);
        RAM8(0x0000 + sp0) = value82;
        if ((value82 & 0x0F) < 6) {
            a_e7102 = value82 & 0x0F;
            a_hi_e7102 = a_hi_e5112;
            x_e7102 = x_e5112;
            carry_e7102 = (value82 & 0x0F) >= 6;
            goto shared_E710_1;
        }
        a_e7102 = 5;
        a_hi_e7102 = a_hi_e5112;
        x_e7102 = x_e5112;
        carry_e7102 = (value82 & 0x0F) >= 6;
        goto shared_E710_1;
    }
    uint8_t value83 = RAM8(0x0014);
    RAM8(0x0002) = RAM8(0xE116 + value83) & 0x0F;
    RAM16_SET(0x0004, RAM16(0xE020 + value83));
    uint16_t value86 = RAM16(0xE074 + value83);
    uint16_t value87 = RAM16(0xE045 + value83);
    uint16_t value88 = RAM16(0xE022 + value83);
    RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value88 + ((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF)));
    uint16_t value89 = RAM16(0x0014);
    r->a = value89 | 0xE0D0;
    r->x = (uint8_t)(value89 | 0xE0D0);
    r->y = y_e5112;
    r->c = ((uint16_t)((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value88 + ((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF) > 0xFFFF;
    r->z = (uint8_t)(value89 | 0xE0D0) == 0;
    r->n = (uint8_t)(value89 | 0xE0D0) & 0x80;
    r->v = (((uint16_t)((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value88 + ((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & (value88 ^ (uint16_t)(((uint16_t)((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF)) ^ 0xFFFF) + value88 + ((value86 & 0x7F) + 0x60 + value87 + ((value86 & 0x7F) + 0x60 > 0xFFFF) > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE700, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE700); }
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    bool m_ret17 = r->mf;
    uint16_t a_all18 = r->a;
    uint8_t y_ret13 = r->y;
    bool overflow_ret17 = r->v;
    if (m_ret17) {
        a_e8c62 = (uint8_t)a_all18;
        a_hi_e8c62 = a_all18 >> 8;
        y_e8c62 = y_ret13;
        overflow_e8c62 = overflow_ret17;
        direct_page_e8c62 = dp_ret12;
        data_bank_e8c62 = db_ret12;
        goto shared_E8C6_1;
    } else {
        a_e8c64 = (uint8_t)a_all18;
        a_hi_e8c64 = a_all18 >> 8;
        y_e8c64 = y_ret13;
        overflow_e8c64 = overflow_ret17;
        direct_page_e8c64 = dp_ret12;
        data_bank_e8c64 = db_ret12;
        goto shared_E8C6_3;
    }
    shared_E89B_2:;
    uint16_t value90 = BUS16_RDP(c, (uint16_t)(direct_page_e89b3 + 0x14));
    r->a = value90 | 0x10;
    r->x = x_e89b3;
    r->y = (uint8_t)(value90 | 0x10);
    r->c = carry_e89b3;
    r->z = (uint8_t)(value90 | 0x10) == 0;
    r->n = (uint8_t)(value90 | 0x10) & 0x80;
    r->v = overflow_e89b3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_e89b3;
    r->dp = direct_page_e89b3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8A6, 0x019106); GUARD_JSL(c, sp_call, 0xE8A6); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret18 = r->mf;
    uint16_t a_all19 = r->a;
    uint8_t x_ret19 = r->x;
    bool carry_ret19 = r->c;
    bool overflow_ret18 = r->v;
    if (!carry_ret19) {
        if (m_ret18) {
            a_hi_e8ac3 = a_all19 >> 8;
            x_e8ac3 = x_ret19;
            carry_e8ac3 = carry_ret19;
            overflow_e8ac3 = overflow_ret18;
            direct_page_e8ac3 = direct_page_e89b3;
            data_bank_e8ac3 = data_bank_e89b3;
            goto shared_E8AC_2;
        } else {
            a_hi_e8ac4 = a_all19 >> 8;
            x_e8ac4 = x_ret19;
            carry_e8ac4 = carry_ret19;
            overflow_e8ac4 = overflow_ret18;
            direct_page_e8ac4 = direct_page_e89b3;
            data_bank_e8ac4 = data_bank_e89b3;
            goto shared_E8AC_3;
        }
    }
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8AB, emit_packed_actor_sprite_list_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8AB); }
    uint16_t dp_ret13 = r->dp;
    uint8_t db_ret13 = r->db;
    bool m_ret19 = r->mf;
    uint16_t a_all20 = r->a;
    uint8_t x_ret20 = r->x;
    bool carry_ret20 = r->c;
    bool overflow_ret19 = r->v;
    if (m_ret19) {
        a_hi_e8ac3 = a_all20 >> 8;
        x_e8ac3 = x_ret20;
        carry_e8ac3 = carry_ret20;
        overflow_e8ac3 = overflow_ret19;
        direct_page_e8ac3 = dp_ret13;
        data_bank_e8ac3 = db_ret13;
        goto shared_E8AC_2;
    } else {
        a_hi_e8ac4 = a_all20 >> 8;
        x_e8ac4 = x_ret20;
        carry_e8ac4 = carry_ret20;
        overflow_e8ac4 = overflow_ret19;
        direct_page_e8ac4 = dp_ret13;
        data_bank_e8ac4 = db_ret13;
        goto shared_E8AC_3;
    }
    shared_E89B_3:;
    uint16_t value91 = BUS16_RDP(c, (uint16_t)(direct_page_e89b4 + 0x14));
    r->a = value91 | 0x10;
    r->x = x_e89b4;
    r->y = (uint8_t)(value91 | 0x10);
    r->c = carry_e89b4;
    r->z = (uint8_t)(value91 | 0x10) == 0;
    r->n = (uint8_t)(value91 | 0x10) & 0x80;
    r->v = overflow_e89b4;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_e89b4;
    r->dp = direct_page_e89b4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8A6, 0x019106); GUARD_JSL(c, sp_call, 0xE8A6); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret20 = r->mf;
    uint16_t a_all21 = r->a;
    uint8_t x_ret21 = r->x;
    bool carry_ret21 = r->c;
    bool overflow_ret20 = r->v;
    if (!carry_ret21) {
        if (m_ret20) {
            a_hi_e8ac3 = a_all21 >> 8;
            x_e8ac3 = x_ret21;
            carry_e8ac3 = carry_ret21;
            overflow_e8ac3 = overflow_ret20;
            direct_page_e8ac3 = direct_page_e89b4;
            data_bank_e8ac3 = data_bank_e89b4;
            goto shared_E8AC_2;
        } else {
            a_hi_e8ac4 = a_all21 >> 8;
            x_e8ac4 = x_ret21;
            carry_e8ac4 = carry_ret21;
            overflow_e8ac4 = overflow_ret20;
            direct_page_e8ac4 = direct_page_e89b4;
            data_bank_e8ac4 = data_bank_e89b4;
            goto shared_E8AC_3;
        }
    }
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8AB, emit_packed_actor_sprite_list_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8AB); }
    uint16_t dp_ret14 = r->dp;
    uint8_t db_ret14 = r->db;
    bool m_ret21 = r->mf;
    uint16_t a_all22 = r->a;
    uint8_t x_ret22 = r->x;
    bool carry_ret22 = r->c;
    bool overflow_ret21 = r->v;
    if (m_ret21) {
        a_hi_e8ac3 = a_all22 >> 8;
        x_e8ac3 = x_ret22;
        carry_e8ac3 = carry_ret22;
        overflow_e8ac3 = overflow_ret21;
        direct_page_e8ac3 = dp_ret14;
        data_bank_e8ac3 = db_ret14;
        goto shared_E8AC_2;
    } else {
        a_hi_e8ac4 = a_all22 >> 8;
        x_e8ac4 = x_ret22;
        carry_e8ac4 = carry_ret22;
        overflow_e8ac4 = overflow_ret21;
        direct_page_e8ac4 = dp_ret14;
        data_bank_e8ac4 = db_ret14;
        goto shared_E8AC_3;
    }
    shared_E8D3:;
    r->a = (a_hi_e8d3 << 8) | a;
    r->y = y_e8d3;
    r->c = carry_e8d3;
    r->v = overflow_e8d3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_e8d3;
    r->dp = direct_page_e8d3;
    prepare_and_emit_actor_body_sprites_v2(c); return;
    shared_E8C6_2:;
    uint16_t value92 = BUS16_RDP(c, (uint16_t)(direct_page_e8c63 + 0x14));
    if (value92 < 0x0600) {
        a_hi_e8d3 = a_hi_e8c63;
        y_e8d3 = y_e8c63;
        carry_e8d3 = value92 >= 0x0600;
        overflow_e8d3 = overflow_e8c63;
        direct_page_e8d3 = direct_page_e8c63;
        data_bank_e8d3 = data_bank_e8c63;
        goto shared_E8D3;
    }
    uint8_t value93 = BUS8_RDP(c, (uint16_t)(direct_page_e8c63 + 0x5C));
    if (value93 & 0x80) {
        r->a = (a_hi_e8c63 << 8) | a_e8c63;
        r->x = value92;
        r->y = y_e8c63;
        r->c = value92 >= 0x0600;
        r->v = value93 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_e8c63;
        r->dp = direct_page_e8c63;
        RETURN_RTS(c);
    }
    a_hi_e8d3 = a_hi_e8c63;
    y_e8d3 = y_e8c63;
    carry_e8d3 = value92 >= 0x0600;
    overflow_e8d3 = value93 & 0x40;
    direct_page_e8d3 = direct_page_e8c63;
    data_bank_e8d3 = data_bank_e8c63;
    goto shared_E8D3;
    shared_E520:;
    uint8_t value94 = RAM8(0xE028 + x_e520);
    if ((value94 & 0x20) != 0) {
        if ((value94 & 0x10) == 0) {
            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e520) + 0x80));
            uint16_t value96 = RAM16(0xE11A + x_e520);
            RAM16_SET(0x0006, (uint16_t)(value96 + 0x70));
            r->a = x_e520 | 0xE0D0;
            r->x = x_e520 | 0xE0D0;
            r->y = y_e520;
            r->c = value96 + 0x70 > 0xFFFF;
            r->z = (x_e520 | 0xE0D0) == 0;
            r->n = (x_e520 | 0xE0D0) & 0x8000;
            r->v = ((value96 ^ (uint16_t)(value96 + 0x70)) & ((uint16_t)(value96 + 0x70) ^ 0x70) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5CA, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5CA); }
            uint16_t dp_ret15 = r->dp;
            uint8_t db_ret15 = r->db;
            bool m_ret22 = r->mf;
            uint16_t a_all23 = r->a;
            uint16_t y_ret16 = r->y;
            bool overflow_ret22 = r->v;
            if (m_ret22) {
                a_e8c6 = (uint8_t)a_all23;
                a_hi_e8c6 = a_all23 >> 8;
                y_e8c6 = y_ret16;
                overflow_e8c6 = overflow_ret22;
                direct_page_e8c6 = dp_ret15;
                data_bank_e8c6 = db_ret15;
                goto shared_E8C6;
            } else {
                a_e8c63 = (uint8_t)a_all23;
                a_hi_e8c63 = a_all23 >> 8;
                y_e8c63 = y_ret16;
                overflow_e8c63 = overflow_ret22;
                direct_page_e8c63 = dp_ret15;
                data_bank_e8c63 = db_ret15;
                goto shared_E8C6_2;
            }
        }
        uint16_t value97 = RAM16(0xE10C + x_e520);
        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e520) + RAM16(0xE020 + value97)));
        uint16_t value100 = RAM16(0xE074 + value97);
        uint16_t value101 = RAM16(0xE045 + value97);
        uint16_t value102 = RAM16(0xE11A + x_e520);
        uint16_t value103 = RAM16(0xE022 + value97);
        RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1) + value103 + (((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1 > 0xFFFF)));
        r->a = x_e520 | 0xE0D0;
        r->x = x_e520 | 0xE0D0;
        r->y = value97;
        r->c = (uint16_t)(((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1) + value103 + (((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1 > 0xFFFF) > 0xFFFF;
        r->z = (x_e520 | 0xE0D0) == 0;
        r->n = (x_e520 | 0xE0D0) & 0x8000;
        r->v = (((uint16_t)(((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1) + value103 + (((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1 > 0xFFFF))) & (value103 ^ (uint16_t)((uint16_t)(((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1) + value103 + (((uint16_t)((value100 & 0x7F) + value101) ^ 0xFFFF) + value102 + 1 > 0xFFFF))) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5AB, emit_packed_actor_sprite_list, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5AB); }
        uint16_t dp_ret16 = r->dp;
        uint8_t db_ret16 = r->db;
        bool m_ret23 = r->mf;
        uint16_t a_all24 = r->a;
        uint16_t y_ret17 = r->y;
        bool overflow_ret23 = r->v;
        if (m_ret23) {
            a_e8c6 = (uint8_t)a_all24;
            a_hi_e8c6 = a_all24 >> 8;
            y_e8c6 = y_ret17;
            overflow_e8c6 = overflow_ret23;
            direct_page_e8c6 = dp_ret16;
            data_bank_e8c6 = db_ret16;
            goto shared_E8C6;
        } else {
            a_e8c63 = (uint8_t)a_all24;
            a_hi_e8c63 = a_all24 >> 8;
            y_e8c63 = y_ret17;
            overflow_e8c63 = overflow_ret23;
            direct_page_e8c63 = dp_ret16;
            data_bank_e8c63 = db_ret16;
            goto shared_E8C6_2;
        }
    }
    a_hi_e527 = a_hi_e520;
    x_e527 = x_e520;
    y_e527 = y_e520;
    goto shared_E527;
    shared_E710:;
    RAM8(0x0002) = a_e710;
    uint8_t value104 = RAM8(0x0000 + sp0);
    if (!carry_e710) {
        a_e727 = 0xD0;
        a_hi_e727 = 0;
        x_e727 = x_e710;
        goto shared_E727;
    }
    a_e727 = (uint8_t)((uint16_t)((uint16_t)((((a_hi_e710 << 8) | value104) & 0x0F) - 5 - (carry_e710 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e710 << 8) | value104) & 0x0F) - 5 - (carry_e710 ^ 1)) << 1) >> 0x0F));
    a_hi_e727 = (uint16_t)((uint16_t)((uint16_t)((((a_hi_e710 << 8) | value104) & 0x0F) - 5 - (carry_e710 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e710 << 8) | value104) & 0x0F) - 5 - (carry_e710 ^ 1)) << 1) >> 0x0F)) >> 8;
    x_e727 = x_e710;
    goto shared_E727;
    shared_E8AC:;
    uint16_t value105 = BUS16_RDP(c, (uint16_t)(direct_page_e8ac + 0x14));
    r->a = value105 | 0x20;
    r->x = x_e8ac;
    r->y = value105 | 0x20;
    r->c = carry_e8ac;
    r->z = (value105 | 0x20) == 0;
    r->n = (value105 | 0x20) & 0x8000;
    r->v = overflow_e8ac;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_e8ac;
    r->dp = direct_page_e8ac;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8B7, 0x019106); GUARD_JSL(c, sp_call, 0xE8B7); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret24 = r->mf;
    uint16_t a_all25 = r->a;
    uint16_t x_ret25 = r->x;
    bool carry_ret25 = r->c;
    bool overflow_ret24 = r->v;
    if (!carry_ret25) {
        if (m_ret24) {
            a_e8bd = (uint8_t)a_all25;
            a_hi_e8bd = a_all25 >> 8;
            x_e8bd = x_ret25;
            y_e8bd = value105 | 0x20;
            carry_e8bd = carry_ret25;
            overflow_e8bd = overflow_ret24;
            direct_page_e8bd = direct_page_e8ac;
            data_bank_e8bd = data_bank_e8ac;
            goto shared_E8BD;
        } else {
            a_e8bd2 = (uint8_t)a_all25;
            a_hi_e8bd2 = a_all25 >> 8;
            x_e8bd2 = x_ret25;
            y_e8bd2 = value105 | 0x20;
            carry_e8bd2 = carry_ret25;
            overflow_e8bd2 = overflow_ret24;
            direct_page_e8bd2 = direct_page_e8ac;
            data_bank_e8bd2 = data_bank_e8ac;
            goto shared_E8BD_1;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8BC, emit_packed_actor_sprite_list_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8BC); }
    uint16_t dp_ret17 = r->dp;
    uint8_t db_ret17 = r->db;
    bool m_ret25 = r->mf;
    uint16_t a_all26 = r->a;
    uint16_t x_ret26 = r->x;
    uint16_t y_ret18 = r->y;
    bool carry_ret26 = r->c;
    bool overflow_ret25 = r->v;
    if (m_ret25) {
        a_e8bd = (uint8_t)a_all26;
        a_hi_e8bd = a_all26 >> 8;
        x_e8bd = x_ret26;
        y_e8bd = y_ret18;
        carry_e8bd = carry_ret26;
        overflow_e8bd = overflow_ret25;
        direct_page_e8bd = dp_ret17;
        data_bank_e8bd = db_ret17;
        goto shared_E8BD;
    } else {
        a_e8bd2 = (uint8_t)a_all26;
        a_hi_e8bd2 = a_all26 >> 8;
        x_e8bd2 = x_ret26;
        y_e8bd2 = y_ret18;
        carry_e8bd2 = carry_ret26;
        overflow_e8bd2 = overflow_ret25;
        direct_page_e8bd2 = dp_ret17;
        data_bank_e8bd2 = db_ret17;
        goto shared_E8BD_1;
    }
    shared_E8AC_1:;
    uint16_t value106 = BUS16_RDP(c, (uint16_t)(direct_page_e8ac2 + 0x14));
    r->a = value106 | 0x20;
    r->x = x_e8ac2;
    r->y = value106 | 0x20;
    r->c = carry_e8ac2;
    r->z = (value106 | 0x20) == 0;
    r->n = (value106 | 0x20) & 0x8000;
    r->v = overflow_e8ac2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_e8ac2;
    r->dp = direct_page_e8ac2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8B7, 0x019106); GUARD_JSL(c, sp_call, 0xE8B7); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret26 = r->mf;
    uint16_t a_all27 = r->a;
    uint16_t x_ret27 = r->x;
    bool carry_ret27 = r->c;
    bool overflow_ret26 = r->v;
    if (!carry_ret27) {
        if (m_ret26) {
            a_e8bd = (uint8_t)a_all27;
            a_hi_e8bd = a_all27 >> 8;
            x_e8bd = x_ret27;
            y_e8bd = value106 | 0x20;
            carry_e8bd = carry_ret27;
            overflow_e8bd = overflow_ret26;
            direct_page_e8bd = direct_page_e8ac2;
            data_bank_e8bd = data_bank_e8ac2;
            goto shared_E8BD;
        } else {
            a_e8bd2 = (uint8_t)a_all27;
            a_hi_e8bd2 = a_all27 >> 8;
            x_e8bd2 = x_ret27;
            y_e8bd2 = value106 | 0x20;
            carry_e8bd2 = carry_ret27;
            overflow_e8bd2 = overflow_ret26;
            direct_page_e8bd2 = direct_page_e8ac2;
            data_bank_e8bd2 = data_bank_e8ac2;
            goto shared_E8BD_1;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8BC, emit_packed_actor_sprite_list_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8BC); }
    uint16_t dp_ret18 = r->dp;
    uint8_t db_ret18 = r->db;
    bool m_ret27 = r->mf;
    uint16_t a_all28 = r->a;
    uint16_t x_ret28 = r->x;
    uint16_t y_ret19 = r->y;
    bool carry_ret28 = r->c;
    bool overflow_ret27 = r->v;
    if (m_ret27) {
        a_e8bd = (uint8_t)a_all28;
        a_hi_e8bd = a_all28 >> 8;
        x_e8bd = x_ret28;
        y_e8bd = y_ret19;
        carry_e8bd = carry_ret28;
        overflow_e8bd = overflow_ret27;
        direct_page_e8bd = dp_ret18;
        data_bank_e8bd = db_ret18;
        goto shared_E8BD;
    } else {
        a_e8bd2 = (uint8_t)a_all28;
        a_hi_e8bd2 = a_all28 >> 8;
        x_e8bd2 = x_ret28;
        y_e8bd2 = y_ret19;
        carry_e8bd2 = carry_ret28;
        overflow_e8bd2 = overflow_ret27;
        direct_page_e8bd2 = dp_ret18;
        data_bank_e8bd2 = db_ret18;
        goto shared_E8BD_1;
    }
    shared_E8C6_3:;
    uint8_t value107 = BUS8_RDP(c, (uint16_t)(direct_page_e8c64 + 0x14));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_E520_1:;
    uint8_t value108 = RAM8(0xE028 + x_e5202);
    if ((value108 & 0x20) != 0) {
        if ((value108 & 0x10) == 0) {
            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e5202) + 0x80));
            uint16_t value110 = RAM16(0xE11A + x_e5202);
            RAM16_SET(0x0006, (uint16_t)(value110 + 0x70));
            r->a = x_e5202 | 0xE0D0;
            r->x = (uint8_t)(x_e5202 | 0xE0D0);
            r->y = y_e5202;
            r->c = value110 + 0x70 > 0xFFFF;
            r->z = (uint8_t)(x_e5202 | 0xE0D0) == 0;
            r->n = (uint8_t)(x_e5202 | 0xE0D0) & 0x80;
            r->v = ((value110 ^ (uint16_t)(value110 + 0x70)) & ((uint16_t)(value110 + 0x70) ^ 0x70) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7E;
            r->dp = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5CA, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5CA); }
            uint16_t dp_ret19 = r->dp;
            uint8_t db_ret19 = r->db;
            bool m_ret28 = r->mf;
            uint16_t a_all29 = r->a;
            uint8_t y_ret20 = r->y;
            bool overflow_ret28 = r->v;
            if (m_ret28) {
                a_e8c62 = (uint8_t)a_all29;
                a_hi_e8c62 = a_all29 >> 8;
                y_e8c62 = y_ret20;
                overflow_e8c62 = overflow_ret28;
                direct_page_e8c62 = dp_ret19;
                data_bank_e8c62 = db_ret19;
                goto shared_E8C6_1;
            } else {
                a_e8c64 = (uint8_t)a_all29;
                a_hi_e8c64 = a_all29 >> 8;
                y_e8c64 = y_ret20;
                overflow_e8c64 = overflow_ret28;
                direct_page_e8c64 = dp_ret19;
                data_bank_e8c64 = db_ret19;
                goto shared_E8C6_3;
            }
        }
        uint8_t value111 = RAM8(0xE10C + x_e5202);
        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + x_e5202) + RAM16(0xE020 + value111)));
        uint16_t value114 = RAM16(0xE074 + value111);
        uint16_t value115 = RAM16(0xE045 + value111);
        uint16_t value116 = RAM16(0xE11A + x_e5202);
        uint16_t value117 = RAM16(0xE022 + value111);
        RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1) + value117 + (((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1 > 0xFFFF)));
        r->a = x_e5202 | 0xE0D0;
        r->x = (uint8_t)(x_e5202 | 0xE0D0);
        r->y = value111;
        r->c = (uint16_t)(((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1) + value117 + (((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1 > 0xFFFF) > 0xFFFF;
        r->z = (uint8_t)(x_e5202 | 0xE0D0) == 0;
        r->n = (uint8_t)(x_e5202 | 0xE0D0) & 0x80;
        r->v = (((uint16_t)(((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1) + value117 + (((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1 > 0xFFFF))) & (value117 ^ (uint16_t)((uint16_t)(((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1) + value117 + (((uint16_t)((value114 & 0x7F) + value115) ^ 0xFFFF) + value116 + 1 > 0xFFFF))) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        r->db = 0x7E;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE5AB, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE5AB); }
        uint16_t dp_ret20 = r->dp;
        uint8_t db_ret20 = r->db;
        bool m_ret29 = r->mf;
        uint16_t a_all30 = r->a;
        uint8_t y_ret21 = r->y;
        bool overflow_ret29 = r->v;
        if (m_ret29) {
            a_e8c62 = (uint8_t)a_all30;
            a_hi_e8c62 = a_all30 >> 8;
            y_e8c62 = y_ret21;
            overflow_e8c62 = overflow_ret29;
            direct_page_e8c62 = dp_ret20;
            data_bank_e8c62 = db_ret20;
            goto shared_E8C6_1;
        } else {
            a_e8c64 = (uint8_t)a_all30;
            a_hi_e8c64 = a_all30 >> 8;
            y_e8c64 = y_ret21;
            overflow_e8c64 = overflow_ret29;
            direct_page_e8c64 = dp_ret20;
            data_bank_e8c64 = db_ret20;
            goto shared_E8C6_3;
        }
    }
    a_hi_e5272 = a_hi_e5202;
    x_e5272 = x_e5202;
    y_e5272 = y_e5202;
    goto shared_E527_1;
    shared_E710_1:;
    RAM8(0x0002) = a_e7102;
    uint8_t value118 = RAM8(0x0000 + sp0);
    if (!carry_e7102) {
        a_e7272 = 0xD0;
        a_hi_e7272 = 0;
        x_e7272 = x_e7102;
        goto shared_E727_1;
    }
    a_e7272 = (uint8_t)((uint16_t)((uint16_t)((((a_hi_e7102 << 8) | value118) & 0x0F) - 5 - (carry_e7102 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e7102 << 8) | value118) & 0x0F) - 5 - (carry_e7102 ^ 1)) << 1) >> 0x0F));
    a_hi_e7272 = (uint16_t)((uint16_t)((uint16_t)((((a_hi_e7102 << 8) | value118) & 0x0F) - 5 - (carry_e7102 ^ 1)) << 2) + 0xD0 + ((uint16_t)((uint16_t)((((a_hi_e7102 << 8) | value118) & 0x0F) - 5 - (carry_e7102 ^ 1)) << 1) >> 0x0F)) >> 8;
    x_e7272 = x_e7102;
    goto shared_E727_1;
    shared_E8AC_2:;
    uint16_t value119 = BUS16_RDP(c, (uint16_t)(direct_page_e8ac3 + 0x14));
    r->a = value119 | 0x20;
    r->x = x_e8ac3;
    r->y = (uint8_t)(value119 | 0x20);
    r->c = carry_e8ac3;
    r->z = (uint8_t)(value119 | 0x20) == 0;
    r->n = (uint8_t)(value119 | 0x20) & 0x80;
    r->v = overflow_e8ac3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_e8ac3;
    r->dp = direct_page_e8ac3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8B7, 0x019106); GUARD_JSL(c, sp_call, 0xE8B7); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret30 = r->mf;
    uint16_t a_all31 = r->a;
    uint8_t x_ret31 = r->x;
    bool carry_ret31 = r->c;
    bool overflow_ret30 = r->v;
    if (!carry_ret31) {
        if (m_ret30) {
            a_e8bd3 = (uint8_t)a_all31;
            a_hi_e8bd3 = a_all31 >> 8;
            x_e8bd3 = x_ret31;
            y_e8bd3 = (uint8_t)(value119 | 0x20);
            carry_e8bd3 = carry_ret31;
            overflow_e8bd3 = overflow_ret30;
            direct_page_e8bd3 = direct_page_e8ac3;
            data_bank_e8bd3 = data_bank_e8ac3;
            goto shared_E8BD_2;
        } else {
            a_e8bd4 = (uint8_t)a_all31;
            a_hi_e8bd4 = a_all31 >> 8;
            x_e8bd4 = x_ret31;
            y_e8bd4 = (uint8_t)(value119 | 0x20);
            carry_e8bd4 = carry_ret31;
            overflow_e8bd4 = overflow_ret30;
            direct_page_e8bd4 = direct_page_e8ac3;
            data_bank_e8bd4 = data_bank_e8ac3;
            goto shared_E8BD_3;
        }
    }
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8BC, emit_packed_actor_sprite_list_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8BC); }
    uint16_t dp_ret21 = r->dp;
    uint8_t db_ret21 = r->db;
    bool m_ret31 = r->mf;
    uint16_t a_all32 = r->a;
    uint8_t x_ret32 = r->x;
    uint8_t y_ret22 = r->y;
    bool carry_ret32 = r->c;
    bool overflow_ret31 = r->v;
    if (m_ret31) {
        a_e8bd3 = (uint8_t)a_all32;
        a_hi_e8bd3 = a_all32 >> 8;
        x_e8bd3 = x_ret32;
        y_e8bd3 = y_ret22;
        carry_e8bd3 = carry_ret32;
        overflow_e8bd3 = overflow_ret31;
        direct_page_e8bd3 = dp_ret21;
        data_bank_e8bd3 = db_ret21;
        goto shared_E8BD_2;
    } else {
        a_e8bd4 = (uint8_t)a_all32;
        a_hi_e8bd4 = a_all32 >> 8;
        x_e8bd4 = x_ret32;
        y_e8bd4 = y_ret22;
        carry_e8bd4 = carry_ret32;
        overflow_e8bd4 = overflow_ret31;
        direct_page_e8bd4 = dp_ret21;
        data_bank_e8bd4 = db_ret21;
        goto shared_E8BD_3;
    }
    shared_E8AC_3:;
    uint16_t value120 = BUS16_RDP(c, (uint16_t)(direct_page_e8ac4 + 0x14));
    r->a = value120 | 0x20;
    r->x = x_e8ac4;
    r->y = (uint8_t)(value120 | 0x20);
    r->c = carry_e8ac4;
    r->z = (uint8_t)(value120 | 0x20) == 0;
    r->n = (uint8_t)(value120 | 0x20) & 0x80;
    r->v = overflow_e8ac4;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_e8ac4;
    r->dp = direct_page_e8ac4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8B7, 0x019106); GUARD_JSL(c, sp_call, 0xE8B7); } /* prepare_one_actor_effect_sprite_list */
    bool m_ret32 = r->mf;
    uint16_t a_all33 = r->a;
    uint8_t x_ret33 = r->x;
    bool carry_ret33 = r->c;
    bool overflow_ret32 = r->v;
    if (!carry_ret33) {
        if (m_ret32) {
            a_e8bd3 = (uint8_t)a_all33;
            a_hi_e8bd3 = a_all33 >> 8;
            x_e8bd3 = x_ret33;
            y_e8bd3 = (uint8_t)(value120 | 0x20);
            carry_e8bd3 = carry_ret33;
            overflow_e8bd3 = overflow_ret32;
            direct_page_e8bd3 = direct_page_e8ac4;
            data_bank_e8bd3 = data_bank_e8ac4;
            goto shared_E8BD_2;
        } else {
            a_e8bd4 = (uint8_t)a_all33;
            a_hi_e8bd4 = a_all33 >> 8;
            x_e8bd4 = x_ret33;
            y_e8bd4 = (uint8_t)(value120 | 0x20);
            carry_e8bd4 = carry_ret33;
            overflow_e8bd4 = overflow_ret32;
            direct_page_e8bd4 = direct_page_e8ac4;
            data_bank_e8bd4 = data_bank_e8ac4;
            goto shared_E8BD_3;
        }
    }
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8BC, emit_packed_actor_sprite_list_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8BC); }
    uint16_t dp_ret22 = r->dp;
    uint8_t db_ret22 = r->db;
    bool m_ret33 = r->mf;
    uint16_t a_all34 = r->a;
    uint8_t x_ret34 = r->x;
    uint8_t y_ret23 = r->y;
    bool carry_ret34 = r->c;
    bool overflow_ret33 = r->v;
    if (m_ret33) {
        a_e8bd3 = (uint8_t)a_all34;
        a_hi_e8bd3 = a_all34 >> 8;
        x_e8bd3 = x_ret34;
        y_e8bd3 = y_ret23;
        carry_e8bd3 = carry_ret34;
        overflow_e8bd3 = overflow_ret33;
        direct_page_e8bd3 = dp_ret22;
        data_bank_e8bd3 = db_ret22;
        goto shared_E8BD_2;
    } else {
        a_e8bd4 = (uint8_t)a_all34;
        a_hi_e8bd4 = a_all34 >> 8;
        x_e8bd4 = x_ret34;
        y_e8bd4 = y_ret23;
        carry_e8bd4 = carry_ret34;
        overflow_e8bd4 = overflow_ret33;
        direct_page_e8bd4 = dp_ret22;
        data_bank_e8bd4 = db_ret22;
        goto shared_E8BD_3;
    }
    shared_E727:;
    uint16_t value121 = RAM16(0x0014);
    uint16_t value122 = RAM16(0xE028 + x_e727);
    if ((value122 & 0x30) != 0x30) {
        a_hi_e73e = 0;
        x_e73e = x_e727;
        y_e73e = (a_hi_e727 << 8) | a_e727 | value121 | 0xE000;
        carry_e73e = (value122 & 0x30) >= 0x30;
        goto shared_E73E;
    }
    uint16_t value123 = RAM16(0xE10C + x_e727);
    a_hi_e73e = value123 >> 8;
    x_e73e = value123;
    y_e73e = (a_hi_e727 << 8) | a_e727 | value121 | 0xE000;
    carry_e73e = (value122 & 0x30) >= 0x30;
    goto shared_E73E;
    shared_E8BD:;
    r->a = (a_hi_e8bd << 8) | a_e8bd;
    r->x = x_e8bd;
    r->y = y_e8bd;
    r->c = carry_e8bd;
    r->v = overflow_e8bd;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_e8bd;
    r->dp = direct_page_e8bd;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8C0, 0x019017); GUARD_JSL(c, sp_call, 0xE8C0); } /* prepare_merged_actor_effect_sprites */
    bool m_ret34 = r->mf;
    uint16_t a_all35 = r->a;
    uint16_t y_ret24 = r->y;
    bool carry_ret35 = r->c;
    bool overflow_ret34 = r->v;
    if (!carry_ret35) {
        if (m_ret34) {
            a_e8c6 = (uint8_t)a_all35;
            a_hi_e8c6 = a_all35 >> 8;
            y_e8c6 = y_ret24;
            overflow_e8c6 = overflow_ret34;
            direct_page_e8c6 = direct_page_e8bd;
            data_bank_e8c6 = data_bank_e8bd;
            goto shared_E8C6;
        } else {
            a_e8c63 = (uint8_t)a_all35;
            a_hi_e8c63 = a_all35 >> 8;
            y_e8c63 = y_ret24;
            overflow_e8c63 = overflow_ret34;
            direct_page_e8c63 = direct_page_e8bd;
            data_bank_e8c63 = data_bank_e8bd;
            goto shared_E8C6_2;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8C5, emit_packed_actor_sprite_list_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8C5); }
    uint16_t dp_ret23 = r->dp;
    uint8_t db_ret23 = r->db;
    bool m_ret35 = r->mf;
    uint16_t a_all36 = r->a;
    uint16_t y_ret25 = r->y;
    bool overflow_ret35 = r->v;
    if (m_ret35) {
        a_e8c6 = (uint8_t)a_all36;
        a_hi_e8c6 = a_all36 >> 8;
        y_e8c6 = y_ret25;
        overflow_e8c6 = overflow_ret35;
        direct_page_e8c6 = dp_ret23;
        data_bank_e8c6 = db_ret23;
        goto shared_E8C6;
    } else {
        a_e8c63 = (uint8_t)a_all36;
        a_hi_e8c63 = a_all36 >> 8;
        y_e8c63 = y_ret25;
        overflow_e8c63 = overflow_ret35;
        direct_page_e8c63 = dp_ret23;
        data_bank_e8c63 = db_ret23;
        goto shared_E8C6_2;
    }
    shared_E8BD_1:;
    r->a = (a_hi_e8bd2 << 8) | a_e8bd2;
    r->x = x_e8bd2;
    r->y = y_e8bd2;
    r->c = carry_e8bd2;
    r->v = overflow_e8bd2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_e8bd2;
    r->dp = direct_page_e8bd2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8C0, 0x019017); GUARD_JSL(c, sp_call, 0xE8C0); } /* prepare_merged_actor_effect_sprites */
    bool m_ret36 = r->mf;
    uint16_t a_all37 = r->a;
    uint16_t y_ret26 = r->y;
    bool carry_ret37 = r->c;
    bool overflow_ret36 = r->v;
    if (!carry_ret37) {
        if (m_ret36) {
            a_e8c6 = (uint8_t)a_all37;
            a_hi_e8c6 = a_all37 >> 8;
            y_e8c6 = y_ret26;
            overflow_e8c6 = overflow_ret36;
            direct_page_e8c6 = direct_page_e8bd2;
            data_bank_e8c6 = data_bank_e8bd2;
            goto shared_E8C6;
        } else {
            a_e8c63 = (uint8_t)a_all37;
            a_hi_e8c63 = a_all37 >> 8;
            y_e8c63 = y_ret26;
            overflow_e8c63 = overflow_ret36;
            direct_page_e8c63 = direct_page_e8bd2;
            data_bank_e8c63 = data_bank_e8bd2;
            goto shared_E8C6_2;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8C5, emit_packed_actor_sprite_list_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8C5); }
    uint16_t dp_ret24 = r->dp;
    uint8_t db_ret24 = r->db;
    bool m_ret37 = r->mf;
    uint16_t a_all38 = r->a;
    uint16_t y_ret27 = r->y;
    bool overflow_ret37 = r->v;
    if (m_ret37) {
        a_e8c6 = (uint8_t)a_all38;
        a_hi_e8c6 = a_all38 >> 8;
        y_e8c6 = y_ret27;
        overflow_e8c6 = overflow_ret37;
        direct_page_e8c6 = dp_ret24;
        data_bank_e8c6 = db_ret24;
        goto shared_E8C6;
    } else {
        a_e8c63 = (uint8_t)a_all38;
        a_hi_e8c63 = a_all38 >> 8;
        y_e8c63 = y_ret27;
        overflow_e8c63 = overflow_ret37;
        direct_page_e8c63 = dp_ret24;
        data_bank_e8c63 = db_ret24;
        goto shared_E8C6_2;
    }
    shared_E727_1:;
    uint16_t value124 = RAM16(0x0014);
    uint16_t value125 = RAM16(0xE028 + x_e7272);
    if ((value125 & 0x30) != 0x30) {
        a_hi_e73e2 = 0;
        x_e73e2 = x_e7272;
        y_e73e2 = (uint8_t)((a_hi_e7272 << 8) | a_e7272 | value124 | 0xE000);
        carry_e73e2 = (value125 & 0x30) >= 0x30;
        goto shared_E73E_1;
    }
    uint16_t value126 = RAM16(0xE10C + x_e7272);
    a_hi_e73e2 = value126 >> 8;
    x_e73e2 = (uint8_t)value126;
    y_e73e2 = (uint8_t)((a_hi_e7272 << 8) | a_e7272 | value124 | 0xE000);
    carry_e73e2 = (value125 & 0x30) >= 0x30;
    goto shared_E73E_1;
    shared_E8BD_2:;
    r->a = (a_hi_e8bd3 << 8) | a_e8bd3;
    r->x = x_e8bd3;
    r->y = y_e8bd3;
    r->c = carry_e8bd3;
    r->v = overflow_e8bd3;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_e8bd3;
    r->dp = direct_page_e8bd3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8C0, 0x019017); GUARD_JSL(c, sp_call, 0xE8C0); } /* prepare_merged_actor_effect_sprites */
    bool m_ret38 = r->mf;
    uint16_t a_all39 = r->a;
    uint8_t y_ret28 = r->y;
    bool carry_ret39 = r->c;
    bool overflow_ret38 = r->v;
    if (!carry_ret39) {
        if (m_ret38) {
            a_e8c62 = (uint8_t)a_all39;
            a_hi_e8c62 = a_all39 >> 8;
            y_e8c62 = y_ret28;
            overflow_e8c62 = overflow_ret38;
            direct_page_e8c62 = direct_page_e8bd3;
            data_bank_e8c62 = data_bank_e8bd3;
            goto shared_E8C6_1;
        } else {
            a_e8c64 = (uint8_t)a_all39;
            a_hi_e8c64 = a_all39 >> 8;
            y_e8c64 = y_ret28;
            overflow_e8c64 = overflow_ret38;
            direct_page_e8c64 = direct_page_e8bd3;
            data_bank_e8c64 = data_bank_e8bd3;
            goto shared_E8C6_3;
        }
    }
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8C5, emit_packed_actor_sprite_list_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8C5); }
    uint16_t dp_ret25 = r->dp;
    uint8_t db_ret25 = r->db;
    bool m_ret39 = r->mf;
    uint16_t a_all40 = r->a;
    uint8_t y_ret29 = r->y;
    bool overflow_ret39 = r->v;
    if (m_ret39) {
        a_e8c62 = (uint8_t)a_all40;
        a_hi_e8c62 = a_all40 >> 8;
        y_e8c62 = y_ret29;
        overflow_e8c62 = overflow_ret39;
        direct_page_e8c62 = dp_ret25;
        data_bank_e8c62 = db_ret25;
        goto shared_E8C6_1;
    } else {
        a_e8c64 = (uint8_t)a_all40;
        a_hi_e8c64 = a_all40 >> 8;
        y_e8c64 = y_ret29;
        overflow_e8c64 = overflow_ret39;
        direct_page_e8c64 = dp_ret25;
        data_bank_e8c64 = db_ret25;
        goto shared_E8C6_3;
    }
    shared_E8BD_3:;
    r->a = (a_hi_e8bd4 << 8) | a_e8bd4;
    r->x = x_e8bd4;
    r->y = y_e8bd4;
    r->c = carry_e8bd4;
    r->v = overflow_e8bd4;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_e8bd4;
    r->dp = direct_page_e8bd4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE8C0, 0x019017); GUARD_JSL(c, sp_call, 0xE8C0); } /* prepare_merged_actor_effect_sprites */
    bool m_ret40 = r->mf;
    uint16_t a_all41 = r->a;
    uint8_t y_ret30 = r->y;
    bool carry_ret41 = r->c;
    bool overflow_ret40 = r->v;
    if (!carry_ret41) {
        if (m_ret40) {
            a_e8c62 = (uint8_t)a_all41;
            a_hi_e8c62 = a_all41 >> 8;
            y_e8c62 = y_ret30;
            overflow_e8c62 = overflow_ret40;
            direct_page_e8c62 = direct_page_e8bd4;
            data_bank_e8c62 = data_bank_e8bd4;
            goto shared_E8C6_1;
        } else {
            a_e8c64 = (uint8_t)a_all41;
            a_hi_e8c64 = a_all41 >> 8;
            y_e8c64 = y_ret30;
            overflow_e8c64 = overflow_ret40;
            direct_page_e8c64 = direct_page_e8bd4;
            data_bank_e8c64 = data_bank_e8bd4;
            goto shared_E8C6_3;
        }
    }
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE8C5, emit_packed_actor_sprite_list_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xE8C5); }
    uint16_t dp_ret26 = r->dp;
    uint8_t db_ret26 = r->db;
    bool m_ret41 = r->mf;
    uint16_t a_all42 = r->a;
    uint8_t y_ret31 = r->y;
    bool overflow_ret41 = r->v;
    if (m_ret41) {
        a_e8c62 = (uint8_t)a_all42;
        a_hi_e8c62 = a_all42 >> 8;
        y_e8c62 = y_ret31;
        overflow_e8c62 = overflow_ret41;
        direct_page_e8c62 = dp_ret26;
        data_bank_e8c62 = db_ret26;
        goto shared_E8C6_1;
    } else {
        a_e8c64 = (uint8_t)a_all42;
        a_hi_e8c64 = a_all42 >> 8;
        y_e8c64 = y_ret31;
        overflow_e8c64 = overflow_ret41;
        direct_page_e8c64 = dp_ret26;
        data_bank_e8c64 = db_ret26;
        goto shared_E8C6_3;
    }
    shared_E73E:;
    RAM16_SET(0x0004, RAM16(0xE020 + x_e73e));
    uint16_t value128 = RAM16(0xE074 + x_e73e);
    uint16_t value129 = RAM16(0xE045 + x_e73e);
    uint16_t value130 = RAM16(0xE022 + x_e73e);
    RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value128 & 0x7F) + value129 + carry_e73e) ^ 0xFFFF) + value130 + ((value128 & 0x7F) + value129 + carry_e73e > 0xFFFF)));
    uint16_t value131 = RAM16(0x0014);
    r->a = (uint16_t)(((uint16_t)((value128 & 0x7F) + value129 + carry_e73e) ^ 0xFFFF) + value130 + ((value128 & 0x7F) + value129 + carry_e73e > 0xFFFF));
    r->x = value131;
    r->y = y_e73e;
    r->c = ((uint16_t)((value128 & 0x7F) + value129 + carry_e73e) ^ 0xFFFF) + value130 + ((value128 & 0x7F) + value129 + carry_e73e > 0xFFFF) > 0xFFFF;
    r->z = value131 == 0;
    r->n = value131 & 0x8000;
    r->v = (((uint16_t)((value128 & 0x7F) + value129 + carry_e73e) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value128 & 0x7F) + value129 + carry_e73e) ^ 0xFFFF) + value130 + ((value128 & 0x7F) + value129 + carry_e73e > 0xFFFF))) & (value130 ^ (uint16_t)(((uint16_t)((value128 & 0x7F) + value129 + carry_e73e) ^ 0xFFFF) + value130 + ((value128 & 0x7F) + value129 + carry_e73e > 0xFFFF))) & 0x8000) != 0;
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
    bool m_ret42 = r->mf;
    uint16_t a_all44 = r->a;
    uint16_t y_ret33 = r->y;
    bool overflow_ret43 = r->v;
    if (m_ret42) {
        a_e8c6 = (uint8_t)a_all44;
        a_hi_e8c6 = a_all44 >> 8;
        y_e8c6 = y_ret33;
        overflow_e8c6 = overflow_ret43;
        direct_page_e8c6 = dp_ret27;
        data_bank_e8c6 = db_ret27;
        goto shared_E8C6;
    } else {
        a_e8c63 = (uint8_t)a_all44;
        a_hi_e8c63 = a_all44 >> 8;
        y_e8c63 = y_ret33;
        overflow_e8c63 = overflow_ret43;
        direct_page_e8c63 = dp_ret27;
        data_bank_e8c63 = db_ret27;
        goto shared_E8C6_2;
    }
    shared_E73E_1:;
    RAM16_SET(0x0004, RAM16(0xE020 + x_e73e2));
    uint16_t value133 = RAM16(0xE074 + x_e73e2);
    uint16_t value134 = RAM16(0xE045 + x_e73e2);
    uint16_t value135 = RAM16(0xE022 + x_e73e2);
    RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value133 & 0x7F) + value134 + carry_e73e2) ^ 0xFFFF) + value135 + ((value133 & 0x7F) + value134 + carry_e73e2 > 0xFFFF)));
    uint8_t value136 = RAM8(0x0014);
    r->a = (uint16_t)(((uint16_t)((value133 & 0x7F) + value134 + carry_e73e2) ^ 0xFFFF) + value135 + ((value133 & 0x7F) + value134 + carry_e73e2 > 0xFFFF));
    r->x = value136;
    r->y = y_e73e2;
    r->c = ((uint16_t)((value133 & 0x7F) + value134 + carry_e73e2) ^ 0xFFFF) + value135 + ((value133 & 0x7F) + value134 + carry_e73e2 > 0xFFFF) > 0xFFFF;
    r->z = value136 == 0;
    r->n = value136 & 0x80;
    r->v = (((uint16_t)((value133 & 0x7F) + value134 + carry_e73e2) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value133 & 0x7F) + value134 + carry_e73e2) ^ 0xFFFF) + value135 + ((value133 & 0x7F) + value134 + carry_e73e2 > 0xFFFF))) & (value135 ^ (uint16_t)(((uint16_t)((value133 & 0x7F) + value134 + carry_e73e2) ^ 0xFFFF) + value135 + ((value133 & 0x7F) + value134 + carry_e73e2 > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE759, 0x02AB54); GUARD_JSL(c, sp_call, 0xE759); } /* duplicate_and_mirror_actor_sprite_list */
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE75C, emit_packed_actor_sprite_list_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xE75C); }
    uint16_t dp_ret28 = r->dp;
    uint8_t db_ret28 = r->db;
    bool m_ret43 = r->mf;
    uint16_t a_all46 = r->a;
    uint8_t y_ret35 = r->y;
    bool overflow_ret45 = r->v;
    if (m_ret43) {
        a_e8c62 = (uint8_t)a_all46;
        a_hi_e8c62 = a_all46 >> 8;
        y_e8c62 = y_ret35;
        overflow_e8c62 = overflow_ret45;
        direct_page_e8c62 = dp_ret28;
        data_bank_e8c62 = db_ret28;
        goto shared_E8C6_1;
    } else {
        a_e8c64 = (uint8_t)a_all46;
        a_hi_e8c64 = a_all46 >> 8;
        y_e8c64 = y_ret35;
        overflow_e8c64 = overflow_ret45;
        direct_page_e8c64 = dp_ret28;
        data_bank_e8c64 = db_ret28;
        goto shared_E8C6_3;
    }
}
SOM_REGISTER(0xC0E40E, SOM_RTS, "gen", update_actor_screen_position_and_emit_sprites, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 49, 1, 0, 1225, 419)

/* C0E5CE prepare_and_emit_actor_body_sprites   [class A, 257 bytes, 129 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
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
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
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

/* C0E5CE prepare_and_emit_actor_body_sprites_v3   [class A, 257 bytes, 129 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
 * Entry: M=any X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void prepare_and_emit_actor_body_sprites_v3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint8_t value = RAM8(0x0014);
    uint8_t value2 = RAM8(0xE00E + value);
    if (value2 == 0) {
        uint16_t value3 = RAM16(0xE083 + value);
        RAM16_SET(0x0002, value3 & 0x0F);
        if ((value3 & 0x0F) == 0) {
            r->a = value3 & 0x0F;
            r->x = value;
            r->z = (value3 & 0x0F) == 0;
            r->n = value3 & 0x0F & 0x8000;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value4 = RAM16(0x0014);
        RAM16_SET(0x0004, RAM16(0xE020 + value));
        uint16_t value6 = RAM16(0xE074 + value);
        uint16_t value7 = RAM16(0xE045 + value);
        uint16_t value8 = RAM16(0xE022 + value);
        RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1));
        uint8_t value9 = RAM8(0xE00D + value);
        uint8_t a3;
        bool overflow1;
        if (value9 == 0) {
            a3 = value9;
            overflow1 = (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1)) & (value8 ^ (uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1)) & 0x8000) != 0;
        } else {
            RAM8(0xE00D + value) = (uint8_t)(value9 - 0x10);
            uint8_t a2;
            if (value9 >= 0x10) {
                if ((uint8_t)(value9 - 0x10) & 0x01) {
                    RAM8(0x0000 + sp0) = (uint8_t)(value9 - 0x10) >> 1;
                    RAM8(0x0004) = ((RAM8(0x00F4) & 1) << 1) ^ RAM8(0x0004);
                }
                uint8_t a1;
                if (!((uint8_t)(value9 - 0x10) >> 1 & 0x01)) {
                    a1 = (uint8_t)(value9 - 0x10) >> 2;
                } else {
                    uint8_t value12 = RAM8(0x00F4);
                    uint8_t value13 = RAM8(0x0006);
                    RAM8(0x0006) = ((value12 & 1) << 1) ^ value13;
                    a1 = ((value12 & 1) << 1) ^ value13;
                }
                a2 = a1;
            } else {
                RAM8(0xE00D + value) = 0;
                a2 = 0;
            }
            a3 = a2;
            overflow1 = ((value9 ^ 0x10) & (value9 ^ (uint8_t)(value9 - 0x10)) & 0x80) != 0;
        }
        uint8_t a4 = a3;
        uint8_t a_hi1 = (uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) >> 8;
        uint8_t x1 = (uint8_t)(value4 | 0x90 | 0xE000);
        uint8_t y1 = (uint8_t)(value4 | 0x90 | 0xE000);
        bool carry1 = 0;
        bool zero1 = (uint8_t)(value4 | 0x90 | 0xE000) == 0;
        bool negative1 = (uint8_t)(value4 | 0x90 | 0xE000) & 0x80;
        bool overflow2 = overflow1;
        for (;;) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
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
    if (!((uint8_t)(value2 << 1) & 0x80)) {
        uint16_t value15 = RAM16(0xE083 + value);
        RAM16_SET(0x0002, value15 & 0x0F);
        if ((value15 & 0x0F) == 0) {
            r->a = value15 & 0x0F;
            r->x = value;
            r->c = value2 & 0x80;
            r->z = (value15 & 0x0F) == 0;
            r->n = value15 & 0x0F & 0x8000;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value16 = RAM16(0x0014);
        RAM16_SET(0x0004, RAM16(0xE020 + value));
        uint16_t value18 = RAM16(0xE074 + value);
        uint16_t value19 = RAM16(0xE045 + value);
        uint16_t value20 = RAM16(0xE022 + value);
        RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value18 & 0x7F) + value19) ^ 0xFFFF) + value20 + 1));
        uint8_t value21 = RAM8(0xE00D + value);
        uint8_t a7;
        bool overflow3;
        if (value21 == 0) {
            a7 = value21;
            overflow3 = (((uint16_t)((value18 & 0x7F) + value19) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value18 & 0x7F) + value19) ^ 0xFFFF) + value20 + 1)) & (value20 ^ (uint16_t)(((uint16_t)((value18 & 0x7F) + value19) ^ 0xFFFF) + value20 + 1)) & 0x8000) != 0;
        } else {
            RAM8(0xE00D + value) = (uint8_t)(value21 - 0x10);
            uint8_t a6;
            if (value21 >= 0x10) {
                if ((uint8_t)(value21 - 0x10) & 0x01) {
                    RAM8(0x0000 + sp0) = (uint8_t)(value21 - 0x10) >> 1;
                    RAM8(0x0004) = ((RAM8(0x00F4) & 1) << 1) ^ RAM8(0x0004);
                }
                uint8_t a5;
                if (!((uint8_t)(value21 - 0x10) >> 1 & 0x01)) {
                    a5 = (uint8_t)(value21 - 0x10) >> 2;
                } else {
                    uint8_t value24 = RAM8(0x00F4);
                    uint8_t value25 = RAM8(0x0006);
                    RAM8(0x0006) = ((value24 & 1) << 1) ^ value25;
                    a5 = ((value24 & 1) << 1) ^ value25;
                }
                a6 = a5;
            } else {
                RAM8(0xE00D + value) = 0;
                a6 = 0;
            }
            a7 = a6;
            overflow3 = ((value21 ^ 0x10) & (value21 ^ (uint8_t)(value21 - 0x10)) & 0x80) != 0;
        }
        uint8_t a8 = a7;
        uint8_t a_hi2 = (uint16_t)(((uint16_t)((value18 & 0x7F) + value19) ^ 0xFFFF) + value20 + 1) >> 8;
        uint8_t x2 = (uint8_t)(value16 | 0x90 | 0xE000);
        uint8_t y2 = (uint8_t)(value16 | 0x90 | 0xE000);
        bool carry2 = 0;
        bool zero2 = (uint8_t)(value16 | 0x90 | 0xE000) == 0;
        bool negative2 = (uint8_t)(value16 | 0x90 | 0xE000) & 0x80;
        bool overflow4 = overflow3;
        for (;;) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
        r->a = (a_hi2 << 8) | a8;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->z = zero2;
        r->n = negative2;
        r->v = overflow4;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value27 = RAM8(0x00F4);
    if (!(value27 & 0x01)) {
        uint16_t value28 = RAM16(0xE083 + value);
        RAM16_SET(0x0002, value28 & 0x0F);
        if ((value28 & 0x0F) == 0) {
            r->a = value28 & 0x0F;
            r->x = value;
            r->c = value27 & 0x01;
            r->z = (value28 & 0x0F) == 0;
            r->n = value28 & 0x0F & 0x8000;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value29 = RAM16(0x0014);
        RAM16_SET(0x0004, RAM16(0xE020 + value));
        uint16_t value31 = RAM16(0xE074 + value);
        uint16_t value32 = RAM16(0xE045 + value);
        uint16_t value33 = RAM16(0xE022 + value);
        RAM16_SET(0x0006, (uint16_t)(((uint16_t)((value31 & 0x7F) + value32) ^ 0xFFFF) + value33 + 1));
        uint8_t value34 = RAM8(0xE00D + value);
        uint8_t a11;
        bool overflow5;
        if (value34 == 0) {
            a11 = value34;
            overflow5 = (((uint16_t)((value31 & 0x7F) + value32) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value31 & 0x7F) + value32) ^ 0xFFFF) + value33 + 1)) & (value33 ^ (uint16_t)(((uint16_t)((value31 & 0x7F) + value32) ^ 0xFFFF) + value33 + 1)) & 0x8000) != 0;
        } else {
            RAM8(0xE00D + value) = (uint8_t)(value34 - 0x10);
            uint8_t a10;
            if (value34 >= 0x10) {
                if ((uint8_t)(value34 - 0x10) & 0x01) {
                    RAM8(0x0000 + sp0) = (uint8_t)(value34 - 0x10) >> 1;
                    RAM8(0x0004) = ((RAM8(0x00F4) & 1) << 1) ^ RAM8(0x0004);
                }
                uint8_t a9;
                if (!((uint8_t)(value34 - 0x10) >> 1 & 0x01)) {
                    a9 = (uint8_t)(value34 - 0x10) >> 2;
                } else {
                    uint8_t value37 = RAM8(0x00F4);
                    uint8_t value38 = RAM8(0x0006);
                    RAM8(0x0006) = ((value37 & 1) << 1) ^ value38;
                    a9 = ((value37 & 1) << 1) ^ value38;
                }
                a10 = a9;
            } else {
                RAM8(0xE00D + value) = 0;
                a10 = 0;
            }
            a11 = a10;
            overflow5 = ((value34 ^ 0x10) & (value34 ^ (uint8_t)(value34 - 0x10)) & 0x80) != 0;
        }
        uint8_t a12 = a11;
        uint8_t a_hi3 = (uint16_t)(((uint16_t)((value31 & 0x7F) + value32) ^ 0xFFFF) + value33 + 1) >> 8;
        uint8_t x3 = (uint8_t)(value29 | 0x90 | 0xE000);
        uint8_t y3 = (uint8_t)(value29 | 0x90 | 0xE000);
        bool carry3 = 0;
        bool zero3 = (uint8_t)(value29 | 0x90 | 0xE000) == 0;
        bool negative3 = (uint8_t)(value29 | 0x90 | 0xE000) & 0x80;
        bool overflow6 = overflow5;
        for (;;) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
        r->a = (a_hi3 << 8) | a12;
        r->x = x3;
        r->y = y3;
        r->c = carry3;
        r->z = zero3;
        r->n = negative3;
        r->v = overflow6;
        r->mf = 1;
        RETURN_RTS(c);
    }
    SET_A8(r, value27 >> 1);
    r->x = value;
    r->c = value27 & 0x01;
    r->z = value27 >> 1 == 0;
    r->n = value27 >> 1 & 0x80;
    r->mf = 1;
    RETURN_RTS(c);
}

/* C0E5CE prepare_and_emit_actor_body_sprites_v4   [class A, 257 bytes, 129 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
 * Entry: M=any X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void prepare_and_emit_actor_body_sprites_v4(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x14));
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xE00E + value);
    if (value2 == 0) {
        uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0xE083 + value);
        BUS16_SET(c, (uint16_t)(dp + 2), value3 & 0x0F);
        if ((value3 & 0x0F) == 0) {
            r->a = value3 & 0x0F;
            r->x = value;
            r->z = (value3 & 0x0F) == 0;
            r->n = value3 & 0x0F & 0x8000;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0x14));
        uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0xE020 + value5);
        BUS16_SET(c, (uint16_t)(dp + 4), value6);
        uint16_t value7 = BUS16_RDP(c, (db << 0x10) + 0xE074 + value5);
        uint16_t value8 = BUS16_RDP(c, (db << 0x10) + 0xE045 + value5);
        uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0xE022 + value5);
        BUS16_SET(c, (uint16_t)(dp + 6), (uint16_t)(((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF) + value9 + 1));
        uint8_t value10 = BUS8_RDP(c, (db << 0x10) + 0xE00D + value5);
        uint8_t a4;
        bool overflow1;
        if (value10 == 0) {
            a4 = value10;
            overflow1 = (((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF) + value9 + 1)) & (value9 ^ (uint16_t)(((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF) + value9 + 1)) & 0x8000) != 0;
        } else {
            BUS8_SET(c, (db << 0x10) + 0xE00D + value5, (uint8_t)(value10 - 0x10));
            uint8_t a3;
            if (value10 >= 0x10) {
                uint8_t a1;
                if (!((uint8_t)(value10 - 0x10) & 0x01)) {
                    a1 = (uint8_t)(value10 - 0x10) >> 1;
                } else {
                    RAM8(0x0000 + sp0) = (uint8_t)(value10 - 0x10) >> 1;
                    uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                    uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 4));
                    BUS8_SET(c, (uint16_t)(dp + 4), ((value11 & 1) << 1) ^ value12);
                    a1 = RAM8(0x0000 + sp0);
                }
                uint8_t a2;
                if (!(a1 & 0x01)) {
                    a2 = a1 >> 1;
                } else {
                    uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 6));
                    BUS8_SET(c, (uint16_t)(dp + 6), ((value14 & 1) << 1) ^ value15);
                    a2 = ((value14 & 1) << 1) ^ value15;
                }
                a3 = a2;
            } else {
                BUS8_SET(c, (db << 0x10) + 0xE00D + value5, 0);
                a3 = 0;
            }
            a4 = a3;
            overflow1 = ((value10 ^ 0x10) & (value10 ^ (uint8_t)(value10 - 0x10)) & 0x80) != 0;
        }
        uint8_t a5 = a4;
        uint8_t a_hi1 = (uint16_t)(((uint16_t)((value7 & 0x7F) + value8) ^ 0xFFFF) + value9 + 1) >> 8;
        uint8_t x1 = (uint8_t)(value4 | 0x90 | 0xE000);
        uint8_t y1 = (uint8_t)(value4 | 0x90 | 0xE000);
        bool carry1 = 0;
        bool zero1 = (uint8_t)(value4 | 0x90 | 0xE000) == 0;
        bool negative1 = (uint8_t)(value4 | 0x90 | 0xE000) & 0x80;
        bool overflow2 = overflow1;
        for (;;) {
            uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp + 0x7C));
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
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
    if (!((uint8_t)(value2 << 1) & 0x80)) {
        uint16_t value17 = BUS16_RDP(c, (db << 0x10) + 0xE083 + value);
        BUS16_SET(c, (uint16_t)(dp + 2), value17 & 0x0F);
        if ((value17 & 0x0F) == 0) {
            r->a = value17 & 0x0F;
            r->x = value;
            r->c = value2 & 0x80;
            r->z = (value17 & 0x0F) == 0;
            r->n = value17 & 0x0F & 0x8000;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp + 0x14));
        uint16_t value20 = BUS16_RDP(c, (db << 0x10) + 0xE020 + value19);
        BUS16_SET(c, (uint16_t)(dp + 4), value20);
        uint16_t value21 = BUS16_RDP(c, (db << 0x10) + 0xE074 + value19);
        uint16_t value22 = BUS16_RDP(c, (db << 0x10) + 0xE045 + value19);
        uint16_t value23 = BUS16_RDP(c, (db << 0x10) + 0xE022 + value19);
        BUS16_SET(c, (uint16_t)(dp + 6), (uint16_t)(((uint16_t)((value21 & 0x7F) + value22) ^ 0xFFFF) + value23 + 1));
        uint8_t value24 = BUS8_RDP(c, (db << 0x10) + 0xE00D + value19);
        uint8_t a9;
        bool overflow3;
        if (value24 == 0) {
            a9 = value24;
            overflow3 = (((uint16_t)((value21 & 0x7F) + value22) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value21 & 0x7F) + value22) ^ 0xFFFF) + value23 + 1)) & (value23 ^ (uint16_t)(((uint16_t)((value21 & 0x7F) + value22) ^ 0xFFFF) + value23 + 1)) & 0x8000) != 0;
        } else {
            BUS8_SET(c, (db << 0x10) + 0xE00D + value19, (uint8_t)(value24 - 0x10));
            uint8_t a8;
            if (value24 >= 0x10) {
                uint8_t a6;
                if (!((uint8_t)(value24 - 0x10) & 0x01)) {
                    a6 = (uint8_t)(value24 - 0x10) >> 1;
                } else {
                    RAM8(0x0000 + sp0) = (uint8_t)(value24 - 0x10) >> 1;
                    uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                    uint8_t value26 = BUS8_RDP(c, (uint16_t)(dp + 4));
                    BUS8_SET(c, (uint16_t)(dp + 4), ((value25 & 1) << 1) ^ value26);
                    a6 = RAM8(0x0000 + sp0);
                }
                uint8_t a7;
                if (!(a6 & 0x01)) {
                    a7 = a6 >> 1;
                } else {
                    uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                    uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 6));
                    BUS8_SET(c, (uint16_t)(dp + 6), ((value28 & 1) << 1) ^ value29);
                    a7 = ((value28 & 1) << 1) ^ value29;
                }
                a8 = a7;
            } else {
                BUS8_SET(c, (db << 0x10) + 0xE00D + value19, 0);
                a8 = 0;
            }
            a9 = a8;
            overflow3 = ((value24 ^ 0x10) & (value24 ^ (uint8_t)(value24 - 0x10)) & 0x80) != 0;
        }
        uint8_t a10 = a9;
        uint8_t a_hi2 = (uint16_t)(((uint16_t)((value21 & 0x7F) + value22) ^ 0xFFFF) + value23 + 1) >> 8;
        uint8_t x2 = (uint8_t)(value18 | 0x90 | 0xE000);
        uint8_t y2 = (uint8_t)(value18 | 0x90 | 0xE000);
        bool carry2 = 0;
        bool zero2 = (uint8_t)(value18 | 0x90 | 0xE000) == 0;
        bool negative2 = (uint8_t)(value18 | 0x90 | 0xE000) & 0x80;
        bool overflow4 = overflow3;
        for (;;) {
            uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp + 0x7C));
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
        r->a = (a_hi2 << 8) | a10;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->z = zero2;
        r->n = negative2;
        r->v = overflow4;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
    if (!(value31 & 0x01)) {
        uint16_t value32 = BUS16_RDP(c, (db << 0x10) + 0xE083 + value);
        BUS16_SET(c, (uint16_t)(dp + 2), value32 & 0x0F);
        if ((value32 & 0x0F) == 0) {
            r->a = value32 & 0x0F;
            r->x = value;
            r->c = value31 & 0x01;
            r->z = (value32 & 0x0F) == 0;
            r->n = value32 & 0x0F & 0x8000;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp + 0x14));
        uint16_t value35 = BUS16_RDP(c, (db << 0x10) + 0xE020 + value34);
        BUS16_SET(c, (uint16_t)(dp + 4), value35);
        uint16_t value36 = BUS16_RDP(c, (db << 0x10) + 0xE074 + value34);
        uint16_t value37 = BUS16_RDP(c, (db << 0x10) + 0xE045 + value34);
        uint16_t value38 = BUS16_RDP(c, (db << 0x10) + 0xE022 + value34);
        BUS16_SET(c, (uint16_t)(dp + 6), (uint16_t)(((uint16_t)((value36 & 0x7F) + value37) ^ 0xFFFF) + value38 + 1));
        uint8_t value39 = BUS8_RDP(c, (db << 0x10) + 0xE00D + value34);
        uint8_t a14;
        bool overflow5;
        if (value39 == 0) {
            a14 = value39;
            overflow5 = (((uint16_t)((value36 & 0x7F) + value37) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value36 & 0x7F) + value37) ^ 0xFFFF) + value38 + 1)) & (value38 ^ (uint16_t)(((uint16_t)((value36 & 0x7F) + value37) ^ 0xFFFF) + value38 + 1)) & 0x8000) != 0;
        } else {
            BUS8_SET(c, (db << 0x10) + 0xE00D + value34, (uint8_t)(value39 - 0x10));
            uint8_t a13;
            if (value39 >= 0x10) {
                uint8_t a11;
                if (!((uint8_t)(value39 - 0x10) & 0x01)) {
                    a11 = (uint8_t)(value39 - 0x10) >> 1;
                } else {
                    RAM8(0x0000 + sp0) = (uint8_t)(value39 - 0x10) >> 1;
                    uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                    uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp + 4));
                    BUS8_SET(c, (uint16_t)(dp + 4), ((value40 & 1) << 1) ^ value41);
                    a11 = RAM8(0x0000 + sp0);
                }
                uint8_t a12;
                if (!(a11 & 0x01)) {
                    a12 = a11 >> 1;
                } else {
                    uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp + 0xF4));
                    uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp + 6));
                    BUS8_SET(c, (uint16_t)(dp + 6), ((value43 & 1) << 1) ^ value44);
                    a12 = ((value43 & 1) << 1) ^ value44;
                }
                a13 = a12;
            } else {
                BUS8_SET(c, (db << 0x10) + 0xE00D + value34, 0);
                a13 = 0;
            }
            a14 = a13;
            overflow5 = ((value39 ^ 0x10) & (value39 ^ (uint8_t)(value39 - 0x10)) & 0x80) != 0;
        }
        uint8_t a15 = a14;
        uint8_t a_hi3 = (uint16_t)(((uint16_t)((value36 & 0x7F) + value37) ^ 0xFFFF) + value38 + 1) >> 8;
        uint8_t x3 = (uint8_t)(value33 | 0x90 | 0xE000);
        uint8_t y3 = (uint8_t)(value33 | 0x90 | 0xE000);
        bool carry3 = 0;
        bool zero3 = (uint8_t)(value33 | 0x90 | 0xE000) == 0;
        bool negative3 = (uint8_t)(value33 | 0x90 | 0xE000) & 0x80;
        bool overflow6 = overflow5;
        for (;;) {
            uint8_t value45 = BUS8_RDP(c, (uint16_t)(dp + 0x7C));
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
        r->a = (a_hi3 << 8) | a15;
        r->x = x3;
        r->y = y3;
        r->c = carry3;
        r->z = zero3;
        r->n = negative3;
        r->v = overflow6;
        r->mf = 1;
        RETURN_RTS(c);
    }
    SET_A8(r, value31 >> 1);
    r->x = value;
    r->c = value31 & 0x01;
    r->z = value31 >> 1 == 0;
    r->n = value31 >> 1 & 0x80;
    r->mf = 1;
    RETURN_RTS(c);
}

/* C0E5F5 sub_C0E5F5   [class A, 218 bytes, 110 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
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
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
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

/* C0E5F5 sub_C0E5F5_v3   [class A, 218 bytes, 110 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
 * Entry: M=16 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void sub_C0E5F5_v3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x14));
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
    uint8_t x1 = y;
    uint8_t y1 = y;
    bool carry1 = 0;
    bool zero1 = y == 0;
    bool negative1 = y & 0x80;
    bool overflow2 = overflow1;
    for (;;) {
        uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 0x7C));
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
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

/* C0E5F5 sub_C0E5F5_v4   [class A, 218 bytes, 110 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
 * Entry: M=16 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void sub_C0E5F5_v4(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t y = r->y;
    uint8_t value = RAM8(0x0014);
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
    uint8_t x1 = y;
    uint8_t y1 = y;
    bool carry1 = 0;
    bool zero1 = y == 0;
    bool negative1 = y & 0x80;
    bool overflow2 = overflow1;
    for (;;) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
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
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
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
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
 * Entry: M=any X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void emit_packed_actor_sprite_list_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a1 = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = x;
    uint8_t y1 = y;
    bool carry1 = carry;
    bool zero1 = zero;
    bool negative1 = negative;
    bool overflow1 = overflow;
    for (;;) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    RETURN_RTS(c);
}

/* C0E640 emit_packed_actor_sprite_list_v3   [class A, 143 bytes, 72 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void emit_packed_actor_sprite_list_v3(SomCtx *c)
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

/* C0E640 emit_packed_actor_sprite_list_v4   [class A, 143 bytes, 72 instructions]
 * Source: src/rom/update_actor_screen_position_and_emit_sprites.s
 * Subroutine of update_actor_screen_position_and_emit_sprites, translated in place.
 * Entry: M=any X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void emit_packed_actor_sprite_list_v4(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 1)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a1 = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = x;
    uint8_t y1 = y;
    bool carry1 = carry;
    bool zero1 = zero;
    bool negative1 = negative;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x7C));
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    RETURN_RTS(c);
}

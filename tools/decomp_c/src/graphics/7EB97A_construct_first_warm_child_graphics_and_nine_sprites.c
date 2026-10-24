#include "som_c.h"

/* 7EB97A construct_first_warm_child_graphics_and_nine_sprites   [class B, 135 bytes, 68 instructions]
 * Source: src/boot/construct_first_warm_child_graphics_and_nine_sprites.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYCV.
 */
static void construct_first_warm_child_graphics_and_nine_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0D) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = (uint16_t)(sp0 - 0x0D);
    r->c = (uint16_t)(sp0 - 3) >= 0x0A;
    r->z = (uint16_t)(sp0 - 0x0D) == 0;
    r->n = (uint16_t)(sp0 - 0x0D) & 0x8000;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0D);
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB989, 0x7EBA7F); GUARD_JSR(c, sp_call, 0xB989); } /* prepare_graphics_palette_and_background */
    r->sp += 13;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | 0;
    r->x = 0x18;
    r->z = 1;
    r->n = 0;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB991, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xB991); } /* allocate_and_fill_bytes */
    r->sp += 13;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x0D), x_ret2);
    r->a = (a_all2 >> 8 << 8) | 8;
    r->z = 0;
    r->n = 0;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB998, 0x7EBBAB); GUARD_JSR(c, sp_call, 0xB998); } /* allocate_palette_slot */
    r->sp += 13;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret3 = r->x;
    RAM8(0x0000 + sp0 - 0x0D) = x_ret3 >> 8;
    RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)x_ret3;
    r->a = 0x7E1E;
    r->y = 0x5180;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB9A4, 0x7EBC9A); GUARD_JSR(c, sp_call, 0xB9A4); } /* copy_palette_colours */
    r->sp += 15;
    if (r->xf != 0) { c->fail = 3; return; }
    uint8_t value = RAM8(0x0000 + sp0 - 0x0E);
    uint8_t value2 = RAM8(0x0000 + sp0 - 0x0D);
    r->x = (value2 << 8) | value;
    r->z = ((value2 << 8) | value) == 0;
    r->n = ((value2 << 8) | value) & 0x8000;
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB9A8, 0x7EBBFE); GUARD_JSR(c, sp_call, 0xB9A8); } /* queue_palette_upload */
    r->sp += 13;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all5 = r->a;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
    BUS8_SET(c, (db_ret3 << 0x10) + 0x16 + value3, (uint8_t)a_all5);
    BUS8_SET(c, (uint16_t)(dp_ret2 + 5), (uint8_t)a_all5);
    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), 9);
    BUS8_SET(c, (uint16_t)(dp_ret2 + 7), 0);
    BUS8_SET(c, (uint16_t)(dp_ret2 + 8), 0);
    uint8_t a1 = 9;
    uint8_t a_hi1 = a_all5 >> 8;
    uint16_t x1 = value3;
    uint16_t y1 = y_ret5;
    bool carry1 = carry_ret5;
    bool zero1 = 0;
    bool negative1 = 0;
    bool overflow1 = overflow_ret5;
    uint8_t data_bank = db_ret3;
    uint16_t direct_page = dp_ret2;
    for (;;) {
        BUS16_SET(c, (uint16_t)(direct_page + 9), x1);
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB9BC, 0x7EB6D0); GUARD_JSR(c, sp_call, 0xB9BC); } /* allocate_native_single_sprite_record_prefix */
        r->sp += 13;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all6 = r->a;
        uint16_t x_ret6 = r->x;
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
        BUS8_SET(c, (db_ret4 << 0x10) + 1 + x_ret6, value4);
        BUS8_SET(c, (db_ret4 << 0x10) + 3 + x_ret6, 0);
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
        BUS8_SET(c, (db_ret4 << 0x10) + 2 + x_ret6, (uint8_t)(RAM8(0x6028 + value5) + 0x86));
        uint8_t value7 = RAM8(0x6028 + (uint16_t)(value5 + 1));
        BUS16_SET(c, (db_ret4 << 0x10) + 4 + x_ret6, (((a_all6 >> 8 << 8) | value7) & 0xFF) + 0x60);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value5 + 2));
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 9));
        BUS16_SET(c, (db_ret4 << 0x10) + value8, x_ret6);
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
        BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value9 - 1));
        a1 = (uint8_t)x_ret6;
        a_hi1 = x_ret6 >> 8;
        x1 = (uint16_t)(value8 + 2);
        y1 = x_ret6;
        carry1 = (((a_all6 >> 8 << 8) | value7) & 0xFF) + 0x60 > 0xFFFF;
        zero1 = (uint8_t)(value9 - 1) == 0;
        negative1 = (uint8_t)(value9 - 1) & 0x80;
        overflow1 = (((((a_all6 >> 8 << 8) | value7) & 0xFF) ^ (((a_all6 >> 8 << 8) | value7) & 0xFF) + 0x60) & ((((a_all6 >> 8 << 8) | value7) & 0xFF) + 0x60 ^ 0x60) & 0x8000) != 0;
        data_bank = db_ret4;
        direct_page = dp_ret3;
        if (!((uint8_t)(value9 - 1) != 0)) break;
    }
    uint16_t value10 = BUS16_RDP(c, (uint16_t)(direct_page + 3));
    uint8_t value11 = RAM8(0x0000 + sp0 - 2);
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->x = value10;
    r->y = y1;
    r->c = value11 & 0x01;
    r->v = value11 & 0x40;
    r->mf = value11 & 0x20;
    r->xf = value11 & 0x10;
    r->db = data_bank;
    r->dp = (value13 << 8) | value12;
    r->i = value11 & 0x04;
    r->d = value11 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB97A, SOM_RTS, "gen", construct_first_warm_child_graphics_and_nine_sprites, 0, L_X | L_Y | L_C | L_V, 15, 1, 0, 135, 68)

#include "som_c.h"

/* 7E8686 queue_colour_sample_palette   [class B, 107 bytes, 56 instructions]
 * Source: src/boot/queue_colour_sample_palette.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYCZNV.
 */
static void queue_colour_sample_palette(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0A) = 0x7F;
    r->a = 0;
    r->x = 0x0200;
    r->c = (uint16_t)(sp0 - 3) >= 6;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x86A2, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x86A2); } /* allocate_and_fill_bytes */
    r->sp += 10;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM16_SET(0x1001C, x_ret);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), 0xE8);
    uint16_t value = RAM16(0x1001A);
    uint8_t a1 = 0xE8;
    uint8_t a_hi1 = 0;
    uint16_t x1 = value;
    uint16_t y1 = x_ret;
    bool carry1 = carry_ret;
    bool zero1 = value == 0;
    bool negative1 = value & 0x8000;
    bool overflow1 = overflow_ret;
    uint16_t direct_page = (uint16_t)(sp0 - 9);
    for (;;) {
        RAM8(0x0000 + sp0 - 0x0A) = x1 >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x1;
        RAM8(0x0000 + sp0 - 0x0C) = y1 >> 8;
        RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)y1;
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7F;
        r->dp = direct_page;
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSR(c, 0x86B3, 0x7E8411); GUARD_JSR(c, sp_call, 0x86B3); } /* pack_five_bit_colour_components */
        r->sp += 14;
        uint16_t dp_ret = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint8_t value2 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value3 = RAM8(0x0000 + sp0 - 0x0C);
        BUS16_SET(c, 0x7F0000 + ((value3 << 8) | value2), a_all2);
        uint8_t value4 = RAM8(0x0000 + sp0 - 0x0B);
        uint8_t value5 = RAM8(0x0000 + sp0 - 0x0A);
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value6 - 1));
        a1 = (uint8_t)(((value5 << 8) | value4) + 4);
        a_hi1 = (uint16_t)(((value5 << 8) | value4) + 4) >> 8;
        x1 = (uint16_t)(((value5 << 8) | value4) + 4);
        y1 = (uint16_t)(((value3 << 8) | value2) + 2);
        carry1 = ((value5 << 8) | value4) + 4 > 0xFFFF;
        zero1 = (uint16_t)(value6 - 1) == 0;
        negative1 = (uint16_t)(value6 - 1) & 0x8000;
        overflow1 = ((((value5 << 8) | value4) ^ (uint16_t)(((value5 << 8) | value4) + 4)) & ((uint16_t)(((value5 << 8) | value4) + 4) ^ 4) & 0x8000) != 0;
        direct_page = dp_ret;
        if (!((uint16_t)(value6 - 1) != 0)) break;
    }
    r->a = 0x0A;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7F;
    r->dp = direct_page;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x86C9, 0x7E8FC7); GUARD_JSR(c, sp_call, 0x86C9); } /* allocate_transfer_descriptor */
    r->sp += 10;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t x_ret4 = r->x;
    uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x1C);
    BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret4, value7);
    BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret4, 0x01D0);
    BUS8_SET(c, (db_ret << 0x10) + 0x0A + x_ret4, 0x0F);
    BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret4, 0x7F);
    r->a = 0x017F;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x86E4, 0x7E90DA); GUARD_JSR(c, sp_call, 0x86E4); } /* submit_transfer_or_program_hdma */
    r->sp += 10;
    uint8_t value8 = RAM8(0x0000 + sp0 - 9);
    uint8_t value9 = RAM8(0x0000 + sp0 - 2);
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    r->c = value9 & 0x01;
    r->z = ((value11 << 8) | value10) == 0;
    r->n = ((value11 << 8) | value10) & 0x8000;
    r->v = value9 & 0x40;
    r->mf = value9 & 0x20;
    r->xf = value9 & 0x10;
    r->db = value8;
    r->dp = (value11 << 8) | value10;
    r->i = value9 & 0x04;
    r->d = value9 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8686, SOM_RTS, "gen", queue_colour_sample_palette, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 14, 1, 0, 107, 56)

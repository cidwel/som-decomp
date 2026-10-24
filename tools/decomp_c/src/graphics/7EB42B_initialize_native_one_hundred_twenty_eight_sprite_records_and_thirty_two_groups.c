#include "som_c.h"

/* 7EB42B initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups   [class B, 241 bytes, 128 instructions]
 * Source: src/boot/initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: CV.
 */
static void initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x3 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x102CF) = (uint8_t)value & 2;
    RAM8(0x102CE) = (uint8_t)value & 1;
    RAM8(0x0003 + (uint16_t)(sp0 - 7)) = value >> 8;
    RAM8(0x102D0) = 0;
    r->a = (((uint8_t)value & 1) << 8) | 0;
    r->x = 0x0800;
    r->c = (uint16_t)(sp0 - 5) >= 2;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB45B, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xB45B); } /* allocate_and_fill_bytes */
    r->sp += 8;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x102C8, x_ret);
    r->a = (a_all >> 8 << 8) | 0;
    r->x = 0x0220;
    r->z = 1;
    r->n = 0;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB466, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xB466); } /* allocate_and_fill_bytes */
    r->sp += 8;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x102CC, x_ret2);
    r->a = (a_all2 >> 8 << 8) | 0;
    r->x = 0x0200;
    r->z = 0;
    r->n = 0;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB471, 0x7EB0A1); GUARD_JSR(c, sp_call, 0xB471); } /* allocate_and_fill_bytes */
    r->sp += 8;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    uint16_t x_ret3 = r->x;
    RAM16_SET(0x102CA, x_ret3);
    uint16_t value2 = RAM16(0x102C8);
    RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0x80;
    uint8_t a_hi1 = a_all3 >> 8;
    uint16_t x1 = value2;
    uint16_t direct_page = (uint16_t)(sp0 - 7);
    for (;;) {
        RAM8(0x0000 + sp0 - 8) = x1 >> 8;
        RAM8(0x0000 + sp0 - 9) = (uint8_t)x1;
        BUS16_SET(c, 0x7F0002 + x1, 0xFFF0);
        BUS16_SET(c, 0x7F0004 + x1, 0);
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
        BUS8_SET(c, 0x7F000A + x1, (uint8_t)(0x80 - value3));
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(direct_page + 3));
        BUS8_SET(c, 0x7F000B + x1, value4 >> 2);
        BUS8_SET(c, 0x7F0008 + x1, 0);
        r->a = (0xFF << 8) | (value4 >> 2);
        r->x = x1;
        r->c = value4 >> 1 & 0x01;
        r->z = value4 >> 2 == 0;
        r->n = value4 >> 2 & 0x80;
        r->v = ((value3 ^ 0x80) & ((uint8_t)(0x80 - value3) ^ 0x80) & 0x80) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7F;
        r->dp = direct_page;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB49E, 0x7EB53D); GUARD_JSR(c, sp_call, 0xB49E); } /* publish_native_sprite_record_to_shadow */
        r->sp += 10;
        uint16_t dp_ret = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value5 = RAM8(0x0000 + sp0 - 9);
        uint8_t value6 = RAM8(0x0000 + sp0 - 8);
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value7 - 1));
        a_hi1 = (uint16_t)(((value6 << 8) | value5) + 0x10) >> 8;
        x1 = (uint16_t)(((value6 << 8) | value5) + 0x10);
        direct_page = dp_ret;
        if (!((uint8_t)(value7 - 1) != 0)) break;
    }
    uint16_t value8 = RAM16(0x102CA);
    uint16_t value9 = RAM16(0x102C8);
    BUS16_SET(c, (uint16_t)(direct_page + 1), 0x20);
    uint8_t a_hi2 = 0;
    uint16_t x2 = value8;
    uint16_t y1 = value9;
    for (;;) {
        BUS16_SET(c, 0x7F0000 + x2, y1);
        BUS16_SET(c, 0x7F000C + y1, x2);
        BUS16_SET(c, 0x7F0002 + x2, (uint16_t)(y1 + 0x10));
        BUS16_SET(c, 0x7F000C + (uint16_t)(y1 + 0x10), x2);
        BUS16_SET(c, 0x7F0004 + x2, (uint16_t)(y1 + 0x20));
        BUS16_SET(c, 0x7F000C + (uint16_t)(y1 + 0x20), x2);
        BUS16_SET(c, 0x7F0006 + x2, (uint16_t)(y1 + 0x30));
        BUS16_SET(c, 0x7F000C + (uint16_t)(y1 + 0x30), x2);
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
        BUS8_SET(c, 0x7F0009 + x2, (uint8_t)((uint8_t)(0x20 - value10) << 2));
        BUS8_SET(c, 0x7F000A + x2, (uint8_t)((uint8_t)(0x20 - value10) << 3));
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(direct_page + 3));
        BUS8_SET(c, 0x7F000B + x2, value11);
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
        BUS16_RMW_SET(c, (uint16_t)(direct_page + 1), (uint16_t)(value12 - 1));
        uint8_t a_hi2_next = (uint16_t)(x2 + 0x10) >> 8;
        uint16_t x2_next = (uint16_t)(x2 + 0x10);
        uint16_t y1_next = (uint16_t)(y1 + 0x40);
        a_hi2 = a_hi2_next;
        x2 = x2_next;
        y1 = y1_next;
        if (!((uint16_t)(value12 - 1) != 0)) break;
    }
    uint8_t value13 = RAM8(0x0000 + sp0 - 7);
    uint8_t value18 = RAM8(0x0000 + sp0 - 2);
    uint8_t value19 = RAM8(0x0000 + sp0 - 1);
    uint8_t value20 = RAM8(0x0000 + sp0);
    r->c = value18 & 0x01;
    r->v = value18 & 0x40;
    r->mf = value18 & 0x20;
    r->xf = value18 & 0x10;
    r->db = value13;
    r->dp = (value20 << 8) | value19;
    r->i = value18 & 0x04;
    r->d = value18 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB42B, SOM_RTS, "gen", initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups, 0, L_C | L_V, 10, 1, 0, 241, 128)

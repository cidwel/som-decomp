#include "som_c.h"

/* 7EB786 release_native_sprite_or_linked_group   [class B, 51 bytes, 32 instructions]
 * Source: src/boot/release_native_sprite_or_linked_group.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$06F4.  Callers read: ABXYCV.
 */
static void release_native_sprite_or_linked_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x06F4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xF4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    uint8_t value = RAM8(0x102CE);
    bool x_flag;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    uint16_t direct_page2;
    if (value == 0) {
        BUS8_SET(c, 0x7F0008 + x, 0);
        RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 4;
        uint8_t a_hi1 = (uint16_t)(sp0 - 4) >> 8;
        uint16_t x1 = x;
        uint16_t y1 = x;
        bool carry1 = carry;
        bool overflow1 = overflow;
        uint16_t direct_page = (uint16_t)(sp0 - 4);
        for (;;) {
            RAM8(0x0000 + sp0 - 5) = y1 >> 8;
            RAM8(0x0000 + sp0 - 6) = (uint8_t)y1;
            uint16_t value2 = BUS16(c, 0x7F0000 + y1);
            r->x = value2;
            r->y = y1;
            r->c = carry1;
            r->z = value2 == 0;
            r->n = value2 & 0x8000;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = direct_page;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB7AC, 0x7EB75F); GUARD_JSR(c, sp_call, 0xB7AC); } /* release_native_sprite_record_and_hide_shadow */
            r->sp += 7;
            uint16_t dp_ret = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            uint8_t value3 = RAM8(0x0000 + sp0 - 6);
            uint8_t value4 = RAM8(0x0000 + sp0 - 5);
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value5 - 1));
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = (uint16_t)(((value4 << 8) | value3) + 2);
            carry1 = carry_ret;
            overflow1 = overflow_ret;
            direct_page = dp_ret;
            if (!((uint8_t)(value5 - 1) != 0)) break;
        }
        x_flag = 0;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        direct_page2 = direct_page;
    } else {
        r->a = ((uint16_t)(sp0 - 4) >> 8 << 8) | value;
        r->z = value == 0;
        r->n = value & 0x80;
        r->dp = (uint16_t)(sp0 - 4);
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB79B, 0x7EB75F); GUARD_JSR(c, sp_call, 0xB79B); } /* release_native_sprite_record_and_hide_shadow */
        r->sp += 5;
        uint16_t dp_ret2 = r->dp;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret3 = r->x;
        x_flag = x_ret2;
        a_hi2 = a_all2 >> 8;
        x2 = x_ret3;
        y2 = y;
        direct_page2 = dp_ret2;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | value7;
    r->x = x2;
    r->y = y2;
    r->c = value8 & 0x01;
    r->v = value8 & 0x40;
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->db = value6;
    r->dp = (value10 << 8) | value9;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB786, SOM_RTS, "gen", release_native_sprite_or_linked_group, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 7, 1, 0, 51, 32)

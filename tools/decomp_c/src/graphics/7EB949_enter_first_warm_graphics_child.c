#include "som_c.h"

/* 7EB949 enter_first_warm_graphics_child   [class C, 34 bytes, 23 instructions]
 * Source: src/boot/enter_first_warm_graphics_child.s
 * Documented in docs/boot-native-warm-child-resources.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void enter_first_warm_graphics_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB95B, 0x7EB97A); GUARD_JSR(c, sp_call, 0xB95B); } /* construct_first_warm_child_graphics_and_nine_sprites */
    r->sp += 6;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0001 + (uint16_t)(sp0 - 5)) = (uint8_t)x_ret2;
        uint8_t value = RAM8(0x0001 + (uint16_t)(sp0 - 5));
        r->x = value;
        r->y = (uint8_t)y_ret;
        r->z = value == 0;
        r->n = value & 0x80;
        r->xf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB962, 0x7EBA01); GUARD_JSR(c, sp_call, 0xB962); } /* enter_warm_child_animation_loop */
        r->sp += 6;
        uint16_t a_all2 = r->a;
        uint8_t value2 = RAM8(0x0000 + sp0 - 5);
        uint8_t value4 = RAM8(0x0000 + sp0 - 3);
        uint8_t value5 = RAM8(0x0000 + sp0 - 2);
        uint8_t value6 = RAM8(0x0000 + sp0 - 1);
        uint8_t value7 = RAM8(0x0000 + sp0);
        r->a = (a_all2 >> 8 << 8) | value4;
        r->c = value5 & 0x01;
        r->z = ((value7 << 8) | value6) == 0;
        r->n = ((value7 << 8) | value6) & 0x8000;
        r->v = value5 & 0x40;
        r->mf = value5 & 0x20;
        r->xf = value5 & 0x10;
        r->db = value2;
        r->dp = (value7 << 8) | value6;
        r->i = value5 & 0x04;
        r->d = value5 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    } else {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x_ret2);
        uint16_t value8 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
        r->x = value8;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB962, 0x7EBA01); GUARD_JSR(c, sp_call, 0xB962); } /* enter_warm_child_animation_loop */
        r->sp += 6;
        uint16_t a_all3 = r->a;
        uint8_t value9 = RAM8(0x0000 + sp0 - 5);
        uint8_t value11 = RAM8(0x0000 + sp0 - 3);
        uint8_t value12 = RAM8(0x0000 + sp0 - 2);
        uint8_t value13 = RAM8(0x0000 + sp0 - 1);
        uint8_t value14 = RAM8(0x0000 + sp0);
        r->a = (a_all3 >> 8 << 8) | value11;
        r->c = value12 & 0x01;
        r->z = ((value14 << 8) | value13) == 0;
        r->n = ((value14 << 8) | value13) & 0x8000;
        r->v = value12 & 0x40;
        r->mf = value12 & 0x20;
        r->xf = value12 & 0x10;
        r->db = value9;
        r->dp = (value14 << 8) | value13;
        r->i = value12 & 0x04;
        r->d = value12 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0x7EB949, SOM_RTL, "gen", enter_first_warm_graphics_child, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 34, 23)

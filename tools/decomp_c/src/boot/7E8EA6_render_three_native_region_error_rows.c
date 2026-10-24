#include "som_c.h"

/* 7E8EA6 render_three_native_region_error_rows   [class B, 58 bytes, 36 instructions]
 * Source: src/boot/render_three_native_region_error_rows.s
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: YCV.
 */
static void render_three_native_region_error_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
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
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    r->a = (uint16_t)(x + 0x03C0);
    r->x = 0x0215;
    r->y = (uint16_t)(x + 0x03C0);
    r->c = x + 0x03C0 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((x ^ (uint16_t)(x + 0x03C0)) & ((uint16_t)(x + 0x03C0) ^ 0x03C0) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8EC3, 0x7E8820); GUARD_JSR(c, sp_call, 0x8EC3); } /* expand_title_text_row */
    r->sp += 6;
    uint16_t dp_ret = r->dp;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
    if (x_ret) {
        r->a = (uint16_t)(value + 0x0440);
        r->x = (uint8_t)x_ret2;
        r->y = (uint8_t)(value + 0x0440);
        r->c = value + 0x0440 > 0xFFFF;
        r->z = (uint8_t)(value + 0x0440) == 0;
        r->n = (uint8_t)(value + 0x0440) & 0x80;
        r->v = ((value ^ (uint16_t)(value + 0x0440)) & ((uint16_t)(value + 0x0440) ^ 0x0440) & 0x8000) != 0;
        r->xf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8ECD, 0x7E8820); GUARD_JSR(c, sp_call, 0x8ECD); } /* expand_title_text_row */
        r->sp += 6;
        uint16_t dp_ret2 = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t x_ret4 = r->x;
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        if (x_ret3) {
            r->a = (uint16_t)(value2 + 0x04C0);
            r->x = (uint8_t)x_ret4;
            r->y = (uint8_t)(value2 + 0x04C0);
            r->c = value2 + 0x04C0 > 0xFFFF;
            r->z = (uint8_t)(value2 + 0x04C0) == 0;
            r->n = (uint8_t)(value2 + 0x04C0) & 0x80;
            r->v = ((value2 ^ (uint16_t)(value2 + 0x04C0)) & ((uint16_t)(value2 + 0x04C0) ^ 0x04C0) & 0x8000) != 0;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8ED7, 0x7E8820); GUARD_JSR(c, sp_call, 0x8ED7); } /* expand_title_text_row */
            r->sp += 6;
            uint8_t value3 = RAM8(0x0000 + sp0 - 5);
            uint8_t value6 = RAM8(0x0000 + sp0 - 2);
            uint8_t value7 = RAM8(0x0000 + sp0 - 1);
            uint8_t value8 = RAM8(0x0000 + sp0);
            r->c = value6 & 0x01;
            r->v = value6 & 0x40;
            r->mf = value6 & 0x20;
            r->xf = value6 & 0x10;
            r->db = value3;
            r->dp = (value8 << 8) | value7;
            r->i = value6 & 0x04;
            r->d = value6 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            r->a = (uint16_t)(value2 + 0x04C0);
            r->y = (uint16_t)(value2 + 0x04C0);
            r->c = value2 + 0x04C0 > 0xFFFF;
            r->z = (uint16_t)(value2 + 0x04C0) == 0;
            r->n = (uint16_t)(value2 + 0x04C0) & 0x8000;
            r->v = ((value2 ^ (uint16_t)(value2 + 0x04C0)) & ((uint16_t)(value2 + 0x04C0) ^ 0x04C0) & 0x8000) != 0;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8ED7, 0x7E8820); GUARD_JSR(c, sp_call, 0x8ED7); } /* expand_title_text_row */
            r->sp += 6;
            uint8_t value9 = RAM8(0x0000 + sp0 - 5);
            uint8_t value12 = RAM8(0x0000 + sp0 - 2);
            uint8_t value13 = RAM8(0x0000 + sp0 - 1);
            uint8_t value14 = RAM8(0x0000 + sp0);
            r->c = value12 & 0x01;
            r->v = value12 & 0x40;
            r->mf = value12 & 0x20;
            r->xf = value12 & 0x10;
            r->db = value9;
            r->dp = (value14 << 8) | value13;
            r->i = value12 & 0x04;
            r->d = value12 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        r->a = (uint16_t)(value + 0x0440);
        r->y = (uint16_t)(value + 0x0440);
        r->c = value + 0x0440 > 0xFFFF;
        r->z = (uint16_t)(value + 0x0440) == 0;
        r->n = (uint16_t)(value + 0x0440) & 0x8000;
        r->v = ((value ^ (uint16_t)(value + 0x0440)) & ((uint16_t)(value + 0x0440) ^ 0x0440) & 0x8000) != 0;
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8ECD, 0x7E8820); GUARD_JSR(c, sp_call, 0x8ECD); } /* expand_title_text_row */
        r->sp += 6;
        uint16_t dp_ret5 = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret9 = r->xf;
        uint16_t x_ret10 = r->x;
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 1));
        if (x_ret9) {
            r->a = (uint16_t)(value15 + 0x04C0);
            r->x = (uint8_t)x_ret10;
            r->y = (uint8_t)(value15 + 0x04C0);
            r->c = value15 + 0x04C0 > 0xFFFF;
            r->z = (uint8_t)(value15 + 0x04C0) == 0;
            r->n = (uint8_t)(value15 + 0x04C0) & 0x80;
            r->v = ((value15 ^ (uint16_t)(value15 + 0x04C0)) & ((uint16_t)(value15 + 0x04C0) ^ 0x04C0) & 0x8000) != 0;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8ED7, 0x7E8820); GUARD_JSR(c, sp_call, 0x8ED7); } /* expand_title_text_row */
            r->sp += 6;
            uint8_t value16 = RAM8(0x0000 + sp0 - 5);
            uint8_t value19 = RAM8(0x0000 + sp0 - 2);
            uint8_t value20 = RAM8(0x0000 + sp0 - 1);
            uint8_t value21 = RAM8(0x0000 + sp0);
            r->c = value19 & 0x01;
            r->v = value19 & 0x40;
            r->mf = value19 & 0x20;
            r->xf = value19 & 0x10;
            r->db = value16;
            r->dp = (value21 << 8) | value20;
            r->i = value19 & 0x04;
            r->d = value19 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            r->a = (uint16_t)(value15 + 0x04C0);
            r->y = (uint16_t)(value15 + 0x04C0);
            r->c = value15 + 0x04C0 > 0xFFFF;
            r->z = (uint16_t)(value15 + 0x04C0) == 0;
            r->n = (uint16_t)(value15 + 0x04C0) & 0x8000;
            r->v = ((value15 ^ (uint16_t)(value15 + 0x04C0)) & ((uint16_t)(value15 + 0x04C0) ^ 0x04C0) & 0x8000) != 0;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8ED7, 0x7E8820); GUARD_JSR(c, sp_call, 0x8ED7); } /* expand_title_text_row */
            r->sp += 6;
            uint8_t value22 = RAM8(0x0000 + sp0 - 5);
            uint8_t value25 = RAM8(0x0000 + sp0 - 2);
            uint8_t value26 = RAM8(0x0000 + sp0 - 1);
            uint8_t value27 = RAM8(0x0000 + sp0);
            r->c = value25 & 0x01;
            r->v = value25 & 0x40;
            r->mf = value25 & 0x20;
            r->xf = value25 & 0x10;
            r->db = value22;
            r->dp = (value27 << 8) | value26;
            r->i = value25 & 0x04;
            r->d = value25 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7E8EA6, SOM_RTS, "gen", render_three_native_region_error_rows, 0, L_Y | L_C | L_V, 7, 1, 0, 58, 36)

#include "som_c.h"

/* 7E8EE0 expand_selected_native_interface_overlay_row   [class A, 40 bytes, 25 instructions]
 * Source: src/boot/expand_selected_native_interface_overlay_row.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABYCV.
 */
static void expand_selected_native_interface_overlay_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    uint16_t x1;
    if ((((a_hi << 8) | a) & 0xFF) != 0) {
        x1 = 0x01A2;
    } else {
        x1 = 0x019E;
    }
    r->a = (uint16_t)(x + 0x03C0);
    r->x = x1;
    r->y = (uint16_t)(x + 0x03C0);
    r->c = x + 0x03C0 > 0xFFFF;
    r->z = (uint16_t)(x + 0x03C0) == 0;
    r->n = (uint16_t)(x + 0x03C0) & 0x8000;
    r->v = ((x ^ (uint16_t)(x + 0x03C0)) & ((uint16_t)(x + 0x03C0) ^ 0x03C0) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8F03, 0x7E8820); GUARD_JSR(c, sp_call, 0x8F03); } /* expand_title_text_row */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value2 & 0x01;
    r->v = value2 & 0x40;
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->db = value;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8EE0, SOM_RTS, "gen", expand_selected_native_interface_overlay_row, 0, L_A | L_B | L_Y | L_C | L_V, 6, 1, 0, 40, 25)

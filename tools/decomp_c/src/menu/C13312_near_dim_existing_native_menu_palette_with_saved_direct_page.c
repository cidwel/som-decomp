#include "som_c.h"

/* C13312 near_dim_existing_native_menu_palette_with_saved_direct_page   [class A, 13 bytes, 8 instructions]
 * Source: src/boot/near_dim_existing_native_menu_palette_with_saved_direct_page.s
 * Documented in docs/source-recovery-parallel-latent-palette-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void near_dim_existing_native_menu_palette_with_saved_direct_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSL(c, 0x331B, 0xC0641A); GUARD_JSL(c, sp_call, 0x331B); } /* forward_native_menu_palette_dimming */
    r->sp += 3;
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->c = value & 0x01;
    r->z = ((value3 << 8) | value2) == 0;
    r->n = ((value3 << 8) | value2) & 0x8000;
    r->v = value & 0x40;
    r->mf = value & 0x20;
    r->xf = value & 0x10;
    r->dp = (value3 << 8) | value2;
    r->i = value & 0x04;
    r->d = value & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13312, SOM_RTS, "gen", near_dim_existing_native_menu_palette_with_saved_direct_page, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 13, 8)

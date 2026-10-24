#include "som_c.h"

/* 7E805F select_graphics_registration   [class B, 60 bytes, 39 instructions]
 * Source: src/boot/select_graphics_registration.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: ABYCV.
 */
static void select_graphics_registration(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)((uint16_t)(sp0 - 5) + 1) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) = (uint8_t)a >> 2;
    uint8_t value = RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1));
    RAM8(0x0000 + sp0 - 4) = (((((((((uint8_t)a >> 4) | value) & 7) >> 7 << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((((((uint8_t)a >> 4) | value) & 7) == 0) << 1)) | (((uint8_t)a >> 3) & 1);
    BUS16_SET(c, 0x004202, 8 << 8 | ((((uint8_t)a >> 4) | value) & 7));
    RAM8(0x0000 + sp0 - 5) = 8;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)(8 << 8 | ((((uint8_t)a >> 4) | value) & 7));
    uint16_t value2 = BUS16(c, 0x004216);
    uint16_t value3 = RAM16(0x10016);
    RAM8(0x0000 + sp0 - 3) = (uint8_t)((value2 & 0xFF) + value3);
    r->a = ((uint16_t)((value2 & 0xFF) + value3) >> 8 << 8) | RAM8(0x0000 + sp0 - 3);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E805F, SOM_RTS, "gen", select_graphics_registration, 0, L_A | L_B | L_Y | L_C | L_V, 7, 0, 0, 60, 39)

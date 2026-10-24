#include "som_c.h"

/* 7E83E2 quantize_component_cube_index   [class B, 47 bytes, 29 instructions]
 * Source: src/boot/quantize_component_cube_index.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$05B8.  Callers read: XYCV.
 */
static void quantize_component_cube_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x05B8) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xB8;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint16_t value = BUS16(c, 0x7F0000 + x);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (value & 0x1E) >> 1);
    uint16_t value2 = BUS16(c, 0x7F0001 + x);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), ((value2 & 0x1E) << 1 << 1 << 1) | RAM16(0x0001 + (uint16_t)(sp0 - 5)));
    uint16_t value4 = BUS16(c, 0x7F0002 + x);
    r->x = ((((value4 & 0x1E) << 8) | 0) >> 1) | RAM16(0x0001 + (uint16_t)(sp0 - 5));
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E83E2, SOM_RTS, "gen", quantize_component_cube_index, 0, L_X | L_Y | L_C | L_V, 5, 1, 0, 47, 29)

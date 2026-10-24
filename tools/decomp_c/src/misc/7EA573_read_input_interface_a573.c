#include "som_c.h"

/* 7EA573 read_input_interface_a573   [class B, 49 bytes, 31 instructions]
 * Source: src/boot/read_input_interface_a573.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void read_input_interface_a573(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x5 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = 0;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 7), 0);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 7), 0);
    uint16_t value = BUS16(c, 0x004218);
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 7), value);
    RAM16_SET(0x0094, RAM16(0x0004 + (uint16_t)(sp0 - 7)));
    uint16_t value3 = RAM16(0x0002 + (uint16_t)(sp0 - 7));
    RAM8(0x0000 + sp0 - 3) = (uint8_t)value3;
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    r->a = (value3 >> 8 << 8) | value7;
    r->c = value8 & 0x01;
    r->z = 0;
    r->n = 0;
    r->v = value8 & 0x40;
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA573, SOM_RTS, "gen", read_input_interface_a573, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 1, 0, 49, 31)

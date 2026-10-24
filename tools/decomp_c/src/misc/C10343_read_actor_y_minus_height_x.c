#include "som_c.h"

/* C10343 read_actor_y_minus_height_x   [class A, 21 bytes, 12 instructions]
 * Source: src/rom/read_actor_y_minus_height_x.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYV.
 */
static void read_actor_y_minus_height_x(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = (uint16_t)((uint16_t)(((RAM16(0x0045 + x) & 0xFF) ^ 0xFFFF) + 1) + RAM16(0x0022 + x));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10343, SOM_RTS, "gen", read_actor_y_minus_height_x, 0, L_A | L_B | L_X | L_Y | L_V, 3, 0, 0, 21, 12)

#include "som_c.h"

/* C1015B read_actor_script_variable_0   [class A, 14 bytes, 9 instructions]
 * Source: src/rom/read_actor_script_variable_0.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E7.  Callers read: AYCZNV.
 */
static void read_actor_script_variable_0(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E7) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xE7;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    SET_A8(r, RAM8(0x0146 + y) & 0x0F);
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1015B, SOM_RTS, "gen", read_actor_script_variable_0, 0, L_A | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 14, 9)

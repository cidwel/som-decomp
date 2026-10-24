#include "som_c.h"

/* C1806F cast_actor_request_preserving_cpu_context   [class A, 26 bytes, 16 instructions]
 * Source: src/rom/cast_actor_request_preserving_cpu_context.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void cast_actor_request_preserving_cpu_context(SomCtx *c)
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
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    RAM8(0x0000 + sp0 - 2) = dp >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    r->a = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 0;
    r->dp = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8080, 0xC188C7); GUARD_JSR(c, sp_call, 0x8080); } /* prepare_guarded_actor_cast_request_and_party_graphics */
    r->sp += 4;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8084, 0x018707); GUARD_JSL(c, sp_call, 0x8084); } /* execute_actor_cast_request */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value4 & 0x01;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->dp = (value2 << 8) | value;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1806F, SOM_RTL, "gen", cast_actor_request_preserving_cpu_context, 0, L_B | L_X | L_Y | L_C | L_V, 5, 1, 0, 26, 16)

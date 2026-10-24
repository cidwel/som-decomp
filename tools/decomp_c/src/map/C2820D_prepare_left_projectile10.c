#include "som_c.h"

/* C2820D prepare_left_projectile10   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/prepare_left_projectile10.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void prepare_left_projectile10(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    BUS16_SET(c, (uint16_t)(dp + 0x95), 0x18);
    BUS16_SET(c, (uint16_t)(dp + 0x97), 0);
    r->a = 0x10;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8219, 0xC282C0); GUARD_JSR(c, sp_call, 0x8219); } /* prepare_attack_row_then_create_parent_projectile */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2820D, SOM_RTS, "gen", prepare_left_projectile10, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 6)

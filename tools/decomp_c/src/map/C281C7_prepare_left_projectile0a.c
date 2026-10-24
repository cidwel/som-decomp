#include "som_c.h"

/* C281C7 prepare_left_projectile0a   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/prepare_left_projectile0a.s
 * Documented in docs/boss-native58-grandchildren.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void prepare_left_projectile0a(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RAM16_SET(0x0395, 0x18);
    RAM16_SET(0x0397, 0);
    r->a = 0x0A;
    { const uint16_t sp_call = r->sp; JSR(c, 0x81D3, 0xC282C0); GUARD_JSR(c, sp_call, 0x81D3); } /* prepare_attack_row_then_create_parent_projectile */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC281C7, SOM_RTS, "gen", prepare_left_projectile0a, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 6)

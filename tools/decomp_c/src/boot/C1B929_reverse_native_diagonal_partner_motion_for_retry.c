#include "som_c.h"

/* C1B929 reverse_native_diagonal_partner_motion_for_retry   [class A, 21 bytes, 9 instructions]
 * Source: src/rom/reverse_native_diagonal_partner_motion_for_retry.s
 * Documented in docs/actor-party-obstacle-detour.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void reverse_native_diagonal_partner_motion_for_retry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(0xE02D + x) = 0;
    RAM8(0xE007 + x) ^= 0x80;
    RAM8(0xE00A + x) = 0x20;
    SET_A8(r, 0x20);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B929, SOM_RTS, "gen", reverse_native_diagonal_partner_motion_for_retry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 21, 9)

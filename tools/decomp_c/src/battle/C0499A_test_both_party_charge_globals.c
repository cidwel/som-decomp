#include "som_c.h"

/* C0499A test_both_party_charge_globals   [class A, 16 bytes, 10 instructions]
 * Source: src/rom/test_both_party_charge_globals.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYC.
 */
static void test_both_party_charge_globals(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    if (RAM8(0xCC79) != 0) {
        if (RAM8(0xCC78) != 0) {
            r->c = 1;
            RETURN_RTS(c);
        }
        r->c = 0;
        RETURN_RTS(c);
    }
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0499A, SOM_RTS, "gen", test_both_party_charge_globals, 0, L_B | L_X | L_Y | L_C, 1, 1, 0, 16, 10)

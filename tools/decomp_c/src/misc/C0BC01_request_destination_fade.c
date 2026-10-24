#include "som_c.h"

/* C0BC01 request_destination_fade   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/request_destination_fade.s
 * Documented in docs/cutscene-engine.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void request_destination_fade(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xBC03, 0xC08B09); /* prepare_destination_fade */
    RAM8(0x00FF) = 0x81;
    SET_A8(r, 0x81);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0BC01, SOM_RTL, "gen", request_destination_fade, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 10, 5)

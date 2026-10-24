#include "som_c.h"

/* C08B09 prepare_destination_fade   [class C, 52 bytes, 25 instructions]
 * Source: src/rom/prepare_destination_fade.s
 * Documented in docs/cutscene-engine.md
 * Entry: M=16 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCV.
 */
static void prepare_destination_fade(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x00E7) = 0;
    RAM16_SET(0x00E4, 0x0201);
    RAM8(0x00E2) |= 1;
    SET_A8(r, 1);
    r->y = 0x0201;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08B09, SOM_RTS, "gen", prepare_destination_fade, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 52, 25)

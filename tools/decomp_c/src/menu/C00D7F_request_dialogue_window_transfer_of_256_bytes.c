#include "som_c.h"

/* C00D7F request_dialogue_window_transfer_of_256_bytes   [class A, 12 bytes, 5 instructions]
 * Source: src/rom/request_dialogue_window_transfer_of_256_bytes.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: YV.
 */
static void request_dialogue_window_transfer_of_256_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x1D08, 0x0100);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00D7F, SOM_RTS, "gen", request_dialogue_window_transfer_of_256_bytes, 0, L_Y | L_V, 1, 1, 0, 12, 5)

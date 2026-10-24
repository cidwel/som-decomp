#include "som_c.h"

/* C05BEA request_native_party_message_suspend_script   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/request_native_party_message_suspend_script.s
 * Documented in docs/event-party-message-queue.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void request_native_party_message_suspend_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RAM16_SET(0x1D01, 0x637D);
    RAM8(0x1D03) = 0xC0;
    RAM8(0x03A3) = 0;
    r->y = 0x637D;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05BEA, SOM_RTS, "gen", request_native_party_message_suspend_script, 0, L_B | L_X | L_Y, 1, 1, 0, 14, 6)

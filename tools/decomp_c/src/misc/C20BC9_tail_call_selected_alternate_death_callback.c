#include "som_c.h"

/* C20BC9 tail_call_selected_alternate_death_callback   [class C, 5 bytes, hand written]
 * STA $0C ; JMP ($020C): stores A as the callback pointer and jumps through it.
 * Entry: D=$0200, DB=$7E; the accumulator width is whatever the caller left (M flag read at run time).
 * Ends in `jmp (abs)`, so the routine tail-calls the pointer stored in direct page; the target's RTS returns to the caller.
 */
static void tail_call_selected_alternate_death_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if (r->mf) RAM8(0x020C) = (uint8_t)a; else RAM16_SET(0x020C, a);
    TAIL_CALL(c, 0xC20000 | RAM16(0x020C), SOM_RTS);
}
SOM_REGISTER(0xC20BC9, SOM_RTS, "hand", tail_call_selected_alternate_death_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 16, -1, -1, 5, 2)

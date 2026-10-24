#include "som_c.h"

/* C2391D boss_state_jump_to_native_pointer   [class C, 5 bytes, hand written]
 * STA $33 ; JMP ($0233): stores A as the native pointer and jumps through it.
 * Entry: D=$0200, DB=$7E; the accumulator width is whatever the caller left (M flag read at run time).
 * Ends in `jmp (abs)`, so the routine tail-calls the pointer stored in direct page; the target's RTS returns to the caller.
 */
static void boss_state_jump_to_native_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if (r->mf) RAM8(0x0233) = (uint8_t)a; else RAM16_SET(0x0233, a);
    TAIL_CALL(c, 0xC20000 | RAM16(0x0233), SOM_RTS);
}
SOM_REGISTER(0xC2391D, SOM_RTS, "hand", boss_state_jump_to_native_pointer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 16, -1, -1, 5, 2)

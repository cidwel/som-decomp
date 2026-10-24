#include "som_c.h"

/* C126FB actor_random_byte_with_preserved_bank   [class A, 21 bytes, 15 instructions]
 * Source: src/rom/actor_random_byte_with_preserved_bank.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYV.
 */
static void actor_random_byte_with_preserved_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a = r->a & 0xFF;
    const bool overflow = r->v;
    r->z = a == 0;
    r->n = a & 0x80;
    r->sp -= 4;
    JSL(c, 0x270B, 0xC00018); /* public_random_byte_jump */
    r->sp += 4;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC126FB, SOM_RTS, "gen", actor_random_byte_with_preserved_bank, 0, L_A | L_B | L_X | L_Y | L_V, 6, 1, 0, 21, 15)

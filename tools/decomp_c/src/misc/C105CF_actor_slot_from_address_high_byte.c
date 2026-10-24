#include "som_c.h"

/* C105CF actor_slot_from_address_high_byte   [class A, 11 bytes, 8 instructions]
 * Source: src/rom/actor_slot_from_address_high_byte.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: AY.
 */
static void actor_slot_from_address_high_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t x = r->x;
    SET_A8(r, (uint8_t)((x >> 8) - 0xE0) >> 1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC105CF, SOM_RTS, "gen", actor_slot_from_address_high_byte, 0, L_A | L_Y, 1, 1, 0, 11, 8)

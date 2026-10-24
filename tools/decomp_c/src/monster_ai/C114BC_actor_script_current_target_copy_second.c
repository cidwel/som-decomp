#include "som_c.h"

/* C114BC actor_script_current_target_copy_second   [class A, 9 bytes, 3 instructions]
 * Source: src/rom/actor_script_current_target_copy_second.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_current_target_copy_second(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x01AD + y);
    RAM8(0x01AC + y) = value;
    r->a = (a_hi << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC114BC, SOM_RTS, "gen", actor_script_current_target_copy_second, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 3)

#include "som_c.h"

/* C12183 actor_script_save_current_position   [class A, 17 bytes, 6 instructions]
 * Source: src/rom/actor_script_save_current_position.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_save_current_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0020 + y);
    RAM16_SET(0x0148 + y, value);
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    JSR(c, 0x218D, 0xC1032E); /* read_actor_y_minus_height_y */
    uint16_t a_all = r->a;
    RAM16_SET(0x014A + y, a_all);
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC12183, SOM_RTS, "gen", actor_script_save_current_position, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 17, 6)

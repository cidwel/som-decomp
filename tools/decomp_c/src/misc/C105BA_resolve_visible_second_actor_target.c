#include "som_c.h"

/* C105BA resolve_visible_second_actor_target   [class A, 21 bytes, 12 instructions]
 * Source: src/rom/resolve_visible_second_actor_target.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void resolve_visible_second_actor_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x01AD + y);
    if (value == 0xFF) {
        SET_A8(r, value | 0xFF);
        r->c = value >= 0xFF;
        r->z = (value | 0xFF) == 0;
        r->n = (value | 0xFF) & 0x80;
        RETURN_RTS(c);
    }
    r->a = ((uint8_t)((uint8_t)(value << 1) + 0xE0) << 8) | 0;
    r->x = ((uint8_t)((uint8_t)(value << 1) + 0xE0) << 8) | 0;
    r->c = (uint8_t)(value << 1) + 0xE0 > 0xFF;
    r->z = (((uint8_t)((uint8_t)(value << 1) + 0xE0) << 8) | 0) == 0;
    r->n = (((uint8_t)((uint8_t)(value << 1) + 0xE0) << 8) | 0) & 0x8000;
    r->v = (((uint8_t)(value << 1) ^ (uint8_t)((uint8_t)(value << 1) + 0xE0)) & ((uint8_t)((uint8_t)(value << 1) + 0xE0) ^ 0xE0) & 0x80) != 0;
    TAIL_CALL(c, 0xC10526, SOM_RTS); /* test_actor_on_screen */
}
SOM_REGISTER(0xC105BA, SOM_RTS, "gen", resolve_visible_second_actor_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 21, 12)

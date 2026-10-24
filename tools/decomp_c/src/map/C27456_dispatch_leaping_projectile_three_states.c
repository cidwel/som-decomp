#include "som_c.h"

/* C27456 dispatch_leaping_projectile_three_states   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_leaping_projectile_three_states.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_leaping_projectile_three_states(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC27464, SOM_RTS); /* initialize_leaping_projectile_animation_and_motion_callback */
    case 0x0002: TAIL_CALL_DYN(c, 0xC27480, SOM_RTS); /* update_leaping_projectile_direction_velocity_and_collision */
    case 0x0004: TAIL_CALL_DYN(c, 0xC274EE, SOM_RTS); /* finish_leaping_projectile_when_animation_word_is_zero */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x745E + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC27456, SOM_RTS, "gen", dispatch_leaping_projectile_three_states, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)

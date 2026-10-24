#include "som_c.h"

/* C23ED6 dispatch_homing_projectile_two_states   [class C, 10 bytes, 5 instructions]
 * Source: src/rom/dispatch_homing_projectile_two_states.s
 * Documented in docs/boss-actor-controller-pool.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_homing_projectile_two_states(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value2 = RAM16(OBJECT_PHASE + RAM16(0x0287));
    r->a = (uint16_t)(value2 << 1);
    r->x = (uint16_t)(value2 << 1);
    r->c = value2 & 0x8000;
    r->z = (uint16_t)(value2 << 1) == 0;
    r->n = (uint16_t)(value2 << 1) & 0x8000;
    switch ((uint16_t)(value2 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC23EE4, SOM_RTS); /* initialize_homing_projectile_animation_target_byte_and_motion_callback */
    case 0x0002: TAIL_CALL_DYN(c, 0xC23F12, SOM_RTS); /* update_homing_projectile_reorientation_acceleration_and_parent_contact */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x3EE0 + ((uint16_t)(value2 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC23ED6, SOM_RTS, "gen", dispatch_homing_projectile_two_states, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 5)

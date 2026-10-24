#include "som_c.h"

/* C24F7D publish_native54_projectile_depth_and_dispatch_phase   [class C, 14 bytes, 6 instructions]
 * Source: src/rom/publish_native54_projectile_depth_and_dispatch_phase.s
 * Documented in docs/boss-native54-projectiles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void publish_native54_projectile_depth_and_dispatch_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0022 + x, RAM16(0x0032 + x));
    uint16_t value2 = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value2 << 1);
    r->x = (uint16_t)(value2 << 1);
    r->c = value2 & 0x8000;
    r->z = (uint16_t)(value2 << 1) == 0;
    r->n = (uint16_t)(value2 << 1) & 0x8000;
    switch ((uint16_t)(value2 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC24F91, SOM_RTS); /* initialize_native54_homing_projectile_and_linked_effect_palette */
    case 0x0002: TAIL_CALL_DYN(c, 0xC24FEB, SOM_RTS); /* home_native54_projectile_or_enter_contact_animation */
    case 0x0004: TAIL_CALL_DYN(c, 0xC25041, SOM_RTS); /* consume_native54_projectile_contacts_and_notify_parent_after_animation */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x4F8B + ((uint16_t)(value2 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC24F7D, SOM_RTS, "gen", publish_native54_projectile_depth_and_dispatch_phase, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 6)

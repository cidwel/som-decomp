#include "som_c.h"

/* C28455 dispatch_native59_parent_with_mp99   [class C, 14 bytes, 6 instructions]
 * Source: src/rom/dispatch_native59_parent_with_mp99.s
 * Documented in docs/boss-native59-header.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_native59_parent_with_mp99(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0186 + x, 0x6363);
    uint16_t value = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC28471, SOM_RTS); /* initialize_native59_and_create_linked_child_and_effects */
    case 0x0002: TAIL_CALL_DYN(c, 0xC284FC, SOM_RTS); /* wait_native59_distance_or_refresh_variant_zero_palette */
    case 0x0004: TAIL_CALL_DYN(c, 0xC285EB, SOM_RTS); /* execute_native59_variant_projectile_or_conditioned_spell */
    case 0x0006: TAIL_CALL_DYN(c, 0xC2874A, SOM_RTS); /* complete_native59_hurt_and_refresh_child_hp_scale */
    case 0x0008: TAIL_CALL_DYN(c, 0xC28817, SOM_RTS); /* begin_native59_terminal_death_after_status_clear */
    case 0x000A: TAIL_CALL_DYN(c, 0xC20B8B, SOM_RTS); /* advance_boss_death_explosions_event_and_reward_phase */
    case 0x000C: TAIL_CALL_DYN(c, 0xC20B50, SOM_RTS); /* wait_for_boss_death_controller_event_gates */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x8463 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC28455, SOM_RTS, "gen", dispatch_native59_parent_with_mp99, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 6)

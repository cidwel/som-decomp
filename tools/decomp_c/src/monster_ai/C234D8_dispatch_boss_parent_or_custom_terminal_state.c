#include "som_c.h"

/* C234D8 dispatch_boss_parent_or_custom_terminal_state   [class C, 44 bytes, 20 instructions]
 * Source: src/rom/dispatch_boss_parent_or_custom_terminal_state.s
 * Documented in docs/boss-actor-controller.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_boss_parent_or_custom_terminal_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(OBJECT_PHASE + x);
    if (value < 4) {
        r->a = (uint16_t)(value << 1);
        r->x = (uint16_t)(value << 1);
        r->c = value & 0x8000;
        r->z = (uint16_t)(value << 1) == 0;
        r->n = (uint16_t)(value << 1) & 0x8000;
        switch ((uint16_t)(value << 1)) {
        case 0x0000: TAIL_CALL_DYN(c, 0xC23512, SOM_RTS); /* initialize_parent_callbacks_and_first_state */
        case 0x0002: TAIL_CALL_DYN(c, 0xC23551, SOM_RTS); /* choose_next_boss_script_list */
        case 0x0004: TAIL_CALL_DYN(c, 0xC23561, SOM_RTS); /* consume_boss_state_list_and_bootstrap_vm */
        case 0x0006: TAIL_CALL_DYN(c, 0xC23594, SOM_RTS); /* update_boss_action_and_completion */
        case 0x0008: TAIL_CALL_DYN(c, 0xC20AFD, SOM_RTS); /* begin_boss_death_initialization_when_control_and_lock_clear */
        case 0x000A: TAIL_CALL_DYN(c, 0xC20B8B, SOM_RTS); /* advance_boss_death_explosions_event_and_reward_phase */
        case 0x000C: TAIL_CALL_DYN(c, 0xC20BCE, SOM_RTS); /* advance_alternate_boss_death_callback_effects_and_event_gates */
        default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x3504 + ((uint16_t)(value << 1)))), SOM_RTS);
        }
    }
    uint16_t value2 = RAM16(0x004C + x);
    if (value2 == 0) {
        r->a = (uint16_t)(value << 1);
        r->x = (uint16_t)(value << 1);
        r->c = value & 0x8000;
        r->z = (uint16_t)(value << 1) == 0;
        r->n = (uint16_t)(value << 1) & 0x8000;
        switch ((uint16_t)(value << 1)) {
        case 0x0000: TAIL_CALL_DYN(c, 0xC23512, SOM_RTS); /* initialize_parent_callbacks_and_first_state */
        case 0x0002: TAIL_CALL_DYN(c, 0xC23551, SOM_RTS); /* choose_next_boss_script_list */
        case 0x0004: TAIL_CALL_DYN(c, 0xC23561, SOM_RTS); /* consume_boss_state_list_and_bootstrap_vm */
        case 0x0006: TAIL_CALL_DYN(c, 0xC23594, SOM_RTS); /* update_boss_action_and_completion */
        case 0x0008: TAIL_CALL_DYN(c, 0xC20AFD, SOM_RTS); /* begin_boss_death_initialization_when_control_and_lock_clear */
        case 0x000A: TAIL_CALL_DYN(c, 0xC20B8B, SOM_RTS); /* advance_boss_death_explosions_event_and_reward_phase */
        case 0x000C: TAIL_CALL_DYN(c, 0xC20BCE, SOM_RTS); /* advance_alternate_boss_death_callback_effects_and_event_gates */
        default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x3504 + ((uint16_t)(value << 1)))), SOM_RTS);
        }
    }
    RAM16_SET(0x020C, value2);
    RAM16_SET(0x020E, 0xC2);
    uint16_t value3 = RAM16(OBJECT_PHASE + x);
    uint16_t value4 = BUS16_RDL(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + (uint16_t)((uint16_t)(value3 - 4) << 1), RAM8(0x020E));
    RAM16_SET(0x020C, value4);
    uint16_t value5 = RAM16(0x020C);
    r->a = value4;
    r->y = (uint16_t)((uint16_t)(value3 - 4) << 1);
    r->c = (uint16_t)(value3 - 4) & 0x8000;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->v = ((value3 ^ 4) & (value3 ^ (uint16_t)(value3 - 4)) & 0x8000) != 0;
    TAIL_CALL_DYN(c, 0xC20000 | value5, SOM_RTS);
}
SOM_REGISTER(0xC234D8, SOM_RTS, "gen", dispatch_boss_parent_or_custom_terminal_state, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 44, 20)

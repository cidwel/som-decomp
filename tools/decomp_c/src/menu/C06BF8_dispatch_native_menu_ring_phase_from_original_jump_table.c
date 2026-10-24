#include "som_c.h"

/* C06BF8 dispatch_native_menu_ring_phase_from_original_jump_table   [class C, 23 bytes, 10 instructions]
 * Source: src/rom/dispatch_native_menu_ring_phase_from_original_jump_table.s
 * Documented in docs/event-menu-ring-phase.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_native_menu_ring_phase_from_original_jump_table(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    RAM8(0x180C) = 1;
    RAM8(0x1807) = 1;
    uint8_t value = RAM8(0x1812);
    uint16_t value2 = RAM16(0x181E);
    r->a = value2;
    r->x = (uint8_t)((a >> 8 << 8) | (uint8_t)(value << 1));
    r->y = (uint8_t)y;
    r->c = value & 0x80;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    switch ((uint8_t)((a >> 8 << 8) | (uint8_t)(value << 1))) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC06C6D, SOM_RTS); /* prepare_native_ring_projection_and_handle_final_direction_step */
    case 0x0002: TAIL_CALL_DYN(c, 0xC06C28, SOM_RTS); /* grow_native_ring_until_default_radius */
    case 0x0004: TAIL_CALL_DYN(c, 0xC06C33, SOM_RTS); /* grow_native_ring_until_outer_transition_threshold */
    case 0x0006: TAIL_CALL_DYN(c, 0xC06C3E, SOM_RTS); /* shrink_native_ring_until_default_radius */
    case 0x0008: TAIL_CALL_DYN(c, 0xC06C1D, SOM_RTS); /* shrink_native_ring_until_category_transition_threshold */
    case 0x000A: TAIL_CALL_DYN(c, 0xC06C3E, SOM_RTS); /* shrink_native_ring_until_default_radius */
    case 0x000C: TAIL_CALL_DYN(c, 0xC06C33, SOM_RTS); /* grow_native_ring_until_outer_transition_threshold */
    default: TAIL_CALL_DYN(c, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x6C0F + ((uint8_t)((a >> 8 << 8) | (uint8_t)(value << 1))))), SOM_RTS);
    }
}
SOM_REGISTER(0xC06BF8, SOM_RTS, "gen", dispatch_native_menu_ring_phase_from_original_jump_table, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 23, 10)

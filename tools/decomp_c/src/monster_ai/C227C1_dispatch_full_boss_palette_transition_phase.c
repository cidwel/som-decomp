#include "som_c.h"

/* C227C1 dispatch_full_boss_palette_transition_phase   [class C, 21 bytes, 10 instructions]
 * Source: src/rom/dispatch_full_boss_palette_transition_phase.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void dispatch_full_boss_palette_transition_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (RAM16(0x009E + x) & 0x8000) {
        uint16_t value2 = RAM16(OBJECT_PHASE + x);
        r->a = (uint16_t)(value2 << 1);
        r->x = (uint16_t)(value2 << 1);
        r->c = value2 & 0x8000;
        r->z = (uint16_t)(value2 << 1) == 0;
        r->n = (uint16_t)(value2 << 1) & 0x8000;
        switch ((uint16_t)(value2 << 1)) {
        case 0x0000: TAIL_CALL_DYN(c, 0xC2285B, SOM_RTS); /* initialize_single_boss_palette_transition_channels */
        case 0x0002: TAIL_CALL_DYN(c, 0xC22976, SOM_RTS); /* derive_single_boss_palette_transition_channel_group */
        case 0x0004: TAIL_CALL_DYN(c, 0xC22992, SOM_RTS); /* advance_single_boss_palette_transition_phase */
        case 0x0006: TAIL_CALL_DYN(c, 0xC22992, SOM_RTS); /* advance_single_boss_palette_transition_phase */
        case 0x0008: TAIL_CALL_DYN(c, 0xC22992, SOM_RTS); /* advance_single_boss_palette_transition_phase */
        case 0x000A: TAIL_CALL_DYN(c, 0xC229EA, SOM_RTS); /* step_single_boss_palette_transition_channels */
        case 0x000C: TAIL_CALL_DYN(c, 0xC22A57, SOM_RTS); /* finish_boss_palette_transition_with_carry */
        default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x27E4 + ((uint16_t)(value2 << 1)))), SOM_RTS);
        }
    }
    uint16_t value3 = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value3 << 1);
    r->x = (uint16_t)(value3 << 1);
    r->c = value3 & 0x8000;
    r->z = (uint16_t)(value3 << 1) == 0;
    r->n = (uint16_t)(value3 << 1) & 0x8000;
    switch ((uint16_t)(value3 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC227F2, SOM_RTS); /* initialize_full_boss_palette_transition_channels */
    case 0x0002: TAIL_CALL_DYN(c, 0xC228FA, SOM_RTS); /* derive_first_boss_palette_transition_channel_group */
    case 0x0004: TAIL_CALL_DYN(c, 0xC22913, SOM_RTS); /* derive_second_boss_palette_transition_channel_group */
    case 0x0006: TAIL_CALL_DYN(c, 0xC22934, SOM_RTS); /* derive_third_boss_palette_transition_channel_group */
    case 0x0008: TAIL_CALL_DYN(c, 0xC22955, SOM_RTS); /* derive_fourth_boss_palette_transition_channel_group */
    case 0x000A: TAIL_CALL_DYN(c, 0xC229BD, SOM_RTS); /* step_full_boss_palette_transition_channels */
    case 0x000C: TAIL_CALL_DYN(c, 0xC22A57, SOM_RTS); /* finish_boss_palette_transition_with_carry */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x27CE + ((uint16_t)(value3 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC227C1, SOM_RTS, "gen", dispatch_full_boss_palette_transition_phase, SOM_UNWINDS, 0, 1, 0, 0, 35, 10)

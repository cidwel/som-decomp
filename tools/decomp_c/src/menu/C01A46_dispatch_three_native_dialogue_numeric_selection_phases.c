#include "som_c.h"

/* C01A46 dispatch_three_native_dialogue_numeric_selection_phases   [class C, 12 bytes, 7 instructions]
 * Source: src/rom/dispatch_three_native_dialogue_numeric_selection_phases.s
 * Documented in docs/event-dialogue-numeric-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_three_native_dialogue_numeric_selection_phases(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA160);
    r->a = (uint8_t)(value << 1);
    r->x = (uint8_t)(value << 1);
    r->c = value & 0x80;
    r->z = (uint8_t)(value << 1) == 0;
    r->n = (uint8_t)(value << 1) & 0x8000;
    { const uint16_t sp_call = r->sp;
    switch ((uint8_t)(value << 1)) {
    case 0x0000: JSR(c, 0x1A50, 0xC01A52); GUARD_JSR(c, sp_call, 0x1A50); break; /* initialize_numeric_choice_controller_and_highlight */
    case 0x0002: JSR(c, 0x1A50, 0xC01A76); GUARD_JSR(c, sp_call, 0x1A50); break; /* poll_native_dialogue_numeric_selection */
    case 0x0004: JSR(c, 0x1A50, 0xC01A7A); GUARD_JSR(c, sp_call, 0x1A50); break; /* finish_numeric_choice_and_begin_window_close */
    case 0x0006: JSR(c, 0x1A50, 0xC000A2); GUARD_JSR(c, sp_call, 0x1A50); break; /* jump_public_hidden_effect_empty_update */
    default: JSR(c, 0x1A50, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1BB7 + ((uint8_t)(value << 1))))); GUARD_JSR(c, sp_call, 0x1A50);
    }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01A46, SOM_RTS, "gen", dispatch_three_native_dialogue_numeric_selection_phases, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 12, 7)

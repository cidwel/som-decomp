#include "som_c.h"

/* C01A76 poll_native_dialogue_numeric_selection   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/poll_native_dialogue_numeric_selection.s
 * Documented in docs/event-dialogue-numeric-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void poll_native_dialogue_numeric_selection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x1A78, 0xC01A96); /* read_numeric_choice_controller_and_dispatch_button_actions */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01A76, SOM_RTS, "gen", poll_native_dialogue_numeric_selection, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 4, 2)

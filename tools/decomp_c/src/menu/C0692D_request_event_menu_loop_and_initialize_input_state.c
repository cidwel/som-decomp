#include "som_c.h"

/* C0692D request_event_menu_loop_and_initialize_input_state   [class A, 18 bytes, 7 instructions]
 * Source: src/rom/request_event_menu_loop_and_initialize_input_state.s
 * Documented in docs/event-menu-actor-selection.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void request_event_menu_loop_and_initialize_input_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x1826, 1);
    RAM16_SET(0x19F0, 0x8080);
    RAM16_SET(0x19F2, 0x8080);
    r->a = 0x8080;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0692D, SOM_RTS, "gen", request_event_menu_loop_and_initialize_input_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 18, 7)

#include "som_c.h"

/* C1E76D event_command_map_context_entry   [class A, 14 bytes, 10 instructions]
 * Source: src/rom/event_command_map_context_entry.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCV.
 */
static void event_command_map_context_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    r->mf = 1;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xE778, 0xC1E77B); /* accept_numeric_event_request */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1E76D, SOM_RTL, "gen", event_command_map_context_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 3, 0, 0, 14, 10)

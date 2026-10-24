#include "som_c.h"

/* C25AFC install_linked_child_periodic_motion_and_idle_definition   [class A, 20 bytes, 8 instructions]
 * Source: src/rom/install_linked_child_periodic_motion_and_idle_definition.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void install_linked_child_periodic_motion_and_idle_definition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0090 + x, 0x5B10);
    RAM16_SET(0x0049 + x, 0);
    RAM16_SET(0x008E + x, 0x5B0E);
    RAM16_SET(OBJECT_AGE + x, 0);
    r->a = 0x5B0E;
    r->c = 0;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25AFC, SOM_RTS, "gen", install_linked_child_periodic_motion_and_idle_definition, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 20, 8)

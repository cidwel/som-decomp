#include "som_c.h"

/* C25CC8 install_linked_child_random_idle_motion   [class A, 17 bytes, 7 instructions]
 * Source: src/rom/install_linked_child_random_idle_motion.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void install_linked_child_random_idle_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x00B8 + x, (uint16_t)(RAM16(0x00B8 + x) + 1));
    RAM16_SET(0x0090 + x, 0x5CD9);
    RAM16_SET(0x008E + x, 0x5CD7);
    r->a = 0x5CD7;
    r->c = 0;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25CC8, SOM_RTS, "gen", install_linked_child_random_idle_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 17, 7)

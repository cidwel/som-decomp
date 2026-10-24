#include "som_c.h"

/* C25B74 terminate_linked_child_when_parent_reaches_state_two   [class A, 18 bytes, 9 instructions]
 * Source: src/rom/terminate_linked_child_when_parent_reaches_state_two.s
 * Documented in docs/boss-native-linked-death-dependencies.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void terminate_linked_child_when_parent_reaches_state_two(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0090 + x, 0);
    uint16_t value = RAM16(0x00B0 + x);
    uint16_t value2 = RAM16(OBJECT_PHASE + value);
    if (value2 != 2) {
        r->a = value2;
        r->y = value;
        r->c = 0;
        r->z = value2 == 2;
        r->n = (uint16_t)(value2 - 2) & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->y = value;
    r->c = 1;
    r->z = value2 == 2;
    r->n = (uint16_t)(value2 - 2) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25B74, SOM_RTS, "gen", terminate_linked_child_when_parent_reaches_state_two, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 18, 9)

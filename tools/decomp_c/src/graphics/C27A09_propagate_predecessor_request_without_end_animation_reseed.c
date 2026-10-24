#include "som_c.h"

/* C27A09 propagate_predecessor_request_without_end_animation_reseed   [class A, 32 bytes, 12 instructions]
 * Source: src/rom/propagate_predecessor_request_without_end_animation_reseed.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void propagate_predecessor_request_without_end_animation_reseed(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    RAM16_SET(0x0014 + value, RAM16(0x0082 + value));
    RAM16_SET(0x0082 + value, RAM16(0x0080 + value));
    RAM16_SET(0x0080 + value, RAM16(0x0082 + value2));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27A09, SOM_RTS, "gen", propagate_predecessor_request_without_end_animation_reseed, 0, 0, 1, 0, 0, 32, 12)

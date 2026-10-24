#include "som_c.h"

/* D9FC50 negate_native_ring_component_then_accumulate_vertical_center   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/negate_native_ring_component_then_accumulate_vertical_center.s
 * Documented in docs/event-menu-ring-geometry.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABY.
 */
static void negate_native_ring_component_then_accumulate_vertical_center(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x186A);
    RAM16_SET(0x186A, (uint16_t)((uint16_t)((a ^ 0xFFFF) + 1) + value));
    r->a = (uint16_t)((uint16_t)((a ^ 0xFFFF) + 1) + value);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD9FC50, SOM_RTS, "gen", negate_native_ring_component_then_accumulate_vertical_center, 0, L_A | L_B | L_Y, 1, 0, 0, 12, 6)

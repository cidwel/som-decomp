#include "som_c.h"

/* D9FC5C project_native_ring_complementary_quarter_wave_component   [class C, 52 bytes, 25 instructions]
 * Source: src/rom/project_native_ring_complementary_quarter_wave_component.s
 * Documented in docs/event-menu-ring-geometry.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABY.
 */
static void project_native_ring_complementary_quarter_wave_component(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    if (y == 0) {
        r->a = RAM16(0x186E) & 0xFF;
        RETURN_RTS(c);
    }
    uint8_t value2 = BUS8(c, 0xD97DE0 + ((uint16_t)((y ^ 0xFFFF) + 1) & 0xFF));
    BUS8_SET(c, 0x004202, value2);
    BUS8_SET(c, 0x004203, RAM8(0x186E));
    uint8_t value4 = BUS8(c, 0x004217);
    r->a = value4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD9FC5C, SOM_RTS, "gen", project_native_ring_complementary_quarter_wave_component, 0, L_A | L_B | L_Y, 1, 0, 0, 52, 25)

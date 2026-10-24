#include "som_c.h"

/* C23C0E plot_terminal_particle_bitplanes   [class B, 98 bytes, 55 instructions]
 * Source: src/rom/plot_terminal_particle_bitplanes.s
 * Documented in docs/boss-native-death-particles.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0200.  Callers read: nothing.
 */
static void plot_terminal_particle_bitplanes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0x0295, a);
    RAM16_SET(0x0297, (uint16_t)((((uint8_t)((((uint8_t)(a & 0xFF00) << 8) | ((a & 0xFF00) >> 8)) >> 3) << 8) | ((((uint8_t)(a & 0xFF00) << 8) | ((a & 0xFF00) >> 8)) >> 3 >> 8)) << 1));
    RAM16_SET(0x0297, (uint16_t)(((((RAM16(0x0295) & 0xFF) >> 3 << 8) | 0) >> 3) + RAM16(0x0297)));
    uint16_t value3 = RAM16(0x0296);
    uint16_t value4 = RAM16(0x0297);
    RAM16_SET(0x020C, (uint16_t)((uint16_t)(((value3 & 7) << 1) + value4) + 0x6000 + (((value3 & 7) << 1) + value4 > 0xFFFF)));
    uint8_t value6 = BUS8(c, 0xC23C70 + (uint8_t)((uint16_t)((uint16_t)(((value3 & 7) << 1) + value4) + 0x6000 + (((value3 & 7) << 1) + value4 > 0xFFFF)) >> 8 << 8 | (RAM8(0x0295) & 7)));
    RAM8(0x0299) = value6;
    if ((RAM8(0x021A) & 8) != 0) {
        uint8_t value8 = RAM8(0x0299);
        uint8_t value9 = BUS8(c, RAM16(0x020C) + 0x7F0000);
        BUS8_SET(c, RAM16(0x020C) + 0x7F0000, value8 | value9);
    }
    uint8_t value10 = RAM8(0x0299);
    uint8_t value11 = BUS8(c, RAM16(0x020C) + 0x7F0001);
    BUS8_SET(c, RAM16(0x020C) + 0x7F0001, value10 | value11);
    uint8_t value12 = RAM8(0x0299);
    uint8_t value13 = BUS8(c, RAM16(0x020C) + 0x7F0010);
    BUS8_SET(c, RAM16(0x020C) + 0x7F0010, value12 | value13);
    uint8_t value14 = RAM8(0x0299);
    uint8_t value15 = BUS8(c, RAM16(0x020C) + 0x7F0011);
    BUS8_SET(c, RAM16(0x020C) + 0x7F0011, value14 | value15);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23C0E, SOM_RTS, "gen", plot_terminal_particle_bitplanes, 0, 0, 1, 0, 0, 98, 55)

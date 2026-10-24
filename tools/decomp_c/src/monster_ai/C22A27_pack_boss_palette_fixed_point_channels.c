#include "som_c.h"

/* C22A27 pack_boss_palette_fixed_point_channels   [class B, 48 bytes, 29 instructions]
 * Source: src/rom/pack_boss_palette_fixed_point_channels.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void pack_boss_palette_fixed_point_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x02C5);
    uint8_t a_hi1 = a >> 8;
    uint16_t y1 = value;
    for (;;) {
        uint16_t value2 = BUS16(c, RAM16(0x0276) + 0x7E0000 + y1);
        RAM16_SET(0x0268, (value2 & 0x1F00) << 1 << 1);
        uint16_t value3 = BUS16(c, RAM16(0x0276) + 0x7E0000 + (uint16_t)(y1 + 2));
        RAM16_SET(0x0268, ((value3 & 0x1F00) >> 3) | RAM16(0x0268));
        uint16_t value5 = BUS16(c, RAM16(0x0276) + 0x7E0000 + (uint16_t)(y1 + 4));
        uint16_t value6 = RAM16(0x0268);
        BUS16_SET(c, RAM16(0x0279) + 0x7E0000, ((uint8_t)(value5 & 0x1F00) << 8) | ((value5 & 0x1F00) >> 8) | value6);
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        uint16_t value7 = RAM16(0x0266);
        a_hi1 = (((uint8_t)(value5 & 0x1F00) << 8) | ((value5 & 0x1F00) >> 8) | value6) >> 8;
        y1 = (uint16_t)(y1 + 6);
        if (!(y1 != value7)) break;
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22A27, SOM_RTS, "gen", pack_boss_palette_fixed_point_channels, 0, 0, 1, 0, 0, 48, 29)

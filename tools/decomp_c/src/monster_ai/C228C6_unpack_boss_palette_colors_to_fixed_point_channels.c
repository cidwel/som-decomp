#include "som_c.h"
#include "som_hand_b.h"

/* C228C6 unpack_boss_palette_colors_to_fixed_point_channels   [class B, 52 bytes, 29 instructions]
 * Source: src/rom/unpack_boss_palette_colors_to_fixed_point_channels.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void unpack_boss_palette_colors_to_fixed_point_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x02C5);
    uint8_t a_hi1 = a >> 8;
    uint8_t y1 = value;
    for (;;) {
        /* The loop ends only when Y meets $66, which stores through ($79) can move: charge each pass its 25 instructions
         * to the step budget like the interpreted original (the original loops forever on some fuzzed states). */
        c->steps += 25;
        if (c->steps > c->step_limit) { c->fail = 1; return; }
        uint16_t value2 = BUS16(c, RAM16(0x0276) + 0x7E0000 + y1);
        bus16_set_once(c, (uint32_t)(0x7E0000 + RAM16(0x0279)), (value2 & 0x7C00) >> 2);
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        uint16_t value3 = BUS16(c, RAM16(0x0276) + 0x7E0000 + y1);
        bus16_set_once(c, (uint32_t)(0x7E0000 + RAM16(0x0279)), (value3 & 0x03E0) << 1 << 1 << 1);
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        uint16_t value4 = BUS16(c, RAM16(0x0276) + 0x7E0000 + y1);
        bus16_set_once(c, (uint32_t)(0x7E0000 + RAM16(0x0279)), ((value4 & 0x1F) << 8) | 0);
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        uint8_t value5 = RAM8(0x0266);
        a_hi1 = value4 & 0x1F;
        y1 = (uint8_t)(y1 + 2);
        if (!(y1 != value5)) break;
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC228C6, SOM_RTS, "hand", unpack_boss_palette_colors_to_fixed_point_channels, 0, 0, 1, 0, 0, 52, 29)

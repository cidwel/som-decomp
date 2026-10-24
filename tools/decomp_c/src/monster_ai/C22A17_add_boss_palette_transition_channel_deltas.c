#include "som_c.h"

/* C22A17 add_boss_palette_transition_channel_deltas   [class A, 16 bytes, 10 instructions]
 * Source: src/rom/add_boss_palette_transition_channel_deltas.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: X.
 */
static void add_boss_palette_transition_channel_deltas(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x02C5);
    uint8_t a_hi1 = a >> 8;
    uint16_t y1 = value;
    for (;;) {
        uint16_t value2 = BUS16(c, RAM16(0x0276) + 0x7E0000 + y1);
        uint16_t value3 = BUS16(c, RAM16(0x0279) + 0x7E0000 + y1);
        BUS16_SET(c, RAM16(0x0276) + 0x7E0000 + y1, (uint16_t)(value2 + value3));
        uint16_t value4 = RAM16(0x0266);
        a_hi1 = (uint16_t)(value2 + value3) >> 8;
        y1 = (uint16_t)(y1 + 2);
        if (!(y1 != value4)) break;
    }
    r->x = x;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22A17, SOM_RTS, "gen", add_boss_palette_transition_channel_deltas, 0, L_X, 1, 0, 0, 16, 10)

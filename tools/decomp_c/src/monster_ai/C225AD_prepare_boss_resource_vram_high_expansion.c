#include "som_c.h"

/* C225AD prepare_boss_resource_vram_high_expansion   [class D, 42 bytes, 18 instructions]
 * Source: src/rom/prepare_boss_resource_vram_high_expansion.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void prepare_boss_resource_vram_high_expansion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = BUS16(c, 0xD0BC56 + (uint16_t)(a << 3));
    BUS16_SET(c, 0x002116, value);
    uint16_t value2 = BUS16(c, 0xD0BC54 + (uint16_t)(a << 3));
    RAM16_SET(0x0279, value2);
    uint16_t value3 = BUS16(c, 0xD0BC58 + (uint16_t)(a << 3));
    RAM16_SET(0x0268, value3);
    RAM16_SET(0x026A, 0);
    RAM16_SET(0x026C, 0);
    uint8_t value4 = BUS8(c, 0xD0BC52 + (uint16_t)(a << 3));
    RAM8(0x027B) = value4;
    r->a = (value3 >> 8 << 8) | value4;
    JSR(c, 0x25D5, 0xC225D7); /* expand_boss_resource_to_vram_high */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC225AD, SOM_RTS, "gen", prepare_boss_resource_vram_high_expansion, 0, 0, 1, 0, 0, 42, 18)

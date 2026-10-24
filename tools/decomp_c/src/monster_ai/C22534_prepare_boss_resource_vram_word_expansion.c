#include "som_c.h"

/* C22534 prepare_boss_resource_vram_word_expansion   [class D, 42 bytes, 18 instructions]
 * Source: src/rom/prepare_boss_resource_vram_word_expansion.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void prepare_boss_resource_vram_word_expansion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = BUS8(c, 0xD0BC52 + ((a_hi << 8) | (uint8_t)(a << 3)));
    RAM8(0x027B) = value;
    uint16_t value2 = BUS16(c, 0xD0BC54 + ((a_hi << 8) | (uint8_t)(a << 3)));
    RAM16_SET(0x0279, value2);
    uint16_t value3 = BUS16(c, 0xD0BC56 + ((a_hi << 8) | (uint8_t)(a << 3)));
    BUS16_SET(c, 0x002116, value3);
    uint16_t value4 = BUS16(c, 0xD0BC58 + ((a_hi << 8) | (uint8_t)(a << 3)));
    RAM16_SET(0x0268, value4);
    RAM16_SET(0x026A, 0);
    RAM16_SET(0x026C, 0);
    r->a = value4;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x255C, 0xC2255E); GUARD_JSR(c, sp_call, 0x255C); } /* expand_boss_resource_to_vram_low_high */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22534, SOM_RTS, "gen", prepare_boss_resource_vram_word_expansion, 0, 0, 1, 1, 0, 42, 18)

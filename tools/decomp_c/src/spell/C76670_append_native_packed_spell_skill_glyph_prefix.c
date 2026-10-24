#include "som_c.h"

/* C76670 append_native_packed_spell_skill_glyph_prefix   [class C, 79 bytes, 40 instructions]
 * Source: src/rom/append_native_packed_spell_skill_glyph_prefix.s
 * Documented in docs/ui-native-spell-item-labels.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_packed_spell_skill_glyph_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM16_SET(0xA171, 0x44);
    RAM16_SET(0xA173, (uint16_t)((((RAM8(0x19FE) << 8) | a_hi) & 0xFF00) << 1));
    uint16_t value2 = RAM16(0xA175);
    uint16_t value3 = RAM16(0xA173);
    uint16_t value4 = RAM16(0xA171);
    uint8_t a1;
    if (!(value2 & 0xFF & 0x01)) {
        a1 = (RAM8(0xE180 + (uint16_t)((uint16_t)(((value2 & 0xFF) >> 1) + value3) + value4 + (((value2 & 0xFF) >> 1) + value3 > 0xFFFF))) & 0xF0) >> 4;
    } else {
        a1 = RAM8(0xE180 + (uint16_t)((uint16_t)(((value2 & 0xFF) >> 1) + value3) + value4 + (((value2 & 0xFF) >> 1) + value3 > 0xFFFF))) & 0x0F;
    }
    RAM8(0xA15A) = a1;
    RAM8(0x9C00 + x) = (uint8_t)(a1 + 0xB5);
    r->a = (r->a & 0x00FF) | (((uint16_t)((uint16_t)(((value2 & 0xFF) >> 1) + value3) + value4 + (((value2 & 0xFF) >> 1) + value3 > 0xFFFF)) >> 8) << 8);
    r->x = (uint16_t)(x + 1);
    r->c = a1 + 0xB5 > 0xFF;
    r->v = ((a1 ^ (uint8_t)(a1 + 0xB5)) & ((uint8_t)(a1 + 0xB5) ^ 0xB5) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76670, SOM_RTS, "gen", append_native_packed_spell_skill_glyph_prefix, 0, L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 79, 40)

#include "som_c.h"

/* C1924C expand_native_effect_points_into_horizontal_vertical_reflections   [class B, 336 bytes, 137 instructions]
 * Source: src/rom/expand_native_effect_points_into_horizontal_vertical_reflections.s
 * Documented in docs/actor-visual-effect-point-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void expand_native_effect_points_into_horizontal_vertical_reflections(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xC026 + (x >> 1));
    RAM16_SET(0xC062 + (x >> 1), value);
    RAM16_SET(0xC066 + (x >> 1), value);
    RAM16_SET(0xC06A + (x >> 1), value);
    RAM16_SET(0xC06C + (x >> 1), RAM16(0xC024 + (x >> 1)));
    RAM16_SET(0xC024 + (x >> 1), (uint16_t)(RAM16(0xC000 + (x >> 1)) + 0x0F00) ^ 0xFF00);
    RAM16_SET(0xC026 + (x >> 1), RAM16(0xC002 + (x >> 1)) ^ 0x8000);
    RAM16_SET(0xC028 + (x >> 1), (uint16_t)(RAM16(0xC004 + (x >> 1)) + 0x0F00) ^ 0xFF00);
    RAM16_SET(0xC02A + (x >> 1), RAM16(0xC006 + (x >> 1)) ^ 0x8000);
    RAM16_SET(0xC02C + (x >> 1), (uint16_t)(RAM16(0xC008 + (x >> 1)) + 0x0F00) ^ 0xFF00);
    RAM16_SET(0xC02E + (x >> 1), RAM16(0xC00A + (x >> 1)) ^ 0x8000);
    uint16_t value9 = RAM16(0xC00C + (x >> 1));
    RAM16_SET(0xC048 + (x >> 1), (uint16_t)(value9 + 0x0F00) ^ 0xFF00);
    RAM16_SET(0xC030 + (x >> 1), (value9 >> 8 << 8) | ((uint8_t)((uint8_t)value9 + 0x0F) ^ 0xFF));
    RAM16_SET(0xC054 + (x >> 1), (uint16_t)(((value9 >> 8 << 8) | ((uint8_t)((uint8_t)value9 + 0x0F) ^ 0xFF)) + 0x0F00) ^ 0xFF00);
    uint16_t value10 = RAM16(0xC00E + (x >> 1));
    RAM16_SET(0xC032 + (x >> 1), value10 ^ 0x4000);
    RAM16_SET(0xC04A + (x >> 1), value10 ^ 0x4000 ^ 0xC000);
    RAM16_SET(0xC056 + (x >> 1), value10 ^ 0x4000 ^ 0xC000 ^ 0x4000);
    uint16_t value11 = RAM16(0xC010 + (x >> 1));
    RAM16_SET(0xC04C + (x >> 1), (uint16_t)(value11 + 0x0F00) ^ 0xFF00);
    RAM16_SET(0xC034 + (x >> 1), (value11 >> 8 << 8) | ((uint8_t)((uint8_t)value11 + 0x0F) ^ 0xFF));
    RAM16_SET(0xC058 + (x >> 1), (uint16_t)(((value11 >> 8 << 8) | ((uint8_t)((uint8_t)value11 + 0x0F) ^ 0xFF)) + 0x0F00) ^ 0xFF00);
    uint16_t value12 = RAM16(0xC012 + (x >> 1));
    RAM16_SET(0xC036 + (x >> 1), value12 ^ 0x4000);
    RAM16_SET(0xC04E + (x >> 1), value12 ^ 0x4000 ^ 0xC000);
    RAM16_SET(0xC05A + (x >> 1), value12 ^ 0x4000 ^ 0xC000 ^ 0x4000);
    uint16_t value13 = RAM16(0xC014 + (x >> 1));
    RAM16_SET(0xC050 + (x >> 1), (uint16_t)(value13 + 0x0F00) ^ 0xFF00);
    RAM16_SET(0xC038 + (x >> 1), (value13 >> 8 << 8) | ((uint8_t)((uint8_t)value13 + 0x0F) ^ 0xFF));
    RAM16_SET(0xC05C + (x >> 1), (uint16_t)(((value13 >> 8 << 8) | ((uint8_t)((uint8_t)value13 + 0x0F) ^ 0xFF)) + 0x0F00) ^ 0xFF00);
    uint16_t value14 = RAM16(0xC016 + (x >> 1));
    RAM16_SET(0xC03A + (x >> 1), value14 ^ 0x4000);
    RAM16_SET(0xC052 + (x >> 1), value14 ^ 0x4000 ^ 0xC000);
    RAM16_SET(0xC05E + (x >> 1), value14 ^ 0x4000 ^ 0xC000 ^ 0x4000);
    uint16_t value15 = RAM16(0xC018 + (x >> 1));
    RAM16_SET(0xC03C + (x >> 1), (value15 >> 8 << 8) | ((uint8_t)((uint8_t)value15 + 0x0F) ^ 0xFF));
    RAM16_SET(0xC03E + (x >> 1), RAM16(0xC01A + (x >> 1)) ^ 0x4000);
    uint16_t value17 = RAM16(0xC01C + (x >> 1));
    RAM16_SET(0xC040 + (x >> 1), (value17 >> 8 << 8) | ((uint8_t)((uint8_t)value17 + 0x0F) ^ 0xFF));
    RAM16_SET(0xC042 + (x >> 1), RAM16(0xC01E + (x >> 1)) ^ 0x4000);
    uint16_t value19 = RAM16(0xC020 + (x >> 1));
    RAM16_SET(0xC044 + (x >> 1), (value19 >> 8 << 8) | ((uint8_t)((uint8_t)value19 + 0x0F) ^ 0xFF));
    uint16_t value20 = RAM16(0xC022 + (x >> 1));
    RAM16_SET(0xC046 + (x >> 1), value20 ^ 0x4000);
    r->a = value20 ^ 0x4000;
    r->x = x >> 1;
    r->c = (uint8_t)value19 + 0x0F > 0xFF;
    r->v = (((uint8_t)value19 ^ (uint8_t)((uint8_t)value19 + 0x0F)) & ((uint8_t)((uint8_t)value19 + 0x0F) ^ 0x0F) & 0x80) != 0;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1924C, SOM_RTL, "gen", expand_native_effect_points_into_horizontal_vertical_reflections, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 336, 137)

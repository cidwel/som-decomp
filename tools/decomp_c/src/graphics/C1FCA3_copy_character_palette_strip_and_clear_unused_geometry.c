#include "som_c.h"

/* C1FCA3 copy_character_palette_strip_and_clear_unused_geometry   [class B, 84 bytes, 36 instructions]
 * Source: src/rom/copy_character_palette_strip_and_clear_unused_geometry.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BY.
 */
static void copy_character_palette_strip_and_clear_unused_geometry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0000, 8);
    uint16_t value = RAM16(0x001C);
    uint16_t value2 = RAM16(0xE083 + x);
    uint8_t a_hi1;
    if ((value2 & 0x0F) >= 4) {
        a_hi1 = 0;
    } else {
        if ((value2 & 0x0F) == 3) {
            RAM16_SET(0xE09C + x, 0x7F7F);
        } else {
            if ((value2 & 0x0F) == 2) {
                RAM16_SET(0xE098 + x, 0x7F7F);
                RAM16_SET(0xE09C + x, 0x7F7F);
            } else {
                RAM16_SET(0xE094 + x, 0x7F7F);
                RAM16_SET(0xE098 + x, 0x7F7F);
                RAM16_SET(0xE09C + x, 0x7F7F);
            }
        }
        a_hi1 = 0x7F;
    }
    uint8_t a_hi2 = a_hi1;
    uint16_t x1 = x;
    uint16_t y1 = value;
    do {
        uint16_t value3 = RAM16(0xE090 + x1);
        RAM16_SET(0xE700 + y1, value3);
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        a_hi2 = value3 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM16(0x0000) != 0);
    uint16_t value4 = RAM16(0x001C);
    RAM16_SET(0x001C, (uint16_t)(value4 + 0x10));
    r->a = (uint16_t)(value4 + 0x10);
    r->y = y1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FCA3, SOM_RTS, "gen", copy_character_palette_strip_and_clear_unused_geometry, 0, L_B | L_Y, 1, 1, 0, 84, 36)

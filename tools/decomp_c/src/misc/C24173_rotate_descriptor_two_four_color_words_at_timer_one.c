#include "som_c.h"

/* C24173 rotate_descriptor_two_four_color_words_at_timer_one   [class B, 45 bytes, 18 instructions]
 * Source: src/rom/rotate_descriptor_two_four_color_words_at_timer_one.s
 * Documented in docs/boss-descriptor-two-palette.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void rotate_descriptor_two_four_color_words_at_timer_one(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value2 != 1) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        zero1 = value2 == 1;
        negative1 = (uint16_t)(value2 - 1) & 0x8000;
    } else {
        RAM16_SET(0x0295, RAM16(0x07D8));
        RAM16_SET(0x07D8, RAM16(0x07DE));
        RAM16_SET(0x07DE, RAM16(0x07DC));
        RAM16_SET(0x07DC, RAM16(0x07DA));
        uint16_t value7 = RAM16(0x0295);
        RAM16_SET(0x07DA, value7);
        RAM16_SET(OBJECT_AGE + value, 0);
        a1 = (uint8_t)value7;
        a_hi1 = value7 >> 8;
        zero1 = value == 0;
        negative1 = value & 0x8000;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24173, SOM_RTS, "gen", rotate_descriptor_two_four_color_words_at_timer_one, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 45, 18)

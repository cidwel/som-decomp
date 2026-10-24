#include "som_c.h"

/* C019C7 format_dialogue_quantity_digits_and_append_original_suffix   [class A, 69 bytes, 40 instructions]
 * Source: src/rom/format_dialogue_quantity_digits_and_append_original_suffix.s
 * Documented in docs/event-dialogue-number-window.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: YV.
 */
static void format_dialogue_quantity_digits_and_append_original_suffix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t a1 = 6;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value = RAM8(0xA136 + y1);
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        if (value != 0) {
            a2 = value;
            a_hi2 = a1;
            x2 = x1;
            y2 = (uint16_t)(y1 + 1);
        } else {
            RAM8(0xA1E0 + x1) = 0x80;
            if ((uint8_t)(a1 - 1) != 0) {
                a1 = (uint8_t)(a1 - 1);
                a_hi1 = 0x80;
                x1 = (uint16_t)(x1 + 1);
                y1 = (uint16_t)(y1 + 1);
                continue;
            }
            a2 = 0x80;
            a_hi2 = (uint8_t)(a1 - 1);
            x2 = (uint16_t)(x1 + 1);
            y2 = (uint16_t)(y1 + 2);
        }
        a1 = a2;
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = y2;
        break;
    }
    uint8_t a3 = (uint8_t)(a_hi1 + 1);
    uint8_t a_hi3 = a1;
    uint16_t x3 = x1;
    uint16_t y3 = (uint16_t)(y1 - 1);
    bool carry1 = 0;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value2 = RAM8(0xA136 + y3);
        RAM8(0xA1E0 + x3) = (uint8_t)(value2 + 0xB5);
        a3 = (uint8_t)(a3 - 1);
        a_hi3 = (uint8_t)(value2 + 0xB5);
        x3 = (uint16_t)(x3 + 1);
        y3 = (uint16_t)(y3 + 1);
        carry1 = value2 + 0xB5 > 0xFF;
        overflow1 = ((value2 ^ (uint8_t)(value2 + 0xB5)) & ((uint8_t)(value2 + 0xB5) ^ 0xB5) & 0x80) != 0;
        if (!(a3 != 0)) break;
    }
    RAM8(0xA1E0 + x3) = 0;
    uint8_t a_hi4 = a_hi3;
    uint16_t x4 = 0;
    uint16_t y4 = x3;
    bool carry2 = carry1;
    bool overflow2 = overflow1;
    for (;;) {
        uint8_t value3 = BUS8(c, 0xC77B6A + x4);
        RAM8(0xA1E0 + y4) = value3;
        x4 = (uint16_t)(x4 + 1);
        y4 = (uint16_t)(y4 + 1);
        if (!(value3 != 0)) break;
    }
    r->y = y4;
    r->v = overflow2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC019C7, SOM_RTS, "gen", format_dialogue_quantity_digits_and_append_original_suffix, 0, L_Y | L_V, 1, 1, 0, 69, 40)

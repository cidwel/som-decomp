#include "som_c.h"

/* C754DB convert_24_bit_dialogue_quantity_to_seven_digit_fields   [class B, 100 bytes, 51 instructions]
 * Source: src/rom/convert_24_bit_dialogue_quantity_to_seven_digit_fields.s
 * Documented in docs/event-dialogue-number-window.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void convert_24_bit_dialogue_quantity_to_seven_digit_fields(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t a1 = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 0;
    for (;;) {
        RAM8(0xA146 + y1) = 0;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = 0;
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != a_hi1)) break;
    }
    RAM8(0xA175) = a1;
    uint8_t a_hi2 = a_hi1;
    uint16_t y2 = 0x18;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t a2 = 4;
        uint8_t a_hi3 = a_hi2;
        uint16_t x1 = 0;
        bool carry1 = 0;
        for (;;) {
            uint8_t value = RAM8(0xA146 + x1);
            bool carry_bcd, overflow_bcd;
            uint8_t sum_bcd = SOM_ADC8_DEC(value, value, carry1, &carry_bcd, &overflow_bcd);
            RAM8(0xA146 + x1) = sum_bcd;
            a2 = (uint8_t)(a2 - 1);
            a_hi3 = sum_bcd;
            x1 = (uint16_t)(x1 + 1);
            carry1 = carry_bcd;
            if (!(a2 != 0)) break;
        }
        uint8_t value2 = RAM8(0xA136);
        RAM8(0xA136) <<= 1;
        uint8_t value3 = RAM8(0xA137);
        RAM8(0xA137) = (uint8_t)((RAM8(0xA137) << 1) | (value2 >> 7));
        uint8_t value4 = RAM8(0xA138);
        RAM8(0xA138) = (uint8_t)((RAM8(0xA138) << 1) | (value3 >> 7));
        uint8_t value5 = RAM8(0xA146);
        bool carry_bcd2, overflow_bcd2;
        uint8_t sum_bcd2 = SOM_ADC8_DEC(0, value5, value4 >> 7, &carry_bcd2, &overflow_bcd2);
        RAM8(0xA146) = sum_bcd2;
        a_hi2 = a_hi3;
        y2 = (uint16_t)(y2 - 1);
        overflow1 = overflow_bcd2;
        if (!(y2 != 0)) break;
    }
    uint8_t value6 = RAM8(0xA149);
    RAM8(0xA136) = value6;
    uint8_t a3 = value6;
    uint8_t a_hi4 = a_hi2;
    uint16_t x2 = 1;
    uint16_t y3 = 3;
    bool carry2 = 0;
    for (;;) {
        uint8_t value7 = RAM8(0xA145 + y3);
        RAM8(0x0000 + sp0) = value7;
        RAM8(0xA136 + x2) = value7 >> 4;
        uint8_t value8 = RAM8(0x0000 + sp0);
        RAM8(0xA136 + (uint16_t)(x2 + 1)) = value8 & 0x0F;
        a3 = value8 & 0x0F;
        x2 = (uint16_t)(x2 + 2);
        y3 = (uint16_t)(y3 - 1);
        carry2 = value7 >> 3 & 0x01;
        if (!(y3 != 0)) break;
    }
    r->a = (a_hi4 << 8) | a3;
    r->y = y3;
    r->c = carry2;
    r->v = overflow1;
    r->d = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC754DB, SOM_RTL, "gen", convert_24_bit_dialogue_quantity_to_seven_digit_fields, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 0, 100, 51)

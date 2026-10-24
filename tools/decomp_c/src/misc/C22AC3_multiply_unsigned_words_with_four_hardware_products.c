#include "som_c.h"

/* C22AC3 multiply_unsigned_words_with_four_hardware_products   [class B, 108 bytes, 52 instructions]
 * Source: src/rom/multiply_unsigned_words_with_four_hardware_products.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void multiply_unsigned_words_with_four_hardware_products(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM8(0x0258) = 0;
    RAM8(0x0259) = 0;
    uint8_t value = RAM8(0x0246);
    BUS8_SET(c, 0x004202, value);
    uint8_t value2 = RAM8(0x024E);
    BUS8_SET(c, 0x004203, value2);
    uint8_t value3 = RAM8(0x0247);
    BUS8_SET(c, 0x004202, value3);
    uint8_t value4 = BUS8(c, 0x004216);
    RAM8(0x0256) = value4;
    uint8_t value5 = BUS8(c, 0x004217);
    RAM8(0x0257) = value5;
    BUS8_SET(c, 0x004203, value2);
    BUS8_SET(c, 0x004202, value);
    uint8_t value6 = BUS8(c, 0x004216);
    uint8_t value7 = RAM8(0x0257);
    RAM8(0x0257) = (uint8_t)(value6 + value7);
    uint8_t value8 = BUS8(c, 0x004217);
    RAM8(0x0258) = (uint8_t)(value8 + RAM8(0x0258) + (value6 + value7 > 0xFF));
    uint8_t value10 = RAM8(0x024F);
    BUS8_SET(c, 0x004203, value10);
    BUS8_SET(c, 0x004202, value3);
    uint8_t value11 = BUS8(c, 0x004216);
    uint8_t value12 = RAM8(0x0257);
    RAM8(0x0257) = (uint8_t)(value11 + value12);
    uint8_t value13 = BUS8(c, 0x004217);
    RAM8(0x0258) = (uint8_t)(value13 + RAM8(0x0258) + (value11 + value12 > 0xFF));
    BUS8_SET(c, 0x004203, value10);
    uint16_t value15 = BUS16(c, 0x004216);
    uint16_t value16 = RAM16(0x0258);
    RAM16_SET(0x0258, (uint16_t)(value15 + value16));
    r->a = (uint16_t)(value15 + value16);
    r->c = value15 + value16 > 0xFFFF;
    r->v = ((value15 ^ (uint16_t)(value15 + value16)) & (value16 ^ (uint16_t)(value15 + value16)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22AC3, SOM_RTS, "gen", multiply_unsigned_words_with_four_hardware_products, 0, L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 108, 52)

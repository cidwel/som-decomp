#include "som_c.h"

/* C0543B multiply_byte_word_divide_by_100   [class B, 119 bytes, 59 instructions]
 * Source: src/rom/multiply_byte_word_divide_by_100.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYV.
 */
static void multiply_byte_word_divide_by_100(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RAM8(0x03CE) = 0;
    BUS8_SET(c, 0x004202, RAM8(BATTLE_TEMP_A6));
    BUS8_SET(c, 0x004203, RAM8(BATTLE_TEMP_A8));
    uint16_t value = BUS16(c, 0x004216);
    RAM16_SET(BATTLE_MUL_WORK, value);
    BUS8_SET(c, 0x004203, RAM8(0x03A9));
    uint16_t value3 = BUS16(c, 0x004216);
    uint16_t value4 = RAM16(0x03CD);
    RAM16_SET(0x03CD, (uint16_t)(value3 + value4));
    BUS16_SET(c, 0x004204, (uint16_t)(value3 + value4));
    BUS8_SET(c, 0x004206, 0x64);
    RAM8(0x03D0) = 0;
    uint16_t value5 = BUS16(c, 0x004214);
    RAM16_SET(0x03D1, value5);
    uint8_t value6 = BUS8(c, 0x004216);
    BUS16_SET(c, 0x004204, (value6 << 8) | RAM8(BATTLE_MUL_WORK));
    BUS8_SET(c, 0x004206, 0x64);
    uint16_t value7 = BUS16(c, 0x004214);
    uint16_t value8 = RAM16(0x03D0);
    RAM16_SET(BATTLE_TEMP_A4, (uint16_t)(value7 + value8));
    r->v = ((value7 ^ (uint16_t)(value7 + value8)) & (value8 ^ (uint16_t)(value7 + value8)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0543B, SOM_RTS, "gen", multiply_byte_word_divide_by_100, 0, L_X | L_Y | L_V, 1, 1, 0, 119, 59)

#include "som_c.h"

/* C054B6 multiply_byte_by_word   [class B, 49 bytes, 23 instructions]
 * Source: src/rom/multiply_byte_by_word.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYV.
 */
static void multiply_byte_by_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    BUS8_SET(c, 0x004202, RAM8(0x03D0));
    BUS8_SET(c, 0x004203, RAM8(0x03D4));
    RAM16_SET(0x03CD, 0);
    uint16_t value3 = BUS16(c, 0x004216);
    RAM16_SET(BATTLE_MUL_WORK, value3);
    BUS8_SET(c, 0x004203, RAM8(0x03D5));
    uint16_t value5 = BUS16(c, 0x004216);
    uint16_t value6 = RAM16(0x03CD);
    RAM16_SET(0x03CD, (uint16_t)(value5 + value6));
    r->v = ((value5 ^ (uint16_t)(value5 + value6)) & (value6 ^ (uint16_t)(value5 + value6)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC054B6, SOM_RTS, "gen", multiply_byte_by_word, 0, L_X | L_Y | L_V, 1, 1, 0, 49, 23)

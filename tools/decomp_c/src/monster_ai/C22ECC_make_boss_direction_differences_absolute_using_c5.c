#include "som_c.h"

/* C22ECC make_boss_direction_differences_absolute_using_c5   [class A, 23 bytes, 13 instructions]
 * Source: src/rom/make_boss_direction_differences_absolute_using_c5.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYV.
 */
static void make_boss_direction_differences_absolute_using_c5(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0246);
    uint8_t a_hi1;
    bool overflow1;
    if (!(value & 0x8000)) {
        a_hi1 = value >> 8;
        overflow1 = overflow;
    } else {
        uint16_t value2 = RAM16(0x02C5);
        RAM16_SET(0x0246, (uint16_t)(value2 - value));
        a_hi1 = (uint16_t)(value2 - value) >> 8;
        overflow1 = ((value2 ^ value) & (value2 ^ (uint16_t)(value2 - value)) & 0x8000) != 0;
    }
    uint16_t value3 = RAM16(0x024E);
    bool overflow2;
    if (!(value3 & 0x8000)) {
        overflow2 = overflow1;
    } else {
        uint16_t value4 = RAM16(0x02C5);
        RAM16_SET(0x024E, (uint16_t)(value4 - value3));
        overflow2 = ((value4 ^ value3) & (value4 ^ (uint16_t)(value4 - value3)) & 0x8000) != 0;
    }
    r->v = overflow2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22ECC, SOM_RTS, "gen", make_boss_direction_differences_absolute_using_c5, 0, L_X | L_Y | L_V, 1, 0, 0, 23, 13)

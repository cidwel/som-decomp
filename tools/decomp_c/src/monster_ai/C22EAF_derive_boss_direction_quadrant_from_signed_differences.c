#include "som_c.h"

/* C22EAF derive_boss_direction_quadrant_from_signed_differences   [class B, 29 bytes, 14 instructions]
 * Source: src/rom/derive_boss_direction_quadrant_from_signed_differences.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYV.
 */
static void derive_boss_direction_quadrant_from_signed_differences(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x026A, 0);
    if (RAM16(0x024E) & 0x8000) {
        RAM16_SET(0x026A, (uint16_t)(RAM16(0x026A) + 1));
        RAM16_SET(0x026A, (uint16_t)(RAM16(0x026A) + 1));
    }
    if (RAM16(0x0246) & 0x8000) {
        RAM16_SET(0x026A, (uint16_t)(RAM16(0x026A) + 1));
    }
    uint16_t value3 = RAM16(0x026A);
    if (value3 >= 2) {
        RAM16_SET(0x026A, value3 ^ 1);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22EAF, SOM_RTS, "gen", derive_boss_direction_quadrant_from_signed_differences, 0, L_X | L_Y | L_V, 1, 0, 0, 29, 14)

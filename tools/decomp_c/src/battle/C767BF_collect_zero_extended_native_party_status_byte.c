#include "som_c.h"

/* C767BF collect_zero_extended_native_party_status_byte   [class A, 13 bytes, 7 instructions]
 * Source: src/rom/collect_zero_extended_native_party_status_byte.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void collect_zero_extended_native_party_status_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0xA1E0 + x) = RAM8(0xE180 + y);
    RAM8(0xA1E0 + (uint16_t)(x + 1)) = 0;
    r->x = (uint16_t)(x + 2);
    r->y = (uint16_t)(y + 1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC767BF, SOM_RTS, "gen", collect_zero_extended_native_party_status_byte, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 13, 7)

#include "som_c.h"

/* C767A6 swap_two_native_party_status_statistic_pairs   [class A, 25 bytes, 9 instructions]
 * Source: src/rom/swap_two_native_party_status_statistic_pairs.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BCV.
 */
static void swap_two_native_party_status_statistic_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0xA1EA);
    uint16_t value2 = RAM16(0xA1EC);
    RAM16_SET(0xA1EC, value);
    RAM16_SET(0xA1EA, value2);
    uint16_t value3 = RAM16(0xA1EE);
    uint16_t value4 = RAM16(0xA1F0);
    RAM16_SET(0xA1F0, value3);
    RAM16_SET(0xA1EE, value4);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC767A6, SOM_RTS, "gen", swap_two_native_party_status_statistic_pairs, 0, L_B | L_C | L_V, 1, 1, 0, 25, 9)

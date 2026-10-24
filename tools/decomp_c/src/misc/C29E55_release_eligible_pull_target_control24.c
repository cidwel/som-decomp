#include "som_c.h"

/* C29E55 release_eligible_pull_target_control24   [class B, 26 bytes, 11 instructions]
 * Source: src/rom/release_eligible_pull_target_control24.s
 * Documented in docs/boss-native-spell-pull-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void release_eligible_pull_target_control24(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B2 + x);
    if ((RAM16(0x0190 + value) & 0xC568) == 0) {
        if (RAM8(0x0060 + value) == 0) {
            RAM8(0x01E5 + value) = 0x24;
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29E55, SOM_RTS, "gen", release_eligible_pull_target_control24, 0, 0, 1, 0, 0, 26, 11)

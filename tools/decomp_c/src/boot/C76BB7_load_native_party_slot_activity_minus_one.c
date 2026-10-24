#include "som_c.h"

/* C76BB7 load_native_party_slot_activity_minus_one   [class A, 16 bytes, 9 instructions]
 * Source: src/rom/load_native_party_slot_activity_minus_one.s
 * Documented in docs/ui-native-party-page-callback.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void load_native_party_slot_activity_minus_one(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xE000 + (uint16_t)((((((a_hi << 8) | a) & 0xFF) << 8) | 0) << 1));
    r->a = (r->a & 0x00FF) | (((uint16_t)((((((a_hi << 8) | a) & 0xFF) << 8) | 0) << 1) >> 8) << 8);
    r->x = (uint16_t)((((((a_hi << 8) | a) & 0xFF) << 8) | 0) << 1);
    r->c = (((((a_hi << 8) | a) & 0xFF) << 8) | 0) & 0x8000;
    r->z = (uint8_t)(value - 1) == 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76BB7, SOM_RTL, "gen", load_native_party_slot_activity_minus_one, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 16, 9)

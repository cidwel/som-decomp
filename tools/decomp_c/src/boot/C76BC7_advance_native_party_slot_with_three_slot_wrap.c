#include "som_c.h"

/* C76BC7 advance_native_party_slot_with_three_slot_wrap   [class A, 8 bytes, 5 instructions]
 * Source: src/rom/advance_native_party_slot_with_three_slot_wrap.s
 * Documented in docs/ui-native-party-page-callback.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXCV.
 */
static void advance_native_party_slot_with_three_slot_wrap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    uint8_t a1;
    if ((uint8_t)(a + 1) != 3) {
        a1 = (uint8_t)(a + 1);
    } else {
        a1 = 0;
    }
    SET_A8(r, a1);
    r->c = (uint8_t)(a + 1) >= 3;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76BC7, SOM_RTL, "gen", advance_native_party_slot_with_three_slot_wrap, 0, L_A | L_B | L_X | L_C | L_V, 1, 1, 0, 8, 5)

#include "som_c.h"

/* C02A9A near_call_native_party_status_page_constructor   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/near_call_native_party_status_page_constructor.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void near_call_native_party_status_page_constructor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2A9D, 0xC7633C); GUARD_JSL(c, sp_call, 0x2A9D); } /* construct_native_party_status_page_with_text_bars_portrait_and_flags */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02A9A, SOM_RTS, "hand", near_call_native_party_status_page_constructor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)

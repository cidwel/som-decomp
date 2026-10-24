#include "som_c.h"
#include "som_hand_d.h"

/* C1EA62 event_refresh_all_map_object_slots   [class B, 34 bytes, 16 instructions]
 * Source: src/rom/event_refresh_all_map_object_slots.s
 * Documented in docs/event-vm-object-refresh.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void event_refresh_all_map_object_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, -1)) return;
L_C1EA62:;
    i_rep(r, 0x10);
    a_ldx(r, 0x1600);
    BIT(c, DP, 0xed);
    if (!r->n) goto L_C1EA6E;
    a_ldx(r, 0xa00);
L_C1EA6E:;
    STX(c, DP, 0x10);
    JSR(c, 0xea72, 0xC1EA84);
    i_rep(r, 0x20);
    LDA(c, DP, 0x10);
    r->c = 1;
    a_sbc(r, 0x200);
    i_tax(r);
    a_cmp(r, 0x600);
    if (r->c) goto L_C1EA6E;
    INC(c, DP, 0xd1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EA62, SOM_RTS, "hand", event_refresh_all_map_object_slots, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, -1, 34, 16)

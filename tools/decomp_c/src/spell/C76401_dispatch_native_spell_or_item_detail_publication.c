#include "som_c.h"
#include "som_hand_d.h"

/* C76401 dispatch_native_spell_or_item_detail_publication   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/dispatch_native_spell_or_item_detail_publication.s
 * Documented in docs/ui-native-spell-item-detail.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void dispatch_native_spell_or_item_detail_publication(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
L_C76401:;
    LDA(c, ABS, 0xa202);
    a_cmp(r, 0x8);
    if (!r->z) goto L_C7640D;
    JSR(c, 0x640a, 0xC7649E);
    goto L_C76410;
L_C7640D:;
    JSR(c, 0x640f, 0xC76411);
L_C76410:;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76401, SOM_RTL, "hand", dispatch_native_spell_or_item_detail_publication, 0, 0, 1, 1, 0, 16, 7)

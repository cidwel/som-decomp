#include "som_c.h"
#include "som_hand_d.h"

/* C0DDBE scan_map_object_cache_for_creation   [class B, 37 bytes, 20 instructions]
 * Source: src/rom/scan_map_object_cache_for_creation.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void scan_map_object_cache_for_creation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
L_C0DDBE:;
    i_sep(r, 0x20);
    LDA(c, ABY, 0xc800);
    if (r->z) goto L_C0DDCD;
    if (r->n) goto L_C0DDCF;
    JSR(c, 0xddc9, 0xC0DDE3);
    if (!r->c) goto L_C0DDCF;
    RETURN_RTS(c);
L_C0DDCD:;
    r->c = 0;
    RETURN_RTS(c);
L_C0DDCF:;
    i_sep(r, 0x20);
    DEC(c, DP, 0xc);
    if (r->z) goto L_C0DDCD;
    i_rep(r, 0x20);
    i_tya(r);
    r->c = 0;
    a_adc(r, 0x10);
    i_tay(r);
    a_cmp(r, 0x300);
    if (!r->c) goto L_C0DDBE;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DDBE, SOM_RTS, "hand", scan_map_object_cache_for_creation, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 37, 20)

#include "som_c.h"

/* C064A4 normalize_menu_native_direct_page_and_bank   [class A, 15 bytes, 10 instructions]
 * Source: src/rom/normalize_menu_native_direct_page_and_bank.s
 * Documented in docs/event-menu-actor-selection.md
 * Entry: M=8 bit X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void normalize_menu_native_direct_page_and_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, -1)) return;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | a;
    r->z = ((a_hi << 8) | a) == 0;
    r->n = ((a_hi << 8) | a) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC064A4, SOM_RTL, "gen", normalize_menu_native_direct_page_and_bank, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, -1, 15, 10)

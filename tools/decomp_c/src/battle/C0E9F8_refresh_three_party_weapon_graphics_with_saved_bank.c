#include "som_c.h"

/* C0E9F8 refresh_three_party_weapon_graphics_with_saved_bank   [class B, 33 bytes, 16 instructions]
 * Source: src/rom/refresh_three_party_weapon_graphics_with_saved_bank.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYC.
 */
static void refresh_three_party_weapon_graphics_with_saved_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->x = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xEA06, 0xC0EA19); /* refresh_object_weapon_graphics_and_palette */
    r->sp += 1;
    r->x = 0x0200;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xEA0E, 0xC0EA19); /* refresh_object_weapon_graphics_and_palette */
    r->sp += 1;
    r->x = 0x0400;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xEA16, 0xC0EA19); /* refresh_object_weapon_graphics_and_palette */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0E9F8, SOM_RTS, "gen", refresh_three_party_weapon_graphics_with_saved_bank, 0, L_A | L_B | L_X | L_Y | L_C, 2, 1, 1, 33, 16)

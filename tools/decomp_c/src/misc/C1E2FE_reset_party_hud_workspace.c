#include "som_c.h"

/* C1E2FE reset_party_hud_workspace   [class A, 40 bytes, 17 instructions]
 * Source: src/rom/reset_party_hud_workspace.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void reset_party_hud_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t x1 = 0x2E;
    for (;;) {
        RAM16_SET(0x0A50 + x1, 0);
        x1 = (uint8_t)(x1 - 1);
        if (!(!(x1 & 0x80))) break;
    }
    RAM8(0x0A56) = 0x17;
    RAM8(0x0A66) = 0x17;
    RAM8(0x0A76) = 0x17;
    RAM8(0x0A57) = 0x28;
    RAM8(0x0A67) = 0x28;
    RAM8(0x0A77) = 0x28;
    r->a = 0x28;
    r->x = x1;
    r->y = (uint8_t)y;
    r->c = carry;
    r->v = overflow;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E2FE, SOM_RTS, "gen", reset_party_hud_workspace, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 40, 17)

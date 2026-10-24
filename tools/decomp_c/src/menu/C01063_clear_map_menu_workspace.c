#include "som_c.h"

/* C01063 clear_map_menu_workspace   [class B, 53 bytes, 23 instructions]
 * Source: src/rom/clear_map_menu_workspace.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYV.
 */
static void clear_map_menu_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x1D04) = 0;
    RAM8(0x1D00) = 0;
    RAM8(0x1D12) = 0;
    uint16_t x1 = 0x0536;
    for (;;) {
        RAM8(0x9BFF + x1) = 0;
        x1 = (uint16_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    uint8_t value = RAM8(0x1D04);
    RAM8(0x1D04) = value | 0x44;
    RAM8(0xA187) = 0;
    r->a = (a_hi << 8) | (value | 0x44);
    r->y = y;
    r->c = carry;
    r->z = (value | 0x44) == 0;
    r->n = (value | 0x44) & 0x80;
    r->v = overflow;
    r->sp -= 2;
    JSL(c, 0x1094, 0xC00EBF); /* reset_map_menu_state */
    r->sp += 2;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC01063, SOM_RTL, "gen", clear_map_menu_workspace, 0, L_A | L_B | L_X | L_Y | L_V, 3, 1, 0, 53, 23)

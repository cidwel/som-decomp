#include "som_c.h"

/* C00FAA clear_direct_page_and_party_workspace_before_load_game_menu   [class A, 43 bytes, 22 instructions]
 * Source: src/rom/clear_direct_page_and_party_workspace_before_load_game_menu.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void clear_direct_page_and_party_workspace_before_load_game_menu(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0;
    bool carry1 = carry;
    for (;;) {
        BUS8_SET(c, x1, 0);
        uint16_t x1_next = (uint16_t)(x1 + 1);
        bool carry1_next = (uint16_t)(x1 + 1) >= 0x0100;
        x1 = x1_next;
        carry1 = carry1_next;
        if (!(x1 != 0x0100)) break;
    }
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    uint16_t x2 = 0x0600;
    for (;;) {
        RAM8(0xDFFF + x2) = 0;
        x2 = (uint16_t)(x2 - 1);
        if (!(x2 != 0)) break;
    }
    uint16_t x3 = 0x80;
    for (;;) {
        RAM8(0xCBFF + x3) = 0;
        x3 = (uint16_t)(x3 - 1);
        if (!(x3 != 0)) break;
    }
    RAM8(0x00D9) = 1;
    RAM8(0xE000) = 1;
    uint8_t value = RAM8(0x0000 + sp0);
    r->a = (a_hi << 8) | 1;
    r->x = x3;
    r->y = y;
    r->c = carry1;
    r->v = overflow;
    r->db = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00FAA, SOM_RTS, "gen", clear_direct_page_and_party_workspace_before_load_game_menu, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 43, 22)

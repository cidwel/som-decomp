#include "som_c.h"
#include "som_hand.h"

/* C06433 initialize_native_menu_hero_categories_with_saved_context   [class C, 108 bytes, 52 instructions]
 * Source: src/rom/initialize_native_menu_hero_categories_with_saved_context.s
 * Documented in docs/event-menu-state-api.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void initialize_native_menu_hero_categories_with_saved_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp; /* PHP PHB PHD: four real stack bytes */
    RAM8(sp0 - 0) = (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;
    RAM8(sp0 - 1) = r->db;
    RAM8(sp0 - 2) = r->dp >> 8;
    RAM8(sp0 - 3) = (uint8_t)r->dp;
    r->sp -= 4;
    JSL(c, 0x6439, 0xC064A4); /* normalize_menu_native_direct_page_and_bank: D = 0, DB = 0 */
    r->sp += 4;
    RAM8(0x1806) = 0;
    RAM8(0x1807) = 0;
    for (uint16_t x = 0; x < 0x10; x++) RAM8(0x1870 + x) = 0;
    RAM8(0x1870) = 3;
    RAM8(0x1871) = 3;
    RAM8(0x1872) = 3;
    r->a = 3; /* LDA #$0000 widened, then LDA #$03 in 8-bit mode */
    r->x = 0x10;
    r->dp = RAM8(sp0 - 3) | (RAM8(sp0 - 2) << 8); /* PLD */
    r->db = RAM8(sp0 - 1); /* PLB */
    som_pull_p(c, sp0); /* PLP restores every flag, including C Z N V */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC06433, SOM_RTL, "hand", initialize_native_menu_hero_categories_with_saved_context, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 158, 52)

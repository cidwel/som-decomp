#include "som_c.h"

/* C06617 enter_public_shop_buy_ring_and_restore_saved_party_categories   [class C, 88 bytes, 39 instructions]
 * Source: src/rom/enter_public_shop_buy_ring_and_restore_saved_party_categories.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCV.
 */
static void enter_public_shop_buy_ring_and_restore_saved_party_categories(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    RAM8(0x0000 + sp0 - 2) = dp >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)dp;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x661C, 0xC06696); GUARD_JSR(c, sp_call, 0x661C); } /* initialize_event_menu_mode_and_saved_coordinates */
    r->sp += 4;
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    BUS8_SET(c, (db_ret << 0x10) + 0x1847, 1);
    r->a = (a_all >> 8 << 8) | 1;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6626, 0xC06AA5); GUARD_JSR(c, sp_call, 0x6626); } /* initialize_event_menu_controller_and_descriptor */
    r->sp += 4;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6629, 0xC066B5); GUARD_JSR(c, sp_call, 0x6629); } /* initialize_native_ring_palette_text_graphics_input_and_list */
    r->sp += 4;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x662C, 0xC0666F); GUARD_JSR(c, sp_call, 0x662C); } /* poll_and_update_complete_native_shop_ring_until_closed */
    r->sp += 4;
    uint8_t db_ret3 = r->db;
    uint16_t value = BUS16_RDP(c, (db_ret3 << 0x10) + 0x1860);
    BUS16_SET(c, (db_ret3 << 0x10) + 0x1870, value);
    uint16_t value2 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x1862);
    BUS16_SET(c, (db_ret3 << 0x10) + 0x1872, value2);
    r->a = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL_FRAME(c, 0xC065BE, SOM_RTS, 4); /* finish_native_ring_public_menu_and_restore_saved_context */
}
SOM_REGISTER(0xC06617, SOM_RTS, "gen", enter_public_shop_buy_ring_and_restore_saved_party_categories, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 88, 39)

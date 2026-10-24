#include "som_c.h"

/* C75217 dispatch_native_name_page_party_icon_variant   [class C, 12 bytes, 7 instructions]
 * Source: src/rom/dispatch_native_name_page_party_icon_variant.s
 * Documented in docs/event-menu-party-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void dispatch_native_name_page_party_icon_variant(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, -1)) return;
    a_lda(r, 0x00);
    i_xba(r);
    a_lda(r, RAM8(0xA22B));
    i_asla(r);
    i_tax(r);
    {
        const uint16_t sp_call = r->sp;
        switch (r->x) {
        case 0x0000: JSR(c, 0x5221, 0xC75EC8); GUARD_JSR_DB(c, sp_call, 0x5221, 0x7E); break; /* native_menu_party_icon_alternative_entry_block */
        default: JSR(c, 0x5221, 0xC70000 | BUS16(c, 0xC70000 + (uint16_t)(0x5223 + r->x))); GUARD_JSR_DB(c, sp_call, 0x5221, 0x7E);
        }
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75217, SOM_RTL, "hand", dispatch_native_name_page_party_icon_variant, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 12, 7)

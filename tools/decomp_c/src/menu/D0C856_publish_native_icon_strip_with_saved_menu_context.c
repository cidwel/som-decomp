#include "som_c.h"
#include "som_hand_b.h"

/* D0C856 publish_native_icon_strip_with_saved_menu_context   [class B, 22 bytes, 12 instructions]
 * Source: src/rom/publish_native_icon_strip_with_saved_menu_context.s
 * Documented in docs/event-menu-icon-strip.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void publish_native_icon_strip_with_saved_menu_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    i_php(c);
    i_phb(c);
    i_phd(c);
    JSL_CHK(c, 0xC85C, 0xC064A4); /* normalize_menu_native_direct_page_and_bank */
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    bus16_set_once(c, ((uint32_t)r->db << 16) + 0x180C, r->x);
    JSR_CHK(c, 0xC864, 0xD0C86C); /* resolve_twelve_native_menu_icon_descriptor_words */
    JSR_CHK(c, 0xC867, 0xD0C8A3); /* upload_native_twelve_icon_strip_and_upper_palette */
    hand_pld(c);
    hand_plb(c);
    hand_plp(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0C856, SOM_RTL, "hand", publish_native_icon_strip_with_saved_menu_context, 0, L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 22, 12)

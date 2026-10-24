#include "som_c.h"
#include "som_hand_b.h"

/* D0D9F6 publish_shop_item_eligible_hero_markers   [class B, 71 bytes, 31 instructions]
 * Source: src/rom/publish_shop_item_eligible_hero_markers.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: B.
 */
static void publish_shop_item_eligible_hero_markers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->mf = 1; /* SEP #$30 */
    r->xf = 1;
    r->x &= 0xFF;
    r->y &= 0xFF;
    hand_cmp16(r, r->x, 6);
    if (r->x < 6) RETURN_RTS(c); /* heroes 0..5 have no marker row */
    JSL_CHK(c, 0xD9FF, 0xC07A02); /* read_native_item_usability_and_category_bits */
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    i_pha(c);
    r->mf = 1; /* SEP #$20 */
    r->c = 1;
    hand_lda8(r, hand_sbc8(r, RAM8(0x181C), 2));
    r->a = (uint16_t)((r->a << 8) | (r->a >> 8)); /* XBA */
    r->c = 1;
    r->a = (r->a & 0xFF00) | hand_sbc8(r, RAM8(0x181A), 0x0C);
    r->mf = 0; /* REP #$20 */
    RAM16_SET(0x1820, r->a);
    r->y = 0x082C;
    r->x = 0xE000;
    r->a = RAM16(r->sp + 1);
    r->z = (r->a & 0x0040) == 0;
    JSR_CHK(c, 0xDA24, 0xD0DA3D); /* place_one_eligible_active_hero_shop_marker */
    r->x = 0xE200;
    r->a = RAM16(r->sp + 1);
    r->z = (r->a & 0x0020) == 0;
    JSR_CHK(c, 0xDA2F, 0xD0DA3D);
    r->x = 0xE400;
    r->a = RAM16(r->sp + 1);
    r->z = (r->a & 0x0010) == 0;
    JSR_CHK(c, 0xDA3A, 0xD0DA3D);
    i_pla(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D9F6, SOM_RTS, "hand", publish_shop_item_eligible_hero_markers, 0, L_B, 2, 0, 0, 71, 31)

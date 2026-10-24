#include "som_c.h"
#include "som_hand_b.h"

/* C1FDE4 publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites   [class B, 116 bytes, 55 instructions]
 * Source: src/rom/publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites.s
 * Documented in docs/ui-native-ui-frame-projection.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 * Hand written: A, X, Y and the flags are carried exactly because the two callees read them. */

static void load16(Cpu *r, uint16_t v) { r->a = v; hand_nz16(r, v); }

/* The ROM assembles the code after each call for 16-bit A and index registers; a callee that returns in another
 * width is outside the contract. */
#define REQUIRE_WIDE(c) do { if ((c)->cpu.mf || (c)->cpu.xf) { (c)->fail = 3; return; } } while (0)

static void publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }

    r->mf = 0; r->xf = 0;                        /* REP #$30 */
    r->y = 0x0100;
    hand_nz16(r, r->y);
    load16(r, RAM16(0x00F1));
    if (!r->n) {
        load16(r, RAM16(0x008C));
        if (r->a == 0) {
            RAM16_SET(0x0010, 0);
            RAM16_SET(0x0012, 0);
            RAM16_SET(0x0A10, 0);
            RAM16_SET(0x0A12, 0);
            r->x = RAM16(0x0012);
            hand_nz16(r, r->x);
            do {
                r->mf = 0;                       /* REP #$20 */
                load16(r, BUS16(c, 0x01FEE2 + r->x));   /* screen-offset table in ROM */
                r->x = r->a;
                load16(r, BUS16(c, 0x010000 + r->x));
                RAM16_SET(0x0000, r->a);
                r->c = 1;                        /* SEC, SBC $F6 */
                uint16_t d = hand_sbc16(r, r->a, RAM16(0x00F6));
                r->a = d;
                if (!r->c) {                     /* negative: wrap into the 512 pixel ring */
                    hand_cmp16(r, r->a, 0xFE00);
                    if (!r->c) r->a = hand_adc16(r, r->a, 0x0400);
                } else {
                    hand_cmp16(r, r->a, 0x0200);
                    if (r->c) r->a = hand_sbc16(r, r->a, 0x0400);
                }
                hand_cmp16(r, r->a, 0x0080);
                bool publish = r->c == 0;        /* BCC: |x| < $80 */
                if (!publish) {
                    hand_cmp16(r, r->a, 0xFF80);
                    publish = r->c != 0;         /* BCC skips the call: publish when x >= $FF80 */
                }
                if (publish) {
                    { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xFE2D, 0xC1FE58); GUARD_JSR_DB(c, sp_call, 0xFE2D, db_call); } /* publish_clipped_ui_angular_icon_tiles_and_high_x_bits */
                    REQUIRE_WIDE(c);
                }
                r->x = RAM16(0x0012);
                r->x = (uint16_t)(r->x + 2);
                RAM16_SET(0x0012, r->x);
                hand_cmp16(r, r->x, 0x0010);
            } while (!r->c);
            { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSL(c, 0xFE3C, 0xC2B10A); GUARD_JSL_DB(c, sp_call, 0xFE3C, db_call); }        /* project_ui_focus_marker_and_trigger_real_map_transition */
        }
    }

    /* hide every sprite slot from Y on: the remaining OAM entries get X=$FF, Y=$E0.  The index width is whatever the
     * last callee left; the loop below only uses implied-mode index instructions, which wrap at that width. */
    const uint16_t imask = r->xf ? 0x00FF : 0xFFFF;
    r->mf = 0;
    r->a = r->y ^ 0xFFFF;                        /* TYA, EOR #$FFFF */
    r->c = 1;
    r->a = hand_adc16(r, r->a, 0x0150);
    r->c = (r->a >> 1) & 1;                      /* LSR, LSR */
    r->a >>= 2;
    r->x = r->a & imask;                         /* TAX */
    do {
        load16(r, 0xE0FF);
        BUS16_SET(c, 0x000800 + r->y, 0xE0FF);
        r->y = (uint16_t)(r->y + 4) & imask;
        r->x = (uint16_t)(r->x - 1) & imask;
        r->z = r->x == 0;
        r->n = (r->x & (imask == 0xFF ? 0x80 : 0x8000)) != 0;
    } while (r->x != 0);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1FDE4, SOM_RTL, "hand", publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 116, 55)

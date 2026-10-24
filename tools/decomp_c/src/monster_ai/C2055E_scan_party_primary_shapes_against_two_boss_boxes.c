#include "som_c.h"

/* C2055E scan_party_primary_shapes_against_two_boss_boxes   [class B, 49 bytes, hand written]
 * docs/graphics.md.  Tests the party's primary collision shapes (index $24 = 0..2) against the two boss collision boxes.
 * Returns carry set at the first shape that touches the second box and overlaps the first box, carry clear when none does
 * or when the boxes cannot be prepared.
 *
 *   prepare_two_boss_collision_boxes_with_selected_second_shape   (carry = unavailable)
 *   for shape in 0..2:
 *     prepare_unmarked_active_party_primary_shape(Y = shape)        carry = skip
 *     test_boss_target_height_with_inverted_flag_pair(A = shape)   carry = skip
 *     exclude_and_mark_party_contact_inside_second_boss_box         carry = skip
 *     test_first_collision_box_overlap                              carry set = hit, return it
 *
 * Entry: any widths (the callees set them); D=$0200; $0287 = current boss object (reloaded into X before returning).
 */
static void scan_party_primary_shapes_against_two_boss_boxes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    a_ldx(r, rdx(c, 0x0287, 0x0288));
    JSR(c, 0x2562, 0xC206FE); /* prepare_two_boss_collision_boxes_with_selected_second_shape */
    if (!r->c) {
        wrm(c, 0x0224, 0x0225, 0); /* STZ $24 (accumulator width) */
        do {
            a_ldy(r, rdx(c, 0x0224, 0x0225));
            JSR(c, 0x256B, 0xC20855); /* prepare_unmarked_active_party_primary_shape */
            if (!r->c) {
                a_lda(r, rdm(c, 0x0224, 0x0225));
                JSR(c, 0x2572, 0xC206C5); /* test_boss_target_height_with_inverted_flag_pair */
                if (!r->c) {
                    JSR(c, 0x2577, 0xC2062D); /* exclude_and_mark_party_contact_inside_second_boss_box */
                    if (!r->c) {
                        JSR(c, 0x257C, 0xC205F8); /* test_first_collision_box_overlap */
                        if (r->c) { /* hit */
                            a_ldx(r, rdx(c, 0x0287, 0x0288));
                            RETURN_RTS(c);
                        }
                    }
                }
            }
            { const uint16_t shape = (uint16_t)(rdm(c, 0x0224, 0x0225) + 1); wrm(c, 0x0224, 0x0225, shape); /* INC $24 */
              zn(r, r->mf ? (shape & 0xFF) : shape, r->mf); }
            a_lda(r, rdm(c, 0x0224, 0x0225));
            a_cmp(r, 3); /* CMP #3: the source assembles a 16-bit immediate, so the callees leave M = 16 here */
        } while (!r->c); /* BCC: shape < 3 */
    }
    a_ldx(r, rdx(c, 0x0287, 0x0288));
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2055E, SOM_RTS, "hand", scan_party_primary_shapes_against_two_boss_boxes, 0, L_ALL, 16, 0, -1, 49, 21)

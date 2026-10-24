#include "som_c.h"

/* C1E4CC select_actor_target_and_distance_class   [class C, 337 bytes, 148 instructions]
 * Source: src/rom/select_actor_target_and_distance_class.s
 * Documented in docs/actor-action-target-selection.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: AXY.
 */
#define ABS(off) ((((uint32_t)r->db << 16) + (off)) & 0xFFFFFF)

/* LDA abs,idx in the current accumulator width; a hardware or open-bus address is outside the contract. */
static int load_indexed(SomCtx *c, uint16_t off, uint16_t index)
{
    return hand_lda_abs(c, (((uint32_t)c->cpu.db << 16) + off + index) & 0xFFFFFF);
}

/* One candidate slot: the default value goes to dp[slot]; when the slot is enabled, the larger of the two bytes at
 * pair+index replaces it.  Slots 1 and 2 are skipped when bit 7 of $5C is set. */
static void scan_slot(SomCtx *c, uint8_t initial, uint8_t slot, bool check_5c, uint16_t enable, uint16_t pair, uint16_t index)
{
    Cpu *r = &c->cpu;
    uint8_t value;
    a_lda(r, initial);
    dp_wr8(c, slot, r->a);
    if (check_5c) {
        a_bit(r, dp_rd8(c, 0x5C));
        if (r->n) return;
    }
    BUS8_OK(c, ABS(enable), value);
    a_lda(r, value);
    if (r->z || r->n) return;
    if (!load_indexed(c, pair, index)) return;
    BUS8_OK(c, (ABS(pair) + 1 + index) & 0xFFFFFF, value);
    a_cmp(r, value);
    if (!r->c) a_lda(r, value);
    dp_wr8(c, slot, r->a);
}

/* Compare the three slot values and load Y with the class of the slot the comparison picks. */
static void rank_slots(SomCtx *c, uint16_t y_slot0_largest, uint16_t y_slot2_largest, uint16_t y_slot1_largest)
{
    Cpu *r = &c->cpu;
    a_lda(r, dp_rd8(c, 0x00));
    a_cmp(r, dp_rd8(c, 0x01));
    if (!r->c) {
        a_cmp(r, dp_rd8(c, 0x02));
        a_ldy(r, r->c ? y_slot2_largest : y_slot1_largest);
    } else {
        a_lda(r, dp_rd8(c, 0x01));
        a_cmp(r, dp_rd8(c, 0x02));
        a_ldy(r, r->c ? y_slot2_largest : y_slot0_largest);
    }
}

static void select_actor_target_and_distance_class(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->c) {
        /* a record is named by its low status byte */
        if (!load_indexed(c, 0xE1AC, r->x)) return;
        i_rep(r, 0x20);
        i_xba(r);
        a_and(r, 0x0F00);
        i_asla(r);
        i_tay(r);
        a_cpx(r, 0x0600);
        if (!r->c) {
            a_cpx(r, 0x0000);
            if (r->z) { if (!load_indexed(c, 0xE050, r->y)) return; }
            else {
                a_cpx(r, 0x0200);
                if (r->z) { if (!load_indexed(c, 0xE053, r->y)) return; }
                else if (!load_indexed(c, 0xE056, r->y)) return;
            }
        } else {
            a_cpy(r, 0x0000);
            if (r->z) { if (!load_indexed(c, 0xE050, r->x)) return; }
            else {
                a_cpy(r, 0x0200);
                if (r->z) { if (!load_indexed(c, 0xE053, r->x)) return; }
                else if (!load_indexed(c, 0xE056, r->x)) return;
            }
        }
        i_sep(r, 0x20);
        dp_wr8(c, 0x00, r->a);
        i_xba(r);
        a_cmp(r, dp_rd8(c, 0x00));
        if (!r->c) i_xba(r);
    } else {
        a_cpx(r, 0x0600);
        if (!r->c) {
            a_ldy(r, 0x0050);
            a_cpx(r, 0x0000);
            if (!r->z) {
                a_ldy(r, 0x0053);
                a_cpx(r, 0x0200);
                if (!r->z) a_ldy(r, 0x0056);
            }
            scan_slot(c, 0xFD, 0x00, false, 0xE600, 0xE600, r->y);
            if (c->fail) return;
            scan_slot(c, 0xFE, 0x01, true, 0xE800, 0xE800, r->y);
            if (c->fail) return;
            scan_slot(c, 0xFF, 0x02, true, 0xEA00, 0xEA00, r->y);
            if (c->fail) return;
            rank_slots(c, 0x0800, 0x0A00, 0x0600);
        } else {
            scan_slot(c, 0xFD, 0x00, false, 0xE000, 0xE050, r->x);
            if (c->fail) return;
            scan_slot(c, 0xFE, 0x01, true, 0xE200, 0xE253, r->x);
            if (c->fail) return;
            scan_slot(c, 0xFF, 0x02, true, 0xE400, 0xE456, r->x);
            if (c->fail) return;
            rank_slots(c, 0x0200, 0x0400, 0x0000);
        }
    }
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    a_cmp(r, 0x04);
    if (r->c) a_lda(r, 0x03);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E4CC, SOM_RTS, "hand", select_actor_target_and_distance_class, 0, L_A | L_X | L_Y, 1, 1, 0, 337, 148)

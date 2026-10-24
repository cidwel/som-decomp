#include "som_c.h"
#include "som_hand_d.h"

/* 7EA8D6 enqueue_task_by_priority   [class B, 55 bytes, hand written]
 * Native boot scheduler (code at 7E:A8D6).  X = task record in the data bank.  Inserts the task into the singly linked
 * ready queue whose head cell is at $00A0 (a cell holds the next record pointer; the priority byte of a record is at +3):
 * the task goes after the last queued task whose priority is not greater (CMP, BCS).
 *
 * The routine keeps its scratch word in the stack slot where it pushed X: PHD, PHP, PHX, TSC, TCD makes the direct page
 * point at that slot, so $01 is the pushed X and is overwritten by the walk.  The exit restores the registers from the
 * stack bytes (PLA, PLA discard the second copy of X, then PLP, PLD).
 * Entry: any M, X; D arbitrary; the routine sets M=8 for the priority compare.
 */
/* abs,X in the data bank: a 24-bit sum, no wrap inside the bank */
#define ABSX(off) ((((uint32_t)r->db << 16) + (off) + r->x) & 0xFFFFFF)

static void enqueue_task_by_priority(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_phx(c);
    i_tsc(r);
    i_tcd(r); /* D = S: $01 is the pushed X */
    i_sep(r, 0x20);
    if (!hand_lda_abs(c, ABSX(0x0003))) return; /* priority of the new task */
    i_phx(c);
    a_ldx(r, 0x00A0); /* queue head cell */
    do {
        dp_wr16(c, 0x01, r->x); /* the cell being examined */
        a_ldy(r, BUS16(c, ABSX(0x0000))); /* next task */
        if (c->fail) return;
        if (r->z) break;
        i_tyx(r);
        a_cmp(r, BUS8(c, ABSX(0x0003)));
        if (c->fail) return;
    } while (r->c); /* stop before the first task with a higher priority number */
    i_rep(r, 0x20);
    a_ldx(r, dp_rd16(c, 0x01));
    if (!hand_lda_abs(c, ABSX(0x0000))) return;
    dp_wr16(c, 0x01, r->a); /* the old link */
    i_pla(c); /* the new task */
    hand_sta_abs(c, ABSX(0x0000)); /* cell -> task */
    i_tax(r);
    a_lda(r, dp_rd16(c, 0x01));
    hand_sta_abs(c, ABSX(0x0000)); /* task -> old link */
    i_sep(r, 0x20);
    i_pla(c);
    i_pla(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA8D6, SOM_RTS, "hand", enqueue_task_by_priority, 0, L_ALL, 8, -1, -1, 55, 27)

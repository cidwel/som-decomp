#include "som_c.h"
#include "som_hand_b.h"

/* C1EC1A event_wait_for_ticks_or_selected_controller   [class B, 44 bytes, 23 instructions]
 * Source: src/rom/event_wait_for_ticks_or_selected_controller.s
 * Documented in docs/event-vm-wait-flag-decrement.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_wait_for_ticks_or_selected_controller(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;

    uint8_t ticks = dp_rd8(c, 0x05);
    hand_lda8(r, ticks);
    if (ticks != 0) {
        dp_wr8(c, 0x4F, ticks);                  /* remaining ticks */
        hand_lda8(r, 0x82);
        dp_wr8(c, 0xD0, 0x82);                   /* wait state: ticks */
    } else {
        hand_lda8(r, 0x83);
        dp_wr8(c, 0xD0, 0x83);                   /* wait state: controller */
        r->xf = 0;                               /* REP #$10 */
        r->x = dp_rd16(c, 0xD4);
        uint8_t slot = RAM8(0xE02C + r->x);
        hand_lda8(r, slot);
        slot = (uint8_t)(slot - 1);
        hand_lda8(r, slot);                      /* DEC */
        hand_cmp8(r, slot, 3);
        if (slot == 3) hand_lda8(r, 2);
        r->mf = 1;                               /* SEP #$20 */
        r->x = r->a;                             /* TAX copies all sixteen bits of the accumulator */
        hand_lda8(r, 0);
        som_wr(c, (uint16_t)(c->cpu.dp + 0xCC + r->x), 0);   /* STA $CC,X: bank 0, wraps at 16 bits */
    }
    r->mf = 0;                                   /* REP #$20 */
    dp_wr16(c, 0xD1, (uint16_t)(dp_rd16(c, 0xD1) + 1));
    uint16_t cursor = (uint16_t)(dp_rd16(c, 0xD1) + 1);
    dp_wr16(c, 0xD1, cursor);
    hand_nz16(r, cursor);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EC1A, SOM_RTS, "hand", event_wait_for_ticks_or_selected_controller, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 44, 23)

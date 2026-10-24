#include "som_c.h"
#include "som_hand_b.h"

/* C23622 invoke_descriptor_hurt_callback   [class C, 11 bytes, hand written]
 * Calls the hurt callback of descriptor X (word at $00BA,X in the data bank) unless it is zero: the value goes to
 * D+$0C and the routine jumps through the absolute bank-0 pointer $020C (the same bytes only while D = $0200).
 * Entry: any direct page, data bank and widths (the M flag sets the size of the value).  The target's RTS returns to
 * the caller.
 */
static void invoke_descriptor_hurt_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_lda_abs(c, ((uint32_t)r->db << 16) + 0x00BA + r->x)) return;          /* LDA $00BA,X */
    if (r->z) RETURN_RTS(c);                                                         /* BEQ */
    hand_sta_dp(c, 0x0C);                                                            /* STA $0C */
    TAIL_CALL(c, 0xC20000 | bus16_dp(c, 0x020C), SOM_RTS);                           /* JMP ($020C) */
}
SOM_REGISTER(0xC23622, SOM_RTS, "hand", invoke_descriptor_hurt_callback, 0, L_ALL, 0, -1, -1, 11, 5)

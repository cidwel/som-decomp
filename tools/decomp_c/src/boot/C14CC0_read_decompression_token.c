#include "som_c.h"
#include "som_hand_d.h"

/* C14CC0 read_decompression_token   [class C, 37 bytes, hand written]
 * Reads one token of the block decompressor (decompress_block, C14C30).  X = source offset in data bank DB, Y = output
 * offset, $05 = output limit, $07 = length mask, $03 receives the copy distance.
 *
 *   token = DB:X++ ;  if Y >= limit: drop the decompressor's frame (3 PLA) and return to ITS caller (end of block);
 *   if token bit 7 is clear: a literal, return with A = token;
 *   otherwise A.high = (token & $7F) & mask, A.low = DB:X++ , $03 = ((A.high << 8) | A.low) + 1  (copy distance),
 *   A.low = token & $7F, Z cleared.
 * Entry: M=8 bit, X=16 bit.  Called with JSL.  The end-of-block path unwinds the caller, so it is only executed in the
 * full decompressor (the entry/exit harness cannot observe it).
 */
static void read_decompression_token(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
L_C14CC0:;
    LDA(c, ABX, 0x0);
    i_inx(r);
    CPY(c, DP, 0x5);
    if (r->c) goto L_C14CE1;
    a_biti(r, 0x80);
    if (r->z) goto L_C14CE0;
    a_and(r, 0x7f);
    i_pha(c);
    AND(c, DP, 0x7);
    i_xba(r);
    LDA(c, ABX, 0x0);
    i_inx(r);
    i_rep(r, 0x20);
    i_inca(r);
    STA(c, DP, 0x3);
    i_sep(r, 0x20);
    i_pla(c);
    i_rep(r, 0x2);
L_C14CE0:;
    RETURN_RTL(c);
L_C14CE1:;
    i_pla(c);
    i_pla(c);
    i_pla(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC14CC0, SOM_RTL, "hand", read_decompression_token, SOM_UNWINDS, L_ALL, 4, 1, 0, 37, 20)

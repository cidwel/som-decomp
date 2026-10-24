#include "som_c.h"
#include "som_hand_b.h"

/* C22459 boss_loader_call_native_callback   [class C, 11 bytes, hand written]
 * LDA [$30] ; INC $30 twice (advances the script cursor) ; STA $33 ; JMP ($0233).
 * Entry: any direct page, data bank and widths.  The cursor and the stored word use the direct page, the jump pointer
 * is the absolute bank-0 word at $0233 (the same bytes only while D = $0200).  The accumulator width (M flag) decides
 * whether the cursor is bumped by one byte twice or by a word twice.  Ends in `jmp (abs)`: the routine tail-calls the
 * pointer, whose RTS returns to the caller.
 */
static void boss_loader_call_native_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const uint32_t ptr = dp_rd16(c, 0x30) | ((uint32_t)dp_rd8(c, 0x32) << 16);
    if (!hand_rd_ok(ptr & 0xFFFFFF) || (!r->mf && !hand_rd_ok((ptr + 1) & 0xFFFFFF))) { c->fail = 3; return; }
    a_lda(r, r->mf ? BUS8(c, ptr & 0xFFFFFF) : BUS16(c, ptr & 0xFFFFFF));          /* LDA [$30] */
    for (int i = 0; i < 2; i++) {                                                    /* INC $30, INC $30 */
        if (r->mf) { uint8_t v = (uint8_t)(dp_rd8(c, 0x30) + 1); dp_wr8(c, 0x30, v); hand_nz8(r, v); }
        else { uint16_t v = (uint16_t)(dp_rd16(c, 0x30) + 1); dp_wr16(c, 0x30, v); hand_nz16(r, v); }
    }
    if (r->mf) dp_wr8(c, 0x33, (uint8_t)r->a); else dp_wr16(c, 0x33, r->a);         /* STA $33 */
    TAIL_CALL(c, 0xC20000 | bus16_dp(c, 0x0233), SOM_RTS);                           /* JMP ($0233) */
}
SOM_REGISTER(0xC22459, SOM_RTS, "hand", boss_loader_call_native_callback, 0, L_ALL, 0, -1, -1, 11, 5)

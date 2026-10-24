#include "som_c.h"
#include "som_hand_b.h"

/* 7EBEDD replace_colour_graphics_workspace   [class B, 51 bytes, 29 instructions]
 * Source: src/boot/replace_colour_graphics_workspace.s
 * Documented in docs/boot.md
 * Entry: any widths, any data bank and direct page (all three are saved on the stack and restored).
 * Hand written: the stack frame is built byte by byte (PHD, PHP, PHX, PHB, PHA) because the callees run with D
 * pointing into it and the exit state is pulled back from those bytes.
 *
 *   sp0      D high        sp0-1  D low        sp0-2  P
 *   sp0-3    X high (counter high)            sp0-4  X low (counter low)
 *   sp0-5    DB                                sp0-6 $7F, popped into DB
 */
static void replace_colour_graphics_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    const uint16_t sp0 = r->sp;

    RAM8(sp0) = r->dp >> 8;                      /* PHD */
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = hand_p_byte(r);              /* PHP */
    r->mf = 0; r->xf = 0;                        /* REP #$30 */
    RAM8(sp0 - 3) = r->x >> 8;                   /* PHX */
    RAM8(sp0 - 4) = (uint8_t)r->x;
    r->dp = (uint16_t)(sp0 - 5);                 /* TSC, TCD */
    RAM8(sp0 - 5) = r->db;                       /* SEP #$20, PHB */
    r->db = 0x7F;                                /* LDA #$7F, PHA, PLB */
    dp_wr16(c, 0x01, r->x);                      /* REP #$20, STX $01: the loop counter */

    r->a = 0x0043; r->z = 0; r->n = 0;           /* LDA #$0043 */
    { const uint16_t sp_call = r->sp - 6; const uint8_t db_call = r->db; r->sp -= 6; JSR(c, 0xBEF4, 0x7E81AA); r->sp += 6; GUARD_JSR_DB(c, sp_call, 0xBEF4, db_call); }   /* release_graphics_buffer */
    HAND_REQUIRE_WIDE(c);
    r->a = 0x0043; r->z = 0; r->n = 0;
    r->x = 0x0300;
    { const uint16_t sp_call = r->sp - 6; const uint8_t db_call = r->db; r->sp -= 6; JSR(c, 0xBEFD, 0x7E809B); r->sp += 6; GUARD_JSR_DB(c, sp_call, 0xBEFD, db_call); }   /* create_graphics_buffer */
    for (;;) {
        HAND_REQUIRE_WIDE(c);                    /* LDA #$0043 is a 16-bit immediate */
        r->a = 0x0043; r->z = 0; r->n = 0;
        { const uint16_t sp_call = r->sp - 6; const uint8_t db_call = r->db; r->sp -= 6; JSR(c, 0xBF03, 0x7E81D6); r->sp += 6; GUARD_JSR_DB(c, sp_call, 0xBF03, db_call); }   /* allocate_graphics_workspace_block */
        if (r->mf) {                             /* DEC $01 follows the width the callee left */
            uint8_t v = (uint8_t)(dp_rd8(c, 0x01) - 1);
            dp_wr8(c, 0x01, v);
            hand_nz8(r, v);
        } else {
            uint16_t v = (uint16_t)(dp_rd16(c, 0x01) - 1);
            dp_wr16(c, 0x01, v);
            hand_nz16(r, v);
        }
        if (r->z) break;                         /* BNE */
    }

    r->db = RAM8(sp0 - 5);                       /* PLB */
    hand_nz8(r, r->db);
    r->mf = 1;                                   /* SEP #$20 */
    { uint8_t v = RAM8(sp0 - 4); r->a = (r->a & 0xFF00) | v; hand_nz8(r, v); }   /* PLA */
    { uint8_t v = RAM8(sp0 - 3); r->a = (r->a & 0xFF00) | v; hand_nz8(r, v); }   /* PLA */
    som_pull_p(c, sp0 - 2);                      /* PLP */
    r->dp = (uint16_t)(RAM8(sp0 - 1) | (RAM8(sp0) << 8));   /* PLD */
    hand_nz16(r, r->dp);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EBEDD, SOM_RTS, "hand", replace_colour_graphics_workspace, 0, L_B | L_Y | L_C | L_V, 7, 1, 0, 51, 29)

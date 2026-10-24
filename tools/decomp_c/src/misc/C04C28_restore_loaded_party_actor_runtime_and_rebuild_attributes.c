#include "som_c.h"
#include "som_hand_b.h"

/* C04C28 restore_loaded_party_actor_runtime_and_rebuild_attributes   [class B, 144 bytes, 59 instructions]
 * Source: src/rom/restore_loaded_party_actor_runtime_and_rebuild_attributes.s
 * Documented in docs/ui-native-loaded-game-save-apply.md
 * Entry: M=any X=16 bit, any DB and D.  Callers read: BV.
 *
 * Literal translation: the direct-page scratch words $B2/$B4 and the data-bank absolute accesses use the live D and DB;
 * the accumulator width of the status loop follows what the attribute rebuild leaves in M.
 */

/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSR
#undef I_JSL
#undef HAND_ROUTINE_RET
#define HAND_ROUTINE_RET SOM_RTL
#define I_JSR(c, retpc, target) HAND_JSR_RESUME(c, retpc, target, sp0)
#define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)

#define ABS_ADDR(off, idx) ((((uint32_t)r->db << 16) + (off) + (idx)) & 0xFFFFFF)

static void restore_loaded_party_actor_runtime_and_rebuild_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHB, PHP */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = r->db;
    RAM8((uint16_t)(sp0 - 3)) = hand_p_byte(r);
    r->sp = (uint16_t)(sp0 - 4);
    JSR(c, 0x4C2D, 0xC04518);            /* prepare_actor_appearance_context */
    if (r->xf) { c->fail = 3; return; }  /* LDX #$0000 is assembled for 16-bit index registers */
    r->mf = 0;                           /* REP #$20 */
    r->x = 0; r->z = 1; r->n = 0;        /* LDX #$0000 */
    dp_wr16(c, 0xB4, 0);                 /* STX $B4 */
    r->a = 3; r->z = 0; r->n = 0;
    dp_wr16(c, 0xB2, 3);                 /* STA $B2 */
    do {
        r->a = 0; r->z = 1; r->n = 0;    /* LDA #$0000 */
        BUS16_SET(c, ABS_ADDR(0xE1F1, r->x), 0);
        BUS16_SET(c, ABS_ADDR(0xE1F3, r->x), 0);
        BUS16_SET(c, ABS_ADDR(0xE1F5, r->x), 0);
        BUS16_SET(c, ABS_ADDR(0xCC78, r->x), 0);
        r->mf = 1;                       /* SEP #$20 */
        BUS8_SET(c, ABS_ADDR(0xE1E5, r->x), 0);
        BUS8_SET(c, ABS_ADDR(0xE19D, r->x), 0);
        BUS8_SET(c, ABS_ADDR(0xE175, r->x), 0);
        r->a = (r->a & 0xFF00) | 0xFF; r->z = 0; r->n = 1;   /* LDA #$FF */
        BUS8_SET(c, ABS_ADDR(0xE1E5, r->x), 0xFF);
        BUS8_SET(c, ABS_ADDR(0xE1F0, r->x), 0xFF);
        r->mf = 0;                       /* REP #$20 */
        for (int i = 0; i < 2; i++) {    /* INC $B5 twice (16-bit) */
            uint16_t v = (uint16_t)(dp_rd16(c, 0xB5) + 1);
            dp_wr16(c, 0xB5, v);
            hand_nz16(r, v);
        }
        a_ldx(r, dp_rd16(c, 0xB4));      /* LDX $B4 */
        {
            uint16_t v = (uint16_t)(dp_rd16(c, 0xB2) - 1);
            dp_wr16(c, 0xB2, v);         /* DEC $B2 */
            hand_nz16(r, v);
        }
    } while (!r->z);

    r->mf = 1;                           /* SEP #$20 */
    {
        uint8_t b;
        BUS8_OK(c, ABS_ADDR(0x00EE, 0), b);
        a_lda(r, b); BUS8_SET(c, ABS_ADDR(0xCC6D, 0), b);
        BUS8_OK(c, ABS_ADDR(0x00EF, 0), b);
        a_lda(r, b); BUS8_SET(c, ABS_ADDR(0xCC6E, 0), b);
        BUS8_OK(c, ABS_ADDR(0x00F0, 0), b);
        a_lda(r, b); BUS8_SET(c, ABS_ADDR(0xCC6F, 0), b);
    }
    r->x = 0; r->z = 1; r->n = 0;        /* LDX #$0000 */
    JSL(c, 0x4C82, 0xC04530);            /* rebuild_actor_attributes_native */
    if (r->xf) { c->fail = 3; return; }
    r->x = 0x0200; r->z = 0; r->n = 0;
    JSL(c, 0x4C89, 0xC04530);
    if (r->xf) { c->fail = 3; return; }
    r->x = 0x0400; r->z = 0; r->n = 0;
    JSL(c, 0x4C90, 0xC04530);
    if (r->xf) { c->fail = 3; return; }
    r->x = 0; r->z = 1; r->n = 0;        /* LDX #$0000 */
    dp_wr16(c, 0xB4, 0);                 /* STX $B4 */
    r->y = 3; r->z = 0; r->n = 0;        /* LDY #$0003 */
    do {
        if (!hand_lda_abs(c, ABS_ADDR(0xE191, r->x))) return;
        if (r->n) {
            if (!r->mf) { c->fail = 3; return; }     /* LDA #$2F and ORA #$08 are assembled for 8-bit A */
            a_lda(r, 0x2F);
            BUS8_SET(c, ABS_ADDR(0xE1E5, r->x), 0x2F);
            uint8_t g;
            BUS8_OK(c, ABS_ADDR(0xE1B1, r->x), g);
            a_lda(r, g);
            a_ora(r, 0x08);
            BUS8_SET(c, ABS_ADDR(0xE1B1, r->x), r->a & 0xFF);
        }
        for (int i = 0; i < 2; i++) {    /* INC $B5 twice, in the accumulator width */
            if (r->mf) { uint8_t v = (uint8_t)(dp_rd8(c, 0xB5) + 1); dp_wr8(c, 0xB5, v); hand_nz8(r, v); }
            else { uint16_t v = (uint16_t)(dp_rd16(c, 0xB5) + 1); dp_wr16(c, 0xB5, v); hand_nz16(r, v); }
        }
        a_ldx(r, dp_rd16(c, 0xB4));      /* LDX $B4 */
        r->y = (uint16_t)(r->y - 1); hand_nz16(r, r->y);   /* DEY */
    } while (!r->z);

    /* PLP, PLB, PLD, RTL */
    r->sp = (uint16_t)(sp0 - 3);
    som_pull_p(c, (uint16_t)(sp0 - 3));
    r->db = RAM8((uint16_t)(sp0 - 2));
    hand_nz8(r, r->db);
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    hand_nz16(r, r->dp);
    r->sp = sp0;
    RETURN_RTL(c);
}
#undef ABS_ADDR
SOM_REGISTER(0xC04C28, SOM_RTL, "hand", restore_loaded_party_actor_runtime_and_rebuild_attributes, 0, L_B | L_V, 4, -1, -1, 144, 59)

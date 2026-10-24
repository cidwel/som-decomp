#include "som_c.h"
#include "som_hand_b.h"

/* C04530 rebuild_actor_attributes_native   [class C, 74 bytes, 32 instructions]
 * Source: src/rom/rebuild_actor_attributes_native.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 * Hand written: the register widths after each call are the callee's, and the exit pulls P, DB and D from the stack
 * bytes pushed at entry (the subroutines run with the caller's direct page and may rewrite them).  The prologue pushes
 * stay implicit in r->sp (entry value); each call is made four bytes lower. */

static void rebuild_actor_attributes_native(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHB, PHP */
    RAM8(sp0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = r->db;
    RAM8(sp0 - 3) = (r->n << 7) | (r->v << 6) | 0x20 | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;

    { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4535, 0xC04518); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4535, db_call); }                  /* prepare_actor_appearance_context */
    { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4538, 0xC047DD); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4538, db_call); }                  /* classify_actor_appearance_from_sprite */
    if (!r->mf) { c->fail = 3; return; }         /* the immediate operands below are assembled for 8-bit A */
    uint8_t kind = RAM8(ACTOR_KIND_FLAGS + r->x);
    hand_lda8(r, kind);

    if (!(kind & 0x20)) {                        /* BIT #$20, BEQ */
        if (!(kind & 0x80)) {                    /* not a hero: the generic refresh body finishes and returns */
            r->z = kind == 0;
            TAIL_CALL_FRAME(c, 0xC04597, SOM_RTL, 4); /* refresh_actor_appearance_attributes_body */
        }
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x454D, 0xC0464F); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x454D, db_call); }              /* load_hero_level_attributes_and_controller_adjustments */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4550, 0xC04860); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4550, db_call); }              /* prepare_actor_appearance_table_pointers */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4553, 0xC048E6); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4553, db_call); }              /* read_appearance_level_and_party_charge */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4556, 0xC04B7D); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4556, db_call); }              /* apply_three_armor_attribute_flags */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4559, 0xC04AFF); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4559, db_call); }              /* apply_packed_appearance_attribute_adjustments */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x455C, 0xC04BBE); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x455C, db_call); }              /* reduce_and_clamp_actor_appearance_attributes */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x455F, 0xC049AA); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x455F, db_call); }              /* derive_actor_appearance_palette_attributes */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4562, 0xC04A0C); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4562, db_call); }              /* derive_hero_weapon_level_accuracy */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4565, 0xC04A2D); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4565, db_call); }              /* combine_hero_armor_element_resistance */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x4568, 0xC04A75); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x4568, db_call); }              /* derive_hero_armor_defenses_and_immunity */
        { const uint16_t sp_call = r->sp - 4; const uint8_t db_call = r->db; r->sp -= 4; JSR(c, 0x456B, 0xC04BF9); r->sp += 4; GUARD_JSR_DB(c, sp_call, 0x456B, db_call); }              /* cap_actor_appearance_word_and_byte_attributes */

        /* PHY, LDY #$100B, LDA [$C0],Y, PLY, STA $E1F7,X: the weapon status chance comes from the actor record */
        if (r->xf) { c->fail = 3; return; }
        RAM16_SET(sp0 - 5, r->y);
        uint32_t record = (RAM8((uint16_t)(r->dp + 0xC2)) << 16) | RAM16((uint16_t)(r->dp + 0xC0));
        if (r->mf) {
            uint8_t chance = BUS8(c, record + 0x100B);
            hand_lda8(r, chance);
            RAM8(ACTOR_WEAPON_STATUS_CHANCE + r->x) = chance;
        } else {
            uint16_t chance = BUS16(c, record + 0x100B);
            r->a = chance;
            hand_nz16(r, chance);
            RAM16_SET(ACTOR_WEAPON_STATUS_CHANCE + r->x, chance);
        }
    }

    /* restore_actor_appearance_context_long: PLP, PLB, PLD, RTL */
    som_pull_p(c, sp0 - 3);
    r->db = RAM8(sp0 - 2);
    r->dp = (RAM8(sp0) << 8) | RAM8(sp0 - 1);
    hand_nz16(r, r->dp);                         /* PLD sets N and Z from the pulled word */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC04530, SOM_RTL, "hand", rebuild_actor_attributes_native, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 74, 32)

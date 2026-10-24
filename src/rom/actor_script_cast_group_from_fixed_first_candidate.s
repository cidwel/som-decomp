; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_script_call_native_cast_preserving_context = $1E16
actor_script_compare_mp_to_spell_argument_cost = $1E2C
advance_actor_script_and_yield = $0111
reject_ineligible_or_nonmonster_actor = $058B
test_actor_target_eligibility = $054A
write_actor_facing_fallback_command = $2534

.segment "CODE"
.org $1E98
actor_script_cast_group_from_fixed_first_candidate:
    jsr actor_script_compare_mp_to_spell_argument_cost
    bcs actor_script_cast_group_from_fixed_first_candidate_c11eae
    lda a:$0060,Y
    .a8
    cmp #$E0
    beq actor_script_cast_group_from_fixed_first_candidate_c11eab
    lda a:$0190,Y
    .a8
    and #$80
    beq actor_script_cast_group_from_fixed_first_candidate_c11eae
actor_script_cast_group_from_fixed_first_candidate_c11eab:
    jmp actor_script_cast_group_from_fixed_first_candidate_c11f2f
actor_script_cast_group_from_fixed_first_candidate_c11eae:
    tyx
    stz a:$0176,X
    stz a:$0177,X
    stz a:$0178,X
    stz a:$0179,X
    stz a:$017A,X
    .i16
    ldx #$E000
    phy
    .a8
    lda #$03
    pha
    cmp a:$01AD,Y
    beq actor_script_cast_group_from_fixed_first_candidate_c11ecc
    bcs actor_script_cast_group_from_fixed_first_candidate_c11ee6
actor_script_cast_group_from_fixed_first_candidate_c11ecc:
    .i16
    ldx #$E600
actor_script_cast_group_from_fixed_first_candidate_c11ecf:
    jsr reject_ineligible_or_nonmonster_actor
    bcs actor_script_cast_group_from_fixed_first_candidate_c11edd
    .a8
    lda #$07
    sec
    sbc $01,S
    sta a:$0178,Y
    iny
actor_script_cast_group_from_fixed_first_candidate_c11edd:
    pla
    dec
    pha
    bne actor_script_cast_group_from_fixed_first_candidate_c11ecf
    pla
    ply
    bra actor_script_cast_group_from_fixed_first_candidate_c11efb
actor_script_cast_group_from_fixed_first_candidate_c11ee6:
    jsr test_actor_target_eligibility
    bne actor_script_cast_group_from_fixed_first_candidate_c11ef4
    .a8
    lda #$04
    sec
    sbc $01,S
    sta a:$0178,Y
    iny
actor_script_cast_group_from_fixed_first_candidate_c11ef4:
    pla
    dec
    pha
    bne actor_script_cast_group_from_fixed_first_candidate_c11ee6
    pla
    ply
actor_script_cast_group_from_fixed_first_candidate_c11efb:
    lda a:$0178,Y
    beq actor_script_cast_group_from_fixed_first_candidate_c11f2f
    tyx
    inc a:$0176,X
    lda a:$0179,Y
    beq actor_script_cast_group_from_fixed_first_candidate_c11f14
    inc a:$0176,X
    lda a:$017A,Y
    beq actor_script_cast_group_from_fixed_first_candidate_c11f14
    inc a:$0176,X
actor_script_cast_group_from_fixed_first_candidate_c11f14:
    .a8
    lda #$44
    sta a:$0140,Y
    ldx a:$0144,Y
    lda f:$D04F16,X
    sta a:$0141,Y
    lda f:$D04F17,X
    sta a:$0170,Y
    jsr actor_script_call_native_cast_preserving_context
    bra actor_script_cast_group_from_fixed_first_candidate_c11f32
actor_script_cast_group_from_fixed_first_candidate_c11f2f:
    jsr write_actor_facing_fallback_command
actor_script_cast_group_from_fixed_first_candidate_c11f32:
    .a8
    lda #$03
    jmp advance_actor_script_and_yield

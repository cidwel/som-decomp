; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-reflection.md.
.setcpu "65816"
.smart
.a8
.i16

restore_target_state_after_previous_cast = $81F2
spell_hit_or_reflection_public_jump = $C00054
transfer_cast_presentation_to_target = $87C2

.segment "CODE"
.org $8D12
deliver_complete_cast_hit_to_target:
    sep #$20
    bit $ED
    bmi deliver_complete_cast_hit_to_target_c18d1f
    .i16
    cpy #$0600
    bcc deliver_complete_cast_hit_to_target_c18d1f
deliver_complete_cast_hit_to_target_c18d1d:
    clc
    rts
deliver_complete_cast_hit_to_target_c18d1f:
    lda a:$E000,Y
    beq deliver_complete_cast_hit_to_target_c18d1d
    bmi deliver_complete_cast_hit_to_target_c18d1d
    rep #$20
    lda a:$E116,X
    phx
    phy
    jsl f:spell_hit_or_reflection_public_jump
    rep #$20
    .a16
    and #$00FF
    beq deliver_complete_cast_hit_to_target_c18d3f
    .a16
    cmp #$0080
    txa
    ply
    plx
    rts
deliver_complete_cast_hit_to_target_c18d3f:
    ply
    plx
    sep #$20
    .a8
    lda #$80
    sta a:$E108,Y
    lda a:$E170,X
    sta a:$E10A,Y
    lda a:$E110,X
    sta a:$E109,Y
    lda a:$E111,X
    sta a:$E10B,Y
    phx
    lda a:$E060,Y
    beq deliver_complete_cast_hit_to_target_c18d75
    .a8
    cmp #$40
    beq deliver_complete_cast_hit_to_target_c18d75
    .a8
    cmp #$C0
    bne deliver_complete_cast_hit_to_target_c18d6d
    jsr restore_target_state_after_previous_cast
    bra deliver_complete_cast_hit_to_target_c18d75
deliver_complete_cast_hit_to_target_c18d6d:
    rep #$20
    pla
    sta a:$E10C,Y
    clc
    rts
deliver_complete_cast_hit_to_target_c18d75:
    rep #$20
    pla
    sta a:$E10C,Y
    jsr transfer_cast_presentation_to_target
    clc
    rts

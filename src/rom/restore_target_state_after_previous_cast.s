; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-restore.md.
.setcpu "65816"
.smart
.a8
.i16

finish_previous_cast_public_jump = $C0001E
restore_target_effect_palettes_preserving_actor = $CA4F
unused_cast_completion_public_jump = $C00033

.segment "CODE"
.org $81F2
restore_target_state_after_previous_cast:
    phx
    phy
    tyx
    ldy a:$E10C,X
    lda a:$E118,X
    .a8
    cmp #$01
    bne restore_target_state_after_previous_cast_c18208
    lda a:$E121,X
    jsl f:unused_cast_completion_public_jump
    bra restore_target_state_after_previous_cast_c1820c
restore_target_state_after_previous_cast_c18208:
    jsl f:finish_previous_cast_public_jump
restore_target_state_after_previous_cast_c1820c:
    ply
    plx
    sep #$20
    jsr restore_target_effect_palettes_preserving_actor
    lda a:$E128,Y
    sta a:$E01C,Y
    lda a:$E129,Y
    sta a:$E05D,Y
    .a8
    lda #$FF
    sta a:$E008,Y
    rep #$20
    lda a:$E12E,Y
    sta a:$E104,Y
    lda a:$E124,Y
    sta a:$E106,Y
    lda a:$E134,Y
    sta a:$E006,Y
    lda a:$E122,Y
    sta a:$E008,Y
    lda a:$E12A,Y
    sta a:$E05E,Y
    rts

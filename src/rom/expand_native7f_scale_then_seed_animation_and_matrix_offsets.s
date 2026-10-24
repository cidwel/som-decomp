; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-entrance-chain.md.
.setcpu "65816"
.smart
.a8
.i16

derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8FB3
expand_native7f_scale_then_seed_animation_and_matrix_offsets:
    ldx $87
    lda a:$00B0,X
    clc
    .a16
    adc #$0020
    sta a:$00B0,X
    .a16
    cmp #$0800
    bcc expand_native7f_scale_then_seed_animation_and_matrix_offsets_c28fe8
    inc a:$0094,X
    stz a:$0000,X
    stz a:$0096,X
    stz a:$0090,X
    .a16
    lda #$0200
    sta a:$00B0,X
    .a16
    lda #$0111
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$000E
    sta a:$02D5
    .a16
    lda #$000A
    sta a:$02D7
expand_native7f_scale_then_seed_animation_and_matrix_offsets_c28fe8:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts

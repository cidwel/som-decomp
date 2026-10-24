; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-entrance-chain.md.
.setcpu "65816"
.smart
.a8
.i16

create_four_native7f_palette_transition_objects = $91F3
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
request_boss_sound_with_parameter_word = $30E3
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $924B
enter_native7f_phase_one_from_initial_phase_eight:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$003C
    bcc enter_native7f_phase_one_from_initial_phase_eight_c292a6
    .a16
    lda #$0108
    sta a:$002B,X
    .a16
    lda #$0160
    sta a:$0032,X
    stz a:$00B2,X
    stz a:$00B6,X
    .a16
    lda #$0114
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B0,X
    .a16
    lda #$0001
    sta a:$0094,X
    .a16
    lda #$3000
    sta a:$003A,X
    stz a:$003C,X
    .a16
    lda #$8000
    sta a:$003E,X
    stz a:$0040,X
    .a16
    lda #$8FED
    sta a:$0090,X
    .a16
    lda #$0030
    sta a:$02D5
    .a16
    lda #$0018
    sta a:$02D7
    jsr create_four_native7f_palette_transition_objects
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    .a16
    lda #$00D6
    jsr request_boss_sound_with_parameter_word
enter_native7f_phase_one_from_initial_phase_eight_c292a6:
    clc
    rts

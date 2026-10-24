; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-motion-collapse.md.
.setcpu "65816"
.smart
.a8
.i16

create_four_native7f_palette_transition_objects = $91F3
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
request_boss_sound_with_parameter_word = $30E3
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $964B
restart_native7f_after_twelve_ticks_with_real_palette_effects:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$000C
    bcc restart_native7f_after_twelve_ticks_with_real_palette_effects_c296a3
    .a16
    lda #$0001
    sta a:$0094,X
    stz a:$0096,X
    stz a:$00B0,X
    .a16
    lda #$0114
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0108
    sta a:$002B,X
    .a16
    lda #$0160
    sta a:$0032,X
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
    jsr create_four_native7f_palette_transition_objects
    .a16
    lda #$0030
    sta a:$02D5
    .a16
    lda #$0018
    sta a:$02D7
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    .a16
    lda #$00D6
    jsr request_boss_sound_with_parameter_word
restart_native7f_after_twelve_ticks_with_real_palette_effects_c296a3:
    clc
    rts

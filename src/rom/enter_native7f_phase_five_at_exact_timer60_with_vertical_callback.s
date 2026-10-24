; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-entrance-chain.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
request_boss_sound_with_parameter_word = $30E3
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $92F6
enter_native7f_phase_five_at_exact_timer60_with_vertical_callback:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$003C
    bne enter_native7f_phase_five_at_exact_timer60_with_vertical_callback_c2937c
    stz a:$0096,X
    .a16
    lda #$0005
    sta a:$0094,X
    .a16
    lda #$0001
    sta a:$0000,X
    stz a:$0096,X
    .a16
    lda #$0800
    sta a:$00B0,X
    stz a:$00B2,X
    .a16
    lda #$0113
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$003A,X
    stz a:$003C,X
    .a16
    lda #$C000
    sta a:$003E,X
    stz a:$0040,X
    .a16
    lda #$9158
    sta a:$0090,X
    .a16
    lda #$0030
    sta a:$02D5
    .a16
    lda #$0020
    sta a:$02D7
    .a16
    lda #$005D
    .i16
    ldx #$0062
    .i16
    ldy #$0004
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$005D
    .i16
    ldx #$0063
    .i16
    ldy #$0005
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$005D
    .i16
    ldx #$0064
    .i16
    ldy #$0006
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$005D
    .i16
    ldx #$0065
    .i16
    ldy #$0007
    jsr allocate_boss_palette_transition_object
    ldx $87
    .a16
    lda #$00D6
    jsr request_boss_sound_with_parameter_word
    ldx $87
enter_native7f_phase_five_at_exact_timer60_with_vertical_callback_c2937c:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts

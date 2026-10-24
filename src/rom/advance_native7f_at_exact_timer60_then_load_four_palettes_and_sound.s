; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-entrance-chain.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_colors_from_rom = $2700
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
request_boss_sound_with_parameter_word = $30E3
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $904E
advance_native7f_at_exact_timer60_then_load_four_palettes_and_sound:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$003C
    bne advance_native7f_at_exact_timer60_then_load_four_palettes_and_sound_c290a7
    stz a:$0096,X
    inc a:$0094,X
    stz a:$0096,X
    .a16
    lda #$0300
    sta a:$00B0,X
    .a16
    lda #$0116
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0018
    sta a:$02D5
    .a16
    lda #$0018
    sta a:$02D7
    .a16
    lda #$0062
    .i16
    ldx #$0004
    jsr copy_boss_palette_colors_from_rom
    .a16
    lda #$0063
    .i16
    ldx #$0005
    jsr copy_boss_palette_colors_from_rom
    .a16
    lda #$0064
    .i16
    ldx #$0006
    jsr copy_boss_palette_colors_from_rom
    .a16
    lda #$0065
    .i16
    ldx #$0007
    jsr copy_boss_palette_colors_from_rom
    ldx $87
    .a16
    lda #$00D6
    jsr request_boss_sound_with_parameter_word
    ldx $87
advance_native7f_at_exact_timer60_then_load_four_palettes_and_sound_c290a7:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts

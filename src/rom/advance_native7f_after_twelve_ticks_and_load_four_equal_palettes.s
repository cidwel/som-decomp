; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-entrance-chain.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_colors_from_rom = $2700
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $92A8
advance_native7f_after_twelve_ticks_and_load_four_equal_palettes:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$000C
    bcc advance_native7f_after_twelve_ticks_and_load_four_equal_palettes_c292f4
    stz a:$0096,X
    inc a:$0094,X
    .a16
    lda #$0200
    sta a:$00B0,X
    .a16
    lda #$0112
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$000C
    sta a:$02D5
    .a16
    lda #$0006
    sta a:$02D7
    .a16
    lda #$0066
    .i16
    ldx #$0004
    jsr copy_boss_palette_colors_from_rom
    .a16
    lda #$0066
    .i16
    ldx #$0005
    jsr copy_boss_palette_colors_from_rom
    .a16
    lda #$0066
    .i16
    ldx #$0006
    jsr copy_boss_palette_colors_from_rom
    .a16
    lda #$0066
    .i16
    ldx #$0007
    jsr copy_boss_palette_colors_from_rom
advance_native7f_after_twelve_ticks_and_load_four_equal_palettes_c292f4:
    clc
    rts

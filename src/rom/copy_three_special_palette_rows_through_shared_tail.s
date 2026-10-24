; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-music-palette-transition.md.
.setcpu "65816"
.smart
.a8
.i16

copy_fifteen_colors_from_hardware_multiplied_palette_index = $FD10

.segment "CODE"
.org $FCF7
copy_three_special_palette_rows_through_shared_tail:
    sep #$20
    rep #$10
    .a8
    lda #$80
    .i16
    ldy #$00A2
    jsr copy_fifteen_colors_from_hardware_multiplied_palette_index
    .a8
    lda #$81
    .i16
    ldy #$00C2
    jsr copy_fifteen_colors_from_hardware_multiplied_palette_index
    .a8
    lda #$82
    .i16
    ldy #$00E2

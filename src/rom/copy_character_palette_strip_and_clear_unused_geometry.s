; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FCA3
copy_character_palette_strip_and_clear_unused_geometry:
    rep #$20
    .a16
    lda #$0008
    sta $00
    ldy $1C
    lda a:$E083,X
    .a16
    and #$000F
    .a16
    cmp #$0004
    bcs copy_character_palette_strip_and_clear_unused_geometry_c1fce0
    .a16
    cmp #$0003
    beq copy_character_palette_strip_and_clear_unused_geometry_c1fcda
    .a16
    cmp #$0002
    beq copy_character_palette_strip_and_clear_unused_geometry_c1fccf
    .a16
    lda #$7F7F
    sta a:$E094,X
    sta a:$E098,X
    sta a:$E09C,X
    bra copy_character_palette_strip_and_clear_unused_geometry_c1fce0
copy_character_palette_strip_and_clear_unused_geometry_c1fccf:
    .a16
    lda #$7F7F
    sta a:$E098,X
    sta a:$E09C,X
    bra copy_character_palette_strip_and_clear_unused_geometry_c1fce0
copy_character_palette_strip_and_clear_unused_geometry_c1fcda:
    .a16
    lda #$7F7F
    sta a:$E09C,X
copy_character_palette_strip_and_clear_unused_geometry_c1fce0:
    lda a:$E090,X
    sta a:$E700,Y
    inx
    inx
    iny
    iny
    dec $00
    bne copy_character_palette_strip_and_clear_unused_geometry_c1fce0
    lda $1C
    clc
    .a16
    adc #$0010
    sta $1C
    rts

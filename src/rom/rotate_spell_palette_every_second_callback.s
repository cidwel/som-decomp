; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-palette-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9C93
rotate_spell_palette_every_second_callback:
    inc a:$00BA,X
    lda a:$00BA,X
    .a16
    bit #$0001
    bne rotate_spell_palette_every_second_callback_c29cb5
    lda a:$07FE
    sta $95
    .i16
    ldx #$001C
rotate_spell_palette_every_second_callback_c29ca6:
    lda a:$07E0,X
    sta a:$07E2,X
    dex
    dex
    bne rotate_spell_palette_every_second_callback_c29ca6
    lda $95
    sta a:$07E2
rotate_spell_palette_every_second_callback_c29cb5:
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-effects.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3C89
clear_terminal_bitmap_until_timer_eighty_four:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0054
    bcs clear_terminal_bitmap_until_timer_eighty_four_c23ca9
    phb
    sep #$20
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .i16
    ldx #$1FFE
clear_terminal_bitmap_until_timer_eighty_four_c23c9f:
    stz a:$6000,X
    dex
    dex
    bpl clear_terminal_bitmap_until_timer_eighty_four_c23c9f
    plb
    clc
    rts
clear_terminal_bitmap_until_timer_eighty_four_c23ca9:
    sec
    rts

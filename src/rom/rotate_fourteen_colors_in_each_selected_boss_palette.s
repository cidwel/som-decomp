; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-dependencies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0C89
rotate_fourteen_colors_in_each_selected_boss_palette:
    ldx $87
rotate_fourteen_colors_in_each_selected_boss_palette_c20c8b:
    lda a:$0018,X
    .a16
    and #$00FF
    beq rotate_fourteen_colors_in_each_selected_boss_palette_c20cdd
    phx
    xba
    lsr
    lsr
    lsr
    sta $1A
    clc
    .a16
    adc #$001E
    .a16
    adc #$0600
    sta $0C
    lda $1A
    clc
    .a16
    adc #$0004
    .a16
    adc #$0600
    sta $0F
    lda ($0C)
    sta $95
    lda $1A
    clc
    .a16
    adc #$001C
    tax
    lda $1A
    clc
    .a16
    adc #$001E
    tay
    lda $1A
    clc
    .a16
    adc #$0004
    sta $1A
rotate_fourteen_colors_in_each_selected_boss_palette_c20cc8:
    lda a:$0600,X
    sta a:$0600,Y
    txy
    dex
    dex
    cpy $1A
    bne rotate_fourteen_colors_in_each_selected_boss_palette_c20cc8
    lda $95
    sta ($0F)
    plx
    inx
    bra rotate_fourteen_colors_in_each_selected_boss_palette_c20c8b
rotate_fourteen_colors_in_each_selected_boss_palette_c20cdd:
    ldx $87
    rts

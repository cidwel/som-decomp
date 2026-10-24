; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_with_cpu_words = $26F9

.segment "CODE"
.org $8AC6
advance_native59_six_palette_cycle_at_two_ticks:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0002
    bcc advance_native59_six_palette_cycle_at_two_ticks_c28af4
    lda a:$00B0,X
    tax
    lda f:$C28AF6,X
    .a16
    and #$00FF
    .i16
    ldx #$000E
    jsr copy_boss_palette_with_cpu_words
    ldx $87
    stz a:$0096,X
    inc a:$00B0,X
    lda a:$00B0,X
    .a16
    cmp #$0006
    bcc advance_native59_six_palette_cycle_at_two_ticks_c28af4
    stz a:$00B0,X
advance_native59_six_palette_cycle_at_two_ticks_c28af4:
    clc
    rts

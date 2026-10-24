; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_with_cpu_words = $26F9

.segment "CODE"
.org $7081
cycle_descriptor_eight_child_end_palette_slot:
    ldx $87
    lda a:$00B2,X
    tax
    lda f:$C270AF,X
    .a16
    and #$00FF
    .i16
    ldx #$000D
    jsr copy_boss_palette_with_cpu_words
    ldx $87
    inc a:$00B2,X
    lda a:$00B2,X
    .a16
    and #$0003
    sta a:$00B2,X
    rts

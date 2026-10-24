; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight-child.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_with_cpu_words = $26F9

.segment "CODE"
.org $7041
cycle_descriptor_eight_child_three_palette_slots:
    ldx $87
    lda a:$00B2,X
    tax
    phx
    lda f:$C270A3,X
    .a16
    and #$00FF
    .i16
    ldx #$0006
    jsr copy_boss_palette_with_cpu_words
    plx
    phx
    lda f:$C270A7,X
    .a16
    and #$00FF
    .i16
    ldx #$0007
    jsr copy_boss_palette_with_cpu_words
    plx
    lda f:$C270AB,X
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

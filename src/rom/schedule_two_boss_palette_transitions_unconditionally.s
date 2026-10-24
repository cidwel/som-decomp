; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D

.segment "CODE"
.org $4477
schedule_two_boss_palette_transitions_unconditionally:
    sep #$20
    .i16
    ldx #$000D
    .a8
    lda #$1E
    sta a:$033F,X
    inx
    .a8
    lda #$1F
    sta a:$033F,X
    rep #$20
    .i16
    ldx #$001E
    .i16
    ldy #$000D
    .a16
    lda #$0016
    jsr allocate_boss_palette_transition_object
    .i16
    ldx #$001E
    .i16
    ldy #$000E
    .a16
    lda #$0016
    jsr allocate_boss_palette_transition_object
    rts

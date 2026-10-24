; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D

.segment "CODE"
.org $4437
schedule_two_boss_palette_transitions_if_variant:
    lda a:$0042,X
    beq schedule_two_boss_palette_transitions_if_variant_c24466
    sep #$20
    .i16
    ldx #$000D
    .a8
    lda #$1C
    sta a:$033F,X
    inx
    .a8
    lda #$1D
    sta a:$033F,X
    rep #$20
    .i16
    ldx #$001C
    .i16
    ldy #$000D
    .a16
    lda #$0010
    jsr allocate_boss_palette_transition_object
    .i16
    ldx #$001D
    .i16
    ldy #$000E
    .a16
    lda #$0010
    jsr allocate_boss_palette_transition_object
schedule_two_boss_palette_transitions_if_variant_c24466:
    rts

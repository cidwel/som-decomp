; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01c599 = $1C599

.segment "CODE"
.org $85F1
load_floating_combat_number_graphic_planes:
    rep #$30
    stx $14
    .a16
    lda #$0032
    sta $08
    .a16
    lda #$0800
    sta $00
    .i16
    ldy #$F100
    .a16
    lda #$00D1
    jsl f:routine_01c599
    rts

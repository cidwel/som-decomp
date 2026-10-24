; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-publication.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01c599 = $1C599

.segment "CODE"
.org $8634
load_actor_cast_secondary_graphics:
    rep #$30
    ldx $14
    .a16
    lda #$0040
    sta $08
    .a16
    lda #$0800
    sta $00
    .i16
    ldy #$BA00
    .a16
    lda #$00D4
    jsl f:routine_01c599
    rts

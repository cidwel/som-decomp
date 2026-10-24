; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16




.segment "CODE"
.org $3962
prepare_cast_actor_context:
    rep #$30
    .a16
    lda #$0300
    tcd
    txa
    .a16
    and #$1FFF
    sta $83
    tya
    .a16
    and #$1FFF
    sta $85
    sep #$20
    lda $84
    lsr
    sta $82
    lda $86
    lsr
    sta $81
    .a8
    lda #$7E
    pha
    plb
    ldx $85
    ldy $83
    rts

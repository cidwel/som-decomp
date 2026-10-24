; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4518
prepare_actor_appearance_context:
    rep #$30
    .a16
    lda #$0300
    tcd
    txa
    .a16
    and #$1FFF
    sta $BD
    tax
    sep #$20
    xba
    lsr
    sta $BA
    .a8
    lda #$7E
    pha
    plb
    rts

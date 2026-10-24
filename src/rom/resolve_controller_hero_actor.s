; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

highest_set_bit_index = $2710



.segment "CODE"
.org $04D3
resolve_controller_hero_actor:
    phd
    php
    rep #$30
    .a16
    and #$0003
    tax
    lda f:$0000D9,X
    .a16
    and #$0007
    tax
    phy
    jsr highest_set_bit_index
    ply
    .i16
    ldx #$0000
    sep #$20
    .a8
    cmp #$FF
    beq resolve_controller_hero_actor_c104ff
    rep #$20
    .a16
    and #$0003
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    sep #$20
resolve_controller_hero_actor_c104ff:
    plp
    pld
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01d5cb = $1D5CB
routine_01d6ef = $1D6EF

.segment "CODE"
.org $CB12
dispatch_external_actor_command_with_saved_context:
    php
    phd
    phb
    rep #$20
    pha
    .a16
    lda #$0000
    tcd
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    pla
    sta $0C
    pla
    .a8
    cmp #$B0
    bcs dispatch_external_actor_command_with_saved_context_c1cb30
    jsl f:routine_01d5cb
    bra dispatch_external_actor_command_with_saved_context_c1cb34
dispatch_external_actor_command_with_saved_context_c1cb30:
    jsl f:routine_01d6ef
dispatch_external_actor_command_with_saved_context_c1cb34:
    plb
    pld
    plp
    rtl

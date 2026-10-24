; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-api.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_guarded_actor_cast_request_and_party_graphics = $88C7
routine_018707 = $18707

.segment "CODE"
.org $806F
cast_actor_request_preserving_cpu_context:
    php
    phb
    phd
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    .a16
    lda #$0000
    tcd
    jsr prepare_guarded_actor_cast_request_and_party_graphics
    jsl f:routine_018707
    pld
    plb
    plp
    rtl

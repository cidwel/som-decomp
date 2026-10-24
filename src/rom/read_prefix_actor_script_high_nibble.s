; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-program-prefix-copies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $00E9
read_prefix_actor_script_high_nibble:
    phd
    php
    rep #$20
    sep #$20
    lda a:$0146,Y
    lsr
    lsr
    lsr
    lsr
    plp
    pld
    rts

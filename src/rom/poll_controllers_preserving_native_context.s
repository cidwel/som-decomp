; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-poll.md.
.setcpu "65816"
.smart
.a8
.i16

poll_three_controller_words_and_publish_pressed_edges = $93B9

.segment "CODE"
.org $939F
poll_controllers_preserving_native_context:
    php
    phd
    phb
    rep #$20
    .a16
    lda #$0000
    tcd
    sep #$20
    pha
    plb
    jsr poll_three_controller_words_and_publish_pressed_edges
    plb
    pld
    plp
    rts

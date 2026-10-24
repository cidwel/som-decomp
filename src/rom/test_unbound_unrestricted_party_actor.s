; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B59D
test_unbound_unrestricted_party_actor:
    phx
    xba
    .a8
    lda #$00
    rep #$10
    tax
    lda a:$E000,X
    beq test_unbound_unrestricted_party_actor_c2b5c4
    bmi test_unbound_unrestricted_party_actor_c2b5c4
    lda a:$E191,X
    .a8
    and #$C1
    bne test_unbound_unrestricted_party_actor_c2b5c4
    lda a:$E190,X
    .a8
    and #$60
    bne test_unbound_unrestricted_party_actor_c2b5c4
    lda a:$E02C,X
    ora a:$E08C,X
    bne test_unbound_unrestricted_party_actor_c2b5c4
    clc
    bra test_unbound_unrestricted_party_actor_c2b5c5
test_unbound_unrestricted_party_actor_c2b5c4:
    sec
test_unbound_unrestricted_party_actor_c2b5c5:
    sep #$10
    plx
    rtl

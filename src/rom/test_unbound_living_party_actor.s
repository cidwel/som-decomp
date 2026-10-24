; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c2b5c4 = $B5C4
routine_c2b5c5 = $B5C5

.segment "CODE"
.org $B5C9
test_unbound_living_party_actor:
    phx
    xba
    .a8
    lda #$00
    rep #$10
    tax
    lda a:$E000,X
    beq routine_c2b5c4
    bmi routine_c2b5c4
    lda a:$E02C,X
    ora a:$E08C,X
    bne routine_c2b5c4
    lda a:$E191,X
    bmi routine_c2b5c4
    clc
    bra routine_c2b5c5

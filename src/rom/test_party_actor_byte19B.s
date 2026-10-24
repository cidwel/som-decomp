; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-target-status-queries.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0A25
test_party_actor_byte19B:
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$019B,X
    .a16
    and #$00FF
    beq test_party_actor_byte19B_c20a3b
    .a16
    lda #$0000
    rts
test_party_actor_byte19B_c20a3b:
    .a16
    lda #$FFFF
    rts

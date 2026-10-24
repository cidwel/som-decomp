; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16




.segment "CODE"
.org $541B
apply_lucid_barrier_absorption:
    lda a:$E1B1,X
    .a8
    bit #$10
    beq apply_lucid_barrier_absorption_c05436
    rep #$20
    lda $90
    .a16
    and #$00FF
    sta $A4
    lda $89
    sec
    sbc $A4
    sta $89
    stz $94
    sep #$20
apply_lucid_barrier_absorption_c05436:
    rts

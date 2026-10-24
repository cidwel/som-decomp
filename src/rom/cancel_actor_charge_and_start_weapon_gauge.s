; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CACD
cancel_actor_charge_and_start_weapon_gauge:
    stz a:$E01A,X
    stz a:$E01B,X
    stz a:$E19B,X
    .a8
    lda #$64
    sec
    sbc a:$E189,X
    lsr
    clc
    .a8
    adc #$32
    sta a:$E1ED,X
    stz a:$E063,X
    rts

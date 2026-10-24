; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B01E
clear_actor_charge_and_idle_party_gauge:
    stz a:$E085,X
    stz a:$E01A,X
    stz a:$E01B,X
    stz a:$E19B,X
    .i16
    cpx #$0600
    bcs clear_actor_charge_and_idle_party_gauge_c2b052
    lda a:$E1ED,X
    bne clear_actor_charge_and_idle_party_gauge_c2b052
    rep #$20
    txa
    xba
    asl
    asl
    asl
    phy
    tay
    .a16
    lda #$2817
    sta a:$0A56,Y
    .a16
    lda #$0000
    sta a:$0A50,Y
    sta a:$0A52,Y
    sta a:$0A53,Y
    ply
    sep #$20
clear_actor_charge_and_idle_party_gauge_c2b052:
    rtl

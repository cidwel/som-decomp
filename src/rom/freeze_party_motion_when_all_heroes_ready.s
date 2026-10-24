; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B053
freeze_party_motion_when_all_heroes_ready:
    rep #$10
    .i16
    ldx #$0400
freeze_party_motion_when_all_heroes_ready_c2b058:
    sep #$20
    lda a:$E000,X
    beq freeze_party_motion_when_all_heroes_ready_c2b066
    bmi freeze_party_motion_when_all_heroes_ready_c2b066
    lda a:$E060,X
    bne freeze_party_motion_when_all_heroes_ready_c2b08f
freeze_party_motion_when_all_heroes_ready_c2b066:
    rep #$20
    txa
    sec
    .a16
    sbc #$0200
    tax
    bpl freeze_party_motion_when_all_heroes_ready_c2b058
    stz a:$E006
    stz a:$E206
    stz a:$E406
    stz a:$E008
    stz a:$E208
    stz a:$E408
    sep #$20
    stz a:$E01D
    stz a:$E21D
    stz a:$E41D
    clc
    rtl
freeze_party_motion_when_all_heroes_ready_c2b08f:
    sec
    rtl

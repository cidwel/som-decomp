; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C097
append_oneshot_ppu_entry:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    txa
    beq append_oneshot_ppu_entry_c0be
    php
    sei
    sec
    sbc a:$02D6
    sep #$20
    ldy a:$02E0
    sta a:$0001,Y
    stz a:$0001,X
    rep #$20
    stx a:$02E0
    plp
append_oneshot_ppu_entry_c0be:
    plb
    plp
    pld
    rts

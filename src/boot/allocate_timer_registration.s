; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CB86
allocate_timer_registration:
    phd
    php
    rep #$30
    pha
    tsc
    inc
    tcd
    pla
    phb
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta $01
    .i16
    ldy #$0020
    ldx a:$0302
    php
    sei
allocate_timer_registration_cba3:
    lda a:$0000,X
    beq allocate_timer_registration_cbba
    clc
    rep #$20
    txa
    .a16
    adc #$0004
    tax
    sep #$20
    dey
    bne allocate_timer_registration_cba3
    .i16
    ldx #$0000
    bra allocate_timer_registration_cbc4
allocate_timer_registration_cbba:
    lda $01
    sta a:$0001,X
    .a8
    lda #$01
    sta a:$0000,X
allocate_timer_registration_cbc4:
    plp
    plb
    pla
    plp
    pld
    rts

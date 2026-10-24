; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

notify_timer_expired = $CC8C

.segment "CODE"
.org $CCB7
tick_timer_registrations:
    phd
    php
    rep #$30
    phb
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$0302
    .a8
    lda #$20
    sta $01
tick_timer_registrations_cccc:
    lda f:$002137
    lda f:$00213D
    xba
    lda f:$00213D
    xba
    .a8
    cmp #$DE
    bcs tick_timer_registrations_ccfb
    lda a:$0000,X
    .a8
    cmp #$02
    rep #$20
    bne tick_timer_registrations_ccef
    dec a:$0002,X
    bne tick_timer_registrations_ccef
    jsr notify_timer_expired
tick_timer_registrations_ccef:
    clc
    txa
    .a16
    adc #$0004
    tax
    sep #$20
    dec $01
    bne tick_timer_registrations_cccc
tick_timer_registrations_ccfb:
    lda $01
    sta a:$0304
    plb
    pla
    plp
    pld
    rts

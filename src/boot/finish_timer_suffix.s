; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

notify_timer_expired = $CC8C

.segment "CODE"
.org $CD05
finish_timer_suffix:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    lda a:$0304
    beq finish_timer_suffix_cd48
    sta $01
    sec
    .a16
    sbc #$0020
    .a16
    eor #$FFFF
    inc
    asl
    asl
    clc
    adc a:$0302
    tax
finish_timer_suffix_cd2b:
    lda a:$0000,X
    .a16
    and #$00FF
    .a16
    cmp #$0002
    bne finish_timer_suffix_cd3e
    dec a:$0002,X
    bne finish_timer_suffix_cd3e
    jsr notify_timer_expired
finish_timer_suffix_cd3e:
    clc
    txa
    .a16
    adc #$0004
    tax
    dec $01
    bne finish_timer_suffix_cd2b
finish_timer_suffix_cd48:
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts

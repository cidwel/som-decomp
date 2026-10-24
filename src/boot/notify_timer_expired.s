; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258

.segment "CODE"
.org $CC8C
notify_timer_expired:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    ldx $01
    jsr allocate_eight_byte_record
    lda $01
    sta a:$0004,X
    tay
    sep #$20
    .a8
    lda #$FF
    sta a:$0002,X
    lda a:$0001,Y
    jsr append_pending_record
    ldx $01
    .a8
    lda #$01
    sta a:$0000,X
    pla
    pla
    plp
    pld
    rts

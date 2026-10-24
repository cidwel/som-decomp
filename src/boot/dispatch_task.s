; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

take_record_link = $B20B

.segment "CODE"
.org $A961
dispatch_task:
    lda a:$0000,X
    sta a:$00A0
    stz a:$0000,X
    stx a:$009E
    lda a:$0006,X
    tcs
    sep #$20
    lda a:$0002,X
    .a8
    cmp #$08
    beq dispatch_task_a997
    .a8
    cmp #$10
    beq dispatch_task_a9a4
    .a8
    lda #$01
    sta a:$0002,X
    rep #$20
    ldy a:$000A,X
    tyx
    jsr take_record_link
    ldy a:$009E
    sta a:$000A,Y
    plp
    plb
    plp
    pld
    rts
dispatch_task_a997:
    .a8
    lda #$01
    sta a:$0002,X
    inc a:$008E
    cli
    dec a:$008E
    rtl
dispatch_task_a9a4:
    rep #$20
    tsc
    .a16
    and #$FF00
    tcd
    clc
    .a16
    adc #$00F6
    tcs
    lda $FD
    sta $F7
    sep #$20
    lda $FF
    sta $F9
    .a8
    lda #$01
    sta a:$0002,X
    inc a:$008E
    cli
    dec a:$008E
    rtl

; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-hdma.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e8fc7 = $8FC7
routine_7e90da = $90DA
routine_7eb081 = $B081
routine_7ec44e = $C44E

.segment "CODE"
.org $8A54
allocate_and_submit_title_colour_hdma_resource:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    sep #$20
    stx $01
    .i16
    ldx #$000D
    phx
    .a8
    lda #$7E
    pha
    phy
    jsr routine_7eb081
    stx $03
    .a8
    lda #$7F
    pha
    phx
    jsr routine_7ec44e
    rep #$20
    tsc
    clc
    .a16
    adc #$0008
    tcs
    sep #$20
    .a8
    lda #$05
    jsr routine_7e8fc7
    rep #$20
    lda $03
    sta a:$0002,X
    ldy $01
    sta a:$0000,Y
    txa
    sta a:$0002,Y
    sep #$20
    .a8
    lda #$7F
    sta a:$0004,X
    .a8
    lda #$22
    sta a:$0001,X
    .a8
    lda #$02
    sta a:$0000,X
    jsr routine_7e90da
    rep #$20
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-hdma.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e8a54 = $8A54
routine_7e8fc7 = $8FC7
routine_7e90da = $90DA

.segment "CODE"
.org $8AB5
construct_four_title_colour_hdma_channels:
    phd
    php
    rep #$30
    sep #$20
    php
    sei
    .i16
    ldy #$5D86
    .i16
    ldx #$004A
    jsr routine_7e8a54
    .i16
    ldy #$5D79
    .i16
    ldx #$0046
    jsr routine_7e8a54
    .i16
    ldy #$5D6C
    .i16
    ldx #$0042
    jsr routine_7e8a54
    .a8
    lda #$05
    jsr routine_7e8fc7
    stx a:$0040
    rep #$20
    .a16
    lda #$5D63
    sta a:$0002,X
    sep #$20
    .a8
    lda #$7E
    sta a:$0004,X
    .a8
    lda #$21
    sta a:$0001,X
    .a8
    lda #$00
    sta a:$0000,X
    jsr routine_7e90da
    plp
    plp
    pld
    rts

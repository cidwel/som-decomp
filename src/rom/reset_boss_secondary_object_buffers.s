; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $238A
reset_boss_secondary_object_buffers:
    .a16
    lda #$EC00
    sta f:$002181
    .a16
    lda #$0D52
    sta f:$004372
    .a16
    lda #$1080
    sta f:$004375
    sep #$20
    .a8
    lda #$00
    sta f:$002183
    .a8
    lda #$08
    sta f:$004370
    .a8
    lda #$80
    sta f:$004371
    .a8
    lda #$C2
    sta f:$004374
    .a8
    lda #$80
    sta f:$00420B
    rep #$20
    .a16
    lda #$0E60
    sta f:$002181
    .a16
    lda #$0200
    sta f:$004375
    sep #$20
    .a8
    lda #$80
    sta f:$00420B
    rep #$20
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1C75
clear_menu_text_video:
    lda f:$7EA187
    .a8
    and #$01
    bne clear_menu_text_video_c01c82
    .a8
    lda #$60
    trb a:$1D04
clear_menu_text_video_c01c82:
    .a8
    lda #$40
    trb a:$1D04
    .a8
    lda #$08
    trb a:$1D11
    rep #$20
    .i16
    ldx #$5820
    stx a:$2116
    .a16
    lda #$0000
    sta f:$7E9000
    .a16
    lda #$9000
    sta a:$4372
    lda a:$1D1A
    sta a:$4375
    sep #$20
    .a8
    lda #$09
    sta a:$4370
    .a8
    lda #$18
    sta a:$4371
    .a8
    lda #$7E
    sta a:$4374
    .a8
    lda #$80
    sta a:$420B
    rts

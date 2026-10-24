; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01ccf5 = $1CCF5

.segment "CODE"
.org $BBD1
request_saved_map_return:
    rep #$20
    .a16
    lda #$0000
    sta f:$7EE006
    sta f:$7EE206
    sta f:$7EE406
    sta f:$7EE008,X
    sep #$20
    lda $D0
    bne request_saved_map_return_c0bbee
    stx $D4
request_saved_map_return_c0bbee:
    jsl f:routine_01ccf5
    sep #$20
    .a8
    lda #$A0
    sta $E0
    .a8
    lda #$40
    sta $FF
    .a8
    lda #$80
    sta $E8
    rts

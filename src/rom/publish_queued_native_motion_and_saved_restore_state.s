; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-queued-effect-requests.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B49C
publish_queued_native_motion_and_saved_restore_state:
    sep #$20
    lda f:$D04157,X
    sta a:$E04F,Y
    .a8
    lda #$C0
    sta a:$E060,Y
    lda a:$E01C,Y
    sta a:$E128,Y
    lda a:$E05D,Y
    sta a:$E129,Y
    .a8
    lda #$40
    sta a:$E01C,Y
    .a8
    lda #$00
    sta a:$E114,Y
    sta a:$E05D,Y
    sta a:$E012,Y
    sta a:$E00C,Y
    sta a:$E025,Y
    sta a:$E084,Y
    rep #$20
    lda a:$E104,Y
    sta a:$E12E,Y
    lda a:$E106,Y
    sta a:$E124,Y
    lda a:$E05E,Y
    sta a:$E12A,Y
    lda a:$E006,Y
    sta a:$E134,Y
    lda a:$E008,Y
    sta a:$E122,Y
    lda f:$D0415C,X
    sta a:$E0FC,Y
    lda f:$D0415A,X
    sta a:$E06A,Y
    .a16
    lda #$0000
    sta a:$E104,Y
    sta a:$E006,Y
    sta a:$E008,Y
    sta a:$E11A,Y
    sta a:$E11C,Y
    sta a:$E11E,Y
    inc
    sta a:$E118,Y
    rtl

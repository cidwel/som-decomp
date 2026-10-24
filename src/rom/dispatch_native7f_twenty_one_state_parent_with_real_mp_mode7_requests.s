; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-header.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8F33
dispatch_native7f_twenty_one_state_parent_with_real_mp_mode7_requests:
    .a16
    lda #$6363
    sta a:$0186,X
    sep #$20
    .a8
    lda #$C0
    sta f:$00211A
    rep #$20
    .a16
    lda #$0002
    sta a:$0FAE
    lda a:$0094,X
    asl
    tax
    jmp ($8F51,X)

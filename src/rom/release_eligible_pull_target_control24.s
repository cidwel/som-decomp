; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9E55
release_eligible_pull_target_control24:
    ldy a:$00B2,X
    lda a:$0190,Y
    .a16
    and #$C568
    bne release_eligible_pull_target_control24_c29e6e
    sep #$20
    lda a:$0060,Y
    bne release_eligible_pull_target_control24_c29e6c
    .a8
    lda #$24
    sta a:$01E5,Y
release_eligible_pull_target_control24_c29e6c:
    rep #$20
release_eligible_pull_target_control24_c29e6e:
    rts

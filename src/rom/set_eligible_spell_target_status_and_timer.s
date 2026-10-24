; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9910
set_eligible_spell_target_status_and_timer:
    ldy a:$00B2,X
    lda a:$0190,Y
    .a16
    and #$C568
    bne set_eligible_spell_target_status_and_timer_c2992c
    sep #$20
    .a8
    lda #$01
    ora a:$0190,Y
    sta a:$0190,Y
    .a8
    lda #$20
    sta a:$01B4,Y
    rep #$20
set_eligible_spell_target_status_and_timer_c2992c:
    rts

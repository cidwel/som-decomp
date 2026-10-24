; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $98F6
mark_eligible_spell_target_control19:
    ldy a:$00B2,X
    lda a:$0190,Y
    .a16
    and #$C568
    bne mark_eligible_spell_target_control19_c2990f
    sep #$20
    lda a:$0060,Y
    bne mark_eligible_spell_target_control19_c2990d
    .a8
    lda #$19
    sta a:$01E5,Y
mark_eligible_spell_target_control19_c2990d:
    rep #$20
mark_eligible_spell_target_control19_c2990f:
    rts

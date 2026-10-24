; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0F59
apply_boss_contact_class_eight_or_nine_control_reaction:
    lda $56
    xba
    .a16
    and #$00FF
    .a16
    cmp #$0008
    beq apply_boss_contact_class_eight_or_nine_control_reaction_c20f69
    .a16
    cmp #$0009
    bne apply_boss_contact_class_eight_or_nine_control_reaction_c20f82
apply_boss_contact_class_eight_or_nine_control_reaction_c20f69:
    sep #$20
    ldx $87
    lda a:$0034,X
    .a8
    and #$70
    asl
    .a8
    ora #$01
    ora a:$0034,X
    sta a:$0034,X
    .a8
    lda #$C0
    sta a:$0100,X
    rep #$20
apply_boss_contact_class_eight_or_nine_control_reaction_c20f82:
    rts

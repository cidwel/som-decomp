; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-actions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $867A
consume_native59_known_action_spell_or_report_unrecognized:
    lda a:$000A,X
    sep #$30
    sta $95
    .i8
    ldx #$00
consume_native59_known_action_spell_or_report_unrecognized_c28683:
    lda f:$C286A5,X
    cmp $95
    beq consume_native59_known_action_spell_or_report_unrecognized_c28696
    inx
    .i8
    cpx #$0A
    bcc consume_native59_known_action_spell_or_report_unrecognized_c28683
    rep #$30
    ldx $87
    sec
    rts
consume_native59_known_action_spell_or_report_unrecognized_c28696:
    rep #$10
    ldx $87
    .a8
    lda #$FF
    sta a:$000A,X
    lda $95
    rep #$20
    clc
    rts

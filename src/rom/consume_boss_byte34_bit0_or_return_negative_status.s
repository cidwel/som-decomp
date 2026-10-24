; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-parent-update.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0501
consume_boss_byte34_bit0_or_return_negative_status:
    sep #$20
    lda a:$0191,X
    bmi consume_boss_byte34_bit0_or_return_negative_status_c20514
    lda a:$0034,X
    .a8
    bit #$01
    beq consume_boss_byte34_bit0_or_return_negative_status_c20518
    .a8
    and #$FE
    sta a:$0034,X
consume_boss_byte34_bit0_or_return_negative_status_c20514:
    rep #$20
    sec
    rts
consume_boss_byte34_bit0_or_return_negative_status_c20518:
    rep #$20
    clc
    rts

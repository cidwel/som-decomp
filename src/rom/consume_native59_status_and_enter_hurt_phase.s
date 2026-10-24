; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-setup.md.
.setcpu "65816"
.smart
.a8
.i16

consume_boss_byte34_bit0_or_return_negative_status = $0501
consume_boss_byte35_request = $051C

.segment "CODE"
.org $857D
consume_native59_status_and_enter_hurt_phase:
    jsr consume_boss_byte35_request
    jsr consume_boss_byte34_bit0_or_return_negative_status
    bcc consume_native59_status_and_enter_hurt_phase_c28596
    ldx $87
    .a16
    lda #$0003
    sta a:$0094,X
    lda $C7
    sta a:$00B2,X
    stz a:$0096,X
    sec
consume_native59_status_and_enter_hurt_phase_c28596:
    rts

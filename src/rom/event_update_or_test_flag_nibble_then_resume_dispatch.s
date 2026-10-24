; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-flags.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c1f1c6 = $F1C6

.segment "CODE"
.org $F16F
event_update_or_test_flag_nibble_then_resume_dispatch:
    .i8
    ldy #$02
    lda [$D1],Y
    sta $04
    ldx $04
    lda a:$CF00,X
    .a8
    and #$0F
    sta $02
    lda $05
    lsr
    lsr
    lsr
    lsr
    lsr
    bcs event_update_or_test_flag_nibble_then_resume_dispatch_c1f199
    lsr
    bcs event_update_or_test_flag_nibble_then_resume_dispatch_c1f193
    lsr
    bcc event_update_or_test_flag_nibble_then_resume_dispatch_c1f1a1
    lda $05
    eor $02
    bra event_update_or_test_flag_nibble_then_resume_dispatch_c1f19d
event_update_or_test_flag_nibble_then_resume_dispatch_c1f193:
    lda $05
    ora $02
    bra event_update_or_test_flag_nibble_then_resume_dispatch_c1f19d
event_update_or_test_flag_nibble_then_resume_dispatch_c1f199:
    lda $05
    ora $02
event_update_or_test_flag_nibble_then_resume_dispatch_c1f19d:
    .a8
    and #$0F
    sta $02
event_update_or_test_flag_nibble_then_resume_dispatch_c1f1a1:
    lda $05
    bpl event_update_or_test_flag_nibble_then_resume_dispatch_c1f1af
    lda a:$CF00,X
    .a8
    and #$F0
    ora $02
    sta a:$CF00,X
event_update_or_test_flag_nibble_then_resume_dispatch_c1f1af:
    lda $02
    beq event_update_or_test_flag_nibble_then_resume_dispatch_c1f1bd
    rep #$20
    lda $D1
    clc
    .a16
    adc #$0003
    bra routine_c1f1c6
event_update_or_test_flag_nibble_then_resume_dispatch_c1f1bd:
    rts

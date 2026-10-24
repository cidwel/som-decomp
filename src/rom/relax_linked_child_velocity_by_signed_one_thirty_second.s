; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

integrate_linked_child_tip_velocity_with_parent_status_gate = $5CF1
shift_linked_child_signed_word_right_once = $5EC3

.segment "CODE"
.org $5D2D
relax_linked_child_velocity_by_signed_one_thirty_second:
    ldx $87
    .i16
    ldy #$0002
relax_linked_child_velocity_by_signed_one_thirty_second_c25d32:
    lda a:$0076,X
    sec
    sbc a:$00BC,X
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    sta $00
    lda a:$00BC,X
    clc
    adc $00
    sta a:$00BC,X
    inx
    inx
    dey
    bne relax_linked_child_velocity_by_signed_one_thirty_second_c25d32
    jsr integrate_linked_child_tip_velocity_with_parent_status_gate
    rts

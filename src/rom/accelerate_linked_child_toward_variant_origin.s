; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

advance_linked_child_strip_ring_and_parent_coordinates = $5E44
integrate_linked_child_tip_velocity_with_parent_status_gate = $5CF1
shift_linked_child_signed_word_right_once = $5EC3

.segment "CODE"
.org $5C80
accelerate_linked_child_toward_variant_origin:
    jsr advance_linked_child_strip_ring_and_parent_coordinates
    ldx $87
    lda a:$007A,X
    asl
    asl
    tax
    lda f:$C25A39,X
    sta $02
    lda f:$C25A3B,X
    sta $00
    ldx $87
    lda $02
    sec
    sbc a:$00B8,X
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    sta a:$00BC,X
    lda $00
    sec
    sbc a:$00BA,X
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    jsr shift_linked_child_signed_word_right_once
    sta a:$00BE,X
    jsr integrate_linked_child_tip_velocity_with_parent_status_gate
    clc
    rts

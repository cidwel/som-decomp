; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

derive_eight_way_direction_to_low_byte_target = $0941
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $5D87
select_target_and_heading_from_linked_child_fractional_tip:
    ldx $87
    lda a:$002B,X
    pha
    lda a:$0032,X
    pha
    lda a:$00B8,X
    php
    xba
    .a16
    and #$00FF
    plp
    bpl select_target_and_heading_from_linked_child_fractional_tip_c25d9f
    .a16
    ora #$FF00
select_target_and_heading_from_linked_child_fractional_tip_c25d9f:
    clc
    adc a:$002B,X
    sta a:$002B,X
    lda a:$00BA,X
    php
    xba
    .a16
    and #$00FF
    plp
    bpl select_target_and_heading_from_linked_child_fractional_tip_c25db4
    .a16
    ora #$FF00
select_target_and_heading_from_linked_child_fractional_tip_c25db4:
    clc
    adc a:$0032,X
    sta a:$0032,X
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    ldx $87
    sta a:$00AB,X
    asl
    tax
    lda f:$C25DDF,X
    ldx $87
    sta a:$00B4,X
    pla
    sta a:$0032,X
    pla
    sta a:$002B,X
    rts

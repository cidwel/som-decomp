; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

clear_linked_child_strip_piece_attribute_bit_40 = $5E8C
construct_linked_child_six_piece_strip_records = $5F60
consume_linked_child_request_and_select_native_definition = $5E9D
follow_linked_child_parent_variant_position = $5D5C
interpolate_linked_child_four_piece_strip_history = $5EC9
prepare_linked_child_tip_collision_and_scan_real_party = $5E5D
relax_linked_child_velocity_by_signed_one_thirty_second = $5D2D
set_linked_child_tip_piece_attribute_bit_40 = $5E7B

.segment "CODE"
.org $5C0B
advance_linked_child_attack_strip_and_switch_at_tip_limit:
    lda a:$00B6,X
    inc
    .a16
    and #$000F
    sta a:$00B6,X
    jsr follow_linked_child_parent_variant_position
    jsr interpolate_linked_child_four_piece_strip_history
    jsr construct_linked_child_six_piece_strip_records
    jsr set_linked_child_tip_piece_attribute_bit_40
    jsr prepare_linked_child_tip_collision_and_scan_real_party
    jsr relax_linked_child_velocity_by_signed_one_thirty_second
    .i16
    ldy #$0002
advance_linked_child_attack_strip_and_switch_at_tip_limit_c25c2a:
    lda a:$00B8,X
    bpl advance_linked_child_attack_strip_and_switch_at_tip_limit_c25c33
    .a16
    eor #$FFFF
    inc
advance_linked_child_attack_strip_and_switch_at_tip_limit_c25c33:
    .a16
    cmp #$3800
    bcs advance_linked_child_attack_strip_and_switch_at_tip_limit_c25c43
    inx
    inx
    dey
    bne advance_linked_child_attack_strip_and_switch_at_tip_limit_c25c2a
    ldx $87
    jsr consume_linked_child_request_and_select_native_definition
    rts
advance_linked_child_attack_strip_and_switch_at_tip_limit_c25c43:
    ldx $87
    jsr clear_linked_child_strip_piece_attribute_bit_40
    stz a:$0078,X
    stz a:$0076,X
    stz a:$00BC,X
    stz a:$00BE,X
    .a16
    lda #$5C61
    sta a:$008E,X
    jsr consume_linked_child_request_and_select_native_definition
    stz a:$00C2,X
    rts

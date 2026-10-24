; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

construct_linked_child_six_piece_strip_records = $5F60
consume_linked_child_request_and_select_native_definition = $5E9D
follow_linked_child_parent_variant_position = $5D5C
interpolate_linked_child_four_piece_strip_history = $5EC9

.segment "CODE"
.org $5E44
advance_linked_child_strip_ring_and_parent_coordinates:
    ldx $87
    lda a:$00B6,X
    inc
    .a16
    and #$000F
    sta a:$00B6,X
    jsr consume_linked_child_request_and_select_native_definition
    jsr follow_linked_child_parent_variant_position
    jsr interpolate_linked_child_four_piece_strip_history
    jsr construct_linked_child_six_piece_strip_records
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

exclude_and_mark_party_contact_inside_second_boss_box = $062D
prepare_two_boss_collision_boxes_with_selected_second_shape = $06FE
prepare_unmarked_active_party_primary_shape = $0855
test_boss_target_height_with_inverted_flag_pair = $06C5
test_first_collision_box_overlap = $05F8

.segment "CODE"
.org $055E
scan_party_primary_shapes_against_two_boss_boxes:
    ldx $87
    jsr prepare_two_boss_collision_boxes_with_selected_second_shape
    bcs scan_party_primary_shapes_against_two_boss_boxes_c2058b
    stz $24
scan_party_primary_shapes_against_two_boss_boxes_c20567:
    ldy $24
    jsr prepare_unmarked_active_party_primary_shape
    bcs scan_party_primary_shapes_against_two_boss_boxes_c20582
    lda $24
    jsr test_boss_target_height_with_inverted_flag_pair
    bcs scan_party_primary_shapes_against_two_boss_boxes_c20582
    jsr exclude_and_mark_party_contact_inside_second_boss_box
    bcs scan_party_primary_shapes_against_two_boss_boxes_c20582
    jsr test_first_collision_box_overlap
    bcc scan_party_primary_shapes_against_two_boss_boxes_c20582
    ldx $87
    rts
scan_party_primary_shapes_against_two_boss_boxes_c20582:
    inc $24
    lda $24
    .a16
    cmp #$0003
    bcc scan_party_primary_shapes_against_two_boss_boxes_c20567
scan_party_primary_shapes_against_two_boss_boxes_c2058b:
    ldx $87
    clc
    rts

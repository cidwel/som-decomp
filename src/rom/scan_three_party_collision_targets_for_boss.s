; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_secondary_collision_box = $0779
prepare_unmarked_active_party_collision_boxes = $07C7
test_boss_target_height_with_inverted_flag_pair = $06C5
test_first_collision_box_overlap = $05F8
test_second_collision_box_overlap = $0690

.segment "CODE"
.org $05BF
scan_three_party_collision_targets_for_boss:
    ldx $87
    jsr prepare_boss_secondary_collision_box
    bcs scan_three_party_collision_targets_for_boss_c205ec
    stz $24
scan_three_party_collision_targets_for_boss_c205c8:
    ldy $24
    jsr prepare_unmarked_active_party_collision_boxes
    bcs scan_three_party_collision_targets_for_boss_c205e3
    lda $24
    jsr test_boss_target_height_with_inverted_flag_pair
    bcs scan_three_party_collision_targets_for_boss_c205e3
    jsr test_second_collision_box_overlap
    bcs scan_three_party_collision_targets_for_boss_c205e3
    jsr test_first_collision_box_overlap
    bcc scan_three_party_collision_targets_for_boss_c205e3
    ldx $87
    rts
scan_three_party_collision_targets_for_boss_c205e3:
    inc $24
    lda $24
    .a16
    cmp #$0003
    bcc scan_three_party_collision_targets_for_boss_c205c8
scan_three_party_collision_targets_for_boss_c205ec:
    ldx $87
    clc
    rts

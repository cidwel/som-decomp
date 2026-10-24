; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

advance_linked_child_strip_ring_and_parent_coordinates = $5E44
derive_linked_child_random_wave_velocity_toward_variant_origin = $5DEF
integrate_linked_child_tip_velocity_with_parent_status_gate = $5CF1
set_linked_child_tip_piece_attribute_bit_40 = $5E7B

.segment "CODE"
.org $5B10
advance_linked_child_periodic_target_motion_and_select_attack:
    lda a:$0096,X
    .a16
    cmp #$0040
    beq advance_linked_child_periodic_target_motion_and_select_attack_c25b23
    ldy a:$00B0,X
    lda a:$0190,Y
    .a16
    bit #$0003
    bne advance_linked_child_periodic_target_motion_and_select_attack_c25b3d
advance_linked_child_periodic_target_motion_and_select_attack_c25b23:
    ldy a:$00B0,X
    lda a:$002D,Y
    lsr
    cmp a:$00AD,Y
    bcs advance_linked_child_periodic_target_motion_and_select_attack_c25b37
    .a16
    lda #$5B86
    sta a:$008E,X
    bra advance_linked_child_periodic_target_motion_and_select_attack_c25b3d
advance_linked_child_periodic_target_motion_and_select_attack_c25b37:
    .a16
    lda #$5CC8
    sta a:$008E,X
advance_linked_child_periodic_target_motion_and_select_attack_c25b3d:
    lda a:$0049,X
    .a16
    bit #$001F
    bne advance_linked_child_periodic_target_motion_and_select_attack_c25b54
    jsr derive_linked_child_random_wave_velocity_toward_variant_origin
    lda a:$0076,X
    sta a:$00BC,X
    lda a:$0078,X
    sta a:$00BE,X
advance_linked_child_periodic_target_motion_and_select_attack_c25b54:
    lda a:$0049,X
    inc
    sta a:$0049,X
    lsr
    .a16
    and #$000E
    tax
    lda f:$C25DDF,X
    ldx $87
    sta a:$00B4,X
    jsr integrate_linked_child_tip_velocity_with_parent_status_gate
    jsr advance_linked_child_strip_ring_and_parent_coordinates
    jsr set_linked_child_tip_piece_attribute_bit_40
    clc
    rts

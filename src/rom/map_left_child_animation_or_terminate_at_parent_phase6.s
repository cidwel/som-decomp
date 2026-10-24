; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-linked-effects.md.
.setcpu "65816"
.smart
.a8
.i16

match_left_child_animation_pointer_and_seed_linked_effect = $83B1

.segment "CODE"
.org $839D
map_left_child_animation_or_terminate_at_parent_phase6:
    ldx $87
    ldy a:$00B2,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    beq map_left_child_animation_or_terminate_at_parent_phase6_c283af
    jsr match_left_child_animation_pointer_and_seed_linked_effect
    clc
    rts
map_left_child_animation_or_terminate_at_parent_phase6_c283af:
    sec
    rts

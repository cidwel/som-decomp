; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_scene_target_with_full_direction_branches = $8E3B

.segment "CODE"
.org $8266
consume_pending_scene_target_initialization:
    sep #$20
    lda $FE
    bpl consume_pending_scene_target_initialization_c08271
    stz $FE
    jmp initialize_scene_target_with_full_direction_branches
consume_pending_scene_target_initialization_c08271:
    rts

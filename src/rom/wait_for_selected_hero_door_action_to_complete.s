; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-door-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B9B6
wait_for_selected_hero_door_action_to_complete:
    rep #$10
    ldx $D4
    lda f:$7EE00A,X
    bne wait_for_selected_hero_door_action_to_complete_c0b9c4
    stz $FF
    stz $E1
wait_for_selected_hero_door_action_to_complete_c0b9c4:
    rts

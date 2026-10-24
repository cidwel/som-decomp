; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $459C
await_next_mode_seven_scene_vblank:
    .a8
    lda #$80
await_next_mode_seven_scene_vblank_c6459e:
    bit a:$4212
    bne await_next_mode_seven_scene_vblank_c6459e
await_next_mode_seven_scene_vblank_c645a3:
    bit a:$4212
    beq await_next_mode_seven_scene_vblank_c645a3
    rts

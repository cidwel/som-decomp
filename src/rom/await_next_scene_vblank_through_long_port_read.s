; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $45A9
await_next_scene_vblank_through_long_port_read:
await_next_scene_vblank_through_long_port_read_c645a9:
    lda f:$004212
    .a8
    bit #$80
    bne await_next_scene_vblank_through_long_port_read_c645a9
await_next_scene_vblank_through_long_port_read_c645b1:
    lda f:$004212
    .a8
    bit #$80
    beq await_next_scene_vblank_through_long_port_read_c645b1
    rts

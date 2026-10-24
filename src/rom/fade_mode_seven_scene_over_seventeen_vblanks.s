; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16

await_next_mode_seven_scene_vblank = $459C

.segment "CODE"
.org $45BA
fade_mode_seven_scene_over_seventeen_vblanks:
    jsr await_next_mode_seven_scene_vblank
    jsr await_next_mode_seven_scene_vblank
    .a8
    lda #$0F
    sta a:$2100
    .a8
    lda #$0E
fade_mode_seven_scene_over_seventeen_vblanks_c645c7:
    pha
    jsr await_next_mode_seven_scene_vblank
    pla
    sta a:$2100
    dec
    bpl fade_mode_seven_scene_over_seventeen_vblanks_c645c7
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

tick_boss_animation_and_prepare_frame_graphics = $13AD

.segment "CODE"
.org $0E42
snapshot_boss_camera_and_tick_enabled_animation:
    lda a:$0098,X
    .a16
    bit #$0008
    beq snapshot_boss_camera_and_tick_enabled_animation_c20e5e
    lda a:$002B,X
    sta a:$0FB0
    lda a:$0066,X
    lsr
    eor $C7
    inc
    clc
    adc a:$0032,X
    sta a:$0FB2
snapshot_boss_camera_and_tick_enabled_animation_c20e5e:
    lda a:$0098,X
    .a16
    bit #$0800
    beq snapshot_boss_camera_and_tick_enabled_animation_c20e69
    jsr tick_boss_animation_and_prepare_frame_graphics
snapshot_boss_camera_and_tick_enabled_animation_c20e69:
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-point-producer.md.
.setcpu "65816"
.smart
.a8
.i16

unwind_native_point_frame_command_return = $A699

.segment "CODE"
.org $A69C
skip_native_point_frame_control_command:
    .a8
    cmp #$FF
    beq unwind_native_point_frame_command_return
    .a8
    cmp #$B0
    bcs skip_native_point_frame_control_command_c2a6a8
    .a8
    lda #$01
    bra skip_native_point_frame_control_command_c2a6ba
skip_native_point_frame_control_command_c2a6a8:
    .a8
    cmp #$F0
    bcs skip_native_point_frame_control_command_c2a6b0
    .a8
    lda #$02
    bra skip_native_point_frame_control_command_c2a6ba
skip_native_point_frame_control_command_c2a6b0:
    .a8
    cmp #$F8
    bcs skip_native_point_frame_control_command_c2a6b8
    .a8
    lda #$03
    bra skip_native_point_frame_control_command_c2a6ba
skip_native_point_frame_control_command_c2a6b8:
    .a8
    lda #$04
skip_native_point_frame_control_command_c2a6ba:
    rep #$20
    .a16
    and #$0007
    clc
    adc $00
    sta $00
    rts

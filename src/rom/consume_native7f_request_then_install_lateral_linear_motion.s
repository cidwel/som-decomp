; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-frame-requests.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_loader_resource_expansion = $24C3
publish_native7f_single_mode7_frame_dma_request = $95A0
request_boss_sound_with_parameter_word = $30E3
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9539
consume_native7f_request_then_install_lateral_linear_motion:
    lda a:$0364
    beq consume_native7f_request_then_install_lateral_linear_motion_c29547
    .a16
    lda #$0020
    jsr prepare_boss_loader_resource_expansion
    stz a:$0364
consume_native7f_request_then_install_lateral_linear_motion_c29547:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0009
    bcc consume_native7f_request_then_install_lateral_linear_motion_c2959b
    stz a:$0096,X
    .a16
    lda #$9224
    sta a:$0090,X
    .a16
    lda #$0080
    sta a:$00B0,X
    .a16
    lda #$0115
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B6,X
    stz a:$00B4,X
    .a16
    lda #$0007
    sta a:$0094,X
    .a16
    lda #$0228
    sta a:$002B,X
    .a16
    lda #$FFF8
    sta a:$003C,X
    stz a:$003A,X
    stz a:$0040,X
    stz a:$003E,X
    .a16
    lda #$0038
    sta a:$02D5
    .a16
    lda #$0020
    sta a:$02D7
    .a16
    lda #$00D6
    jsr request_boss_sound_with_parameter_word
    bra consume_native7f_request_then_install_lateral_linear_motion_c2959e
consume_native7f_request_then_install_lateral_linear_motion_c2959b:
    jsr publish_native7f_single_mode7_frame_dma_request
consume_native7f_request_then_install_lateral_linear_motion_c2959e:
    clc
    rts

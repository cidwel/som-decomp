; Recovered Secret of Mana USA routine; behaviour documented in docs/map-motion-shared.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D890
publish_actor_wrapped_position_layer_and_camera_step:
    sep #$20
    .i16
    cpx #$0600
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d8ae
    lda $1B
    .a8
    and #$08
    beq publish_actor_wrapped_position_layer_and_camera_step_c0d8ae
    lda a:$E02C,X
    bne publish_actor_wrapped_position_layer_and_camera_step_c0d8ae
    phx
    ldx $BA
    asl $1B
    lda a:$E00B,X
    asl
    ror $1B
    plx
publish_actor_wrapped_position_layer_and_camera_step_c0d8ae:
    lda $1B
    sta a:$E00B,X
    lda $04
    cmp a:$E04D,X
    beq publish_actor_wrapped_position_layer_and_camera_step_c0d8c5
    sta a:$E04D,X
    sta a:$E048,X
    lda $05
    sta a:$E049,X
publish_actor_wrapped_position_layer_and_camera_step_c0d8c5:
    lda $1E
    sta $84
    beq publish_actor_wrapped_position_layer_and_camera_step_c0d912
    bmi publish_actor_wrapped_position_layer_and_camera_step_c0d8de
    rep #$20
    .a16
    and #$007F
    clc
    adc a:$E002,X
    cmp $C0
    bcc publish_actor_wrapped_position_layer_and_camera_step_c0d8ef
    sbc $C0
    bra publish_actor_wrapped_position_layer_and_camera_step_c0d8ef
publish_actor_wrapped_position_layer_and_camera_step_c0d8de:
    rep #$20
    .a16
    and #$007F
    .a16
    eor #$FFFF
    sec
    adc a:$E002,X
    bpl publish_actor_wrapped_position_layer_and_camera_step_c0d8ef
    clc
    adc $C0
publish_actor_wrapped_position_layer_and_camera_step_c0d8ef:
    sta a:$E002,X
    .i16
    cpx #$0600
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d90e
    sec
    sbc $16
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d8fe
    adc $C0
publish_actor_wrapped_position_layer_and_camera_step_c0d8fe:
    bit $1D
    bpl publish_actor_wrapped_position_layer_and_camera_step_c0d909
    .a16
    cmp #$0038
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d90e
    bcc publish_actor_wrapped_position_layer_and_camera_step_c0d912
publish_actor_wrapped_position_layer_and_camera_step_c0d909:
    .a16
    cmp #$00C8
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d912
publish_actor_wrapped_position_layer_and_camera_step_c0d90e:
    sep #$20
    stz $84
publish_actor_wrapped_position_layer_and_camera_step_c0d912:
    sep #$20
    lda $1F
    sta $86
    beq publish_actor_wrapped_position_layer_and_camera_step_c0d961
    bmi publish_actor_wrapped_position_layer_and_camera_step_c0d92d
    rep #$20
    .a16
    and #$007F
    clc
    adc a:$E004,X
    cmp $C2
    bcc publish_actor_wrapped_position_layer_and_camera_step_c0d93e
    sbc $C2
    bra publish_actor_wrapped_position_layer_and_camera_step_c0d93e
publish_actor_wrapped_position_layer_and_camera_step_c0d92d:
    rep #$20
    .a16
    and #$007F
    .a16
    eor #$FFFF
    sec
    adc a:$E004,X
    bpl publish_actor_wrapped_position_layer_and_camera_step_c0d93e
    clc
    adc $C2
publish_actor_wrapped_position_layer_and_camera_step_c0d93e:
    sta a:$E004,X
    .i16
    cpx #$0600
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d961
    sec
    sbc $18
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d94d
    adc $C2
publish_actor_wrapped_position_layer_and_camera_step_c0d94d:
    bit $1E
    bpl publish_actor_wrapped_position_layer_and_camera_step_c0d958
    .a16
    cmp #$0048
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d95d
    bcc publish_actor_wrapped_position_layer_and_camera_step_c0d961
publish_actor_wrapped_position_layer_and_camera_step_c0d958:
    .a16
    cmp #$00B0
    bcs publish_actor_wrapped_position_layer_and_camera_step_c0d961
publish_actor_wrapped_position_layer_and_camera_step_c0d95d:
    sep #$20
    stz $86
publish_actor_wrapped_position_layer_and_camera_step_c0d961:
    rts

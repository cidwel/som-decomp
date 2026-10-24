; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-action-gates.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B6CD
gate_one_controller_input_and_publish_native_running_velocity:
    rep #$20
    lda a:$E190,X
    .a16
    bit #$C160
    sep #$20
    bne gate_one_controller_input_and_publish_native_running_velocity_c2b753
    lda a:$E060,X
    bne gate_one_controller_input_and_publish_native_running_velocity_c2b753
    lda a:$E1ED,X
    ora a:$E01C,X
    ora a:$E00A,X
    bne gate_one_controller_input_and_publish_native_running_velocity_c2b742
    .a8
    lda #$80
    trb $00
    beq gate_one_controller_input_and_publish_native_running_velocity_c2b741
    lda a:$E01A,X
    ora a:$E01B,X
    bne gate_one_controller_input_and_publish_native_running_velocity_c2b741
    lda a:$E063,X
    .a8
    ora #$01
    sta a:$E063,X
    .a8
    lda #$02
    sta a:$E011,X
    lda a:$E006,X
    beq gate_one_controller_input_and_publish_native_running_velocity_c2b710
    .a8
    and #$80
    .a8
    ora #$03
    sta a:$E006,X
gate_one_controller_input_and_publish_native_running_velocity_c2b710:
    lda a:$E007,X
    beq gate_one_controller_input_and_publish_native_running_velocity_c2b71c
    .a8
    and #$80
    .a8
    ora #$03
    sta a:$E007,X
gate_one_controller_input_and_publish_native_running_velocity_c2b71c:
    ora a:$E006,X
    bne gate_one_controller_input_and_publish_native_running_velocity_c2b75d
    .i16
    ldy #$8300
    lda a:$E010,X
    beq gate_one_controller_input_and_publish_native_running_velocity_c2b738
    .i16
    ldy #$0300
    dec
    beq gate_one_controller_input_and_publish_native_running_velocity_c2b738
    .i16
    ldy #$0003
    dec
    beq gate_one_controller_input_and_publish_native_running_velocity_c2b738
    .i16
    ldy #$0083
gate_one_controller_input_and_publish_native_running_velocity_c2b738:
    phy
    pla
    sta a:$E006,X
    pla
    sta a:$E007,X
gate_one_controller_input_and_publish_native_running_velocity_c2b741:
    rts
gate_one_controller_input_and_publish_native_running_velocity_c2b742:
    lda a:$E063,X
    .a8
    and #$F0
    sta a:$E063,X
    .a8
    lda #$80
    trb $00
    .a8
    lda #$80
    trb $01
    rts
gate_one_controller_input_and_publish_native_running_velocity_c2b753:
    .a8
    lda #$42
    .a8
    eor #$FF
    trb $00
    stz $01
    stz $02
gate_one_controller_input_and_publish_native_running_velocity_c2b75d:
    rts

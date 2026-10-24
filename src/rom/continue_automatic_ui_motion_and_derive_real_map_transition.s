; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-motion-chain.md.
.setcpu "65816"
.smart
.a8
.i16

advance_automatic_ui_radial_focus_and_publish_attribute_sample = $8F24
advance_two_scene_attribute_windows_and_rom_rows = $8455
derive_automatic_ui_map_target_before_native_stack_reset = $824E
integrate_automatic_ui_fractional_motion_and_request_tile_edges = $8DEE

.segment "CODE"
.org $8CFF
continue_automatic_ui_motion_and_derive_real_map_transition:
    jmp advance_automatic_ui_radial_focus_and_publish_attribute_sample
    lsr
    bcs continue_automatic_ui_motion_and_derive_real_map_transition_c08d08
    brl continue_automatic_ui_motion_and_derive_real_map_transition_c08d8e
continue_automatic_ui_motion_and_derive_real_map_transition_c08d08:
    rep #$20
    lda $8E
    dec
    sta $8E
    sep #$20
    bne continue_automatic_ui_motion_and_derive_real_map_transition_c08d1a
    .a8
    lda #$80
    sta $F2
    jmp derive_automatic_ui_map_target_before_native_stack_reset
continue_automatic_ui_motion_and_derive_real_map_transition_c08d1a:
    lda $8F
    lsr
    lda $8E
    bcs continue_automatic_ui_motion_and_derive_real_map_transition_c08d2a
    .a8
    cmp #$40
    bcs continue_automatic_ui_motion_and_derive_real_map_transition_c08d2a
    lsr
    lsr
    sta a:$2100
continue_automatic_ui_motion_and_derive_real_map_transition_c08d2a:
    lda $8F
    lsr
    lda $8E
    ror
    sta a:$4202
    .a8
    lda #$D0
    sta a:$4203
    .a8
    lda #$10
    clc
    nop
    nop
    adc a:$4217
    sta $F8
    rep #$30
    lda $8E
    stz $00
    .a16
    bit #$0100
    beq continue_automatic_ui_motion_and_derive_real_map_transition_c08d4f
    dec $00
continue_automatic_ui_motion_and_derive_real_map_transition_c08d4f:
    .a16
    bit #$0080
    beq continue_automatic_ui_motion_and_derive_real_map_transition_c08d57
    .a16
    eor #$007F
continue_automatic_ui_motion_and_derive_real_map_transition_c08d57:
    .a16
    and #$007F
    asl
    asl
    tax
    lda a:$FD22,X
    lsr
    bit $00
    bpl continue_automatic_ui_motion_and_derive_real_map_transition_c08d68
    .a16
    eor #$FFFF
continue_automatic_ui_motion_and_derive_real_map_transition_c08d68:
    clc
    adc $96
    .a16
    and #$03FF
    sta $F6
    jsr integrate_automatic_ui_fractional_motion_and_request_tile_edges
    sep #$30
    lda $8F
    lsr
    ror
    eor $8E
    .a8
    eor #$80
    lsr
    lsr
    .a8
    and #$20
    tax
    .i8
    ldy #$02
    lda $F4
    .a8
    bit #$01
    beq continue_automatic_ui_motion_and_derive_real_map_transition_c08d8b
    rts
continue_automatic_ui_motion_and_derive_real_map_transition_c08d8b:
    jmp advance_two_scene_attribute_windows_and_rom_rows
continue_automatic_ui_motion_and_derive_real_map_transition_c08d8e:
    rep #$20
    sep #$10
    lda $F6
    sec
    .a16
    sbc #$0004
    sta $F6
    lda $8E
    sec
    .a16
    sbc #$0001
    sta $8E
    bcs continue_automatic_ui_motion_and_derive_real_map_transition_c08dac
    .i8
    ldx #$00
    stx $8C
    jmp derive_automatic_ui_map_target_before_native_stack_reset
continue_automatic_ui_motion_and_derive_real_map_transition_c08dab:
    rts
continue_automatic_ui_motion_and_derive_real_map_transition_c08dac:
    sta $8E
    .a16
    cmp #$0100
    sep #$20
    bcc continue_automatic_ui_motion_and_derive_real_map_transition_c08db9
    .a8
    eor #$FF
    bra continue_automatic_ui_motion_and_derive_real_map_transition_c08dc4
continue_automatic_ui_motion_and_derive_real_map_transition_c08db9:
    .a8
    cmp #$40
    bcs continue_automatic_ui_motion_and_derive_real_map_transition_c08dc4
    pha
    lsr
    lsr
    sta a:$2100
    pla
continue_automatic_ui_motion_and_derive_real_map_transition_c08dc4:
    rep #$30
    .a16
    and #$00FF
    asl
    tax
    lda a:$FD22,X
    .a16
    cmp #$0100
    sep #$30
    bne continue_automatic_ui_motion_and_derive_real_map_transition_c08dd7
    .a8
    lda #$FF
continue_automatic_ui_motion_and_derive_real_map_transition_c08dd7:
    sta a:$4202
    .a8
    lda #$F8
    sta a:$4203
    nop
    nop
    nop
    nop
    lda a:$4217
    .a8
    ora #$01
    sta $90
    lda $8F
    beq continue_automatic_ui_motion_and_derive_real_map_transition_c08dab

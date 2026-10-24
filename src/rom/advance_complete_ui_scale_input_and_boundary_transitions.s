; C085DD immediate width inferred from public-entry SEP30/Y-domain proof.
; No executed coverage state claimed for this instruction.
; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-navigation.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c087b7 = $87B7
test_ui_target_tile_permission_and_request_map_transition = $8159

.segment "CODE"
.org $8598
advance_complete_ui_scale_input_and_boundary_transitions:
    sep #$30
    .i8
    ldy #$02
    bit $42
    bpl advance_complete_ui_scale_input_and_boundary_transitions_c085a9
    lda $F8
    .a8
    cmp #$30
    bcs advance_complete_ui_scale_input_and_boundary_transitions_c085c1
    dey
    bra advance_complete_ui_scale_input_and_boundary_transitions_c085c1
advance_complete_ui_scale_input_and_boundary_transitions_c085a9:
    lda $F8
    .a8
    cmp #$30
    bcs advance_complete_ui_scale_input_and_boundary_transitions_c085c1
    dey
    .a8
    cmp #$20
    bcs advance_complete_ui_scale_input_and_boundary_transitions_c085c1
    lsr
    lsr
    .a8
    and #$03
    .a8
    eor #$03
    .a8
    ora #$01
    and $F4
    beq advance_complete_ui_scale_input_and_boundary_transitions_c085c1
    rts
advance_complete_ui_scale_input_and_boundary_transitions_c085c1:
    bit $42
    bmi advance_complete_ui_scale_input_and_boundary_transitions_c085e8
    bit $43
    bmi advance_complete_ui_scale_input_and_boundary_transitions_c085fe
    lda $6B
    beq advance_complete_ui_scale_input_and_boundary_transitions_c085e7
    lda $6A
    clc
    .a8
    adc #$04
    sta $6A
    and $6B
    beq advance_complete_ui_scale_input_and_boundary_transitions_c085e7
    asl $6B
    dey
    bpl advance_complete_ui_scale_input_and_boundary_transitions_c085df
    .i8
    ldy #$00
advance_complete_ui_scale_input_and_boundary_transitions_c085df:
    .a8
    lda #$01
    bit $6A
    bne advance_complete_ui_scale_input_and_boundary_transitions_c085f0
    beq advance_complete_ui_scale_input_and_boundary_transitions_c08606
advance_complete_ui_scale_input_and_boundary_transitions_c085e7:
    rts
advance_complete_ui_scale_input_and_boundary_transitions_c085e8:
    .a8
    lda #$04
    sta $6B
    .a8
    lda #$01
    sta $6A
advance_complete_ui_scale_input_and_boundary_transitions_c085f0:
    tya
    clc
    adc $F8
    sta $F8
    .a8
    cmp #$32
    bcc advance_complete_ui_scale_input_and_boundary_transitions_c0861b
    .a8
    cmp #$E0
    bcc advance_complete_ui_scale_input_and_boundary_transitions_c0862d
advance_complete_ui_scale_input_and_boundary_transitions_c085fe:
    .a8
    lda #$04
    sta $6B
    .a8
    lda #$02
    sta $6A
advance_complete_ui_scale_input_and_boundary_transitions_c08606:
    tya
    .a8
    eor #$FF
    inc
    clc
    adc $F8
    .a8
    cmp #$2B
    bcs advance_complete_ui_scale_input_and_boundary_transitions_c08619
    bit $F2
    bpl advance_complete_ui_scale_input_and_boundary_transitions_c0861f
    .a8
    cmp #$10
    bcc advance_complete_ui_scale_input_and_boundary_transitions_c0861c
advance_complete_ui_scale_input_and_boundary_transitions_c08619:
    sta $F8
advance_complete_ui_scale_input_and_boundary_transitions_c0861b:
    rts
advance_complete_ui_scale_input_and_boundary_transitions_c0861c:
    jmp test_ui_target_tile_permission_and_request_map_transition
advance_complete_ui_scale_input_and_boundary_transitions_c0861f:
    .a8
    lda #$03
    bit $F2
    beq advance_complete_ui_scale_input_and_boundary_transitions_c08626
    rts
advance_complete_ui_scale_input_and_boundary_transitions_c08626:
    .a8
    lda #$10
    tsb $9E
    jmp routine_c087b7
advance_complete_ui_scale_input_and_boundary_transitions_c0862d:
    .a8
    lda #$10
    trb $9E
    beq advance_complete_ui_scale_input_and_boundary_transitions_c08637
    ora $CC
    sta $CC
advance_complete_ui_scale_input_and_boundary_transitions_c08637:
    rts

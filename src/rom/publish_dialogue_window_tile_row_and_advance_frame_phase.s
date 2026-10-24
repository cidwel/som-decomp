; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

clear_dialogue_window_tile_run_and_advance_destination = $0435
draw_native_dialogue_window_rom_tile_sequence = $0478
request_dialogue_transfer_and_conditional_window_flags = $0FFA
request_dialogue_window_transfer_of_256_bytes = $0D7F

.segment "CODE"
.org $02BD
publish_dialogue_window_tile_row_and_advance_frame_phase:
    lda a:$A16C
    lsr
    .a8
    adc #$00
    inc
    sta a:$A164
    ldx a:$A1A2
    stx a:$A1A0
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    lda a:$A162
    .a8
    cmp #$01
    bne publish_dialogue_window_tile_row_and_advance_frame_phase_c002e4
    lda a:$A15C
    .a8
    cmp #$05
    bcs publish_dialogue_window_tile_row_and_advance_frame_phase_c002e4
    jsr clear_dialogue_window_tile_run_and_advance_destination
publish_dialogue_window_tile_row_and_advance_frame_phase_c002e4:
    .a8
    lda #$00
    xba
    lda a:$A15C
    .a8
    cmp #$01
    beq publish_dialogue_window_tile_row_and_advance_frame_phase_c002f5
    .a8
    cmp #$05
    beq publish_dialogue_window_tile_row_and_advance_frame_phase_c002f5
    .a8
    lda #$02
    xba
publish_dialogue_window_tile_row_and_advance_frame_phase_c002f5:
    xba
    tsb a:$A186
    .a8
    lda #$FF
    sta a:$A171
    jsr draw_native_dialogue_window_rom_tile_sequence
    lda a:$A15C
    .a8
    cmp #$05
    bcc publish_dialogue_window_tile_row_and_advance_frame_phase_c0030c
    tyx
    jsr clear_dialogue_window_tile_run_and_advance_destination
publish_dialogue_window_tile_row_and_advance_frame_phase_c0030c:
    jsr request_dialogue_window_transfer_of_256_bytes
    rep #$20
    .a16
    lda #$0180
    sta f:$001D18
    lda a:$A15C
    .a16
    and #$00FF
    dec
    asl
    tax
    lda f:$C01102,X
    sta f:$001D06
    sep #$20
    .a8
    lda #$07
    jsr request_dialogue_transfer_and_conditional_window_flags
    lda a:$A15C
    .a8
    cmp #$04
    bne publish_dialogue_window_tile_row_and_advance_frame_phase_c00344
    ldx a:$A1A0
    dex
    dex
    stx a:$A1A2
    .a8
    lda #$01
    sta a:$A186
publish_dialogue_window_tile_row_and_advance_frame_phase_c00344:
    inc a:$A15C
    rts

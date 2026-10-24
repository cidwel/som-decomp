; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

clear_dialogue_window_tile_run_and_advance_destination = $0435
draw_dialogue_window_end_tile_for_current_style = $0413
draw_dialogue_window_fill_tile_pairs = $044C
request_dialogue_transfer_and_conditional_window_flags = $0FFA
request_dialogue_window_transfer_of_256_bytes = $0D7F

.segment "CODE"
.org $0348
publish_active_dialogue_window_raster_phase:
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    lda a:$A162
    .a8
    cmp #$01
    bne publish_active_dialogue_window_raster_phase_c0036d
    lda a:$A16F
    beq publish_active_dialogue_window_raster_phase_c00363
    lda a:$A15C
    .a8
    cmp #$03
    bcs publish_active_dialogue_window_raster_phase_c0036d
    bra publish_active_dialogue_window_raster_phase_c0036a
publish_active_dialogue_window_raster_phase_c00363:
    lda a:$A15C
    .a8
    cmp #$05
    bcs publish_active_dialogue_window_raster_phase_c0036d
publish_active_dialogue_window_raster_phase_c0036a:
    jsr clear_dialogue_window_tile_run_and_advance_destination
publish_active_dialogue_window_raster_phase_c0036d:
    ldx a:$A1A0
    phx
    lda a:$A16F
    beq publish_active_dialogue_window_raster_phase_c0037f
    lda a:$A15C
    .a8
    cmp #$03
    bcs publish_active_dialogue_window_raster_phase_c00389
    bra publish_active_dialogue_window_raster_phase_c00386
publish_active_dialogue_window_raster_phase_c0037f:
    lda a:$A15C
    .a8
    cmp #$05
    bcs publish_active_dialogue_window_raster_phase_c00389
publish_active_dialogue_window_raster_phase_c00386:
    jsr draw_dialogue_window_end_tile_for_current_style
publish_active_dialogue_window_raster_phase_c00389:
    lda a:$A16C
    lsr
    .a8
    adc #$00
    sta a:$A164
    ldx a:$A182
    stx a:$A1A0
    stz a:$A16D
    stz a:$A171
    jsr draw_dialogue_window_fill_tile_pairs
    lda a:$A16F
    beq publish_active_dialogue_window_raster_phase_c003af
    lda a:$A15C
    .a8
    cmp #$03
    bcc publish_active_dialogue_window_raster_phase_c003bd
    bra publish_active_dialogue_window_raster_phase_c003b6
publish_active_dialogue_window_raster_phase_c003af:
    lda a:$A15C
    .a8
    cmp #$05
    bcc publish_active_dialogue_window_raster_phase_c003bd
publish_active_dialogue_window_raster_phase_c003b6:
    jsr draw_dialogue_window_end_tile_for_current_style
    tyx
    jsr clear_dialogue_window_tile_run_and_advance_destination
publish_active_dialogue_window_raster_phase_c003bd:
    plx
    stx a:$A1A0
    jsr request_dialogue_window_transfer_of_256_bytes
    rep #$20
    lda a:$A15C
    .a16
    and #$00FF
    dec
    asl
    tax
    lda f:$C01102,X
    sta f:$001D06
    sep #$20
    lda a:$A16F
    beq publish_active_dialogue_window_raster_phase_c00404
    lda a:$A15C
    .a8
    cmp #$02
    bne publish_active_dialogue_window_raster_phase_c003ea
    .a8
    lda #$01
    tsb a:$A186
publish_active_dialogue_window_raster_phase_c003ea:
    rep #$20
    lda a:$A15C
    .a16
    and #$00FF
    dec
    asl
    tax
    lda f:$C01112,X
    sta f:$001D06
    .a16
    lda #$0180
    sta f:$001D18
publish_active_dialogue_window_raster_phase_c00404:
    sep #$20
    .a8
    lda #$07
    jsr request_dialogue_transfer_and_conditional_window_flags
    inc a:$A15C
    rts

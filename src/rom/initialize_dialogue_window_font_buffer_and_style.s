; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

copy_dialogue_window_style_and_fill_graphics_page = $09BA
publish_dialogue_style_palette_banks = $0968
request_dialogue_transfer_and_conditional_window_flags = $0FFA
select_dialogue_window_geometry_from_state = $0D8B

.segment "CODE"
.org $090F
initialize_dialogue_window_font_buffer_and_style:
    .a8
    lda #$02
    sta a:$A16E
    .i16
    ldx #$9C00
    stx a:$A19B
    stz a:$9400
    rep #$20
    .a16
    lda #$06FF
    .i16
    ldx #$9400
    .i16
    ldy #$9401
    mvn #$7E, #$7E
    sep #$20
    jsr copy_dialogue_window_style_and_fill_graphics_page
    lda a:$A162
    .a8
    cmp #$01
    beq initialize_dialogue_window_font_buffer_and_style_c0093a
    jsr publish_dialogue_style_palette_banks
initialize_dialogue_window_font_buffer_and_style_c0093a:
    .a8
    lda #$0F
    sta f:$001D04
    inc a:$A15C
    lda a:$CFF8
    beq initialize_dialogue_window_font_buffer_and_style_c00962
    .a8
    lda #$00
    xba
    lda a:$A24E
    tax
    lda a:$A24F,X
    sta a:$A21B
    .a8
    lda #$04
    sta a:$A24F,X
    .a8
    lda #$05
    sta a:$A15C
    jsr select_dialogue_window_geometry_from_state
initialize_dialogue_window_font_buffer_and_style_c00962:
    .a8
    lda #$20
    jsr request_dialogue_transfer_and_conditional_window_flags
    rts

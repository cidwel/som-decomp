; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

publish_active_dialogue_window_style_palette_pair = $05C3
request_dialogue_transfer_and_conditional_window_flags = $0FFA
select_dialogue_window_geometry_from_state = $0D8B

.segment "CODE"
.org $0261
initialize_active_dialogue_window_geometry_and_style:
    jsr select_dialogue_window_geometry_from_state
    .a8
    lda #$04
    sta a:$A16E
    rep #$20
    .a16
    lda #$0100
    sta a:$A18E
    .i16
    ldx #$6480
    lda a:$A16F
    .a16
    and #$00FF
    beq initialize_active_dialogue_window_geometry_and_style_c0027f
    .i16
    ldx #$6580
initialize_active_dialogue_window_geometry_and_style_c0027f:
    stx a:$A18C
    lda a:$A24E
    .a16
    and #$00FF
    asl
    sta a:$A173
    asl
    asl
    asl
    asl
    sec
    sbc a:$A173
    sta a:$A1A2
    lda a:$A24E
    .a16
    and #$00FF
    tax
    lda a:$A24F,X
    .a16
    and #$00FF
    xba
    lsr
    sta a:$A178
    sep #$20
    jsr publish_active_dialogue_window_style_palette_pair
    .a8
    lda #$49
    jsr request_dialogue_transfer_and_conditional_window_flags
    stz a:$A186
    stz a:$A16D
    inc a:$A15C
    rts

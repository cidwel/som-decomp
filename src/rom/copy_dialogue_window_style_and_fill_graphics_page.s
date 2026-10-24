; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

set_dialogue_graphics_transfer_size_preserving_status = $1936

.segment "CODE"
.org $09BA
copy_dialogue_window_style_and_fill_graphics_page:
    .i16
    ldy #$0000
    sty a:$A199
    .i16
    ldy #$9400
    rep #$20
    lda a:$A24E
    .a16
    and #$00FF
    xba
    lsr
    clc
    .a16
    adc #$D080
    tax
    .a16
    lda #$0008
    sta a:$A173
copy_dialogue_window_style_and_fill_graphics_page_c009d8:
    .a16
    lda #$000F
    mvn #$D2, #$7E
    tya
    clc
    adc a:$A199
    tay
    lda a:$A173
    dec
    sta a:$A173
    bne copy_dialogue_window_style_and_fill_graphics_page_c009d8
    sep #$20
    .a8
    lda #$00
    xba
    lda a:$A24E
    tax
    lda a:$A24F,X
    rep #$20
    xba
    lsr
    clc
    .a16
    adc #$D480
    tax
    .a16
    lda #$0008
    sta a:$A173
copy_dialogue_window_style_and_fill_graphics_page_c00a08:
    .a16
    lda #$000F
    mvn #$D2, #$7E
    tya
    clc
    adc a:$A199
    tay
    lda a:$A173
    dec
    sta a:$A173
    bne copy_dialogue_window_style_and_fill_graphics_page_c00a08
    tyx
    .a16
    lda #$00FF
    sta a:$000E,X
    .a16
    lda #$4880
    sta f:$001D06
    .a16
    lda #$0110
    jsr set_dialogue_graphics_transfer_size_preserving_status
    sep #$20
    rts

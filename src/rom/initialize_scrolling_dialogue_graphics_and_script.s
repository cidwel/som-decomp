; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

copy_scrolling_dialogue_script_until_terminator = $0B00
decompress_block_long_call_wrapper = $C10014

.segment "CODE"
.org $091D
initialize_scrolling_dialogue_graphics_and_script:
    .a8
    lda #$7E
    xba
    .a8
    lda #$C7
    .i16
    ldx #$C1C0
    .i16
    ldy #$9400
    jsl f:decompress_block_long_call_wrapper
    rep #$20
    .a16
    lda #$4800
    sta f:$001D06
    .a16
    lda #$0400
    sta f:$001D08
    .a16
    lda #$0800
    sta f:$001D1A
    sep #$20
    lda f:$001D04
    .a8
    ora #$07
    sta f:$001D04
    .i16
    ldx #$0002
    stx a:$A18F
    jsr copy_scrolling_dialogue_script_until_terminator
    inc a:$A161
    rts

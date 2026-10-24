; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $09FA
write_scrolling_dialogue_character_tile:
    ldx a:$A19B
    lda a:$9000,Y
    iny
    .a8
    cmp #$20
    beq write_scrolling_dialogue_character_tile_cc0a0e
    .a8
    cmp #$2E
    beq write_scrolling_dialogue_character_tile_cc0a12
    sec
    .a8
    sbc #$40
    bra write_scrolling_dialogue_character_tile_cc0a14
write_scrolling_dialogue_character_tile_cc0a0e:
    .a8
    lda #$00
    bra write_scrolling_dialogue_character_tile_cc0a14
write_scrolling_dialogue_character_tile_cc0a12:
    .a8
    lda #$1B
write_scrolling_dialogue_character_tile_cc0a14:
    rep #$20
    .a16
    and #$00FF
    asl
    clc
    .a16
    adc #$2100
    sta a:$9400,X
    inx
    inx
    txa
    sta a:$A19B
    sep #$20
    clc
    rts

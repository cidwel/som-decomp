; Recovered Secret of Mana USA routine; behaviour documented in docs/map-graphics-offset-sequencer.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B052
advance_native_graphics_offset_pattern_and_publish_source:
    lda a:$8003,X
    bmi advance_native_graphics_offset_pattern_and_publish_source_c1b05c
    stz $92
    stz $93
    rts
advance_native_graphics_offset_pattern_and_publish_source_c1b05c:
    lda a:$8000,X
    bmi advance_native_graphics_offset_pattern_and_publish_source_c1b0a8
    asl
    bmi advance_native_graphics_offset_pattern_and_publish_source_c1b084
advance_native_graphics_offset_pattern_and_publish_source_c1b064:
    rep #$20
    lda a:$8006,X
    clc
    .a16
    adc #$0080
advance_native_graphics_offset_pattern_and_publish_source_c1b06d:
    .a16
    and #$01FF
    sta a:$8006,X
advance_native_graphics_offset_pattern_and_publish_source_c1b073:
    clc
    adc a:$8002,X
    sta $92
    lda a:$8004,X
    .a16
    ora #$0000
    sta $96
    sep #$20
    rts
advance_native_graphics_offset_pattern_and_publish_source_c1b084:
    lda a:$8001,X
    tay
    inc
    .a8
    cmp #$06
    bcc advance_native_graphics_offset_pattern_and_publish_source_c1b08f
    .a8
    lda #$00
advance_native_graphics_offset_pattern_and_publish_source_c1b08f:
    sta a:$8001,X
    tya
    .a8
    cmp #$04
    bcc advance_native_graphics_offset_pattern_and_publish_source_c1b09f
    bne advance_native_graphics_offset_pattern_and_publish_source_c1b09d
    .a8
    lda #$02
    bra advance_native_graphics_offset_pattern_and_publish_source_c1b09f
advance_native_graphics_offset_pattern_and_publish_source_c1b09d:
    .a8
    lda #$01
advance_native_graphics_offset_pattern_and_publish_source_c1b09f:
    rep #$20
    .a16
    and #$0003
    xba
    lsr
    bra advance_native_graphics_offset_pattern_and_publish_source_c1b073
advance_native_graphics_offset_pattern_and_publish_source_c1b0a8:
    asl
    bmi advance_native_graphics_offset_pattern_and_publish_source_c1b0c8
    lda a:$8001,X
    tay
    inc
    .a8
    cmp #$03
    bcc advance_native_graphics_offset_pattern_and_publish_source_c1b0b6
    .a8
    lda #$00
advance_native_graphics_offset_pattern_and_publish_source_c1b0b6:
    sta a:$8001,X
    .i8
    cpy #$02
    bne advance_native_graphics_offset_pattern_and_publish_source_c1b064
    rep #$20
    lda a:$8006,X
    sec
    .a16
    sbc #$0080
    bra advance_native_graphics_offset_pattern_and_publish_source_c1b06d
advance_native_graphics_offset_pattern_and_publish_source_c1b0c8:
    rep #$20
    lda a:$8006,X
    bne advance_native_graphics_offset_pattern_and_publish_source_c1b064
    sep #$20
    lda a:$8001,X
    bpl advance_native_graphics_offset_pattern_and_publish_source_c1b0e1
    lda $F4
    adc $F5
    .a8
    and #$7F
    sta a:$8001,X
    bra advance_native_graphics_offset_pattern_and_publish_source_c1b064
advance_native_graphics_offset_pattern_and_publish_source_c1b0e1:
    dec
    sta a:$8001,X
    rep #$20
    .a16
    lda #$0000
    bra advance_native_graphics_offset_pattern_and_publish_source_c1b073

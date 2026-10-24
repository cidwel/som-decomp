; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E807
clip_and_emit_ground_shadow_piece:
    ora $98
    sty $02
    ora $0E
    sta $00
    lda $04
    clc
    adc a:$E022,X
    bmi clip_and_emit_ground_shadow_piece_c0e81d
    .a16
    cmp #$00E0
    bcc clip_and_emit_ground_shadow_piece_c0e829
clip_and_emit_ground_shadow_piece_c0e81c:
    rts
clip_and_emit_ground_shadow_piece_c0e81d:
    .a16
    cmp #$FFF0
    bcs clip_and_emit_ground_shadow_piece_c0e829
    adc $C2
    .a16
    cmp #$00E0
    bcs clip_and_emit_ground_shadow_piece_c0e81c
clip_and_emit_ground_shadow_piece_c0e829:
    sep #$20
    sta $08
    rep #$20
    lda $02
    clc
    adc a:$E020,X
    bmi clip_and_emit_ground_shadow_piece_c0e83d
    .a16
    cmp #$0100
    bcc clip_and_emit_ground_shadow_piece_c0e849
clip_and_emit_ground_shadow_piece_c0e83c:
    rts
clip_and_emit_ground_shadow_piece_c0e83d:
    .a16
    cmp #$FFE0
    bcs clip_and_emit_ground_shadow_piece_c0e849
    adc $C0
    .a16
    cmp #$0100
    bcs clip_and_emit_ground_shadow_piece_c0e83c
clip_and_emit_ground_shadow_piece_c0e849:
    sep #$20
    ldy $7C
    .i16
    cpy #$0200
    bcs clip_and_emit_ground_shadow_piece_c0e83c
    sta a:$0800,Y
    lda $08
    sta a:$0801,Y
    xba
    beq clip_and_emit_ground_shadow_piece_c0e86d
    .a8
    lda #$00
    xba
    lda $5A
    tay
    lda a:$0A00,Y
    eor $59
    sta a:$0A00,Y
    ldy $7C
clip_and_emit_ground_shadow_piece_c0e86d:
    rep #$20
    lda $00
    sta a:$0802,Y
    tya
    clc
    .a16
    adc #$0004
    sta $7C
    sep #$20
    lda $59
    asl
    asl
    bcc clip_and_emit_ground_shadow_piece_c0e887
    inc $5A
    .a8
    lda #$01
clip_and_emit_ground_shadow_piece_c0e887:
    sta $59
    rts

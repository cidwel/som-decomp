; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $ACAC
append_or_retire_native_visual_effect_trail_points:
    sep #$20
    lda a:$E117,X
    bne append_or_retire_native_visual_effect_trail_points_c2acb6
    brl append_or_retire_native_visual_effect_trail_points_c2ad0d
append_or_retire_native_visual_effect_trail_points_c2acb6:
    rep #$20
    txa
    lsr
    sta $00
    lda a:$E115,X
    .a16
    and #$00FF
    ora $00
    tay
    phx
    stx $00
    lda a:$E126,X
    .a16
    and #$00FF
    asl
    asl
    clc
    .a16
    adc #$00D0
    ora $00
    tax
    lda a:$C000,Y
    sta a:$E000,X
    lda a:$C002,Y
    sta a:$E002,X
    plx
    sep #$20
    lda a:$E115,X
    clc
    .a8
    adc #$04
    sta a:$E115,X
    lda a:$E126,X
    inc
    .a8
    cmp #$0A
    bcc append_or_retire_native_visual_effect_trail_points_c2acf9
    .a8
    lda #$00
append_or_retire_native_visual_effect_trail_points_c2acf9:
    sta a:$E126,X
    lda a:$E116,X
    inc
    .a8
    cmp #$0B
    bcc append_or_retire_native_visual_effect_trail_points_c2ad06
    .a8
    lda #$0A
append_or_retire_native_visual_effect_trail_points_c2ad06:
    sta a:$E116,X
    dec a:$E117,X
    rts
append_or_retire_native_visual_effect_trail_points_c2ad0d:
    lda a:$E116,X
    dec
    sta a:$E116,X
    bne append_or_retire_native_visual_effect_trail_points_c2ad1d
    stz a:$E114,X
    stz a:$E084,X
    rts
append_or_retire_native_visual_effect_trail_points_c2ad1d:
    pha
    stx $00
    asl
    asl
    sta $00
    lda a:$E115,X
    sec
    sbc $00
    sta $00
    lsr $01
    ldy $00
    pla
    rep #$20
    .a16
    and #$00FF
    phx
append_or_retire_native_visual_effect_trail_points_c2ad37:
    pha
    lda a:$C000,Y
    sta a:$E0D0,X
    lda a:$C002,Y
    sta a:$E0D2,X
    inx
    inx
    inx
    inx
    iny
    iny
    iny
    iny
    pla
    dec
    bne append_or_retire_native_visual_effect_trail_points_c2ad37
    plx
    rts

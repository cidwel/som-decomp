; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

choose_and_copy_floating_number_animated_palette = $8564
clear_sixteen_floating_number_tile_words = $852B
routine_0185e4 = $185E4

.segment "CODE"
.org $8355
advance_floating_number_bounce_hold_and_retirement:
    lda a:$E11F,X
    bne advance_floating_number_bounce_hold_and_retirement_c18376
    lda a:$E11E,X
    clc
    adc a:$E11C,X
    sta a:$E11E,X
    bne advance_floating_number_bounce_hold_and_retirement_c18381
    asl a:$E11C,X
    lda a:$E11D,X
    lsr
    sta a:$E11D,X
    .a8
    cmp #$02
    bcs advance_floating_number_bounce_hold_and_retirement_c18381
    .a8
    lda #$FF
advance_floating_number_bounce_hold_and_retirement_c18376:
    sec
    .a8
    sbc #$07
    sta a:$E11F,X
    bcc advance_floating_number_bounce_hold_and_retirement_c183f9
    bra advance_floating_number_bounce_hold_and_retirement_c183db
    rtl
advance_floating_number_bounce_hold_and_retirement_c18381:
    lda a:$E11E,X
    bpl advance_floating_number_bounce_hold_and_retirement_c18388
    .a8
    eor #$FF
advance_floating_number_bounce_hold_and_retirement_c18388:
    rep #$20
    .a16
    and #$007F
    asl
    asl
    phx
    tax
    lda f:$00FD22,X
    plx
    .a16
    cmp #$0100
    sep #$20
    bcc advance_floating_number_bounce_hold_and_retirement_c1839f
    .a8
    lda #$FF
advance_floating_number_bounce_hold_and_retirement_c1839f:
    sta f:$004202
    lda a:$E11D,X
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    xba
    pha
    .a16
    and #$00FF
    .a16
    eor #$FFFF
    inc
    sta a:$E11A,X
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E11A,X
    sta a:$E11A,X
    pla
    sep #$20
    lsr
    sta a:$E0D1,X
    lsr
    sta a:$E0D9,X
    jsr choose_and_copy_floating_number_animated_palette
    rtl
advance_floating_number_bounce_hold_and_retirement_c183db:
    .a8
    cmp #$38
    bcs advance_floating_number_bounce_hold_and_retirement_c183f5
    lda a:$E0D0,X
    cmp a:$E0D4,X
    beq advance_floating_number_bounce_hold_and_retirement_c183ea
    inc a:$E0D0,X
advance_floating_number_bounce_hold_and_retirement_c183ea:
    lda a:$E0D8,X
    cmp a:$E0D4,X
    beq advance_floating_number_bounce_hold_and_retirement_c183f5
    dec a:$E0D8,X
advance_floating_number_bounce_hold_and_retirement_c183f5:
    jsr choose_and_copy_floating_number_animated_palette
    rtl
advance_floating_number_bounce_hold_and_retirement_c183f9:
    sep #$20
    stz a:$E00C,X
    stz a:$E059,X
    stz a:$E060,X
    stz a:$E084,X
    bit $5C
    bpl advance_floating_number_bounce_hold_and_retirement_c18416
    .i16
    cpx #$0600
    bcc advance_floating_number_bounce_hold_and_retirement_c18416
    .a8
    lda #$01
    sta a:$E001,X
    rtl
advance_floating_number_bounce_hold_and_retirement_c18416:
    .a8
    lda #$01
    sta a:$E00C,X
    stx $14
    jsl f:routine_0185e4
    jsr clear_sixteen_floating_number_tile_words
    rtl

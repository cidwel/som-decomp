; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_map_palette_fixed_source_ramp = $BD38
prepare_map_palette_target_ramp = $BD48
scan_map_palette_animation_color_span = $BEB1

.segment "CODE"
.org $BCD9
decode_map_palette_animation_record:
    pha
    bpl decode_map_palette_animation_record_c2bceb
    inx
    lda f:$C8087B,X
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
decode_map_palette_animation_record_c2bceb:
    pla
    pha
    .a8
    and #$07
    asl
    asl
    asl
    asl
    asl
    sta a:$D204,Y
    .a8
    lda #$00
    sta a:$D205,Y
    pla
    lsr
    lsr
    lsr
    pha
    .a8
    and #$03
    sta a:$D202,Y
    sta a:$D203,Y
    rep #$20
    .a16
    lda #$0000
    sta a:$D206,Y
    lda f:$004216
    clc
    adc f:$C80800
    sta a:$D208,Y
    sep #$20
    .a8
    lda #$00
    sta a:$D201,Y
    pla
    lsr
    lsr
    sta a:$D200,Y
    .a8
    cmp #$04
    beq prepare_map_palette_target_ramp
    .a8
    cmp #$03
    beq prepare_map_palette_fixed_source_ramp
    bcs decode_map_palette_animation_record_c2bd37
    jmp scan_map_palette_animation_color_span
decode_map_palette_animation_record_c2bd37:
    rts

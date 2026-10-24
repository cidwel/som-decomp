; Recovered Secret of Mana USA routine; behaviour documented in docs/map-graphics-runtime-animation.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_animation_record_by_motion_type = $C026

.segment "CODE"
.org $BFE0
advance_timed_map_graphics_animation_records:
    sep #$30
    lda $9A
    bne advance_timed_map_graphics_animation_records_c1bfe7
    rtl
advance_timed_map_graphics_animation_records_c1bfe7:
    .a8
    and #$0F
    sta $00
    phb
    .a8
    lda #$7F
    sta $04
    pha
    plb
    stz $01
advance_timed_map_graphics_animation_records_c1bff4:
    sep #$30
    ldx $01
    .a8
    lda #$00
    sta a:$8200,X
    dec a:$8208,X
    bpl advance_timed_map_graphics_animation_records_c1c013
    lda a:$8209,X
    sta a:$8208,X
    inc a:$8200,X
    ldy a:$8201,X
    jsr advance_map_graphics_animation_record_by_motion_type
    sep #$30
advance_timed_map_graphics_animation_records_c1c013:
    lda $01
    clc
    .a8
    adc #$10
    sta $01
    dec $00
    bne advance_timed_map_graphics_animation_records_c1bff4
    plb
    lda $9A
    .a8
    ora #$80
    sta $9A
    rtl

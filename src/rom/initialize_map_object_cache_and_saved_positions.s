; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

copy_map_object_record_to_cache = $DD55

.segment "CODE"
.org $DCFC
initialize_map_object_cache_and_saved_positions:
    rep #$10
    sep #$20
    .i16
    ldx #$0000
    stz $BD
    lda $BC
    sta $04
    bne initialize_map_object_cache_and_saved_positions_c0dd10
    .a8
    lda #$80
    trb $E8
    rts
initialize_map_object_cache_and_saved_positions_c0dd10:
    jsr copy_map_object_record_to_cache
    rep #$20
    lda $0D
    clc
    .a16
    adc #$0008
    sta $0D
    txa
    clc
    .a16
    adc #$0010
    tax
    sep #$20
    dec $04
    bne initialize_map_object_cache_and_saved_positions_c0dd10
    .a8
    lda #$80
    trb $E8
    bne initialize_map_object_cache_and_saved_positions_c0dd30
    rts
initialize_map_object_cache_and_saved_positions_c0dd30:
    rep #$20
    .i16
    ldx #$0000
    txy
initialize_map_object_cache_and_saved_positions_c0dd36:
    lda a:$CD70,Y
    sta a:$C80A,X
    sep #$20
    lda a:$CD72,Y
    sta a:$C80C,X
    rep #$20
    txa
    clc
    .a16
    adc #$0010
    tax
    iny
    iny
    iny
    .i16
    cpy #$0090
    bcc initialize_map_object_cache_and_saved_positions_c0dd36
    rts

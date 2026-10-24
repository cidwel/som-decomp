; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

set_map_layer_packed_parameters = $A7D5

.segment "CODE"
.org $A765
set_map_layer_nibble_parameters:
    .a8
    and #$0F
    beq set_map_layer_nibble_parameters_c2a799
    .a8
    cmp #$08
    beq set_map_layer_nibble_parameters_c2a79a
    bcc set_map_layer_nibble_parameters_c2a776
    pha
    .a8
    lda #$80
    sta a:$0A85,Y
    pla
set_map_layer_nibble_parameters_c2a776:
    pha
    .a8
    lda #$02
    sta a:$0A82,Y
    pla
    .a8
    and #$07
    dec
    bne set_map_layer_nibble_parameters_c2a788
    .a8
    lda #$55
    sta a:$0A86,Y
    rts
set_map_layer_nibble_parameters_c2a788:
    dec
    bne set_map_layer_nibble_parameters_c2a790
    .a8
    lda #$80
    sta a:$0A86,Y
set_map_layer_nibble_parameters_c2a790:
    .a8
    cmp #$05
    bne set_map_layer_nibble_parameters_c2a796
    .a8
    lda #$08
set_map_layer_nibble_parameters_c2a796:
    sta a:$0A87,Y
set_map_layer_nibble_parameters_c2a799:
    rts
set_map_layer_nibble_parameters_c2a79a:
    .a8
    lda #$01
    sta a:$0A82,Y
    sep #$10
    rep #$20
    lda $F4
    inc $F4
    .a16
    and #$13FF
    jmp set_map_layer_packed_parameters

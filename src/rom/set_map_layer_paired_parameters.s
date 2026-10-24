; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

set_map_layer_packed_parameters = $A7D5

.segment "CODE"
.org $A7AD
set_map_layer_paired_parameters:
    .a8
    and #$0F
    asl
    phx
    rep #$20
    lda f:$480000,X
    jsr set_map_layer_packed_parameters
    rep #$20
    tya
    clc
    .a16
    adc #$0010
    tay
    lda f:$480002,X
    jsr set_map_layer_packed_parameters
    sep #$20
    .a8
    lda #$03
    sta a:$0A82,Y
    sta a:$0A92,Y
    plx
    rts

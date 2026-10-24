; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

set_map_layer_nibble_parameters = $A765
set_map_layer_paired_parameters = $A7AD

.segment "CODE"
.org $A6C9
initialize_map_layer_records:
    sep #$30
    .a8
    lda #$00
    tax
initialize_map_layer_records_c2a6ce:
    sta a:$0A80,X
    inx
    .i8
    cpx #$40
    bcc initialize_map_layer_records_c2a6ce
    lda $80
    asl
    asl
    tax
    lda f:$C80000,X
    ldy $9C
    bne initialize_map_layer_records_c2a6e5
    .a8
    and #$F0
initialize_map_layer_records_c2a6e5:
    ldy $A0
    bne initialize_map_layer_records_c2a6eb
    .a8
    and #$0F
initialize_map_layer_records_c2a6eb:
    sta $80
    .a8
    and #$03
    sta a:$0A80
    lda $80
    lsr
    lsr
    .a8
    and #$03
    sta a:$0A90
    lda $80
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$03
    sta a:$0AA0
    lda $80
    asl
    rol
    rol
    .a8
    and #$03
    sta a:$0AB0
    .i8
    ldy #$00
    lda $9C
    beq initialize_map_layer_records_c2a739
    lda f:$C80003,X
    .a8
    and #$0F
    beq initialize_map_layer_records_c2a723
    jsr set_map_layer_paired_parameters
    bra initialize_map_layer_records_c2a739
initialize_map_layer_records_c2a723:
    lda f:$C80001,X
    .a8
    and #$0F
    jsr set_map_layer_nibble_parameters
    .i8
    ldy #$10
    lda f:$C80001,X
    lsr
    lsr
    lsr
    lsr
    jsr set_map_layer_nibble_parameters
initialize_map_layer_records_c2a739:
    .i8
    ldy #$20
    lda $A0
    beq initialize_map_layer_records_c2a764
    lda f:$C80003,X
    lsr
    lsr
    lsr
    lsr
    beq initialize_map_layer_records_c2a74e
    jsr set_map_layer_paired_parameters
    bra initialize_map_layer_records_c2a764
initialize_map_layer_records_c2a74e:
    lda f:$C80002,X
    .a8
    and #$0F
    jsr set_map_layer_nibble_parameters
    .i8
    ldy #$30
    lda f:$C80002,X
    lsr
    lsr
    lsr
    lsr
    jsr set_map_layer_nibble_parameters
initialize_map_layer_records_c2a764:
    rts

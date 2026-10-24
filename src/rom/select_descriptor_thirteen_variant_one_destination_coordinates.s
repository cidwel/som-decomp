; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6834
select_descriptor_thirteen_variant_one_destination_coordinates:
    ldx $87
    lda a:$007E,X
    bne select_descriptor_thirteen_variant_one_destination_coordinates_c26848
    lda f:$DCE39C
    sta $9D
    lda f:$DCE39E
    sta $A1
    rts
select_descriptor_thirteen_variant_one_destination_coordinates_c26848:
    .a16
    bit #$0020
    bne select_descriptor_thirteen_variant_one_destination_coordinates_c26862
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$DCE3B8,X
    sta $9D
    lda f:$DCE3BA,X
    sta $A1
    ldx $87
    rts
select_descriptor_thirteen_variant_one_destination_coordinates_c26862:
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$DCE3D8,X
    sta $9D
    lda f:$DCE3DA,X
    sta $A1
    ldx $87
    rts

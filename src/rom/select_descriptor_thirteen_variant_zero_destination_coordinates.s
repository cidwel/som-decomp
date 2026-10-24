; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $67F1
select_descriptor_thirteen_variant_zero_destination_coordinates:
    ldx $87
    lda a:$007E,X
    bne select_descriptor_thirteen_variant_zero_destination_coordinates_c26805
    lda f:$DCE398
    sta $9D
    lda f:$DCE39A
    sta $A1
    rts
select_descriptor_thirteen_variant_zero_destination_coordinates_c26805:
    .a16
    bit #$0020
    bne select_descriptor_thirteen_variant_zero_destination_coordinates_c2681f
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$DCE3A0,X
    sta $9D
    lda f:$DCE3A2,X
    sta $A1
    ldx $87
    rts
select_descriptor_thirteen_variant_zero_destination_coordinates_c2681f:
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$DCE3D0,X
    sta $9D
    lda f:$DCE3D2,X
    sta $A1
    ldx $87
    rts

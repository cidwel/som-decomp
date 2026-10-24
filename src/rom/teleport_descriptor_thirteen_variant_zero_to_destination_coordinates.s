; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6907
teleport_descriptor_thirteen_variant_zero_to_destination_coordinates:
    ldx $87
    lda a:$007E,X
    bne teleport_descriptor_thirteen_variant_zero_to_destination_coordinates_c2691d
    lda f:$DCE398
    sta a:$002B,X
    lda f:$DCE39A
    sta a:$0032,X
    rts
teleport_descriptor_thirteen_variant_zero_to_destination_coordinates_c2691d:
    .a16
    bit #$0020
    bne teleport_descriptor_thirteen_variant_zero_to_destination_coordinates_c26941
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$DCE3A0,X
    sta $95
    lda f:$DCE3A2,X
    sta $97
    ldx $87
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    rts
teleport_descriptor_thirteen_variant_zero_to_destination_coordinates_c26941:
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$DCE3D0,X
    sta $95
    lda f:$DCE3D2,X
    sta $97
    ldx $87
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    rts

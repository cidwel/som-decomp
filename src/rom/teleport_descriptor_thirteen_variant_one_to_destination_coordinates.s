; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6960
teleport_descriptor_thirteen_variant_one_to_destination_coordinates:
    ldx $87
    lda a:$007E,X
    bne teleport_descriptor_thirteen_variant_one_to_destination_coordinates_c26976
    lda f:$DCE39C
    sta a:$002B,X
    lda f:$DCE39E
    sta a:$0032,X
    rts
teleport_descriptor_thirteen_variant_one_to_destination_coordinates_c26976:
    .a16
    bit #$0020
    bne teleport_descriptor_thirteen_variant_one_to_destination_coordinates_c2699a
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$DCE3B8,X
    sta $95
    lda f:$DCE3BA,X
    sta $97
    ldx $87
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    rts
teleport_descriptor_thirteen_variant_one_to_destination_coordinates_c2699a:
    .a16
    and #$000F
    asl
    asl
    tax
    lda f:$DCE3D8,X
    sta $95
    lda f:$DCE3DA,X
    sta $97
    ldx $87
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    rts

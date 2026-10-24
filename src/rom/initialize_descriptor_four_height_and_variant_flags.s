; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6B1B
initialize_descriptor_four_height_and_variant_flags:
    .a16
    lda #$0040
    sta a:$0066,X
    lda a:$0042,X
    beq initialize_descriptor_four_height_and_variant_flags_c26b32
    lda a:$0098,X
    .a16
    and #$FFFC
    .a16
    ora #$0001
    sta a:$0098,X
initialize_descriptor_four_height_and_variant_flags_c26b32:
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $70B3
initialize_descriptor_seven_height_and_variant_two_field:
    .a16
    lda #$0020
    sta a:$0066,X
    lda a:$0042,X
    .a16
    cmp #$0002
    bne initialize_descriptor_seven_height_and_variant_two_field_c270c4
    stz a:$004C,X
initialize_descriptor_seven_height_and_variant_two_field_c270c4:
    rts

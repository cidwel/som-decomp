; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4628
derive_native54_part_spawn_position_from_variant_and_offset:
    sta $95
    lda a:$0042,X
    asl
    asl
    asl
    clc
    adc $95
    tax
    lda f:$C24643,X
    sta $95
    lda f:$C24645,X
    sta $97
    ldx $87
    rts

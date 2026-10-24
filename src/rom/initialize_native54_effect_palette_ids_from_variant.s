; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $50C8
initialize_native54_effect_palette_ids_from_variant:
    ldx $87
    inc a:$0094,X
    lda a:$0042,X
    asl
    asl
    clc
    adc a:$0042,X
    clc
    .a16
    adc #$0022
    sta a:$00B0,X
    lda a:$0042,X
    asl
    asl
    clc
    adc a:$0042,X
    .a16
    adc #$0020
    sta a:$00B2,X
    clc
    rts

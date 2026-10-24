; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-sprite-publish-wrapper.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb53d = $B53D

.segment "CODE"
.org $B7B9
publish_native_sprite_record_with_data_bank_7f:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    jsr routine_7eb53d
    plb
    plp
    pld
    rts

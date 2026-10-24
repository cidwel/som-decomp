; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-stopped-image-source.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e9660 = $9660
routine_7eabe7 = $ABE7

.segment "CODE"
.org $9675
finish_native_stopped_title_image_task:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .i16
    ldx #$0001
    jsr routine_7eabe7
    jsr routine_7e9660
    plb
    plp
    pld
    rtl

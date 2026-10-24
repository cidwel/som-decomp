; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B00D
await_survey_nmi_and_clear_complete_vram_page:
    sep #$20
    .a8
    lda #$80
    sta $0E
    sta a:$2115
await_survey_nmi_and_clear_complete_vram_page_c0b016:
    bit $0E
    bne await_survey_nmi_and_clear_complete_vram_page_c0b016
    rep #$20
    stz $00
    stz a:$2116
    stz a:$4372
    .a16
    lda #$1809
    sta a:$4370
    .a16
    lda #$1000
    sta a:$4375
    sep #$20
    stz a:$4374
    .a8
    lda #$80
    sta a:$420B
    .a8
    lda #$FF
    sta $0F
    rts

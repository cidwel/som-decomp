; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_destination_fade = $8B09

.segment "CODE"
.org $BC01
request_destination_fade:
    jsr prepare_destination_fade
    sep #$20
    .a8
    lda #$81
    sta $FF
    rtl

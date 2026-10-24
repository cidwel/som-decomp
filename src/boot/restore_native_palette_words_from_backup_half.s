; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-palette-apis.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ec3bf = $C3BF

.segment "CODE"
.org $BE3C
restore_native_palette_words_from_backup_half:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    txa
    clc
    .a16
    adc #$0200
    txy
    tax
    .a16
    lda #$0020
    jsr routine_7ec3bf
    plb
    plp
    pld
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-random-byte-copies.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c00018 = $C00018

.segment "CODE"
.org $275A
draw_native_random_byte_with_wram_bank_copy_one:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    jsl f:routine_c00018
    plb
    plp
    pld
    rts

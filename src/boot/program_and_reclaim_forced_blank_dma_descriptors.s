; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-title-hdma-resources.md.
.setcpu "65816"
.smart
.a8
.i16

cleanup_processed_transfers = $92E9
program_dma_descriptor_pass = $91B8

.segment "CODE"
.org $91A2
program_and_reclaim_forced_blank_dma_descriptors:
    phd
    php
    rep #$30
    lda a:$006C
    sta a:$006E
    .a16
    lda #$0107
    jsr program_dma_descriptor_pass
    jsr cleanup_processed_transfers
    plp
    pld
    rts

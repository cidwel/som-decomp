; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-recycle-ppu-record.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C077
recycle_native_allocated_ppu_record_to_free_head:
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
    beq recycle_native_allocated_ppu_record_to_free_head_c093
    php
    sei
    lda a:$02D8
    sta a:$0000,X
    stx a:$02D8
    plp
recycle_native_allocated_ppu_record_to_free_head_c093:
    plb
    plp
    pld
    rts

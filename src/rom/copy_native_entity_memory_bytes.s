; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-queue.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4761
copy_native_entity_memory_bytes:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    .a16
    cmp #$0000
    beq copy_native_entity_memory_bytes_c14796
    .a16
    bit #$0001
    beq copy_native_entity_memory_bytes_c14785
    pha
    sep #$20
    lda a:$0000,X
    sta a:$0000,Y
    rep #$20
    inx
    iny
    pla
    dec
    beq copy_native_entity_memory_bytes_c14796
copy_native_entity_memory_bytes_c14785:
    lsr
    sta $01
copy_native_entity_memory_bytes_c14788:
    lda a:$0000,X
    sta a:$0000,Y
    inx
    inx
    iny
    iny
    dec $01
    bne copy_native_entity_memory_bytes_c14788
copy_native_entity_memory_bytes_c14796:
    sep #$20
    pla
    pla
    plp
    pld
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-memory.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4738
fill_native_entity_memory_bytes:
    phd
    php
    rep #$30
    sep #$20
    pha
    sta a:$0000,X
    tya
    .a8
    and #$01
    beq fill_native_entity_memory_bytes_c1474b
    inx
    dey
    beq fill_native_entity_memory_bytes_c1475b
fill_native_entity_memory_bytes_c1474b:
    lda $01,S
    xba
    lda $01,S
    rep #$20
fill_native_entity_memory_bytes_c14752:
    sta a:$0000,X
    inx
    inx
    dey
    dey
    bne fill_native_entity_memory_bytes_c14752
fill_native_entity_memory_bytes_c1475b:
    sep #$20
    pla
    plp
    pld
    rts

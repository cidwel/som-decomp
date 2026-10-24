; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-cast-queue-initialize.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $38CE
clear_cast_queues_and_seed_fifteen_byte_random_pool:
    phd
    phb
    php
    rep #$30
    pha
    .a16
    lda #$0300
    tcd
    .a16
    lda #$0000
    .i16
    ldx #$0000
    .i16
    ldy #$0010
clear_cast_queues_and_seed_fifteen_byte_random_pool_c038e1:
    sta a:$0380,X
    sta a:$03A0,X
    sta a:$03C0,X
    sta a:$03E0,X
    inx
    inx
    dey
    bne clear_cast_queues_and_seed_fifteen_byte_random_pool_c038e1
    .i16
    ldx #$FE00
    .i16
    ldy #$0063
clear_cast_queues_and_seed_fifteen_byte_random_pool_c038f8:
    sta a:$0000,X
    inx
    inx
    dey
    bne clear_cast_queues_and_seed_fifteen_byte_random_pool_c038f8
    pla
    sta $B4
    bne clear_cast_queues_and_seed_fifteen_byte_random_pool_c03908
    .a16
    lda #$7524
clear_cast_queues_and_seed_fifteen_byte_random_pool_c03908:
    sta $B4
clear_cast_queues_and_seed_fifteen_byte_random_pool_c0390a:
    .i16
    ldx #$03F1
    sep #$20
    .a8
    lda #$0F
    sta $B2
clear_cast_queues_and_seed_fifteen_byte_random_pool_c03913:
    rep #$20
    lda $B4
    .a16
    and #$4001
    beq clear_cast_queues_and_seed_fifteen_byte_random_pool_c0392b
    .a16
    eor #$4001
    beq clear_cast_queues_and_seed_fifteen_byte_random_pool_c0392b
    lda $B4
    .a16
    ora #$8000
    lsr
    sta $B4
    bra clear_cast_queues_and_seed_fifteen_byte_random_pool_c03930
clear_cast_queues_and_seed_fifteen_byte_random_pool_c0392b:
    lda $B4
    lsr
    sta $B4
clear_cast_queues_and_seed_fifteen_byte_random_pool_c03930:
    .a16
    bit #$0001
    beq clear_cast_queues_and_seed_fifteen_byte_random_pool_c03913
    lsr
    sep #$20
    sta a:$0000,X
    inx
    dec $B2
    bne clear_cast_queues_and_seed_fifteen_byte_random_pool_c03913
    sep #$20
    .i16
    ldx #$03F1
    .a8
    lda #$0F
    sta $B2
    .a8
    lda #$00
clear_cast_queues_and_seed_fifteen_byte_random_pool_c0394b:
    ora a:$0000,X
    inx
    dec $B2
    bne clear_cast_queues_and_seed_fifteen_byte_random_pool_c0394b
    .a8
    cmp #$FF
    bne clear_cast_queues_and_seed_fifteen_byte_random_pool_c0390a
    stz a:$03F0
    plp
    plb
    pld
    rtl

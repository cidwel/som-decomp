; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-task-resources.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C2D9
seed_fifteen_native_random_bytes_from_saved_slot_counters:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    txa
    bne seed_fifteen_native_random_bytes_from_saved_slot_counters_c2f3
    .a16
    lda #$7524
seed_fifteen_native_random_bytes_from_saved_slot_counters_c2f3:
    sta $03
seed_fifteen_native_random_bytes_from_saved_slot_counters_c2f5:
    .i16
    ldx #$02E5
    sep #$20
    .a8
    lda #$0F
    sta $01
seed_fifteen_native_random_bytes_from_saved_slot_counters_c2fe:
    rep #$20
    lda $03
    .a16
    and #$4001
    beq seed_fifteen_native_random_bytes_from_saved_slot_counters_c316
    .a16
    eor #$4001
    beq seed_fifteen_native_random_bytes_from_saved_slot_counters_c316
    lda $03
    .a16
    ora #$8000
    lsr
    sta $03
    bra seed_fifteen_native_random_bytes_from_saved_slot_counters_c31b
seed_fifteen_native_random_bytes_from_saved_slot_counters_c316:
    lda $03
    lsr
    sta $03
seed_fifteen_native_random_bytes_from_saved_slot_counters_c31b:
    .a16
    bit #$0001
    beq seed_fifteen_native_random_bytes_from_saved_slot_counters_c2fe
    lsr
    sep #$20
    sta a:$0000,X
    inx
    dec $01
    bne seed_fifteen_native_random_bytes_from_saved_slot_counters_c2fe
    sep #$20
    .i16
    ldx #$02E5
    .a8
    lda #$0F
    sta $01
    .a8
    lda #$00
seed_fifteen_native_random_bytes_from_saved_slot_counters_c336:
    ora a:$0000,X
    inx
    dec $01
    bne seed_fifteen_native_random_bytes_from_saved_slot_counters_c336
    .a8
    cmp #$FF
    bne seed_fifteen_native_random_bytes_from_saved_slot_counters_c2f5
    stz a:$02E4
    plb
    pla
    pla
    pla
    pla
    plp
    pld
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-owner-records-release.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0d6 = $B0D6
routine_7ed678 = $D678

.segment "CODE"
.org $801A
release_native_eight_resource_owner_records:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldy a:$0016
    beq release_native_eight_resource_owner_records_8059
    .a8
    lda #$08
    sta $01
release_native_eight_resource_owner_records_8031:
    ldx a:$0006,Y
    beq release_native_eight_resource_owner_records_803b
    phy
    jsr routine_7eb0d6
    ply
release_native_eight_resource_owner_records_803b:
    lda a:$0000,Y
    beq release_native_eight_resource_owner_records_8045
    phy
    jsr routine_7ed678
    ply
release_native_eight_resource_owner_records_8045:
    clc
    rep #$20
    tya
    .a16
    adc #$0008
    tay
    sep #$20
    dec $01
    bne release_native_eight_resource_owner_records_8031
    ldx a:$0016
    jsr routine_7eb0d6
release_native_eight_resource_owner_records_8059:
    plb
    pla
    pla
    plp
    pld
    rts

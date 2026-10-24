; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-resource-ppu.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097

.segment "CODE"
.org $BFDA
queue_thirty_eight_native_boot_ppu_defaults_from_loaded_descriptor:
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
    .i16
    ldx #$6072
    stx $02
    .a8
    lda #$7E
    sta $04
    .a8
    lda #$26
    sta $01
queue_thirty_eight_native_boot_ppu_defaults_from_loaded_descriptor_bff9:
    lda [$02]
    jsr allocate_ppu_register_entry
    .i16
    ldy #$0001
    lda [$02],Y
    sta a:$0002,X
    stz a:$0003,X
    jsr append_oneshot_ppu_entry
    ldx $02
    inx
    inx
    stx $02
    dec $01
    bne queue_thirty_eight_native_boot_ppu_defaults_from_loaded_descriptor_bff9
    plb
    pla
    pla
    pla
    pla
    plp
    pld
    rts

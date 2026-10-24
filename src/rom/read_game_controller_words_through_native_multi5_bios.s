; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-inputs.md.
.setcpu "65816"
.smart
.a8
.i16

detect_native_multi5_interfaces_from_serial_probes = $FE70
read_native_multi5_auto_and_serial_controller_fields = $FF2A

.segment "CODE"
.org $FE00
read_game_controller_words_through_native_multi5_bios:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0014
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    jsr detect_native_multi5_interfaces_from_serial_probes
    lda $01
    .a8
    bit #$40
    rep #$20
    beq read_game_controller_words_through_native_multi5_bios_cffe34
    jsr read_native_multi5_auto_and_serial_controller_fields
    lda $0A
    sta a:$0042
    lda $08
    sta a:$0044
    lda $06
    sta a:$0046
    .a16
    lda #$FFFF
    bra read_game_controller_words_through_native_multi5_bios_cffe46
read_game_controller_words_through_native_multi5_bios_cffe34:
    lda a:$4218
    sta a:$0042
    lda a:$421A
    sta a:$0044
    .a16
    lda #$0000
    sta a:$0046
read_game_controller_words_through_native_multi5_bios_cffe46:
    plb
    sta $13,S
    tsc
    clc
    .a16
    adc #$0012
    tcs
    pla
    plp
    pld
    rtl

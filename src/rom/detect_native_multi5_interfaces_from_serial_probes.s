; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-inputs.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FE70
detect_native_multi5_interfaces_from_serial_probes:
    php
    sep #$30
    stz $01
detect_native_multi5_interfaces_from_serial_probes_cffe75:
    lda a:$4212
    .a8
    and #$01
    bne detect_native_multi5_interfaces_from_serial_probes_cffe75
    stz a:$4016
    .a8
    lda #$01
    sta a:$4016
    .i8
    ldx #$08
detect_native_multi5_interfaces_from_serial_probes_cffe86:
    lda a:$4016
    lsr
    lsr
    rol $12
    lda a:$4017
    lsr
    lsr
    rol $14
    dex
    bne detect_native_multi5_interfaces_from_serial_probes_cffe86
    stz a:$4016
    .i8
    ldx #$08
detect_native_multi5_interfaces_from_serial_probes_cffe9c:
    lda a:$4016
    lsr
    lsr
    rol $11
    lda a:$4017
    lsr
    lsr
    rol $13
    dex
    bne detect_native_multi5_interfaces_from_serial_probes_cffe9c
    lda $12
    .a8
    cmp #$FF
    bne detect_native_multi5_interfaces_from_serial_probes_cffebd
    lda $11
    .a8
    cmp #$FF
    beq detect_native_multi5_interfaces_from_serial_probes_cffebd
    .a8
    lda #$80
    sta $01
detect_native_multi5_interfaces_from_serial_probes_cffebd:
    lda $14
    .a8
    cmp #$FF
    bne detect_native_multi5_interfaces_from_serial_probes_cffecf
    lda $13
    .a8
    cmp #$FF
    beq detect_native_multi5_interfaces_from_serial_probes_cffecf
    .a8
    lda #$40
    ora $01
    sta $01
detect_native_multi5_interfaces_from_serial_probes_cffecf:
    plp
    rts

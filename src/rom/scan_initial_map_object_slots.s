; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_map_object_load_window = $E0EB
scan_map_object_cache_for_creation = $DDBE

.segment "CODE"
.org $DD8B
scan_initial_map_object_slots:
    sep #$20
    .i16
    ldx #$0600
    sep #$20
    lda $ED
    asl
    .a8
    lda #$09
    bcc scan_initial_map_object_slots_c0dd9b
    .a8
    lda #$03
scan_initial_map_object_slots_c0dd9b:
    .i16
    ldy #$0000
scan_initial_map_object_slots_c0dd9e:
    pha
    lda $BC
    sta $0C
    phy
    jsr prepare_map_object_load_window
    jsr scan_map_object_cache_for_creation
    rep #$20
    ply
    txa
    clc
    .a16
    adc #$0200
    tax
    sep #$20
    pla
    bit $5C
    bmi scan_initial_map_object_slots_c0ddbd
    dec
    bne scan_initial_map_object_slots_c0dd9e
scan_initial_map_object_slots_c0ddbd:
    rts

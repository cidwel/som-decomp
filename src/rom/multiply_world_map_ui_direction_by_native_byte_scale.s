; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $92E8
multiply_world_map_ui_direction_by_native_byte_scale:
    tay
    sty a:$4202
    ldx $32
    stx a:$4203
    nop
    ldx $33
    beq multiply_world_map_ui_direction_by_native_byte_scale_c092f8
    sty $00
multiply_world_map_ui_direction_by_native_byte_scale_c092f8:
    ldx a:$4217
    txa
    ldx $30
    stx a:$4203
    rep #$20
    clc
    adc $00
    bit $4B
    bpl multiply_world_map_ui_direction_by_native_byte_scale_c0930e
    .a16
    eor #$FFFF
    inc
multiply_world_map_ui_direction_by_native_byte_scale_c0930e:
    asl
    sta $36
    .i8
    ldx #$00
    stx $00
    ldx $31
    beq multiply_world_map_ui_direction_by_native_byte_scale_c0931b
    sty $00
multiply_world_map_ui_direction_by_native_byte_scale_c0931b:
    ldx a:$4217
    txa
    clc
    adc $00
    bit $4B
    bvs multiply_world_map_ui_direction_by_native_byte_scale_c0932a
    .a16
    eor #$FFFF
    inc
multiply_world_map_ui_direction_by_native_byte_scale_c0932a:
    asl
    sta $38
    .i8
    ldx #$80
    stx $60
    rts

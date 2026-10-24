; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_linear_map_layer_motion = $DB9E
advance_sine_map_layer_motion = $DB48

.segment "CODE"
.org $DB1E
advance_all_automatic_map_layer_motion:
    sep #$30
    .i8
    ldx #$00
advance_all_automatic_map_layer_motion_c0db22:
    lda a:$0A82,X
    beq advance_all_automatic_map_layer_motion_c0db3c
    .a8
    cmp #$01
    bne advance_all_automatic_map_layer_motion_c0db30
    jsr advance_sine_map_layer_motion
    bra advance_all_automatic_map_layer_motion_c0db3c
advance_all_automatic_map_layer_motion_c0db30:
    .a8
    cmp #$02
    bne advance_all_automatic_map_layer_motion_c0db39
    jsr advance_linear_map_layer_motion
    bra advance_all_automatic_map_layer_motion_c0db3c
advance_all_automatic_map_layer_motion_c0db39:
    jsr advance_sine_map_layer_motion
advance_all_automatic_map_layer_motion_c0db3c:
    sep #$30
    txa
    clc
    .a8
    adc #$10
    tax
    .a8
    cmp #$40
    bcc advance_all_automatic_map_layer_motion_c0db22
    rts

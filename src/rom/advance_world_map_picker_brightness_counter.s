; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A6D4
advance_world_map_picker_brightness_counter:
    tax
    bmi advance_world_map_picker_brightness_counter_c0a6de
    inc
    .a8
    and #$3F
    sta $0C
    bra advance_world_map_picker_brightness_counter_c0a6e4
advance_world_map_picker_brightness_counter_c0a6de:
    inc
    sta $0C
    bne advance_world_map_picker_brightness_counter_c0a6e4
    rts
advance_world_map_picker_brightness_counter_c0a6e4:
    txa
    .a8
    cmp #$80
    bcc advance_world_map_picker_brightness_counter_c0a6eb
    .a8
    eor #$FF
advance_world_map_picker_brightness_counter_c0a6eb:
    .a8
    cmp #$40
    bcs advance_world_map_picker_brightness_counter_c0a6f4
    lsr
    lsr
    sta a:$2100
advance_world_map_picker_brightness_counter_c0a6f4:
    rts

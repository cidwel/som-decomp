.setcpu "65816"
.segment "CODE"
.org $7341
map_control_0c7341:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count

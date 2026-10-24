.setcpu "65816"
.segment "CODE"
.org $8702
map_control_0c8702:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count

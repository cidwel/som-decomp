.setcpu "65816"
.segment "CODE"
.org $8086
map_control_0f8086:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count

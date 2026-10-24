.setcpu "65816"
.segment "CODE"
.org $3086
map_control_0c3086:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $2A4B
map_control_0e2a4b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

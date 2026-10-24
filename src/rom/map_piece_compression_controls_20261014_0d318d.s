.setcpu "65816"
.segment "CODE"
.org $318D
map_control_0d318d:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

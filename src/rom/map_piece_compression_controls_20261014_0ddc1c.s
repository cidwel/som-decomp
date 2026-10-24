.setcpu "65816"
.segment "CODE"
.org $DC1C
map_control_0ddc1c:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $AC61
map_control_0fac61:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

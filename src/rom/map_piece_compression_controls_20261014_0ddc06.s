.setcpu "65816"
.segment "CODE"
.org $DC06
map_control_0ddc06:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $571D
map_control_0e571d:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

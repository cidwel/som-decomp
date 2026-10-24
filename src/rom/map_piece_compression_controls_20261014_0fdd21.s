.setcpu "65816"
.segment "CODE"
.org $DD21
map_control_0fdd21:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

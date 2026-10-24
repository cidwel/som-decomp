.setcpu "65816"
.segment "CODE"
.org $A8DA
map_control_0da8da:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

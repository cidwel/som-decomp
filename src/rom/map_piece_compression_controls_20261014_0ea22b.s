.setcpu "65816"
.segment "CODE"
.org $A22B
map_control_0ea22b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

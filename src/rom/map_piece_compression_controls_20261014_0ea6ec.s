.setcpu "65816"
.segment "CODE"
.org $A6EC
map_control_0ea6ec:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

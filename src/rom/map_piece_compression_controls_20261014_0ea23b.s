.setcpu "65816"
.segment "CODE"
.org $A23B
map_control_0ea23b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

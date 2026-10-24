.setcpu "65816"
.segment "CODE"
.org $A233
map_control_0ea233:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

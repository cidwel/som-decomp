.setcpu "65816"
.segment "CODE"
.org $A92E
map_control_0ea92e:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

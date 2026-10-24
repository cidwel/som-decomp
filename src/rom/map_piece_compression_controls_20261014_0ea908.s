.setcpu "65816"
.segment "CODE"
.org $A908
map_control_0ea908:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

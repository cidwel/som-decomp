.setcpu "65816"
.segment "CODE"
.org $2AA6
map_control_0f2aa6:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

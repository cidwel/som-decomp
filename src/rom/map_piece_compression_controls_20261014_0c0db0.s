.setcpu "65816"
.segment "CODE"
.org $0DB0
map_control_0c0db0:
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count

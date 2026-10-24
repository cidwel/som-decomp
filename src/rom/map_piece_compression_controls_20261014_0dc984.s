.setcpu "65816"
.segment "CODE"
.org $C984
map_control_0dc984:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $0AB8
map_control_0f0ab8:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count

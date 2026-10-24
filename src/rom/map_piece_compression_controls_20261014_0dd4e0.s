.setcpu "65816"
.segment "CODE"
.org $D4E0
map_control_0dd4e0:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

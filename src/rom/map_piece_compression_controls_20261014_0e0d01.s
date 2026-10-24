.setcpu "65816"
.segment "CODE"
.org $0D01
map_control_0e0d01:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

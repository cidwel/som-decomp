.setcpu "65816"
.segment "CODE"
.org $222D
map_control_0f222d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

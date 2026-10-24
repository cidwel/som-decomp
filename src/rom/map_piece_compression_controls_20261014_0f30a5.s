.setcpu "65816"
.segment "CODE"
.org $30A5
map_control_0f30a5:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count

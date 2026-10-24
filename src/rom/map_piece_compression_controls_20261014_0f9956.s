.setcpu "65816"
.segment "CODE"
.org $9956
map_control_0f9956:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count

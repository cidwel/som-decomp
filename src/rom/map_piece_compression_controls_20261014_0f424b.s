.setcpu "65816"
.segment "CODE"
.org $424B
map_control_0f424b:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count

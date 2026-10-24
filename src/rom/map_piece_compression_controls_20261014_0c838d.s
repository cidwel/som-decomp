.setcpu "65816"
.segment "CODE"
.org $838D
map_control_0c838d:
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count

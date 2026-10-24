.setcpu "65816"
.segment "CODE"
.org $7D60
map_control_0e7d60:
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count

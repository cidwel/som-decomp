.setcpu "65816"
.segment "CODE"
.org $4C91
map_control_0c4c91:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count

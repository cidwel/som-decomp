.setcpu "65816"
.segment "CODE"
.org $19C6
map_control_0e19c6:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count

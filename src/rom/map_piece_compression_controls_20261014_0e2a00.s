.setcpu "65816"
.segment "CODE"
.org $2A00
map_control_0e2a00:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $1049
map_control_0e1049:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count

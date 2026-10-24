.setcpu "65816"
.segment "CODE"
.org $7133
map_control_0d7133:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

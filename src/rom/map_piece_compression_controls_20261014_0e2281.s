.setcpu "65816"
.segment "CODE"
.org $2281
map_control_0e2281:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

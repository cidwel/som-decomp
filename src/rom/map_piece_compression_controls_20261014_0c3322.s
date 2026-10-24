.setcpu "65816"
.segment "CODE"
.org $3322
map_control_0c3322:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $CD0D
map_control_0dcd0d:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count

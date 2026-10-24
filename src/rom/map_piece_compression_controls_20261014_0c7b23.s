.setcpu "65816"
.segment "CODE"
.org $7B23
map_control_0c7b23:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count

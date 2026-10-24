.setcpu "65816"
.segment "CODE"
.org $52A6
map_control_0c52a6:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count

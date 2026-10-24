.setcpu "65816"
.segment "CODE"
.org $ED52
map_control_0fed52:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count

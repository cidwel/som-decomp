.setcpu "65816"
.segment "CODE"
.org $2DB6
map_control_0f2db6:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

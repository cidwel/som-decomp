.setcpu "65816"
.segment "CODE"
.org $D4E3
map_control_0ed4e3:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count

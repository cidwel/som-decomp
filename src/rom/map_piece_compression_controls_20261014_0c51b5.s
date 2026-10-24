.setcpu "65816"
.segment "CODE"
.org $51B5
map_control_0c51b5:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count

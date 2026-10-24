.setcpu "65816"
.segment "CODE"
.org $4E4D
map_control_0c4e4d:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count

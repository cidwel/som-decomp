.setcpu "65816"
.segment "CODE"
.org $E08D
map_control_0de08d:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count

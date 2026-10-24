.setcpu "65816"
.segment "CODE"
.org $2FD1
map_control_0f2fd1:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count

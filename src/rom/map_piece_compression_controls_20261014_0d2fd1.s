.setcpu "65816"
.segment "CODE"
.org $2FD1
map_control_0d2fd1:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count

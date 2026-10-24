.setcpu "65816"
.segment "CODE"
.org $88AE
map_control_0d88ae:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count

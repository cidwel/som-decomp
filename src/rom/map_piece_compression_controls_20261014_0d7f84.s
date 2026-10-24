.setcpu "65816"
.segment "CODE"
.org $7F84
map_control_0d7f84:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count

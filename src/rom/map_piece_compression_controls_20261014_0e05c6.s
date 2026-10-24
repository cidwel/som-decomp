.setcpu "65816"
.segment "CODE"
.org $05C6
map_control_0e05c6:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count

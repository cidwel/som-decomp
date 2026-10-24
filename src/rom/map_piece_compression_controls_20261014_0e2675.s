.setcpu "65816"
.segment "CODE"
.org $2675
map_control_0e2675:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $6E4D
map_control_0e6e4d:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count

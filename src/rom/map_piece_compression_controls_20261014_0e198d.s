.setcpu "65816"
.segment "CODE"
.org $198D
map_control_0e198d:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count

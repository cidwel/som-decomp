.setcpu "65816"
.segment "CODE"
.org $198D
map_control_0d198d:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $B484
map_control_0db484:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count

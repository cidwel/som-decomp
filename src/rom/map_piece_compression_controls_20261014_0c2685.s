.setcpu "65816"
.segment "CODE"
.org $2685
map_control_0c2685:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count

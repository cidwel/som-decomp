.setcpu "65816"
.segment "CODE"
.org $33BE
map_control_0e33be:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count

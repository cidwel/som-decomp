.setcpu "65816"
.segment "CODE"
.org $1C9B
map_control_0c1c9b:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count

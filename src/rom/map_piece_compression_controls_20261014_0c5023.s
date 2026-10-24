.setcpu "65816"
.segment "CODE"
.org $5023
map_control_0c5023:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count

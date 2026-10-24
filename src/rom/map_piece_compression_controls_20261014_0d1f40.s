.setcpu "65816"
.segment "CODE"
.org $1F40
map_control_0d1f40:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $1759
map_control_0c1759:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

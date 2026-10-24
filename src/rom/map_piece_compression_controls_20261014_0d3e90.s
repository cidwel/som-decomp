.setcpu "65816"
.segment "CODE"
.org $3E90
map_control_0d3e90:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count

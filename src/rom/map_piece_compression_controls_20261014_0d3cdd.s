.setcpu "65816"
.segment "CODE"
.org $3CDD
map_control_0d3cdd:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $3640
map_control_0d3640:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

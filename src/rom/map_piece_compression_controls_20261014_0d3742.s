.setcpu "65816"
.segment "CODE"
.org $3742
map_control_0d3742:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count

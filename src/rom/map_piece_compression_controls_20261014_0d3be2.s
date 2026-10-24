.setcpu "65816"
.segment "CODE"
.org $3BE2
map_control_0d3be2:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count

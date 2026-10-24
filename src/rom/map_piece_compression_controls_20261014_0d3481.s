.setcpu "65816"
.segment "CODE"
.org $3481
map_control_0d3481:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count

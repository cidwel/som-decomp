.setcpu "65816"
.segment "CODE"
.org $3F95
map_control_0d3f95:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count

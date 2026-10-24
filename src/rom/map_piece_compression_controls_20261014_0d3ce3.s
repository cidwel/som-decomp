.setcpu "65816"
.segment "CODE"
.org $3CE3
map_control_0d3ce3:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

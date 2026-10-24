.setcpu "65816"
.segment "CODE"
.org $3E5C
map_control_0d3e5c:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count

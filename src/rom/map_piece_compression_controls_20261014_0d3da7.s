.setcpu "65816"
.segment "CODE"
.org $3DA7
map_control_0d3da7:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

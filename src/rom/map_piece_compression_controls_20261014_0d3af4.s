.setcpu "65816"
.segment "CODE"
.org $3AF4
map_control_0d3af4:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

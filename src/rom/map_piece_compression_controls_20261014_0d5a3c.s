.setcpu "65816"
.segment "CODE"
.org $5A3C
map_control_0d5a3c:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $5D4C
map_control_0e5d4c:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count

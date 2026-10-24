.setcpu "65816"
.segment "CODE"
.org $5C1F
map_control_0d5c1f:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count

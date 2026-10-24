.setcpu "65816"
.segment "CODE"
.org $EA9F
map_control_0dea9f:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count

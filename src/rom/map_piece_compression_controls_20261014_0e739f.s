.setcpu "65816"
.segment "CODE"
.org $739F
map_control_0e739f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

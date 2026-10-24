.setcpu "65816"
.segment "CODE"
.org $12AA
map_control_0f12aa:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count

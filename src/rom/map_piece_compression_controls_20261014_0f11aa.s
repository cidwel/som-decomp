.setcpu "65816"
.segment "CODE"
.org $11AA
map_control_0f11aa:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $21B2
map_control_0d21b2:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

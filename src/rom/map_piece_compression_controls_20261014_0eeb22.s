.setcpu "65816"
.segment "CODE"
.org $EB22
map_control_0eeb22:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count

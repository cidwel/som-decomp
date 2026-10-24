.setcpu "65816"
.segment "CODE"
.org $29D6
map_control_0d29d6:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count

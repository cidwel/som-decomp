.setcpu "65816"
.segment "CODE"
.org $ABE2
map_control_0eabe2:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $6EE2
map_control_0d6ee2:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

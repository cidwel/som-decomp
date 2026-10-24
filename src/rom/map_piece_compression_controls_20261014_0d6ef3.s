.setcpu "65816"
.segment "CODE"
.org $6EF3
map_control_0d6ef3:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

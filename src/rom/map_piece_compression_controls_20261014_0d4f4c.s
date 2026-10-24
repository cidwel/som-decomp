.setcpu "65816"
.segment "CODE"
.org $4F4C
map_control_0d4f4c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

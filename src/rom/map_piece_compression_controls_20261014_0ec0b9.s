.setcpu "65816"
.segment "CODE"
.org $C0B9
map_control_0ec0b9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

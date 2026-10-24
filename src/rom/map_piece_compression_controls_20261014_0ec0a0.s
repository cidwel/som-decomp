.setcpu "65816"
.segment "CODE"
.org $C0A0
map_control_0ec0a0:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

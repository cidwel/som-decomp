.setcpu "65816"
.segment "CODE"
.org $3006
map_control_0e3006:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

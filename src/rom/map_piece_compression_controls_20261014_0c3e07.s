.setcpu "65816"
.segment "CODE"
.org $3E07
map_control_0c3e07:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

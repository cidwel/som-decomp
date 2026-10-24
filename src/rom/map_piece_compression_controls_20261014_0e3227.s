.setcpu "65816"
.segment "CODE"
.org $3227
map_control_0e3227:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

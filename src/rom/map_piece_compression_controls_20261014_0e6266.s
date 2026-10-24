.setcpu "65816"
.segment "CODE"
.org $6266
map_control_0e6266:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count

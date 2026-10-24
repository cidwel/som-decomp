.setcpu "65816"
.segment "CODE"
.org $6E24
map_control_0d6e24:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

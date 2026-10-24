.setcpu "65816"
.segment "CODE"
.org $9E24
map_control_0f9e24:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count

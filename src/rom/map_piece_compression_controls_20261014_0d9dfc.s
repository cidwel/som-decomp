.setcpu "65816"
.segment "CODE"
.org $9DFC
map_control_0d9dfc:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

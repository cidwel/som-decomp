.setcpu "65816"
.segment "CODE"
.org $9F25
map_control_0d9f25:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

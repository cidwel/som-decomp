.setcpu "65816"
.segment "CODE"
.org $9DE9
map_control_0d9de9:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

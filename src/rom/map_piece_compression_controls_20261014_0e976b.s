.setcpu "65816"
.segment "CODE"
.org $976B
map_control_0e976b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

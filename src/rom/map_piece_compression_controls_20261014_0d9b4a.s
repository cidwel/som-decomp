.setcpu "65816"
.segment "CODE"
.org $9B4A
map_control_0d9b4a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

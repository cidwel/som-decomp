.setcpu "65816"
.segment "CODE"
.org $99C2
map_control_0d99c2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

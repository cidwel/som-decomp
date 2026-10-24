.setcpu "65816"
.segment "CODE"
.org $41E5
map_control_0d41e5:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $89D7
map_control_0d89d7:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $70D7
map_control_0f70d7:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

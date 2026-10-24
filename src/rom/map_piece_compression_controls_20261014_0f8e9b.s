.setcpu "65816"
.segment "CODE"
.org $8E9B
map_control_0f8e9b:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

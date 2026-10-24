.setcpu "65816"
.segment "CODE"
.org $8E88
map_control_0f8e88:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

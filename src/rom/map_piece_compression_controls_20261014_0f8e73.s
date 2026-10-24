.setcpu "65816"
.segment "CODE"
.org $8E73
map_control_0f8e73:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

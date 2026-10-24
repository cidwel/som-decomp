.setcpu "65816"
.segment "CODE"
.org $07C9
map_control_0f07c9:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

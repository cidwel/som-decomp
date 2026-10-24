.setcpu "65816"
.segment "CODE"
.org $07F9
map_control_0f07f9:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

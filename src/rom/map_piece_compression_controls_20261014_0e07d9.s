.setcpu "65816"
.segment "CODE"
.org $07D9
map_control_0e07d9:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count

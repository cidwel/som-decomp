.setcpu "65816"
.segment "CODE"
.org $85F6
map_control_0e85f6:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $282A
map_control_0f282a:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

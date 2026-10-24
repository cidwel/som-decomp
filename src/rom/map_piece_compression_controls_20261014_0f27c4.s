.setcpu "65816"
.segment "CODE"
.org $27C4
map_control_0f27c4:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count

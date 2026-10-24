.setcpu "65816"
.segment "CODE"
.org $49B1
map_control_0f49b1:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count

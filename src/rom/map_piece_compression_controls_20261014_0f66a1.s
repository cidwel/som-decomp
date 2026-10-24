.setcpu "65816"
.segment "CODE"
.org $66A1
map_control_0f66a1:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $39F1
map_control_0f39f1:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

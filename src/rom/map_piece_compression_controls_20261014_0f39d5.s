.setcpu "65816"
.segment "CODE"
.org $39D5
map_control_0f39d5:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

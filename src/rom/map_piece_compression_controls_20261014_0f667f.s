.setcpu "65816"
.segment "CODE"
.org $667F
map_control_0f667f:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count

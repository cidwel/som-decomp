.setcpu "65816"
.segment "CODE"
.org $49D4
map_control_0f49d4:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count

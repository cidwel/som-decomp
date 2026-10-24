.setcpu "65816"
.segment "CODE"
.org $8588
map_control_0f8588:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count

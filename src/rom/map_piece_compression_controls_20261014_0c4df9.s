.setcpu "65816"
.segment "CODE"
.org $4DF9
map_control_0c4df9:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count

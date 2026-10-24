.setcpu "65816"
.segment "CODE"
.org $4FEF
map_control_0c4fef:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count

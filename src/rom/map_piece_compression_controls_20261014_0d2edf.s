.setcpu "65816"
.segment "CODE"
.org $2EDF
map_control_0d2edf:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count

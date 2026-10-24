.setcpu "65816"
.segment "CODE"
.org $4EDF
map_control_0d4edf:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count

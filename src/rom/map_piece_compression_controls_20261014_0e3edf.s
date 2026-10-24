.setcpu "65816"
.segment "CODE"
.org $3EDF
map_control_0e3edf:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count

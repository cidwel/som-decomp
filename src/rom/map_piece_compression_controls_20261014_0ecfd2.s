.setcpu "65816"
.segment "CODE"
.org $CFD2
map_control_0ecfd2:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

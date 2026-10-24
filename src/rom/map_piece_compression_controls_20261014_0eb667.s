.setcpu "65816"
.segment "CODE"
.org $B667
map_control_0eb667:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

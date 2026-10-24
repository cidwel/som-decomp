.setcpu "65816"
.segment "CODE"
.org $D008
map_control_0ed008:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

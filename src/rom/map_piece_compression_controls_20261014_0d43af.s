.setcpu "65816"
.segment "CODE"
.org $43AF
map_control_0d43af:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count

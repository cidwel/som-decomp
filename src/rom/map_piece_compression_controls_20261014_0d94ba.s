.setcpu "65816"
.segment "CODE"
.org $94BA
map_control_0d94ba:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

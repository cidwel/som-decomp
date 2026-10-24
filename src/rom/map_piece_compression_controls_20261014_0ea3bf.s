.setcpu "65816"
.segment "CODE"
.org $A3BF
map_control_0ea3bf:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count

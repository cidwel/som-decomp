.setcpu "65816"
.segment "CODE"
.org $BFA0
map_control_0ebfa0:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

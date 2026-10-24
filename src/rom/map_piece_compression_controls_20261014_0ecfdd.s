.setcpu "65816"
.segment "CODE"
.org $CFDD
map_control_0ecfdd:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $CFFD
map_control_0ecffd:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

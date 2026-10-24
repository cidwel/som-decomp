.setcpu "65816"
.segment "CODE"
.org $ECDC
map_control_0fecdc:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count

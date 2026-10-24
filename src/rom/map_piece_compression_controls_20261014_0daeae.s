.setcpu "65816"
.segment "CODE"
.org $AEAE
map_control_0daeae:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count

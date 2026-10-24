.setcpu "65816"
.segment "CODE"
.org $BBCD
map_control_0ebbcd:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $BB1E
map_control_0ebb1e:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $93 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $1FA3
map_control_0d1fa3:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count

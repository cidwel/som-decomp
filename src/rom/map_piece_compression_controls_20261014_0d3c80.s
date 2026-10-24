.setcpu "65816"
.segment "CODE"
.org $3C80
map_control_0d3c80:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count

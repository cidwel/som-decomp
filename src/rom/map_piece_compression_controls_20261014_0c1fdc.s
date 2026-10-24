.setcpu "65816"
.segment "CODE"
.org $1FDC
map_control_0c1fdc:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count

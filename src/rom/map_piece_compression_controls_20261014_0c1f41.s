.setcpu "65816"
.segment "CODE"
.org $1F41
map_control_0c1f41:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $6591
map_control_0d6591:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count

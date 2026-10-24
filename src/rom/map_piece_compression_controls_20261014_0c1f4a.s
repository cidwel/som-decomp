.setcpu "65816"
.segment "CODE"
.org $1F4A
map_control_0c1f4a:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count

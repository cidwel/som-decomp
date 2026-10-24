.setcpu "65816"
.segment "CODE"
.org $D104
map_control_0ed104:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count

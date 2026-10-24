.setcpu "65816"
.segment "CODE"
.org $BE44
map_control_0ebe44:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count

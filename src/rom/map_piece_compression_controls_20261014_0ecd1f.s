.setcpu "65816"
.segment "CODE"
.org $CD1F
map_control_0ecd1f:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count

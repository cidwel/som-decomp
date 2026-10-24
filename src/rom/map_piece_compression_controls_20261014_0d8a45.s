.setcpu "65816"
.segment "CODE"
.org $8A45
map_control_0d8a45:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

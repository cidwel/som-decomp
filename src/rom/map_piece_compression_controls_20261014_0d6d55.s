.setcpu "65816"
.segment "CODE"
.org $6D55
map_control_0d6d55:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

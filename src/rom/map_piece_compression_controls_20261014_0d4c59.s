.setcpu "65816"
.segment "CODE"
.org $4C59
map_control_0d4c59:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count

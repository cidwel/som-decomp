.setcpu "65816"
.segment "CODE"
.org $440D
map_control_0c440d:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count

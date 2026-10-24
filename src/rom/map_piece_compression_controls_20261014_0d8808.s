.setcpu "65816"
.segment "CODE"
.org $8808
map_control_0d8808:
    .byte $EF ; backreference distance high bits
    .byte $11 ; distance low bit/count

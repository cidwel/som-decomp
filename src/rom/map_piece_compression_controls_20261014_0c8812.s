.setcpu "65816"
.segment "CODE"
.org $8812
map_control_0c8812:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $6578
map_control_0d6578:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count

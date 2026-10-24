.setcpu "65816"
.segment "CODE"
.org $5507
map_control_0e5507:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count

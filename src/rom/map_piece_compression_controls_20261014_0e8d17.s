.setcpu "65816"
.segment "CODE"
.org $8D17
map_control_0e8d17:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count

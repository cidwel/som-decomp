.setcpu "65816"
.segment "CODE"
.org $08B8
map_control_0e08b8:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $80E6
map_control_0e80e6:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count

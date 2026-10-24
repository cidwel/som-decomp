.setcpu "65816"
.segment "CODE"
.org $5473
map_control_0c5473:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count

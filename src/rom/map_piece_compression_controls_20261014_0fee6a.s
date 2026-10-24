.setcpu "65816"
.segment "CODE"
.org $EE6A
map_control_0fee6a:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count

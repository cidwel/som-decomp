.setcpu "65816"
.segment "CODE"
.org $266B
map_control_0e266b:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $F1C1
map_control_0ef1c1:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count

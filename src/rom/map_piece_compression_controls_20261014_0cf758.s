.setcpu "65816"
.segment "CODE"
.org $F758
map_control_0cf758:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

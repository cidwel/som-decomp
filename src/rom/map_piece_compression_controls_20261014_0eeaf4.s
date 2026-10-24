.setcpu "65816"
.segment "CODE"
.org $EAF4
map_control_0eeaf4:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count

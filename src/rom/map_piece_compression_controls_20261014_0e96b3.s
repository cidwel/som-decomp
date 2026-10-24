.setcpu "65816"
.segment "CODE"
.org $96B3
map_control_0e96b3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

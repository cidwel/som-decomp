.setcpu "65816"
.segment "CODE"
.org $96B7
map_control_0d96b7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

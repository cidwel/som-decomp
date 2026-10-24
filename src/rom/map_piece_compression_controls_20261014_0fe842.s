.setcpu "65816"
.segment "CODE"
.org $E842
map_control_0fe842:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count

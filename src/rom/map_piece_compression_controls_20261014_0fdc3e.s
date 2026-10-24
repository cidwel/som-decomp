.setcpu "65816"
.segment "CODE"
.org $DC3E
map_control_0fdc3e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

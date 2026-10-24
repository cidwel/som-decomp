.setcpu "65816"
.segment "CODE"
.org $DC61
map_control_0fdc61:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $957B
map_control_0e957b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

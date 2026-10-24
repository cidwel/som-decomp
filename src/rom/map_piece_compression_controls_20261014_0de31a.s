.setcpu "65816"
.segment "CODE"
.org $E31A
map_control_0de31a:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count

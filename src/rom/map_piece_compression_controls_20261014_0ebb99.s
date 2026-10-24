.setcpu "65816"
.segment "CODE"
.org $BB99
map_control_0ebb99:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

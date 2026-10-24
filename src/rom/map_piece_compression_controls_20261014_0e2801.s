.setcpu "65816"
.segment "CODE"
.org $2801
map_control_0e2801:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count

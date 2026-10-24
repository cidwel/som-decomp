.setcpu "65816"
.segment "CODE"
.org $B194
map_control_0fb194:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count

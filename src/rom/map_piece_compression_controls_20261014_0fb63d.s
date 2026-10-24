.setcpu "65816"
.segment "CODE"
.org $B63D
map_control_0fb63d:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count

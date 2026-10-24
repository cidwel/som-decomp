.setcpu "65816"
.segment "CODE"
.org $E2F9
map_control_0de2f9:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count

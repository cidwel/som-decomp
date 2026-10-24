.setcpu "65816"
.segment "CODE"
.org $E0EF
map_control_0fe0ef:
    .byte $E8 ; backreference distance high bits
    .byte $4E ; distance low bit/count

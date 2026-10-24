.setcpu "65816"
.segment "CODE"
.org $3887
map_control_0e3887:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count

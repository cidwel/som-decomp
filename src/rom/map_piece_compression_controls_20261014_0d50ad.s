.setcpu "65816"
.segment "CODE"
.org $50AD
map_control_0d50ad:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count

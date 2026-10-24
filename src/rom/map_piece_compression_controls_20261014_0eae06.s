.setcpu "65816"
.segment "CODE"
.org $AE06
map_control_0eae06:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count

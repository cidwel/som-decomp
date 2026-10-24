.setcpu "65816"
.segment "CODE"
.org $2626
map_control_0d2626:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
